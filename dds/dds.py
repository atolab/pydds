from ctypes import *
import os
import jsonpickle


__author__ = 'Angelo Corsaro'


#@TODO: Fix this to go and look for the right library...
lite_lib = 'libdds.dylib'
bit_lib = 'libdython.dylib'
lite_lib_path = os.environ['LITE_HOME'] + os.sep + 'lib' + os.sep + os.environ['LITE_TARGET'] + os.sep + lite_lib
# Yes, this assumes that the Python BIT should be under the lite lib... If not there copy it!
bit_lib_path = os.environ['LITE_HOME'] + os.sep + 'lib' + os.sep + os.environ['LITE_TARGET'] + os.sep + bit_lib
#############################################################################
### Statuses
DDS_READ_SAMPLE_STATE = 1
DDS_NOT_READ_SAMPLE_STATE = 2
DDS_ANY_SAMPLE_STATE = DDS_READ_SAMPLE_STATE | DDS_NOT_READ_SAMPLE_STATE
DDS_NEW_VIEW_STATE = 4
DDS_NOT_NEW_VIEW_STATE = 8
DDS_ANY_VIEW_STATE = DDS_NEW_VIEW_STATE | DDS_NOT_NEW_VIEW_STATE


DDS_ALIVE_INSTANCE_STATE = 16
DDS_NOT_ALIVE_DISPOSED_INSTANCE_STATE = 32
DDS_NOT_ALIVE_NO_WRITERS_INSTANCE_STATE = 64
DDS_ANY_INSTANCE_STATE = DDS_ALIVE_INSTANCE_STATE | DDS_NOT_ALIVE_DISPOSED_INSTANCE_STATE | DDS_NOT_ALIVE_NO_WRITERS_INSTANCE_STATE

DDS_ANY_STATE = DDS_ANY_SAMPLE_STATE | DDS_ANY_VIEW_STATE | DDS_ANY_INSTANCE_STATE

#############################################################################
## QoS IDs
DDS_INVALID_QOS_POLICY_ID = 0
DDS_USERDATA_QOS_POLICY_ID = 1
DDS_DURABILITY_QOS_POLICY_ID = 2
DDS_PRESENTATION_QOS_POLICY_ID = 3
DDS_DEADLINE_QOS_POLICY_ID = 4
DDS_LATENCYBUDGET_QOS_POLICY_ID = 5
DDS_OWNERSHIP_QOS_POLICY_ID = 6
DDS_OWNERSHIPSTRENGTH_QOS_POLICY_ID = 7
DDS_LIVELINESS_QOS_POLICY_ID = 8
DDS_TIMEBASEDFILTER_QOS_POLICY_ID = 9
DDS_PARTITION_QOS_POLICY_ID = 10
DDS_RELIABILITY_QOS_POLICY_ID = 11
DDS_DESTINATIONORDER_QOS_POLICY_ID = 12
DDS_HISTORY_QOS_POLICY_ID = 13
DDS_RESOURCELIMITS_QOS_POLICY_ID = 14
DDS_ENTITYFACTORY_QOS_POLICY_ID = 15
DDS_WRITERDATALIFECYCLE_QOS_POLICY_ID = 16
DDS_READERDATALIFECYCLE_QOS_POLICY_ID = 17
DDS_TOPICDATA_QOS_POLICY_ID = 18
DDS_GROUPDATA_QOS_POLICY_ID = 19
DDS_TRANSPORTPRIORITY_QOS_POLICY_ID = 20
DDS_LIFESPAN_QOS_POLICY_ID = 21
DDS_DURABILITYSERVICE_QOS_POLICY_ID = 22

#############################################################################
#### QoS Kinds

### Durability
DDS_DURABILITY_VOLATILE = 0
DDS_DURABILITY_TRANSIENT_LOCAL = 1
DDS_DURABILITY_TRANSIENT = 2
DDS_DURABILITY_PERSISTENT = 3

### History
DDS_HISTORY_KEEP_LAST = 0
DDS_HISTORY_KEEP_ALL = 1

### Ownership
DDS_OWNERSHIP_SHARED = 0
DDS_OWNERSHIP_EXCLUSIVE = 1

### Reliability
DDS_RELIABILITY_BEST_EFFORT = 0
DDS_RELIABILITY_RELIABLE = 1

### Dest Order
DDS_DESTINATIONORDER_BY_RECEPTION_TIMESTAMP = 0
DDS_DESTINATIONORDER_BY_SOURCE_TIMESTAMP = 1

DDS_LIVELINESS_AUTOMATIC = 0
DDS_LIVELINESS_MANUAL_BY_PARTICIPANT = 1
DDS_LIVELINESS_MANUAL_BY_TOPIC = 2


class Policy:
    def __init__(self, id):
        self.id = id


class Partition(Policy):
    def __init__(self, ps):
        Policy.__init__(self, DDS_PARTITION_QOS_POLICY_ID)
        self.partitions = ps


class Reliable(Policy):
    def __init__(self):
        Policy.__init__(self, DDS_RELIABILITY_RELIABLE)
        self.max_blocking_time = 0


class BestEffort(Policy):
    def __init__(self):
        Policy.__init__(self, DDS_RELIABILITY_BEST_EFFORT)


class KeepLastHistory(Policy):
    def __init__(self, depth):
        Policy.__init__(self, DDS_HISTORY_KEEP_LAST)
        self.depth = depth


class KeepAllHistory(Policy):
    def __init__(self):
        Policy.__init__(self, DDS_HISTORY_KEEP_ALL)


class Volatile(Policy):
    def __init__(self):
        Policy.__init__(self, DDS_DURABILITY_VOLATILE)


class TransientLocal(Policy):
    def __init__(self):
        Policy.__init__(self, DDS_DURABILITY_TRANSIENT_LOCAL)


class Transient(Policy):
    def __init__(self):
        Policy.__init__(self, DDS_DURABILITY_TRANSIENT)


class Persistent(Policy):
    def __init__(self):
        Policy.__init__(self, DDS_DURABILITY_PERSISTENT)


class ExclusiveOwnership(Policy):
    def __init__(self, strength):
        Policy.__init__(self, DDS_OWNERSHIP_EXCLUSIVE)
        self.strength = strength


class SharedOwnership(Policy):
    def __init__(self):
        Policy.__init__(self, DDS_OWNERSHIP_SHARED)


theRuntime = None


class SampleSelector:
    @staticmethod
    def readSamples():
        return c_uint(DDS_READ_SAMPLE_STATE | DDS_ALIVE_INSTANCE_STATE | DDS_ANY_VIEW_STATE)

    @staticmethod
    def newSamples():
        return c_uint(DDS_NOT_READ_SAMPLE_STATE | DDS_ALIVE_INSTANCE_STATE | DDS_ANY_VIEW_STATE)

    @staticmethod
    def allSamples():
        return c_uint(DDS_ANY_STATE)

    @staticmethod
    def newInstanceSamples():
        return c_uint(DDS_NOT_READ_SAMPLE_STATE | DDS_ALIVE_INSTANCE_STATE | DDS_NEW_VIEW_STATE)

    @staticmethod
    def notAliveInstanceSamples():
        return c_uint(DDS_ANY_SAMPLE_STATE | DDS_ANY_VIEW_STATE | DDS_NOT_ALIVE_NO_WRITERS_INSTANCE_STATE)


###
### Built-in Key-Value type
###
class DDSKeyValue(Structure):
    _fields_ = [("key", c_char_p),
                ("value", c_char_p)]



REQUESTED_DEADLINE_MISSED_PROTO = CFUNCTYPE(None, c_void_p, c_void_p)
REQUESTED_INCOMPATIBLE_QOS_PROTO = CFUNCTYPE(None, c_void_p, c_void_p)
SAMPLE_REJECTED_PROTO = CFUNCTYPE(None, c_void_p, c_void_p)
LIVELINESS_CHANGED_PROTO = CFUNCTYPE(None, c_void_p, c_void_p)
DATA_AVAILABLE_PROTO = CFUNCTYPE(None, c_void_p)
SUBSCRIPTION_MATCHED_PROTO = CFUNCTYPE(None, c_void_p, c_void_p)
SAMPLE_LOST_PROTO = CFUNCTYPE(None, c_void_p, c_void_p)


# There are actually used to check the the listener are actually working...

def trivial_on_requested_deadline_missed(e, s):
    print(">> trivial_on_requested_deadline_missed")


def trivial_on_requested_incompatible_qos(e, s):
    print(">> trivial_on_requested_incompatible_qos")


def trivial_on_sample_rejected(e, s):
    print(">> trivial_on_sample_rejected")


def trivial_on_liveliness_changed(e, s):
    print(">> trivial_on_liveliness_changed")


def trivial_on_data_available(r):
    Runtime.dispatchDataListener(c_void_p(r))


def trivial_on_subscription_matched(e, s):
    print(">> trivial_on_subscription_matched")


def trivial_on_sample_lost(e, s):
    print(">> trivial_on_sample_lost")


class DDSReaderListener(Structure):
    _fields_ = [("on_requested_deadline_missed", CFUNCTYPE(None, c_void_p, c_void_p)),
                ("on_requested_incompatible_qos", CFUNCTYPE(None, c_void_p, c_void_p)),
                ("on_sample_rejected", CFUNCTYPE(None, c_void_p, c_void_p)),
                ("on_liveliness_changed", CFUNCTYPE(None, c_void_p, c_void_p)),
                ("on_data_available", CFUNCTYPE(None, c_void_p)),
                ("on_subscription_matched", CFUNCTYPE(None, c_void_p, c_void_p)),
                ("on_sample_lost", CFUNCTYPE(None, c_void_p, c_void_p))]


class Participant:
    def __init__(self, did):
        global theRuntime
        self.rt = theRuntime
        self.did = did
        self.handle = c_void_p()
        self.rt.ddslib.dds_participant_create(byref(self.handle), did, None, None)


class Publisher:
    def __init__(self, dp, policies):
        global theRuntime
        self.rt = theRuntime
        self.dp = dp
        self.policies = policies
        self.handle = c_void_p()
        qos = self.rt.toPubSubQos(policies)
        self.rt.ddslib.dds_publisher_create(dp.handle, byref(self.handle), qos, None)
        self.rt.releaseDDSQoS(qos)


class Subscriber:
    def __init__(self, dp, policies):
        global theRuntime
        self.rt = theRuntime
        self.dp = dp
        self.policies = policies
        self.handle = c_void_p()
        qos = self.rt.toPubSubQos(policies)
        self.rt.ddslib.dds_subscriber_create(dp.handle, byref(self.handle), qos, None)
        self.rt.releaseDDSQoS(qos)


class FlexyTopic:
    def __init__(self, dp, name, keygen, qos):
        global theRuntime
        self.rt = theRuntime
        self.keygen = keygen
        ts = self.rt.getKeyValueTypeSupport()
        self.topic = Topic(dp, name, ts, DDSKeyValue, qos)


class Topic:
    def __init__(self, dp, topic_name, type_support, data_type, qos):
        global theRuntime
        self.rt = theRuntime
        self.topic_name = topic_name
        self.type_support = type_support
        self.data_type = data_type
        self.qos = qos

        self.handle = c_void_p()
        self.rt.ddslib.dds_topic_create(dp.handle, byref(self.handle), type_support, topic_name, qos, None)


class FlexyWriter:
    def __init__(self, pub, flexy_topic, policies):
        self.writer = DataWriter(pub, flexy_topic.topic, policies)
        self.keygen = flexy_topic.keygen

    def write(self, s):
        key = jsonpickle.encode(self.keygen(s))
        value = jsonpickle.encode(s)
        x = DDSKeyValue(key, value)
        self.writer.write(x)

    def write_all(self, xs):
        for x in xs:
            self.write(x)


class DataWriter:
    def __init__(self, pub, topic, policies):
        global theRuntime
        self.rt = theRuntime
        self.pub = pub
        self.topic = topic
        self.policies = policies
        self.handle = c_void_p()

        qos = self.rt.toRWQos(policies)
        self.rt.ddslib.dds_writer_create(pub.handle, byref(self.handle), topic.handle, qos, None)

    def write(self, s):
        self.rt.ddslib.dds_write(self.handle, byref(s))


class FlexyReader:
    def __init__(self, sub, flexy_topic, policies, flexyDataListener):
        global theRuntime
        self.rt = theRuntime
        self.sub = sub
        self.flexy_topic = flexy_topic
        self.policies = policies
        self.dataListener = flexyDataListener

        holder = DDSReaderListener(self.rt.on_requested_deadline_missed,
                                   self.rt.on_requested_incompatible_qos,
                                   self.rt.on_sample_rejected,
                                   self.rt.on_liveliness_changed,
                                   self.rt.on_data_available,
                                   self.rt.on_subscription_matched,
                                   self.rt.on_sample_lost)
        self.handle = c_void_p()
        topic = self.flexy_topic.topic
        qos = self.rt.toRWQos(policies)
        self.rt.ddslib.dds_reader_create(sub.handle, byref(self.handle), topic.handle, qos, byref(holder))
        self.rt.registerDataListener(self.handle, self.handleData)

    def handleData(self, r):
        self.dataListener(self)


    def read(self, n, sampleSelector):
        # @TODO: This is a dirty hack... It is but I am not ashamed by it :-P
        #        I'll fix it once proper support for SampleInfo will be in place
        info_len = n * 256  # 128 should be enough... but we keep it safe
        Info_t = c_byte * info_len

        info = cast(Info_t(), c_void_p)

        SampleVec_t = c_void_p * n
        samples = SampleVec_t()
        nr = theRuntime.ddslib.dds_read(self.handle, samples, n, info, sampleSelector)
        data = []

        for s in samples:
            sp = cast(c_void_p(samples[0]), POINTER(self.flexy_topic.topic.data_type))
            data.append(jsonpickle.decode(sp[0].value))

        return data

    def take(self, n, sampleSelector):
        # @TODO: This is a dirty hack... It is but I am not ashamed by it :-P
        #        I'll fix it once proper support for SampleInfo will be in place
        info_len = n * 256  # 128 should be enough... but we keep it safe
        Info_t = c_byte * info_len

        info = cast(Info_t(), c_void_p)

        SampleVec_t = c_void_p * n
        samples = SampleVec_t()
        nr = theRuntime.ddslib.dds_take(self.handle, samples, n, info, sampleSelector)
        data = []
        for s in samples:
            sp = cast(c_void_p(samples[0]), POINTER(self.flexy_topic.topic.data_type))
            data.append(jsonpickle.decode(sp[0].value))

        return data

class DataReader:
    def __init__(self, sub, topic, policies, dataListener):
        global theRuntime
        self.rt = theRuntime
        self.sub = sub
        self.topic = topic
        self.policies = policies
        self.dataListener = dataListener

        holder = DDSReaderListener(self.rt.on_requested_deadline_missed,
                                   self.rt.on_requested_incompatible_qos,
                                   self.rt.on_sample_rejected,
                                   self.rt.on_liveliness_changed,
                                   self.rt.on_data_available,
                                   self.rt.on_subscription_matched,
                                   self.rt.on_sample_lost)
        self.handle = c_void_p()
        qos = self.rt.toRWQos(policies)
        self.rt.ddslib.dds_reader_create(sub.handle, byref(self.handle), topic.handle, qos, byref(holder))
        self.rt.registerDataListener(self.handle, self.handleData)

    def handleData(self, r):
        self.dataListener(self)

    def take(self, n, sampleSelector):
        # @TODO: This is a dirty hack... It is but I am not ashamed by it :-P
        #        I'll fix it once proper support for SampleInfo will be in place
        info_len = n * 256  # 128 should be enough... but we keep it safe
        Info_t = c_byte * info_len

        info = cast(Info_t(), c_void_p)

        SampleVec_t = c_void_p * n
        samples = SampleVec_t()
        nr = theRuntime.ddslib.dds_take(self.handle, samples, n, info, sampleSelector)
        data = []
        for s in samples:
            sp = cast(c_void_p(samples[0]), POINTER(self.topic.data_type))
            data.append(sp[0])

        return data

    def read(self, n, sampleSelector):
        # @TODO: This is a dirty hack... It is but I am not ashamed by it :-P
        #        I'll fix it once proper support for SampleInfo will be in place
        info_len = n * 256 # 128 should be enough... but we keep it safe
        Info_t = c_byte * info_len

        info = cast(Info_t(), c_void_p)

        SampleVec_t = c_void_p * n
        samples = SampleVec_t()
        nr = theRuntime.ddslib.dds_read(self.handle, samples, n, info, sampleSelector)
        data = []
        for s in samples:
            sp = cast(c_void_p(samples[0]), POINTER(self.topic.data_type))
            data.append(sp[0])

        return data


class Error(Exception):
    pass

class Runtime:

    @staticmethod
    def getRuntime():
        return theRuntime
    def __init__(self):

        self.dataListenerMap = {}

        self.ddslib = CDLL(lite_lib_path)
        self.bitypes = CDLL(bit_lib_path)

        self.ddslib.dds_init(0, None)
        self.kv_topic = None
        self.v_topic = None

        self.on_requested_deadline_missed = REQUESTED_DEADLINE_MISSED_PROTO(trivial_on_requested_deadline_missed)
        self.on_requested_incompatible_qos = REQUESTED_INCOMPATIBLE_QOS_PROTO(trivial_on_requested_incompatible_qos)
        self.on_sample_rejected = SAMPLE_REJECTED_PROTO(trivial_on_sample_rejected)
        self.on_liveliness_changed = LIVELINESS_CHANGED_PROTO(trivial_on_liveliness_changed)
        self.on_data_available =  DATA_AVAILABLE_PROTO(trivial_on_data_available)
        self.on_subscription_matched = SUBSCRIPTION_MATCHED_PROTO(trivial_on_subscription_matched)
        self.on_sample_lost = SAMPLE_LOST_PROTO(trivial_on_sample_lost)

        self.ddslib.dds_qos_create.restype = c_void_p
        self.ddslib.dds_qos_create.argtypes = []

        self.ddslib.dds_qos_delete.restype = None
        self.ddslib.dds_qos_delete.argtypes = [c_void_p]

        self.ddslib.dds_qset_durability.restype = None
        self.ddslib.dds_qset_durability.argtypes = [c_void_p, c_uint32]

        self.ddslib.dds_qset_history.restype = None
        self.ddslib.dds_qset_history.argtypes = [c_void_p, c_uint32, c_uint32]

        self.ddslib.dds_qset_reliability.restype = None
        self.ddslib.dds_qset_reliability.argtypes = [c_void_p, c_uint32, c_uint64]

        self.ddslib.dds_qset_ownership.restype = None
        self.ddslib.dds_qset_ownership.argtypes = [c_void_p, c_uint32]

        self.ddslib.dds_qset_ownership_strength.restype = None
        self.ddslib.dds_qset_ownership_strength.argtypes = [c_void_p, c_uint32]


        global theRuntime
        theRuntime = self

    def registerDataListener(self, handle, fun):
        h = repr(handle)
        self.dataListenerMap[h] = fun

    @staticmethod
    def dispatchDataListener(handle):
        h = repr(handle)
        global theRuntime
        if h in theRuntime.dataListenerMap:
            fun = theRuntime.dataListenerMap[h]
            fun(handle)
        else:
            print ('warning>> Trying to dispatch listener for unknown reader {0}'.format(handle))


    def getKeyValueTypeSupport(self):
        return self.bitypes.dython_bit_KDython_desc

    def getSimpleValueTypeSupport(self):
        return self.bitypes.dython_bit_Dython_desc

    def toRWQos(self, ps):
        if ps == None:
            return None

        qos = self.createDDSQoS()

        for p in ps:
            if p.id == DDS_DURABILITY_PERSISTENT:
                self.ddslib.dds_qset_durability(qos, DDS_DURABILITY_PERSISTENT)
            elif p.id == DDS_DURABILITY_TRANSIENT:
                self.ddslib.dds_qset_durability(qos, DDS_DURABILITY_TRANSIENT)
            elif p.id == DDS_DURABILITY_TRANSIENT_LOCAL:
                self.ddslib.dds_qset_durability(qos, DDS_DURABILITY_TRANSIENT_LOCAL)
            elif p.id == DDS_DURABILITY_VOLATILE:
                self.ddslib.dds_qset_durability(qos, DDS_DURABILITY_VOLATILE)
            elif p.id == DDS_HISTORY_KEEP_ALL:
                self.ddslib.dds_qset_history(qos, DDS_HISTORY_KEEP_ALL, 0)
            elif p.id == DDS_HISTORY_KEEP_LAST:
                self.ddslib.dds_qset_history(qos, DDS_HISTORY_KEEP_LAST, p.depth)
            elif p.id == DDS_RELIABILITY_RELIABLE:
                self.ddslib.dds_qset_reliability(qos, DDS_RELIABILITY_RELIABLE, p.max_blocking_time)
            elif p.id == DDS_RELIABILITY_BEST_EFFORT:
                self.ddslib.dds_qset_reliability(qos, DDS_RELIABILITY_BEST_EFFORT, 0)
            elif p.id == DDS_OWNERSHIP_SHARED:
                self.ddslib.dds_qset_ownership(qos, DDS_OWNERSHIP_SHARED)
            elif p.id == DDS_OWNERSHIP_EXCLUSIVE:
                self.ddslib.dds_qset_ownership(qos, DDS_OWNERSHIP_EXCLUSIVE)
                self.ddslib.dds_qset_ownership_strength(qos, p.strength)

            return qos


    def toPubSubQos(self, ps):
        if ps == None:
            return None

        qos = self.createDDSQoS()
        xs = filter(lambda p: p.id == DDS_PARTITION_QOS_POLICY_ID, ps)

        if len(xs) > 0:
            policy = xs[0]
            L = len(policy.partitions)
            vec = (c_char_p * L)()
            vec[:] = policy.partitions
            self.ddslib.dds_qset_partition (qos, c_uint32(L), vec)
        return qos


    def createDDSQoS(self):
        return c_void_p(self.ddslib.dds_qos_create())

    def releaseDDSQoS(self, qos):
        self.ddslib.dds_qos_delete(qos)

    def close(self):
        self.ddslib.dds_fini()


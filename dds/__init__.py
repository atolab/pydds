__author__ = 'Angelo Corsaro'

from ctypes import *
import os
import jsonpickle
import platform


def get_lib_ext():
    system = platform.system()
    if system == 'Linux':
        return '.so'
    elif system == 'Darwin':
        return '.dylib'
    else:
        return '.dll'


# @TODO: Fix this to go and look for the right library...
ospl_lib = 'libdcpsc99' + get_lib_ext()
bit_lib = 'libdython' + get_lib_ext()

ospl_lib_path = os.environ['OSPL_HOME'] + os.sep + 'lib' + os.sep + ospl_lib

# Yes, this assumes that the Python BIT should be under the OSPL lib... If not there copy it!
ospl_bit_lib_path = os.environ['OSPL_HOME'] + os.sep + 'lib' + os.sep + bit_lib

# Limits and Constants
MAX_SAMPLES = 256

#
#  Statuses
DDS_READ_SAMPLE_STATE = 1
DDS_NOT_READ_SAMPLE_STATE = 2
DDS_ANY_SAMPLE_STATE = DDS_READ_SAMPLE_STATE | DDS_NOT_READ_SAMPLE_STATE
DDS_NEW_VIEW_STATE = 4
DDS_NOT_NEW_VIEW_STATE = 8
DDS_ANY_VIEW_STATE = DDS_NEW_VIEW_STATE | DDS_NOT_NEW_VIEW_STATE

DDS_ALIVE_INSTANCE_STATE = 16
DDS_NOT_ALIVE_DISPOSED_INSTANCE_STATE = 32
DDS_NOT_ALIVE_NO_WRITERS_INSTANCE_STATE = 64
DDS_ANY_INSTANCE_STATE =  DDS_ALIVE_INSTANCE_STATE | DDS_NOT_ALIVE_DISPOSED_INSTANCE_STATE | DDS_NOT_ALIVE_NO_WRITERS_INSTANCE_STATE

DDS_ANY_STATE = DDS_ANY_SAMPLE_STATE | DDS_ANY_VIEW_STATE | DDS_ANY_INSTANCE_STATE

#  QoS IDs
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

#
# QoS Kinds

# Durability
DDS_DURABILITY_VOLATILE = 0
DDS_DURABILITY_TRANSIENT_LOCAL = 1
DDS_DURABILITY_TRANSIENT = 2
DDS_DURABILITY_PERSISTENT = 3

# History
DDS_HISTORY_KEEP_LAST = 0
DDS_HISTORY_KEEP_ALL = 1

# Ownership
DDS_OWNERSHIP_SHARED = 0
DDS_OWNERSHIP_EXCLUSIVE = 1

# Reliability
DDS_RELIABILITY_BEST_EFFORT = 0
DDS_RELIABILITY_RELIABLE = 1

# Dest Order
DDS_DESTINATIONORDER_BY_RECEPTION_TIMESTAMP = 0
DDS_DESTINATIONORDER_BY_SOURCE_TIMESTAMP = 1

DDS_LIVELINESS_AUTOMATIC = 0
DDS_LIVELINESS_MANUAL_BY_PARTICIPANT = 1
DDS_LIVELINESS_MANUAL_BY_TOPIC = 2

def dds_secs(n):
    return n*1000000000

def dds_millis(n):
    return n*1000000

def dds_micros(n):
    return n*1000

def dds_nanos(n):
    return n

class TopicType(object):
    def gen_key(self): None


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


class ManualInstanceDispose(Policy):
    def __init__(self):
        Policy.__init__(self, DDS_WRITERDATALIFECYCLE_QOS_POLICY_ID)
        self.auto_dispose = False


class AutoInstanceDispose(Policy):
    def __init__(self):
        Policy.__init__(self, DDS_WRITERDATALIFECYCLE_QOS_POLICY_ID)
        self.auto_dispose = True


the_runtime = None


def read_samples():
    return c_uint(DDS_READ_SAMPLE_STATE | DDS_ALIVE_INSTANCE_STATE | DDS_ANY_VIEW_STATE)


def new_samples():
    return c_uint(DDS_NOT_READ_SAMPLE_STATE | DDS_ALIVE_INSTANCE_STATE | DDS_ANY_VIEW_STATE)


def all_samples():
    return c_uint(DDS_ANY_STATE)


def new_instance_samples():
    return c_uint(DDS_NOT_READ_SAMPLE_STATE | DDS_ALIVE_INSTANCE_STATE | DDS_NEW_VIEW_STATE)


def not_alive_instance_samples():
    return c_uint(DDS_ANY_SAMPLE_STATE | DDS_ANY_VIEW_STATE | DDS_NOT_ALIVE_NO_WRITERS_INSTANCE_STATE)


#
# Built-in Key-Value type
#
class DDSKeyValue(Structure):
    _fields_ = [('key', c_char_p),
                ('value', c_char_p)]


#
# These types are used for binary payload
#
class DDSSequence(Structure):
    _fields_ = [('_maximum', c_uint32),
                ('_length', c_uint32),
                ('_buffer', c_char_p),
                ('_release', c_bool)]


#
# Built-in key-value type
#
class DDSKeyBValue(Structure):
    _fields_ = [('key', c_char_p),
                ('value', DDSSequence)]


#
# DDS Sample Info
#
class SampleInfo(Structure):
    _fields_ = [('sample_state', c_uint),
                ('view_state', c_uint),
                ('instance_state', c_uint),
                ('valid_data', c_bool),
                ('source_timestamp', c_int64),
                ('instance_handle', c_uint64),
                ('pubblication_handle', c_uint64),
                ('disposed_generation_count', c_uint32),
                ('no_writer_generation_count', c_uint32),
                ('sample_rank', c_uint32),
                ('generation_rank', c_uint32),
                ('absolute_generation_rank', c_uint32),
                ('reception_timestamp', c_int64)]

    def is_new_sample(self):
        return self.sample_state == DDS_NOT_READ_SAMPLE_STATE

    def is_read_sample(self):
        return not self.is_new_sample()

    def is_new_instance(self):
        return self.view_state == DDS_NEW_VIEW_STATE

    def is_alive_instance(self):
        return self.instance_state == DDS_ALIVE_INSTANCE_STATE

    def is_disposed_instance(self):
        return self.instance_state == DDS_NOT_ALIVE_DISPOSED_INSTANCE_STATE

    def is_not_alive_instance(self):
        return self.instance_state == DDS_NOT_ALIVE_NO_WRITERS_INSTANCE_STATE


class KeyHolder(object):
    def __init__(self, k):
        self.key = k


REQUESTED_DEADLINE_MISSED_PROTO = CFUNCTYPE(None, c_void_p, c_void_p)
REQUESTED_INCOMPATIBLE_QOS_PROTO = CFUNCTYPE(None, c_void_p, c_void_p)
SAMPLE_REJECTED_PROTO = CFUNCTYPE(None, c_void_p, c_void_p)
LIVELINESS_CHANGED_PROTO = CFUNCTYPE(None, c_void_p, c_void_p)
DATA_AVAILABLE_PROTO = CFUNCTYPE(None, c_void_p)
SUBSCRIPTION_MATCHED_PROTO = CFUNCTYPE(None, c_void_p, c_void_p)
SAMPLE_LOST_PROTO = CFUNCTYPE(None, c_void_p, c_void_p)


# There are actually used to check the the listener are actually working...

def trivial_on_requested_deadline_missed(r, s):
    print(">> trivial_on_requested_deadline_missed")


def trivial_on_requested_incompatible_qos(r, s):
    print(">> trivial_on_requested_incompatible_qos")


def trivial_on_sample_rejected(r, s):
    print(">> trivial_on_sample_rejected")


def trivial_on_liveliness_changed(r, s):
    Runtime.dispatch_liveliness_changed_listener(c_void_p(r), s)


def trivial_on_data_available(r):
    Runtime.dispatch_data_listener(c_void_p(r))


def trivial_on_subscription_matched(e, s):
    Runtime.dispatch_subscription_matched_listener(e, s)


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
        global the_runtime
        self.rt = the_runtime
        self.did = did
        self.handle = c_void_p()
        self.rt.ddslib.dds_participant_create(byref(self.handle), did, None, None)


class Publisher:
    def __init__(self, dp, policies):
        global the_runtime
        self.rt = the_runtime
        self.dp = dp
        self.policies = policies
        self.handle = c_void_p()
        qos = self.rt.to_ps_qos(policies)
        self.rt.ddslib.dds_publisher_create(dp.handle, byref(self.handle), qos, None)
        self.rt.release_dds_qos(qos)


class Subscriber:
    def __init__(self, dp, policies):
        global the_runtime
        self.rt = the_runtime
        self.dp = dp
        self.policies = policies
        self.handle = c_void_p()
        qos = self.rt.to_ps_qos(policies)
        self.rt.ddslib.dds_subscriber_create(dp.handle, byref(self.handle), qos, None)
        self.rt.release_dds_qos(qos)


class FlexyTopic:
    def __init__(self, dp, name, keygen=None, qos=None):
        global the_runtime
        self.rt = the_runtime
        if keygen is None:
            self.keygen = lambda x: x.gen_key()
        else:
            self.keygen = keygen

        ts = self.rt.get_key_value_type_support()
        self.topic = Topic(dp, name, ts, DDSKeyValue, qos)

    def gen_key(self, s):
        return self.keygen(s)


class Topic:
    def __init__(self, dp, topic_name, type_support, data_type, qos):
        global the_runtime
        self.rt = the_runtime
        self.topic_name = topic_name
        self.type_support = type_support
        self.data_type = data_type
        self.qos = qos

        self.handle = c_void_p()
        self.rt.ddslib.dds_topic_create(dp.handle, byref(self.handle), type_support, topic_name.encode(), qos, None)


class FlexyWriter:
    def __init__(self, pub, flexy_topic, policies):
        self.writer = DataWriter(pub, flexy_topic.topic, policies)
        self.keygen = flexy_topic.gen_key

    def write(self, s):
        gk = self.keygen(s)
        key = jsonpickle.encode(gk)
        value = jsonpickle.encode(s)
        x = DDSKeyValue(key.encode(), value.encode())
        self.writer.write(x)

    def write_all(self, xs):
        for x in xs:
            self.write(x)

    def dispose_instance(self, s):
        gk = self.keygen(s)
        key = jsonpickle.encode(gk)
        value = jsonpickle.encode(s)
        x = DDSKeyValue(key.encode(), value.encode())
        self.writer.dispose_instance(x)


class DataWriter:
    def __init__(self, pub, topic, policies):
        global the_runtime
        self.rt = the_runtime
        self.pub = pub
        self.topic = topic
        self.policies = policies
        self.handle = c_void_p()

        qos = self.rt.to_rw_qos(policies)
        self.rt.ddslib.dds_writer_create(pub.handle, byref(self.handle), topic.handle, qos, None)

    def write(self, s):
        self.rt.ddslib.dds_write(self.handle, byref(s))

    def dispose_instance(self, s):
        self.rt.ddslib.dds_instance_dispose(self.handle, byref(s))


# The current waitset implementation has the limitation that can wait
# on a single condition.
class WaitSet(object):
    def __init__(self, condition):
        global the_runtime
        self.rt = the_runtime
        self.handle = c_void_p(self.rt.ddslib.dds_waitset_create())
        self.condition = condition
        self.rt.ddslib.dds_waitset_attach(self.handle, self.condition, None)

    def close(self):
        self.rt.ddslib.dds_waitset_detach(self.handle, self.condition)
        self.rt.ddslib.dds_waitset_delete(self.handle)

    def wait(self, timeout):
        # we only have one condition
        cs = (c_void_p * 1)()
        pcs = cast(cs, c_void_p)
        s = self.rt.ddslib.dds_waitset_wait(self.handle, byref(pcs), 1, timeout)
        if s == 0:
            return False
        else:
            return True


def do_nothing(a):
    return a


class FlexyReader:
    def __init__(self, sub, flexy_topic, policies, flexy_data_listener):
        global the_runtime
        self.rt = the_runtime
        self.sub = sub
        self.sub = sub
        self.flexy_topic = flexy_topic
        self.policies = policies
        if flexy_data_listener is None:
            self.data_listener = do_nothing
        else:
            self.data_listener = flexy_data_listener

        self.subsciption_listener = None
        self._liveliness_listener = None

        self.listener = DDSReaderListener(self.rt.on_requested_deadline_missed,
                                          self.rt.on_requested_incompatible_qos,
                                          self.rt.on_sample_rejected,
                                          self.rt.on_liveliness_changed,
                                          self.rt.on_data_available,
                                          self.rt.on_subscription_matched,
                                          self.rt.on_sample_lost)
        self.handle = c_void_p()
        topic = self.flexy_topic.topic
        qos = self.rt.to_rw_qos(policies)
        self.rt.ddslib.dds_reader_create(sub.handle, byref(self.handle), topic.handle, qos, byref(self.listener))
        self.rt.register_data_listener(self.handle, self.__handle_data)

    def on_data_available(self, fun):
        self.data_listener = fun
        self.rt.register_data_listener(self.handle, fun)

    def on_subscription_matched(self, fun):
        self.subsciption_listener = fun
        self.rt.register_subscription_matched_listener(self.handle, self.__handle_sub_matched)

    def on_liveliness_changed(self, fun):
        self._liveliness_listener = fun
        self.rt.register_liveliness_changed_listener(self.handle, self.__handle_liveliness_change)

    def __handle_data(self, r):
        self.data_listener(self)

    def __handle_sub_matched(self, r, s):
        self.subsciption_listener(self, s)

    def __handle_liveliness_change(self, r, s):
        self._liveliness_listener(self, s)

    def wait_for_data(self, selector, timeout):
        condition = c_void_p(self.rt.ddslib.dds_readcondition_create(self.handle, selector))
        ws = WaitSet(condition)
        r = ws.wait(timeout)
        ws.close()
        return r

    # sread is the synchronous read, that means this blocks until some data is received
    def sread(self, selector, timeout):
        if self.wait_for_data(selector, timeout):
            return self.read(selector)
        else:
            return []

    def read(self, selector):
        return self.read_n(MAX_SAMPLES, selector)

    def sread_n(self, n, selector, timeout):
        if self.wait_for_data(selector, timeout):
            return self.read_n(n, selector)
        else:
            return []

    def read_n(self, n, sample_selector):
        ivec = (SampleInfo * n)()
        infos = cast(ivec, POINTER(SampleInfo))
        samples = (c_void_p * n)()
        nr = self.rt.ddslib.dds_read(self.handle, samples, n, infos, sample_selector)

        data = []
        for i in range(nr):
            sp = cast(c_void_p(samples[i]), POINTER(self.flexy_topic.topic.data_type))
            if infos[i].valid_data:
                v = sp[0].value.decode(encoding='UTF-8')
                data.append(jsonpickle.decode(v))
            else:
                k = sp[0].key.decode(encoding='UTF-8')
                data.append(KeyHolder(k))

        return zip(data, infos)

    def stake(self, selector, timeout):
        if self.wait_for_data(selector, timeout):
            return self.take(selector)
        else:
            return []

    def take(self, selector):
        return self.take_n(MAX_SAMPLES, selector)

    def stake_n(self, n, selector, timeout):
        if self.wait_for_data(selector, timeout):
            return self.take_n(n, selector)
        else:
            return []

    def take_n(self, n, sample_selector):
        ivec = (SampleInfo * n)()
        infos = cast(ivec, POINTER(SampleInfo))

        SampleVec_t = c_void_p * n
        samples = SampleVec_t()
        nr = the_runtime.ddslib.dds_take(self.handle, samples, n, infos, sample_selector)
        data = []

        for i in range(nr):
            sp = cast(c_void_p(samples[i]), POINTER(self.flexy_topic.topic.data_type))
            if infos[i].valid_data:
                v = sp[0].value.decode(encoding='UTF-8')
                data.append(jsonpickle.decode(v))
            else:
                k = sp[0].key.decode(encoding='UTF-8')
                data.append(KeyHolder(k))

        return zip(data, infos)

    def wait_history(self, timeout):
        return the_runtime.ddslib.dds_reader_wait_for_historical_data(self.handle, timeout)


class DataReader:
    def __init__(self, sub, topic, policies, data_listener):
        global the_runtime
        self.rt = the_runtime
        self.sub = sub
        self.topic = topic
        self.policies = policies
        if data_listener is None:
            self.data_listener = do_nothing
        else:
            self.data_listener = data_listener

        self.listener = DDSReaderListener(self.rt.on_requested_deadline_missed,
                                          self.rt.on_requested_incompatible_qos,
                                          self.rt.on_sample_rejected,
                                          self.rt.on_liveliness_changed,
                                          self.rt.on_data_available,
                                          self.rt.on_subscription_matched,
                                          self.rt.on_sample_lost)
        self.handle = c_void_p()
        qos = self.rt.to_rw_qos(policies)
        self.rt.ddslib.dds_reader_create(sub.handle, byref(self.handle), topic.handle, qos, byref(self.listener))
        self.rt.register_data_listener(self.handle, self.handle_data)

    def on_data_available(self, fun):
        self.rt.register_data_listener(self.handle, fun)

    def on_subscription_matched(self, fun):
        self.rt.register_subscription_matched_listener(self.handle, fun)

    def on_liveliness_changed(self, fun):
        self.rt.register_liveliness_changed_listener(self.handle, fun)

    def handle_data(self, r):
        self.data_listener(self)

    def wait_for_data(self, selector, timeout):
        condition = self.rt.ddslib.dds_readcondition_create(self.handle, selector)
        ws = WaitSet(condition)
        r = ws.wait(timeout)
        ws.close()
        return r

    def stake(self, selector, timeout):
        if self.wait_for_data(selector, timeout):
            return self.take(selector)
        else:
            return []

    def stake_n(self, n, selector, timeout):
        if self.wait_for_data(selector, timeout):
            return self.take_n(n, selector)
        else:
            return []

    def take(self, selector):
        return self.take_n(MAX_SAMPLES, selector)

    def take_n(self, n, sampleSelector):
        ivec = (SampleInfo * n)()
        infos = cast(ivec, POINTER(SampleInfo))

        SampleVec_t = c_void_p * n
        samples = SampleVec_t()
        nr = the_runtime.ddslib.dds_take(self.handle, samples, n, infos, sampleSelector)
        data = []
        for i in range(nr):
            sp = cast(c_void_p(samples[i]), POINTER(self.topic.topic.data_type))
            data.append(sp[0])
            # if infos[i].valid_data:
            #     # v = sp[0].value.decode(encoding='UTF-8')
            #     data.append(sp[0])
            # else:
            #     # k = sp[0].key.decode(encoding='UTF-8')
            #     data.append()

        return zip(data, infos)

    def sread(self, selector, timeout):
        if self.wait_for_data(selector, timeout):
            return self.read(selector)
        else:
            return []

    def read(self, selector):
        return self.read_n(MAX_SAMPLES, selector)

    def sread_n(self, n, selector, timeout):
        if self.wait_for_data(selector, timeout):
            return self.read_n(n, selector)
        else:
            return []

    def read_n(self, n, sampleSelector):
        ivec = (SampleInfo * n)()
        infos = cast(ivec, POINTER(SampleInfo))

        SampleVec_t = c_void_p * n
        samples = SampleVec_t()
        nr = the_runtime.ddslib.dds_read(self.handle, samples, n, infos, sampleSelector)
        data = []
        for i in range(nr):
            sp = cast(c_void_p(samples[i]), POINTER(self.topic.data_type))
            if infos[i].valid_data:
                # v = sp[0].value.decode(encoding='UTF-8')
                data.append(sp[0])
            # else:
            #     k = sp[0].key.decode(encoding='UTF-8')
            #     data.append(KeyHolder(k))

        return zip(data, infos)

    def wait_history(self, timeout):
        return the_runtime.ddslib.dds_reader_wait_for_historical_data(self.handle, timeout)


class Error(Exception):
    pass


class Runtime:
    @staticmethod
    def get_runtime():
        global the_runtime
        if the_runtime is not None:
            return the_runtime
        else:
            the_runtime = Runtime()
            return the_runtime

    def __init__(self):
        self.dataListenerMap = {}
        self.subscriptionMatchedListenerMap = {}
        self.livelinessChangeListenerMap = {}

        self.ddslib = CDLL(ospl_lib_path)
        self.bitypes = CDLL(ospl_bit_lib_path)

        self.ddslib.dds_init(0, None)
        self.kv_topic = None
        self.v_topic = None

        self.on_requested_deadline_missed = REQUESTED_DEADLINE_MISSED_PROTO(trivial_on_requested_deadline_missed)
        self.on_requested_incompatible_qos = REQUESTED_INCOMPATIBLE_QOS_PROTO(trivial_on_requested_incompatible_qos)
        self.on_sample_rejected = SAMPLE_REJECTED_PROTO(trivial_on_sample_rejected)
        self.on_liveliness_changed = LIVELINESS_CHANGED_PROTO(trivial_on_liveliness_changed)
        self.on_data_available = DATA_AVAILABLE_PROTO(trivial_on_data_available)
        self.on_subscription_matched = SUBSCRIPTION_MATCHED_PROTO(trivial_on_subscription_matched)
        self.on_sample_lost = SAMPLE_LOST_PROTO(trivial_on_sample_lost)

        # -- QoS operations --
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

        # -- read / take --
        self.ddslib.dds_read.restype = c_int
        self.ddslib.dds_read.argtypes = [c_void_p, POINTER(c_void_p), c_uint32, POINTER(SampleInfo), c_uint32]

        self.ddslib.dds_take.restype = c_int
        self.ddslib.dds_take.argtypes = [c_void_p, POINTER(c_void_p), c_uint32, POINTER(SampleInfo), c_uint32]

        # -- dispoase --

        self.ddslib.dds_instance_dispose.restype = c_uint
        self.ddslib.dds_instance_dispose.argtypes = [c_void_p, c_void_p]

        self.ddslib.dds_write.restype = c_uint
        self.ddslib.dds_write.argtypes = [c_void_p, c_void_p]

        # -- Waitset Operations --

        # create/detele
        self.ddslib.dds_waitset_create.restype = c_void_p
        self.ddslib.dds_waitset_create.argtypes = None
        self.ddslib.dds_waitset_delete.restype = c_int
        self.ddslib.dds_waitset_delete.argtypes = [c_void_p]

        # attach / detach
        self.ddslib.dds_waitset_attach.restype = c_int
        self.ddslib.dds_waitset_attach.argtypes = [c_void_p, c_void_p, c_void_p]
        self.ddslib.dds_waitset_detach.restype = c_int
        self.ddslib.dds_waitset_detach.argtypes = [c_void_p, c_void_p]

        # wait
        self.ddslib.dds_waitset_wait.restype = c_int
        self.ddslib.dds_waitset_wait.argtypes = [c_void_p, POINTER(c_void_p), c_int, c_int64]

        # -- Condition Operations --
        self.ddslib.dds_readcondition_create.restype = c_void_p
        self.ddslib.dds_readcondition_create.argtypes = [c_void_p, c_uint32]
        self.ddslib.dds_condition_delete.restype = None
        self.ddslib.dds_condition_delete.argtypes = [c_void_p]

        global the_runtime
        the_runtime = self

    def register_data_listener(self, handle, fun):
        h = repr(handle)
        self.dataListenerMap[h] = fun

    def register_liveliness_changed_listener(self, handle, fun):
        h = repr(handle)
        self.livelinessChangeListenerMap[h] = fun

    def register_subscription_matched_listener(self, handle, fun):
        h = repr(handle)
        self.subscriptionMatchedListenerMap[h] = fun

    @staticmethod
    def dispatch_data_listener(handle):
        h = repr(handle)
        global the_runtime
        if h in the_runtime.dataListenerMap:
            fun = the_runtime.dataListenerMap[h]
            fun(handle)
        else:
            print('warning>> Trying to dispatch listener for unknown reader {0}'.format(handle))

    @staticmethod
    def dispatch_subscription_matched_listener(handle, s):
        h = repr(handle)
        global the_runtime
        if h in the_runtime.subscriptionMatchedListenerMap:
            fun = the_runtime.subscriptionMatchedListenerMap[h]
            fun(handle, s)

    @staticmethod
    def dispatch_liveliness_changed_listener(handle, s):
        h = repr(handle)
        global the_runtime
        if h in the_runtime.livelinessChangeListenerMap:
            fun = the_runtime.livelinessChangeListenerMap[h]
            fun(handle, s)

    def get_key_value_type_support(self):
        return self.bitypes.dython_bit_KDython_desc

    def get_simple_value_type_support(self):
        return self.bitypes.dython_bit_Dython_desc

    def to_rw_qos(self, ps):
        if ps is None:
            return None

        qos = self.create_dds_qos()

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
            elif p.id == DDS_WRITERDATALIFECYCLE_QOS_POLICY_ID:
                self.ddslib.dds_qset_writer_data_lifecycle(qos, p.auto_dispose)
            return qos


    def to_ps_qos(self, ps):
        if ps is None:
            return None

        qos = self.create_dds_qos()
        xs = list(filter(lambda p: p.id == DDS_PARTITION_QOS_POLICY_ID, ps))

        if len(xs) > 0:
            policy = xs[0]
            L = len(policy.partitions)
            vec = (c_char_p * L)()
            sbuf = list(map(lambda s: s.encode(), policy.partitions))
            vec[:] = sbuf
            self.ddslib.dds_qset_partition(qos, c_uint32(L), vec)
        return qos

    def create_dds_qos(self):
        return c_void_p(self.ddslib.dds_qos_create())

    def release_dds_qos(self, qos):
        self.ddslib.dds_qos_delete(qos)

    def close(self):
        self.ddslib.dds_fini()

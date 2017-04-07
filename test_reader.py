__author__ = 'Angelo Corsaro'

from dds import *
import  time

from ctypes import *

def onDataAvailable(r):
    samples = r.read(1, SampleSelector.newSamples())
    for s in samples:
        print ('reader>> ({0}, {1})'.format(s.key, s.value))

def testDynaTypes():
    rt = dds.Runtime()
    theRuntime = rt
    dp = Participant(0)
    type_support = rt.getKeyValueTypeSupport()
    t = Topic(dp,  'KeyValye', type_support, DDSKeyValue, None)
    s = Subscriber(dp, None)
    # def __init__(self, rt, sub, topic, qos, dataListener):

    dr = DataReader(s, t, None, onDataAvailable)

    time.sleep(6000)

if __name__ == '__main__':
    testDynaTypes()
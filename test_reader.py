__author__ = 'Angelo Corsaro'

from dds.dds import *
import  time

def onDataAvailable(r):
    samples = r.read(1, new_samples())
    for s in samples:
        print ('reader>> ({0}, {1})'.format(s.key, s.value))

def testDynaTypes():
    rt = Runtime()
    dp = Participant(0)
    type_support = rt.get_key_value_type_support()
    t = Topic(dp,  'KeyValue', type_support, DDSKeyValue, None)
    s = Subscriber(dp, None)

    dr = DataReader(s, t, None, onDataAvailable)

    time.sleep(6000)

if __name__ == '__main__':
    testDynaTypes()
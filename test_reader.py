__author__ = 'Angelo Corsaro'

from dds import *
import  time

def onDataAvailable(r):
    samples = r.read(new_samples())
    for (d, i) in samples:
        if i.valid_data:
            print ('reader>> ({0}, {1})'.format(d.key, d.value))
        else:
            print('reader>> ({0}, None)'.format(d.key))

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
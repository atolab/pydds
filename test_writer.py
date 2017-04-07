__author__ = 'Angelo Corsaro'

from dds import *
import  time

if __name__ == '__main__':
    # Always create a runtime to initialise DDS
    rt = dds.Runtime()
    dp = Participant(0)

    type_support = rt.getKeyValueTypeSupport()
    t = Topic(dp, 'KeyValue', type_support, DDSKeyValue, None)

    p = Publisher(dp, None)
    w = DataWriter(p, t, None)

    hello = DDSKeyValue("API", "Python")


    while (True):
        w.write(w.handle, byref(hello))
        print ("writer>> ({0}, {1})".format(hello.key, hello.value))
        time.sleep(1)


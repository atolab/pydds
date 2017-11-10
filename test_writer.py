__author__ = 'Angelo Corsaro'

from dds import *
import  time

if __name__ == '__main__':
    # Always create a runtime to initialise DDS
    rt = Runtime()
    dp = Participant(0)

    type_support = rt.get_key_value_type_support()
    t = Topic(dp, 'KeyValue', type_support, DDSKeyValue, None)

    p = Publisher(dp, None)
    w = DataWriter(p, t, None)

    hello = DDSKeyValue(b'API', b'Python')


    while (True):
        w.write(hello)
        print ("writer>> ({0}, {1})".format(hello.key, hello.value))
        time.sleep(1)


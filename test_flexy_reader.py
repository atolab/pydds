__author__ = 'Angelo Corsaro'

from dds import *
import  time

# TODO: Factor out the definition of Vehicle position...
class VehiclePosition(Topic):
    def __init__(self, cid):
        super(Topic, self).__init__()
        self.x = 0
        self.y = 0
        self.key_ = cid

    def gen_key(self):
        return self.key_

    def moveTo(self, x, y):
        self.x = x
        self.y = y

    def moveBy(self, dx, dy):
        self.x += dx
        self.y += dy

    def __str__(self):
        return 'VehiclePosition({0}, {1}, {2})'.format(self.key_, self.x, self.y)

def onDataAvailable(r):
    samples = r.read(all_samples())
    for s in samples:
        if s[1].valid_data:
            print ('reader>> {0})'.format(s[0]))

def testDynaTypes():
    rt = Runtime()
    dp = Participant(0)

    t = FlexyTopic(dp,  'KeyValue',None, [Reliable(), Persistent(), KeepLastHistory(1)])
    s = Subscriber(dp, [Partition(['dds-python.demo'])])

    dr = FlexyReader(s, t, [Reliable(), Persistent(), KeepLastHistory(1)], None)

    dr.wait_history(dds_secs(2))

    samples = dr.read(all_samples())
    for s in samples:
        if s[1].valid_data:
            print('reader>> {0})'.format(s[0]))

    dr.on_data_available(onDataAvailable)
    time.sleep(6000)

if __name__ == '__main__':
    testDynaTypes()

,_author__ = 'Angelo Corsaro'

from dds import *
import  time
import sys
from random import randint

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

if __name__ == '__main__':

    cid = randint(0, 1000)

    if len(sys.argv) > 1:
        cid = int(sys.argv[0])

    # Always create a runtime to initialise DDS
    rt = Runtime()
    dp = Participant(0)

    print("Persistent id = {0}".format(Persistent().id))
    print("Reliable id = {0}".format(Reliable().id))
    print("KeepLastHistory id = {0}".format(KeepLastHistory(1).id))
    # 'VehiclePosition'
    t = FlexyTopic(dp, 'KeyValue', None, [Reliable(),Persistent(), KeepLastHistory(1)])

    p = Publisher(dp, [Partition(['dds-python.demo'])])
    w = FlexyWriter(p, t, [Reliable(),Persistent(), KeepLastHistory(1), ManualInstanceDispose()])

    vpos = VehiclePosition(cid)
    dx = 1
    dy = 1


    while (True):
        w.write(vpos)
        print('Wrote: {0}'.format(vpos))
        vpos.moveBy(dx, dy)
        #print('Press a key to move the vehicle...')
        #input()
        time.sleep(0.5)

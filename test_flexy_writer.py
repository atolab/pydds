_author__ = 'Angelo Corsaro'

from dds.dds import *
import  time
import sys
from random import randint

class VehiclePosition:
    def __init__(self, cid):
        self.x = 0
        self.y = 0
        self.key = cid

    def moveTo(self, x, y):
        self.x = x
        self.y = y

    def moveBy(self, dx, dy):
        self.x += dx
        self.y += dy

    def __str__(self):
        return 'VehiclePosition({0}, {1}, {2})'.format(self.key, self.x, self.y)

if __name__ == '__main__':

    cid = randint(0, 1000)

    if len(sys.argv) > 1:
        cid = int(sys.argv[0])

    # Always create a runtime to initialise DDS
    rt = Runtime()
    dp = Participant(0)

    # 'VehiclePosition'
    t = FlexyTopic(dp, 'KeyValue', lambda  s: s.key, None)

    p = Publisher(dp, [Partition(['dds-python.demo'])])
    w = FlexyWriter(p, t, [Reliable(),KeepLastHistory(1)])

    vpos = VehiclePosition(cid)
    dx = 1
    dy = 1


    while (True):
        w.write(vpos)
        print('Wrote: {0}'.format(vpos))
        vpos.moveBy(dx, dy)
        time.sleep(1)


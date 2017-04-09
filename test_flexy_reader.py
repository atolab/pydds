__author__ = 'Angelo Corsaro'

from dds import *
import  time

# TODO: Factor out the definition of Vehicle position...
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

def onDataAvailable(r):
    samples = r.read(1, SampleSelector.allSamples())
    for s in samples:
        print ('reader>> {0})'.format(s))

def testDynaTypes():
    rt = dds.Runtime()
    dp = Participant(0)

    t = FlexyTopic(dp,  'KeyValue', lambda x: x.key, None)
    s = Subscriber(dp, [Partition(["dds-python.demo"])])

    dr = FlexyReader(s, t, [Reliable(), KeepLastHistory(1)], onDataAvailable)

    time.sleep(6000)

if __name__ == '__main__':
    testDynaTypes()
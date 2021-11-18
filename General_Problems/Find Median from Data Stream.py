# url - Find Median from Data Stream

class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.l = []       

    def addNum(self, num: int) -> None:
        self.l.append(num)

    def findMedian(self) -> float:
        lenl = len(self.l)
        self.l.sort()
        if lenl % 2 == 1:
            return self.l[lenl//2]
        else:
            return (self.l[(lenl//2)-1]+self.l[lenl//2])/2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

from heapq import *
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.small = []
        self.large = []
        

    def addNum(self, num: int) -> None:
        if len(self.small) == len(self.large):
            heappush(self.large, - heappushpop(self.small, -num))
        else:
            heappush(self.small, - heappushpop(self.large, num))

    def findMedian(self) -> float:
        if len(self.small) == len(self.large):
            return float(self.large[0] - self.small[0]) / 2.0
        else:
            return float(self.large[0])
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

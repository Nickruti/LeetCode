class RecentCounter:

    def __init__(self):
        self.slide_window = deque()
        

    def ping(self, t: int) -> int:
        #1. Append the current call
        self.slide_window.append(t)
        
        #2. Invalidate the outdated pings
        while self.slide_window[0] < t - 3000:
            self.slide_window.popleft()
            
        return len(self.slide_window)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)

'''
Input----
["RecentCounter","ping","ping","ping","ping"]
[[],[1],[100],[3001],[3002]]

Output----
[null,1,2,3,3]
'''


class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        last = 0
        ans = 0
        if meetings[0][0] > 1:
            ans += meetings[0][0] - 1
        last = meetings[0][1]
        
        for i in range(1, len(meetings)):
            if meetings[i][0] - 1 > last:
                ans += meetings[i][0] - last-1
            last = max(last, meetings[i][1])
        
        ans += (days-last)
        
        return ans
        
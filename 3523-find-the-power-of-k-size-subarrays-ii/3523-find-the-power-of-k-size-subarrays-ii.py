class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        ans = []
        dq = deque()
        
        check = True
        for i in range(k):
            while dq and nums[dq[-1]] <= nums[i]:
                dq.pop()
            dq.append(i)
            if i > 0 and nums[i] != nums[i - 1] + 1:
                check = False
        
        if check:
            ans.append(nums[dq[0]])
        else:
            ans.append(-1)
        
        for i in range(k, n):
            if dq[0] < i - k + 1:
                dq.popleft()
            
            while dq and nums[dq[-1]] <= nums[i]:
                dq.pop()
            dq.append(i)
            
            if nums[i] != nums[i - 1] + 1:
                check = False
            
            if nums[i - k + 1] != nums[i - k] + 1:
                check = True
                for j in range(i - k + 2, i + 1):
                    if nums[j] != nums[j - 1] + 1:
                        check = False
                        break
            
            if check:
                ans.append(nums[dq[0]])
            else:
                ans.append(-1)
        
        return ans

class Solution:
    def numberOfChild(self, n: int, k: int) -> int:
        ind = 0
        arr=[]
        for i in range(n):
            arr.append(i)
        while k > 0:
            if arr[ind] == n-1:
                dire = -1
            if arr[ind] == 0:
                dire = 1
            ind += dire
            k -= 1
        return arr[ind]
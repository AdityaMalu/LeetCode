class Solution:
    def compressedString(self, word: str) -> str:
        prev = word[0]
        count = 1
        ans = ''
        for i in range(1,len(word)):
            if count == 9:
                ans+='9'+prev
                count =1
                prev = word[i]
            else:
                if prev != word[i]:
                    ans += str(count)+prev
                    prev = word[i]
                    count = 1
                else:
                    count+=1
                    prev = word[i]
        ans += str(count)+prev
        return ans
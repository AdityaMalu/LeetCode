class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 0, i = 1;
        vector<int> kmp(needle.size(),0);
        while(i<needle.size()){
            if(needle[i] == needle[j]){
                j++;
                kmp[i] = j;
                i++;
            }
            else{
                if(j!=0){
                    j = kmp[j-1];
                }
                else{
                    kmp[i] = 0;
                    i++;
                }
            }
        }

        i = 0,j = 0;
        while(i<haystack.length()){
            if(j == needle.length()){
                return (i-j);
            }
            if(haystack[i] == needle[j]){
                j++;
                i++;
            }
            else if(i<haystack.length() && haystack[i] != needle[j]){
                if(j != 0){
                    j = kmp[j-1];
                }
                else{
                    i++;
                }
            }
        }
        
        if(j == needle.length()){
        return (i-j);   
        }
        return -1;
     
    }
};
class Solution {
public:
    int findComplement(int num) {
        int temp = 0,chc = num;
        while(chc){
            temp = temp<<1 | 1;
            chc>>=1;
        }

        return num^temp;
    }

};
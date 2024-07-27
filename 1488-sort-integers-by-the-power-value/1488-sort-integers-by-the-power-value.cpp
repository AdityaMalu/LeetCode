class Solution {
public:
    int recc(int n){
        if( n == 1) return 0;

        int op1 = 0,op2 = 0;
        if(n%2==0) 
        {
           op1 =  1+ recc(n/2);
        }
        else{
            op2 = 1+ recc(3*n+1);
        }

        return op1+op2;
    }

    static bool comp(pair<int,int> &p1, pair<int,int> &p2){
        if (p1.second == p2.second) return p1.first < p2.first;
        return p1.second < p2.second;
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> v;
        for(int i = lo ; i<=hi ; i++){
            v.push_back({i,recc(i)});
        }

        sort(v.begin(),v.end(),comp);

        for(auto i : v){
            cout<<i.first<<" "<<i.second<<"...";
        }
        return v[k-1].first;



    }
};
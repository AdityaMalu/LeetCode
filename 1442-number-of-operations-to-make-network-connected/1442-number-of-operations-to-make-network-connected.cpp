class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        class DisJointSet{
            public:
            vector<int> size,par;
            DisJointSet(int n){
                size.resize(n+1,0);
                par.resize(n+1);
                for(int i = 0; i < n ; i++){
                    par[i] = i;
                }
            }

            int findpar(int n){
                if(n == par[n]){
                    return n;
                }
                return par[n] = findpar(par[n]);
            }

            void UnionSize(int u,int v){
                int upu = findpar(u);
                int upv = findpar(v);

                if(upu == upv) return;
                if(size[upu] > size[upv]){
                    par[upv] = upu;
                    size[upu] += size[upv];
                }
                else{
                    par[upu] = upv;
                    size[upv] += size[upu];
                }
            }

        };


        DisJointSet st(n);

        
        int ava = 0;
        for(auto i : connections){
            if(st.findpar(i[0]) == st.findpar(i[1])){
                ava++;
            }
            else{
                st.UnionSize(i[0],i[1]);
            }
        }

        int req = 0;
        for(int i = 0 ; i < n ; i++){
            if(st.par[i] == i){
                req++;
            }
        }

        if(ava >= req-1) return req-1;
        return -1;
    }
};
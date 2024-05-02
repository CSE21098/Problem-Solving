class DisjointSet {
public:
    vector<int>  parent, size;
    DisjointSet(int n) {
        parent.resize(n );
        size.resize(n );
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& rest, vector<vector<int>>& req) {
        vector<bool> ans;
        DisjointSet ds(n);
        for(int i=0;i<req.size();i++){
            int u = req[i][0];
            int v = req[i][1];
            DisjointSet prev=ds;
            ds.unionBySize(u,v);
            bool restricted=false;
            for(int j =0 ; j<rest.size();j++){
                int x=rest[j][0];
                int y=rest[j][1];
                if(ds.findUPar(x)==ds.findUPar(y)){
                    restricted=true;
                    break;
                }

            }
            if(restricted){
                ds=prev;
                ans.push_back(false);
            }else ans.push_back(true);

        }
        return ans;
    }
};
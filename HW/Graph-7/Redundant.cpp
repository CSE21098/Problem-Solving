class Solution {
public:
    int parent[1001];
    int find(int x){
        return parent[x]==x ? x: find(parent[x]);
    }
    void doUnion(int a, int b){
        parent[find(a)] = parent[find(b)];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        for(int i=0;i<1001;++i) parent[i] = i;
        for(auto edge: edges){
            int a = edge[0], b = edge[1];
            if(find(a) != find(b)){
                doUnion(a, b);
            }
            else{
                ans = {a,b};
            }

        }
        return ans;
    }
};
class DisjointSet{
public:
    vector < int > parent, rank;
    
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findUParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int node1, int node2){
        int ulpNode1 = findUParent(node1);
        int ulpNode2 = findUParent(node2);
        if(ulpNode1 == ulpNode2)return;
        if(rank[ulpNode1] < rank[ulpNode2])
            parent[ulpNode1] = ulpNode2;
        else if(rank[ulpNode2] < rank[ulpNode1])
            parent[ulpNode2] = ulpNode1;
        else{
            parent[ulpNode1] = ulpNode2;
            rank[ulpNode2]+=1;
        }
    }
    
    bool isConnected(){
        int ctr = 0;
        for(int i = 1; i < parent.size(); i++){
            if(parent[i] == i)
                ctr += 1;
        }
        return (ctr == 1);
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        set < tuple < int, int, int> > removedEdges;
        sort(edges.begin(), edges.end(), [&](vector<int> a, vector<int> b){
            return (a[0] > b[0]);
        });

        int var = 1;
        while(var <= 2){
            DisjointSet ds(n);
            for(int i = 0; i < edges.size(); i++){
                if(edges[i][0] == 3 || edges[i][0] == var){
                    if(ds.findUParent(edges[i][1]) == ds.findUParent(edges[i][2]))
                        removedEdges.insert({
                            (edges[i][0] == 3 ? 3 : var),
                            min(edges[i][1], edges[i][2]),
                            max(edges[i][1], edges[i][2])
                        });
                    else
                        ds.unionByRank(edges[i][1], edges[i][2]);
                }
            }
            if(!ds.isConnected())
                return -1;
            var += 1;
        }
        return removedEdges.size();
    }
};
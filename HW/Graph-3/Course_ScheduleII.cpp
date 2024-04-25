class Solution {
public:
    void dfsHelper(vector<vector<int>>& graph, vector<int>& visited, vector<int>& order, int idx){
        visited[idx] = 0;
        for(int neighbor : graph[idx]){
            if(visited[neighbor] == 1) continue;
            if(visited[neighbor] == 0){
                visited[idx] = 1;
                return;
            }
            dfsHelper(graph, visited, order, neighbor);
        }

        visited[idx] = 1;
        order.push_back(idx);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, -1);
        vector<vector<int>> graph(numCourses);
        for(vector<int>& course : prerequisites){
            graph[course[1]].push_back(course[0]);
        }

        vector<int> order;
        for(int idx=0; idx<numCourses; ++idx){
            if(visited[idx]==1) continue;
            dfsHelper(graph, visited, order, idx);
        }

        if(order.size() < numCourses) return {};
        reverse(order.begin(), order.end());
        return order;
    }
};
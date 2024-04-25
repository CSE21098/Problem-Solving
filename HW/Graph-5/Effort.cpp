class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        set<pair<int, pair<int, int>>> s;
        s.insert({0, {0, 0}});
        while (!s.empty()) {
            auto it = s.begin();
            auto [effort, pos] = *it;
            s.erase(it);
            int x = pos.first;
            int y = pos.second;
            if (x == m - 1 && y == n - 1) {
                return effort;
            }
            for (auto dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];   
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newEffort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                    if (newEffort < efforts[nx][ny]) {
                        efforts[nx][ny] = newEffort;
                        s.insert({newEffort, {nx, ny}});
                    }
                }
            }
        }
        return -1; 
    }
};
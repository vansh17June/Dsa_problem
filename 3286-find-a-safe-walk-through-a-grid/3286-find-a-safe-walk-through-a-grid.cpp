class Solution {
public:
    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m,vector<bool>(health+1,false)));
        queue<pair<int, pair<int, int>>> pq;
        if (grid[0][0] == 1) {
            health--;
        }
        pq.push({0, {0, health}});
        vis[0][0][health]=true;
        while (!pq.empty()) {
            int x = pq.front().first;
            int y = pq.front().second.first;
            int hp = pq.front().second.second;
            pq.pop();
            if (x == n - 1 && y == m - 1 && hp >= 1) {
                return true;
            }
            for (auto it : direction) {
                int nx = x + it.first, ny = y + it.second;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nhp = hp;
                    if (grid[nx][ny] == 1) {
                        nhp--;
                    }
                    if (nhp>=0&&vis[nx][ny][nhp] == false) {
                        pq.push({nx, {ny, nhp}});
                        vis[nx][ny][nhp]=true;
                    }
                }
            }
        }
        return false;
    }
};
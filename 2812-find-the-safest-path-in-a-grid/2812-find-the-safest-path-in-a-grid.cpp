class Solution {
public:
    typedef pair<int, int> p;
    queue<p> pq;
    vector<vector<int>> temp;
    vector<p> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void bfs(vector<vector<int>>& grid, int n) {
        int level = 1;
        while (!pq.empty()) {
            int size = pq.size();
            for (int i = 0; i < size; i++) {
                int x = pq.front().first, y = pq.front().second;
                pq.pop();
                for (auto it : dir) {
                    int nx = x + it.first, ny = y+it.second;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && temp[nx][ny]==INT_MAX) {
                        temp[nx][ny]=level;
                        pq.push({nx,ny});
                    }
                }
            }
            level++;
        }
    }
    bool check(vector<vector<int>>& grid,int sf,int n){
        queue<p>l;
        if(temp[0][0]>=sf){
            l.push({0,0});
        }
        vector<vector<bool>>vis(n+1,vector<bool>(n+1,false));
        vis[0][0]=true;
        while(!l.empty()){
            int x = l.front().first, y = l.front().second;
            l.pop();
            if(x==n-1&&y==n-1&&temp[x][y]>=sf){
                return true;
            }
            for (auto it : dir) {
                    int nx = x + it.first, ny = y+it.second;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n&&vis[nx][ny]==false&&temp[nx][ny]>=sf) {
                        vis[nx][ny]=true;
                        l.push({nx,ny});
                    }
                }
            
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int end = 2 * n, start = 0;
        int ans = 0;
        temp.resize(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    temp[i][j] = 0;
                    pq.push({i, j});
                }
            }
        }
        bfs(grid, n);
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (check(grid, mid,n)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};
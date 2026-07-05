class Solution {
public:
    vector<vector<int>> dir = {{0, -1}, {-1, 0}, {-1, -1}};
    vector<vector<int>> dp;
    vector<vector<vector<long long>>> t;
    long long mod=1e9+7;
    long long help(vector<string>& board, int i, int j, int s, int n) {
        if (i == 0 && j == 0 && s == 0) {
            return 1;
        }
        if (t[i][j][s] != -1) {
            return t[i][j][s];
        }
        long long ans = 0;
        for (vector<int>& x : dir) {
            int nx = i + x[0], ny = j + x[1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                board[nx][ny] != 'X') {
                int val = 0;
                if (board[i][j] >= '0' && board[i][j] <= '9') {
                    val += board[i][j] - '0';
                }
                if (s >= val)
                    ans += help(board, nx, ny, s - val, n)%mod;
            }
        }
        return t[i][j][s] = ans%mod;
    }
    int solve(vector<string>& board, int i, int j, int n) {
        if (i == 0 && j == 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MIN;
        for (vector<int>& x : dir) {
            int nx = i + x[0], ny = j + x[1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                board[nx][ny] != 'X') {
                int val = 0;
                if (board[i][j] >= '0' && board[i][j] <= '9') {
                    val += board[i][j] - '0';
                }
                ans = max(ans, solve(board, nx, ny, n) + val);
            }
        }
        return dp[i][j] = ans;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        dp.resize(101,vector<int>(101,-1));
        int first = solve(board, n-1, n-1, board.size());
         if (first<0) {
            return {0, 0};
        }
       
        t.resize(101, vector<vector<long long>>(101, vector<long long>(first + 1, -1)));
        int second = (int)help(board, n-1, n-1, first, board.size());
        return {first, second};
    }
};
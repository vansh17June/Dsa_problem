class Solution {
public:
    int n, m;
    int dp[301][301];
    int solve(int i, int j, vector<vector<int>>& matrix) {
        if (i >= n || j >= m) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (matrix[i][j] == 0) {
            return dp[i][j] = 0;
        }
        int down = solve(i + 1, j, matrix),
            diagonal = solve(i + 1, j + 1, matrix),
            right = solve(i, j + 1, matrix);
        return dp[i][j] = 1 + min(down, min(right, diagonal));
    }
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    ans+= solve(i, j, matrix);
                }
            }
        }
        return ans;
    }
};
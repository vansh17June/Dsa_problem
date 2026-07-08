class Solution {
public:
    typedef long long ll;
    long long getSum(vector<int>& nums) {
        int n = nums.size();
        vector<ll> prefSum(n + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefSum[i + 1] = prefSum[i] + nums[i];
        }
        long long ans = 0;
        vector<int> p;
        p.push_back(-1);
        for (int x : nums) {
            p.push_back(-2);
            p.push_back(x);
        }
        p.push_back(-2);
        p.push_back(-3);
        n = p.size();
        vector<int> t(n, 0);
        int center = 0, right = 0;
        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i;
            if (right > i) {
                t[i] = min(right - i, t[mirror]);
            }
            while (p[(i + t[i] + 1)] == p[(i - t[i] - 1)]) {
                t[i]++;
            }
            if (i + t[i] > right) {
                right = i + t[i];
                center = i;
            }
        }
        for (int i = 1; i < n - 1; i++) {
            int L = i - t[i];
            int R = i + t[i];

            int left = (L - 1) / 2;
            int right = (R - 3) / 2;

            if (left >= 0 && right >= left)
                ans = max(ans, prefSum[right + 1] - prefSum[left]);
        }
        return ans;
    };
};

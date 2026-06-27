class Solution {
public:
   long long l=1e9;
    bool isPower(int n) {
        if (n == 1) {
            return true;
        }
        return (n & (n - 1))==0;
    }
    int maximumLength(vector<int>& nums) {
        int ans = 1;
        unordered_map<int, int> mp;
        int count_1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count_1++;
            }
            mp[nums[i]]++;
        }
        count_1 = count_1 % 2 ? count_1 : count_1 - 1;
        ans = max(count_1, ans);
        for (int i = 0; i < nums.size(); i++) {
            long long x = nums[i];
            int len = 0;
            int k = 1;
            if (nums[i] == 1)
                continue;
            while (x <= 1000000000) {
                if (mp.find(x) != mp.end() && mp[x] >= 1) {
                    len++;
                } else {
                    break;
                }
                if(x*x<=l&&mp[x]>=2&&mp.find(x*x)!=mp.end()){
                     len++;
                     x*=x;
                }else{
                    break;
                }
            }
            
                ans = max(ans, len);
        }
        return ans;
    }
};

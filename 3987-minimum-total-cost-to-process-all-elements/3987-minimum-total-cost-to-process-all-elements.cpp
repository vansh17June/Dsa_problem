class Solution {
public:
    long long mod = 1e9 + 7;
    int minimumCost(vector<int>& nums, int k) {
        long long ans = 0;
        long long l = k;
        long long temp = k;
        long long cost = 0;
        for (int x : nums) {
            if (l < x) {

                long long n = (x - l) / temp;
                if ((x - l) % temp) {
                    n++;
                }
                l = l + (n)*temp;

                long long p = cost - 1;
                long long t = 0;
                if (p >= 0) {
                    t = ((cost + 1) * cost) / 2;
                }
                cost += n;
                cost%=mod;
                ans += cost * (cost + 1) / 2;
                
                ans -= t;
                if(ans<0){
                    ans+=mod;
                }
                if(ans<0){
                    ans+=mod;
                }
                ans%=mod;
            }
            l -= x;
        }
        if(ans<0){
            ans+=mod;
        }
        ans%=mod;
        return (int)ans;
    }
};
// l>=x
// l+n*temp>=x

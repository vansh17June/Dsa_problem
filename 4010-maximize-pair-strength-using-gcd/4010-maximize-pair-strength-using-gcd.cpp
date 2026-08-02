class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans=LLONG_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long x=1ll*((1ll*nums[i] * nums[j]) / pow(gcd(nums[i], nums[j]),2));
               ans=max(ans,x);
            }
        }
        return ans;
    }
};
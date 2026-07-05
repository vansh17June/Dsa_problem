class Solution {
public:
    typedef long long ll;
    ll mod=1e9+7;
    long long solve(vector<int>& nums,int k){
        ll sum=LLONG_MIN,temp=sum;
        for(int i=0;i<nums.size();i++){
            int val=(nums[i]%k)?-nums[i]:nums[i];
            if(temp<0){
                temp=val;
            }else{
                temp+=val;
            }
            sum=max(sum,temp);
        }
        return sum;
    }
    int divisibleGame(vector<int>& nums) {
        long long ans=INT_MIN;
        set<int>s;
        for(int x:nums){
            for(int d=1;d*d<=x;d++){
                if(x%d==0){
                    if(d>1){
                        s.insert(d);
                    }
                    if(x/d>1){
                        s.insert(x/d);
                    }
                }
            }
        }
        s.insert(2);
        int t;
        
        for(int k:s){
           long long val=(solve(nums,k))%mod;
           if(val>ans){
            ans=val;
            t=k;
           }
        }
        return (int) ((ans*t)%mod+mod)%mod;
    }
};

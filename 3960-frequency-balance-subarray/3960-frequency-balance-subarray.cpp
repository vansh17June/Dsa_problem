class Solution {
public:
    int getLength(vector<int>& nums) {
        int ans=1;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>mp1;
            unordered_map<int,int>mp2;
            int x=0,s=0;
            for(int j=i;j<nums.size();j++){
                if(mp1.find(nums[j])!=mp1.end()){
                    mp2[mp1[nums[j]]]--;
                }
                mp1[nums[j]]++;
                mp2[mp1[nums[j]]]++;
                if(x<mp1[nums[j]]){
                    x=mp1[nums[j]];
                }
                s=mp2[x];
                if(1==mp1.size()){
                    ans=max(ans,j-i+1);
                }else if(x%2==0&&s<mp1.size()&&mp2[x/2]==mp1.size()-s){
                     ans=max(ans,j-i+1);
                }

            }
        }
        return ans;
    }
};
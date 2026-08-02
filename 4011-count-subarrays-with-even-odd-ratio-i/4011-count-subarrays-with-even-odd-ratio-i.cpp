class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int x=0,y=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
               if(nums[j]%2==0) x++;
               if(nums[j]%2==1) y++;
               if(y>0&&x*b<=y*a){
                  ans++;
               }
            }
            x=0,y=0;
        }
        return ans;
    }
};
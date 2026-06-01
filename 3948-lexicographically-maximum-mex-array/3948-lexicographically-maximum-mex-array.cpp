class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        vector<int>ans;
        int size=*max_element(nums.begin(),nums.end());
        vector<int>seen(size+2,0),freq(size+2,0);
        for(int x:nums)
          freq[x]++;
        
        int mex=0;
        for(int i=0;i<nums.size();i++){
           while(seen[mex]){
            mex++;
           }
           if(freq[mex]==0){
            ans.push_back(mex);
            for(int j=0;j<=mex;j++){
                seen[j]=0;
            }
            mex=0;
           }
           seen[nums[i]]=1;
           freq[nums[i]]-=1;
        }
        while(seen[mex]){
           mex++;
        }
        if(ans.size()!=nums.size())
          ans.push_back(mex);
        return ans;
    }
};
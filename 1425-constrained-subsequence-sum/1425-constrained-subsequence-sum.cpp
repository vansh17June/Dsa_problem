class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int>t(nums.size());
        for(int i=0;i<nums.size();i++){
            t[i]=nums[i];
        }
        deque<int>dq;
        int ans=*max_element(nums.begin(),nums.end());
        dq.push_back(0);
        for(int i=1;i<nums.size();i++){
            while(!dq.empty()&&i-k>dq.front()){
                dq.pop_front();
            }
            ans=max(ans,t[dq.front()]+nums[i]);
            t[i]=max(t[i],t[dq.front()]+t[i]);
            while(!dq.empty()&&t[dq.back()]<t[i]){
               dq.pop_back();
            }
            dq.push_back(i);
            
            
            
        }
        return ans;
    }
};

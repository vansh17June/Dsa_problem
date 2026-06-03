class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans=INT_MAX,t=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            t=min(landStartTime[i]+landDuration[i],t);
        }
        for(int i=0;i<waterStartTime.size();i++){
            ans=min(max(waterStartTime[i],t)+waterDuration[i],ans);
        }
        t=INT_MAX;
        for(int i=0;i<waterStartTime.size();i++){
            t=min(waterStartTime[i]+waterDuration[i],t);
        }
        for(int i=0;i<landStartTime.size();i++){
            ans=min(max(landStartTime[i],t)+landDuration[i],ans);
        }

        return ans;
        
    }
};
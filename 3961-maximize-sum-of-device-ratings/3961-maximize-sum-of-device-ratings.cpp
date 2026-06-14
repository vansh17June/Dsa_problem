class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long  long ans=0;
        int temp1=INT_MAX,temp2=INT_MAX;
        for(int i=0;i<units.size();i++){
            int first_min=INT_MAX,second_min=INT_MAX;
            for(int j=0;j<units[0].size();j++){
                if(units[i][j]<first_min){
                    second_min=first_min;
                    first_min=units[i][j];
                }else if(units[i][j]<second_min){
                    second_min=units[i][j];
                }
            }
            if(second_min==INT_MAX){
                second_min=first_min;
            }
            ans+=1ll*second_min;
            
            temp1=min(temp1,second_min),temp2=min(temp2,first_min);
        }
        ans+=(temp2-temp1);
        return ans;
    }
};
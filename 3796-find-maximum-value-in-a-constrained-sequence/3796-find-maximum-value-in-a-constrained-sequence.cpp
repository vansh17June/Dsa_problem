class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int>temp(n,INT_MAX);
        temp[0]=0;
        for(vector<int>x:restrictions){
            temp[x[0]]=min(temp[x[0]],x[1]);
        }
        for(int i=1;i<n;i++){
            temp[i]=min(temp[i],diff[i-1]+temp[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            temp[i]=min(temp[i],diff[i]+temp[i+1]);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,temp[i]);
        }
        return ans;
    }
};
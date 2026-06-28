class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=1;
        int t=1;
        for(int i=0;i<arr.size();i++){
           if(t<=arr[i]){
            ans=max(t,ans);
            t++;
           }else if(t>arr[i]){
            continue;
           }
        }
        return ans;
    }
};
// 2 2 1 2 1       1 100 1000   1 1 2 2 2      5  2
// 1 1 2 2 2

// 1 2 3


// 1 2 3 4 5
// 1 2 3 4 5
// MAP TO STORE FREQ 
// PEHLA DKEHUKA 1  HA 
// AGAR NAHI HA TO SMALLEST ELEMENT 1 PAR CHANGE HO JAIGA 

// 1 1 1 1 1

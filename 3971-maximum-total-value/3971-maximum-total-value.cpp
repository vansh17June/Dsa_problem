class Solution {
public:
    long long mod=1e9+7;
    long long check(vector<int>& value, vector<int>& decay, int m){
        long long count=0;
        for(int i=0;i<value.size();i++){
            if(value[i]<m){
                continue;
            }
            count+=(abs(m-value[i])/decay[i])+1;
        }
        return count;
    }

    long long maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
    
        long long start=1,end=*max_element(value.begin(),value.end()),cuttoff=0;
        while(start<=end){
           long long mid=start+(end-start)/2;
           if(check(value,decay,mid)>=1ll*m){
            cuttoff=mid;
            start=mid+1;
           }else{
            end=mid-1;
           }
        }
        
        long long sum=0,count=0;
        for(int i=0;i<value.size();i++){
            if(value[i]<cuttoff){
                continue;
            }
            long long k=(abs(cuttoff-value[i])/decay[i])+1;
            count+=k;
           sum += k * (2LL * value[i] - 1LL * decay[i] * (k - 1)) / 2;
            sum%=mod;
        }
        sum=(sum-((count-m)*cuttoff)%mod+mod)%mod;

        return (int)sum;
    }
};
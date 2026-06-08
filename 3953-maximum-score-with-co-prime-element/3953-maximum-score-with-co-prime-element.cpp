class Solution {
public:
    int maxScore(vector<int>& nums, int maxVal) {
        //selecting maximum value of selectedValue 
        int x=max(*max_element(nums.begin(),nums.end()),maxVal);
        
        vector<int>spf(x+1);
        iota(spf.begin(),spf.end(),0);
        for(int i=2;i*i<=x;i++){
            if(spf[i]==i){
                for(int j=i*i;j<=x;j+=i){
                   if(spf[j]==j){
                    spf[j]=i;
                   }
                }
            }
        }
        vector<int>freq(x+1,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<int>mults(x+1,0);
        for(int i=1;i<=x;i++){
            for(int j=i;j<=x;j+=i){
                mults[i]+=freq[j];
            }
        }
        int ans=(freq[1]>0?1:0);
        for(int i=x;i>=2;i--){
            if(ans>=i){
                return ans;
            }
            int rem=0;
            rem-=freq[i];
            vector<int>prime;
            int t=i;
            while(t>1){
                int y=spf[t];
                prime.push_back(y);
                while(t%y==0){
                    t/=y;
                }
            }
            int k=prime.size();
            for(int mask=1;mask<(1<<k);mask++){
                int prod=1,bit=0;
                for(int q=0;q<k;q++){
                    if(mask&(1<<q)){
                        bit++;
                        prod*=prime[q];
                    }

                }
                if(bit&1){
                    rem+=mults[prod];
                }else{
                    rem-=mults[prod];
                }
                
            }
            if(freq[i]>0){
                int cost=freq[i]-1+rem;
                ans=max(ans,i-cost);
            }else if(i<=maxVal){
               int cost=(rem>0)?rem:1;
               ans=max(ans,i-cost);
            }
        }
        return ans;
    }
};

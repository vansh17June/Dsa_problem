class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int>temp(n,0);
        for(int i=0;i<n;i++){
            int v=lights[i];
            int idx=max(0, i - v);
            temp[idx]=max(temp[idx],i+v-idx);
        }
        vector<int>p;
        int jump=0;
        for(int i=0;i<n;i++){
           if(jump==0&&temp[i]==0){
            p.push_back(i);
           }else{
            jump--;
            jump=max(jump,temp[i]);
           }

        }
        int ans=0;
        int j=0;
        while(j<p.size()){
            int time=0;
            int val=p[j];
         
            while(j+1<p.size()&&time<2&&val+1==p[j+1]){
                j++;
                val=p[j];
                time++;
            }
            ans++;
            j++;
        }
        return ans;
    }
};

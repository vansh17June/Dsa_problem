class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        queue<int>q;
        for(int i=1;i<9;i++) q.push(i);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(x>high){
                continue;
            }
            int last_digit=x%10;
            if(last_digit!=9){
                q.push(x*10+last_digit+1);
            }
            if(x>=low&&x<=high){
                ans.push_back(x);
            }
        }
        return ans;
    }
};
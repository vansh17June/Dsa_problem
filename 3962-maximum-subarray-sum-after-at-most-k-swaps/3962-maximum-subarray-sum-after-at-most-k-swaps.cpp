class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        long long ans = LLONG_MIN / 2;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            multiset<int> t1, t2;
            long long currsum = 0;
            for (int i = 0; i < n - k; i++) {
                t1.insert(sorted[i]);
            }
            for (int i = n - k; i < n; i++) {
                t2.insert(sorted[i]);
            }
            for (int j = i; j < nums.size(); j++) {

                int val = nums[j];
                if(t1.size()>0){
                    auto a=t1.find(val);
                    if(a!=t1.end()){
                        t2.insert(*a);
                        t1.erase(a);
                    }else{
                        auto b=prev(t1.end());
                        t2.insert(*b);
                        t1.erase(b);
                    }
                }
                auto a=prev(t2.end());
                currsum+=*a;
                t2.erase(a);
                ans = max(ans, currsum);
            }
        }
        return ans;
    }
};
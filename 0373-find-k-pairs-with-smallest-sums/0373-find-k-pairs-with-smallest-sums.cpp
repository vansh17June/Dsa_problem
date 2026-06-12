class Node{
    public:
    int a,b,c;
    Node(int a,int b,int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
};
class Solution {
public:
    struct cmp{
        bool operator()(Node* a,Node* b){
            return a->a>b->a;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Node*,vector<Node*>,cmp>pq;
        vector<vector<int>>ans;
        set<pair<int,int>>visited;
        pq.push(new Node(nums1[0]+nums2[0],0,0));
        visited.insert({0,0});
        while(k--){
            Node* temp=pq.top();
            pq.pop();
            ans.push_back({nums1[temp->b],nums2[temp->c]});
            int b=temp->b,c=temp->c;
            if(b+1<nums1.size()&&visited.find({b+1,c})==visited.end()){
                pq.push(new Node(nums1[b+1]+nums2[c],b+1,c));
                visited.insert({b+1,c});
            }
            if(c+1<nums2.size()&&visited.find({b,c+1})==visited.end()){
                pq.push(new Node(nums1[b]+nums2[c+1],b,c+1));
                visited.insert({b,c+1});
            }
        }
        return ans;

    }
};
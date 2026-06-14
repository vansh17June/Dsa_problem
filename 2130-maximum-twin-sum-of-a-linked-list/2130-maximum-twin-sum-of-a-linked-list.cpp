/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>v;
        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        v.resize(n);
        temp=head;
        for(int i=0;i<n/2;i++){
            v[i]=temp->val;
            temp=temp->next;
        }
        for(int i=(n/2)-1;i>=0;i--){
            v[i]+=temp->val;
            temp=temp->next;
        }
        int ans=*max_element(v.begin(),v.end());
        return ans;
    }
};
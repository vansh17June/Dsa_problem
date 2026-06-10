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
    struct cmp{
        bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val;
        }
    };
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
       for(int i=0;i<lists.size();i++){
        if(lists[i]){
        pq.push(lists[i]);
        }
       }
       ListNode* head=(pq.size())?pq.top():NULL;
       ListNode* temp=head;
       if(pq.size())
       pq.pop();
       if(temp&&temp->next){
        pq.push(temp->next);
       }
       while(!pq.empty()){
        ListNode* t=pq.top();
        pq.pop();
        if(t->next){
            pq.push(t->next);
        }
        temp->next=t;
        temp=t;
       }
       return head;
    }
};
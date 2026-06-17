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
    pair<ListNode* ,ListNode* >reverse(ListNode* t1,ListNode* t2){
          ListNode* temp=t1;
          ListNode* prev=NULL;
          while(temp&&temp!=t2){
            ListNode* n=temp->next;
            temp->next=prev;
            prev=temp;
            temp=n;
          }
          if(temp)
          temp->next=prev;
          return {temp,t1};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* t1=head;
        ListNode* t2=head;
        ListNode* t3;
        for(int i=1;i<k&&t2;i++){
            t2=t2->next;
        }
        if(t2==NULL){
            return t1;
        }
        t3=t2->next;
        pair<ListNode* ,ListNode* > x=reverse(t1,t2);
        ListNode* ans=x.first;
        ListNode* last_tail=x.second;
        t1=t3,t2=t3;

        while(t2){
            
            for(int i=1;i<k&&t2;i++){
           
            t2=t2->next;
        }
        if(t2==NULL){
            last_tail->next=t1;
            break;
        }
        if(t2){
            t3=t2->next;
        }
        auto x=reverse(t1,t2);
        last_tail->next=x.first;
        last_tail=x.second;
        if(t2){
            t1=t3,t2=t3;
        }
        }
        return ans;

    }
};
// 1 2 3 4 5
// 2 1 4 3 5

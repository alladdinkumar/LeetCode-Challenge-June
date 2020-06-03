/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node->next==NULL)
            return;
        ListNode *prev ,*curr,*p;
        p=node;
        prev=node;
        curr=node->next;
        while(curr!=NULL )
        {
            prev->val=curr->val;
            p=prev;
            prev=curr;
            curr=curr->next;
        }
        p->next=NULL;
    }
};

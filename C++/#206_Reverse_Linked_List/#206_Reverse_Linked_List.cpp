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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *curr = head->next, *prev = head, *next = curr->next;

        head->next = NULL;
        
        while(curr != NULL)
        {
            //cout << prev->val << " " << curr->val << endl;
            curr->next = prev;
            prev = curr;
            curr = next;
            
            if(curr == NULL)
                break;
            
            next = curr->next;
        }

        return prev;
        
    }
};
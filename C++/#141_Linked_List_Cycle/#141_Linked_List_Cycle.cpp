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
    bool hasCycle(ListNode *head) {
        /* map method, time O(N)*/
        /*
        map<ListNode*, int> map;
        
        while(head != NULL)
        {
            if(head->next == NULL)
                return false;
            else if(map.find(head) != map.end())
                return true;
            else
            {
                map[head] = head->val;
                head = head->next;
            }
        }
        
        return false;
        */
        
        /* Modify list method, time: O(N) */
        ListNode* loopNode = head;
        
        while(head != NULL)
        {
            if(head->next == loopNode)
                return true;
            else
            {
                ListNode* prev = head;
                head = head->next;
                prev->next = loopNode;
            }
        }
        
        return false;
    }
};
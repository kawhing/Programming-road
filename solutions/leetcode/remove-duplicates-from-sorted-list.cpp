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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || (head && !head->next))
            return head;
        ListNode *cnt = head;
        while(cnt){
            while(cnt->next && cnt->val == cnt->next->val){
                ListNode *tempNode = cnt->next;
                cnt->next = tempNode->next;
                delete tempNode;
            }
            cnt = cnt->next;
            
        }
        return head;
    }
};
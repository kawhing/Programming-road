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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l = new ListNode();
        ListNode *cnt = l, *cnt1 = l1, *cnt2 = l2, *cntlast;
        
        while(cnt1 || cnt2){
            int addNum = 0, addenNum = 0;
            if(cnt1) addNum = cnt1->val;
            if(cnt2) addenNum = cnt2->val;

            int sumNum = addNum + addenNum + cnt->val;
            cnt->val = sumNum % 10;
            
            ListNode* newNode = new ListNode(sumNum / 10);
            
            cnt->next = newNode;
            cnt = cnt->next;
            
            if(cnt1) cnt1 = cnt1->next;
            if(cnt2) cnt2 = cnt2->next;
            cntlast = cnt;
        }
        cnt = l;
        while(cnt->next->next){
            cnt = cnt->next;
        }
        if(cnt->next->val == 0){
            ListNode* tempNode = cnt->next;
            cnt->next = nullptr;
            delete(tempNode);
        }
        return l;
    }
};
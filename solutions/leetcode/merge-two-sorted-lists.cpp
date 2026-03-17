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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return nullptr;
        ListNode* list;
        bool isEmptyList = true;
        ListNode *l1 = list1, *l2 = list2, *cnt = nullptr;
        int num1, num2;
        while(l1 || l2){
            if(l1) num1 = l1->val;
            if(l2) num2 = l2->val;
            int newVal;
            if(l1 && l2){
                if(l1->val > l2 ->val){
                    newVal = l2->val;
                    l2 = l2->next;
                }else{
                    newVal = l1->val;
                    l1 = l1->next;
                }
            }else if(l1 == nullptr && l2){
                newVal = num2;
                l2 = l2->next;
            }else if(l1 && l2 == nullptr){
                newVal = num1;
                l1 = l1->next;
            }
            
            if(isEmptyList){
                list = new ListNode(newVal);
                cnt = list;
                isEmptyList = false;

            }else{
                cnt->next = new ListNode(newVal, cnt->next);
                cnt = cnt->next;
            }
        }
        return list;
    }
};
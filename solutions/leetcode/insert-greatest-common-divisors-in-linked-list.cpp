//在链表中插入最大公约数
//仅仅是一个leetcode题解类，非完整代码
class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;
        while(current->next != nullptr){
            ListNode* newNode = new ListNode;
            newNode->val = gcd(current->val, current->next->val);
            newNode->next = current->next;
            current->next = newNode;
            current = current->next->next;
        }
        return head;
    }
};
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
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* third = second->next;
        while (third != nullptr) {
            second->next = first;
            first = second;
            second = third;
            third = third->next;
        }
        head->next = nullptr;
        second->next = first;
        return second;
    }
};
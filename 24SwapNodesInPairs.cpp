struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* first = head;
    if (first == nullptr)
      return nullptr;
    ListNode* second = first->next;
    if (second == nullptr)
      return first;
    ListNode* newHead = second;
    ListNode* third = second->next;
    second->next = first;
    first->next = third;
    if (third == nullptr)
      return newHead;
    ListNode* forth = third->next;
    for (;;) {
      second = first->next;
      if (second == nullptr)
        return newHead;
      third = second->next;
      if (third == nullptr)
        return newHead;
      forth = third->next;
      first->next = third;
      third->next = second;
      second->next = forth;
      first = second;
    }
  }
};

int main() {}
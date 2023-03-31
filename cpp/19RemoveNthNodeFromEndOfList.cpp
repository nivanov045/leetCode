struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* lNode = head;
    ListNode* rNode = head;
    for (int i = 0; i < n - 1; ++i)
      rNode = rNode->next;
    if (rNode->next == nullptr) {
      lNode = head->next;
      delete head;
      return lNode;
    }
    rNode = rNode->next;
    while (rNode->next != nullptr) {
      rNode = rNode->next;
      lNode = lNode->next;
    }
    rNode = lNode->next;
    lNode->next = rNode->next;
    delete rNode;
    return head;
  }
};
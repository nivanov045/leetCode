//  21. Merge Two Sorted Lists
//  Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes
//  of the first two lists.

#include <iostream>
#include <string>
#include <map>
#include <list>

struct ListNode {
  ListNode(int x) : val(x), next(nullptr) {}

  int val;
  ListNode *next;
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr)
      return nullptr;
    if (l1 == nullptr)
      return l2;
    if (l2 == nullptr)
      return l1;
    ListNode* result = new ListNode(0);
    if (l1->val < l2->val) {
      result->val = l1->val;
      l1 = l1->next;
    }
    else {
      result->val = l2->val;
      l2 = l2->next;
    }
    ListNode* current = result;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        ListNode* newNode = new ListNode(l1->val);
        current->next = newNode;
        l1 = l1->next;
      }
      else {
        ListNode* newNode = new ListNode(l2->val);
        current->next = newNode;
        l2 = l2->next;
      }
      current = current->next;
    }
    if (l1 == nullptr) {
      current->next = l2;
    }
    else {
      current->next = l1;
    }
    return result;
  }
};
int main(int argc, char* argv[])
{
  
  return 0;
}
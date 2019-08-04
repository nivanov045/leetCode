//  2. Add Two Numbers
//  You are given two non-empty linked lists representing two non-negative integers. 
//  The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//  You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
    bool operator==(const ListNode& otherVal) {
      if (val != otherVal.val)
        return false;
      auto thisNextNode = next;
      auto otherNextNode = otherVal.next;
      while (thisNextNode != nullptr && otherNextNode != nullptr) {
        if (thisNextNode->val != otherNextNode->val)
          return false;
        thisNextNode = thisNextNode->next;
        otherNextNode = otherNextNode->next;
      }
      if (thisNextNode != nullptr || otherNextNode != nullptr)
        return false;
      return true;
    }
    bool operator!=(const ListNode& otherVal) {
      return !(operator==(otherVal));
    }
};
 
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    bool overaged = false;
    int valForNode = 0;
    auto tmpVal = l1->val + l2->val;
    if (tmpVal > 9) {
      valForNode = tmpVal % 10;
      overaged = true;
    }
    else {
      valForNode = tmpVal;
    }
    ListNode* result = new ListNode(valForNode);
    ListNode* l1NextNode = l1->next;
    ListNode* l2NextNode = l2->next;
    ListNode* curResultNode = result;
    while (l1NextNode != nullptr && l2NextNode != nullptr) {
      auto tmpVal = l1NextNode->val + l2NextNode->val + (overaged ? 1 : 0);
      if (tmpVal > 9) {
        valForNode = tmpVal % 10;
        overaged = true;
      }
      else {
        valForNode = tmpVal;
        overaged = false;
      }
      ListNode* newResultNode = new ListNode(valForNode);
      curResultNode->next = newResultNode;
      curResultNode = curResultNode->next;
      l1NextNode = l1NextNode->next;
      l2NextNode = l2NextNode->next;
    }
    if (l1NextNode == nullptr && l2NextNode == nullptr) {
      if (overaged) {
        curResultNode->next = new ListNode(1);
        return result;
      }
    }
    ListNode* taleListNode = l1NextNode == nullptr ? l2NextNode : l1NextNode;
    if (overaged) {
      while (taleListNode != nullptr && overaged) {
        auto tmpVal = taleListNode->val + 1;
        if (tmpVal > 9) {
          valForNode = tmpVal % 10;
          overaged = true;
        }
        else {
          valForNode = tmpVal;
          overaged = false;
        }
        ListNode* newResultNode = new ListNode(valForNode);
        curResultNode->next = newResultNode;
        curResultNode = curResultNode->next;
        taleListNode = taleListNode->next;
      }
    }
    while (taleListNode != nullptr) {
      curResultNode->next = new ListNode(taleListNode->val);
      curResultNode = curResultNode->next;
      taleListNode = taleListNode->next;
    }
    if (overaged)
      curResultNode->next = new ListNode(1);
    return result;
  }
};

int main(int argc, char* argv[])
{
  Solution sol;
  ListNode* testRootFirst = new ListNode(2);
  ListNode* testNotRootFirst = new ListNode(4);
  testRootFirst->next = testNotRootFirst;
  testNotRootFirst->next = new ListNode(3);
  
  ListNode* testRootSecond = new ListNode(5);
  ListNode* testNotRootSecond = new ListNode(6);
  testRootSecond->next = testNotRootSecond;
  testNotRootSecond->next = new ListNode(4);
  
  ListNode* resultRoot = new ListNode(7);
  ListNode* resultNotRoot = new ListNode(0);
  resultRoot->next = resultNotRoot;
  resultNotRoot->next = new ListNode(8);
  
  std::map<std::pair<ListNode*, ListNode*>, ListNode*> tests = {
    {{testRootFirst, testRootSecond},resultRoot}
  };
  for (auto test : tests) {
    auto curVr = test.first;
    if (*sol.addTwoNumbers(testRootFirst, testRootSecond) != *test.second) {
      std::cout << "Mistake at test!" << std::endl;
      system("pause");
      return 1;
    }
  }
  return 0;
}
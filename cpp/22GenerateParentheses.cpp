class Solution {
  struct node {
    node* leftNode;
    node* rightNode;
    std::string bracket;
    int sumInNode;
    size_t openBracketsInNode;
  };
public:
  vector<string> generateParenthesis(int n) {
  vector<string> result;
  if (n == 0)
    return result;

  size_t depth = 1;
  std::vector<node*> leafs;
  leafs.push_back(new node({ nullptr, nullptr, "(", 1, 1 }));
  while (depth < n * 2) {
    std::vector<node*> newLeafs;
    for (auto l : leafs) {
      if (l->openBracketsInNode < n) {
        node* newLeftNode = new node({ nullptr, nullptr, l->bracket + '(', l->sumInNode + 1,
          l->openBracketsInNode + 1 });
        l->leftNode = newLeftNode;
        newLeafs.push_back(newLeftNode);
      }
      if (l->sumInNode > 0) {
        node* newRightNode = new node({ nullptr, nullptr, l->bracket + ')', l->sumInNode - 1,
          l->openBracketsInNode });
        l->rightNode = newRightNode;
        newLeafs.push_back(newRightNode);
      }
    }
    for (auto l : leafs)
      delete(l);
    leafs = move(newLeafs);
    ++depth;
  }
  for (auto l : leafs)
    result.push_back(l->bracket);
  return result;;
  }
};
#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};


bool isBinarySearchTree_(const vector<Node>& tree, int node, long long min, long long max) {

  // First check that the left and right keys fall within bounds
  int left = tree[node].left;
  int right = tree[node].right;

  bool isBinaryLeft = true;
  bool isBinaryRight = true;

  if (left == -1) {
    // Nothing
  }

  // Less than equal?
  else if ((tree[left].key > max) || (tree[left].key < min)) {
    isBinaryLeft = false;
  }

  else if (tree[left].key > tree[node].key) {
    isBinaryLeft = false;
  }

  else {

    isBinaryLeft = isBinarySearchTree_(tree, left, min, tree[node].key);
  }

  if (!isBinaryLeft) {
    return false;
  }

  if (right == -1) {
    // Nothing
  }

  // Less than equal?
  else if ((tree[right].key > max) || (tree[right].key < min)) {
    isBinaryRight = false;
  }

  else if (tree[right].key < tree[node].key) {
    isBinaryRight = false;
  }

  else {

    isBinaryRight = isBinarySearchTree_(tree, right, tree[node].key, max);  
  }
  
  if (!isBinaryRight) {
    return false;
  }
  
  return true;
}


bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here

  if (tree.empty()) {
    return true;
  }

  Node root = tree[0];

  int right = root.right;
  int left = root.left;

  bool left_tree = true;
  bool right_tree = true;

  if (left == -1) {
    // Do nothing
  }

  // Check if left key of root node is not less than root key
  else if (tree[left].key >= root.key) {
    return false;
  }

  if (right == -1) {
    // Do nothing
  }

  else if (tree[right].key <= root.key) {
    return false;
  }


  // Search Left Side of Tree
  if (left != -1) {
    left_tree = isBinarySearchTree_(tree, left, 0x8000000000000000, root.key);
  }
  
  if (!left_tree) {
    return false;
  }

  if (right != -1) {
    right_tree = isBinarySearchTree_(tree, right, root.key, 0x7FFFFFFFFFFFFFFF);
  }
  
  if (!right_tree) {
    return false;
  }

  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  void inOrderTraversal(int node, vector<int>& result) {

    int l = left[node];
    int r = right[node];

    if (l == -1) {
      // Do nothing
    }

    else {

      inOrderTraversal(l, result);
    }

    result.push_back(key[node]);

    if (r == -1) {
      // Do nothing
    }

    else {

      inOrderTraversal(r, result);
    }

    return;
  }

  vector <int> in_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that

    if (key.empty()) {
      return result;
    }

    inOrderTraversal(0, result);

    return result;
  }

   void preOrderTraversal(int node, vector<int>& result) {

    int l = left[node];
    int r = right[node];

    result.push_back(key[node]);

    if (l == -1) {
      // Do nothing
    }

    else {

      preOrderTraversal(l, result);
    }

    if (r == -1) {
      // Do nothing
    }

    else {

      preOrderTraversal(r, result);
    }

    return;
  }

  vector <int> pre_order() {
    vector<int> result;    
    // Finish the implementation
    // You may need to add a new recursive method to do that
    
    if (key.empty()) {
      return result;
    }

    preOrderTraversal(0, result);

    return result;
  }

  void postOrderTraversal(int node, vector<int>& result) {

    int l = left[node];
    int r = right[node];

    if (l == -1) {
      // Do nothing
    }

    else {

      postOrderTraversal(l, result);
    }

    if (r == -1) {
      // Do nothing
    }

    else {

      postOrderTraversal(r, result);
    }

    result.push_back(key[node]);

    return;
  }

  vector <int> post_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    
    if (key.empty()) {
      return result;
    }

    postOrderTraversal(0, result);

    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}


#include "util.h"

bool areEqual(TreeNode* s, TreeNode* t) {
    //if any are null
    if (s == nullptr || t == nullptr) {
      return s == t;  // both null
    }
    //if vals not equal then not even worth comparing
    //if they are, then keep searching in the same directions
    return s->val == t->val
      && areEqual(s->left, t->left)
      && areEqual(s->right, t->right);
  }
//concise solution
  bool Solution::isSubtree(TreeNode* s, TreeNode* t) {
      // second and third calls are to explore the tree
    return areEqual(s, t)
      || (s->left && isSubtree(s->left, t))
      || (s->right && isSubtree(s->right, t));
  }

int main() {

    return 0;
}
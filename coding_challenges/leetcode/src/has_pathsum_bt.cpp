#include "util.h"
bool Solution::hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;
    if(!root->left && !root->right && sum==root->val) return true; 
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}
int main() {

    return 0;
}
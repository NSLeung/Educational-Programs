#include "util.h"
int maxDepthHelper(TreeNode* root, int level) {
    if(root->left == NULL && root->right == NULL) {
        return level;
    }
    else if (root->left == NULL && root->right != NULL){
        return maxDepthHelper(root->right, level + 1);
    }
    else if (root->left != NULL && root->right == NULL){
        return maxDepthHelper(root->left, level + 1);
    }
    else{
        return max( maxDepthHelper(root->left, level + 1), maxDepthHelper(root->right, level + 1));
    }
}
int Solution::maxDepth(TreeNode* root) {
    if(root==NULL)
        return 0;
    /* think recursively I guess */
    return maxDepthHelper(root, 1);
}



int main() {
    //test 1
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    //test 2
    // TreeNode* root = new TreeNode(1);
    // root->right = new TreeNode(2);
    Solution s;
    cout << s.maxDepth(root) << endl;

    return 0;
}
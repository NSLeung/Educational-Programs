#include "util.h"

int Solution::minDepth(TreeNode* root) {
    if(!root)
        return 0;
    if(root->left && root->right){
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
    else if(root->left && !root->right){
        return minDepth(root->left)+1;
    }
    else if(!root->left && root->right){
        return minDepth(root->right)+1;
    }
    else {
        return 1;
    }

}

int main() {
TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    // s.printDubVector( s.minDepth(root));
    cout << s.minDepth(root) << endl;
    return 0;
}
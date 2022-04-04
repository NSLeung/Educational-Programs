#include "util.h"

bool isValidBST_helper(TreeNode* root, long min, long max) {
    if(!root)
        return true;
    if(root->val > min && root->val < max) {
        return isValidBST_helper(root->left, min, root->val) && isValidBST_helper(root->right, root->val, max);
    }
    return false;
}
bool Solution::isValidBST(TreeNode* root) {
    return isValidBST_helper(root, LONG_MIN, LONG_MAX);
    /* valid binary tree */
    /* the below code doesn't preserve/persist min/max root */
    /*
    if(root->left == NULL && root->right == NULL) {
        return true;
    }
    else if (root->left == NULL && root->right != NULL){
        if(root->right->val > root->val)
            return isValidBST(root->right);
        else
        {
            return false;
        }
        
    }
    else if (root->left != NULL && root->right == NULL){
        if(root->left->val < root->val)
            return isValidBST(root->left);
        else
        {
            return false;
        }
    }
    else{
        if(root->left->val < root->val && root->right->val > root->val){
            cout << "root->right->val " << root->right->val << " > root->val " << root->val << " : " << (root->right->val > root->val) << endl;
            return isValidBST(root->left) && isValidBST(root->right);
        }
        else
        {
            return false;
        }
    }
    */


}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    Solution s;
    cout << s.isValidBST(root) << endl;

    return 0;
}
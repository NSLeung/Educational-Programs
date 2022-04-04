#include "util.h"

bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
    //initial checks
    if(!p || !q){
            if(!p && !q)
                return true;
            else
                return false;
        }
    if(p->val == q->val) {
        if(p->left && p->right && q->left && q->right)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else if(!p->left && p->right && !q->left && q->right)
            return isSameTree(p->right, q->right);
        else if(p->left && !p->right && q->left && !q->right)
            return isSameTree(p->left, q->left);
        else if(!p->left && !p->right && !q->left && !q->right)
            return true;
        else
            return false;
    }
    else {
        return false;
    }

}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);

    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(6);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(8);
    Solution s;
    cout << s.isSameTree(root,root2) << endl;
    return 0;
}
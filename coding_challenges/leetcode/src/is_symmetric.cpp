#include "util.h"

bool Solution::isSymmetric(TreeNode* root) {
    //base case

    return isSymmetric(root->left) && isSymmetric(root->right);

}

int main() {
    
    return 0;
}
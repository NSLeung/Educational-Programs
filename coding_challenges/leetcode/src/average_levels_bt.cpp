#include "util.h"
int depth(TreeNode* root) {
    if(!root)
        return 0;
    return max(depth(root->left), depth(root->right))+1;
}
vector<double> Solution::averageOfLevels(TreeNode* root) {
    if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<double> res;
        vector<int> tmp;
        int len, i;
        TreeNode *curr;
        while (q.size()) {
            tmp.clear();
            len = q.size();
            for (i = 0; i < len; i++) {
                curr = q.front();
                tmp.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                q.pop();
            }
            res.push_back(accumulate(begin(tmp), end(tmp), 0.0) / tmp.size());
        }
        return res;


}

int main() {
TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution s;
    s.printVector(s.averageOfLevels(root));
    return 0;
}
#include "util.h"
// helper depth function
int depth(TreeNode* root) {
    if(!root)
        return 0;
    return max(depth(root->left), depth(root->right))+1;
}
vector<vector<int>> Solution::levelOrderBottom(TreeNode* root) {
    if(!root)
        return {};
    int d = depth(root);
    cout << d << endl;
    vector<vector<int>> ret(d, vector<int>({}));
    //just try rederiving regular bfs first
    queue<TreeNode*> q;
    q.push(root);
    ret[d-1].push_back(root->val);
    q.push(NULL);
    d--;
    while(!q.empty()){
        TreeNode* tn = q.front();
        int toPrint = (tn) ? tn->val : 0;
        cout << "d " << d << " " <<  toPrint << endl;
        q.pop();
        if(tn) {
            if(tn->left){
                cout << "pushing left" << endl;
                q.push(tn->left);
                ret[d-1].push_back(tn->left->val);
            }
            if(tn->right) {
                cout << "pushing right" << endl;
                q.push(tn->right);
                ret[d-1].push_back(tn->right->val);
            }
        }
        else {
            /* mark the end of the level */
            if(q.empty()) break;
            d--;
            q.push(NULL);
        }
        
               
    }

    return ret;

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
    s.printDubVector( s.levelOrderBottom(root));
    // s.levelOrderBottom(root);
    // s.printVector()
    return 0;
}
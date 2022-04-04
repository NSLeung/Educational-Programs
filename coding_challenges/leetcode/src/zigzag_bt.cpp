#include "util.h"
int depth(TreeNode* root) {
    if(!root)
        return 0;
    return max(depth(root->left), depth(root->right))+1;
}
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {

    if(!root)
        return {};
    int d = depth(root);
    // cout << d << endl;
    vector<vector<int>> ret(d, vector<int>({}));
    //just try rederiving regular bfs first
    queue<TreeNode*> q;
    q.push(root);
    int i = 0;
    ret[i].push_back(root->val);
    q.push(NULL);
    i++;
    while(!q.empty()){
        TreeNode* tn = q.front();
        // int toPrint = (tn) ? tn->val : 0;
        // cout << "d " << d << " " <<  toPrint << endl;
        q.pop();
        if(tn) {
            if(tn->left){
                cout << "pushing left" << endl;
                q.push(tn->left);
                ret[i].push_back(tn->left->val);
            }
            if(tn->right) {
                cout << "pushing right" << endl;
                q.push(tn->right);
                ret[i].push_back(tn->right->val);
            }
            
        }
        else {
            /* mark the end of the level */
            if(q.empty()) break;
            if(i%2==1 && i < d){
                reverse(ret[i].begin(), ret[i].end());
            }
            i++;
            cout << "i " << i << endl;
            q.push(NULL);
        }
        
               
    }
// if (!root) return {};
//         queue<TreeNode*> q;
//         q.push(root);
//         // vector<double> res;
//         vector<vector<int>> res;
//         vector<int> tmp;
//         int level = 0;
    
//         TreeNode *curr;
//         while (q.size()) {
//             tmp.clear();
//             for (int i = 0; i < q.size(); i++) {
//                 curr = q.front();
//                 tmp.push_back(curr->val);
//                 if (curr->left) q.push(curr->left);
//                 if (curr->right) q.push(curr->right);
//                 q.pop();
//             }
//             if(level%2==1 && level < d)
//                 reverse(tmp.begin(), tmp.end());
//             // res.push_back(accumulate(begin(tmp), end(tmp), 0.0) / tmp.size());
//             res.push_back(tmp);
//             level++;
//         }
//         return res;
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
    s.printDubVector( s.zigzagLevelOrder(root));
    // s.levelOrderBottom(root);
    // s.printVector()
    return 0;
}
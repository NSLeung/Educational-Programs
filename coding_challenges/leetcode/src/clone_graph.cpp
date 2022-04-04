#include "util.h"

 Node* Solution::cloneGraph(Node* node) {
     /* BFS soln */
    if (!node) {
        return NULL;
    }
    Node* copy = new Node(node -> val, {});
    unordered_map<Node*, Node*> copies;
    copies[node] = copy;
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        for (Node* neighbor : cur -> neighbors) {
            if (copies.find(neighbor) == copies.end()) {
                copies[neighbor] = new Node(neighbor -> val, {});
                q.push(neighbor);
            }
            copies[cur] -> neighbors.push_back(copies[neighbor]);
        }
    }
    return copy;

    /* DFS Solution (recursive ?)*/

    /* 
    if (!node) {
            return NULL;
    }
    if (copies.find(node) == copies.end()) {
        copies[node] = new Node(node -> val, {});
        for (Node* neighbor : node -> neighbors) {
            copies[node] -> neighbors.push_back(cloneGraph(neighbor));
        }
    }
    return copies[node];
    */
 }

 int main () {

     return 0;
 }
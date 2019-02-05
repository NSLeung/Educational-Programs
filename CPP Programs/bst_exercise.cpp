#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    cout << node->data << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    printInorder(node->right);
}
int size(struct Node* node) {
		return node == NULL ? 0 : 1 + size(node->left) + size(node->right);
	}
/* Given a binary tree, print its nodes in preorder*/
int preorderCount(struct Node* node, int num)
{
  //leaf node
  // if(node->left == NULL && node->right == NULL){
  //     if(node->data == num)
  //       return 1;
  //     else
  //       return 0;
  // }
  // // int count = 0;
  // if(node->data == num){
  //   if(node->left != NULL)
  //     return preorderCount(node->left, num) + 1;
  //   if(node->right != NULL)
  //     return preorderCount(node->right, num) + 1;
  //
  // }
  // if(node->left != NULL){
  //
  // }
  //
  // if(node->right != NULL)
  //   return preorderCount(node->right, num);
  //
  // return 0;

    // if(node==NULL){
    //   return 0;
    // }
    // if(node->data < num){
    //   return preorderCount(node->right, num);
    // }
    // return 1+ preorderCount(node->left, num) + size(node->right);

    

}



/* Driver program to test above functions*/
int main()
{
    struct Node *root = new Node(1);
    root->left             = new Node(3);
    root->right         = new Node(3);
    root->left->left     = new Node(4);
    root->left->right = new Node(3);

    // cout << "\nPreorder traversal of binary tree is \n";
    int result = 0;
    result = preorderCount(root, 3);
    cout << result <<endl;
    // cout << "\nInorder traversal of binary tree is \n";
    // printInorder(root);

    // cout << "\nPostorder traversal of binary tree is \n";
    // printPostorder(root);

    return 0;
}

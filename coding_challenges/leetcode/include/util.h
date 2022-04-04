#pragma once
//should include standard leetcode header stuff: stl, math, algorithm, etc
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <map>
#include <algorithm>
#include <limits.h>
#include <iterator>
#include <cmath>
#include <numeric>
#include <functional>
/* graph stuff */

#include <utility>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <iomanip>
#include <sstream>
// #include "graph.h"
// #include "vertex.h"
// #include "edge.h"

// #include "bfs.h"

using namespace std;
//standard listnode struct
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    public: 
    /* all leetcode problem prototypes here */

    /* Easy 38. Count and Say */
    string countAndSay(int n);
    vector<int> frequencySort(vector<int>& nums); //1636
    
    

    /* Medium */
    bool isAdditiveNumber(string num); // 306
    int minimumSwap(string s1, string s2); //1247
    

    
        /* IBM */
    int threeSumSmaller(vector<int> nums, int target); // 259
    vector<string> fizzBuzz(int n); //412
    int minSwaps(int arr[], int n); //1151
    int maximalSquare(vector<vector<char>>& matrix); //221
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost); //134
    int numWaterBottles(int numBottles, int numExchange); //1518
    vector<int> twoSum(vector<int>& nums, int target); //1
    int numPairsDivisibleBy60(vector<int>& time); //1010
    int compress(vector<char>& chars); //443
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n); //88
    string longestCommonPrefix(vector<string>& strs); //14
    int lengthOfLIS(vector<int>& nums); //300
    int maxSubArray(vector<int>& nums); //53

    /* Akuna */
    int numSubarrayProductLessThanK(vector<int>& nums, int k); //713
    int dieSimulator(int n, vector<int>& rollMax); //1223
    /* easy collection */

    /* Hard */
    int consecutiveNumbersSum(int N);
    //1012 skip (IBM)

    /* list */
    ListNode* removeNthFromEnd(ListNode* head, int n);
    void printList(ListNode* head){
        ListNode* curr = head;
        while(curr!=NULL){
            cout << curr->val << " " << endl;
            curr = curr->next;
        }
    }
    ListNode* reverseList(ListNode* head);
    ListNode* reverseList_r(ListNode* head);
    ListNode* mergeKLists(vector<ListNode*>& lists);
    ListNode* merge2Lists(ListNode* l1, ListNode* l2);
    void reverseString(vector<char>& s);
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    /* vector */
    template<typename T>
    void printVector(vector<T> v){
        cout << "{ ";
        for(auto it = v.begin(); it != v.end(); it++){
            cout << *it << " ";
        }
        cout << "}" << endl;
    }

    template<typename T>
    void printDubVector(vector<vector<T>> v) {
        cout << "{ ";
        // C++11:
        for (auto & vec : v)
        {
            cout << "{ ";

            for (auto & i : vec)
                cout << std::setw(2) << i;
            cout << " } " << '\n';
        }
        cout << "} " << endl;
    }

    /* tree */
    int maxDepth(TreeNode* root);
    bool isValidBST(TreeNode* root);
    bool isSymmetric(TreeNode* root);
    bool isSameTree(TreeNode* p, TreeNode* q); //100 (easy)
    vector<vector<int>> levelOrderBottom(TreeNode* root); //107 (Medium/easy)
    vector<double> averageOfLevels(TreeNode* root); //637 easy
    int minDepth(TreeNode* root); //111 easy
    bool hasPathSum(TreeNode* root, int targetSum); //112 Path Sum easy
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q); //235 easy
    bool isSubtree(TreeNode* s, TreeNode* t); //572 easy
    vector<vector<int>> zigzagLevelOrder(TreeNode* root); //103 medium

    /* Backtracking */
     bool exist(vector<vector<char>>& board, string word); //79 medium
      vector<vector<int>> updateMatrix(vector<vector<int>>& matrix); //542 medium

    /* DP collection */
    int climbStairs(int n); //70 easy
     int rob(vector<int>& nums); //198 easy

     /* Graph */
      Node* cloneGraph(Node* node); //133 medium
     
};

class Algorithms {
    public:
    int binary_search_it(vector<int> nums, int target, int left, int right);
    int binary_search_r(vector<int> nums, int target, int left, int right);


};
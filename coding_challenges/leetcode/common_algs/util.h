#pragma once
//should include standard leetcode header stuff: stl, math, algorithm, etc
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <iterator>
/* graph stuff */

#include <utility>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "graph.h"
#include "vertex.h"
#include "edge.h"

#include "bfs.h"

using namespace std;
//standard listnode struct
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public: 
    /* all leetcode problem prototypes here */

    /* easy collection */

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

    /* vector */
    template<typename T>
    void printVector(vector<T> v){
        cout << "{ ";
        for(auto it = v.begin(); it != v.end(); it++){
            cout << *it << " ";
        }
        cout << "}" << endl;
    }

};

class Algorithms {
    public:
    int binary_search_it(vector<int> nums, int target, int left, int right);
    int binary_search_r(vector<int> nums, int target, int left, int right);


};
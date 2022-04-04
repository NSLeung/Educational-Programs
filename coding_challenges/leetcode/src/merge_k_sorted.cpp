#include "util.h"

ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
    /* one way is to merge 2 lists at a time, works out to be O(kN) with O(1) space - big idea: cut number of lists in half each time */

    /* optimal solution: O(Nlogk) space O(1) */
    if(lists.size() == 0){
        return NULL;
    }
    int interval = 1;
    while(interval < lists.size()){
        for(int i = 0; i + interval < lists.size();i=i+interval*2){
            lists[i] = merge2Lists(lists[i],lists[i+interval]);
        }
        interval *= 2;
    }
    return lists[0];

}

ListNode* Solution::merge2Lists(ListNode* l1, ListNode* l2) {
    ListNode* sortedl = new ListNode(0);
    ListNode* res = sortedl;
    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            sortedl->next = l1;
            sortedl = sortedl->next;
            l1 = l1->next;
        }
        else {
            sortedl->next = l2;
            sortedl = sortedl->next;
            l2 = l2->next;
        }
    }
    if(l1 == NULL){
        sortedl->next = l2;
    }
    if(l2 == NULL) {
        sortedl->next = l1;
    }
    return res->next;
}

int main() {
    ListNode* l1_3 = new ListNode(5);
    ListNode* l1_2 = new ListNode(3);
    ListNode* l1_1 = new ListNode(1);
    l1_1->next = l1_2;
    l1_2->next = l1_3;
    ListNode* l2_3 = new ListNode(6);
    ListNode* l2_2 = new ListNode(4);
    ListNode* l2_1 = new ListNode(2);
    l2_1->next = l2_2;
    l2_2->next = l2_3;
    Solution s;
    vector<ListNode*> v;
    v.push_back(l1_1);
    v.push_back(l2_1);
    ListNode* ret = s.mergeKLists(v);
    s.printList(ret);
    return 0;
}
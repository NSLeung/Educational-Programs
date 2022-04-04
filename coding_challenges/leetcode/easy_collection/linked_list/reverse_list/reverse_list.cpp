#include "util.h"

ListNode* Solution::reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* idx = head;
    ListNode* idx_next = head->next;
    head->next = NULL;
    while(idx_next->next!=NULL){
        ListNode* temp = idx_next->next;
        idx_next->next = idx;
        idx = idx_next;
        idx_next = temp;

    }
    idx_next->next = idx;
    return idx_next;
}

ListNode* Solution::reverseList_r(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* ret = reverseList_r(head->next);
    head->next->next = head;
    head->next = NULL; /* this basically gets reassigned correctly by recursive calls */
    return ret;
}
int main(){
    ListNode* l3 = new ListNode(3);
    ListNode* l2 = new ListNode(2);
    ListNode* l1 = new ListNode(1);
    l1->next = l2;
    l2->next = l3;
    Solution s;
    s.printList(l1);
    ListNode* ret = s.reverseList_r(l1);
    s.printList(ret);
}
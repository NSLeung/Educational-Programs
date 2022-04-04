#include "util.h"
/* iterative solution (easier to re-derive) */
ListNode* Solution::reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* idx = head;
    ListNode* idx_next = head->next;
    head->next = NULL;
    while(idx_next->next!=NULL){
        ListNode* temp = idx_next->next;
        idx_next->next = idx; /* change direction of pointer */
        idx = idx_next; /* move up the pointer */
        idx_next = temp; /* restore next to keep moving in the list */

    }
    /* final pointer change */
    idx_next->next = idx;
    return idx_next;
}
ListNode* rev_head;
/* recursive solution */
ListNode* Solution::reverseList_r(ListNode* head) {
    // if(head == NULL || head->next == NULL){
    //     return head;
    // }    
    // ListNode* ret = reverseList_r(head->next);
    // /* tail recursion, think about the end part of the list first */
    // head->next->next = head;
    // head->next = NULL; /* this basically gets reassigned correctly by recursive calls */
    // return ret;
    if(!head)
        return head;
    if(!head->next){
        rev_head = head;
        return head;
    }
    ListNode* ret = reverseList_r(head->next);
    /* you take the subproblem ret and assume it has been reversed, so you want to replace it's next with the current head */
    ret->next = head;
    head->next = NULL; /* this basically gets reassigned correctly by recursive calls - all the way to the beginning */
    return head;
}
int main(){
    ListNode* l3 = new ListNode(3);
    ListNode* l2 = new ListNode(2);
    ListNode* l1 = new ListNode(1);
    l1->next = l2;
    l2->next = l3;
    Solution s;
    s.printList(l1);
    ListNode* ret = s.reverseList(l1);
    s.printList(ret);
}
#include "util.h"


ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
        //remember - n is from the end
        ListNode* idx = head;
        ListNode* end_idx = head;
        for(int i = 0; i <= n; i++){
            if(end_idx == NULL){
                //if we hit this early, we know we are removing head (?)
                return head->next;
            }                
            end_idx = end_idx->next;
        }
        // cout << "idx val " << idx->val << endl;
        // cout << "end_idx val " << end_idx->val << endl;
        // return head;
        while(end_idx!=NULL){
            end_idx = end_idx->next;
            idx = idx->next;
        }
        cout << "idx val " << idx->val << endl;
        idx->next = idx->next->next;
        return head;
    }

// };

int main() {
    ListNode* l3 = new ListNode(3);
    ListNode* l2 = new ListNode(2);
    ListNode* l1 = new ListNode(1);
    l1->next = l2;
    l2->next = l3;
    Solution s;
    s.printList(l1);
    ListNode* ret = s.removeNthFromEnd(l1, 3);
    s.printList(ret);

}
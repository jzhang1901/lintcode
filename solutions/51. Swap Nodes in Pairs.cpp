
/**
51. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.
Example

Given 1->2->3->4, you should return the list as 2->1->4->3.
Challenge

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: a ListNode
     * @return: a ListNode
     */
    ListNode * swapPairs(ListNode * head) {
        // write your code here
        if(!head || !head->next) return head;
        ListNode *head1 = head;
        ListNode *head2 = head->next;
        
        ListNode *head11 = head1;
        ListNode *head22 = head2;

        int i = 0;
        head = head->next->next;
        //split 
        while(head) {
            if(i & 0x1) {
                head2->next = head;
                head2 = head2->next;
            } else {
                head1->next = head;
                head1 = head1->next;
            }
            i++;
            head = head->next;
        }
        head1->next = nullptr;
        head2->next = nullptr;
        

        ListNode *fhead1 = head22;
        ListNode *fhead2 = head22;
        
        while(head11 && head22) {
            ListNode *nxt1 = head11->next;
            ListNode *nxt2 = head22->next;
            
            fhead1->next = head11;
            if(nxt2) // made a mistake here
                head11->next = nxt2;
            head11 = nxt1;
            head22 = nxt2;
            fhead1 = head22;
        }
        
        return fhead2;
    }
};


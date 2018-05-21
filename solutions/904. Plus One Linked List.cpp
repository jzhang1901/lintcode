
/*904. Plus One Linked List

Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

*/
/**
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
     * @param head: the first Node
     * @return: the answer after plus one
     */
    ListNode * reverse(ListNode * head) {
        if(!head || !head->next) return head;
        ListNode* prev, *cur, *nxt;
        prev = nullptr;
        cur = head;
        while(cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    
    ListNode * plusOne(ListNode * head) {
        // Write your code here
        ListNode* rhead = reverse(head);
        rhead->val += 1;
        ListNode* runner = rhead;
        int carry = 0;
        
        while(runner) {
            int val = runner->val + carry;
            carry = val / 10;
            runner->val = val % 10; 
            if(!runner->next && carry) {
                ListNode* tmp = new ListNode(carry);
                tmp->next = nullptr;
                runner->next = tmp;
                carry = 0;
                break;
            }
            
            runner = runner->next;
        }
        
        return reverse(rhead);
    }
};
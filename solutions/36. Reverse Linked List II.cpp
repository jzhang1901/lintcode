/* 36. Reverse Linked List II

Reverse a linked list from position m to n.
Example

Given 1->2->3->4->5->NULL, m = 2 and n = 4, return 1->4->3->2->5->NULL.
Challenge

Reverse it in-place and in one-pass

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
     * @param head: ListNode head is the head of the linked list 
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
    ListNode * reverse(ListNode * head, ListNode * remain) {
        if(!head || !head->next) return head;
        ListNode* prev, *cur, *nxt;
        prev = remain;
        cur = head;
        while(cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        // write your code here
        if(!head) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;
        // find positon m-1 and n
        ListNode *node_m_minnus_1 = nullptr;
        ListNode *node_n = nullptr;
        int i = 0; 
        while(head && i <= n) {
            if(i == m-1)
                node_m_minnus_1 = head;
            else if(i == n) {
                node_n = head;
                break;                
            }
            head = head->next;
            i++;
            if(node_m_minnus_1 && node_n)
                break;
        }
        if(!node_m_minnus_1)
            return nullptr;
        
        ListNode *rhead = node_m_minnus_1->next;
        ListNode *remain = node_n ? node_n->next : nullptr;
        if(node_n)
            node_n->next = nullptr;
        
        node_m_minnus_1->next = reverse(rhead, remain);
        head = dummy->next;
        delete dummy;
        return head;
    }
};
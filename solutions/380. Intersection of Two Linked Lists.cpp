/*
Description

Write a program to find the node at which the intersection of two singly linked lists begins.

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.

Have you met this question in a real interview?  
Example

The following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.
Challenge

Your code should preferably run in O(n) time and use only O(1) memory.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    int getListLen(ListNode *head)
    {
        int len = 0;
        while(head != NULL)
        {
            head = head->next;
            len++;
        }
        
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        if(headA == NULL || headB == NULL)
            return NULL;
            
        int lenA = getListLen(headA);
        int lenB = getListLen(headB);

        if(lenA > lenB)
        {
            for(int i=0; i<lenA-lenB; i++)
            {
                headA = headA->next;
            }
        }
        else if(lenA < lenB)
        {
            for(int i=0; i<lenB-lenA; i++)
            {
                headB = headB->next;
            }
        }

        
        while(headA && headB)
        {
            if(headA == headB)
            {
                return headA;
            }
            else
            {
                headA = headA->next;
                headB = headB->next;
            }
        }
        
        return NULL;
        
    }
};

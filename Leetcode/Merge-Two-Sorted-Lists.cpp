/* Aki Saito
* Leetcode - Easy
* Merge Two Sorted Lists
* June 18, 2019
* Language: C++
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Check for dummy inputs
        // Both given lists are empty
        if (l1 == nullptr && l2 == nullptr) {
           return nullptr; 
        }
        // l1 is only non-empty list
        if (l1 && l2 == nullptr) {
            return l1;
        }
        // 12 is only non-empty list
        if (l1 == nullptr && l2) {
            return l2;
        }
        
        // Initialize our head pointer
        ListNode* head;
        // Declare head as zero val
        head = nullptr;
        
        // Assign head to the lower value and update
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        
        // Initialize pointer for result
        ListNode* result;
        // Declare to head
        result = head;
        
        // Loop until end of list and update
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                result->next = l1;
                result = result->next;
                l1 = l1->next;
            } else {
                result->next = l2;
                result = result->next;
                l2 = l2->next;
            }
        }
        
        // Add the last values we missed
        if (l1) {
            result->next = l1;
        } 
        if (l2) {
            result->next = l2;
        }
        
        return head;
    }
};

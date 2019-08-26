/*
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example:
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *l = l1;
    int sum = 0, div = 0;
    sum = l1->val + l2->val;
    div = sum / 10;
    l1->val = sum % 10;
    while (l1->next && l2->next) {
        l1 = l1->next;
        l2 = l2->next;
        sum = l1->val + l2->val + div;
        div = sum / 10;
        l1->val = sum % 10;
    }
    if (l2->next) 
        l1->next = l2->next;
    
    while(l1->next && div) {
        l1 = l1->next;
        sum = l1->val + div;
        div = sum / 10;
        l1->val = sum % 10;
    }
    if (!div)
        return l;
    l1->next = malloc(sizeof(struct ListNode));
    l1 = l1->next;
    l1-> val = 1;
    l1->next = NULL;
    return l;
}

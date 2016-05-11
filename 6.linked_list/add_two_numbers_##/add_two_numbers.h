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
   * @param l1: the first list
   * @param l2: the second list
   * @return: the sum list of l1 and l2 
   */
  ListNode *addLists(ListNode *l1, ListNode *l2) {
    // write your code here
        
    if(l1 == NULL)
      return l2;
            
    if(l2 == NULL)
      return l1;
            
    int a = 0, b = 0;
    int cnt = 1;
    int sum = 0;
    int carry = 0;
        
    ListNode * dummy = new ListNode;
    ListNode * curr = dummy;
        
    while(l1 != NULL && l2 != NULL)
    {
      sum = l1->val + l2->val + carry;
            
      carry = sum / 10;
      sum = sum % 10;
            
      curr->next = new ListNode(sum);
            
      l1 = l1->next;
      l2 = l2->next;
      curr = curr->next;
    }
        
    // remember the carry
    while(l1 != NULL)
    {
      sum = l1->val + carry;
            
      carry = sum / 10;
      sum = sum % 10;
            
      curr->next = new ListNode(sum);
            
      l1 = l1->next;
      curr = curr->next;
            
    }
        
    while(l2 != NULL)
    {
      sum = l2->val + carry;
            
      carry = sum / 10;
      sum = sum % 10;
            
      curr->next = new ListNode(sum);
            
      l2 = l2->next;
      curr = curr->next;
    }
        
    // remember the final carry!!!
    if(carry)
    {
      curr->next = new ListNode(1);
      curr = curr->next;
    }
        
    curr->next = NULL;
        
        
    return dummy->next;
  }
};

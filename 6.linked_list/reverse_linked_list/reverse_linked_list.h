/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
  /**
   * @param head: The first node of linked list.
   * @return: The new head of reversed linked list.
   */
  ListNode *reverse(ListNode *head) {
    // write your code here
        
    if(head == NULL)
      return head;
            
    if(head->next == NULL)
      return head;
            
    ListNode *prev, *curr, *next;
        
    prev = head;
    curr = head->next;
    next = head->next->next;
        
    while(curr != NULL)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
        
    head->next = NULL;
    return prev;
  }
};

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
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
   * @param x: an integer
   * @return: a ListNode 
   */
  ListNode *partition(ListNode *head, int x) {
    // write your code here
        
    ListNode *dummy = new ListNode;
    ListNode *more = new ListNode;
    ListNode *curr, *next, *more_end;
        
    dummy->next = head;
    head = dummy;
    curr = head;
    next = curr->next;
        
    more->next = NULL;
    more_end = more;
        
    while(next != NULL)
    {
      if(next->val >= x)
      {
        more_end->next = next;
        curr->next = next->next;
        next = curr->next;
        more_end = more_end->next;
        more_end->next = NULL;
      }
      else
      {
        curr = curr->next;
        next = next->next;
      }
    }
        
    curr->next = more->next;
    head = dummy->next;
    return head;
  }
};



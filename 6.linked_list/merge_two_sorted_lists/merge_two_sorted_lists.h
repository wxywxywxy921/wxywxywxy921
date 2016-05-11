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
   * @param ListNode l1 is the head of the linked list
   * @param ListNode l2 is the head of the linked list
   * @return: ListNode head of linked list
   */
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    // write your code here
        
    ListNode *dummy = new ListNode;
    ListNode *res_curr, *l1_curr, *l2_curr;
    res_curr = dummy;
    l1_curr = l1;
    l2_curr = l2;
        
    if(l1 == NULL && l2 == NULL)
      return NULL;
        
    while(l1_curr != NULL && l2_curr != NULL)
    {
      if(l1_curr->val < l2_curr->val)
      {
        res_curr->next = l1_curr;
        res_curr = res_curr->next;
        l1_curr = l1_curr->next;
      }
      else
      {
        res_curr->next = l2_curr;
        res_curr = res_curr->next;
        l2_curr = l2_curr->next;
      }
    }
        
    if(l1_curr != NULL)
    {
      res_curr->next = l1_curr;
    }
        
    if(l2_curr != NULL)
    {
      res_curr->next = l2_curr;
    }
        
    return dummy->next;
  }
};

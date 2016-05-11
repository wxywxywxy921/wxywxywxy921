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
   * @return: void
   */  

  void reorderList(ListNode *head) {
    // write your code here
        
    if(head == NULL)
      return;
        
    // [step 1] find the mid
        
    ListNode *slow = head;
    ListNode *fast = head;
        
    while(1)
    {
      fast = fast->next;
            
      if(fast == NULL)
      {
        break;
      }
            
      fast = fast->next;
            
      if(fast == NULL)
      {
        break;
      }
            
      slow = slow->next;
    }
        
    // [step 2] revert the second half
        
    ListNode *curr, *prev, *next, *sec_head;
        
    sec_head = prev = slow->next;
        
    if(prev == NULL)
      return;
        
    curr = prev->next;
    prev->next = NULL;
    slow->next = NULL;
        
    while (curr != NULL)
    {
      next = curr->next;
      curr->next = prev;
      sec_head = curr;
      prev = curr;
      curr = next;
    }
        
    // [step 3] merge two lists
        
    ListNode *prim_curr = head;
    ListNode *sec_curr = sec_head;
    ListNode *prim_temp;
    ListNode *sec_temp;
        
    while(prim_curr != NULL && sec_curr != NULL)
    {
      prim_temp = prim_curr->next;
      sec_temp = sec_curr->next;
            
      prim_curr->next = sec_curr;
      sec_curr->next = prim_temp;
            
      prim_curr = prim_temp;
      sec_curr = sec_temp;
    }
  }
};



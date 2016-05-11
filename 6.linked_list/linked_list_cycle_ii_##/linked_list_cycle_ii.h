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
   * @return: The node where the cycle begins. 
   *           if there is no cycle, return null
   */
  ListNode *detectCycle(ListNode *head) {
    // write your code here
        
    ListNode *slow = head;
    ListNode *fast = head;
        
    if(head == NULL)
      return NULL;
        
    while(1)
    {
      fast = fast->next;
            
      if(fast == NULL)
        return NULL;
                
      fast = fast->next;
            
      if(fast == NULL)
        return NULL;
                
      slow = slow->next;
            
      if(slow->val == fast->val)
        break;
    }
        
    slow = head;
        
    while(slow->val != fast->val)
    {
      fast = fast->next;
      slow = slow->next;
    }
        
    return slow;
  }
};

/*

  m = distance between the head and the cycle begins.
  n = distance for the loop;

  1) when slow = m, fast to "cycle begins" is n - m
  2) slow and fast meet at n - m from "cycle begins"
  3) so, the meet point to "cycle begins" is m

*/



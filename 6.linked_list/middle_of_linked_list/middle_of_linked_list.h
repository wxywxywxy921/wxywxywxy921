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
class Solution{
public:
  /**
   * @param head: the head of linked list.
   * @return: a middle node of the linked list
   */
  ListNode *middleNode(ListNode *head) {
    // Write your code here
        
    ListNode *slow, *fast;
        
    slow = head;
    fast = head;
        
    if(head == NULL)
      return NULL;
            
    while (1)
    {
      fast = fast->next;
            
      if(fast == NULL)
        break;
                
      fast = fast->next;
            
      if(fast == NULL)
        break;
                
      slow = slow->next;
    }
        
    return slow;
  }
};


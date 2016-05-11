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
   * @return: The head of linked list.
   */
  ListNode *insertionSortList(ListNode *head) {
    // write your code here
        
    ListNode *dummy = new ListNode;
    ListNode *curr, *prev, *temp;
        
    if(head == NULL)
      return NULL;
            
    dummy->next = head;
    dummy->val  = 999999;
    head = dummy;
    curr = head->next;
    prev = head;
        
    while(1)
    {
      temp = head;
            
      while(temp->next != curr && temp != NULL)
      {
        if(temp->next->val > curr->val)
        {
          ListNode *insert = new ListNode(curr->val);
          insert->next = temp->next;
          temp->next = insert;
                    
          break;
        }
                
        temp = temp->next;
      }
            
      if(temp->next != curr)
      {
        if(curr->next == NULL)
        {
          prev->next = NULL;
          break; 
        }
        else
        {
          curr->val = curr->next->val;
          curr->next = curr->next->next;
        }
      }
      else //if(temp->next == curr)
      {
        if(curr->next == NULL)
        {
          break; 
        }
                
        prev = curr;
        curr = curr->next;
      }
    }
        
    return dummy->next;
  }
};

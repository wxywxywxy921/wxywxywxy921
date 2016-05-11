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
   * @param head: The first node of linked list.
   * @return: head node
   */
  ListNode * deleteDuplicates(ListNode *head) {
    // write your code here
        
    ListNode *dummy = new ListNode;
    ListNode *curr, *temp;
        
    dummy->next = head;
    head = dummy;
    curr = head;
        
    while(curr != NULL)
    {
      if(curr->next != NULL && curr->next->next != NULL)
      {
        if(curr->next->val == curr->next->next->val)
        {
          while(curr->next->next != NULL && curr->next->val == curr->next->next->val)
          {
            temp = curr->next->next;
            curr->next->next = curr->next->next->next;
            delete[] temp;
          }
                        
          temp = curr->next;
          curr->next = curr->next->next;
          delete[] temp;
        }
        else
        {
          curr = curr->next;
        }
      }
      else
      {
        break;
      }
    }
        
    return dummy->next;
  }
};

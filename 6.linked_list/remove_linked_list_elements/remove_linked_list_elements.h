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
   * @param head a ListNode
   * @param val an integer
   * @return a ListNode
   */
  ListNode *removeElements(ListNode *head, int val) {
    // Write your code here
        
    ListNode *temp, *dummy, *curr;
        
    if(head == NULL)
      return NULL;
        
    dummy = new ListNode;
    dummy->next = head;
    head = dummy;
    curr = dummy;
        
    while(1)
    {
      if(curr->next == NULL)
        break;
                
      if(curr->next->val == val)
      {
        temp = curr->next;
        curr->next = temp->next;
        delete[] temp;
      }
      else
      {
        curr = curr->next;
      }
    }
        
    return dummy->next;
  }
};

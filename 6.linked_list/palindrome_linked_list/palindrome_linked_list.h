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
   * @return a boolean
   */
      
  ListNode *revert_list(ListNode *l)
  {
    ListNode *prev, *curr, *next;
        
    if(l == NULL || l->next == NULL)
    {
      return l;
    }
        
    prev = l;
    curr = l->next;
        
    while(curr != NULL)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
        
    l->next = NULL;
        
    return prev;
  }

  bool isPalindrome(ListNode* head) {
    // Write your code here
        
    if(head == NULL || head->next == NULL)
      return true;
            
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *sec_half;
        
    while(1)
    {
      fast = fast->next;
      if(fast == NULL)
        break;
                
      fast = fast->next;
      if(fast == NULL)
        break;
                
      slow = slow->next;
    }
        
    sec_half = revert_list(slow);
        
    while(sec_half != NULL && head != NULL)
    {
      if(sec_half->val != head->val)
      {
        return false;
      }
            
      sec_half = sec_half->next;
      head = head->next;
    }
        
    return true;
  }
};

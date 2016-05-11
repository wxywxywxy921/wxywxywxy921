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
   * @param l1: the first list
   * @param l2: the second list
   * @return: the sum list of l1 and l2 
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
    
  ListNode *sum_two_lists(ListNode *l1, ListNode *l2)
  {
    ListNode *l1_curr = l1;
    ListNode *l2_curr = l2;
    ListNode *dummy = new ListNode;
    ListNode *head = dummy;
        
    int carry = 0;
        
    while(l1_curr != NULL && l2_curr != NULL)
    {
      dummy->next = new ListNode((l1_curr->val + l2_curr->val + carry) % 10);
            
      if(l1_curr->val + l2_curr->val + carry >= 10) // [xywu] forgot the carry
      {
        carry = 1;
      }
      else
      {
        carry = 0;
      }
            
      dummy = dummy->next;
      l1_curr = l1_curr->next;
      l2_curr = l2_curr->next;
    }
        
    while(l1_curr != NULL)
    {
      dummy->next = new ListNode((l1_curr->val + carry) % 10);
            
      if(l1_curr->val + carry >= 10)
      {
        carry = 1;
      }
      else
      {
        carry = 0;
      }
            
      dummy = dummy->next;
      l1_curr = l1_curr->next;
    }
        
    while(l2_curr != NULL)
    {
      dummy->next = new ListNode((l2_curr->val + carry) % 10);
            
      if(l2_curr->val + carry >= 10)
      {
        carry = 1;
      }
      else
      {
        carry = 0;
      }
            
      dummy = dummy->next;
      l2_curr = l2_curr->next;
    }
        
    if(carry == 1) // [xywu] forgot it
    {
      dummy->next = new ListNode(carry);
      dummy->next->next = NULL;
    }
    else
    {
      dummy->next = NULL;
    }
        
    return head->next;
  }
     
  ListNode *addLists2(ListNode *l1, ListNode *l2) {
    // write your code here
        
    ListNode *revert_l1;
    ListNode *revert_l2;
    ListNode *sum;
        
    revert_l1 = revert_list(l1);
    revert_l2 = revert_list(l2);
        
    sum = sum_two_lists(revert_l1, revert_l2); 
        
    return revert_list(sum);
  }
};

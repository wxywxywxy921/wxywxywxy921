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
   * @return: You should return the head of the sorted linked list,
   using constant space complexity.
  */
     
  int count_list_entry(ListNode *head)
  {
    int ret = 0;
        
    while(head != NULL)
    {
      ret ++;
      head = head->next;
    }
        
    return ret;
  }
    
  ListNode *sortList(ListNode *head) {
    // write your code here
        
    ListNode *ret;
    int cnt = count_list_entry(head);
        
    if(cnt == 0)
    {
      return NULL;
    }
        
    if(cnt == 1)
    {
      return head;
    }
        
        
    ret = sortList_helper(head, cnt);
        
    return ret;
  }
    
  ListNode *merge(ListNode *left, ListNode *right)
  {
    ListNode *dummy, *left_curr, *right_curr, *dummy_curr, *ret;
        
    dummy = new ListNode;
    left_curr = left;
    right_curr = right;
    dummy_curr = dummy;
        
    while(left_curr != NULL && right_curr != NULL)
    {
      if(left_curr->val > right_curr->val)
      {
        dummy_curr->next = right_curr;
        right_curr = right_curr->next;
      }
      else
      {
        dummy_curr->next = left_curr;
        left_curr = left_curr->next;
      }
            
      dummy_curr = dummy_curr->next;
    }
        
    if(left_curr == NULL)
    {
      dummy_curr->next = right_curr;
    }
    else
    {
      dummy_curr->next = left_curr;
    }
        
    ret = dummy->next;
    delete[] dummy;
    return ret;
  }
    
  ListNode *sortList_helper(ListNode *&head, int cnt) 
  {
    ListNode *left, *right, *ret;
        
    if(cnt == 1)
    {
      ret = head;
      head = head->next;
      ret->next = NULL;
      return ret;
    }
        
    left = sortList_helper(head, cnt / 2);
    right = sortList_helper(head, cnt - cnt / 2);
    ret = merge(left, right);
        
    return ret;
  }
        
};



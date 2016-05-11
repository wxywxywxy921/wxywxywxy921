/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
  /**
   * @param head: The head of linked list.
   * @param m: The start position need to reverse.
   * @param n: The end position need to reverse.
   * @return: The new head of partial reversed linked list.
   */
     
  ListNode *get_kth_entry(ListNode *head, int k)
  {
    int cnt = 0;
        
    while(head != NULL)
    {
      cnt ++;
      head = head->next;
            
      if(cnt == k)
      {
        break;
      }
    }
        
    return head;
  }
    
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    // write your code here
        
    ListNode *dummy = new ListNode;
    ListNode *pre;
        
    dummy->next = head;
    head = dummy;
        
    if(m == n)
    {
      return head->next;
    }
        
    if(m == 1)
      pre = dummy;
    else
      pre = get_kth_entry(head, m - 1);
            
    // [step 2] revert the sub list
        
    ListNode *sub_pre, *sub_curr, *sub_next;
    int sub_list_cnt = m + 1;
        
    sub_pre = pre->next;        // m
    sub_curr = sub_pre->next;   // m + 1
    sub_next = sub_curr->next;
        
    while(1)
    {
      sub_next = sub_curr->next;
      sub_curr->next = sub_pre;
            
      if(sub_list_cnt == n)       // made mistake here
      {
        break;
      }
      sub_list_cnt ++;
            
      sub_pre = sub_curr;
      sub_curr = sub_next;
            
    }
        
    // [step 3] connect
    ListNode *temp;
        
    temp = pre->next;
    pre->next = sub_curr;
    temp->next = sub_next;
        
    return dummy->next;
  }
};

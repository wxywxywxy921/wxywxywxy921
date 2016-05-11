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
   * @param head: the list
   * @param k: rotate to the right k places
   * @return: the list after rotation
   */
  ListNode *rotateRight(ListNode *head, int k) {
    // write your code here
        
        
    if(head == NULL)
      return NULL;
            
    // #### missing this case
    if(head->next == NULL)
      return head;
            
    // [step 1] find the entry
    ListNode *slow, *fast;
    int cnt = 0;
        
    slow = fast = head;
        
    while(cnt != k && fast != NULL)
    {
      cnt ++;
      fast = fast->next;
    }
        
    if(fast == NULL)
    {
      return head;
    }
        
    while(fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next;
    }
        
    // [step 2] rorate
        
    ListNode *ptr_0, *ptr_1, *ptr_2, *ptr_3;
        
    ptr_0 = head;
    ptr_1 = slow;
    ptr_2 = slow->next;
    ptr_3 = fast;
        
    ptr_3->next = ptr_0;
    ptr_1->next = NULL;
        
    return ptr_2;
  }
};

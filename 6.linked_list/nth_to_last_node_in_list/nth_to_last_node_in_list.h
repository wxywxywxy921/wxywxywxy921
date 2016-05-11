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
   * @param n: An integer.
   * @return: Nth to last node of a singly linked list. 
   */
  ListNode *nthToLast(ListNode *head, int n) {
    // write your code here
        
    ListNode *dummy;
    ListNode *slow, *fast;
    int cnt = 0;
        
    dummy = new ListNode;
    dummy->next = head;
    head = dummy;
    slow = fast = head;
        
    if(head == NULL)
    {
      return NULL;
    }
        
    while(cnt != n && fast->next != NULL)
    {
      cnt ++;
      fast = fast->next;
    }
        
    while(fast != NULL)
    {
      slow = slow->next;
      fast = fast->next;
    }
        
    return slow;
  }
};



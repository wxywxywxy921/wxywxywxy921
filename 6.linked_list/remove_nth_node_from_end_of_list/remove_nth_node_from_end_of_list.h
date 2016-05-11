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
   * @return: The head of linked list.
   */
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // write your code here
        
    ListNode *dummy = new ListNode;
    ListNode *slow;
    ListNode *fast;
    ListNode *temp;
    int i = 0;
        
    if(head == NULL)
      return NULL;
        
    dummy->next = head;
    head = dummy;
        
    slow = head;
    fast = head;
        
    for(i = 0; i < n + 1; i++)
    {
      fast = fast->next;
    }
        
    while(fast != NULL)
    {
      slow = slow->next;
      fast = fast->next;
    }
        
    temp = slow->next;
    slow->next = slow->next->next;
    delete[] temp;
        
    head = head->next;
    delete[] dummy;
        
    return head;
  }
};



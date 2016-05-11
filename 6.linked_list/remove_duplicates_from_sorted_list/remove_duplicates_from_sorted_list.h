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
   * @return: head node
   */
  ListNode *deleteDuplicates(ListNode *head) {
    // write your code here
    ListNode *curr = head;
        
    while(head != NULL)
    {
      while(head->next != NULL && head->val == head->next->val)
      {
        head->next = head->next->next;
      }
      head = head->next;
    }
        
    return curr;
  }
};

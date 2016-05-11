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
   * @return a ListNode
   */
  ListNode* swapPairs(ListNode* head) {
    // Write your code here
        
    ListNode *dummy = new ListNode;
    ListNode *curr = dummy;
    ListNode *temp;
    dummy->next = head;
    head = dummy;
        
    while(curr->next != NULL && curr->next->next != NULL)
    {
      temp = curr->next;
      curr->next = curr->next->next;
      temp->next = curr->next->next;
      curr->next->next = temp;
      curr = curr->next->next;
    }
        
    return dummy->next;
  }
};

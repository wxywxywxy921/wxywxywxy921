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
  ListNode *removeDuplicates(ListNode *head) {
    // Write your code here
        
    ListNode *dummy = new ListNode;
    ListNode *curr;
    unordered_set<int> hash;
        
    dummy->next = head;
    head = dummy;
    curr = head;
        
    while(curr->next != NULL)
    {
      if(hash.find(curr->next->val) != hash.end())
      {
        curr->next = curr->next->next;
      }
      else
      {
        hash.insert(curr->next->val);
        curr = curr->next;
      }
    }
        
    return dummy->next;
  }
};


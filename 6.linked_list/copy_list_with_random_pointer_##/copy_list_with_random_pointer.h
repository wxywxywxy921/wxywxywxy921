/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
  /**
   * @param head: The head of linked list with a random pointer.
   * @return: A new head of a deep copy of the list.
   */
  RandomListNode *copyRandomList(RandomListNode *head) {
    // write your code here
        
    if(head == NULL)
      return NULL;
        
    // [step 1] create the copy node in the original list
        
    RandomListNode *ori_curr = head;
    RandomListNode *cpy_curr;
    RandomListNode *cpy_head;
        
    while(ori_curr != NULL)
    {
      cpy_curr = new RandomListNode(ori_curr->label);
      cpy_curr->next = ori_curr->next;
      ori_curr->next = cpy_curr;
      ori_curr = cpy_curr->next;
    }
        
    // [step 2] set the random ptr for the copy node
        
    ori_curr = head;
        
    while(ori_curr != NULL)
    {
      cpy_curr = ori_curr->next;
            
      if(ori_curr->random != NULL) // !!! I missed it
      {
        cpy_curr->random = ori_curr->random->next;
      }
            
      ori_curr = cpy_curr->next;
    }
        
    // [step 3] decouple two lists
        
    cpy_head = new RandomListNode;
    ori_curr = head;
    cpy_curr = cpy_head;
        
    while(ori_curr != NULL)
    {
      cpy_curr->next  = ori_curr->next;
      cpy_curr = cpy_curr->next;
      ori_curr = cpy_curr->next;
    }
        
    return cpy_head->next;
  }
};

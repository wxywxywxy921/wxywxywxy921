/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
 this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
  /**
   * @param root: The root of tree
   * @return: the head of doubly list node
   */
  DoublyListNode* bstToDoublyList(TreeNode* root) {
    // Write your code here
        
    if(root == NULL)
      return NULL;
            
    DoublyListNode *ret = helper(root);
        
    return seekToBegin(ret);
  }
    
  DoublyListNode* helper(TreeNode* root) 
  {
    if(root == NULL)
    {
      return NULL;
    }
        
    DoublyListNode *left_end, *right_end, *curr, *right_begin;
        
    left_end = helper(root->left);
    right_end = helper(root->right);
    curr = new DoublyListNode(root->val);
        
    if(left_end != NULL)
    {
      left_end->next = curr;
      curr->prev = left_end;
    }
    else
    {
      curr->prev = NULL;
    }
        
    right_begin = seekToBegin(right_end);
        
    if(right_begin != NULL)
    {
      curr->next = right_begin;
      right_begin->prev = curr;
    }
    else
    {
      curr->next = NULL;
    }
        
    return seekToEnd(curr);
  }
    
  DoublyListNode* seekToBegin(DoublyListNode* curr)
  {
    if(curr == NULL)
    {
      return NULL;
    }
        
    while(curr->prev != NULL)
    {
      curr = curr->prev;
    }
        
    return curr;
  }
    
  DoublyListNode* seekToEnd(DoublyListNode* curr)
  {
    if(curr == NULL)
    {
      return NULL;
    }
        
    while(curr->next != NULL)
    {
      curr = curr->next;
    }
        
    return curr;
  }
};



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
 */
class Solution {
public:
  /**
   * @param head: The first node of linked list.
   * @return: a tree node
   */
     
  int list_entry_count(ListNode *head)
  {
    int count = 0;
        
    while(head != NULL)
    {
      count ++;
      head = head->next;
    }
        
    return count;
  }
     
  ListNode *get_list_entry(ListNode *head, int n)
  {
    int count = 0;
        
    while(head != NULL)
    {   
      count ++;
            
      if(count == n)
        break;
                
      head = head->next;
    }
        
    return head;
  }
    
  TreeNode *helper(ListNode *head, int count)
  {
    TreeNode *root, *left, *right;
    ListNode *temp;
        
    if(!count)
      return NULL;
            
    if(head == NULL)
      return NULL;
        
    root = new TreeNode;
        
    left = helper(head, count / 2);
    temp = get_list_entry(head, count / 2 + 1);
    root->val = temp->val;
    right = helper(temp->next, count - (count / 2 + 1));
        
    root->left = left;
    root->right = right;
        
    return root;
  }
     
  TreeNode *sortedListToBST(ListNode *head) {
    // write your code here
        
    int count = list_entry_count(head);
    TreeNode *ret;
        
    ret = helper(head, count);
        
    return ret;
  }
    
};



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
 */
class Solution {
public:
  /**
   * @param root: The root of binary tree.
   * @return: An integer
   */
  int maxDepth(TreeNode *root) {
    // write your code here
        
    int ret = 0;
        
    if(root != NULL)
    {
      ret = helper(root);
    }
        
    return ret;
  }
    
  int helper(TreeNode *root)
  {
    int ret;
    int ret_left, ret_right;
        
    if(root == NULL)
      return 0;
            
    ret_left = helper(root->left);
    ret_right = helper(root->right);
        
    if(ret_left > ret_right)
      ret = ret_left + 1;
    else
      ret = ret_right + 1;
            
    return ret;
  }
};

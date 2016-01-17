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
  int minDepth(TreeNode *root) {
    // write your code here
        
    int ret;
        
    ret = helper(root);
        
    return ret;
  }
    
  int helper(TreeNode *root)
  {
    if(root == NULL)
    {
      return 0;
    }
        
    int left = helper(root->left);
    int right = helper(root->right);
        
    // [xywu] important
    if(!left)
      return right + 1;
    if(!right)
      return left + 1;
            
    if(left < right)
      return left + 1;
    else 
      return right + 1;
  }
};

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
   * @param root, the root of binary tree.
   * @return true if it is a mirror of itself, or false.
   */
  bool isSymmetric(TreeNode* root) {
    // Write your code here
        
    bool ret = false;
        
    if(root)
    {
      ret = helper(root->left, root->right);
    }
    else
    {
      ret = true;
    }
        
    return ret;
  }
    
  bool helper(TreeNode *left, TreeNode *right)
  {
    if(left == NULL && right == NULL)
      return true;
            
    if(left == NULL || right == NULL)
      return false;
            
    if(left->val != right->val)
      return false;
            
    if(helper(left->left, right->right)
       && helper(left->right, right->left))
      return true;
    else 
      return false;
  }
};

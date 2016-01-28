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
   * @param root the root of binary tree.
   * @return an integer
   */
  int maxPathSum2(TreeNode *root) {
    // Write your code here
        
    int ret;
    int ret_left;
    int ret_right;
        
    if(root == NULL)
    {
      return 0;
    }
        
    ret = root->val;
    ret_left = maxPathSum2(root->left);
    ret_right = maxPathSum2(root->right);
        
    if(ret_left > ret_right
       && ret_left > 0)
      ret += ret_left;
        
    if(ret_right > ret_left
       && ret_right > 0)
      ret += ret_right;
            
    return ret;
  }
};

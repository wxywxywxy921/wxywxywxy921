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
typedef struct RESULT
{
  int sub_max;
  int path_max;
} RES;
 
class Solution {
public:
  /**
   * @param root: The root of binary tree.
   * @return: An integer
   */
  int maxPathSum(TreeNode *root) {
    // write your code here
        
    RES ret = helper(root);
        
    return ret.sub_max;
  }
    
  RES helper(TreeNode *root) {    
    RES ret;
    RES ret_left;
    RES ret_right;
    int max;
        
    if(root == NULL)
    {
      ret.sub_max = 0;
      ret.path_max = 0;
      return ret;
    }
        
    ret_left = helper(root->left);
    ret_right = helper(root->right);
        
    max = ret_left.path_max + root->val + ret_right.path_max;
        
    if(root->left && ret_left.sub_max > max)
      max = ret_left.sub_max;
            
    if(root->right && ret_right.sub_max > max)
      max = ret_right.sub_max;
            
    if(root->val > max)
      max = root->val;
            
    ret.sub_max = max;
        
    if(ret_left.path_max > ret_right.path_max)
      max = root->val + ret_left.path_max;
    else
      max = root->val + ret_right.path_max;
            
    if(root->val > max)
      max = root->val;
            
    ret.path_max = max;
        
    return ret;
  }
};

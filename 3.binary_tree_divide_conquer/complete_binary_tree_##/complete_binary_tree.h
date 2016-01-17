typedef struct RESULT
{
  int depth;
  bool is_full;
  bool is_complete;
} result;

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
   * @return true if it is a complete binary tree, or false.
   */
  bool isComplete(TreeNode* root) {
    // Write your code here
        
    result ret;
        
    ret = helper(root);
        
    return ret.is_complete;
  }
    
  result helper(TreeNode* root)
  {
    result ret;
        
    if(root == NULL)
    {
      ret.depth = 0;
      ret.is_full = true;
      ret.is_complete = true;
            
      return ret;
    }
        
    result ret_left = helper(root->left);
    result ret_right = helper(root->right);
        
    if(ret_left.depth == ret_right.depth)
    {
      // [xywu] which means the right is not empty
      // so the left should be full
            
      if(ret_left.is_full && ret_right.is_complete)
      {
        ret.depth = ret_left.depth + 1;
        ret.is_complete = true;
        ret.is_full = ret_right.is_full;
      }
      else
      {
        ret.depth = -1;
        ret.is_complete = false;
        ret.is_full = false;
      }
      return ret;
    }
    else if(ret_left.depth == ret_right.depth + 1)
    {
      if(ret_left.is_complete && ret_right.is_full)
      {
        ret.depth = ret_left.depth + 1;
        ret.is_complete = true;
        ret.is_full = false;
      }
      else
      {
        ret.depth = -1;
        ret.is_complete = false;
        ret.is_full = false;
      }
      return ret;
    }
    else
    {
      ret.depth = -1;
      ret.is_complete = ret.is_full = false;
      return ret;
    }
  }
};

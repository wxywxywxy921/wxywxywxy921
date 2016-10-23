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
  int depth;
  bool is_bal;
} RES;
 
class Solution {
public:
  /**
   * @param root: The root of binary tree.
   * @return: True if this Binary tree is Balanced, or false.
   */
  bool isBalanced(TreeNode *root) {
    // write your code here
        
    bool ret = true;
    RES result;
        
    if(root)
    {
      result = helper(root);
      ret = result.is_bal;
    }
        
    return ret;
  }
    
  RES helper(TreeNode *root)
  {
    RES ret, ret_left, ret_right;
        
    if(!root)
    {
      ret.depth = 0;
      ret.is_bal = true;
            
      return ret;
    }
        
    ret_left = helper(root->left);
    ret_right = helper(root->right);
        
    if(!ret_left.is_bal || !ret_right.is_bal)
    {
      ret.depth = -1;
      ret.is_bal = false;
    }
    else
    {
      if(ret_left.depth > ret_right.depth)
      {
        if(ret_left.depth - ret_right.depth > 1)
        {
          ret.depth = -1;
          ret.is_bal = false;
        }
        else
        {
          ret.depth = ret_left.depth + 1;
          ret.is_bal = true;
        }
      }
      else if(ret_left.depth < ret_right.depth)
      {
        if(ret_right.depth - ret_left.depth > 1)
        {
          ret.depth = -1;
          ret.is_bal = false;
        }
        else
        {
          ret.depth = ret_right.depth + 1;
          ret.is_bal = true;
        }
      }
      else
      {
        ret.depth = ret_right.depth + 1;
        ret.is_bal = true;
      }
    }
        
    return ret;
  }
};


SIMPLE WAY:

Using the depth == -1 to show if the sub is balanced

class Solution {
public:
    int depth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        return max(left, right) + 1;
    }

    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        return depth(root) != -1;
    }
};

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
 
#define MAX 999999
#define MIN -999999
 
class Solution {
public:
  /**
   * @param root: The root of binary tree.
   * @return: True if the binary tree is BST, or false
   */
  bool isValidBST(TreeNode *root) {
    // write your code here
        
    int max = MIN; 
    int min = MAX;
    bool ret = true;
        
    if(root != NULL)
    {
      ret = isValidBST(root, max, min);
    }
        
    return ret;
  }
    
  bool isValidBST(TreeNode *root, int &max, int &min)
  {
    bool ret, ret_left, ret_right;
    int max_left, max_right, min_left, min_right;
        
    max_left = max_right = MIN;
    min_left = min_right = MAX;
        
    if(root == NULL)
    {
      max = MIN;
      min = MAX;
            
      return true;
    }
        
    ret_left = isValidBST(root->left, max_left, min_left);
    ret_right = isValidBST(root->right, max_right, min_right);
        
    if(root->left)
    {
      if(ret_left && root->val > max_left)
      {
        ret_left = true;
      }
      else
      {
        ret_left = false;
      }
            
      min = min_left;
    }
    else
    {
      min = root->val;
    }
        
    if(root->right)
    {
      if(ret_right && root->val < min_right)
      {
        ret_right = true;
      }
      else
      {
        ret_right = false;
      }
            
      max = max_right;
    }
    else
    {
      max = root->val;
    }
        
    if(ret_left && ret_right)
      ret = true;
    else
      ret = false;
            
    return ret;
  }
};

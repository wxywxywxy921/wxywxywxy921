/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
typedef struct RESULT
{
  TreeNode *last_bigger;
  TreeNode *eq;
} Res;

class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    // write your code here
        
    Res ret;
        
    if(root != NULL)
      ret = helper_find(root, p);
    else
      return NULL;
            
    if(ret.last_bigger != NULL)
      return ret.last_bigger;
    else
      return NULL;
  }
    
  Res helper_find(TreeNode* root, TreeNode* p)
  {
    Res ret;
        
    ret.eq = NULL;
    ret.last_bigger = NULL;
        
    if(root == NULL)
    {
      ret.last_bigger = NULL;
      ret.eq = NULL;
            
      return ret;
    }
            
    if(root->val == p->val)
    {
      ret = helper_find(root->right, p);
      ret.eq = root;
    }
    else if(root->val < p->val)
    {
      ret = helper_find(root->right, p);
    }
    else // >
    {
      ret = helper_find(root->left, p);
            
      if(ret.last_bigger && ret.last_bigger->val > root->val)
      {
        ret.last_bigger = root;
      }
            
      if(ret.last_bigger == NULL)
      {
        ret.last_bigger = root;
      }
    }
        
    return ret;
  }
};

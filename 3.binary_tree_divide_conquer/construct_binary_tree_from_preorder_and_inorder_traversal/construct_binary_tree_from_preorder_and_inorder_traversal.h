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
  /**
   *@param preorder : A list of integers that preorder traversal of a tree
   *@param inorder : A list of integers that inorder traversal of a tree
   *@return : Root of a tree
   */
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    // write your code here
        
    TreeNode *ret = NULL;
    int begin_pre, end_pre;
    int begin_in, end_in;
        
    begin_pre = begin_in = 0; 
    end_pre = end_in = inorder.size() - 1;
        
    if(preorder.size())
      ret = helper(preorder, inorder, 
                   begin_pre, end_pre,
                   begin_in, end_in);
        
    return ret;
  }
    
  TreeNode *helper(vector<int> &preorder, 
                   vector<int> &inorder,
                   int begin_pre, int end_pre, 
                   int begin_in, int end_in)
  {
    TreeNode *root;
    int i;
    int dist;
        
    if(begin_in > end_in)
    {
      return NULL;
    }
        
    if(begin_pre > end_pre)
    {
      return NULL;
    }
        
    root = new TreeNode(preorder[begin_pre]);
        
    for(i = 0; i < preorder.size(); i++)
    {
      if(inorder[i] == preorder[begin_pre])
        break;
    }
        
    dist = i - begin_in;
        
    root->left = helper(preorder, inorder,
                        begin_pre + 1, begin_pre + dist,
                        begin_in, i - 1);
        
    root->right = helper(preorder, inorder,
                         begin_pre + dist + 1, end_pre,
                         i + 1, end_in);
                             
    return root;
  }
};

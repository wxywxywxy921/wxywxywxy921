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
   *@param inorder : A list of integers that inorder traversal of a tree
   *@param postorder : A list of integers that postorder traversal of a tree
   *@return : Root of a tree
   */
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    // write your code here
        
    int begin_in, end_in;
    int begin_post, end_post;
        
    TreeNode *ret = NULL;
        
    begin_in = begin_post = 0;
    end_in = end_post = inorder.size() - 1;
        
    if(inorder.size())
    {
      ret = helper(inorder, postorder,
                   begin_in, end_in,
                   begin_post, end_post);
    }
        
    return ret;
  }
    
  TreeNode *helper(vector<int> &inorder, vector<int> &postorder,
                   int begin_in, int end_in,
                   int begin_post, int end_post)
  {
    if(begin_in > end_in)
      return NULL;
            
    if(begin_post > end_post)
      return NULL;
            
    TreeNode *root = new TreeNode(postorder[end_post]);
    int i = 0;
    int dist;
        
    for(; i < inorder.size(); i++)
    {
      if(inorder[i] == postorder[end_post])
        break;
    }
        
    dist = end_in - i;
        
    root->left = helper(inorder, postorder,
                        begin_in, i - 1,
                        begin_post, end_post - dist - 1);
                            
    root->right = helper(inorder, postorder,
                         i + 1, end_in,
                         end_post - dist, end_post - 1);
        
    return root;
  }
    
};

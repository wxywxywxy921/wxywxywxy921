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
  bool found_a;
  bool found_b;
  TreeNode *lca;
}RES;
 
class Solution {
public:
  /**
   * @param root: The root of the binary search tree.
   * @param A and B: two nodes in a Binary.
   * @return: Return the least common ancestor(LCA) of the two nodes.
   */
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
    // write your code here
        
    RES result;
        
    if(root)
    {
      result = helper( root, A, B);
      return result.lca;
    }
    else
    {
      return NULL;
    }
  }
    
  RES helper(TreeNode *root, TreeNode *A, TreeNode *B)
  {
    RES ret, ret_left, ret_right;
        
    if(!root)
    {
      ret.found_a = false;
      ret.found_b = false;
      ret.lca = NULL;
            
      return ret;
    }
        
    ret_left = helper(root->left, A, B);
    ret_right = helper(root->right, A, B);
        
    if((ret_left.found_a && ret_right.found_b)
       || (ret_left.found_b && ret_right.found_a)
       || (A->val == B->val == root->val)
       || (A->val == root->val && (ret_left.found_b || ret_right.found_b))
       || (B->val == root->val && (ret_left.found_a || ret_right.found_a)))
    {
      ret.lca = root;
    }
    else if(ret_left.lca)
    {
      ret.lca = ret_left.lca;
    }
    else if(ret_right.lca)
    {
      ret.lca = ret_right.lca;
    }
    else
    {
      ret.lca = NULL;
    }
        
    if((root->val == A->val)
       || ret_left.found_a || ret_right.found_a)
      ret.found_a = true;
    else
      ret.found_a = false;
        
    if((root->val == B->val)
       || ret_left.found_b || ret_right.found_b)
      ret.found_b = true;
    else
      ret.found_b = false;
        
    return ret;
  }
};

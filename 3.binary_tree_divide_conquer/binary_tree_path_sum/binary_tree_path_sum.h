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
   * @param root the root of binary tree
   * @param target an integer
   * @return all valid paths
   */
  vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
    // Write your code here
        
    vector<vector<int> > ret;
        
    ret = helper(root, target);
        
    return ret;
  }
    
  vector<vector<int> > helper(TreeNode *root, int target)
  {
    vector<vector<int> > ret;
    vector<vector<int> > left;
    vector<vector<int> > right;
    vector<int> tmp;
        
    int i;
        
    if(!root)
    {
      return ret;
    }
        
    if((target - root->val) == 0)
    {
      // [xywu] found the last piece
            
      tmp.push_back(root->val);
      ret.push_back(tmp);
      return ret;
    }
        
    left = helper(root->left, target - root->val);
    right = helper(root->right, target - root->val);
        
    for(i = 0; i < left.size(); i++)
    {
      ret.push_back(left[i]);
      ret.back().insert(ret.back().begin(), root->val);
    }
        
    for(i = 0; i < right.size(); i++)
    {
      ret.push_back(right[i]);
      ret.back().insert(ret.back().begin(), root->val);
    }
        
    return ret;
  }
};

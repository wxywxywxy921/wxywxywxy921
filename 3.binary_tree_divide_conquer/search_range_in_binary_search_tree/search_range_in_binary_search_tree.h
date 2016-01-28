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
   * @param root: The root of the binary search tree.
   * @param k1 and k2: range k1 to k2.
   * @return: Return all keys that k1<=key<=k2 in ascending order.
   */
  vector<int> searchRange(TreeNode* root, int k1, int k2) {
    // write your code here
        
    vector<int> ret;
        
    if(root != NULL)
      ret = helper(root, k1, k2);
            
    return ret;
  }
    
  vector<int> helper(TreeNode* root, int k1, int k2)
  {
    vector<int> ret;
    vector<int> ret_left;
    vector<int> ret_right;
        
    if(root == NULL)
      return ret;
            
    if(root->val >= k1 && root->val <= k2)
    {
      ret_left = helper(root->left, k1, k2);
      ret.insert(ret.end(), ret_left.begin(), ret_left.end());
            
      ret.push_back(root->val);
            
      ret_right = helper(root->right, k1, k2);
      ret.insert(ret.end(), ret_right.begin(), ret_right.end());
    }
    else if(root->val < k1)
    {
      ret = helper(root->right, k1, k2);
    }
    else
    {
      ret = helper(root->left, k1, k2);
    }
        
    return ret;
  }
};

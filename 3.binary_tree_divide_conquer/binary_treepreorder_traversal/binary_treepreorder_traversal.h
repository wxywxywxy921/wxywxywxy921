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
   * @param root: The root of binary tree.
   * @return: Preorder in vector which contains node values.
   */
  vector<int> preorderTraversal(TreeNode *root) {
    // write your code here
        
    vector<int> ret;
    vector<int> ret_left;
    vector<int> ret_right;
        
    if(root == NULL)
      return ret;
            
    ret.push_back(root->val);
    ret_left = preorderTraversal(root->left);
    ret_right = preorderTraversal(root->right);
    ret.insert(ret.end(), ret_left.begin(), ret_left.end());
    ret.insert(ret.end(), ret_right.begin(), ret_right.end());
        
    return ret;
  }
};

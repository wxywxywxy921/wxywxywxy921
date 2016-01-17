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
   * @param root: The root of binary tree.
   * @return: Inorder in vector which contains node values.
   */
public:
  vector<int> inorderTraversal(TreeNode *root) {
    // write your code here
        
    vector<int> ret;
    int i;
        
    if(root == NULL)
      return ret;
            
    vector<int> left = inorderTraversal(root->left);
    vector<int> right = inorderTraversal(root->right);
        
    for(i = 0; i < left.size(); i++)
      ret.push_back(left[i]);
            
    ret.push_back(root->val);
        
    for(i = 0; i < right.size(); i++)
      ret.push_back(right[i]);
            
    return ret;
  }
};

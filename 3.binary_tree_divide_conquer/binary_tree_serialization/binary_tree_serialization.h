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
   * This method will be invoked first, you should design your own algorithm 
   * to serialize a binary tree which denote by a root node to a string which
   * can be easily deserialized by your own "deserialize" method later.
   */
  string serialize(TreeNode *root) {
    // write your code here
        
    string ret;
    string ret_left;
    string ret_right;
        
    if(root == NULL)
    {
      ret.push_back('#');
      return ret;
    }
        
    ret_left = serialize(root->left);
    ret_right = serialize(root->right);
    ret.push_back(root->val + '0');
    ret += ret_left;
    ret += ret_right;
        
    return ret;
  }

  /**
   * This method will be invoked second, the argument data is what exactly
   * you serialized at method "serialize", that means the data is not given by
   * system, it's given by your own serialize method. So the format of data is
   * designed by yourself, and deserialize it here as you serialize it in 
   * "serialize" method.
   */
  TreeNode *deserialize(string data) {
    // write your code here
        
    TreeNode *root;
    int idx = 0;
        
    if(data.size())
    {
      root = helper(data, idx);
    }
        
    return root;
  }
        
  TreeNode *helper(string data, int &idx)
  {
    TreeNode *root = NULL;
    TreeNode *root_left = NULL;
    TreeNode *root_right = NULL;
        
    if(data[idx] == '#'
       || idx >= data.size())
    {
      idx ++;
      return root;
    }
        
    root = new TreeNode(data[idx] - '0');
    idx ++;
        
    root->left = helper(data, idx);
    root->right = helper(data, idx);
        
    return root;
  }
};

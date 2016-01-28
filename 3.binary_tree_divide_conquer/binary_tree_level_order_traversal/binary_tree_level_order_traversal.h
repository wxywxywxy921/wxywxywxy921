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
   * @return: Level order a list of lists of integer
   */
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    // write your code here
        
    queue<TreeNode *> reorder;
    vector<int> temp;
    TreeNode *cur;
    vector<vector<int> > ret;
    int size, i;
        
    if(root)
    {
      reorder.push(root);
      size = 1;
    }
    else
    {
      return ret;
    }
        
    while(1)
    {
      for(i = 0; i < size; i++) 
      {
        cur = reorder.front();
        reorder.pop();
        temp.push_back(cur->val);
               
        if(cur->left)
          reorder.push(cur->left);
                
        if(cur->right)
          reorder.push(cur->right);
      }
           
      ret.push_back(temp);
      size = reorder.size();
      temp.clear();
           
      if(!size)
        break;
    }
        
    return ret;
        
  }
};

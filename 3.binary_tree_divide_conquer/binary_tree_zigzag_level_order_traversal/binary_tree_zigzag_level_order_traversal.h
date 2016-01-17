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
   * @return: A list of lists of integer include 
   *          the zigzag level order traversal of its nodes' values 
   */
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    // write your code here
        
    int begin = 0;
    int end = 1;
    int size = 0;
    bool is_right = false;
    int i;
    vector<vector<int> > ret;
    vector<int> tmp;
    vector<TreeNode *> cur;
        
    if(root)
      cur.push_back(root);
    else
      return ret;
        
    while(1)
    {
      if(is_right)
        for(i = end - 1; i >= begin; i--)
        {
          tmp.push_back(cur[i]->val);
        }
      else
        for(i = begin; i < end; i++)
        {
          tmp.push_back(cur[i]->val);
        }
            
      ret.push_back(tmp);
            
      size = 0;
            
      for(i = 0; i < tmp.size(); i++)
      {
        if(cur[begin + i]->left)
        {
          cur.push_back(cur[begin + i]->left);
          size ++;
        }
                
        if(cur[begin + i]->right)
        {
          cur.push_back(cur[begin + i]->right);
          size ++;
        }
      }
            
      if(!size)
        break;
            
      tmp.clear();
      begin = end;
      end += size;
      if(is_right)
        is_right = false;
      else
        is_right = true;
    }
        
    return ret;
  }
};

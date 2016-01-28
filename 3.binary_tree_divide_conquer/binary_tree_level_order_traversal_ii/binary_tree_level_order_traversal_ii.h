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
   * @param root : The root of binary tree.
   * @return : buttom-up level order a list of lists of integer
   */
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    // write your code here
        
    vector<vector<int> > ret;
    vector<int> cur;
    queue<TreeNode *> tree_2_queue;
    TreeNode *temp;
    int size;
    int i;
        
    if(root == NULL)
      return ret;
        
    tree_2_queue.push(root);
    size = 1;
        
    while(1)
    {
      for(i = 0; i < size; i++)
      {
        temp = tree_2_queue.front();
        tree_2_queue.pop();
        cur.push_back(temp->val);

        if(temp->left != NULL)
          tree_2_queue.push(temp->left);
        if(temp->right != NULL)
          tree_2_queue.push(temp->right);
      }
            
      ret.insert(ret.begin(), cur);
      size = tree_2_queue.size();
      cur.clear();
            
      if(!size)
        break;
    }
        
    return ret;
  }
};

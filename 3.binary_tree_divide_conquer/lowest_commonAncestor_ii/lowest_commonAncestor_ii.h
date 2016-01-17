/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */
class Solution {
public:
  /**
   * @param root: The root of the tree
   * @param A, B: Two node in the tree
   * @return: The lowest common ancestor of A and B
   */
  ParentTreeNode *lowestCommonAncestorII(ParentTreeNode *root,
                                         ParentTreeNode *A,
                                         ParentTreeNode *B) {
    // Write your code here
        
    vector<ParentTreeNode *> path_a;
    vector<ParentTreeNode *> path_b;
    ParentTreeNode *tmp;
    ParentTreeNode *ret = 0;
    int idx = 0;
        
    tmp = A;
        
    while(tmp)
    {
      path_a.push_back(tmp);
      tmp = tmp->parent;
    }
        
    tmp = B;
        
    while(tmp)
    {
      path_b.push_back(tmp);
      tmp = tmp->parent;
    }
        
    if(path_a.size() && path_b.size())
    {
      while(1)
      {
        if(path_a[path_a.size() - 1 - idx]->val == path_b[path_b.size() - 1 - idx]->val)
        {
          ret = path_a[path_a.size() - 1 - idx];
          idx ++;
        }
        else
        {
          break;
        }
                
        if(idx > path_a.size() - 1 || idx > path_b.size() - 1)
        {
          break;
        }
      }
    }
        
    return ret;
  }
};

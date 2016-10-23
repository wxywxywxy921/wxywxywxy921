/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
  /**
   * @param graph: A list of Directed graph node
   * @return: Any topological order for the given graph.
   */
  vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
    // write your code here
        
    map<DirectedGraphNode *, int> indegree, indegree_backup;
    vector<DirectedGraphNode*> ret;
    int i;
        
    if(!graph.size())
    {
      return ret;
    }
        
    getIndegree(graph, indegree);
    indegree_backup = indegree;
        
    for(i = 0; i < graph.size(); i ++)
    {
      if(!indegree_backup[graph[i]])
      {
        //printf("[0] label=%d\n", graph[i]->label);
        ret.push_back(graph[i]);
        helper(graph[i], indegree, ret);
      }
    }
        
    return ret;
  }
    
    
  // DFS solution
  void getIndegree(vector<DirectedGraphNode*> graph, map<DirectedGraphNode *, int> &indegree)
  {
    int i = 0;
    int j = 0;
        
    for(i = 0; i < graph.size(); i++)
    {
      for(j = 0; j < graph[i]->neighbors.size(); j++)
      {
        if(indegree.find(graph[i]->neighbors[j]) == indegree.end())
        {
          indegree[graph[i]->neighbors[j]] = 1;
        }
        else
        {
          indegree[graph[i]->neighbors[j]] ++;
        }
      }
    }
  }
    
  void helper(DirectedGraphNode* node, 
              map<DirectedGraphNode *, int> &indegree, 
              vector<DirectedGraphNode*> &ret)
  {
    int i = 0;
        
    if(!node->neighbors.size())
    {
      return;
    }
        
    for(i = 0; i < node->neighbors.size(); i++)
    {
      indegree[node->neighbors[i]] --;
            
      if(!indegree[node->neighbors[i]])
      {
        //printf("[2] label=%d\n", node->neighbors[i]->label);
        ret.push_back(node->neighbors[i]);
        helper(node->neighbors[i], indegree, ret);
      }
    }
  }
};

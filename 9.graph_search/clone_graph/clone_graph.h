/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
  /**
   * @param node: A undirected graph node
   * @return: A undirected graph node
   */
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    // write your code here
        
    if(!node)
      return NULL;
        
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> record;
    queue<UndirectedGraphNode *> fifo;
    UndirectedGraphNode *temp;
    int i;
        
    UndirectedGraphNode *copied_node = new UndirectedGraphNode(node->label);
    record[node] = copied_node;
    fifo.push(node);
        
    while(fifo.size() > 0)
    {
      temp = fifo.front();
      fifo.pop();
            
      for(i = 0; i < temp->neighbors.size(); i++)
      {
        if(record.find(temp->neighbors[i]) != record.end())  // [xywu] !!! using "find" in unordered_map
        {
          record[temp]->neighbors.push_back(record[temp->neighbors[i]]);
        }
        else
        {
          UndirectedGraphNode *curr = new UndirectedGraphNode(temp->neighbors[i]->label);
          record[temp->neighbors[i]] = curr;
          record[temp]->neighbors.push_back(curr);
          fifo.push(temp->neighbors[i]); // [xywu] should push the ori instead of the copied
        }
      }
    }
        
    return record[node];
  }
};


//[xywu] we can also use the recursion and we use the stack provided by the compiler instead of the queue on the stack

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
    unordered_map<int, UndirectedGraphNode*> um;
    UndirectedGraphNode* cloneHelper(UndirectedGraphNode *node) {
        if(node == NULL) {
            return NULL;
        }
        if(um.find(node->label) != um.end()) {
            return um[node->label];
        }
        UndirectedGraphNode* n = new UndirectedGraphNode(node->label);
        um[node->label] = n;
        int i;
        int size = (node->neighbors).size();
        for(i = 0;i < size;i ++) {
            (n->neighbors).push_back(cloneHelper((node->neighbors)[i]));
        }
        return n;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) {
            return NULL;
        }
        um.clear();
        return cloneHelper(node);
    }
};
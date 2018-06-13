/*
Description

Given an directed graph, a topological order of the graph nodes is defined as follow:

    For each directed edge A -> B in graph, A must before B in the order list.
    The first node in the order can be any node in the graph with no nodes direct to it.
*/
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
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        vector<DirectedGraphNode*> ret;
        unordered_map<DirectedGraphNode*, int> indegree;
        
        // calculate the indegree of all the nodes in the graph
        for(const auto &node : graph) {
            if(!node) continue;
            for(const auto &neighbor : node->neighbors) {
                if(!neighbor) continue;
                if(indegree.find(neighbor) == indegree.end()) {
                    indegree[neighbor] = 1;
                } else {
                    indegree[neighbor] += 1;
                }
            }
        }
        
        // put all the nodes with indegree 0 to the q
        std::queue<DirectedGraphNode*> q;
        for(const auto & node : graph) {
            if(indegree.find(node) == indegree.end()) {
                q.push(node);
                ret.push_back(node);   
            }
        }
    
        while(!q.empty()) {
            DirectedGraphNode* curNode = q.front();
            q.pop();
            for(const auto &neighbor : curNode->neighbors) {
                indegree[neighbor] -= 1;
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                    ret.push_back(neighbor);
                } 
            }
        }
        
        return ret;
    }
};
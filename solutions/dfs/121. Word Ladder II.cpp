/*
Description
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
All words have the same length.
All words contain only lowercase alphabetic characters.
Have you met this question in a real interview?  
Example
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
*/

解题思路
先用BFS建立从 end 到 start 的图
然后从start出发找到所有到end的路径


class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
    vector<vector<string>> findLadders(string &start, 
                                       string &end, 
                                       unordered_set<string> &dict) {
                                           
        unordered_map<string, unordered_set<string>> dictGraph;
        unordered_map<string, int> distance;

        
        dict.insert(start);
        dict.insert(end);
        
        bfs(end, start, dict, distance, dictGraph);
        
        vector<vector<string>> results;
        vector<string> path;
        
        dfs(start, end, dictGraph, distance, path, results);
        
        return results;
    }
    
private:
    // 从起点向终点做深度优先搜索
    // 每次搜索的时候，只取那些到终点的距离和当前节点到终点的距离相比差１的
    // 这样可以提高搜索效率，并且避免回头
    void dfs(const string & current, 
             const string & end, 
             unordered_map<string, unordered_set<string>> &dictGraph,
             unordered_map<string, int> &distance,
             vector<string> path,
             vector<vector<string>> &results) {
                 
        path.push_back(current);
        
        if(current == end) {
            results.push_back(path); 
        } else {
            
            for(const auto & item : dictGraph[current]) {
                if(!distance.count(item)) continue;
                
                if(distance[current] == distance[item] + 1) {
                    dfs(item, end, dictGraph, distance, path, results);
                }
            }
        }
        
        path.pop_back();    
    }

    //　从终点往起点build一个有向图，并且记录这个有向图中每个结点到终点的距离
    void bfs(const string &start, 
            const string & end, 
            unordered_set<string> &dict,
            unordered_map<string, int> &distance,
            unordered_map<string, unordered_set<string>> &dictGraph) {
                
        //Init the graph as empty 
        for(const auto & item : dict) {
            unordered_set<string> tmp; 
            dictGraph[item] = tmp;
        }
        
               
        queue<string> q;
        
        q.push(start);
        distance[start] = 0;
        
        while(!q.empty()) {
            
            string head = q.front(); q.pop();
            // find all the string inside dict which has distance 1 to head
            unordered_set<string> expandedList = expand(head, dict);
            
            // build graph reversely 
            for(const auto & item : expandedList) {
                dictGraph[item].insert(head);
                //　如果这个节点第一次出现，那么记录它到end的距离
                // 并且把这个节点加入到queue中
                // 比如: hog -> hot, cog
                // hot -> hog, hit
                //　需要去重
                if(distance.count(item) == 0) {
                    distance[item] = distance[head] + 1;
                    q.push(item);
                }
            } // for(const auto & item : expandedList)
        }
    }
    
    unordered_set<string> expand(string & s, 
                unordered_set<string> &dict) {
        
        unordered_set<string> results;
        
        if(s.empty()) return results;
        
        for(int i = 0; i < s.length(); i++) {
            char orgChar = s[i];
            
            for(char c = 'a'; c <= 'z'; c++) {
                
                if(orgChar == c) continue;
                
                s[i] = c;
                
                if(dict.count(s) && !results.count(s)) {
                    results.insert(s); 
                }
                
                s[i] = orgChar;
            }
        }
        
        return results;
        
    }
};

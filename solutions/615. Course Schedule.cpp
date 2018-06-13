/*
Description

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
Have you met this question in a real interview?  
Example

Given n = 2, prerequisites = [[1,0]]
Return true

Given n = 2, prerequisites = [[1,0],[0,1]]
Return false

*/
class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // write your code here
        set<int> takenOrder;
        vector<int> indegree(numCourses, 0);
        for(const auto & it: prerequisites) {
            indegree[it.first]++;
        }
        
        std::queue<int> freeCourse;
        
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                freeCourse.push(i);    
                takenOrder.insert(i);   
            }
        }
 
        while(!freeCourse.empty()) {
            int cur = freeCourse.front();
            freeCourse.pop();
            // decrease the indegree of all the courses depend on current course
            for(const auto & itp : prerequisites) {
                if(itp.second == cur) {
                    indegree[itp.first]--;
                    if(indegree[itp.first] == 0) {
                        freeCourse.push(itp.first);
                        takenOrder.insert(itp.first); 
                    }
                }
            }
        }
        
        if(takenOrder.size() != numCourses)
            return false;
        return true;
    }
};
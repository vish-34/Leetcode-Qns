class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto &pre : prerequisites){
            int course = pre[0];
            int prerequisites = pre[1];

            adj[prerequisites].push_back(course);
            indegree[course]++;
        }

        queue<int>q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            count++;

            for(int next : adj[curr]){
                indegree[next]--;
                if(indegree[next] == 0)
                q.push(next);
            }
        }
        return count == numCourses;
    }
};
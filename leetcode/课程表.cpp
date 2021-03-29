class Solution {
public:
    void dfs(int u)
    {
        visited[u]=1;
        for(int i=0;i<edges[u].size();i++)
        {
            if(visited[edges[u][i]]==0)
            {
                dfs(edges[u][i]);
                if(!valid)
                {
                    return;
                }
            }
            else if(visited[edges[u][i]]==1)
                {
                    valid=false;
                    return;
                }
        }
        visited[u]=2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<numCourses&&valid;i++)
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }
        return valid;
    }
private:
    vector<vector<int> > edges;
    vector<int> visited;
    bool valid=true;
};
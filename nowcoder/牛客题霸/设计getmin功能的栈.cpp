class Solution {
public:
    /**
     * return a array which include all ans for op3
     * @param op int整型vector<vector<>> operator
     * @return int整型vector
     */
    vector<int> getMinStack(vector<vector<int> >& op) {
        // write code here
        vector<int> vec;
        int size=op.size();
        for(int i=0;i<size;i++)
        {
            if(op[i][0]==1)
            {
                if(stamin.empty())
                {
                    stadata.push(op[i][1]);
                    stamin.push(op[i][1]);
                }
                else
                {
                    stadata.push(op[i][1]);
                    if(op[i][1]<=stamin.top())
                        stamin.push(op[i][1]);
                    else
                    {
                        stamin.push(stamin.top());
                    }
                }
            }
            else if(op[i][0]==2)
            {
                stadata.pop();
                stamin.pop();
            }
            else
            {
                vec.push_back(stamin.top());
            }
        }
        return vec;
    }
    stack<int> stadata;
    stack<int> stamin;
};
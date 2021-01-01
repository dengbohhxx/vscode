class Solution {
public:
    /**
     * the medians
     * @param operations int整型vector<vector<>> ops
     * @return double浮点型vector
     */
    vector<double> flowmedian(vector<vector<int> >& operations)
    {
        // write code here
        vector<double> res;
        priority_queue<int, vector<int>, less<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;
        int i=0;
        for (auto v: operations)
        {
            int opt = v[0];
            if (opt == 1)
            {
                int insert = v[1];
                if (i&1)
                {
                    if (!left.empty() && left.top() > insert)
                    {
                        int top = left.top();
                        left.pop();
                        left.push(insert);
                        insert = top;
                    }
                    right.push(insert);
                }
                else
                {
                    if (!right.empty() && right.top() < insert)
                    {
                        int top = right.top();
                        right.pop();
                        right.push(insert);
                        insert = top;
                    }
                    left.push(insert);                   
                }
                i++;
            }
            else
            {
                if (left.empty())
                    res.push_back(-1);
                else if (i&1)
                {
                    res.push_back(left.top());
                }
                else
                {
                    res.push_back((left.top()+right.top())*0.5);
                }
            }
        }
        return res;
    }
};
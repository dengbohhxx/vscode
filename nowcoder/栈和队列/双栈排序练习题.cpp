class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        // write code here
        stack<int> data;
        stack<int> help;
        for(int i=numbers.size()-1;i>=0;i--)
        {
            data.push(numbers[i]);
        }
        while(!data.empty())
        {
            if(help.empty())
            {
                help.push(data.top());
                data.pop();
            }
            else
            {
                int temp=data.top();
                data.pop();
                if(temp>=help.top())
                {
                    help.push(temp);
                }
                else
                {
                    int k=0;
                    while(!help.empty()&&temp<help.top())
                    {
                        data.push(help.top());
                        help.pop();
                        k++;
                    }
                    help.push(temp);
                    while(k--)
                    {
                        help.push(data.top());
                        data.pop();
                    }
                }
            }
        }
        vector<int> vec;
        for(int i=0;i<numbers.size();i++)
        {
            vec.push_back(help.top());
            help.pop();
        }
        return vec;
    }
};
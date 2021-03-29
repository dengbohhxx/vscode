class UnionFind
{
    public:
        UnionFind(int n)
        {
            this->count=n;
            for(int i=0;i<n;i++)
            {
                parent.push_back(i);
                size.push_back(1);
                weight.push_back(1.0);
            }
        }
        int count1()
        {
            return this->count;
        }
        int find(int x)
        {
            if (x != parent[x]) {
                int origin = parent[x];
                parent[x] = find(parent[x]);
                weight[x] *= weight[origin];
            }
            return parent[x];
        }
        double connected(int p,int q)
        {
            int rootp=find(p);
            int rootq=find(q);
            if(rootp==rootq)
                return weight[p]/weight[q];
            else
                return -1.0;
        }
        void union1(int p,int q,double value)
        {
            int rootp=find(p);
            int rootq=find(q);
            if(rootp==rootq)
                return;
           parent[rootp] = rootq;
           weight[rootp] = weight[q] * value / weight[p];
            count--;
        }
    private:
    vector<int> parent;
    vector<double> weight;
    vector<int> size;
    int count;
};
class Solution {
public:
    //带权并查集

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        int temp=2*n;
        UnionFind * uf=new UnionFind(temp);
        unordered_map<string,int> hashmap;
        int id=0;
        for(int i=0;i<n;i++)
        {
            string s1=equations[i][0];
            string s2=equations[i][1];
            if(hashmap.count(s1)==0)
            {
                hashmap[s1]=id;
                id++;
            }
            if(hashmap.count(s2)==0)
            {
                hashmap[s2]=id;
                id++;
            }
            uf->union1(hashmap[s1],hashmap[s2],values[i]);
        }
        int m=queries.size();
        vector<double> vec(m,0);
        for(int i=0;i<m;i++)
        {
            string s1=queries[i][0];
            string s2=queries[i][1];
            int id1=INT_MAX;
            int id2=INT_MAX;
            if(hashmap.count(s1)>0)
            {
                id1=hashmap[s1];
            }
            if(hashmap.count(s2)>0)
            {
                id2=hashmap[s2];
            }
            if(id1==INT_MAX||id2==INT_MAX)
            {
                vec[i]=-1.0;
            }
            else
            {
                vec[i]=uf->connected(id1,id2);
            }
        }
        return vec;
    }
};
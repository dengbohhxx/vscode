#include<unordered_map>
class Solution {
public:
    /**
     * return topK string
     * @param strings string字符串vector strings
     * @param k int整型 the k
     * @return string字符串vector<vector<>>
     */
    struct keyvalue
    {
        string key;
        int val;
    };
    void heap(vector<keyvalue> &vec,int len,int index)//小跟堆
    {
        int minidx=index;
        int left=2*index+1;
        int right=2*index+2;
        if(left<len&&vec[left].val<=vec[minidx].val)
        {
            if(vec[left].val<vec[minidx].val)
                minidx=left;
            if(vec[left].val==vec[minidx].val)
            {
                if(vec[left].key>vec[minidx].key)
                    minidx=left;
            }
        }
        if(right<len&&vec[right].val<=vec[minidx].val)
        {
            if(vec[right].val<vec[minidx].val)
                minidx=right;
            if(vec[right].val==vec[minidx].val)
            {
                if(vec[right].key>vec[minidx].key)
                    minidx=right;
            }
        }
        if(minidx!=index)
        {
            swap(vec[minidx],vec[index]);
            heap(vec,len,minidx);
        }
    }
    
    vector<vector<string> > topKstrings(vector<string>& strings, int k) {
        // write code here
        int n=strings.size();
        vector<vector<string> > res;
        vector<string> row;
        if(n==0)
            return res;
        unordered_map<string,int> hash;
        for(int i=0;i<n;i++)//压入哈希表
        {
            hash[strings[i]]++;
        }
        vector<keyvalue> vec;
        for(unordered_map<string,int>::iterator iter=hash.begin();iter!=hash.end();iter++)//将string和出现次数转为keyvalue结构
        {
            keyvalue kv;
            kv.key=iter->first;
            kv.val=iter->second;
            vec.push_back(kv);
        }
        
        vector<keyvalue> vec1(vec.begin(),vec.begin()+k);
        for(int i=k/2-1;i>=0;i--)//数组前k个建成小跟堆
        {
            heap(vec1,k,i);
        }
        for(int i=k;i<vec.size();i++)//找出其中最大的k个
        {
            if(vec[i].val>=vec1[0].val)
            {
                if(vec[i].val>vec1[0].val)
                {
                    vec1[0]=vec[i];
                    heap(vec1,k,0);
                }
                else if(vec[i].val==vec1[0].val)
                {
                    if(vec[i].key<vec1[0].key)
                    {
                        vec1[0]=vec[i];
                        heap(vec1,k,0);
                    }
                }
            }
        }
        for(int i=k-1;i>0;i--)//调整顺序
        {
            swap(vec1[0],vec1[i]);
            heap(vec1,i,0);
        }
        for(int i=0;i<vec1.size();i++)
        {
            row.push_back(vec1[i].key);
            row.push_back(to_string(vec1[i].val));
            res.push_back(row);
            row.clear();
        }
        return res;
    }
};
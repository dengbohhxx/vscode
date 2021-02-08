struct keyvalue
{
    int key;
    int value;
};
class Solution {
public:
    void heap(vector<keyvalue> &vec,int len,int index)
    {
        int minidx=index;
        while(index<len)
        {
            int left=2*index+1;
            int right=2*index+2;
            if(left<len&&vec[left].value<=vec[minidx].value)
            {
                minidx=left;
            }
            if(right<len&&vec[right].value<=vec[minidx].value)
            {
                minidx=right;
            }
            if(index!=minidx)
            {
                swap(vec[index],vec[minidx]);
                index=minidx;
            }
            else
            {
                break;
            }
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> vec2;
        if(n==0)
        {
            return vec2;
        }
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]]++;
        }
        vector<keyvalue> vec;
        for(unordered_map<int,int>::iterator iter=hash.begin();iter!=hash.end();iter++)
        {
            keyvalue kv;
            kv.key=iter->first;
            kv.value=iter->second;
            vec.push_back(kv);
        } 
        vector<keyvalue> vec1(vec.begin(),vec.begin()+k);
        for(int i=k/2-1;i>=0;i--)
        {
            heap(vec1,k,i);
        }
        for(int i=k;i<vec.size();i++)
        {
            if(vec[i].value>vec1[0].value)
            {
                vec1[0]=vec[i];
                heap(vec1,k,0);
            }
        }
        for(int i=k-1;i>0;i--)
        {
            swap(vec1[0],vec1[i]);
            heap(vec1,i,0);
        }
        for(int i=0;i<vec1.size();i++)
        {
            vec2.push_back(vec1[i].key);
        }
        return vec2;
    }
};
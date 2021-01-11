#include<string>
class Trie
{
    public:
        Trie()
        {
            isend=false;
            for(int i=0;i<26;i++)
            {
                next[i]=NULL;
            }
            cnt=0;
        }
        void insert(string word)
        {
            Trie * p=this;
            for(int i=0;i<word.size();i++)
            {
                if(p->next[word[i]-'a']==NULL)
                    p->next[word[i]-'a']=new Trie();
                p=p->next[word[i]-'a'];
                p->cnt++;
            }
            p->isend=true;
        }
    
        void remove(string word)
        {
            Trie * p=this;
            Trie * q=this;
            for(int i=0;i<word.size();i++)
            {
                if(p->next[word[i]-'a']==NULL)
                    return ;
                p=p->next[word[i]-'a'];
                p->cnt--;
            }
            if(p->cnt==0)
                p->isend=false;
        }
    
        bool search(string word)
        {
            Trie * p=this;
            for(int i=0;i<word.size();i++)
            {
                if(p->next[word[i]-'a']==NULL)
                    return false;
                p=p->next[word[i]-'a'];
            }
            return p->isend;
        }
        int prefixNumber(string pre)
        {
            Trie * p=this;
            for(int i=0;i<pre.size();i++)
            {
                if(p->next[pre[i]-'a']==NULL)
                    return 0;
                p=p->next[pre[i]-'a'];
            }
            return p->cnt;
        }
    private:
        bool isend;
        Trie * next[26];
        int cnt;
};
class Solution {
public:
    /**
     * 
     * @param operators string字符串vector<vector<>> the ops
     * @return string字符串vector
     */
    vector<string> trieU(vector<vector<string> >& operators) {
        // write code here
        vector<string> vec;
        int n=operators.size();
        if(n==0)
            return vec;
        Trie trie;
        for(int i=0;i<n;i++)
        {
            if(operators[i][0]=="1")
                trie.insert(operators[i][1]);
            else if(operators[i][0]=="2")
                trie.remove(operators[i][1]);
            else if(operators[i][0]=="3")
                vec.push_back(trie.search(operators[i][1])==true?"YES":"NO");
            else if(operators[i][0]=="4")
                vec.push_back(to_string(trie.prefixNumber(operators[i][1])));
        }
        return vec;
    }
};
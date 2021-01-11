class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        this->isend=false;
        
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie * p=this;
        for(int i=0;i<word.size();i++)
        {
            if(p->next[word[i]-'a']==NULL)
                p->next[word[i]-'a']=new Trie;
            p=p->next[word[i]-'a'];
        }
        p->isend=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie * p=this;
        for(int i=0;i<word.size();i++)
        {
            if(p->next[word[i]-'a']==NULL)
                return false;
            p=p->next[word[i]-'a'];
        }
        return p->isend;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie * p=this;
        for(int i=0;i<prefix.size();i++)
        {
            if(p->next[prefix[i]-'a']==NULL)
                return false;
            p=p->next[prefix[i]-'a'];
        }
        return true;
    }
    private:
    bool isend;
    Trie * next[26];
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
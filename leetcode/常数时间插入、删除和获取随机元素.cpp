class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash.count(val)==0)
        {

            hash[val]=vec.size();
            vec.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hash.count(val)>0)
        {
            int pos=hash[val];
            hash.erase(val);
            if(vec[pos]==vec[vec.size()-1])
            {
                vec.pop_back();
                return true;
            }
            swap(vec[pos],vec[vec.size()-1]);
            vec.pop_back();
            hash[vec[pos]]=pos;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand()%vec.size()];
    }
private:
    unordered_map<int,int> hash;
    vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
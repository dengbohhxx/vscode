/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    void parse(NestedInteger item)
    {
        if(item.isInteger())
        {
            vec.push_back(item.getInteger());
        }
        else
        {
            vector<NestedInteger> list1=item.getList();
            for(vector<NestedInteger>::iterator iter=list1.begin();iter!=list1.end();iter++)
            {
                parse(*iter);
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList)
     {
        for(vector<NestedInteger>::iterator iter=nestedList.begin();iter!=nestedList.end();iter++)
        {
            parse(*iter);
        }
    }
    int next() {
        return vec[idx++];
    }
    
    bool hasNext() {
        if(idx>=vec.size())
            return false;
        else
            return true;
    }
private:
    vector<int> vec;
    int idx=0;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
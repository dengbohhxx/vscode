#include <unordered_map>
class Node//双向链表的node
{
    public:
    int key,val;
    Node * pre;
    Node * next;
    Node(int k,int v)
    {
        this->key=k;
        this->val=v;
        pre=NULL;
        next=NULL;
    }
};
class Doublelist//双向链表
{
    public:
        Doublelist()
        {
            head=new Node(0,0);
            tail=new Node(0,0);
            head->next=tail;
            tail->pre=head;
            size=0;
        }
        void addlast(Node * x)//从tail添加
        {
            x->pre=tail->pre;
            x->next=tail;
            tail->pre->next=x;
            tail->pre=x;
            size=size+1;
        }
        void remove(Node * x)//移除节点
        {
            x->pre->next=x->next;
            x->next->pre=x->pre;
            size=size-1;
        }
        Node * removefirst()//从head移除节点
        {
            if(head->next==tail)
                return NULL;
            Node * first=head->next;
            remove(first);
            return first;
        }
        int size1()//大小
        {
            return size;
        }
    private:
        Node * head;
        Node * tail;
        int size;
};
class LRUcache
{
    public:
        LRUcache(int k)
        {
            cap=k;
            //hash=unordered_map();
            cache=new Doublelist();
        }
        void makerecently(int key)//将已经有的key对应的节点调整到tail前
        {
            Node * x=hash[key];
            cache->remove(x);
            cache->addlast(x);
        }
        void addrecently(int k,int v)//根据key value添加
        {
            Node * x =new Node(k,v);
            cache->addlast(x);
            hash[k]=x;
        }
        void deletekey(int key)//根据key移除节点
         {
            Node * x=hash[key];
            cache->remove(x);
            hash.erase(key);
        }
        void removelru()//移除LRU
        {
            Node * delnode=cache->removefirst();
            int delkey=delnode->key;
            hash.erase(delkey);
        }
        int get(int k)
        {
             if(hash.count(k)==0)
                 return -1;
             makerecently(k);
            return hash[k]->val;
        }
        void set(int k,int v)
        {
            if(hash.count(k)>0)
            {
                deletekey(k);
                addrecently(k,v);
                return;
            }
            if(cap==cache->size1())
                removelru();
            addrecently(k,v);
        }
    private:
        unordered_map<int,Node *> hash;
        Doublelist * cache;
        int cap;
};
class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        vector<int> vec;
        int size=operators.size();
        if(size==0)
            return vec;
        LRUcache lru=LRUcache(k);
        for(int i=0;i<size;i++)
        {
            if(operators[i][0]==1)
            {
                lru.set(operators[i][1],operators[i][2]);
            }
            else if(operators[i][0]==2)
            {
                vec.push_back(lru.get(operators[i][1]));
            }
        }
        return vec;
    }
};
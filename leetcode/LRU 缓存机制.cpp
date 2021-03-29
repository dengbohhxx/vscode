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
class LRUCache {
private:
        unordered_map<int,Node *> hash;//哈希表
        Doublelist * cache;//双向链表
        int cap;
public:
    LRUCache(int capacity)
     {
            cap=capacity;
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
        void removelru()//移除LRU,删除第一个节点
        {
            Node * delnode=cache->removefirst();
            int delkey=delnode->key;
            hash.erase(delkey);
        }
    
    
    int get(int key) {
        if(hash.count(key)==0)
                 return -1;
             makerecently(key);
            return hash[key]->val;
    }
    
    void put(int key, int value) {
        if(hash.count(key)>0)//如果已经有相同的key
            {
                deletekey(key);
                addrecently(key,value);
                return;
            }
            if(cap==cache->size1())//如果已经cache的大小已经等于cap，删除head的下一个节点
                removelru();
            addrecently(key,value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
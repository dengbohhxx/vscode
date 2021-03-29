class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        int size=min.size()+max.size();
        if(size%2==0)
        {
            int temp=num;
            if(!min.empty()&&num<min[0])
            {
                temp=min[0];
                min[0]=num;
                make_heap(min.begin(),min.end(),less<>());
            }
            max.push_back(temp);
            push_heap(max.begin(),max.end(),greater<>());
        }
        else
        {
            int temp=num;
            if(!max.empty()&&num>max[0])
            {
                temp=max[0];
                max[0]=num;
                make_heap(max.begin(),max.end(),greater<>());
            }
            min.push_back(temp);
            push_heap(min.begin(),min.end(),less<>());
        }
    }
    
    double findMedian() {
        int size=min.size()+max.size();
        double res=0;
        if(size%2==0)
        {
            res=(double)(min[0]+max[0])/2;
        }
        else
        {
            res=max[0];
        }
        return res;
    }
private:
vector<int> min;//小的那部分数字，大根堆less
vector<int> max;//大的那部分数字，小跟堆 greater
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
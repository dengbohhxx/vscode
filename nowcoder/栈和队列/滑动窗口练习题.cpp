/*
class SlideWindow {
public:
    vector<int> slide(vector<int> arr, int n, int w) {
        // write code here
        vector<int> res;
        if(n<w||w<1)
            return res;
        deque<int> deq;
        for(int i=0;i<w;i++)
        {
            while(!deq.empty()&&arr[i]>=arr[deq.back()])
                deq.pop_back();
            deq.push_back(i);
        }
        for(int i=w;i<n;i++)
        {
            res.push_back(arr[deq.front()]);
             while(!deq.empty()&&arr[i]>=arr[deq.back()])
                deq.pop_back();
            if(!deq.empty()&&deq.front()<=i-w)
                deq.pop_front();
             deq.push_back(i);
        }
        res.push_back(arr[deq.front()]); 
        return res;
    }
};
*/
class SlideWindow {
public:
    vector<int> slide(vector<int> arr, int n, int w) {
        // write code here
        vector<int> vec;
        if(w<1)//窗口小于1
            return vec;
        if(n<w)//窗口大于数组长度
        {
            vec.push_back(*max_element(arr.begin(),arr.end()));
            return vec;
        }
        deque<int> deq;
        for(int i=0;i<n;i++)
        {
            while(!deq.empty()&&arr[i]>=arr[deq.back()])
                deq.pop_back();
            deq.push_back(i);
            if(!deq.empty()&&deq.front()==i-w)//left过期
                deq.pop_front();
            if(i>=w-1)//vec纪录最大值
                vec.push_back(arr[deq.front()]);
        }
        return vec;
    }
};
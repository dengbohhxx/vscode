class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0)
            return 0;
        if(rotateArray.size()==1)
            return rotateArray[0];
        int left=0;
        int right=rotateArray.size()-1;
        int index=-1;
        if(rotateArray[left]<rotateArray[right])
            return rotateArray[0];
        while(rotateArray[left]>=rotateArray[right])
        {
            if(right-left==1)
            {
                index=right;
                break;
            }
            int mid=(left+right)/2;
            if(rotateArray[mid]>=rotateArray[left])
            {
                left=mid;
            }
            if(rotateArray[mid]<=rotateArray[right])
            {
                right=mid;
            }
            if(rotateArray[left]==rotateArray[left]&&rotateArray[mid]==rotateArray[left])
            {
                return *min_element(rotateArray.begin(),rotateArray.end());
            }
        }
        return rotateArray[index];
    }
};
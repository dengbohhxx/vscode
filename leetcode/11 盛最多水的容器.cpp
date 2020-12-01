class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int aera=0;
        while(i<j)
        {
            aera=height[i]<height[j]?max(height[i]*(j-i++),aera):max(height[j]*(j-- -i),aera);
        }
        return aera;
    }
};
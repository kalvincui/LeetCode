class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int start = 0;
        int end = height.size()-1;
        while (start < end){
            area = max(min(height[start], height[end]) * (end-start), area);
            if (height[start]>height[end]){
                end--;
            }else {
                start++;
            }
        }
        return area;
    }
};

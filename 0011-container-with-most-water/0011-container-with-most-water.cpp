class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int area = 0;
        int maxarea = 0;
        while (i != j) {
            if (height[i] <= height[j]) {
                area = (j - i) * height[i];
                i++;
            } else {
                area = (j - i) * height[j];
                j--;
            }
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};
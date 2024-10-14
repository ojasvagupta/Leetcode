class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long res=0;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        for(int i=0;i<k;i++)
        {
            res=res+pq.top();
            int x=pq.top();
            pq.pop();
            int y=ceil(x/3.0);
            pq.push(y);
            
        }
        return res;
    }
};
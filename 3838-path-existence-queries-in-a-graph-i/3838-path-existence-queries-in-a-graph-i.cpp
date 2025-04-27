class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> range(n);
        range[0] = 0;
        int start = 0;
        int end = 0;

        for(int i=1; i<nums.size(); i++){
            int diff = nums[i]-nums[i-1];
            if(diff > maxDiff){
                start = i;
            }

            range[i] = start;
        }

        vector<bool> ans(queries.size(), false);

        for(int i=0; i<queries.size(); i++){
            start = queries[i][0];
            end = queries[i][1];

            if(start > end) swap(start, end);

            if(start >= range[end]) ans[i] = true;
        }

        
        return ans;
    }
};
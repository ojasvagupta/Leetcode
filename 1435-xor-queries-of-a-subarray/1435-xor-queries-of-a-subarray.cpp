class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto a : queries)
        {
            int start=arr[a[0]];
            for(int i=a[0]+1 ; i<=a[1];i++)
            {
                start=start ^ arr[i];
            }
            res.push_back(start);
        }
        return res;
    }
};
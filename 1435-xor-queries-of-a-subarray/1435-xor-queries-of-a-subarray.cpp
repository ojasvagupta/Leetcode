class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        vector<int> pre(arr.size());
        pre[0]=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            pre[i]=pre[i-1] ^ arr[i];
        }
        for (auto a : queries) {
            if(a[0]==0)
            {
                res.push_back(pre[a[1]]);
            }
            else
            {
                int x=pre[a[1]] ^ pre[a[0]-1];
                res.push_back(x);
            }
        }
        return res;
    }
};
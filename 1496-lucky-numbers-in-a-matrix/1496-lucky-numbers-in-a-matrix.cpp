class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {

        vector<int> res;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<matrix.size();i++)
        {
            int temp=INT_MAX;
            for(int j=0;j<matrix[i].size();j++)
            {
                temp=min(temp,matrix[i][j]);
            }
            for(int j=0;j<matrix[i].size();j++)
            {
                if(temp==matrix[i][j])
                {
                    mp[temp]={i,j};
                }
            }
        }
        for(int i=0;i<matrix[0].size();i++)
        {
            int temp=INT_MIN;
            for(int j=0;j<matrix.size();j++)
            {
                temp=max(temp,matrix[j][i]);
            }
            if(mp.count(temp))
            {
                res.push_back(temp);
            }
        }
        return res;
    }
};
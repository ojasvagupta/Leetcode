class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>> v={{1}};
        if(n==1) return v;
        v.push_back({1,1});
        if(n==2) return v;
        for(int i=2;i<n;i++)
        {
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<v[i-1].size();j++)
            {
                temp.push_back(v[i-1][j-1]+v[i-1][j]);
            }
            temp.push_back(1);
            v.push_back(temp);
        }
        return v;
    }
};
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> v(rowSum.size(),vector<int>(colSum.size(),0));
        for(int i=0;i<rowSum.size();i++)
        {
            for(int j=0;j<colSum.size();j++)
            {
                int temp=min(rowSum[i],colSum[j]);
                v[i][j]=temp;
                rowSum[i]=rowSum[i]-temp;
                colSum[j]=colSum[j]-temp;
            }
        }
        return v;
        


    }
};
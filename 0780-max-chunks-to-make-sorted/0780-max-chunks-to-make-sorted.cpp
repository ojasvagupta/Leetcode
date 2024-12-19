class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max=arr[0];
        int res=0;
        for(int i=0;i<arr.size();i++)
        {
            if(max<arr[i])
            {
                max=arr[i];
            }
            if(max==i)
            {
                res++;
            }

        }
        return res;

        
    }
};
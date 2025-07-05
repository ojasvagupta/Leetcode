class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int res=-1;
        int count=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i-1]==arr[i])
            {
                count++;
            }
            else{
                if(count==arr[i-1])
                {
                    res=arr[i-1];
                }
                count=1;
            }
        }
        if(count==arr[arr.size()-1])
        {
            res=arr[arr.size()-1];
        }

        return res;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        if(arr.size()==1)
        {
            if(arr[0]%2!=0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        vector<int> prefix(arr.size());
        int sum=0;
        int count=0;
        int odd=0;
        int even=0;
        if(arr[0]%2!=0)
        {
            count++;
            odd++;
            sum=sum+arr[0];
        }
        else
        {
            sum=sum+arr[0];
            even++;
        }
        for(int i=1;i<arr.size();i++)
        {
            sum=sum+arr[i];
            if(sum%2!=0)
            {
                count=count+even+1;
                odd++;
            }
            else
            {
                count=count+odd;
                even++;
            }
            count=count%(1000000000+7);
        }
        
        return count%(1000000000+7);
        
    }
};
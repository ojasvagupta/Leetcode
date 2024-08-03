class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int a=0;
        for(int i=0;i<target.size();i++)
        {
            if(target[i]!=arr[i])
            {
                int check=0;
                for(int j=i+1;j<arr.size();j++)
                {
                    if(target[i]==arr[j])
                    {
                        check=1;
                        reverse(arr.begin()+i,arr.begin()+j+1);
                        break;
                    }
                }
                if(check==0)
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};
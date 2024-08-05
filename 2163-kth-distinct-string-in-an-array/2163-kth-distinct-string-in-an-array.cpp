class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<arr.size();i++)
        {
            if(mp.count(arr[i]))
            {
                mp[arr[i]][0]++;
            }
            else
            {
                mp[arr[i]].push_back(1);
                mp[arr[i]].push_back(i);
            }
        }
        vector<string> v;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            auto a=it->second;
            if(a[0]==1)
            {
                v.push_back(it->first);
            }
        }
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<v.size();j++)
            {
                if(arr[i]==v[j])
                {
                    count++;
                    break;
                }
            }
            if(count==k)
            {
                return arr[i];
            }
        }
        return "";
        
    }
};
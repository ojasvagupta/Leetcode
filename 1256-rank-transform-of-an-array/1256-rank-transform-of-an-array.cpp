class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mp;
        vector<int> v=arr;
        sort(v.begin(),v.end());
        int count=1;
        for(int i=0;i<v.size();i++)
        {
            if(!mp.count(v[i]))
            {
                mp[v[i]]=count;
                count++;
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};
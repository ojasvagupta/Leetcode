class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>> mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.count(s[i]))
            {
                mp[s[i]].second=i;
            }
            else
            {
                mp[s[i]].first=i;
                mp[s[i]].second=i;
            }
        }
        vector<pair<int,int>> v;
        for(auto [x,y] : mp)
        {
            v.push_back(y);
        }
        sort(v.begin(),v.end());
        int start=v[0].first;
        int end=v[0].second;
        vector<int> res;
        for(int i=1;i<v.size();i++)
        {
            if(v[i].first>end)
            {
                res.push_back(end-start+1);
                start=v[i].first;
                end=v[i].second;
            }
            else
            {
                start=min(start,v[i].first);
                end=max(end,v[i].second);
            }
            if(i==v.size()-1)
            {
                res.push_back(end-start+1);
            }
        }
        return res;
    }
};
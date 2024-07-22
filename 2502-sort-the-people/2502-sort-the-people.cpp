class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int ,string> mp;
        vector<string> v;
        for(int i=0;i<names.size();i++)
        {
            mp[heights[i]]=names[i];
        }
        sort(heights.begin(),heights.end());
        for(int i=heights.size()-1;i>=0;i--)
        {
            v.push_back(mp[heights[i]]);
        }
        return v;
    }
};
class Solution {
public:
void find(unordered_map<string, vector<pair<string,double>>> mp,double val,string a,string b,unordered_set<string> set,double& rval)
{
    if(b==a)
    {
        rval=val;
        return;
    }
    if(!set.count(a))
    {
        for(auto m : mp[a])
    {
        set.insert(a);
        find(mp,val*m.second,m.first,b,set,rval);
    }
    }
    

}
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> mp;
        vector<double> res;
        for (int i = 0; i < equations.size(); i++) {
            mp[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));

            mp[equations[i][1]].push_back(make_pair(equations[i][0], (1.0 / values[i])));
        }
        for (auto a : queries) {
            if (mp.count(a[0])) {
                if(a[0]==a[1])
                {
                    res.push_back(1);
                }
                else
                {
                    double rval=-1;
                    unordered_set<string> set;
                    find(mp,1,a[0],a[1],set,rval);
                    res.push_back(rval);
                }
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};
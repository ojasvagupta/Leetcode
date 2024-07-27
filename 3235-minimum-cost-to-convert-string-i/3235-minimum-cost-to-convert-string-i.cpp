class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char,set<pair<char,int>>> mp;
        for(int i=0;i<cost.size();i++)
        {
            char x=original[i];
            char y=changed[i];
            int z=cost[i];
            if(mp.count(x)){
                bool a=false;
            for(auto it=mp[x].begin();it!=mp[x].end();it++)
            {
                if(it->first==y)
                {
                    a=true;
                    if(it->second>z){
                    mp[x].erase(it);
                    mp[x].insert(make_pair(y,z));
                    }
                    
                }
                
                
            }
            if(a==false)
            {
                mp[x].insert(make_pair(y,z));
            }
            }
            else
            {
                mp[x].insert(make_pair(y,z));
            }

        }
        unordered_map<char,int> up;
        for(int i=0;i<original.size();i++)
        {
            up[original[i]]=INT_MAX;
        }
        for(int i=0;i<original.size();i++)
        {
            up[changed[i]]=INT_MAX;
        }
        unordered_map<char,unordered_map<char,int>> res;
        for(auto it=up.begin();it!=up.end();it++)
        {
            char source1=it->first;
        set<pair<char,int>> st;
        st.insert(make_pair(source1,0));
        unordered_map<char,int> ap;
        ap=up;
        ap[source1]=0;
        while(!st.empty())
        {
            auto top=*(st.begin());
            int dist=top.second;
            char node=top.first;
            st.erase(st.begin());
            for(auto a : mp[node])
            {
                if(dist + a.second < ap[a.first])
                {
                    auto record=st.find(make_pair(a.first,ap[a.first]));
                    if(record!=st.end())
                    {
                        st.erase(record);
                    }
                    ap[a.first]=dist + a.second;
                    st.insert(make_pair(a.first,ap[a.first]));
                }
            }
        
        }
        res[it->first]=ap;
        }
        long long sum=0;
        for(int i=0;i<source.size();i++)
        {
            if(source[i]!=target[i])
            {
                if(!res.count(source[i]))
                {
                    return -1;
                }
                for(auto it=res[source[i]].begin();it!=res[source[i]].end();it++)
                {
                    if(it->first==target[i] && it->second==INT_MAX)
                    {
                        return -1;
                    }
                    if(it->first==target[i])
                    {
                        sum=sum+it->second;
                    }
                }
            }
        }
        return sum;




        
    }
};
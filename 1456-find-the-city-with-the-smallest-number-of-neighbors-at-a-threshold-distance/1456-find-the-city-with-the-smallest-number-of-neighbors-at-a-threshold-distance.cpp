class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,list<pair<int,int>>> adj;
        
        vector<int> v(n,0);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int x=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back(make_pair(x,w));
            adj[x].push_back(make_pair(u,w));
        }
        vector<int> dist(n);
        for(int source=0;source<n;source++)
        {
        for(int i=0;i<n;i++)
        {
            dist[i]=INT_MAX;
        }
        set<pair<int,int>> st;
        dist[source]=0;
        st.insert(make_pair(0,source));
        while(!st.empty())
        {
            auto top=*(st.begin());
            int nodeDistance=top.first;
            int topNode=top.second;
            st.erase(st.begin());
            for(auto neighbour : adj[topNode])
            {
                if(nodeDistance + neighbour.second < dist[neighbour.first])
                {
                    auto record =st.find(make_pair(dist[neighbour.first],neighbour.first));
                    if(record!=st.end())
                    {
                        st.erase(record);
                    }
                    dist[neighbour.first]=nodeDistance + neighbour.second;
                    st.insert(make_pair(dist[neighbour.first],neighbour.first));
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(dist[i]<=distanceThreshold)
            {
                count++;
            }
        }
        v[source]=count;
        }
        int res=INT_MAX;
        int out=-1;
        for(int i=0;i<n;i++)
        {
            res=min(res,v[i]);
            if(res==v[i])
            {
                out=i;
            }
        }
        return out;

  }
};
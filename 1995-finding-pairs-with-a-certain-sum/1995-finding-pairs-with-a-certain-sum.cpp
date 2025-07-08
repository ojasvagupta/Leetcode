class FindSumPairs {
public:
vector<int> a;
vector<int> b;
unordered_map<int,int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        int x=max(nums1.size(),nums2.size());
        int n=nums1.size();
        int m=nums2.size();
        
        for(int i=0;i<x;i++)
        {
            if(i<n)
            {
                a.push_back(nums1[i]);
            }
            if(i<m)
            {
                if(mp.count(nums2[i]))
                {
                    mp[nums2[i]]++;
                }
                else
                {
                    mp[nums2[i]]=1;
                }
                b.push_back(nums2[i]);
            }
        }
    }
    
    void add(int index, int val) {
        if(mp.count(b[index]))
        {
            if(mp[b[index]]>0)
            {
                mp[b[index]]--;
            }
        }
        b[index]=b[index]+val;
        if(mp.count(b[index]))
        {
                mp[b[index]]++;
        }
        else
        {
            mp[b[index]]=1;
        }
    }
    
    int count(int tot) {
        int res=0;
         for(int i=0;i<a.size();i++)
         {
            if(mp.count(tot-a[i]) && mp[tot-a[i]]>0)
            {
                res=res+mp[tot-a[i]];
            }
         }
         return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> t;
    RandomizedSet() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        t.push_back(val);
        mp[val] = t.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int v = t.back();
        t.pop_back();
        t[mp[val]] = v;
        mp[v] = mp[val];
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return t[rand()%t.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
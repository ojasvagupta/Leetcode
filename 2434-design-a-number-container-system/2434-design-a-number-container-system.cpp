class NumberContainers {
public:
    unordered_map<int, int> mp1;
    unordered_map<int, set<int>> mp2;
    NumberContainers() {}

    void change(int index, int number) {
        if (mp1.count(index)) {
            if (mp2[mp1[index]].count(index)) {
                mp2[mp1[index]].erase(index);
            }
            mp1[index] = number;
            mp2[number].insert(index);

        } else {
            mp1[index] = number;
            mp2[number].insert(index);
        }
    }

    int find(int number) {
        if (mp2.count(number) && !mp2[number].empty()) {
            return *mp2[number].begin(); // Corrected access
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
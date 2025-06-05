class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n = status.size();
        int res = 0;
        queue<int> q;
        vector<bool> hasBox(n, false), opened(n, false);

        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box] == 1) {
                q.push(box);
                opened[box] = true;
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            res += candies[curr];
            
            for (int k : keys[curr]) {
                if (status[k] == 0) {
                    status[k] = 1;
                    if (hasBox[k] && !opened[k]) {
                        q.push(k);
                        opened[k] = true;
                    }
                }
            }

            for (int box : containedBoxes[curr]) {
                hasBox[box] = true;
                if (status[box] == 1 && !opened[box]) {
                    q.push(box);
                    opened[box] = true;
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> v(1001, 0);
        int res = 0;
        for (int i = 0; i < answers.size(); i++) {
            if (v[answers[i]] == 0) {
                v[answers[i]] = 1;
            } else if (v[answers[i]] > 0 && v[answers[i]] < answers[i] + 1) {
                v[answers[i]]++;
            } else {
                if (v[answers[i]] >= answers[i] + 1) {
                    res = res + v[answers[i]];
                    v[answers[i]] = 1;
                }
            }
        }
        for(int i=0;i<1001;i++)
        {
            if(v[i]!=0)
            {
                res=res+i+1;
            }
        }
        return res;
    }
};
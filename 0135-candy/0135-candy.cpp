class Solution {
public:
    int candy(vector<int>& ratings) {
        int i=0;
        int res=0;
        vector<int> val(ratings.size(),1);
        while(i+1<ratings.size())
        {
            if(ratings[i]<ratings[i+1])
            {
                while(i+1<ratings.size() && ratings[i]<ratings[i+1])
                {
                    val[i+1]=val[i]+1;
                    i++;
                }
            }
            else
            {
                i++;
            }
        }
        i=ratings.size()-1;
        while(i-1>=0)
        {
            if(ratings[i]<ratings[i-1])
            {
                while( i-1>=0 && ratings[i]<ratings[i-1])
                {
                    val[i-1]=max(val[i-1],val[i]+1);
                    i--;
                }
            }
            else
            {
                i--;
            }
        }
        for(int i=0;i<ratings.size();i++)
        {
            res=res+val[i];
        }
        return res;
    }
};
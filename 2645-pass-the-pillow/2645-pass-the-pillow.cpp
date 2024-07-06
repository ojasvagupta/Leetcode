class Solution {
public:
    int passThePillow(int n, int time) {
        if(n>time)
        {
            return time+1;

        }
        if(n==time)
        {
            return time-1;
        }
        if(n<time)
        {
            if((time/(n-1))%2==0)
            {
                return time%(n-1)+1;
            }

        }

        return n-(time%(n-1));
        
    }
};
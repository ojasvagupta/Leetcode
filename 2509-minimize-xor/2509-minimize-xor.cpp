class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x=num2;
        int n=0;
        while(x>0)
        {
            if(x%2==1)
            {
                n++;
            }
            x=x/2;
        }
        int y=num1;
        int m=0;
        while(y>0)
        {
            if(y%2==1)
            {
                m++;
            }
            y=y/2;
        }
        if(n==m)
        {
            return num1;
        }
        if(n>m)
        {
            int diff=n-m;
            int k=0;
            while(diff>0)
            {
                if(!(num1 & (1<<k)))
                {
                    num1=num1 | (1<<k);
                    diff--;
                }
                k++;
            }
        }
        if(n<m)
        {
            int diff=m-n;
            int k=0;
            while(diff>0)
            {
                if(num1 & (1<<k))
                {
                    num1=num1>>k+1;
                    num1=num1<<k+1;
                    diff--;
                }
                k++;
            }
        }
        return num1;
    }
};
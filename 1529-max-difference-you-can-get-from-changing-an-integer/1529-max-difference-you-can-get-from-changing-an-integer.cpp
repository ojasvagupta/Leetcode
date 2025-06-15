class Solution {
public:
    int maxDiff(int num) {
        vector<int> a;
        vector<int> b;
        vector<int> v;
        int x=num;
        int count=1;
        while(x>0)
        {
            count=count*10;
            x=x/10;
        }
        count=count/10;
        x=num;
        while(count>0)
        {
            int n=x/count;
            x=x%count;
            count=count/10;
            v.push_back(n);
        }
        a=v;
        b=v;
        bool check=true;
        bool ch_eck=true;
        for(int i=0;i<v.size();i++)
        {
            if(a[i]<9 && check)
            {
                check=false;
                int k=a[i];
                for(int m=i;m<a.size();m++)
                {
                    if(a[m]==k)
                    {
                        a[m]=9;
                    }
                }

            }
            if(b[i]>0 && ch_eck && i>0 && b[0]!=b[i])
            {
                ch_eck=false;
                int k=b[i];
                for(int m=i;m<a.size();m++)
                {
                    if(b[m]==k)
                    {
                        b[m]=0;
                    }
                }
            }
            if(b[i]>1 && ch_eck)
            {
                ch_eck=false;
                int k=b[i];
                for(int m=i;m<a.size();m++)
                {
                    if(b[m]==k)
                    {
                        b[m]=1;
                    }
                }
            }
            
        }
        count=1;
        int res=0;
        x=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            x=x+a[i]*count;
            res=res+b[i]*count;
            count=count*10;
        }
        return x-res;
    }
};
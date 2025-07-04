class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        string word = "a";
        long long count = 1;
        int val=0;
        int n=0;
        vector<char> alpha = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                              'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                              's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        for (int i = 0; i < operations.size(); i++) {
            count = count * 2;
            n++;
            if(count>=k)
            {
                break;
            }
        }
        for (int i = n-1; i >= 0; i--) {
            if (operations[i] == 1) {
                count=count/2;
                if(k>count)
                {
                    k=k-count;
                    val--;
                }
                
            }
            else
            {
                count=count/2;
                if(k>count)
                {
                    k=k-count;
                }
                
                
            }
            
        }
        val=-val%26;
        return alpha[val];
        
    }
};
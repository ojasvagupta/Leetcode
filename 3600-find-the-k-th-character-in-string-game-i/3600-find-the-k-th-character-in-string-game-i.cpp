class Solution {
public:
    char kthCharacter(int k) {
        vector<char> alpha={'b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a'};
        string word="a";
        while(word.size()<k)
        {
            string temp="";
            for(int i=0;i<word.size();i++)
            {
                temp=temp+alpha[word[i]-'a'];
            }
            word=word+temp;
        }

        return word[k-1];
    }
};
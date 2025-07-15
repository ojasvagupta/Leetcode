class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3)
            return false;
        bool check = true;
        int vowels = 0;
        int con = 0;
        for (int i = 0; i < word.size(); i++) {
            if ((word[i] - 'a' <= 'z' - 'a' && word[i] - 'a' >= 0) ||
                (word[i] - 'A' >= 0 && word[i] - 'A' <= 'Z' - 'A') ||
                (word[i] - '0' >= 0 && word[i] - '0' <= '9' - '0')) {
                check = true;
            } else {
                return false;
            }
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                 word[i] == 'o' || word[i] == 'u' || word[i] == 'A' ||
                 word[i] == 'E' || word[i] == 'I' || word[i] == 'O' ||
                 word[i] == 'U'
                ) {
                vowels++;
            } else {
                if(!(word[i] - '0' >= 0 && word[i] - '0' <= '9' - '0'))
                {
                    con++;
                }
                
            }
        }
        if (vowels > 0 && con > 0 && check) {
            return true;
        }

        return false;
    }
};
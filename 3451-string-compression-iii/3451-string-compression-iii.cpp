class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 1;

        for (int i = 0; i < word.size(); i++) {
            if (i < word.size() - 1 && word[i] == word[i + 1]) {
                count++;
            } else {
                // Handle cases where the count is greater than 9
                while (count > 0) {
                    int to_add = min(count, 9);  // Get the maximum chunk we can add (9 or less)
                    comp += to_string(to_add) + word[i];  // Append count and character
                    count -= to_add;  // Reduce the count by the chunk added
                }
                count = 1;  // Reset count for the next character sequence
            }
        }

        return comp;
    }
};

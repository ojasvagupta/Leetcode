class Node {
public:
    unordered_map<string, Node*> mp;  // map to store children nodes
    bool end;  // to mark the end of a folder path

    Node() { end = false; }
};

class Solution {
public:
    // Function to insert a folder path into the trie
    void insert(string s, Node* top) {
        int i = 0;
        string st = "";
        while (i < s.size()) {
            if (s[i] == '/' || i == s.size() - 1) {
                // If we hit a '/' or reach the end, add the current folder segment
                if (s[i] != '/') {
                    st += s[i];  // Add the last character if it's not '/'
                }
                if (!st.empty()) {
                    if (top->mp.find(st) == top->mp.end()) {
                        top->mp[st] = new Node();  // Create new node if not found
                    }
                    top = top->mp[st];  // Move to the next node
                    st = "";  // Reset folder segment
                }
            } else {
                st += s[i];  // Build folder segment
            }
            i++;
        }
        top->end = true;  // Mark the end of a folder
    }

    // Function to traverse the trie and collect valid folder paths
    void res(Node* top, string temp, vector<string>& v) {
        if (top->end) {
            v.push_back(temp);
            return;  // If it's the end of a valid folder, add it to the result
        }

        // Continue traversal even if this node marks the end, because we could
        // still have valid sibling paths
        for (auto it : top->mp) {
            res(it.second, temp + "/" + it.first, v);  // Recursively add characters to build the path
        }
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        Node* top = new Node();

        // Insert all folder paths into the trie
        for (int i = 0; i < folder.size(); i++) {
            insert(folder[i], top);
        }

        vector<string> ans;
        // Collect valid folder paths (without subfolders)
        res(top, "", ans);
        return ans;
    }
};

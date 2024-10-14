class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        unordered_set<string> visited;  // To track visited genes
        queue<pair<string, int>> q;  // BFS queue, stores (currentGene, mutationCount)
        
        // If the endGene is not in the bank, return -1 (it's unreachable)
        if (bankSet.count(endGene) == 0) {
            return -1;
        }

        // Start the BFS from startGene
        q.push({startGene, 0});
        visited.insert(startGene);

        vector<char> genes = {'A', 'C', 'G', 'T'};  // Possible gene mutations

        // Perform BFS
        while (!q.empty()) {
            auto [currentGene, mutationCount] = q.front();
            q.pop();

            // If we've reached the endGene, return the mutation count
            if (currentGene == endGene) {
                return mutationCount;
            }

            // Try mutating each position in the current gene
            for (int i = 0; i < 8; i++) {
                char originalChar = currentGene[i];
                
                // Try all possible gene mutations at this position
                for (char g : genes) {
                    if (g == originalChar) continue;  // Skip if it's the same character
                    
                    currentGene[i] = g;  // Mutate the gene

                    // Check if the mutated gene is in the bank and hasn't been visited
                    if (bankSet.count(currentGene) && !visited.count(currentGene)) {
                        visited.insert(currentGene);  // Mark it as visited
                        q.push({currentGene, mutationCount + 1});  // Enqueue the mutated gene
                    }
                }

                // Restore the original gene after trying all mutations
                currentGene[i] = originalChar;
            }
        }

        // If we exit the loop without finding the endGene, return -1
        return -1;
    }
};

class Solution {
public:
    bool prepare(unordered_map<string, vector<string>>& recipeMap,
                 unordered_set<string>& supply,
                 const string& item,
                 unordered_set<string>& vis) 
    {
        if (supply.count(item)) return true;  // Already available
        if (!recipeMap.count(item)) return false;  // No recipe for this item
        if (vis.count(item)) return false;  // Cycle detected

        vis.insert(item);

        for (const auto& ingredient : recipeMap[item]) {
            if (!supply.count(ingredient)) {
                if (!prepare(recipeMap, supply, ingredient, vis)) {
                    vis.erase(item);
                    return false;  // Ingredient can't be made
                }
            }
        }

        vis.erase(item);
        supply.insert(item);  // Mark item as now available
        return true;
    }

    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) 
    {
        unordered_map<string, vector<string>> recipeMap;
        unordered_set<string> supply(supplies.begin(), supplies.end());
        vector<string> result;

        for (int i = 0; i < recipes.size(); ++i) {
            recipeMap[recipes[i]] = ingredients[i];
        }

        for (const auto& recipe : recipes) {
            unordered_set<string> vis;
            if (prepare(recipeMap, supply, recipe, vis)) {
                result.push_back(recipe);
            }
        }

        return result;
    }
};

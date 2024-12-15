class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Priority queue to maximize the gain in average ratio
        auto compare = [](const pair<double, int>& a, const pair<double, int>& b) {
            return a.first < b.first; // Max-heap based on the gain
        };
        priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(compare)> pq(compare);

        // Initialize the priority queue with the initial gain for each class
        for (int i = 0; i < classes.size(); i++) {
            double pass = classes[i][0];
            double total = classes[i][1];
            double currentGain = (pass + 1) / (total + 1) - (pass / total);
            pq.push({currentGain, i});
        }

        // Distribute the extra students
        while (extraStudents--) {
            auto [gain, idx] = pq.top();
            pq.pop();
            classes[idx][0]++; // Add a student to the passing count
            classes[idx][1]++; // Add a student to the total count
            double pass = classes[idx][0];
            double total = classes[idx][1];
            double newGain = (pass + 1) / (total + 1) - (pass / total);
            pq.push({newGain, idx});
        }

        // Calculate the final average ratio
        double totalRatio = 0.0;
        for (const auto& cls : classes) {
            totalRatio += (double)cls[0] / cls[1];
        }
        return totalRatio / classes.size();
    }
};

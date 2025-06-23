class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;

        for (const char chr: tasks) map[chr]++;

        priority_queue<int> pq;

        for (auto [k, v] : map) pq.push(v);

        int time = 0;

        while (!pq.empty()) {
            vector<int> newTasks;
            int cycle = n+1;
            int executedTasks = 0;
            while (cycle > 0 && !pq.empty()) {
                if (pq.top() > 1) {
                    newTasks.emplace_back(pq.top()-1);
                }

                pq.pop();
                executedTasks++;
                cycle--;
            }

            for (int i: newTasks) {
                pq.push(i);
            }

            time += (pq.empty() ? executedTasks : n+1);
        }

        return time;
    }
};
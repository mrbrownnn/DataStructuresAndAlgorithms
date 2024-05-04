

#include <iostream>
#include <vector>
#include <algorithm>

int findMaxActions(std::vector<int>& startTimes, std::vector<int>& endTimes) {
    int n = startTimes.size();
    std::vector<std::pair<int, int>> actions;

    for (int i = 0; i < n; i++) {
        actions.push_back({startTimes[i], endTimes[i]});
    }

    std::sort(actions.begin(), actions.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });

    int count = 1;
    int endTime = actions[0].second;

    for (int i = 1; i < n; i++) {
        if (actions[i].first >= endTime) {
            count++;
            endTime = actions[i].second;
        }
    }

    return count;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> startTimes(n);
        std::vector<int> endTimes(n);

        for (int i = 0; i < n; i++) {
            std::cin >> startTimes[i];
        }

        for (int i = 0; i < n; i++) {
            std::cin >> endTimes[i];
        }

        int maxActions = findMaxActions(startTimes, endTimes);
        std::cout << maxActions << std::endl;
    }

    return 0;
}
#include<iostream>
#include<vector>

using namespace std;
/*
the problem was to find the number of boys each boy can see.
eg: for array of heights: 1 2 1 4 2
*/

// no.
std::vector<int> countVisibleBoys(const std::vector<int>& boys) {
    int n = boys.size();
    std::vector<int> result(n, 0);

    for (int i = 0; i < n; ++i) {
        int visibleCount = 0;
        for (int j = i + 1; j < n; ++j) {
            if (boys[j] <= boys[i]) {
                ++visibleCount;
            }
        }
        result[i] = (visibleCount == 0) ? -1 : visibleCount;
    }

    return result;
}

int main() {
    std::vector<int> boys = {1, 2, 1, 4, 2};

    std::vector<int> visibleCounts = countVisibleBoys(boys);

    std::cout << "Result: ";
    for (int count : visibleCounts) {
        std::cout << count << " ";
    }
    std::cout << std::endl;

    return 0;
}

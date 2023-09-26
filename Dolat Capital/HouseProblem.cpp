#include <iostream>
#include <vector>
#include <algorithm>

int maxHouses = 4; // Number of houses to choose
int maxDistance;   // Maximum distance constraint

std::vector<int> chosenHouses;
std::vector<int> resultHouses;

void chooseHouses(const std::vector<int>& houses, int startIndex, int currentHouses) {
    if (currentHouses == maxHouses) {
        // Check if the chosen houses satisfy the distance constraint
        bool valid = true;
        for (int i = 1; i < maxHouses; ++i) {
            if (chosenHouses[i] - chosenHouses[i - 1] > maxDistance) {
                valid = false;
                break;
            }
        }

        if (valid) {
            resultHouses = chosenHouses;
        }
        return;
    }

    for (int i = startIndex; i < houses.size(); ++i) {
        chosenHouses.push_back(houses[i]);
        chooseHouses(houses, i + 1, currentHouses + 1);
        chosenHouses.pop_back();
    }
}

int main() {
    int x = 20;
    maxDistance = x;

    std::vector<int> housePositions = {15, 23, 28, 31, 32, 60};
    // std::sort(housePositions.begin(), housePositions.end());

    chooseHouses(housePositions, 0, 0);

    std::cout << "Chosen houses: ";
    for (int house : resultHouses) {
        std::cout << house << " ";
    }
    std::cout << std::endl;

    return 0;
}

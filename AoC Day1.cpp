#include <iostream>
#include <fstream>
#include <vector>



//Part One Solution
int partOne() {
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        std::cerr << "Unable to open file";
        exit(1);
    }
    int depth = 0;
    int nextDepth = 0;
    int count = 0;
    while (!inFile.eof()) {
        if (depth < nextDepth) {
            count += 1;
        }
        depth = nextDepth;
        inFile >> nextDepth;

    }
    inFile.close();
    return count;
}

//Part Two Solution, very ugly
int partTwo() {
    std::vector<int> values;
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        std::cerr << "Unable to open file";
        exit(1);
    }
    int currVal = 0;
    while (!inFile.eof()) {
        inFile >> currVal;
        values.push_back(currVal);
    }
    inFile.close();
    int sum = 0;
    int nextSum = 0;
    int total = 0;
    bool done = false;
    for (int i = 0; i < values.size(); i++) {
        if (done) {
            break;
        }
        if (sum < nextSum) {
            total += 1;
        }
        sum = nextSum;
        nextSum = 0;
        for (int j = i; j < i + 3; j++) {
            if ((j + 1) >= values.size()) {
                std::cout << "Not enough values";
                done = true;
                break;
            }
            else {
                nextSum += values[j];
            }
        }
    }
    return total;
}


int main()
{
    std::cout << partOne() << "\n";
    std::cout << partTwo();
    return 0;
}
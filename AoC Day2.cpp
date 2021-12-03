#include <vector>
#include <fstream>
#include <iostream>
#include <string>



int partOne() {
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        std::cerr << "Unable to open file";
        exit(1);
    }
    std::string command;
    std::string fward = "forward";
    std::string upward = "up";
    std::string downward = "down";
    int forwardSum = 0;
    int downSum = 0;
    while (std::getline (inFile, command)) {
        if (command.find(fward) != std::string::npos) {
            int f = command[command.size() - 1] - '0';
            forwardSum += f;
        }
        if (command.find(upward) != std::string::npos) {
            int u = command[command.size() - 1] - '0';
            downSum -= u;
        }
        if (command.find(downward) != std::string::npos) {
            int d = command[command.size() - 1] - '0';
            downSum += d;
        }
    }
    inFile.close();
    return forwardSum * downSum;
}

int partTwo() {
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        std::cerr << "Unable to open file";
        exit(1);
    }
    std::string command;
    std::string fward = "forward";
    std::string upward = "up";
    std::string downward = "down";
    int aim = 0;
    int depth = 0;
    int horizontal = 0;
    while (std::getline(inFile, command)) {
        if (command.find(fward) != std::string::npos) {
            int f = command[command.size() - 1] - '0';
            horizontal += f;
            if (aim > 0 || aim < 0) {
                depth += (aim * f);
            }
        }
        if (command.find(upward) != std::string::npos) {
            int u = command[command.size() - 1] - '0';
            aim -= u;
        }
        if (command.find(downward) != std::string::npos) {
            int d = command[command.size() - 1] - '0';
            aim += d;
        }
    }
    inFile.close();
    return depth * horizontal;
}

int main()
{
    std::cout <<partOne() << "\n";
    std::cout << partTwo();
    return 0;
}

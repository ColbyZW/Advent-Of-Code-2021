#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::string> readings;

void readFile() {
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        std::cerr << "Unable to open the file.";
        exit(1);
    }
    std::string reading;
    while (!inFile.eof()) {
        inFile >> reading;
        readings.push_back(reading);
    }
    inFile.close();
}

std::string partOne() {
    std::string gamma = "";
    int count = 0;
    while (count < readings[0].size()) {
        int oneCount = 0;
        int zeroCount = 0;
        for (int i = 0; i < readings.size(); i++) {
            char binary = readings[i][count];
            if (binary == '1') {
                oneCount += 1;
            }
            else if (binary == '0') {
                zeroCount += 1;
            }
        }
        count += 1;
        if (zeroCount > oneCount) {
            gamma += '0';
        }
        else {
            gamma += '1';
        }
    }
    return gamma;
}

std::string epsilon(std::string gamma) {
    std::string epsilon;
    for (int i = 0; i < gamma.size(); i++) {
        if (gamma[i] == '1') {
            epsilon += '0';
        }
        else {
            epsilon += '1';
        }
    }
    return epsilon;
}

int binaryConv(std::string binary) {
    int decimal = 0;
    int power = 0;
    for (int i = binary.size() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            int val = pow(2, power);
            decimal += val;
        }
        power += 1;
    }
    return decimal;
}


int main()
{
    readFile();
    std::string gamma = partOne();
    std::string epsil = epsilon(gamma);
    std::cout << gamma << " - " << binaryConv(gamma) << "\n";
    std::cout << epsil << " - " << binaryConv(epsil) << "\n";
    std::cout << "Total Power Consumption = " << binaryConv(gamma) * binaryConv(epsil) << "\n";
    return 0;
}


#include<fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


using namespace std;


int lineNumWithMostDigits(std::string filename) {
    std::ifstream inputfile(filename);
    int maxDigits = 0;
    int lineNumber = 0;
    if (inputfile.is_open()) {
        std::string line;
        int lineCounter = 0;
        while (std::getline(inputfile, line)) {
                int digitCounter = 0;
                for(std::string::size_type i = 0; i < line.size(); ++i) {
                    if (isdigit(line[i])) {
                        digitCounter++;
                    }
                }
                if(digitCounter >= maxDigits) {
                    maxDigits = digitCounter;
                    lineNumber = lineCounter;
                }
                lineCounter++;
        }
        inputfile.close();
    }
    return lineNumber;
}

int main() {
    int result = lineNumWithMostDigits("input.txt");

    cout << result << endl;

    return 0;

}

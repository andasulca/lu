#include <iostream>

using namespace std;

string processDigits(string input) {
    string output = "";
    for(int i = 0; i < input.length() - 1; i++) {
        if (!(isspace(input[i + 1]) && isdigit(input[i]))) {
            output = output + input[i];
        }
    }
    return output;
}

int main()
{
    string line;
    std::cout << "Enter something: " << std::endl;
    std::getline(std::cin, line);
    string outputLine = processDigits(line);
    std::cout << outputLine;
    return 0;
}



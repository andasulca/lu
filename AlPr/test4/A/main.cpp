#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{

    std::string line;
    std::cout << "Enter something: " << std::endl;
    std::getline(std::cin, line);
    int maxL = 0;
    string current = "";
    bool stringStarted = false;

    for(int i = 0; i < line.length(); i ++) {
        if (isspace(line[i])) {
            if (current.length() > maxL) maxL = current.length();
            current = "";
            stringStarted = true;
        } else if (stringStarted) {
            if (isdigit(line[i]))
                current = current + line[i];
            else
                stringStarted = false;
        }

    }
    if (current.length() > maxL) maxL = current.length();
    std:cout << maxL;
    return 0;
}

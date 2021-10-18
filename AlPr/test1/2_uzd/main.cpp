#include <iostream>

using namespace std;

int main()
{
char input[1000];
char result[1000];
int opened = 0;
int maxOpened = 0;

cin>>input;
int length = sizeof(input)/sizeof(char);
    for (int z = 0; z < length; z++) {
       if (input[z] != '.') {
            if (input[z] == '(') {
                opened++;
                if (opened > maxOpened)
                        maxOpened = opened;
            }
            if (input[z] == ')') {
                opened--;
            }
       } else break;
    }
    cout << maxOpened << endl;
    return 0;
}

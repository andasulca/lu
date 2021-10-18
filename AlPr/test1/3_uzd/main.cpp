#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
char input[1000];
char result[1000];

cin>>input;
int length = sizeof(input)/sizeof(char);
    for (int z = 0; z < length; z++) {
       if (input[z] != '.') {
            if (isdigit(input[z])) {
                char temp[2];
                temp[0] = input[z];
                std::strcat(result, temp);
            }
       } else break;
    }

int resultInt = atoi(result);
cout<< "answer is "<< resultInt << " and " << resultInt*resultInt << endl;

return 0;
}

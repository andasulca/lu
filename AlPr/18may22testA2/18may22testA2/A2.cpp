#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
    char n[10];
    int a=0;
    int maxlength = 0;
    string outputString;

    fstream fb("input.txt",ios::in|ios::binary);
    fb.read(n,10);
    fb.read((char*)&a,4);
    while (fb) {
        if (strlen(n) > maxlength) {
            outputString = std::to_string(a);
            maxlength = strlen(n);
        } else if (strlen(n) == maxlength) {
            outputString = outputString + "," + std::to_string(a);
        }
        fb.read(n,10);
        fb.read((char*)&a,4);
    }
    cout << outputString << endl;
    fb.close();
}

#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {

    int maxlength = 0;

	char inputSubject[20];

	cout << "input Subject: ";
	cin  >> inputSubject;

	char surname[20];
	char firstname[20];
	char subject1[20];
	int grade1;
	char subject2[20];
	int grade2;
	char subject3[20];
	int grade3;

    fstream fb("input.txt",ios::in|ios::binary);

    while (fb) {

        fb.read(surname,20);
        fb.read(firstname,20);
        fb.read(subject1,20);
        fb.read((char*)&grade1,4);
        fb.read(subject2,20);
        fb.read((char*)&grade2,4);
        fb.read(subject1,20);
        fb.read((char*)&grade3,4);

		if (inputSubject == subject1)
			cout << surname <<" "<< firstname << " " << grade1 << endl;
		if (inputSubject == subject2)
			cout << surname <<" "<< firstname << " " << grade2 << endl;
		if (inputSubject == subject3)
			cout << surname <<" "<< firstname << " " << grade3 << endl;
    }
    fb.close();
}

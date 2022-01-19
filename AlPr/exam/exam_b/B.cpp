#include <iostream>

using namespace std;

void ouputLargestNumberOrError(int n) {
   if (n < 100) {
     cout << "The number "<< n <<" is too small." << endl;
     return;
   }

   int removedFirst = 0;
   int removedLast = 0;
   int remainder;

   int temp = n;
   int position = 1;

    do {
    remainder = temp % 10;
    removedFirst = removedFirst + remainder * position;
    temp = temp / 10;
    position = position * 10;
   } while (temp >= 100);

   removedLast = n / 100;

   if (removedFirst > removedLast)
        cout << "Such a number is " << removedFirst << "." << endl;
   else if (removedFirst < removedLast)
        cout << "Such a number is " << removedLast << "." << endl;
   else if (removedFirst == removedLast)
        cout << "Both are equal: " << removedLast << "." << endl;
}

int main()
{
    int n;
    std::cout << "Enter natural n: " << std::endl;
    cin >> n;

    ouputLargestNumberOrError(n);

    return 0;
}



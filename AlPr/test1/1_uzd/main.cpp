#include <iostream>

using namespace std;

int main()
{
    int arr[10];
    bool isSequence = true;
    for (int z = 0; z < 10; z++) {
        cin >> arr[z];
    }
    for (int z = 1; z < 10; z++) {
       if (arr[z] < arr[z-1]) {
            isSequence = false;
            break;
       }
    }
    if (isSequence)
        cout << "YES" << endl;
     else
        cout << "NO" << endl;
    return 0;
}

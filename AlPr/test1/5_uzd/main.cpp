#include <iostream>

using namespace std;

int main()
{
    int arr[20];
    int starting;

    for (int z = 0; z < 20; z++) {
        cin >> arr[z];
    }
    starting = arr[0];

    if (starting > 0) {
        for (int z = 0; z < 20; z++) {
           if (arr[z] <= 0) {
                cout << "Starts with " << z <<" positive numbers" << endl;
                break;
           }
        }
    } else if (starting < 0) {
        for (int z = 0; z < 20; z++) {
           if (arr[z] >= 0) {
                cout << "Starts with " << z <<" negative numbers" << endl;
                break;
           }
        }
    } else if (starting == 0) {
        for (int z = 0; z < 20; z++) {
           if (arr[z] != 0) {
                cout << "Starts with " << z <<" zeros" << endl;
                break;
           }
        }
    }

    return 0;
}

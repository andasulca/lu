#include <iostream>

using namespace std;

float exampleB (int one, int two, int& three, int& four) {
    float avg = (float)((one + two + three) / 3);

    int max = one;
    if (max < two) max = two;
    if (max < three) max = three;
    four = max;

    max = one;
    if (max < two) max = two;
    three = max;

    return avg;
}

int main()
{
    int three;
    int four;
    three = 7;
    float result = exampleB(4,2,three,four);
    cout << three << endl;
    cout << four << endl;
    printf ("%f\n", result);
   // cout << result << endl;
   // std::cout << std::setprecision(10) << result << std::endl;
    return 0;
}




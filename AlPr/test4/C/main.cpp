#include <iostream>
#include <triangle.h>

using namespace std;

int main()
{
    // m(a,b,c) - a,b,c - lengths of sides
    // no side should be longer than remaining two,
    // if so all sides are initialized as 1
    triangle m(4,5,6);
    m.print(); // 4 5 6 15 (a,b,c,perimeter)
    // set(a,b,c) - a,b,c - lengths of sides
    // no side should be longer than remaining two,
    // if so all sides are initialized as 1
    m.set(1,2,4);
    m.print(); // 1 1 1 3
    m.set(5,6,8);
    m.print(); // 5 6 8 19
    cout<<m.perimeter()<<endl; // 19

    return 0;
}

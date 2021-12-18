#include "triangle.h"
#include <iostream>

triangle::triangle(int a, int b, int c)
{
    this->set(a,b,c);
}

void triangle::set(int a, int b, int c)
{
    if (a + b < c || c + b < a || a + c < b) {
        this->sideA = 1;
        this->sideB = 1;
        this->sideC = 1;
    } else {
        this->sideA = a;
        this->sideB = b;
        this->sideC = c;
    }
}

void triangle::print()
{
    std::cout << this->sideA  << " " << this->sideB << " " << this->sideC << " " << this->perimeter() << std::endl;
}

int triangle::perimeter()
{
   return this->sideA + this->sideB + this->sideC;
}


triangle::~triangle()
{
    //dtor
}

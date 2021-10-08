/***************

Anda Šulca, as21271

A5. Given natural number n and k, representing a digit 0..9. Create and print another number m, which is obtained by removing all digits k from n. (E.g., n=12025, k=2 -> m=105). Splitting into digits should be performed numerically.

***************/

#include <iostream>
#include <iomanip>      // std::setw


int main() {
    int n;
    int k;
    bool repeat = true;
    char repeatChar[2];
    bool validInput = false;

    while(repeat) {

     //loop until valid n is entered
     do {
        validInput = true;
         std::cout << "Enter number: " << std::endl;
         //Check for a valid input - 'is number entered?'.
         if(!(std::cin >> n))
         {
             std::cout << "Error: Invalid input detected" << std::endl;
             //clears error flag on cin
             std::cin.clear();
             //skips all 'enter' characters left in cin stream
             while( std::cin.get() != '\n' );
             validInput = false;
             continue;
         }
         //checks for a natural number
         if (n <= 0) {
            std::cout << "Error: Not a natural number entered" << std::endl;
            validInput = false;
         }
     }
     while (!validInput);

     //loop until valid k is entered
     do {
        validInput = true;
         std::cout << "Enter digit to remove: " << std::endl;
         //Check for a valid input - 'is number entered?'.
         if(!(std::cin >> k))
         {
             std::cout << "Error: Invalid input detected" << std::endl;
             //clears error flag on cin
             std::cin.clear();
             //skips all 'enter' characters left in cin stream
             while( std::cin.get() != '\n' );
             validInput = false;
             continue;
         }
         //checks for a valid digit
         if (k < 0 || k > 9) {
            std::cout << "Error: Entered value is not a digit" << std::endl;
            validInput = false;
         }
     } while (!validInput);

    int temp = n;
    int power = 1;
    int m = 0;

        while (temp != 0) {
            // Find the rightmost digit in the number
            int digit = temp % 10;

            //checks if the found digit should be removed
            if (digit != k) {
                //adds digit to m
                m += digit * power;
                //increases power to be used for next iteration of the loop
                power*=10;
            }
            //remove the rightmost digit from number using division
            temp/=10;
        }

        std::cout << "Removing " << k << " from " << n << std::endl;
        //Output m unless all the digits are removed
        if (m != 0) {
            std::cout << "Result: " << m << std::endl;
        } else {
            std::cout << "Result: All digits have been removed" << std::endl;
        }

        std::cout << std::endl << "Enter 1 to continue. Enter any other character to exit." << std::endl;
        std::cin >> std::setw(3) >> repeatChar;
        repeat = (std::string(repeatChar) == "1");
        std::cout << std::endl;
    };

    return 0;
}

/************
 *
 * Input number |Input digit| Desired response Result            | Actual response
 * -------------+-----------+------------------------------------+----------------------------------
 * 0            |           |Error: Not a natural number entered |
 * -888         |           |Error: Not a natural number entered |
 * ABC          |           |Error: Invalid input detected       |
 * 2147483699   |           |Error: Invalid input detected       |
 * 1            | abcd      |Error: Invalid input detected       |
 * 1            | -3        |Error: Entered value is not a digit |
 * 1            | 99        |Error: Entered value is not a digit |
 * 11122233     | 2         |Result: 111333                      |
 * 2147483647   | 3         |Result: 214748647                   |
 * 100          | 0         |Result: 1                           |
 * 00001        | 9         |Result: 1                           |
 * 10000        | 1         |Result: All digits have been removed|
 * ***********/
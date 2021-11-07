/***************

Anda Sulca, as21271

B4: Calculate whether the given natural number contains repeating digits. Print all such digits and the number of occurrences of each of them. Splitting into digits should be carried out numerically.

***************/

#include <iostream>
#include <iomanip>      // std::setw


int main() {
    int n;

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

    //array elements correspond to digits 0 through 9
    int masivs[10] = {0,0,0,0,0,0,0,0,0,0};

        while (n != 0) {
            // Find the rightmost digit in the number
            int digit = n % 10;
            //increase the array element which stands for the according digit
            masivs[digit] = masivs[digit] + 1;
            //remove the rightmost digit from number using division
            n/=10;
        }


        for (int i = 0; i < 10; i++) {
            //checks if digit is reapeating
            if (masivs[i] > 1)    {
                //output results
                std::cout << "Repeating n`gumber: " << i <<"; Occurences:"<< masivs[i] << ";" << std::endl;
            }
            else if (masivs[i] < 1){
                std::cout << "No repeating number" << std::endl;
            }
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
 * Input number | Desired response Result                                                                              | Actual response
 * -------------+------------------------------------------------------------------------------------------------------+----------------------------------
 * 0            |Error: Not a natural number entered                                                                   |
 * -888         |Error: Not a natural number entered                                                                   |
 * ABC          |Error: Invalid input detected                                                                         |
 * 2147483699   |Error: Invalid input detected                                                                         |
 * 1            |-                                                                                                     |
 * 11122233     |Repeating number: 1; Occurences:3;Repeating number: 2; Occurences:3;Repeating number: 3; Occurences:2;|
 * 2147483647   |Repeating number: 4; Occurences:3;Repeating number: 7; Occurences:2;                                  |
 * 100          |Repeating number: 0; Occurences:2;                                                                    |
 * 00001        |-                                                                                                     |
 * 10000        |Repeating number: 0; Occurences:4;                                                                    |
 * ***********/

# /***************

# Anda Šulca, as21271

# A5. Given natural number n and k, representing a digit 0..9. Create and print another number m, which is obtained by removing all digits k from n. (E.g., n=12025, k=2 -> m=105). Splitting into digits should be performed numerically.

# ***************/


while True:
    k = None
    #loop until valid n is entered
    try:
        #Check for a valid input - 'is number entered?'
        n = int(input("Enter number: "))
    except ValueError:
        print("Error: Invalid input detected")
        continue
    #checks for a natural number
    if n <= 0:
        print("Error: Not a natural number entered")
        continue

    #loop until valid k is entered
    while True:
        try:
            #Check for a valid input - 'is number entered?'
            k = int(input("Enter digit to remove: "))
        except ValueError:
            print("Error: Invalid input detected")
            continue
        #checks for a valid digit
        if k < 0 or k > 9:
            print("Error: Entered value is not a digit")
        else:
            break
    
    temp = abs(n)
    power = 0
    m = 0

    while temp != 0:
        #Find the rightmost digit in the number
        number = temp % 10
        #checks if the found digit should be removed
        if (number != k):
            #adds digit to m
            m += number * 10**power
            #increases power to be used for next iteration of the loop
            power += 1
        #remove the rightmost digit from number using division
        temp //= 10

    if n < 0:
        m *= -1

    #Output m unless all the digits are removed
    if m == 0:
        print("Result: All digits have been removed")
    else:
        print("Removing ",k," from ",n,"\nResult: ", m)

    ok = input("Enter 1 to continue. Enter any other character to exit. ")

    if ok != '1':
        break

# /************
#  *
#  * Input number |Input digit| Desired response Result            | Actual response
#  * -------------+-----------+------------------------------------+----------------------------------
#  * 0            |           |Error: Not a natural number entered |
#  * -888         |           |Error: Not a natural number entered |
#  * ABC          |           |Error: Invalid input detected       |
#  * 2147483699   |           |Error: Invalid input detected       |
#  * 1            | abcd      |Error: Invalid input detected       |
#  * 1            | -3        |Error: Entered value is not a digit |
#  * 1            | 99        |Error: Entered value is not a digit |
#  * 11122233     | 2         |Result: 111333                      |
#  * 2147483647   | 3         |Result: 214748647                   |
#  * 100          | 0         |Result: 1                           |
#  * 00001        | 9         |Result: 1                           |
#  * 10000        | 1         |Result: All digits have been removed|
#  * ***********/
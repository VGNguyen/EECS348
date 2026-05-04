#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double extractNumeric(const char* str);

int main() {
    //Make string that is able to hold 200 characters
    char input[200];
    //Keep getting numbers until the user types END
    while (1) {
        printf("Enter a string (or 'END' to quit): ");
        scanf(" %[^\n]", input);

        if (strcmp(input, "END") == 0) {
            printf("Program Terminated\n");
            break;
        }
        //Call the function to find the number
        double result = extractNumeric(input);
        //If invalid number print invalid result, else print the number
        if (result == -999999.99) {
            printf("Invalid input: no valid floating-point number found\n");
        }else{
            //Print with 4 decimal places
            printf("Extracted number: %.4f\n", result);
        }
    }

    return 0;
}

double extractNumeric(const char* str) {
    int i = 0;
    //Go through until the end of the string
    while (str[i] != '\0') {

        //Holder variables for exponents and numbers
        int sign = 1, expSign = 1;
        double num = 0.0, frac = 0.0, divisor = 1.0;
        int exponent = 0;

        int hasDigit = 0, hasDecimal = 0, hasExp = 0;

        int j = i;

        // Handle sign
        if (str[j] == '+' || str[j] == '-') {
            if(str[j] == '-'){
                sign = -1;
            }else{
                sign = 1;
            }
            j++;
        }

        //Find the starting digit/decimal point
        if (!isdigit(str[j]) && str[j] != '.') {
            i++;
            continue;
        }

        // Integer + fraction parsing
        while (isdigit(str[j]) || str[j] == '.') {
            //The string has two '.' and that means it is invalid
            if (str[j] == '.') {

                if (hasDecimal){
                    return -999999.99;
                }else{
                    hasDecimal = 1;
                }
                
            } else {
                hasDigit = 1;
                if (!hasDecimal) {
                    num = num * 10 + (str[j] - '0');
                } else {
                    divisor *= 10;
                    frac += (str[j] - '0') / divisor;
                }
            }
            j++;
        }

        if (!hasDigit) return -999999.99;

        num += frac;

        //Exponent handling
        if (str[j] == 'e' || str[j] == 'E') {
            hasExp = 1;
            j++;

            if (str[j] == '+' || str[j] == '-') {
                expSign = (str[j] == '-') ? -1 : 1;
                j++;
            }

            if (!isdigit(str[j])) return -999999.99;

            while (isdigit(str[j])) {
                exponent = exponent * 10 + (str[j] - '0');
                j++;
            }
        }

        //Make sure there is no digits or decimal past the found number
        if (isdigit(str[j]) || str[j] == '.') {
            return -999999.99;
        }

        //Computer final value
        double result = sign * num;
        //Apply the exponent
        if (hasExp) {
            double powVal = pow(10, expSign * exponent);
            result *= powVal;

            if (!isfinite(result)) return -999999.99;
        }

        return result;
    }

    return -999999.99;
}
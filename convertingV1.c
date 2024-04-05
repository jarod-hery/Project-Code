#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // For LONG_MIN, LONG_MAX
#include <errno.h> // For errno (used for error reporting)
#define BUFFER_SIZE 80

void converting(void)
{
    printf("*** Start of Converting Strings to int Demo ***\n");
    char    intString[BUFFER_SIZE];
    long int intNumber; // Use long int to handle larger range
    char* endptr;
    do {
        printf("Type an int numeric string (q - to quit):\n");
        fgets(intString, BUFFER_SIZE, stdin);

        // Remove the newline character from the input
        intString[strlen(intString) - 1] = '\0';

        // Check if the input string is empty (only contains newline character)
        if (strlen(intString) == 0) 
        {
            // Skip the rest of the loop iteration and prompt for input again
            continue; 
        }

        if (strcmp(intString, "q") != 0) 
        {
            // Reset errno before the call to ensure that any previous error is cleared
            errno = 0; 
            
            // Use strtol to handle overflow
            //Convert the inputed string to an integer
            intNumber = strtol(intString, &endptr, 10); 

            if (intString[0] == '-' && endptr == intString + 1 && *endptr == '\0') 
            {
                // If the string consists only of '-' and nothing else
                printf("Converted number is %ld\n", intNumber);
            }

            //Check for errors or if there is an overflow during the conversion
            else if (*endptr != '\0' || (intNumber == LONG_MIN && errno == ERANGE) || (intNumber == LONG_MAX && errno == ERANGE)) 
            {
                printf("Error: Input is not a valid integer or exceeds the range of long int.\n");
            }
            else 
            {
                printf("Converted number is %ld\n", intNumber);
            }
        }
    } while (strcmp(intString, "q") != 0); //Continue loop until the user enter 'q'
    printf("*** End of Converting Strings to int Demo ***\n\n");

}

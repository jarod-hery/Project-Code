#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 80 //whitebox testing
#define NUM_INPUT_SIZE 10
#include "fundamentals.h"



void clr(char* ptr)
{
	//This checks for the excess input in the buffer that the fgets didn't read
	if (strchr(ptr, '\n') == NULL)
	{
		while (getchar() != '\n')
		{
			;
		}
	}

}
void fundamentals(void)
{
	/* Version 1 */
	//--:::::::  Variables] 
	char buffer1[BUFFER_SIZE+2];
	char tmpbuffer1[BUFFER_SIZE+2];
	char numInput[NUM_INPUT_SIZE];
	size_t position;

	//------>> Added Variables for Counter and Flag 
	int flagExit = 1, ctr = 0, flagChar = 0, spceCtr = 0, spceFlag = 0;


//::::::: MAIN PROGRAM START 
	printf("*** Start of Indexing Strings Demo ***\n");


//------------[] Main loop
	do
	{

		flagExit = 1; spceFlag = 0;

//--------------->>> STRING Input
		do
		{
			spceCtr = 0;
			printf("Type not empty string (q - to quit):\n");
			fgets(tmpbuffer1, BUFFER_SIZE+2, stdin); // Get the String from User and Add 2 to the buffer size to accomodate exactly 80 characters
				
			clr(tmpbuffer1);//Buffer dumper

			if (tmpbuffer1[0] != '\n')
				{
					tmpbuffer1[strlen(tmpbuffer1) - 1] = '\0';
					flagExit = 0;
					while (spceFlag == 0) // Validate the first character of String if it's a space
					{
						if (tmpbuffer1[spceCtr] == ' ') // Count Spaces that comes first in string input
						{
								spceCtr++; //Variables to be use in transftering the value
						}
						else
						{
								spceFlag = 1; //Flag to exit while loop
						}
					}
					
					for (ctr = spceCtr; tmpbuffer1[ctr] != '\0';ctr++) // To exclude the spaces in front of the first String in tmpbuffer1(user Input)
						{
							buffer1[ctr - spceCtr] = tmpbuffer1[ctr]; // And transfer the value to buffer1 variable
						}

						buffer1[strlen(tmpbuffer1)] = '\0'; // Setting a Null Terminator at the end of buffer1 variable
			}
			else
			{
						printf("String empty please input a string.\n\n");
			}
		} while (flagExit != 0);



//-------------->>> POSITION Locating FUNCTION


		if (strcmp(buffer1, "q") != 0) // Check Input for Possible Exit Input
		{
			flagExit = 1;
			do
			{
				flagChar = 1; flagExit = 1;

				printf("Type the character position within the string:\n");
				fgets(numInput, NUM_INPUT_SIZE+2, stdin); //get the position from the user, and Add 2 accomodate exactly 10 characters 
				clr(numInput);// Buffer Dumper

				numInput[strlen(numInput) - 1] = '\0'; //set null terminator on numInput variable
				
				
				for (ctr = 0;ctr < strlen(numInput) && flagChar != 0;ctr++) //Flag to check for non Positive, non Numeric Input
				{
					flagChar = isdigit(numInput[ctr]); //Function that flag a non Numeric Character
				}
				position = atoi(numInput); //function that converts strings into a numeric value
				if (flagChar != 0 && position > 0) // Validate the Input if Numeric and Positive
				{
					
					if (position >= (strlen(buffer1)+1)) //Check if position inputted go out of bound in higher range
					{
						position = strlen(buffer1) - 1; //SET to max String length
						printf("Too big.. Position reduce to max. available\n");
					}
					else
					{
						position = atoi(numInput) - 1; //Fix:Adjust the position value to output Correctly
					}

					flagExit = 0;
					printf("The character found at %d position is \'%c\'\n", (int)position + 1, buffer1[position]);// fix the proper value for the Position
				}
				else
				{
					printf("Invalid Input Please Input only numeric and Positive Number\n"); 
				}
			 } while(flagExit != 0);
		}
		
	} while (strcmp(buffer1, "q") != 0);
	printf("*** End of Indexing Strings Demo ***\n\n");





	/* Version 2 */
	//>> insert here


	/* Version 3 */
	//>> insert here



}





int main(void)
{
	fundamentals();

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 300


#include "Tokenizing.h"


// Entry point to the application
int main(void) {
	// Sub function call to the Tokening module
	tokenizing();
}

// Tokenizing: Break user's input strings into tokens.
// E.g	Input:	The quick brown fox jumps over the lazy dog.
//		Output:	Words #1 is 'The'
//				Words #2 is 'quick'
//				Words #3 is 'brown'
//				Words #4 is 'fox'
//				Words #5 is 'jumps'
//				Words #6 is 'over'
//				Words #7 is 'the'
//				Words #8 is 'lazy'
//				Words #9 is 'dog.'
void tokenizing(void) {

	// Diplay welcom message
	printf("*** Start of Tokenizing Words Demo  ***\n");

	// Variables declarations
	char words[BUFFER_SIZE];
	char* nextWord = NULL;
	int wordsCounter;

	// Do while construct: Code block to keep user on performinng
	//	tokenizing demo in the application. This loop ends
	//	once user pressed the charact 'q' on the keyword therefore quitting the application.
	do {
		// Display program instruction
		printf("Type a few words separated by space (q - to quit):\n");

		// Read line of text and assign to the variable words with buffer size of BUFFER_SIZE 300
		fgets(words, BUFFER_SIZE, stdin);
		//words[strlen(words) - 1] - '\0';
		// Statement to remove the NULL string ternmination.
		words[strlen(words) - 1] = '\0';
		//	else, the application perform the tokinization
		if (strcmp(words, "q") != 0) {

			// Get token values using the built in function strtok to get the splitted words from an input string using " " (space delimiter) 
			nextWord = strtok(words, " ");
			wordsCounter = 1;

			// Perform while construct to get each word (token) from the the splitted words
			while (nextWord)
			{
				//Print each token to the command line including the position of the words in ascending order
				printf("Words #%d is \'%s\'\n", wordsCounter++, nextWord);
				//Set next word value to by getting the succeding tokens of the splitted words  (space delimiter) 
				nextWord = strtok(NULL, " ");
			}
		}
	} while (strcmp(words, "q") != 0);

	// End of program display message
	printf("*** End of Tokenizing Words Demo ***\n\n");
}
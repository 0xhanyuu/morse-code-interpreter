#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Edit these limits in order to handle larger sizes of inputs and outputs.

#define INPUT_SIZE 2048
#define OUTPUT_SIZE 1364

// The output has been deliberately made 2/3rds the size of the output for the reason that:

/* The maximum information possibly stored would be a morse code sequence that contains the least -
 * number of characters possible, and that being any character that takes a single dot or dash.
 *
 * Morse code sequences have to be delimited in order to be parsed correctly, and the most -
 * characters that can be stored, using the least space possible, is half of the input size.
 * e.g. ". ." - Input size of 3.
 *      "ee" - Output size of 2. 
 */

/*
Can be implemented for more direct indexing of characters.

typedef enum morse_index
{
	A = 0, B, C, D, E,
	F, G, H, I, J,
	K, L, M, N, O,
	P, Q, R, S, T,
	U, V, W, X, Y, Z
}
morse_index;
*/

const char * morse_tokens[] =
{
	".-", "-...", "-.-.", "-..",
	".", "..-.", "--.", "....",
	"..", ".---", "-.-", ".-..",
	"--", "-.", "---", ".--.",
	"--.-", ".-.", "...", "-",
	"..-", "...-", ".--", "-..-",
	"-.--", "--.."
};

void interpreter(char * input, char * output)
{
	// A zero-instantiated (for sanity) buffer in order to copy the data to output.
	char output_temp[OUTPUT_SIZE] = {0};
	// An iterator to properly store the output characters consecutively.
	int output_string_iterator = 0;

	// Tokenise the input through the usage of space delimiters.
	char * tokenised_input = strtok(input, " ");

	while ( tokenised_input != NULL ) 
	{
		// Default to '?' for unparsable characters.
		char decoded_character = '?';
		
		for ( int i = 0; i < 26; i++ )
		{
			if ( strcmp(tokenised_input, "/") == 0 )
			{
				decoded_character = ' ';
				break;
			}

			// If there is a match between the input token and a morse sequence token,
			// set the decoded character, and break from the loop.
			if ( strcmp(tokenised_input, morse_tokens[i]) == 0 )
			{
				decoded_character = i + 97;
				// Alternatively, this statement can be used in order to -
				// make all of the characters uppercase.
				// decoded_character = i + 65;
				break;
			}
		}

		// Set the decoded character to the output character,
		// and increment the iterator to move to the next.
		output_temp[output_string_iterator] = decoded_character;
		output_string_iterator++;
		//Move to the next token.
		tokenised_input = strtok(NULL, " ");
	}

	// Return the output string.
	memcpy(output, output_temp, 32);
}

int main(void)
{
	char input[INPUT_SIZE];
	// Will only take as many bytes as INPUT_SIZE.
	// Refer to notes at the top to increase the size of the input if needed.
	fgets(input, INPUT_SIZE, stdin);

	// Remove trailing newline from the input, produced by fgets().
	input[strcspn(input, "\n")] = 0;

	char output[OUTPUT_SIZE];
	interpreter(input, output);

	printf("%s\n", output);

	return 0;
}

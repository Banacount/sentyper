#include "helpers.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
 * Tasks:
 *  
 *
 * Promises:
 *
 *  - [Game mode update] Infinite mode.
 *	- Refactor if needed.
 *
 * */

int main (int args_count, char * args[]) 
{
	// Print the arguments for some bullshit.
	/*
	for (int i = 1; i < args_count; ++i)
	{
		printf("%s\n", args[i]);
	}
	*/

	// Hehe (will add later fasho)
	if (args_count >= 2) {
		if (strncmp("-i", args[1], 2) == 0) 
			printf("Still work in progress.. for now hehe\n");
	} 

	double start_sec, end_sec, start_nanosec, end_nanosec;

	// Get sentence
	char sentence[500];
	int sentence_count = randomSentence(sentence, sizeof(sentence));
	printf("[ ENTER TO START (WARNING: MISTAKES MAY RESULT IN NEGATIVE WPM) ]");

	// Throw away input and clear the line
	int throw_away;
	while ((throw_away = getchar()) != '\n' && throw_away != EOF);
	printf("\033[A\33[2K\r"); // clear the line

	// Start time
	start_sec = currentSecondsTimeInDouble();
	start_nanosec = currentNanosecondsTimeInDouble();

	printf("\033[0;32m"); // change: green text
	printf("| %s\n> ", sentence);
	printf("\033[0;33m"); // change: yellow text
	int key, check_loop = 0, wrongs = 0;

	// Check the characters (if right)
	while (1) {
		key = getchar();
		if (check_loop == 0) printf("] ");;
		printf("\033[0m"); // change: default text

		if (
			(char)key == '\n' ||
			check_loop >= sentence_count
		) 
			break;

		char sentenceLetter = sentence[check_loop];

		if ((char)key == sentenceLetter)
		{
			printf("%c", sentenceLetter);
		}
		else 
		{
			printf("_");
			wrongs++;
		}

		check_loop++;
	}

	printf("\n");

	wrongs += sentence_count - check_loop;
	end_sec = currentSecondsTimeInDouble();
	end_nanosec = currentNanosecondsTimeInDouble();

	double secs = (end_sec - start_sec);
	double nanosecs = (end_nanosec - start_nanosec);
	double elapsed = secs + nanosecs * 1e-9;
	double wpm = (((double)sentence_count / 5) - wrongs) / (elapsed / 60);

	printf("\033[0;33m"); // change: yellow text

	// Show result info
	printf("\nWPM(standard): %.2f | Elapsed(sec): %.2f | Mistakes: %d\n", 
			wpm, elapsed, wrongs);

	return 0;
}

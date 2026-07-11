#include "helpers.h"
#include <time.h>
#include <stdio.h>
#include <unistd.h>

/*
 * Tasks:
 *
 * - Refactor later if you can lmao.
 *
 * Promises:
 *
 * - [Game mode update] Infinite mode.
 *
 * */

int main () 
{
	struct timespec start, end;

	// Get sentence
	char sentence[500];
	int sentence_count = randomSentence(sentence, sizeof(sentence));
	printf("[ ENTER TO START (WARNING: MISTAKES MAY RESULT IN NEGATIVE WPM) ]");

	// Throw away input and clear the line
	int throw_away;
	while ((throw_away = getchar()) != '\n' && throw_away != EOF);
	printf("\033[A\33[2K\r");

	// Start time
	clock_gettime(CLOCK_MONOTONIC, &start);

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
	clock_gettime(CLOCK_MONOTONIC, &end);

	double secs = (end.tv_sec - start.tv_sec);
	double nanosecs = (end.tv_nsec - start.tv_nsec);
	double elapsed = secs + nanosecs * 1e-9;
	double wpm = (((double)sentence_count / 5) - wrongs) / (elapsed / 60);

	printf("\033[0;33m"); // change: yellow text
	printf("\nWPM(standard): %.2f | Elapsed(sec): %.2f | Mistakes: %d\n", 
			wpm, elapsed, wrongs);

	return 0;
}

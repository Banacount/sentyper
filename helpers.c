#include "helpers.h"
#include "config.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>



int randomRangeInt (int min, int max)
{
	// Generate seed
	srand(time(NULL));
	int ran_num = (rand() % (max - min + 1)) + min;

	return ran_num;
}

int randomSentence (char* buff, size_t buff_size)
{
	int rand_num = randomRangeInt(MIN_SENTENCE_COUNT, MAX_SENTENCE_COUNT);

	strncpy(
		buff, 
		sentences[rand_num], 
		buff_size-1
	);
	buff[buff_size-1] = '\0';

	return (int)strlen(sentences[rand_num]);
}

double currentSecondsTimeInDouble () 
{
	struct timespec current;
	clock_gettime(CLOCK_MONOTONIC, &current);
	return current.tv_sec;
}
double currentNanosecondsTimeInDouble ()
{
	struct timespec current;
	clock_gettime(CLOCK_MONOTONIC, &current);
	return current.tv_nsec;
}


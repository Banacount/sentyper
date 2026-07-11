#include "helpers.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SENTENCE_COUNT 0
#define MAX_SENTENCE_COUNT 7

char sentences[][500] = {
	"Hello world. This is the classic programming line, is it good?",
	"I don't really care! not my problem. For real, not my problem though.",
	"Two people are better off than one, for they can help each other succeed.",
	"Likewise, two people lying close together can keep each other warm.",
	"The greatest high is the day you were born and the rest is suffering.",
	"I needed a friend, Gave my heart for complacency. Love-esque adjacency.",
	"Give a man a fire and he's warm for the day.",
	"But set fire to him and he's warm for the rest of his life."
};

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

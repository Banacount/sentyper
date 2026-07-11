#include "helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char sentences[][500] = {
	"Hello world.",
	"I don't really care! not my problem.",
	"Two people are better off than one, for they can help each other succeed.",
	"Likewise, two people lying close together can keep each other warm.",
	"The greatest high is the day you were born and the rest is suffering."
};

int randomRangeInt (int min, int max)
{
	// Generate seed
	srand(time(NULL));
	int ran_num = (rand() % (max - min + 1)) + min;

	return ran_num;
}
//char* buff, size_t buff_size
int randomSentence (char* buff, size_t buff_size)
{
	int rand_num = randomRangeInt(0, 4);

	strncpy(
		buff, 
		sentences[rand_num], 
		buff_size-1
	);
	buff[buff_size-1] = '\0';

	return (int)strlen(sentences[rand_num]);
}

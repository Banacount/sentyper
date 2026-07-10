#include "helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char sentences[][500] = {
	"Hello world.",
	"Nggas talking shit.",
	"What in the sigma.",
	"This shit is fuking lame.",
	"I don't really care! not my problem.",
};

int randomRangeInt (int min, int max)
{
	// Generate seed
	srand(time(NULL));
	int ran_num = (rand() % (max - min + 1)) + min;

	return ran_num;
}
//char* buff, size_t buff_size
void randomSentence (char* buff, size_t buff_size)
{
	int rand_num = randomRangeInt(0, 4);
	strncpy(buff, sentences[rand_num], buff_size-1);
	buff[buff_size-1] = '\0';
}

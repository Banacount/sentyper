#include "helpers.h"
#include <stdio.h>

int main () 
{
	printf("Random number: %d\n", randomRangeInt(10, 20));

	char sentence[500];
	randomSentence(sentence, sizeof(sentence));
	printf("Some random ass sentence: %s\n", sentence);
	return 0;
}

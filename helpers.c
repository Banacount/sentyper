#include <stdlib.h>
#include <time.h>

int randomRangeInt (int min, int max)
{
	// Generate seed
	srand(time(NULL));
	int ran_num = (rand() % (max - min + 1)) + min;

	return ran_num;
}

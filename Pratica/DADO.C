#include "DADO.H"

int* jogaDados(int *d)
{
	time_t t;
	srand((unsigned) time(&t));

	d[0] = (rand() % 6) + 1;
	d[1] = (rand() % 6) + 1;

	if(d[0] == d[1])
	{
		d[2] = d[0];
		d[3] = d[0];
	}

	return d;
}


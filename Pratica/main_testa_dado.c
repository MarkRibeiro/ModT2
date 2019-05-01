#include"dado.h"

int main ()
{
	int d[4] = {0, 0, 0, 0};
	int i;

	jogaDados(d);

	for(i=0; d[i]!=0 && i!=4; i++)
	{
		printf("Dado %d: %d\n", i+1, d[i]);
	}
	
	return 0;
}
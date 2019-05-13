#include "DadosPontos.h"

int main()
{
	int val = 0;
	
	criaDadosPontos();
	
	dobraValor(1);
	
	printf("Valor do mult: %d\n", dobraValor(2));

	//printf("Valor do mult: %d\n", dobraValor(1));	
	
	lerValorDadosPontos(&val);
	
	printf("Valor do mult: %d\n", val);

	return 0;
}
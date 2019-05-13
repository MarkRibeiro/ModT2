#include "DadosPontos.h"

int main()
{
	DadosPontos *dp;

	dp = criaDadosPontos();

	dobraValor(1, dp);

	printf("Valor do mult: %d\n", lerValorDadosPontos(dp));

	return 0;
}
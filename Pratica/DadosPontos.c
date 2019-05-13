#include "DadosPontos.h"

struct dadosPontos {

	//ID do ultimo jogador (1 ou 2) que requisitou a dobra dos pontos
	int ultimo_jogador;

	//Valor atual do DadosPontos
	int mult;

	//Pontuacao dos jogadores
	int pontuacaoJogador1;
	int pontuacaoJogador2;

};

DadosPontos* criaDadosPontos() 
{
	DadosPontos *dp = (DadosPontos*)malloc(sizeof(DadosPontos));
	
	//Primeira 'dobrada' pode ser feita por qualquer jogador entao ultimo_jogador inicializa com 0
	dp->ultimo_jogador = 0;

	//Multiplicador incializa com 1
	dp->mult = 1;

	//Pontuacao de ambos jogadores incializa com 0
	dp->pontuacaoJogador1 = 0;
	dp->pontuacaoJogador2 = 0;
	
	return dp;
}

int dobraValor(int jogador, DadosPontos *dp)
{
	//Verifica se ID do jogador é valido
	if (jogador != 1 && jogador != 2) {
		printf("ID do jogador invalido! Deve ser 1 ou 2\n");
		return 1;
	}

	//Primeira 'dobrada'
	if (dp->ultimo_jogador == 0) {

		dp->mult = 2;
		dp->ultimo_jogador = jogador;

		return 0;
	}

	//Verifica se jogador pode dobrar os pontos
	if (dp->ultimo_jogador == jogador) {
		printf("Este jogador não pode dobrar a pontuacao!\n");
		return 2;
	}
	
	//Verifica se valor do multiplicador é maximo
	if (dp->mult == 64) {
		printf("Valor maximo do dado atingido!\n");
		return 3;
	}

	dp->ultimo_jogador = jogador;
	dp->mult = dp->mult * 2;

	return 0;
}

int lerPontos(DadosPontos *dp, int jogador)
{
	//Verifica se ID do jogador é valido
	if (jogador != 1 && jogador != 2) {
		printf("ID do jogador invalido! Deve ser 1 ou 2\n");
		return -1;
	}

	if (jogador == 1) {
		return dp->pontuacaoJogador1;
	}
	else
	{
		return dp->pontuacaoJogador2;
	}

}

int lerValorDadosPontos(DadosPontos *dp) 
{
	return dp->mult;
}

int lerUltimoJogador(DadosPontos *dp) 
{
	return dp->ultimo_jogador;
}

int modificaPontos(int valor, int jogador, DadosPontos *dp)
{
	//Verifica se ID do jogador é valido
	if (jogador != 1 && jogador != 2) {
		printf("ID do jogador invalido! Deve ser 1 ou 2\n");
		return 1;
	}

	if (jogador == 1) {
		dp->pontuacaoJogador1 =  dp->pontuacaoJogador1 + valor;
	}
	else
	{
		dp->pontuacaoJogador2 = dp->pontuacaoJogador2 + valor;
	}

	return 0;
	
}
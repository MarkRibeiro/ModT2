#include<stdio.h>
#include<stdlib.h>

typedef struct dadosPontos DadosPontos;

typedef enum {

	DP_CondRetOk = 0,
	/* Executou correto */

	DP_CondRetNaoExiste = 1,
	/* DadosPontos nao incializado */

	DP_CondRetJogadorInvalido = 2,
	/*ID jogador invalido*/

	DP_CondRetJogadorNaoPodeDobrar = 3,
	/*Jogador nao pode dobrar*/

	DP_CondRetValorMaximoDado = 4,
	/*Valor maximo do dado atingido*/

	DP_CondRetFaltouMemoria = 5
	/* Faltou memória ao alocar dados */

} DP_tpCondRet;

//Inicializa DadosPontos
DP_tpCondRet criaDadosPontos(void);

//Dobra valor do DadosPontos, necessita o id do jogador que esta dobrando a pontuacao
DP_tpCondRet dobraValor(int jogador);

//Adciona valor a pontuacao do jogador
DP_tpCondRet modificaPontos(int valor, int jogador);

//Retorna a pontuacao do jogador
DP_tpCondRet lerPontos(int jogador, int *val);

//Retorna o valor atual do multiplicador dos pontos
DP_tpCondRet lerValorDadosPontos(int *val);

//Retorna o ID do ultimo jogador que dobrou
DP_tpCondRet lerUltimoJogador(int *val);

DP_tpCondRet destroiDadosPontos(void);

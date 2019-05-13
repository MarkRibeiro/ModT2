#include<stdio.h>
#include<stdlib.h>

typedef struct dadosPontos DadosPontos;

//Inicializa DadosPontos
DadosPontos* criaDadosPontos();

//Dobra valor do DadosPontos, necessita o id do jogador que esta dobrando a pontuacao
int dobraValor(int jogador, DadosPontos *dp);

//Adciona valor a pontuacao do jogador
int modificaPontos(int valor, int jogador, DadosPontos *dp);

//Retorna a pontuacao do jogador
int lerPontos(DadosPontos *dp, int jogador);

//Retorna o valor atual do multiplicador dos pontos
int lerValorDadosPontos(DadosPontos *dp);

//Retorna o ID do ultimo jogador que dobrou
int lerUltimoJogador(DadosPontos *dp);

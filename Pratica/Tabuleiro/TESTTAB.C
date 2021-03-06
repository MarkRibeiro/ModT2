/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste do tabuleiro
*
*  Arquivo gerado:              TESTTAB.C
*  Letras identificadoras:      TESTAB
*
*  Projeto: Trabaolho 2 Modular
*  Autores: cgm - Caio Gra�a Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Hist�rico de evolu��o:
*    Vers�o	  Autores		 	 Data			Observa��es
*      1		cgm			  	03/05/2019     Modulo de teste criado
*
*  $ED Descri��o do m�dulo
*     Este m�dulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo tabuleiro. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo tabuleiro:
*
*     "=criar"        
*		- chama fun��o TAB_CriarTabuleiro( )
*
*     "=destruir"   
*		- chama fun��o TAB_DestruirTabuleiro( )
*
*	  "=move" <int> <int>
*		- chama fun��o TAB_MoverPeca( <int>, <int> )
*
*     "=remove <int>"
*       - chama fun��o TAB_RemoverPecaCasa( <int> )
*
*     "=insere <Int> <Int>"
*       - chama fun��o TAB_InserirPecaCasa( <Int> , <Int> )
*
*     "=imprimir"		
*		- chama fun��o TAB_PrintTabuleiro()
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    "generico.h"
#include    "lerparm.h"
#include "LISTA.H"
#include "TABULEIRO.H"
#include "PECA.H"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_TAB_CMD       "=criar"
#define     ARRUMAR_TAB_CMD     "=arrumar"
#define     INSERE_CMD         	"=inserir"
#define     REMOVE_CMD         	"=remover"
#define     MOVE_CMD         	"=mover"
#define     IMPRIMI_CMD         "=imprimir"
#define     DESTROI_CMD         "=destruir"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TESTAB Efetuar opera��es de teste espec�ficas para tabuleiro
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     tabuleiro ser testado.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

	TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
	{

		TAB_tpCondRet CondRetObtido   = TAB_CondRetOK ;
		TAB_tpCondRet CondRetEsperada = TAB_CondRetCasaVazia ;
												  /* inicializa para qualquer coisa */

		char ValorDadoCor='b';
		int ValorDadoInt= 0 ;
		int ValorDadoInt2=0;
		int ValorRecebidoInt= 0 ;
		int ValorEsperadoInt= 0 ;

		int  NumLidos = -1 ;

		TST_tpCondRet Ret ;

		/* Testar TAB Criar tabuleiro */

			if ( strcmp( ComandoTeste , CRIAR_TAB_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_CriarTabuleiro( ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao criar o tabuleiro." ) ;

			} /* fim ativa: Testar TAB Criar tabuleiro */

			/* Testar TAB Criar tabuleiro */

			if ( strcmp( ComandoTeste , ARRUMAR_TAB_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_ArrumarTabuleiro( ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao criar o tabuleiro." ) ;

			} /* fim ativa: Testar TAB Criar tabuleiro */

		/* Testar TAB Arrumar Pe�a na Casa */

			else if ( strcmp( ComandoTeste , INSERE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "iici" ,
										 &ValorDadoInt , &ValorDadoInt2, &ValorDadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 4 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_InserirPecasCasa( ValorDadoInt , ValorDadoCor, ValorDadoInt2 ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao inserir pe�a na casa dada." ) ;

			} /* fim ativa: Testar TAB Arrumar Pe�a na Casa */

			/* Testar TAB Move Pe�a */

			else if ( strcmp( ComandoTeste , MOVE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "iici" ,
										 &ValorDadoInt , &ValorDadoInt2, &ValorDadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 4 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_MoverPeca( ValorDadoInt , ValorDadoInt2, ValorDadoCor ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao inserir pe�a na casa dada." ) ;

			} /* fim ativa: Testar TAB Move Pe�a */

		/* Testar TAB Remover Pe�a na Casa */

			else if ( strcmp( ComandoTeste , REMOVE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ii" ,
										 &ValorDadoInt , &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_RemoverPeca( ValorDadoInt ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao remover pe�a na casa dada." ) ;

			} /* fim ativa: Testar TAB Remover Pe�a na Casa */

		 /* Testar TAB Imprime Tabuleiro */

			else if ( strcmp( ComandoTeste , IMPRIMI_CMD ) == 0 )
			{
				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */
				
				CondRetObtido = TAB_PrintTabuleiro() ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao imprimir costura." ) ;

			} /* fim ativa: Testar TAB Imprime Tabuleiro */


		/* Testar TAB Destruir Tabuleiro */

			else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
			{

				TAB_DestruirTabuleiro( ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar TAB Destruir Tabuleiro */

		return TST_CondRetNaoConhec ;

	} /* Fim fun��o: TTAB Efetuar opera��es de teste espec�ficas para tabuleiro */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/
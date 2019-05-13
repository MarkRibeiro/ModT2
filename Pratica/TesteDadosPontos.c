#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "DadosPontos.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_DP			"=criar"
#define     DOBRA				"=dobra"
#define     MOD_PONTOS			"=modPontos"
#define     LER_PONTOS          "=lerPontos"
#define     LER_VALOR_DP        "=lerDP"
#define     LER_ULTIMO_JOGADOR  "=lerUltimoJogador"
#define     DESTROI_DP			"=destruir"


   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

	   DP_tpCondRet CondRetObtido   = DP_CondRetOk;
	   DP_tpCondRet CondRetEsperada = DP_CondRetFaltouMemoria;

      int ValorEsperado = 0 ;
      int ValorObtido   = 0  ;
      int ValorDado     = 0 ;
	  int ValorDado_2 = 0;

      int  NumLidos = -1 ;

      TST_tpCondRet Ret ;

      /* Testar ARV Criar DadosPontos */

         if ( strcmp( ComandoTeste , CRIAR_DP) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            }

            CondRetObtido = criaDadosPontos( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar DadosPontos." );

         }

      /* Testar DP dobrar valor dado */

         else if ( strcmp( ComandoTeste , DOBRA) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                               &ValorDado , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            }

            CondRetObtido = dobraValor( ValorDado ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao dobrar dados pontos." );

         }

      /* Testar DP modificar pontos */

         else if ( strcmp( ComandoTeste , MOD_PONTOS) == 0 )
         {

            NumLidos = LER_LerParametros( "iii" ,
                               &ValorDado, &ValorDado_2 , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            }

            CondRetObtido = modificaPontos( ValorDado, ValorDado_2 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao modificar pontos." );

         } 

      /* Testar ler pontuacao */

         else if ( strcmp( ComandoTeste , LER_PONTOS) == 0 )
         {
			 NumLidos = LER_LerParametros("iii",
				 &ValorDado, &ValorEsperado, &CondRetEsperada);
			 if (NumLidos != 3)
			 {
				 return TST_CondRetParm;
			 }

			 CondRetObtido = lerPontos(ValorDado, &ValorObtido);

			 Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				 "Retorno errado ao ler pontos.");

			 if (Ret != TST_CondRetOK)
			 {
				 return Ret;
			 }

			 return TST_CompararInt(ValorEsperado, ValorObtido,
				 "Valor retornado por ler pontos esta errado.");

         }

      /* Testar DP ler valor do dados pontos */

         else if ( strcmp( ComandoTeste , LER_VALOR_DP) == 0 )
         {

			 NumLidos = LER_LerParametros("ii",
				 &ValorEsperado, &CondRetEsperada);
			 if (NumLidos != 2)
			 {
				 return TST_CondRetParm;
			 }

			 CondRetObtido = lerValorDadosPontos(&ValorObtido);

			 Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				 "Retorno errado ao ler valor do dados pontos.");

			 if (Ret != TST_CondRetOK)
			 {
				 return Ret;
			 }

			 return TST_CompararInt(ValorEsperado, ValorObtido,
				 "Valor do dados pontos esta errado.");

         }

         else if ( strcmp( ComandoTeste , LER_ULTIMO_JOGADOR) == 0 )
         {

			 NumLidos = LER_LerParametros("ii",
				 &ValorEsperado, &CondRetEsperada);
			 if (NumLidos != 2)
			 {
				 return TST_CondRetParm;
			 }

			 CondRetObtido = lerUltimoJogador(&ValorObtido);

			 Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				 "Retorno errado ao ler ultimo jogador a dobrar.");

			 if (Ret != TST_CondRetOK)
			 {
				 return Ret;
			 }

			 return TST_CompararInt(ValorEsperado, ValorObtido,
				 "Ultimo jogador esta errado.");

         }

         else if ( strcmp( ComandoTeste , DESTROI_DP ) == 0 )
         {
            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            }

            CondRetObtido = destroiDadosPontos( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar DadosPontos." );

         } 

      return TST_CondRetNaoConhec ;

   }


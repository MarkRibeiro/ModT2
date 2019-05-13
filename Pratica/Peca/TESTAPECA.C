#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "PECA.H"


#define     CRIAR_PEC_CMD          "=criarpeca"
#define     OBTER_PEC_CMD          "=obterpeca"
#define     DESTROI_PEC_CMD        "=destruirpeca"

Peca *pecas[2] = {NULL, NULL};

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
      PEC_tpCondRet CondRetObtido   = PEC_CondRetOK ;
      PEC_tpCondRet CondRetEsperada = PEC_CondRetFaltouMemoria ;               

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorRecebido = '\0' ;

      int  NumLidos = -1 ;
      int ind;
      int i;

      TST_tpCondRet Ret ;


      //Testar PEC_CriaPeça
      if ( strcmp( ComandoTeste , CRIAR_PEC_CMD ) == 0 )
      {
         NumLidos = LER_LerParametros( "ici" , &ind, &ValorRecebido, &CondRetEsperada ) ;

         if ( NumLidos != 3 )
         {
            return TST_CondRetParm ;
         } //if

         if ( pecas[ind]!=NULL || ind>=2  )
         {
         	return TST_CondRetParm;
         } //if

         CondRetObtido = PEC_CriaPeca(&pecas[ind], ValorRecebido );

         return TST_CompararInt( CondRetEsperada , CondRetObtido , "Retorno errado ao criar peça." );

      } //fim ativa: Testar PEC_CriaPeca


      //Testar PEC_ObterCorPeca
      else if ( strcmp( ComandoTeste , OBTER_PEC_CMD ) == 0 )
      {
         NumLidos = LER_LerParametros( "ici" , &ind, &ValorRecebido, &CondRetEsperada ) ;
         
         if ( NumLidos != 3 )
         {
            return TST_CondRetParm ;
         } //if

         if ( ind>=30  )
         {
         	return TST_CondRetParm;
         } //if

         CondRetObtido = PEC_ObterCorPeca(pecas[ind], &ValorObtido );

         if(CondRetObtido == PEC_CondRetPecaNaoExiste)
         {
            return TST_CompararInt( CondRetEsperada , CondRetObtido , "Retorno errado ao criar peca." );
         } //if

         if(ValorRecebido!=ValorObtido)
   	   {
   		   return TST_CompararChar(ValorRecebido, ValorObtido, "Cor errada");
   	   } //if

         return TST_CompararInt( CondRetEsperada , CondRetObtido , "Retorno errado ao obter cor." );
      } //fim ativa: PEC_ObterCorPeca 


      //Testar PEC_DestroiPeca
      else if ( strcmp( ComandoTeste , DESTROI_PEC_CMD ) == 0 )
      {
         NumLidos = LER_LerParametros( "ii" , &ind, &CondRetEsperada ) ;
            
         if ( NumLidos != 2 )
         {
            return TST_CondRetParm ;
         } //if

         if ( ind>=30  )
         {
            return TST_CondRetParm;
         } //if
         
         CondRetObtido = PEC_DestroiPeca( pecas[ind] );

         if(CondRetObtido == PEC_CondRetOK)
         {
            return TST_CondRetOK;
         } //if

         if(CondRetObtido == PEC_CondRetPecaNaoExiste)
         {
            return TST_CondRetParm;
         } //if

         return TST_CompararInt( CondRetEsperada , CondRetObtido , "Retorno errado ao destruir peça." );
      } //fim ativa: PEC_DestroiPeca

      return TST_CondRetNaoConhec ;
   } //Fim função: TPEC Efetuar operações de teste específicas para peça
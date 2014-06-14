/***************************************************************************
*  $MCI Módulo de implementação: PEC  Peca 
*
*  Arquivo gerado:              PECA.c
*  Letras identificadoras:      PEC
*
*  Projeto: damas
*  Arquivo: damas\Fontes\peca.c    
*
*  Autores: hs - Henrique Santiago
*	    mr - Marcelo Resende
*	    rh - Rafael Haeusler
*  
*  $HA Histórico de evolução: 
*     Versão  Autor    Data     Observações
*     2       hs/mr/rh   17/junho/2014    implementação completa do jogo
*  
*  $CRE Créditos
*    Arndt von Staa. Programa AutoTest - Arcabouço para a automação de testes de 
*    programas redigidos em C;módulo Lista Duplamente Encadeada
*  
***************************************************************************/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define peca_OWN
#include "peca.h"
#undef peca_OWN

#ifdef _DEBUG
#include "generico.h"
#include "conta.h"
#include "cespdin.h"
#include "tipos.h"
#endif

/***********************************************************************
*
*  $TC Tipo de dados: PEC tipo estipula a estrutura de peca
*
*
***********************************************************************/
typedef struct _Peca {
    PecaTipo tipo;
    char caracter;
} Peca;


/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: PEC  &Criar uma peça
*  ****/
Peca *PEC_criar(PecaTipo tipo, char caracter)
{
    Peca *peca = (Peca*)malloc(sizeof(Peca));
    if(peca == NULL)
        return NULL;

#ifdef _DEBUG
    CED_DefinirTipoEspaco(peca, PEC_Peca);
#endif

    PEC_setarTipo(peca, tipo);
    PEC_setarCaracter(peca, tolower(caracter));
    return peca;
}/* Fim função: PEC  &Criar uma peça */


/***************************************************************************
*
*  Função: PEC  &Destruir uma determinada peça
*  ****/
PEC_tpCondRet PEC_destruir(Peca *peca)
{
    if(peca == NULL)
        return PEC_CondRetPecaVazia;

    free(peca);
    return PEC_CondRetOK;
}/* Fim função: PEC  &Destruir uma determinada peça */


/***************************************************************************
*
*  Função: PEC  &Imprimir uma determinada  peça
*  ****/
void PEC_imprimir(Peca *peca)
{
#ifdef _DEBUG
    assert(peca);
#endif
    if(peca->tipo == PecaNormal)
        printf("%c|", peca->caracter);
    else
        printf("%c|", toupper(peca->caracter));
}/* Fim função: PEC  &Imprimir uma determinada peça */


/***************************************************************************
*
*  Função: PEC  &Obter tipo de uma determinada  peça
*  ****/
PecaTipo PEC_obterTipo(Peca *peca)
{
#ifdef _DEBUG
    assert(peca);
#endif
    return peca->tipo;
}/* Fim função: PEC  &Obter tipo de uma determinada peça */


/***************************************************************************
*
*  Função: PEC  &Setar tipo de uma determinada  peça
*  ****/
PEC_tpCondRet PEC_setarTipo(Peca *peca, PecaTipo tipo)
{
    if(peca == NULL)
        return PEC_CondRetPecaVazia;

    if(tipo != PecaNormal && tipo != PecaDama)
        return PEC_CondRetTipoInexistente;

    peca->tipo = tipo;
    return PEC_CondRetOK;
}/* Fim função: PEC  &Setar tipo de uma determinada peça */


/***************************************************************************
*
*  Função: PEC  &Obter caracter identificador de uma determinada  peça
*  ****/
char PEC_obterCaracter(Peca *peca)
{
#ifdef _DEBUG
    assert(peca);
#endif
    return peca->caracter;
}/* Fim função: PEC  &Obter caracter identificador de uma determinada peça */


/***************************************************************************
*
*  Função: PEC  &Setar caracter identificador de uma determinada  peça
*  ****/
PEC_tpCondRet PEC_setarCaracter(Peca *peca, char caracter)
{
    if(peca == NULL)
        return PEC_CondRetPecaVazia;
    caracter=tolower(caracter);
    peca->caracter = caracter;
    return PEC_CondRetOK;
}/* Fim função: PEC  &Setar caracter identificador de uma determinada  peça */

/********** Fim do módulo de definição: PEC Peca **********/

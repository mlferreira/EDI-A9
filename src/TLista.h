/**********************************************************************/
/*                                                                    */
/*                        Estrutura de Dados I                        */
/*                             Prática 09                             */
/*                                                                    */
/*                               2016-1                               */
/*                                                                    */
/*                        Melina Lopes Ferreira                       */
/*                              15.2.4002                             */
/*                                                                    */
/**********************************************************************/

#ifndef TLista_h
#define TLista_h

#include <iostream>
using namespace std;


typedef struct{
	int chave;
}TItem;

typedef struct celula{
	struct celula *pProx;
	TItem item;
}TCelula;

typedef struct{
	TCelula *pPrimeiro;
	TCelula *pUltimo;
	int tamanho;
}TLista;


TLista* TLista_Inicia();

bool TLista_EhVazia(TLista* pLista);

int TLista_InsereUltimo(TLista* pLista, TItem x);

int TLista_InsereOrdenado(TLista* pLista, TItem x);

int TLista_RetiraPrimeiro(TLista* pLista, TItem* pX);


#endif /* TLista_h */

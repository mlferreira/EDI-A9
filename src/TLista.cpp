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

#include <iostream>
#include "TLista.h"
using namespace std;


TLista* TLista_Inicia(){
	TLista * pLista = new TLista[sizeof(TLista)];
    pLista->pPrimeiro = NULL;
    pLista->pUltimo = NULL;
	pLista->tamanho = 0;
	return pLista;
}

bool TLista_EhVazia(TLista* pLista){
    return (pLista->tamanho == 0);
}

//insere um item no final da lista
int TLista_InsereUltimo(TLista* pLista , TItem x){
    TCelula *novo = new TCelula[sizeof(TCelula)];
    novo->item = x;
    novo->pProx = NULL;
    if(TLista_EhVazia(pLista)){
        pLista->pPrimeiro = novo;
        pLista->pUltimo = novo;
    }else{
        pLista->pUltimo->pProx = novo;
        pLista->pUltimo = novo;
    }
	pLista->tamanho += 1;
	return 1;
}

int TLista_InsereOrdenado(TLista* pLista, TItem x){
	TCelula *novo = new TCelula[sizeof(TCelula)];
	TCelula *aux;
    novo->item = x;


    if(TLista_EhVazia(pLista)){
        pLista->pPrimeiro = novo;
        pLista->pUltimo = novo;
    }
	else if(novo->item.chave <= pLista->pPrimeiro->item.chave){
			novo->pProx = pLista->pPrimeiro;
			pLista->pPrimeiro = novo;
	}
	else if(novo->item.chave >= pLista->pUltimo->item.chave){
			pLista->pUltimo->pProx = novo;
			pLista->pUltimo = novo;
			novo->pProx = NULL;
	}
	else{
		aux = pLista->pPrimeiro;

		while(novo->item.chave >= aux->pProx->item.chave){
			aux = aux->pProx;
		}
		novo->pProx = aux->pProx;
		aux->pProx = novo;
    }

	pLista->tamanho += 1;
	return 1;
}

//retira um item da posição p da lista
int TLista_RetiraPrimeiro(TLista* pLista ,TItem* pX){
    if(TLista_EhVazia(pLista)){
        return 0;
    }
    TCelula *pAux;
    pAux = pLista->pPrimeiro;
    *pX = pAux->item;
    pLista->pPrimeiro =  pAux->pProx;
	pLista->tamanho -= 1;
    return 1;
}




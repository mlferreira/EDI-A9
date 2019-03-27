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

#ifndef gerador_h
#define gerador_h


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;


#define QTD_NUM 100
#define QTD_VET 3


void gerarVetores() {
	srand(time(NULL));
	
	int v=0;
	
	ofstream arquivo("test/entrada.txt", ios::trunc);

	if (arquivo.is_open()){
		
		arquivo << QTD_VET << endl;
		
		while(v<QTD_VET){
		
			//aleatorio
			arquivo << QTD_NUM << " ";
			for(int i=0; i<QTD_NUM; i++){
				arquivo << rand()%QTD_NUM + 1 << " ";
			}
			arquivo << endl;
			v++;
			if(v==QTD_VET) break;
			
			//crescente
			arquivo << QTD_NUM << " ";
			for(int i=1; i<=QTD_NUM; i++){
				arquivo << i << " ";
			}
			arquivo << endl;
			v++;
			if(v==QTD_VET) break;
			
			//decrescente
			arquivo << QTD_NUM << " ";
			for(int i=QTD_NUM; i>0; i--){
				arquivo << i << " ";
			}
			arquivo << endl;
			v++;
			
		}
		
		arquivo.close();
		
	}else{ 
		cout << "Nao foi possivel abrir o arquivo" << endl;
	}  
}


#endif /* gerador_h */

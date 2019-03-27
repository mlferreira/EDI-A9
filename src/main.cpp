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

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>
#include <time.h>
#include "gerador.h"
#include "TLista.h"
using namespace std;

typedef void (*Funcoes) (int* v, int n, long int* C, long int* M, double* T);

void copiaVetor(int* vA, int* vB, int n);
void imprimeVetor(int* v, int n, ofstream &saida);

void bubbleSort(int* v, int n, long int* C, long int* M, double* T);
void selectionSort(int* v, int n, long int* C, long int* M, double* T);
void insertionSort(int* v, int n, long int* C, long int* M, double* T);
void mergeSort(int* v, int n, long int* C, long int* M, double* T);
	void mergeSortIntercala(int* v, int esq, int meio, int dir, long int* C, long int* M);
void shellSort(int* v, int n, long int* C, long int* M, double* T);
void quickSort(int* v, int n, long int* C, long int* M, double* T);
	void quickSortOrdena(int* v, int esq, int dir, long int* C, long int* M);
	void quickSortParticao(int* v, int esq, int dir, int* i, int* j, long int* C, long int* M);
void heapSort(int* v, int n, long int* C, long int* M, double* T);
	void heapConstroi(int* v, int n, long int* C, long int* M);
	void heapRefaz(int* v, int esq, int dir, long int* C, long int* M);
void countingSort(int* v, int n, long int* C, long int* M, double* T);
void radixSort(int* v, int n, long int* C, long int* M, double* T);
	void countingSort_Radix(int* v, int n, int d, long int* C, long int* M);
void bucketSort(int* v, int n, long int* C, long int* M, double* T);



int main(int argc, char *argv[]) {
	int tamVetor, quantVetores;
	string ordenacoes;
	
	string nomeSort[10] = {"Bubble....", "Selection.", "Insertion.", "Merge.....", "Shell.....", "Quick.....", "Heap......", "Counting..", "Radix.....", "Bucket...."};
	
	long int C[10]; // Contador de comparacoes 
	long int M[10]; // Contador de movimentos 
	double T[10]; 	// Contador do tempo 
	
	int * vAux;
	int * vetor;
	
	ifstream entrada;
	ofstream saida("test/saida.txt", ios::trunc);
	
	Funcoes ordena[10] = {bubbleSort, selectionSort, insertionSort, mergeSort, shellSort, quickSort, heapSort, countingSort, radixSort, bucketSort};
	
	
	if(argc == 1) {
		gerarVetores();
		ordenacoes = "0123456789";
		entrada.open("test/entrada.txt");
	}
	else if(argc == 3) {
		ordenacoes = argv[1];
		entrada.open(argv[2]);
	}
	else {
		cout << "ERRO: CHAMADA INCORRETA";
		return 0;
	}
	
	entrada >> quantVetores;
	cout << quantVetores <<endl;
	
	for(int i=0; i<quantVetores; i++){

		entrada >> tamVetor;
		
		vAux = new int[tamVetor];
		vetor = new int[tamVetor];
		
		for(int j=0; j<tamVetor; j++){
			entrada >> vetor[j];
		}
		
		saida << "Vetor " << i+1 << ": " << endl;
		cout << "Vetor " << i+1 << ": " << endl;
		
		saida << "- Ordenacao: " << endl;
		cout << "- Ordenacao: " << endl;
		
		for(int k=0; k<ordenacoes.size(); k++) {
			int n = (int)ordenacoes[k]-48;
			copiaVetor(vetor, vAux, tamVetor);
			ordena[n](vAux, tamVetor, &C[n], &M[n], &T[n]);
			saida << "- - " << nomeSort[n] << ":  "; imprimeVetor(vAux, tamVetor, saida);
			cout << "- - " << nomeSort[n] << ":  "; imprimeVetor(vAux, tamVetor, saida);			
		}
		
		saida << endl;
		cout << endl;
		for(int k=0; k<ordenacoes.size(); k++) {
			int n = (int)ordenacoes[k]-48;
			saida << "- Comparacoes | Movimentacoes | Tempo: " << endl;
			cout << "- Comparacoes | Movimentacoes | Tempo: " << endl;
			saida << "- - " << nomeSort[n] << ":  " << C[0] << " | " << M[0] << " | " << T[0] << endl;
			cout << "- - " << nomeSort[n] << ":  " << C[0] << " | " << M[0] << " | " << T[0] << endl;
		}
		saida << endl;
		cout << endl;
			
	}
	
	delete[] vetor;
	delete[] vAux;

	saida << endl;
	cout << endl;

	entrada.close();
	saida.close();
	
	return 0;
}


void copiaVetor(int* vA, int* vB, int n){
	for(int i=0; i<n; i++){
		vB[i] = vA[i];
	}
}

void imprimeVetor(int* v, int n, ofstream &saida){
	if (saida.is_open()){
		saida << "V = {";
		cout << "V = {";
		for(int i=0; i<n-1; i++){
			saida << v[i] << ", ";
			cout << v[i] << ", ";
		}
		saida << v[n-1] << "}" << endl;
		cout << v[n-1] << "}" << endl;
	}else{
		cout << "ERRO AO ABRIR O ARQUIVO!" << endl;
		cout << "V = {";
		for(int i=0; i<n-1; i++){
			cout << v[i] << ", ";
		}
		cout << v[n-1] << "}" << endl;
	}
}



void bubbleSort(int* v, int n, long int* C, long int* M, double* T){
	double start_s=clock();
	*C = 0;
	*M = 0;
	int aux, trocas;
	
	for(int i=0; i<n-1; i++){
		
		trocas = 0;
		
		for(int j=1; j<n; j++){
			*C += 1;
			if(v[j] < v[j-1]){
				aux = v[j];
				v[j] = v[j-1];
				v[j-1] = aux;
				trocas++;
				*M += 1;
			}
		}
		if(trocas == 0){
			break;
		}
	}

	double stop_s=clock();
	*T = (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000.0;
}

void selectionSort(int* v, int n, long int* C, long int* M, double* T){
	double start_s=clock();
	*C = 0;
	*M = 0;
	int aux, min;
	
	for(int i=0; i<n-1; i++){
		
		min = i;
		
		for(int j=i+1; j<n; j++){
			*C += 1;
			if(v[j] < v[min]){
				min = j;
			}
		}
		*C += 1;
		if(i != min){
			aux = v[min];
			v[min] = v[i];
			v[i] = aux;
			*M += 1;
		}
	}
	double stop_s=clock();
	*T = (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000.0;
}

void insertionSort(int* v, int n, long int* C, long int* M, double* T){
	double start_s=clock();
	int j;
	*C = 0;
	*M = 0;
	for(int i=n-2; i>=0; i--){
		
		v[n] = v[i];
		j = i+1;
		
		while(v[n] > v[j]){
			v[j-1] = v[j];
			j++;
		}

		*C += 1;
		*M += 1;
		
		v[j-1] = v[n];
	}
	double stop_s=clock();
	*T = (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000.0;
}

void mergeSort(int* v, int n, long int* C, long int* M, double* T){
	double start_s=clock();
	int esq, dir, b = 1;
	*C = 0;
	*M = 0;

	while(b<n){
		esq = 0;

		while(esq+b < n){
			dir = esq + 2*b;

			if(dir > n){
				dir = n;
			}

			mergeSortIntercala(v, esq, esq+b-1, dir-1, C, M);

			esq = esq + 2*b;
		}
		b *= 2;
	}

	double stop_s=clock();
	*T = (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000.0;
}

void mergeSortIntercala(int* v, int esq, int meio, int dir, long int* C, long int* M){
	int tamA = meio-esq+1;
	int tamB = dir-meio;

	int * a = new int[tamA];
	int * b = new int[tamB];

	for(int i=0; i<tamA; i++){
		a[i] = v[i+esq];
	}

	for(int i=0; i<tamB; i++){
		b[i] = v[i+meio+1];
	}

	for(int i=0, j=0, k=esq; k<=dir; k++){
		*C += 1;
		if(i==tamA){
			v[k] = b[j++];
		}
		else if(j==tamB){
			v[k] = a[i++];
		}
		else if(a[i] < b[j]){
			*M += 1;
			v[k] = a[i++];
		}
		else{
			*M += 1;
			v[k] = b[j++];
		}
	}

	delete[] a;
	delete[] b;
}

void shellSort(int* v, int n, long int* C, long int* M, double* T){
	double start_s=clock();
	int h, j, aux;
	*C = 0;
	*M = 0;

	for(h=1; h<n; h = (3*h)+1);
	
	do{

		h = (h-1)/3;

		for(int i=h; i<n; i++){
			*C += 1;

			aux = v[i];
			j=i;

			while(v[j-h] > aux){
				*M += 1;

				v[j] = v[j-h];
				j -= h;

				if(j<h){
					break;
				}
			}

			v[j] = aux;
		}

	}while(h != 1);

	double stop_s=clock();
	*T = (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000.0;
}

void quickSort(int* v, int n, long int* C, long int* M, double* T){
	double start_s=clock();
	*C = 0;
	*M = 0;

	quickSortOrdena(v, 0, n-1, C, M);

	double stop_s=clock();
	*T = (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000.0;
}

void quickSortOrdena(int* v, int esq, int dir, long int* C, long int* M){
	*M += 1;
	*C += 1;
	int i, j;

	quickSortParticao(v, esq, dir, &i, &j, C, M);

	if(esq < j){
		quickSortOrdena(v, esq, j, C, M);
	}
	if(i < dir){
		quickSortOrdena(v, i, dir, C, M);
	}
}

void quickSortParticao(int* v, int esq, int dir, int* i, int* j, long int* C, long int* M){
	*M += 1;
	int pivo, aux;
	
	*i = esq; 
	*j = dir;
	pivo = v[(*i + *j)/2];

	do{

		while(!(pivo <= v[*i])){
			*C += 1;
			*i += 1;
		}

		while(pivo < v[*j]){
			*C += 1;
			*j -= 1;
		}

		if(*i <= *j){
			aux = v[*i];
			v[*i] = v[*j];
			v[*j] = aux;

			*i += 1;
			*j -= 1;

			*C += 1;
			*M += 1;
		}

	}while (*i <= *j);
}

void heapSort(int* v, int n, long int* C, long int* M, double* T){
	double start_s=clock();
	*C = 0;
	*M = 0;

	int aux;
	int nAux = n;
	
	heapConstroi(v, n, C, M);

	while(nAux > 1){
		aux = v[nAux-1];
		v[nAux-1] = v[0];
		v[0] = aux;
		nAux--;

		heapRefaz(v, 0, nAux-1, C, M);
	}

	double stop_s=clock();
	*T = (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000.0;
}

void heapConstroi(int* v, int n, long int* C, long int* M){
	int esq;
	esq = (n/2) - 1;

	while (esq >= 0){
		heapRefaz(v, esq, n-1, C, M);
		esq--;
	}
}

void heapRefaz(int* v, int esq, int dir, long int* C, long int* M){
	int i = esq;
	int j = i*2 +1;
	int aux = v[i];

	while(j <= dir){
		*C += 1;

		if(j<dir && v[j] < v[j+1]){
			j++;
		}

		if(aux >= v[j]){
			break;
		}

		v[i] = v[j];
		i = j;
		j = i*2 + 1;

		*M += 1;
	}

	v[i] = aux;

}

void countingSort(int* v, int n, long int* C, long int* M, double* T){
	double start_s=clock();
	*C = 0;
	*M = 0;
	int k = 0;

	int * vCopia = new int[n+1]; //copia o vetor e acha o valor de k
	for(int i=1; i<=n; i++){
		vCopia[i] = v[i-1];
		if(vCopia[i] > k)
			k = vCopia[i];
	}

	int * vTemp = new int[k+1];
	for(int i=0; i<=k; i++){
		vTemp[i] = 0;
	}

	for(int i=1; i<=n; i++){
		*C += 1;
		vTemp[vCopia[i]] += 1;
	}

	for(int i=1; i<=k; i++){
		vTemp[i] += vTemp[i-1];
	}

	for(int i=n; i>0; i--){
		*M += 1;
		v[vTemp[vCopia[i]]-1] = vCopia[i];
		vTemp[vCopia[i]] -= 1;
	}

	delete[] vCopia;
	delete[] vTemp;

	double stop_s=clock();
	*T = (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000.0;
}

void radixSort(int* v, int n, long int* C, long int* M, double* T){
	double start_s=clock();
	*C = 0;
	*M = 0;

	int max=0;

	for(int i=0; i<n; i++){ //acha o maior numero
		if(v[i] > max)
			max = v[i];
	}

	for(int i = 1; max/i > 0; i *= 10){ //quantidade de digitos
		countingSort_Radix(v, n, i, C, M);
	}

	double stop_s=clock();
	*T = (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000.0;
}

void countingSort_Radix(int* v, int n, int d, long int* C, long int* M){
	int * vCopia = new int[n+1]; 
	for(int i=1; i<=n; i++){
		vCopia[i] = v[i-1];
	}

	int * vTemp = new int[10];
	for(int i=0; i<10; i++){
		vTemp[i] = 0;
	}

	for(int i=1; i<=n; i++){
		*C += 1;
		vTemp[ (vCopia[i]/d)%10 ] += 1;
	}

	for(int i=1; i<10; i++){
		vTemp[i] += vTemp[i-1];
	}

	for(int i=n; i>0; i--){
		*M += 1;
		v[ vTemp[ (vCopia[i]/d)%10 ] -1] = vCopia[i];
		vTemp[ (vCopia[i]/d)%10 ] -= 1;
	}

	delete[] vCopia;
	delete[] vTemp;
}

void bucketSort(int* v, int n, long int* C, long int* M, double* T){
	double start_s=clock();
	*C = 0;
	*M = 0;
	TItem item;
	int m;

	if (n >= 10) m = n/10;
	else m = n;

	TLista * vAux[10];
	for(int i=0; i<10; i++){
		vAux[i] = TLista_Inicia();
	}

	for(int i=0; i<n; i++){
		*C += 1;
		*M += 1;
		item.chave = v[i];
		TLista_InsereOrdenado(vAux[(v[i]-1)/m], item);
	}

	for(int i=0, j=0; i<n; i++){
		if(TLista_RetiraPrimeiro(vAux[j], &item) == 1){
			v[i] = item.chave;
			*M += 1;
		}else{
			j++;
			i--;
		}
	}

	double stop_s=clock();
	*T = (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000.0;
}
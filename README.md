# Algoritmos de Ordenação

Atividade prática de Estrutura de Dados I.

## Definição do Problema

Implementação dos algoritmos de ordenação: BubbleSort, SelectionSort, InsertionSort, MergeSort, ShellSort, QuickSort, HeapSort, CountingSort, RadixSort e BucketSort.


### Entrada

Se executado sem nenhum comando de linha, o programa irá executar um gerador, que vai criar um arquivo (test/entrada.txt) contendo 3 vetores de tamanho 100 (um aleatório, um ordenado de forma crescente, e um ordenado de forma decrescente), e irá executar todos os algoritmos de ordenação.

Para executar com vetores diferentes e/ou apenas alguns metodos de ordenação, deverá ser usado o comando de linha contendo os numeros do metodos de ordenação (sem espaços) e o diretório do arquivo contendo os vetores a serem ordenados.

O arquivo de entrada deve conter: a quantidade de vetores, seguido do tamanho do vetor e seus elementos, separados por espaço.


#### Exemplo

##### Execução
```
./a9 035 test/entrada.txt
```
Executará apenas os métodos: BubbleSort (0), MergeSort (3) e QuickSort (5).

##### Arquivo de Entrada
```
2
10 1 2 3 4 5 6 7 8 9 10
10 5 4 3 2 1 6 7 8 9 10
```
2 vetores de tamanho 10


### Saida

A saída contém, para cada método de ordenação, o número de comparações de chaves, o número de movimentações de registros, e o tempo de execução.
respectivamente


## Instalação e Execução


### Linux

```
make all
```

```
./a9 <metodo(s) de ordenacao> <arquivo com os vetores>
```
ou (para rodar com o gerador e todos os metodos de ordenação)
```
make run
```

### Windows

```
g++ -o a9 src/main.cpp src/gerador.h src/TLista.h src/TLista.cpp
```

```
a9 <metodo(s) de ordenacao> <arquivo com os vetores>
```
ou (para rodar com o gerador e todos os metodos de ordenação)
```
a9
```

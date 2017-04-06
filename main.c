/* 
 * File:   main.c
 * Author: BORGES, Gustavo; CASTRO, Lucas S. A.; ROSA, Murilo N.; SANTOS, Adan R. D.; SILVA, Haltielles C.; 
 * 
 * Feito para a matéria COM112 - Algoritmos e Estrutura de Dados - UNIFEI
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

long long int contComparacao, contTroca = 0;
    
double calculateExecutionTime(clock_t begin, clock_t end)
{
    return (double) (end - begin) / CLOCKS_PER_SEC;
}


/** Ordena a região de vector[] compreendida entre bgn inclusive e end inclusive. **/
void mergeSort(int vector[], int bgn, int end) {
    if (bgn < end) {
        int middle = (bgn + end) / 2;
        mergeSort(vector, bgn, middle);
        mergeSort(vector, middle + 1, end);
        merge_inPlace(vector, bgn, middle, middle + 1, end);
    }
}
void merge_inPlace(int vect[], int i, int m, int j, int n) {
    int temp; /* Variábil a se utilizar na transferência de valores entre os vectores. */
    int comp; /* Índice da secção do vector sendo comparada no algorithmo explicado abaixo. */
    while (i <= m) { /* Porque, se o primeiro vector se acabar, o vector final estará já ordenado.*/
        if (vect[i] <= vect[j]){
            i++; /* Se o primeiro campo do primeiro vector é o menor, já está na posição correcta.*/
            contTroca++;
            contComparacao++;
        }
        else {
            temp = vect[i]; /* Backup do antigo elemento inicial do primeiro vector. */
            vect[i++] = vect[j]; /* Moção do menor dos elementos pera seu devido lugar. */
            comp = j + 1;
            contTroca++;
            while (comp <= n && temp > vect[comp]) {
                vect[comp - 1] = vect[comp];
                comp++;
                contTroca++;
                contComparacao++;
            }
            vect[comp - 1] = temp;
            contTroca++;
        }
        contComparacao++;
    }
}

int mergeSortTradicional(int vet[], int inicio, int fim) {
    int meio = (inicio + fim) / 2;
    if (inicio < fim) {
        mergeSortTradicional(vet, inicio, meio);
        mergeSortTradicional(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim);
    }
    return 0;
}

void merge(int vet[], int inicio, int meio, int fim) {
    //v1:posição vetor 1    qtdv1=quantidade de elementos v1
    //v2:posição vetor 2    qtdv2=quantidade de elementos v2
    int v1 = inicio, qtdv1 = meio - inicio + 1, qtdv2 = fim - meio, v2 = meio + 1, vAux[(fim - inicio) + 1], i = 0;
    
    while (qtdv1 > 0 && qtdv2 > 0) {
        if (vet[v1] <= vet[v2]) {
            vAux[i] = vet[v1];
            contTroca++;
            contComparacao++;
            i++;
            v1++;
            qtdv1--;
        } else {
            vAux[i] = vet[v2];
            contTroca++;
            contComparacao++;
            i++;
            v2++;
            qtdv2--;
        }
        contComparacao++;
    }
    if (qtdv1 > 0) {
        while (qtdv1 > 0) {
            vAux[i] = vet[v1];
            contTroca++;
            contComparacao++;
            i++;
            v1++;
            qtdv1--;
        }
        contComparacao++;
    } else if (qtdv2 > 0) {
        while (qtdv2 > 0) {
            vAux[i] = vet[v2];
            contTroca++;
            contComparacao++;
            i++;
            v2++;
            qtdv2--;
        }
        contComparacao++;
    }
    for (i = 0; i < fim - inicio + 1; i++) {
        vet[inicio + i] = vAux[i];
        contTroca++;
        contComparacao++;
    }
    return;
}

int main(int argc, char** argv)
{
    int array[MAX];
    int size, seed, option;
    clock_t begin, end;
    double timeSpent;

    
    while(1) {
        option = menu();

        switch(option) {
            case 1:
                printf("Qual o tamanho do vetor?\n");
                scanf("%d", &size);
                
                printf("Qual a semente?\n");
                scanf("%d", &seed);
                
                //array = (int*) malloc(size*sizeof(int));
                generateArrayRandomNumbers(array, size, seed);
                //writeToFile(&array, size);
                //printArray(array, size);
                break;
            case 2:
                size = readFromFile(array);
                printArray(array, size);
                break;
            case 3:
                contComparacao = contTroca = 0;
                printCalculatingMessage();
                
                begin = clock();
                mergeSortTradicional(array, 0, size-1);
                end = clock();
                
                //printArray(array, size);
                printf("Comp: %d\n", contComparacao);
                printf("Trocas: %d\n", contTroca);
                timeSpent = calculateExecutionTime(begin, end);
                printExecutionTime(timeSpent);
                break;
            case 4:
                contComparacao = contTroca = 0;
                printCalculatingMessage();
                
                begin = clock();
                mergeSort(array, 0, size-1);
                end = clock();
                
                //printArray(array, size);
                printf("Comp: %d\n", contComparacao);
                printf("Trocas: %d\n", contTroca);
                timeSpent = calculateExecutionTime(begin, end);
                printExecutionTime(timeSpent);
                break;
            default:
                //free(array);
                exit(0);
        }
    }
    
    return (EXIT_SUCCESS);
}



/*
 * File:    ordination.c
 * Author: BORGES, Gustavo; CASTRO, Lucas S. A.; ROSA, Murilo N.; SANTOS, Adan R. D.; SILVA, Haltielles C.; 
 * 
 * Biblioteca de algoritmos de ordenação 
 */
#include <stdlib.h>
#include "ordination.h"

/**
 * BubbleSort algorithm.
 * @param array
 */
void bubbleSort(int array[], int size)
{
    int i, j, aux;
    
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size-1; j++)
        {
            if(array[j] > array[j+1])
            {
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux; 
            }
        }
    }
}

void improvedBubbleSort(int array[], int size)
{
    int i, j, aux, swap;
    
    for(i = 0; i < size; i++)
    {
        swap = 0;
        for(j = 0; j < size-1; j++)
        {
            if(array[j] > array[j+1])
            {
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
                swap = 1;
            }
        }
        
        if(swap == 0)
        {
            return;
        }
    }
}

/**
 * SelectSort algorithm.
 * @param array
 */
void selectSort(int array[], int size)
{
    int i, j, aux, position;
    
    for(i = 0; i < size-1; i++)
    {
        position = i;
        
        for(j = i+1; j < size; j++)
        {
            if(array[position] > array[j])
            {
                position = j;
            }
        }
        
        if(position != i)
        {
            aux = array[i];
            array[i] = array[position];
            array[position] = aux;
        }
    }
}
/*
void insertionSort(int array[], int size)
{
    int i, j, aux;
    
    for(i = 0; i < size; i++)
    {
        j = i;
        
        while(j > 0 && array[j] < array[j-1])
        {
            aux = array[j];
            array[j] = array[j-1];
            array[j-1] = aux;
            
            j--;
        }
    }
}
*/
/*
void mergeSort(int * array, int size)
{
    int middle, i, * arrayRight, * arrayLeft;
    
    // Caso base: se vetor tiver apenas 1 elemento, já está ordenado
    if(size < 2)
    {
        return;
    }
    
    middle = size/2;
    
    arrayLeft = (int*) malloc((size-middle)*sizeof(int));
    arrayRight = (int*) malloc((size-middle)*sizeof(int));
    
    for(i=0; i < middle; i++)
    {
        arrayRight[i] = array[i];
    }
    
    for(i=middle; i < size; i++)
    {
        arrayLeft[i-middle] = array[i];
    }
    
    mergeSort(arrayLeft, middle);
    mergeSort(arrayRight, size-middle);
    merge(array, arrayLeft, middle, arrayRight, size-middle);
    free(arrayRight);
    free(arrayLeft);
}

void merge(int *array, int *arrayLeft, int sizeLeft, int *arrayRight, int sizeRight)
{
    int i, j, k;
    
    i = j = k = 0;
    
    while(i < sizeLeft && j < sizeRight)
    {
        if(arrayLeft[i] < arrayRight[j])
        {
            array[k++] = arrayLeft[i++];
            contTroca++;
            contComparacao++;
        }
        else
        {
            array[k++] = arrayRight[j++];
            contTroca++;
        }
        contComparacao++;
    }
    
    while(i < sizeLeft)
    {
        array[k++] = arrayLeft[i++];
        contTroca++;
        contComparacao++;
    }
    
    while(j < sizeRight){
        array[k++] = arrayRight[j++];
        contTroca++;
        contComparacao++;
    }
}
int mergeSort(int vet[], int inicio, int fim) {
    int meio = (inicio + fim) / 2;
    if (inicio < fim) {
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
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
 */

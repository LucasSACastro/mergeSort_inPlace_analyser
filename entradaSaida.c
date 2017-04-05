#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "entradaSaida.h"


int menu()
{
    int option;
    
    printf("\n\t\t============== Menu ==============");
    printf("\n\t\t| 1 - Gerar vetor aleatorio      |");
    printf("\n\t\t| 2 - Carregar vetor do arquivo  |");
    printf("\n\t\t| 3 - MergeSort Tradicional      |");
    printf("\n\t\t| 4 - MergeSort In-Place         |");
    printf("\n\t\t| 5 - Sair                       |");
    printf("\n\t\t==================================\n");
    
    printf("Escolha uma opcao: ");
    scanf("%d", &option);
    
    return option;
}

void generateArrayRandomNumbers(int *array, int size, int seed)
{
    int randomNumber;
    
    srand(seed);
    
    while(size >= 0)
    {
        randomNumber = rand() % 10000;
        array[size] = randomNumber;
        size--;
    }
}

/**
 * Read data from file and store it in an array.
 * @param array
 * @return 
 */
int readFromFile(int *array)
{
    FILE * file;
    int posicao, contador;
    
    // Lê arquivo
    file = fopen("vetor.txt", "r");
 
    if(file == NULL)
    {
        printf("Erro na abertura do arquivo!");
        exit(0);
    }
 
    posicao = 0; // Inicializa o contador
    while(!feof(file))
    {
        fscanf(file, "%d ", &array[posicao]);
        posicao++;
    }
 
    fclose(file);
    
    return posicao;
}

void writeToFile(int *array, int size)
{
    FILE * file;
    int i;
    
    file = fopen("vetor_saida.txt", "w");
    
    if(file == NULL)
    {
        printf("Erro na abertura do arquivo!");
        exit(0);
    }
    
    for(i = 0; i <= size; i++)
    {
        fprintf(file, "%d ", array[i]);
    }
    
    fclose(file);
}

/**
 * Display data stored in array.
 * @param array
 * @param size
 */
void printArray(int *array, int size)
{
    int counter;
    
    printf("[");
    for(counter = 0; counter < size; counter++)
    {
        printf("%d", array[counter]);
        
        if(counter+1 != size)
        {
            printf(", ");
        }
    }
    printf("]\n\n");
}

void printExecutionTime(double time)
{
    printf("Executou em: %f segundos", time);
}

void printCalculatingMessage()
{
    printf("\nOrdenando... \n");
}


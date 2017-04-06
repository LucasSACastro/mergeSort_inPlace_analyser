/* 
 * File:   entradaSaida.h
 * Author: BORGES, Gustavo; CASTRO, Lucas S. A.; ROSA, Murilo N.; SANTOS, Adan R. D.; SILVA, Haltielles C.; 
 *
 * Created on 16 de Março de 2017, 17:14
 */

#ifndef ENTRADASAIDA_H
#define ENTRADASAIDA_H

int menu();
void generateArrayRandomNumbers(int *array, int size, int seed);
int readFromFile(int *array);
void writeToFile(int *array, int size);

void printArray(int *array, int size);
void printExecutionTime(double time);
void printCalculatingMessage();

#endif /* ENTRADASAIDA_H */


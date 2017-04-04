/*
 * File:   sort.c
 * Author: Lucas S. A. Castro (ponde vossos nomes cá)
 *
 * Created on 03 de Abril de 2017, 20:57
 */


void merge_inPlace(int i,int m, int j,int n);

/** Ordena a regiao de vector[] compreendida entre bgn inclusive e end inclusive. **/
void mergeSort(int vector[], int bgn, int end) {
    if(bgn<end) {
        int middle = bgn+end/2;
        mergeSort(bgn, middle);
        mergeSort(middle+1, end);
        merge_inPlace(bgn, middle, middle+1, end);
    }
}

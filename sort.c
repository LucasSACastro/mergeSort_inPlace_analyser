/*
 * File:   sort.c
 * Author: Lucas S. A. Castro (ponde vossos nomes cá)
 *
 * Created on 03 de Abril de 2017, 20:57
 */



/**
 ** Mescla as secções ordenadas [i,m] e [j,n] de vect[] numa só secção ordenada [i,n], sem uso de
 **qualquer espaço adicional.
 **/
void merge_inPlace(int vect[], int i,int m, int j,int n);



/** Ordena a região de vector[] compreendida entre bgn inclusive e end inclusive. **/
void mergeSort(int vector[], int bgn,int end) {
    if(bgn<end) {
        int middle = (bgn+end)/2;
        mergeSort(vector, bgn,middle);
        mergeSort(vector, middle+1,end);
        merge_inPlace(vector, bgn,middle, middle+1,end);
    }
}


/**
 ** Mescla as secções ordenadas [i,m] e [j,n] de vect[] numa só secção ordenada [i,n], sem uso de
 **qualquer espaço adicional.
 **/
void merge_inPlace(int vect[], int i,int m, int j,int n) {
 int temp; /* Variábil a se utilizar na transferência de valores entre os vectores. */
 int comp; /* Índice da secção do vector sendo comparada no algorithmo explicado abaixo. */

 while(i<=m) {              /* Porque, se o primeiro vector se acabar, o vector final estará já ordenado.*/
  if(vect[i]<=vect[j]) i++; /* Se o primeiro campo do primeiro vector é o menor, já está na posição correcta.*/

  /*
   * Agora a cousa fica interessante; se o elemento seguinte está no segundo vector, ele é trazido
   *para o início do primeiro vector, tornando-se o final da parte já ordenada. O elemento que era*
   *o primeiro desse vector é inserido no segundo, por meio de huma adaptação do
   *algorithmo do InsertionSort, que é especifica demais pera haver sua própria função.
   *
   * Façamo-lo!
   */
  else {
   temp = vect[i];       /* Backup do antigo elemento inicial do primeiro vector. */
   vect[i++] = vect[j];  /* Moção do menor dos elementos pera seu devido lugar. */

   /*
    * Agora algo que não sey se foy tentado antes; achey conceiptos similares, mas creio ter
    *inventado este méthodo de minha própria mente.
    *
    * O algorithmo usa a variável comp criada mais acima como índice, comparando o valor de temp
    *progressivamente com cada um dos elementos do segundo vector, a partir de j+1 rumo a n posicio-
    *nando-o em seu devido local.
    */

   comp = j+1;

   /*
    * Corre o vector, movendo elementos para a esquerda, até o local onde se deve inserir o
    *componente desejado.
    */
   while(comp<=n && temp>vect[comp]) {
    vect[comp-1] = vect[comp];
    comp++;
   }

   /* Insere o componente novo onde cabe. */
   vect[comp-1] = temp;
  }

 }
}

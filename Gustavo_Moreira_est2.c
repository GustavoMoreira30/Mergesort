#include <stdio.h>
#include<stdlib.h>
/*void merge(int barraca[], int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = barraca[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = barraca[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            barraca[k] = L[i];
            i++;
        }
        else
        {
            barraca[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        barraca[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        barraca[k] = R[j];
        j++;
        k++;
    }
}*/
void merge(int barracas[], int inicio)
{
    int i, j, k;
    int meio;
    int* tmp;

    tmp = (int*) malloc(inicio * sizeof(int));
    if(tmp == NULL){
        exit(1);
    }
    meio = inicio / 2;
    i = 0;
    j = meio;
    k = 0;

    while (i < meio && j < inicio)
    {
        if (barracas[i] < barracas[j])
        {
            tmp[k] = barracas[i];
            i++;
        }
        else
        {
            tmp[k] = barracas[j];
            j++;
        }
        ++k;
    }
    if (i == meio)
    {
        while( j < inicio)
        {
            tmp[k] = barracas[j];
            ++j;
            ++k;
        }
    }
    else
    {
        while (i < meio)
        {
            tmp[k] = barracas[i];
            ++i;
            ++k;
        }
        for( i =0; i < inicio; ++i){
            barracas[i] = tmp[i];
        }
    free(tmp);
    }
}
/*void mergeSort(int barraca[], int inicio, int fim)
{
    if (inicio < fim)
        return;
    int meio = inicio + (fim - inicio) / 2;
    mergeSort(barraca, inicio, meio);
    mergeSort(barraca, meio + 1, fim);
    merge(barraca, inicio, meio, fim);
}*/
int mergeSort(int barracas[], int inicio, int fim)
{
    int meio;
    if(inicio > fim){
    meio = inicio /2;
    mergeSort(barracas, inicio, meio);
    mergeSort(barracas, meio + 1, fim);
    merge(barracas, inicio);
    }
    return (fim+1);
}
void print(int *barracas, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%i", barracas[i]);
    }
    printf("]");
    printf("\n\n");
}
int main(void)
{
    int barracas[8] = {2, 0, 0, 3, 8, 7, 5, 0};
    int n = sizeof(barracas) / sizeof(int);

    printf(" ---- Exibindo as Barracas ---- \n\n");
    printf("barraca 0 = %d\n", barracas[0]);
    printf("barraca 1 = %d\n", barracas[1]);
    printf("barraca 2 = %d\n", barracas[2]);
    printf("barraca 3 = %d\n", barracas[3]);
    printf("barraca 5 = %d\n", barracas[4]);
    printf("barraca 6 = %d\n", barracas[5]);
    printf("barraca 7 = %d\n", barracas[6]);
    printf("barraca 8 = %d\n", barracas[7]);

    mergeSort(barracas, 0, n);
    /* print(barracas, n);
    mergeSort(barracas, 0, n);
    print(barracas, n);*/

    return 0;
}
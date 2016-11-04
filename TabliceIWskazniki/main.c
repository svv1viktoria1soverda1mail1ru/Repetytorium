#include <stdio.h>
#include <conio.h>
#define ROZ 100
int main()
{
    int i, nl, min,max;
    int tab[ROZ];
    printf("\nprogram szuka maksymalnej i minimalnej liczby w tablicy\n ");
    printf("Ile liczb calkowitych :");
    scanf("%d",&nl);
    printf("\nwprowadz n = %d danych\n",nl);
    for (i=0; i<nl; i++)
    {
        printf("liczba nr %3d = ",i+1);
        scanf("%d",tab+i); //uwaga na format !
    }
    max = min = *tab;
    for (i = 1; i<nl; i++)
    {
        if (*(tab + i) > max) max = *(tab+i);
        if (*(tab + i) < min) min = *(tab+i);
    }
    printf("\nmaksimum = %d , minimum = %d",max,min);
    getche();
    return 0;
}

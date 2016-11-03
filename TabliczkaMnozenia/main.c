#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Tabliczka mnozenia \n");
    int tab[11][11];
    int i,j;
    int liczba;
    for(i=1;i<11;i++)
    {
        for(j=1;j<11;j++)
        {
            tab[i][j]=i*j;
            liczba=tab[i][j];
            printf("%4d",liczba);
        }
        printf("\n");
    }

    return 0;
}

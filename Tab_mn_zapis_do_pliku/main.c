#include <stdio.h>
#include <stdlib.h>

int main()
{
 FILE *fp;
   if((fp=fopen("Tabl_mnozenia.txt","w"))==NULL)
   {
        printf("Błąd otwarcia pliku!\n");
        exit(1);
   }


    printf("Tabliczka mnozenia \n");
    fprintf(fp,"Tabliczka mnozenia \n");
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
            fprintf(fp,"%4d",liczba);
        }
        printf("\n");
        fprintf(fp,"\n");
    }
fclose(fp);
    return 0;
}

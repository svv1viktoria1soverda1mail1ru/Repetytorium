#include <stdio.h>
#include <stdlib.h>

int main()
{
/* sposoby otwarcia pliku - funkcja fopen()
"r" - czytanie
"r+" - czytanie i nadpisywanie (aktualizacja)
"w" - nadpisywanie (zamazuje stara tresc)
"w+" - nadpisywanie i czytanie
"a" - dopisywanie
"a+" - dopisywanie i odczyt
"t" - otwiera w trybie tekstowym
"b" - w trybie binarnym
  Litery mozna ze soba laczyc, np. "rwb"
*/
   //zapis pliku
   FILE *fp;
   char tekst[]="Mój pirwszy plik";
   if((fp=fopen("napis.txt","w"))==NULL)
   {
        printf("B³¹d otwarcia pliku!\n");
        exit(1);
   }
    fprintf(fp,"%s",tekst);
    fclose(fp);

    //odczyt pliku
/*
    typedef FILE *plik;
    plik fp1;
    int c;

    if ((fp1=fopen("napis1.txt","r"))==NULL)
    {
        perror("Bl¹d otwarcia pliku!\n");
        exit(1);
    }
    while(1)
    {
        c = fgetc(fp1);
        if(feof(fp1))
            break;
        printf("%c",c);

    }
    fclose(fp1);

    //strumienie

   // srdin - we
   // stdout - wy
   // stderr - errors

    fprintf(stdout,"\nWitaj! Wpisz swoj wiek\n");
    int wiek;
    fscanf(stdin,"%d",&wiek);
    fprintf(stdout,"%d\n",wiek);
    */
    return 0;
}

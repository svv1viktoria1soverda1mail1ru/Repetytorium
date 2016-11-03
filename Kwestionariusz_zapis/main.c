#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TRUE 1
#define ILOSC 100

void nowa_osoba(void);
void drukuj_liste(void);
void zwieksz_liste(void);
void info();
void sprawdzIleOsobJest();
typedef struct
{
    char imie[40];
    char nazwisko[40];
    char email[50];
    char adres[70];
    int telefon;

} Lista_osob;
Lista_osob *lista;
int n;
int rozmiar;
FILE *fp;
FILE *fp1;
int c;

int main()

{
    sprawdzIleOsobJest();
    info();
    char znak;
    printf("Ile osob chcesz wpisac? ");
    scanf("%d", &rozmiar);
    lista = (Lista_osob*)malloc((rozmiar+n+1) * sizeof(Lista_osob));
    while (TRUE)
    {
        printf("\n wybierz 'n' aby wprowadzic nowa osobe");
        printf("\n wybierz 'l' aby wydrukowac liste");
        printf("\n wybierz 'q' aby zakonczyc program");
        printf("\n wybor : ");
        znak = getche();
        switch (znak)
        {
        case 'n' :
            if(n==rozmiar) zwieksz_liste();
            nowa_osoba();
            break;
        case 'l' :
            drukuj_liste();
            break;
        case 'q' :
            exit(0);
        default :
            puts("\n wprowadz tylko n,l lub q");
        } // koniec instrukcji switch
    } // koniec petli while

    return 0;
}
void info(void)
{
    printf("Program tworzy liste osob. \n");
}
void nowa_osoba(void)
{
    if((fp=fopen("Osoby.txt","a"))==NULL)
    {
        printf("Blad otwarcia pliku!\n");
        exit(1);
    }
    char numstr [81];
    printf("\nOsoba nr %d ", n+1);
    fprintf(fp,"%2d .", n+1);
    printf("\npodaj imie : ");
    scanf("%s",lista[n].imie);
    fprintf(fp,"Imie : %s\n",lista[n].imie);
    printf("\npodaj nazwisko : ");
    scanf("%s",lista[n].nazwisko);
    fprintf(fp,"Nazwisko : %s\n",lista[n].nazwisko);
    printf("\npodaj email : ");
    scanf("%s",lista[n].email);
    fprintf(fp,"E-mail : %s\n",lista[n].email);
    printf("\npodaj adres : ");
    scanf("%s",lista[n].adres);
    fprintf(fp,"Adres : %s\n",lista[n].adres);
    printf("\npodaj telefon : ");
    scanf("%s",numstr);
    lista[n].telefon = atol(numstr);
    fprintf(fp,"Telefon : %d\n",lista[n].telefon);
    fprintf(fp,"-------------------------------\n");
    n++;
    fclose(fp);
}
void drukuj_liste(void)
{
    int j;
    if (n < 1) {printf("\n Lista jest pusta, zapisz kogos.");} else {
    typedef FILE *plik1;
    plik1 fp1;
    int c;

    if ((fp1=fopen("Osoby.txt","r"))==NULL)
    {
        perror("Blod otwarcia pliku!\n");
      //  exit(1);
    }
    printf("\n");
    while(1)
    {
        c = fgetc(fp1);
        if(feof(fp1))
            break;
        printf("%c",c);

    }
    fclose(fp1);
    }
}
void zwieksz_liste()
{
    lista=realloc(lista,2*(rozmiar+n)*sizeof(*lista));
}
void sprawdzIleOsobJest()
{
    FILE *fp1;
    int wiersz = 0;
    char znak;

    if ((fp1=fopen("Osoby.txt","r"))==NULL)
    {
     n=0;
    printf("Lista jest pusta!\n");
    }else{

    while((znak = getc(fp1)) != EOF)
    {
        if(znak == '\n')
            ++wiersz;
    }
    n=wiersz/6;
    printf("Plik zawiera %d osob\n", n);
    fclose(fp1);
    }
}



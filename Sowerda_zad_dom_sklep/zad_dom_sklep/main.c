#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
typedef struct Produkt
{

    char nazwa[100];
    char rodzaj[50];
    char opis[100];
    float cena;
    struct Produkt* next;
} Produkt ;
FILE *fp;

// zlicza dlugosc listy

int dlugosc_listy(Produkt* lista)
{
    int d = 0;
    Produkt* wsk = lista;
    while(wsk != NULL)
    {
        d++;
        wsk = wsk->next;
    }
    return d;
}

void dodaj(Produkt** lista, Produkt* nowy)
{
    while (*lista != NULL) lista = &((*lista)->next);
    *lista = nowy;
    nowy->next = NULL;
}

// dodaje produkt do listy
void dodajProdukt(Produkt** lista)
{
    Produkt* nowy = (Produkt*)malloc(sizeof(Produkt));
    printf("\n\nPodaj nazwe: ");
    scanf("%s", nowy->nazwa);

    printf("Podaj rodzaj: ");
    scanf("%s", nowy->rodzaj);

    printf("Podaj opis: " );
    scanf("%s", nowy->opis);

    printf("Podaj cene: " );
    scanf("%f", &(nowy->cena));

    dodaj(lista, nowy);
}

//Wypisuje cala liste
void wypisz_liste(Produkt* lista)
{
    Produkt* wsk = lista;
    if(lista == NULL)
        printf("LISTA JEST PUSTA");
    else {
        printf("Lista zawiera %d elementow: \n", dlugosc_listy(lista) );
        printf("%2s %15s %15s %15s %6s\n", "NR","NAZWA", "RODZAJ", "OPIS", "CENA");}
    int i = 1;
    while( wsk != NULL)
    {
        printf("%2d %15s %15s %15s %4.2f\n", i, wsk->nazwa, wsk->rodzaj, wsk->opis, wsk->cena);
        wsk=wsk->next;
        i++;
    }
}
//Usuwa element z listy
void usun(Produkt** lista, int ID)
{
    Produkt* poprzedni = NULL;
    Produkt* wsk = *lista;
    int i;
    for(i = 1; i < ID; i++)
    {
        poprzedni=wsk;
        wsk=wsk->next;

    }
    if(poprzedni==NULL)
    {
        (*lista)=(*lista)->next;
        free(wsk);
    }
    else
    {
        poprzedni->next=wsk->next;
        free(wsk);
    }
}

void modyfikuj(Produkt** lista, int ID)
{
    Produkt* wsk = *lista;
    int i;
    for(i = 1; i < ID; i++)
    {
        wsk=wsk->next;

    }
    printf("Podaj nowa nazwe: ");
    scanf("%s", wsk->nazwa);

    printf("Podaj nowy rodzaj: ");
    scanf("%s", wsk->rodzaj);

    printf("Podaj nowy opis: " );
    scanf("%s", wsk->opis);

    printf("Podaj nowa cene: " );
    scanf("%f", &(wsk->cena));

    printf("\nInformacja o produkcie zostala zmieniona na:\n%d %s %s %s %.2f\n", ID, wsk->nazwa, wsk->rodzaj, wsk->opis, wsk->cena);
}
void wypisz_produkt_lista(Produkt* lista, int ID)
{
    int i;
    Produkt* wsk = lista;
    for(i = 1; i < ID; i++)
    {
        wsk=wsk->next;

    }
    printf("%d %s %s %s %.2f\n", i, wsk->nazwa, wsk->rodzaj, wsk->opis, wsk->cena);
}

void usun_produkt(Produkt** lista)
{
    int ID;
    printf(" Podaj indeks produktu: " );
    scanf("%d", &ID);

    if((ID > dlugosc_listy(*lista)) || (ID < 1))
    {
        printf(" Nie ma takiego indeksu");

    }
    else
    {
        usun(lista,ID);
    }
}

void modyfikuj_produkt(Produkt** lista)
{
    int ID;
    printf(" Podaj indeks produktu: " );
    scanf("%d", &ID);

    if((ID > dlugosc_listy(*lista)) || (ID < 1))
    {
        printf(" Nie ma takiego indeksu");

    }
    else
    {
        printf("Wybrales do modyfikacji dany produkt:\n");
        wypisz_produkt_lista(*lista,ID);

        modyfikuj(lista,ID);
    }
}



//wypisz produkt o podanym indexie
void wypisz_produkt(Produkt* lista)
{
    int ID;

    printf("Podaj numer produktu: " );
    scanf("%d", &ID);

    if((ID > dlugosc_listy(lista)) || (ID < 1))
    {
        printf("Nie ma takiego indeksu");

    }
    else
        wypisz_produkt_lista(lista, ID);

}
void zapisz_zmiany(Produkt* lista)
{
    Produkt* wsk = lista;
    remove("Produkty.txt");
    if((fp=fopen("Produkty.txt","a"))==NULL)
    {
        printf("Blad otwarcia pliku!\n");
        exit(1);
    }
    int i = 1;
    while( wsk != NULL)
    {
        fprintf(fp,"%d\t%s\t%s\t%s\t%.2f\n", i, wsk->nazwa, wsk->rodzaj, wsk->opis, wsk->cena);
        wsk=wsk->next;
        i++;
    }
    fclose(fp);
}

int main()
{   remove("Produkty.txt");
    Produkt* lista=NULL;
    int option;
    while(option != 0)
    {
        printf("\n\n MENU");
        printf("\n\n\n 0 Wyjscie z programu");
        printf("\n 1 Dodaj produkt do bazy");
        printf("\n 2 Usun produkt o podanym indeksie");
        printf("\n 3 Modyfikuj dane produktu o podanym indeksie");
        printf("\n 4 Wyswietl informacje o produkcie o podanym indeksie");
        printf("\n 5 Wyswietl cala liste produktow\n");

        scanf("%d", &option);

        switch(option)
        {
        case 0:
            exit(0);

        case 1:
            printf("DODANIE PRODUKTU\n");
            printf(" -Ile produktow chcesz dodac? -  ");
            int k,j;
            scanf("%d",&k);
            for(j=1; j<=k; j++)
            {
                dodajProdukt(&lista);
                zapisz_zmiany(lista);
            }
            break;

        case 2:
            printf("USUWANIE PRODUKTU O PODANYM INDEKSIE\n");
            wypisz_liste(lista);
            usun_produkt(&lista);
            zapisz_zmiany(lista);
            break;
        case 3:
            printf("MODYFIKUJ INFORMACJE O PRODUKCIE O PODANYM INDEKSIE\n");
            wypisz_liste(lista);
            modyfikuj_produkt(&lista);
            zapisz_zmiany(lista);

            break;
        case 4:
            printf("WYSWIETL INFORMACJE O PRODUKCIE O PODANYM INDEKSIE\n");
            wypisz_produkt(lista);
            break;

        case 5:
            printf("WYSWIETL CALA BAZE\n");
            wypisz_liste(lista);
            break;
        default :
            printf("nie ma takiej opcji");
            break;
        }
    }
    int key;
    scanf("%d", &key);
    return 0;
}

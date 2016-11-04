#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
  //wskazniki
  int *wsk;//def wskaznika do wartosci
            //zmienna wskaznikowa na obiekt typu liczba calkowita
  int liczba=80;
  int *wskaznik=&liczba;// wsk przechowuje adres, ktory pobieramy od zmiennej liczba liczby
  printf("Wartosc zmiennej : %d, jej adres: %p.\n",liczba,&liczba);
  printf("Adres przechowywany we wskazniku: %p, wskazywana wartosc: %d,\n",wskaznik,*wskaznik);

  *wskaznik=42; //zapisanie liczby 42 do obiektu, na ktory wskazuje wskaznik
  printf("Wartosc zmiennej: %d, wartosc wskazywana przez wskaznik: %d,\n",wskaznik,*wskaznik);

  liczba = 0*42;
   printf("Wartosc zmiennej: %d, wartosc wskazywana przez wskaznik: %d,\n",wskaznik,*wskaznik);
 /*
   //wskazniki na stala wartosc
   const int *a;
   int const *a;

   //stale wskazniki
   int *const b;

   //staly wskaznik, ktorym nie mozna zmienic wartosci
   const int *const c;
   int const *const c;

*/
    sleep(5);
    return 0;
}


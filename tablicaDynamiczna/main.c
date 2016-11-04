#include <stdio.h>
#include <stdlib.h>

int main()
{
        int rozmiar;
        float *tablica;

        rozmiar=5;
        tablica=(float*)malloc(rozmiar * sizeof(*tablica));//pierwsza gwiazdka (*) w funkcji malloc() to operator mnozenia
        //tablica=(float*)calloc(rozmiar ,sizeof(*tablica));//zeruje wartosc przydzielonej pamieci
                                                                //(do wsz bajtow wpisuje wartosc zero)
    tablica[0]=0.4;
    tablica=realloc(tablica,2*rozmiar*sizeof(*tablica));//zmiana rozmiaru tablicy
    free(tablica);//zwalnia pamiec
    return 0;
}

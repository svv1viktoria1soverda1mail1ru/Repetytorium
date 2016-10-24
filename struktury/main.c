#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
    char marka[10];
    char color[10];
    int ilosc_drzwi;
}Samochod;

Samochod sam()
{
    Samochod sam1={"Audi","czarny",4};
    return sam1;

}



int main()
{
    Samochod sam1;
    sam1=sam();
    puts("Parametry samochodu:\n");
    printf("Marka: %s\n",sam1.marka);
    printf("Kolor: %s\n",sam1.color);
    printf("Ilosc drzwi: %s\n",sam1.ilosc_drzwi);
    sleep(3);
    return 0;
}

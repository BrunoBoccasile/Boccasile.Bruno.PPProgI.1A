#include <stdio.h>
#include <stdlib.h>
#define TAM 2

typedef struct
{
   int id;
   char procesador[20];
   char marca[20];
   float precio;
}Notebook;

float aplicarDescuento(float precioProducto);

int contarCaracteres(char cadena[], char caracter);

void ordenarNotebook(Notebook computadoras[]);

int main()
{
float precio = 100;

char string[20] = "Hola como estas";
char caracterBuscado = 'a';

Notebook compus[10];

int id[2] = {1000, 1001};
char procesador[2][20] = {"AMD Ryzen 5 3600", "Intel I5 7700"};
char marca[2][20] = {"MSI", "Lenovo"};
float precios[2] = {245000.5, 230100};

for(int i=0; i<TAM ; i++)
        {
            compus[i].id = id[i];

            strcpy(compus[i].procesador, procesador[i]);

            strcpy(compus[i].marca, marca[i]);

            compus[i].precio = precios[i];
        }


aplicarDescuento(precio);

contarCaracteres(string, caracterBuscado);

ordenarNotebook(compus);

for(int i=0; i<TAM ; i++)
{
    printf("%-4d | %-20s | %-20s |%-10f\n", compus[i].id, compus[i].procesador, compus[i].marca, compus[i].precio);
}


return 0;
}

float aplicarDescuento(float precioProducto)
{
    float precioConDescuento;
    float descuento;

    descuento = precioProducto * 0.05;

    precioConDescuento = precioProducto - descuento;

    return precioConDescuento;
}

int contarCaracteres(char cadena[], char caracter)
{
    int i= 0;
    int contadorCaracter = 0;

    while(cadena[i] != '\0')
    {
        if(cadena[i] == caracter)
        {
            contadorCaracter++;
        }
        i++;
    }

    return contadorCaracter;
}

void ordenarNotebook(Notebook computadoras[])
{
    Notebook auxComputadoras;

    for(int i = 0; i<TAM-1; i++)
        {
            for(int j = i+1; j<TAM; j++)
            {
                if((computadoras[i].marca > computadoras[j].marca)
                   ||(computadoras[i].marca == computadoras[j].marca) && computadoras[i].precio > computadoras[j].precio)
                {
                    auxComputadoras = computadoras[i];
                    computadoras[i] = computadoras[j];
                    computadoras[j] = auxComputadoras;
                }
            }
        }

}

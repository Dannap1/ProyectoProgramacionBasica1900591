// Avance.cpp : Avance 2, para mostrar el menú
//

#include <iostream>
#include <stdio.h>
#include<conio.h>
#include <string.h>
#include <string>
#include <wchar.h>
#include <cstring>
#include <cstringt.h>

using namespace std;

struct info
{
    int numero, lanzamiento;
    float precio, impuesto, total;
    string nombre, descripcion, genero, clasificacion, consola;
};

int main()
{
    info videojuegos[3];
    int opcion;

    do
    {
        printf("\n\n*** BIENVENIDO A TU JUEGO ONLINE ***\n\n");
        printf("*********************************\n");
        printf("             MENU                \n");
        printf("\n*********************************\n\n");
        printf("1.- Alta de articulo\n");
        printf("2.- Modificacion de articulo\n");
        printf("3.- Baja de articulo\n");
        printf("4.- Lista de articulos\n");
        printf("5.- Limpiar pantalla\n");
        printf("6.- Salir\n");
        printf("\nPor favor, ingrese una opcion\n");
        scanf_s("%d", opcion);
        switch (opcion)
        {
        case 1:
            for (int i = 0; i < 3; i++)
            {
                printf("\nNumero de articulo: "); scanf_s("%d", &videojuegos[i].numero);
                printf("Nombre del articulo: "); cin.ignore(); getline(cin, videojuegos[i].nombre);//cin.ignore(); - ayuda a ignorar el enter presionado del cin anterior para que el getline no lo tome en cuenta
                printf("Fecha de lanzamiento: "); scanf_s("%d", &videojuegos[i].lanzamiento);
                printf("Descripcion del articulo: "); cin.ignore(); getline(cin, videojuegos[i].descripcion);//getline - toma en cuenta como caracter al pasar espacio
                printf("Genero del articulo: "); getline(cin, videojuegos[i].genero);
                printf("Clasificacion del articulo: ");  getline(cin, videojuegos[i].clasificacion);
                printf("Consola en que se juega: "); cin.ignore(); getline(cin, videojuegos[i].consola);
                printf("Precio del articulo unitario: "); scanf_s("%f", &videojuegos[i].precio);
                videojuegos[i].impuesto = videojuegos[i].precio * 0.16;
                cout << "El impuesto del articulo es de: " << videojuegos[i].impuesto << " pesos\n";
                videojuegos[i].total = videojuegos[i].precio + videojuegos[i].impuesto;
                cout << "El costo total del articulo es de: " << videojuegos[i].total << " pesos\n";
            }
            break;
        case 2:
            return main();
            break;
        case 3:
            return main();
            break;
        case 4:
            for (int i = 0; i < 3; i++)
            {
                printf("\n\nNumero de articulo: %d", videojuegos[i].numero);
                printf("\nNombre del articulo: %s", videojuegos[i].nombre.c_str());
                printf("\nFecha de lanzamiento: ", "%d", videojuegos[i].lanzamiento);
                printf("\nDescripcion del articulo: %s", videojuegos[i].descripcion.c_str());
                printf("\nGenero del articulo: %s", videojuegos[i].genero.c_str());
                printf("\nClasificacion del articulo: %s", videojuegos[i].clasificacion.c_str());
                printf("\nConsola en que se juega: %s", videojuegos[i].consola.c_str());
                printf("\nPrecio del articulo unitario: %f", videojuegos[i].precio);
            }
            break;
        case 5:
            system("cls"); //limpia la pantalla
            return main();
            break;
        case 6:
            exit(1); // finaliza el programa
            break;
        default:
            return main();
            break;

        }
    } while (opcion != 6);
}


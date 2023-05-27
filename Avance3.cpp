// Avance.cpp : Avance 2, para mostrar el menú
//

#include <iostream>
#include <stdio.h>
#include<conio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Info
{
    int lanzamiento;
    float precio, impuesto, total;
    string nombre, descripcion, genero, clasificacion, consola, status;
};
int contador, alta;

Info* videojuegos;

void Alta();
void lista();
void modificar();
void eliminar();
void archivos();

int main()
{
    int opc1;

        printf("\n\n*** BIENVENIDO A TU JUEGO ONLINE ***\n\n");
        printf("*********************************\n");
        printf("             MENU                \n");
        printf("\n*********************************\n\n");
        printf("1.- Alta de articulos\n");
        printf("2.- Lista de articulos\n");
        printf("3.- Modificacion de articulos\n");
        printf("4.- Baja de articulos\n");
        printf("5.- Limpiar pantalla\n");
        printf("6.- Salir\n");
        printf("\nPor favor, ingrese una opcion\n");
        cin >> opc1;
        switch (opc1)
        {
        case 1:
            Alta();
            return main();
            break;

        case 2:
            lista();
            return main();
            break;
        case 3:
            modificar();
            return main();
            break;
        case 4:
            eliminar();
            break;
        case 5:
            system("cls"); //limpia la pantalla
            return main();
            break;
        case 6:
            archivos();
            break;
        default:
            return main();
            break;

        }
}

void Alta()
{
    printf("Ingrese el numero de articulos que desee dar de alta \n");
    scanf_s("%d", &alta);
    videojuegos = new Info[alta];
    for (int i = 0; i < alta; i++)
    {
        //printf("\nNumero de articulo: "); scanf_s("%d", &videojuegos[i].numero);
        printf("\nNombre del articulo: "); cin.ignore(); getline(cin, videojuegos[i].nombre);//cin.ignore(); - ayuda a ignorar el enter presionado del cin anterior para que el getline no lo tome en cuenta
        printf("Fecha de lanzamiento: "); scanf_s("%d", &videojuegos[i].lanzamiento);
        printf("Descripcion del articulo: "); cin.ignore(); getline(cin, videojuegos[i].descripcion);//getline - toma en cuenta como caracter al pasar espacio
        printf("Genero del articulo: "); getline(cin, videojuegos[i].genero);
        printf("Clasificacion del articulo: ");  getline(cin, videojuegos[i].clasificacion);
        printf("Consola en que se juega: "); getline(cin, videojuegos[i].consola);
        printf("Precio del articulo unitario: "); scanf_s("%f", &videojuegos[i].precio);
        videojuegos[i].impuesto = videojuegos[i].precio * 0.16;
        cout << "El impuesto del articulo es de: " << videojuegos[i].impuesto << " pesos\n";
        videojuegos[i].total = videojuegos[i].precio + videojuegos[i].impuesto;
        cout << "El costo total del articulo es de: " << videojuegos[i].total << " pesos\n";
    }
}

//void lista()
//{
//    for (int i = 0; i < alta; i++)
//    {
//        if (videojuegos[i].status == "ELIMINADO")
//        {
//            printf("ARTICULO ELIMINADO");
//            i + 1;
//        }
//        else
//        {
//            printf("\nArticulo %d", i + 1);
//            printf("\nNombre del articulo: %s", videojuegos[i].nombre.c_str());
//            printf("\nFecha de lanzamiento: %d", videojuegos[i].lanzamiento);
//            printf("\nDescripcion del articulo: %s", videojuegos[i].descripcion.c_str());
//            printf("\nGenero del articulo: %s", videojuegos[i].genero.c_str());
//            printf("\nClasificacion del articulo: %s", videojuegos[i].clasificacion.c_str());
//            printf("\nConsola en que se juega: %s", videojuegos[i].consola.c_str());
//            printf("\nPrecio del articulo unitario: %f", videojuegos[i].precio);
//            printf("\nEl impuesto del articulo es de: %f", videojuegos[i].impuesto," pesos");
//            printf("\nEl costo total del articulo es de: %f", videojuegos[i].total, " pesos");
//        }
//    }
//}

void lista()
{
    string genero, consola;
    printf("\nFiltrar por genero (deje en blanco para ignorar): ");
    cin.ignore();
    getline(cin, genero);
    printf("Filtrar por consola (deje en blanco para ignorar): ");
    getline(cin, consola);

    bool filtroGenero = !genero.empty();
    bool filtroConsola = !consola.empty();

    for (int i = 0; i < alta; i++)
    {
        if (videojuegos[i].status == "ELIMINADO")
        {
            printf("ARTICULO ELIMINADO\n");
        }
        else if ((filtroGenero && videojuegos[i].genero != genero) || (filtroConsola && videojuegos[i].consola != consola))
        {
            // El artículo no coincide con los filtros, se omite
            continue;
        }
        else
        {
            printf("\nArticulo %d", i + 1);
            printf("\nNombre del articulo: %s", videojuegos[i].nombre.c_str());
            printf("\nFecha de lanzamiento: %d", videojuegos[i].lanzamiento);
            printf("\nDescripcion del articulo: %s", videojuegos[i].descripcion.c_str());
            printf("\nGenero del articulo: %s", videojuegos[i].genero.c_str());
            printf("\nClasificacion del articulo: %s", videojuegos[i].clasificacion.c_str());
            printf("\nConsola en que se juega: %s", videojuegos[i].consola.c_str());
            printf("\nPrecio del articulo unitario: %f", videojuegos[i].precio);
            printf("\nEl impuesto del articulo es de: %f", videojuegos[i].impuesto);
            printf("\nEl costo total del articulo es de: %f", videojuegos[i].total);
        }
    }
}

void modificar()
{
    int j, opc, opc2;
    do
    {
        printf("Ingrese que numero del articulo que desea modificar: ");
        cin>>j;
        j = j - 1;

        for (int i = j; i == j; i++)
        {
            if ((videojuegos[i].status == "ELIMINADO"))
            {
                printf("ARTICULO ELIMINADO", i + 1);
                printf("\nIngrese un articulo valido\n");
                opc2 = 1;
            }
            else
            {
                opc2 = 2;
            }
        }
    } while (opc2 == 1);
    printf("Ingrese la opcion que desee modificar\n1.-Nombre del articulo\n2.-Fecha de lanzamiento\n3.-Descripcion del articulo\n4.-Genero del articulo\n5.-Clasificacion del articulo\n6.-Consola en que se juega\n7.-Precio del articulo unitario\n");
    cin>>opc;

    switch (opc)
    {
    case 1:
        for (int i = j; i == j; i++)
        {
            printf("Nombre del articulo: "); cin.ignore(); getline(cin, videojuegos[i].nombre);
        }
        break;
    case 2:
        for (int i = j; i == j; i++)
        {
            printf("Fecha de lanzamiento: "); scanf_s("%d", &videojuegos[i].lanzamiento);
        }
        break;
    case 3:
        for (int i = j; i == j; i++)
        {
            printf("Descripcion del articulo: "); cin.ignore(); getline(cin, videojuegos[i].descripcion);
        }
        break;
    case 4:
        for (int i = j; i == j; i++)
        {
            printf("Genero del articulo: "); getline(cin, videojuegos[i].genero);
        }
        break;
    case 5:
        for (int i = j; i == j; i++)
        {
            printf("Clasificacion del articulo: ");  getline(cin, videojuegos[i].clasificacion);
        }
        break;
    case 6:
        for (int i = j; i == j; i++)
        {
            printf("Consola en que se juega: "); cin.ignore(); getline(cin, videojuegos[i].consola);
        }
        break;
    case 7:
        for (int i = j; i == j; i++)
        {
            printf("Precio del articulo unitario: "); scanf_s("%f", &videojuegos[i].precio);
        }
        break;
    }
}

void eliminar()
{
    int j;
    printf("\nIngrese el numero de articulo que desea eliminar: ");
    cin>>j;
    j = j - 1;
    for (int i = j; i == j; i++)
    {
        printf("\nARTICULO ELIMINADO ");
        printf("%d", j + 1);
        videojuegos[i].status = "ELIMINADO";
    }
}

void archivos()
{
    ofstream archivo;
    string nombrearchivo;
    int texto;
    string texto2;
    float texto3;

    nombrearchivo = "altasvideojuegos.txt";

    archivo.open(nombrearchivo.c_str(), ios::out);
    if (archivo.fail())
    {
        printf("ERROR AL CREAR EL ARCHIVO");
        exit(1);
    }
    
    archivo << "NOMBRE" << "\t";
    archivo << "FECHA DE LANZAMIENTO" << "\t";
    archivo << "DESCRIPCION" << "\t";
    archivo << "GENERO" << "\t";
    archivo << "CLASIFICACION" << "\t";
    archivo << "CONSOLA" << "\t";
    archivo << "PRECIO" << "\t";

    for (int i = 0; i < alta; i++)
    {
        if (videojuegos[i].status == "ELIMINADO")
        {
            texto2 = "ARTICULO ELIMINADO";
            texto = i;
            archivo << texto2 << texto << "\n";
        }
        else
        {
            texto2 = videojuegos[i].nombre;
            archivo <<"\n" << texto2 << "\n" << "\t";
            texto = videojuegos[i].lanzamiento;
            archivo << texto << "\t";
            texto2 = videojuegos[i].descripcion;
            archivo << texto2 << "\t";
            texto2 = videojuegos[i].genero;
            archivo << texto2 << "\t";
            texto2 = videojuegos[i].clasificacion;
            archivo << texto2 << "\t";
            texto2 = videojuegos[i].consola;
            archivo << texto2 << "\t";
            texto3 = videojuegos[i].precio;
            archivo << texto3 << "\t";

        }
    }
    archivo.close();
}
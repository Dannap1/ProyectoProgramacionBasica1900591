// Avance.cpp : Avance 1, para mostrar el menú
//

#include <iostream>
using namespace std;

int main()
{
    //declaración de variables
    int opcion, decision, numero, lanzamiento;
    float precio, impuesto, total;
    char nombre[25], descripcion[25], genero[10], clasificacion[5],consola[15];

    cout << "*** BIENVENIDO A TU JUEGO ONLINE ***\n\n";
    cout << "*********************************\n";
    cout << "             MENU                \n";
    cout << "\n*********************************\n\n";
    cout << "1.- Alta de articulo\n";
    cout << "2.- Modificacion de articulo\n";
    cout << "3.- Baja de articulo\n";
    cout << "4.- Lista de articulos\n";
    cout << "5.- Limpiar pantalla\n";
    cout << "6.- Salir\n";
    cout << "\nPor favor, ingrese una opcion\n";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        cout << "\nNumero de articulo: "; cin >> numero;
        cout << "Nombre del articulo: "; cin.ignore(); cin.getline(nombre, 25, '\n');//cin.ignore(); - ayuda a ignorar el enter presionado del cin anterior para que el getline no lo tome en cuenta
        cout << "Fecha de lanzamiento: "; cin >> lanzamiento;
        cout << "Descripcion del articulo: "; cin.ignore(); cin.getline(descripcion, 25,'\n');//cin.getline - toma en cuenta como caracter al pasar espacio
        cout << "Genero del articulo: "; cin >> genero;
        cout << "Clasificacion del articulo: ";  cin >> clasificacion;
        cout << "Consola en que se juega: "; cin.ignore(); cin.getline(consola,15,'\n');
        cout << "Precio del articulo unitario: "; cin >> precio;
        impuesto = precio * 0.16;
        cout << "El impuesto del articulo es de: " << impuesto << " pesos\n";
        total = precio + impuesto;
        cout << "El costo total del articulo es de: " << total << " pesos\n";
        cout << "\n Desea agregar otro articulo?\n1.- Si\n2.- No\n"; cin.ignore(); cin >> decision;
        if (decision == 1)
        {
            return main();
        }

        break;
    case 2:
        return main();
        break;
    case 3:
        return main();
        break;
    case 4:
        return main();
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
}



#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void agregar();
void borrar();


int main() {
    int opcion;
    do {
        cout << "Opciones del CRUD" << endl;
        cout << "-----------------" << endl;
        cout << "1. Agregar registro" << endl;
        cout << "2. Leer registros" << endl;
        cout << "3. Actualizar registro" << endl;
        cout << "4. Borrar registro" << endl;
        cout << "5. Consultar registro" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: agregar(); break;
            case 2: break;
            case 3: break;
            case 4: borrar(); break;
            case 5:  break;
            case 0: cout << "Saliendo..." << endl; break;
            default: cout << "Opción no válida" << endl;
        }
    } while(opcion != 0);

    return 0;
}

void agregar() {
    int cuenta;
    char nombre[20];
    float saldo;
    FILE *fp = fopen("credito.txt", "a");
    
    if (fp == NULL) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    cout << "Ingrese número de cuenta: ";
    cin >> cuenta;
    cout << "Ingrese nombre: ";
    cin >> nombre; // Lee el nombre directamente
    cout << "Ingrese saldo: ";
    cin >> saldo;

    fprintf(fp, "%d %s %.2f\n", cuenta, nombre, saldo);
    fclose(fp);
    cout << "Registro agregado exitosamente." << endl;
}

void borrar() {
    int cuenta, cuentaBorrar;
    char nombre[20];
    float saldo;
    bool encontrado = false;

    FILE *fp = fopen("credito.txt", "r+");
    if (!fp) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    cout << "Ingrese número de cuenta a borrar: ";
    cin >> cuentaBorrar;

    while (fscanf(fp, "%d %19s %f", &cuenta, nombre, &saldo) != EOF) {
        if (cuenta != cuentaBorrar) {
            fprintf(fp, "%d %s %.2f\n", cuenta, nombre, saldo);
        } else {
            encontrado = true;
        }
    }

    fclose(fp);


    if (encontrado) {
        cout << "Registro borrado exitosamente." << endl;
    } else {
        cout << "Registro no encontrado." << endl;
    }
}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

struct Fecha {
    int dia;
    int mes;
    int year;
};

struct Paquete {
    int id;
    char nombre[50];
    char descripcion[100];
    char origen[50];
    char destino[50];
    char remitente[50];
    Fecha fecha_actual;
    Fecha fecha_entrega;
};

Paquete* paquetes[100];
int paqueteCount = 0;

void Menu();
void Agregar_Paquetes();
void Borrar_Paquetes();
void Actualizar_Paquetes();
void Buscar_PaquetesID();
void Buscar_PaquetesN();
void Buscar_PaquetesR();
void Historial_No();
void Historial_Si();
void Detalles_Paquete_No();
void Detalles_Paquete_Si();
void Iniciar_Sesion();
void Registrar_Usuario();
void Cambiar_Password();

int main() {
    int opc1;    
    cout << "InterPack \n";
    cout << "''''''''''''''''''''\n"; 
    cout << "Menu De Opciones\n";
    cout << "1) Iniciar Sesion\n";
    cout << "2) Registrar Sesion\n";
    cout << "3) Salir\n";
    cin >> opc1;

    switch (opc1)
    {
    case 1:
        Menu();
        break;
    case 2:
        Registrar_Usuario();
        break;
    case 3:
        return 0;
    default:
        break;
    }
    
    return 0;
}

void Menu(){
    int opc;
    while (opc != 9)
    {
        cout << "InterPack \n";
        cout << "''''''''''''''''''''\n"; 
        cout << "Menu De Opciones\n";
        cout << "1) Agregar Nuevo Paquete\n";
        cout << "2) Borrar Paquete\n";
        cout << "3) Actualizar Paquete\n";
        cout << "4) Buscar Paquetes\n";
        cout << "5) Historial de Paquetes\n";
        cout << "6) Detalle de paquetes\n";
        cout << "7) Registrar Usuario\n";
        cout << "8) Ajustes\n";
        cout << "9) Salir\n";
        cin >> opc;

        switch (opc)
        {
        case 1:
            Agregar_Paquetes();
            break;
        case 2:
            Borrar_Paquetes();
            break;
        case 3:
            Actualizar_Paquetes();
            break;
        case 4:
            int busqueda;
            cout << "1) Buscar por ID\n";
            cout << "2) Buscar por Nombre\n";
            cout << "3) Buscar por Remitente\n";
            cin >> busqueda;
            switch (busqueda) {
                case 1:
                    Buscar_PaquetesID();
                    break;
                case 2:
                    Buscar_PaquetesN();
                    break;
                case 3:
                    Buscar_PaquetesR();
                    break;
                default:
                    cout << "Opcion invalida\n";
                    break;
            }
            break;
        case 5:
            int historial;
            cout << "1) Historial No Entregados\n";
            cout << "2) Historial Entregados\n";
            cin >> historial;
            switch (historial) {
                case 1:
                    Historial_No();
                    break;
                case 2:
                    Historial_Si();
                    break;
                default:
                    cout << "Opcion invalida \n";
                    break;
            }
            break;
        case 6:
            int detalles;
            cout << "1) Detalle No Entregados \n";
            cout << "2) Detalle Entregados \n";
            cin >> detalles;
            switch (detalles) {
                case 1:
                    Detalles_Paquete_No();
                    break;
                case 2:
                    Detalles_Paquete_Si();
                    break;
                default:
                    cout << "Opcion invalida \n";
                    break;
            }
            break;
        case 7:
            Registrar_Usuario();
            break;
        case 8:
            Cambiar_Password();
            break;
        case 9:
            return;
        default:
            cout << "Opcion invalida\n";
            break;
        }
    }
}

void ObtenerFechaActual(Fecha &fecha) {
    time_t t = time(0);
    struct tm *now = localtime(&t);
    fecha.dia = now->tm_mday;
    fecha.mes = now->tm_mon + 1;
    fecha.year = now->tm_year + 1900;
}

void Agregar_Paquetes() {
    Paquete* nuevoPaquete = new Paquete;
    nuevoPaquete->id = paqueteCount + 1;  

    cout << "Ingrese un nombre al paquete: ";
    cin >> nuevoPaquete->nombre;
    cout << "Ingrese descripcion del paquete: ";
    cin >> nuevoPaquete->descripcion;
    cout << "Ingrese origen del paquete: ";
    cin >> nuevoPaquete->origen;
    cout << "Ingrese destino del paquete: ";
    cin >> nuevoPaquete->destino;
    cout << "Ingrese remitente del paquete: ";
    cin >> nuevoPaquete->remitente;

    ObtenerFechaActual(nuevoPaquete->fecha_actual);


    cout << "Ingrese la fecha de entrega (dd mm aaaa): ";
    cin >> nuevoPaquete->fecha_entrega.dia >> nuevoPaquete->fecha_entrega.mes >> nuevoPaquete->fecha_entrega.year;

    
    paquetes[paqueteCount] = nuevoPaquete;

    paqueteCount++;
    cout << "Paquete agregado exitosamente con ID " << nuevoPaquete->id << ".\n";
}

bool FechaMenorIgual(Fecha fecha1, Fecha fecha2) {
    if (fecha1.year < fecha2.year) return true;
    if (fecha1.year > fecha2.year) return false;
    if (fecha1.mes < fecha2.mes) return true;
    if (fecha1.mes > fecha2.mes) return false;
    if (fecha1.dia <= fecha2.dia) return true;
    return false;
}

void Actualizar_Paquetes() {
    if (paqueteCount == 0) {
        cout << "No se encontró ningún paquete.\n";
        return;
    }

    Fecha fechaActual;
    ObtenerFechaActual(fechaActual);

    cout << "Lista de paquetes:\n";
    for (int i = 0; i < paqueteCount; i++) {
        Paquete* paquete = paquetes[i];
        cout << "ID: " << paquete->id << "\n"
             << ", Nombre: " << paquete->nombre << "\n"
             << ", Descripcion: " << paquete->descripcion << "\n"
             << ", Origen: " << paquete->origen << "\n"
             << ", Destino: " << paquete->destino << "\n"
             << ", Remitente: " << paquete->remitente << "\n";
        
        cout << "Fecha de Entrega: " << paquete->fecha_entrega.dia << "/"
             << paquete->fecha_entrega.mes << "/" << paquete->fecha_entrega.year << "\n";
        
        if (FechaMenorIgual(paquete->fecha_entrega, fechaActual)) {
            cout << "El paquete ha llegado.\n";
        } else {
            cout << "El paquete no ha llegado.\n";
        }
    }
    
}


void Borrar_Paquetes() {
    if (paqueteCount == 0) {
        cout << "No se encontró ningún paquete.\n";
        return;
    }

    cout << "Lista de paquetes:\n";
    for (int i = 0; i < paqueteCount; i++) {
        cout << "ID: " << paquetes[i]->id 
             << ", Nombre: " << paquetes[i]->nombre 
             << ", Descripcion: " << paquetes[i]->descripcion 
             << ", Origen: " << paquetes[i]->origen 
             << ", Destino: " << paquetes[i]->destino 
             << ", Remitente: " << paquetes[i]->remitente << "\n";
    }

    int idEliminar;
    cout << "Ingrese ID del paquete que desea eliminar: ";
    cin >> idEliminar;

    bool encontrado = false;
    for (int i = 0; i < paqueteCount; i++) {
        if (paquetes[i]->id == idEliminar) {
            encontrado = true;
            cout << "¿Está seguro que desea eliminar el paquete? (s/n): ";
            char confirmacion;
            cin >> confirmacion;
            if (confirmacion == 's' || confirmacion == 'S') {
                delete paquetes[i];
                for (int j = i; j < paqueteCount - 1; j++) {
                    paquetes[j] = paquetes[j + 1];
                }
                paqueteCount--;
                cout << "Paquete eliminado exitosamente.\n";
            } else {
                cout << "Eliminación cancelada.\n";
            }
            break;
        }
    }
    if (!encontrado) {
        cout << "Paquete no encontrado.\n";
    }
}

void Historial_No() {
    
}
void Historial_Si() {

}


void Buscar_PaquetesID() {}
void Buscar_PaquetesN() {}
void Buscar_PaquetesR() {}
void Detalles_Paquete_No() {}
void Detalles_Paquete_Si() {}
void Iniciar_Sesion() {}
void Registrar_Usuario() {}
void Cambiar_Password() {}

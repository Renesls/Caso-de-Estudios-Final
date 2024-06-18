#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Paquete {
    int id;
    char nombre[50];
    char descripcion[100];
    char origen[50];
    char destino[50];
    char remitente[50];
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
    cout << "''''''''''''''''''\n"; 
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
        cout << "''''''''''''''''''\n"; 
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
            int bsq;
            system("cls");
            cout << "Desea Buscar el Paquete por:\n";
            cout << "1) Paquete Por ID\n";
            cout << "2) Paquete Por Nombre\n";
            cout << "3) Paquete Por Remitente\n";
            cout << "4) Salir";
            cin >> bsq;
            switch (bsq)
            {
            case 1:
                Buscar_PaquetesID();
                break;
            case 2:
                Buscar_PaquetesN();
                break;
            case 3:
                Buscar_PaquetesR();
                break;
            case 4:
                main();
                break;                
            default:
                break;
            }
            break;
        case 5:
            int Hist;
            system("cls");
            cout << "Historial de paquetes:\n";
            cout << "1) Paquetes Entregados\n";
            cout << "2) Paquetes No Entregados\n";
            cout << "3) Salir\n";
            cin >> Hist;
            switch (Hist)
            {
            case 1:
                Historial_Si();
                break;
            case 2:
                Historial_No();
                break;
            case 3:
                main();
                break;    
            default:
                break;
            }
            break;

        case 6:
            int Dtl;
            system("cls");
            cout << "Detalles de Paquetes:\n";
            cout << "1) Paquetes Entregados:\n";
            cout << "2) Paquetes No Entregados:\n";
            cout << "3) Salir";
            cin >> Dtl;
            switch (Dtl)
            {
            case 1:
                Detalles_Paquete_No();
                break;
            case 2:
                Detalles_Paquete_Si();
                break;
            case 3:
                main();
                break;        
            default:
                break;
            }
            break;
        case 7:
            Registrar_Usuario();
            break;
        case 8:
            int Set;
            system("cls");
            cout << "Ajustes:\n";
            cout << "1) Cambiar Password:\n";
            cout << "2) Info del app:\n";
            cout << "3) Salir";
            cin >> Set;
            switch (Set)
            {
            case 1:
                Cambiar_Password();
                break;
            case 2:
                
                break;
            case 3:
                main();
                break;                
            default:
                break;
            }
            break;
        case 9:
            exit(0);
            break;                        
        default:
            break;
        }
    }
}

void Agregar_Paquetes() {
    Paquete* nuevoPaquete = new Paquete;
    nuevoPaquete->id = paqueteCount + 1;  

    cout << "Ingrese nombre del paquete: ";
    cin >> nuevoPaquete->nombre;
    cout << "Ingrese descripcion del paquete: ";
    cin >> nuevoPaquete->descripcion;
    cout << "Ingrese origen del paquete: ";
    cin >> nuevoPaquete->origen;
    cout << "Ingrese destino del paquete: ";
    cin >> nuevoPaquete->destino;
    cout << "Ingrese remitente del paquete: ";
    cin >> nuevoPaquete->remitente;

    paquetes[paqueteCount] = nuevoPaquete;
    paqueteCount++;
    cout << "Paquete agregado exitosamente con ID " << nuevoPaquete->id << ".\n";
}

void Borrar_Paquetes() {
    if (paqueteCount == 0) {
        cout << "No se encontró ningún paquete.\n";
        Menu();
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


void Actualizar_Paquetes(){}
void Buscar_PaquetesID(){}
void Buscar_PaquetesN(){}
void Buscar_PaquetesR(){}
void Historial_No(){}
void Historial_Si(){}
void Detalles_Paquete_No(){}
void Detalles_Paquete_Si(){}
void Iniciar_Sesion(){}
void Registrar_Usuario(){

char usuario [50];
char password [50];
int edad;
char nombre [50];
FILE * ptrf;

if ((ptrf = fopen("archivo.dat", "w"))== NULL){
    printf("\nEl archivo no pudo ser abierto/creado");
}else{
   printf("Ingrese un nuevo usuario");
   scanf("%s", usuario);
   printf("Ingrese su password");
   scanf("s", password);
   printf("Ingrese su nombre");
   scanf("s", nombre);
   printf("Ingrese su edad");
   scanf("d", edad);
}


}
void Cambiar_Password(){}

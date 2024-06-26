#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

struct Paquete {
    int id = 0;
    char nombre[50];
    char descripcion[100];
    char origen[50];
    char destino[50];
    char remitente[50];
    int lastId = 0;
    char Fecha_Entrega[11]; 

};

struct Sesion{
    char usuario [50];
    char password [50];
    int edad;
    char nombre [50];
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
    Paquete paquete; 
    FILE *AgregarPaquete;
    FILE *IdFile;

    IdFile = fopen("ID.txt", "r");
    if (IdFile != NULL) {
        fscanf(IdFile, "%d", &paquete.lastId);
        fclose(IdFile);
    }

    paquete.id = paquete.lastId + 1; 

    AgregarPaquete = fopen("archivo.txt", "a"); 
    if (AgregarPaquete == NULL) {
        printf("\nEl archivo no pudo ser abierto/creado\n");
    } else {
        printf("Ingrese el nombre del paquete: \n");
        getchar(); 
        fgets(paquete.nombre, sizeof(paquete.nombre), stdin);
        paquete.nombre[strcspn(paquete.nombre, "\n")] = 0;
        fprintf(AgregarPaquete, "ID: %d\nNombre: %s\n", paquete.id, paquete.nombre);
        
        printf("Ingrese la descripcion del paquete: \n");
        fgets(paquete.descripcion, sizeof(paquete.descripcion), stdin);
        paquete.descripcion[strcspn(paquete.descripcion, "\n")] = 0;
        fprintf(AgregarPaquete, "Descripcion: %s\n", paquete.descripcion);
        
        printf("Ingrese el origen del paquete: \n");
        fgets(paquete.origen, sizeof(paquete.origen), stdin);
        paquete.origen[strcspn(paquete.origen, "\n")] = 0;
        fprintf(AgregarPaquete, "Origen: %s\n", paquete.origen);
        
        printf("Ingrese el destino del paquete: \n");
        fgets(paquete.destino, sizeof(paquete.destino), stdin);
        paquete.destino[strcspn(paquete.destino, "\n")] = 0;
        fprintf(AgregarPaquete, "Destino: %s\n", paquete.destino);
        
        printf("Ingrese el remitente del paquete: \n");
        fgets(paquete.remitente, sizeof(paquete.remitente), stdin);
        paquete.remitente[strcspn(paquete.remitente, "\n")] = 0;
        fprintf(AgregarPaquete, "Remitente: %s\n", paquete.remitente);

        printf("Ingrese la fecha de entrega (yyyy-mm-dd): \n");
        fgets(paquete.Fecha_Entrega, sizeof(paquete.Fecha_Entrega), stdin);
        paquete.Fecha_Entrega[strcspn(paquete.Fecha_Entrega, "\n")] = 0;
        fprintf(AgregarPaquete, "Fecha de Entrega: %s\n", paquete.Fecha_Entrega);
       
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        char fechaActual[11];
        snprintf(fechaActual, sizeof(fechaActual), "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

        
        if (strcmp(paquete.Fecha_Entrega, fechaActual) > 0) {
            printf("El paquete no ha sido entregado\n");
        } else {
            printf("El paquete ha sido entregado\n");
        }

        printf("Paquete agregado exitosamente con ID: %d\n", paquete.id);

        fclose(AgregarPaquete);

        IdFile = fopen("ID.txt", "w");
        if (IdFile != NULL) {
            fprintf(IdFile, "%d", paquete.id);
            fclose(IdFile);
        }
    }
}




void Borrar_Paquetes() {
    int idBorrar;
    char confirmacion;

    FILE *archivo;
    FILE *temporal;
    Paquete paquete;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char fechaActual[11];
    snprintf(fechaActual, sizeof(fechaActual), "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    archivo = fopen("archivo.txt", "r");
    temporal = fopen("temp.txt", "w");

    if (archivo == NULL || temporal == NULL) {
        printf("Error al abrir el archivo o crear el archivo temporal.\n");
        return;
    }

    // Mostrar lista de paquetes
    printf("Lista de paquetes:\n");
    printf("---------------------------------------\n");

    while (fscanf(archivo, "ID: %d\nNombre: %[^\n]\nDescripcion: %[^\n]\nOrigen: %[^\n]\nDestino: %[^\n]\nRemitente: %[^\n]\nFecha de Entrega: %[^\n]\n", 
                  &paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega) != EOF) {
        printf("ID: %d\n", paquete.id);
        printf("Nombre: %s\n", paquete.nombre);
        printf("Descripcion: %s\n", paquete.descripcion);
        printf("Origen: %s\n", paquete.origen);
        printf("Destino: %s\n", paquete.destino);
        printf("Remitente: %s\n", paquete.remitente);
        printf("Fecha de Entrega: %s\n", paquete.Fecha_Entrega);

        if (strcmp(paquete.Fecha_Entrega, fechaActual) > 0) {
            printf("El paquete aun no ha sido entregado\n");
        } else {
            printf("El paquete ya ha sido entregado\n");
        }

        printf("---------------------------------------\n");
    }

    fclose(archivo);

    printf("Ingrese el ID del paquete que desea borrar: ");
    cin >> idBorrar;
    cin.ignore(); 
    printf("¿Está seguro de eliminar el paquete con ID %d? (s/n): ", idBorrar);
    cin >> confirmacion;
    cin.ignore(); 

    if (confirmacion == 's' || confirmacion == 'S') {
        archivo = fopen("archivo.txt", "r");

        while (fscanf(archivo, "ID: %d\nNombre: %[^\n]\nDescripcion: %[^\n]\nOrigen: %[^\n]\nDestino: %[^\n]\nRemitente: %[^\n]\nFecha de Entrega: %[^\n]\n", 
                      &paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega) != EOF) {
            if (paquete.id != idBorrar) {
                fprintf(temporal, "ID: %d\n", paquete.id);
                fprintf(temporal, "Nombre: %s\n", paquete.nombre);
                fprintf(temporal, "Descripcion: %s\n", paquete.descripcion);
                fprintf(temporal, "Origen: %s\n", paquete.origen);
                fprintf(temporal, "Destino: %s\n", paquete.destino);
                fprintf(temporal, "Remitente: %s\n", paquete.remitente);
                fprintf(temporal, "Fecha de Entrega: %s\n", paquete.Fecha_Entrega);
            } else {
                printf("Paquete con ID %d eliminado.\n", idBorrar);
            }
        }

        fclose(archivo);
        fclose(temporal);

        remove("archivo.txt");
        rename("temp.txt", "archivo.txt");
    } else {
        printf("Operación de eliminación cancelada.\n");
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

void Iniciar_Sesion(){

   char usuario1 [50];
   char password1 [50];
   bool encontrado = false;
   file * ptrf;

   if ((ptrf = fopen("usuarios.edad", "r")) == NULL){
    printf ("El archivo no puede ser abierto/creado");
   }
   else
   {
    printf("Ingrese su usuario");
    scanf("%50s"usuario1);
    printf("Ingrese su password");
    scanf("%50s"password1);

    while(!feof(ptrf)){
      fscanf( ptrf "%50s %50s", usuario1, password1);
      if(strcmp(usuario1, usuario))
    }
   }
   

   cout << "Ingrese su usuario para iniciar sesion";
   cin >> usuario1;
   cout << "Ingrese su password para iniciar sesion";
   cin >> password1;

   if (usuario = usuario1 && password = password1 )
   {
     cout << "Inicio de sesion exitoso";
   }
   else

   cout << "Password o usuario incorrectos";


}
void Registrar_Usuario(){

char usuario [50];
char password [50];
int edad;
char nombre [50];
FILE * ptrf;

if ((ptrf = fopen("usuarios.dat", "w"))== NULL){
    printf("\nEl archivo no pudo ser abierto/creado");
}else{
   printf("Ingrese un nuevo usuario");
   scanf("%s", usuario);
   printf("Ingrese su password");
   scanf("%s", password);
   printf("Ingrese su nombre");
   scanf("%s", nombre);
   printf("Ingrese su edad");
   scanf("%d", edad);

   while (!feof(stdin)){
   fprintf(ptrf "%s %s %s %d", usuario, password, nombre, edad);
   printf("Ingrese un nuevo usuario");
   scanf("%s", usuario);
   printf("Ingrese su password");
   scanf("%s", password);
   printf("Ingrese su nombre");
   scanf("%s", nombre);
   printf("Ingrese su edad");
   scanf("%d", edad);
}
fclose (ptrf);
printf ("Registro exitoso");
}

}
void Cambiar_Password(){
    char newpassword;
    

    cout << "Ingrese su password para continuar";
    cin >> newpassword;
}

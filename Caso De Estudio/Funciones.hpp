#include "Estructuras.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

#ifndef FUNCIONES_H
#define FUNCIONES_H

extern void Menu();
extern void Agregar_Paquetes();
extern void Borrar_Paquetes();
extern void Actualizar_Paquetes();
extern void Buscar_PaquetesID();
extern void Buscar_PaquetesN();
extern void Buscar_PaquetesR();
extern void Historial_Si();
extern void Historial_No();
extern void Registrar_Usuario();
extern void Cambiar_Password();


extern void Menu(){
    setlocale(LC_ALL, "");
    int opc;
    while (opc != 9)
    {
        cout << "********* InterPack *********\n";
        cout << "-----------------------------\n"; 
        cout << "| Menu De Opciones          |\n";
        cout << "| 1) Agregar Nuevo Paquete  |\n";
        cout << "| 2) Borrar Paquete         |\n";
        cout << "| 3) Actualizar Paquete     |\n";
        cout << "| 4) Buscar Paquetes        |\n";
        cout << "| 5) Historial de Paquetes  |\n";
        cout << "| 6) Registrar Usuario      |\n";
        cout << "| 7) Ajustes                |\n";
        cout << "| 8) Salir                  |\n";
        cout << "-----------------------------\n"; 
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
        case 4:
            
            int bsq;
            system("cls");
            cout << "Desea Buscar el Paquete por:\n";
            cout << "1) Paquete Por ID\n";
            cout << "2) Paquete Por Nombre\n";
            cout << "3) Paquete Por Remitente\n";
            cout << "4) Salir \n";
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
                Menu();
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
                Menu();
                break;    
            default:
                break;
            }
            break;

        case 6:
            Registrar_Usuario();

        case 7:
            int Set;
            system("cls");
            cout << "Ajustes:\n";
            cout << "1) Cambiar contraseña:\n";
            cout << "2) Info del app:\n";
            cout << "3) Salir \n";
            cin >> Set;
            switch (Set)
            {
            case 1:
                Cambiar_Password();
                break;
            case 2:
                cout << "Aplicacion de paqueteria para Aduana\n";
                cout << "Realizado por: \n";
                cout << "Rene Nicolas Sandoval Lagos \n";
                cout << "Carlos Alfredo Abea Martinez \n";
                cout << "Joseph Moises Vargas Rodriguez: \n";
                break;
            case 3:
                Menu();
                break;                
            default:
                break;
            }
            break;
        case 8:
            cout << "Saliendo Del Programa";
            cout << "Tenga Bonito Dia";

            exit(0);
            break;                        
        default:
            break;
        }
    }
}

extern void Agregar_Paquetes() {
    // declarar una variable para utilizar el struct de Paquete
    Paquete paquete; 
    // declarar 2 punteros para manejar archivos 
    FILE *AgregarPaquete;
    FILE *IdFile;

    IdFile = fopen("ID.txt", "r");
    if (IdFile != NULL) {
        //Lee un numero del archivo y lo guarda
        fscanf(IdFile, "%d", &paquete.lastId);
        fclose(IdFile);
    }

    paquete.id = paquete.lastId + 1; 

    AgregarPaquete = fopen("archivo.txt", "a"); 
    if (AgregarPaquete == NULL) {
        printf("\nEl archivo no pudo ser abierto/creado\n");
    } else {
        //fgets lo utilizamos para leer las entradas del paquete
        //fprintf para escribir cada campo del paquete en el archivo.txt
        

        printf("Ingrese el nombre del paquete: \n");
        getchar(); // Usar getchar() para consumir y descartar el carácter de nueva línea residual en el búfer
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


        fclose(AgregarPaquete);

        IdFile = fopen("ID.txt", "w");
        if (IdFile != NULL) {
            fprintf(IdFile, "%d", paquete.id);
            fclose(IdFile);
        }
    }
    system("pause");
    system("cls");
}


extern void Actualizar_Paquetes() {
    FILE *archivo, *temp;
    Paquete paquete;
    int id, opcion;
    char nuevoNombre[50];
    char nuevaDescripcion[100];

    // Mostrar el historial de paquetes
    archivo = fopen("archivo.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("Historial de Paquetes:\n");
    printf("------------------------------------------------------\n");

    while (fscanf(archivo, "ID: %d\nNombre: %49[^\n]\nDescripcion: %99[^\n]\nOrigen: %49[^\n]\nDestino: %49[^\n]\nRemitente: %49[^\n]\nFecha de Entrega: %10[^\n]\n",
                  &paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega) != EOF) {
        printf("ID: %d\n", paquete.id);
        printf("Nombre: %s\n", paquete.nombre);
        printf("Descripcion: %s\n", paquete.descripcion);
        printf("Origen: %s\n", paquete.origen);
        printf("Destino: %s\n", paquete.destino);
        printf("Remitente: %s\n", paquete.remitente);
        printf("Fecha de Entrega: %s\n", paquete.Fecha_Entrega);
        printf("---------------------------------------\n");
    }

    fclose(archivo);

    // Preguntar el ID del paquete que desea actualizar
    printf("Ingrese el ID del paquete que desea actualizar: ");
    scanf("%d", &id);

    // Preguntar si desea actualizar el nombre o la descripción
    printf("Seleccione lo que desea actualizar:\n");
    printf("1) Nombre\n");
    printf("2) Descripcion\n");
    scanf("%d", &opcion);

    // Obtener el nuevo valor
    if (opcion == 1) {
        printf("Ingrese el nuevo nombre: ");
        scanf(" %49[^\n]", nuevoNombre);
    } else if (opcion == 2) {
        printf("Ingrese la nueva descripcion: ");
        scanf(" %99[^\n]", nuevaDescripcion);
    } else {
        printf("Opcion no valida.\n");
        return;
    }

    // Actualizar el archivo
    archivo = fopen("archivo.txt", "r");
    temp = fopen("temp.txt", "w");

    if (archivo == NULL || temp == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    while (fscanf(archivo, "ID: %d\nNombre: %49[^\n]\nDescripcion: %99[^\n]\nOrigen: %49[^\n]\nDestino: %49[^\n]\nRemitente: %49[^\n]\nFecha de Entrega: %10[^\n]\n",
                  &paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega) != EOF) {
        if (paquete.id == id) {
            if (opcion == 1) {
                strcpy(paquete.nombre, nuevoNombre);
            } else if (opcion == 2) {
                strcpy(paquete.descripcion, nuevaDescripcion);
            }
        }

        fprintf(temp, "ID: %d\nNombre: %s\nDescripcion: %s\nOrigen: %s\nDestino: %s\nRemitente: %s\nFecha de Entrega: %s\n",
                paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega);
    }

    fclose(archivo);
    fclose(temp);

    remove("archivo.txt");
    rename("temp.txt", "archivo.txt");

    printf("Paquete actualizado con exito.\n");

    system("pause");
    system("cls");
}


extern void Borrar_Paquetes() {
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

    printf("¿Está seguro de eliminar el paquete con ID %d? (s/n): ", idBorrar);
    cin >> confirmacion;


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
        printf("Se elimino correctamente del sistema.\n");
    }
    system("pause");
    system("cls");
}



extern void Historial_No() {
    FILE *archivo;
    Paquete paquete;
    time_t t = time(NULL); //declara una variable para almacenar el tiempo
    struct tm tm = *localtime(&t); // un struct que contiene informacion sobre la fecha y la hora
    char fechaActual[11]; //arreglo para almacenar la fecha con el formato "yyyy-mm-dd"
    //snprintf se utiliza para reiniciar y almacenar una cadena en fechaactual
    //sizeof me da el size del buffer
    //tm_year + 1900 es para obtener el year actual 
    //tm_mon + 1 Es para obtener el mes actual
    //tm_mday Es para obtener el dia actual
    snprintf(fechaActual, sizeof(fechaActual), "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday); 

    archivo = fopen("archivo.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("Paquetes no entregados:\n");
    printf("----------------------------------------------------\n");

    while (fscanf(archivo, "ID: %d\nNombre: %[^\n]\nDescripcion: %[^\n]\nOrigen: %[^\n]\nDestino: %[^\n]\nRemitente: %[^\n]\nFecha de Entrega: %[^\n]\n", 
                  &paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega) != EOF) {
        if (strcmp(paquete.Fecha_Entrega, fechaActual) > 0) {
            printf("ID: %d\n", paquete.id);
            printf("Nombre: %s\n", paquete.nombre);
            printf("Descripcion: %s\n", paquete.descripcion);
            printf("Origen: %s\n", paquete.origen);
            printf("Destino: %s\n", paquete.destino);
            printf("Remitente: %s\n", paquete.remitente);
            printf("Fecha de Entrega: %s\n", paquete.Fecha_Entrega);
            printf("----------------------------------------------------\n");
            printf("\n"); 
        }
    }

    fclose(archivo);
    system("pause");
    system("cls");
}


extern void Historial_Si() {
    FILE *archivo;
    Paquete paquete;
    time_t t = time(NULL); //declara una variable para almacenar el tiempo
    struct tm tm = *localtime(&t); // un struct que contiene informacion sobre la fecha y la hora
    char fechaActual[11]; //arreglo para almacenar la fecha con el formato "yyyy-mm-dd"
    //snprintf se utiliza para reiniciar y almacenar una cadena en fechaactual
    //sizeof me da el size del buffer
    //tm_year + 1900 es para obtener el year actual 
    //tm_mon + 1 Es para obtener el mes actual
    //tm_mday Es para obtener el dia actual
    snprintf(fechaActual, sizeof(fechaActual), "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday); 
    
    

    archivo = fopen("archivo.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("Paquetes entregados:\n");
    printf("------------------------------------------------------\n");

    while (fscanf(archivo, "ID: %d\nNombre: %[^\n]\nDescripcion: %[^\n]\nOrigen: %[^\n]\nDestino: %[^\n]\nRemitente: %[^\n]\nFecha de Entrega: %[^\n]\n", 
                  &paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega) != EOF) {
        
        if (strcmp(paquete.Fecha_Entrega, fechaActual) <= 0) {
            printf("ID: %d\n", paquete.id);
            printf("Nombre: %s\n", paquete.nombre);
            printf("Descripcion: %s\n", paquete.descripcion);
            printf("Origen: %s\n", paquete.origen);
            printf("Destino: %s\n", paquete.destino);
            printf("Remitente: %s\n", paquete.remitente);
            printf("Fecha de Entrega: %s\n", paquete.Fecha_Entrega);
            printf("---------------------------------------\n");
        }
    }

    fclose(archivo);
    system("pause");
    system("cls");
}

extern void Iniciar_Sesion(){

   Sesion sesion;
   char usuario1 [50];
   char password1 [50];
   bool encontrado = false;
   FILE * ptrf;

   if ((ptrf = fopen("usuarios.txt", "r")) == NULL){
    printf ("El archivo no puede ser abierto/creado");
   }
   else
   {
    printf("Ingrese su usuario: \n");
    scanf("%50s", usuario1);
    printf("Ingrese su contraseña: \n");
    scanf("%50s", password1);

    while (fscanf(ptrf, "%50s %50s %s %d", sesion.usuario, sesion.password, sesion.nombre, &sesion.edad) != EOF){
      if(strcmp(usuario1, sesion.usuario) == 0 && strcmp(password1, sesion.password) == 0){
          printf ("Inicio de sesion exitoso\n");
          encontrado = true;
          system ("pause");
          system("cls");
          Menu();
      }
      
    }
   }

  fclose(ptrf);
  if (!encontrado){
    printf("contraseña o usuario incorrecto \n");
    system ("pause");
    system("cls");
    }


   
}
extern void Registrar_Usuario() {
    Sesion sesion;
    FILE *ptrf;
    char usuario1[51];
    int usuario_existe = 0;

    if ((ptrf = fopen("usuarios.txt", "a+")) == NULL) {
        printf("\nEl archivo no pudo ser abierto/creado");
    } else {
        printf("Ingrese un nuevo usuario: \n");
        scanf("%50s", sesion.usuario);

        rewind(ptrf); //funciona para regresar al inicio del archivo para que lea todos los archivos(Creo xd)
        while (fscanf(ptrf, "%50s", usuario1) != EOF) {
            fscanf(ptrf, "%*s %*s %*d");  
            if (strcmp(sesion.usuario, usuario1) == 0) {
                usuario_existe = 1;
            }
        }

        if (usuario_existe) {
            printf("El usuario ya existe y no debe ser guardado.\n");
        } else {
            printf("Ingrese su contraseña: \n");
            scanf("%50s", sesion.password);
            printf("Ingrese su nombre: \n");
            scanf("%50s", sesion.nombre);
            printf("Ingrese su edad: \n");
            scanf("%d", &sesion.edad);

            fprintf(ptrf, "%s %s %s %d\n", sesion.usuario, sesion.password, sesion.nombre, sesion.edad);
            printf("Registro exitoso\n");
        }

        fclose(ptrf);
    }

    system("pause");
}

extern void Cambiar_Password(){
    char usuario1[50];
    char oldPassword[50];
    char newPassword[50];
    Sesion sesion;
    bool encontrado = false;
    FILE *ptrf;
    FILE *tempf;

    ptrf = fopen("usuarios.txt", "r");
    tempf = fopen("temp.txt", "w");

    if (ptrf == NULL || tempf == NULL) {
        printf("\nEl archivo no pudo ser abierto\n");
        return;
    }

    printf("Ingrese su usuario para cambiar contraseña: \n");
    scanf("%50s", usuario1);
    printf("Ingrese su contraseña actual: \n");
    scanf("%50s", oldPassword);
    printf("Ingrese su nuevo contraseña: \n");
    scanf("%50s", newPassword);

    while (fscanf(ptrf, "%50s %50s %50s %d", sesion.usuario, sesion.password, sesion.nombre, &sesion.edad) != EOF) {
        if (strcmp(sesion.usuario, usuario1) == 0 && strcmp(sesion.password, oldPassword) == 0) {
            strcpy(sesion.password, newPassword);
            encontrado = true;
        }
        fprintf(tempf, "%s %s %s %d\n", sesion.usuario, sesion.password, sesion.nombre, sesion.edad);
    }

    fclose(ptrf);
    fclose(tempf);
    
    remove("usuarios.txt");
    rename("temp.txt", "usuarios.txt");

    if (encontrado) {
        printf("contraseña cambiada exitosamente\n");
    } else {
        printf("Usuario o contraseña incorrectos\n");
    }
}

extern void MenuP(){
    setlocale(LC_ALL, "");

    int opc1;    
    do{


    cout << "******** InterPack ********\n";
    cout << "---------------------------\n"; 
    cout << "| Menu                    |\n";
    cout << "| 1) Iniciar Sesion       |\n";
    cout << "| 2) Salir                |\n";
    cout << "---------------------------\n"; 
    cin >> opc1;
    system("cls");

        switch (opc1)
        {
        case 1:
            Iniciar_Sesion();
            break;
        case 2:

        default:
            break;
    }
    
    } while (opc1 != 2);
    


}

extern void Buscar_PaquetesID() {
    FILE* archivo = fopen("archivo.txt", "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo de paquetes.\n");
        return;
    }

    int idBuscar;
    printf("Ingrese el ID del paquete que desea buscar: \n");
    scanf("%d", &idBuscar);

    Paquete paquete;
    bool encontrado = false;

    while (fscanf(archivo, "ID: %d\nNombre: %50[^\n]\nDescripcion: %100[^\n]\nOrigen: %50[^\n]\nDestino: %50[^\n]\nRemitente: %50[^\n]\nFecha de Entrega: %11[^\n]\n",
                  &paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega) != EOF) {
        if (paquete.id == idBuscar) {
            printf("ID: %d\n", paquete.id);
            printf("Nombre: %s\n", paquete.nombre);
            printf("Descripcion: %s\n", paquete.descripcion);
            printf("Origen: %s\n", paquete.origen);
            printf("Destino: %s\n", paquete.destino);
            printf("Remitente: %s\n", paquete.remitente);
            printf("Fecha de Entrega: %s\n", paquete.Fecha_Entrega);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró ningún paquete con el ID %d.\n", idBuscar);
    }

    fclose(archivo);
    system("pause");
    system("cls");
}

extern void Buscar_PaquetesN() {
    FILE* archivo = fopen("archivo.txt", "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo de paquetes.\n");
        return;
    }

    char nombreBuscar[50];
    printf("Ingrese el nombre del paquete que desea buscar: \n");
    getchar();  // Para consumir el salto de línea dejado por scanf
    fgets(nombreBuscar, sizeof(nombreBuscar), stdin);
    nombreBuscar[strcspn(nombreBuscar, "\n")] = 0;  // Eliminar el salto de línea

    Paquete paquete;
    bool encontrado = false;

    while (fscanf(archivo, "ID: %d\nNombre: %49[^\n]\nDescripcion: %99[^\n]\nOrigen: %49[^\n]\nDestino: %49[^\n]\nRemitente: %49[^\n]\nFecha de Entrega: %10[^\n]\n",
                  &paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega) != EOF) {
        if (strcmp(paquete.nombre, nombreBuscar) == 0) {
            printf("ID: %d\n", paquete.id);
            printf("Nombre: %s\n", paquete.nombre);
            printf("Descripcion: %s\n", paquete.descripcion);
            printf("Origen: %s\n", paquete.origen);
            printf("Destino: %s\n", paquete.destino);
            printf("Remitente: %s\n", paquete.remitente);
            printf("Fecha de Entrega: %s\n", paquete.Fecha_Entrega);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró ningún paquete con el nombre %s.\n", nombreBuscar);
    }

    fclose(archivo);
    system("pause");
    system("cls");
}

extern void Buscar_PaquetesR() {
    FILE* archivo = fopen("archivo.txt", "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo de paquetes.\n");
        return;
    }

    char remitenteBuscar[50];
    printf("Ingrese el remitente del paquete que desea buscar: \n");
    getchar();  // Para consumir el salto de línea dejado por scanf
    fgets(remitenteBuscar, sizeof(remitenteBuscar), stdin);
    remitenteBuscar[strcspn(remitenteBuscar, "\n")] = 0;  // Eliminar el salto de línea

    Paquete paquete;
    bool encontrado = false;

    while (fscanf(archivo, "ID: %d\nNombre: %49[^\n]\nDescripcion: %99[^\n]\nOrigen: %49[^\n]\nDestino: %49[^\n]\nRemitente: %49[^\n]\nFecha de Entrega: %10[^\n]\n",
                  &paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega) != EOF) {
        if (strcmp(paquete.remitente, remitenteBuscar) == 0) {
            printf("ID: %d\n", paquete.id);
            printf("Nombre: %s\n", paquete.nombre);
            printf("Descripcion: %s\n", paquete.descripcion);
            printf("Origen: %s\n", paquete.origen);
            printf("Destino: %s\n", paquete.destino);
            printf("Remitente: %s\n", paquete.remitente);
            printf("Fecha de Entrega: %s\n", paquete.Fecha_Entrega);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró ningún paquete con el remitente %s.\n", remitenteBuscar);
    }

    fclose(archivo);
    system("pause");
    system("cls");
}


#endif // FUNCIONES_H

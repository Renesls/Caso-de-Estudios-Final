#include "Estructuras.hpp" //Libreria creada para agregar las estructuras que tenemos
#include <iostream> //es para utilizar lo que es el cout y el cin
#include <stdio.h> //usado para imprimir salidas de datos
#include <stdlib.h> //esta libreria define las funciones numericas de conversion
#include <time.h> //libreria de tiempo para revisar el tiempo actual
#include <string.h> // nos ayuda a manipular los strings y los arreglos
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

// Funcion de menu principal en donde todas las funciones se pueden utilizar

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
            break;

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
            default:
                break;
            }


        case 6:
            Registrar_Usuario();
            break;

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
             
            default:
                break;
            }

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


//Funcion del crud para agregar paquetes utilizando punteros de archivos 
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


    AgregarPaquete = fopen("archivo.txt", "a");     //mandar a crear el archivo para add los datos del paquete
    if (AgregarPaquete == NULL) {  
        printf("\nEl archivo no pudo ser abierto/creado\n"); // si no funciona entonces mandara este mensaje
    } else {

        //fgets lo utilizamos para leer las entradas del paquete
        //fprintf para escribir cada campo del paquete en el archivo.txt
        

        printf("Ingrese el nombre del paquete: \n");
        getchar(); // Usar getchar() Esta línea lee un solo carácter del teclado y lo descarta. 
        fgets(paquete.nombre, sizeof(paquete.nombre), stdin); //lee una cadena en el argumento stream de entrada y la almacena en str
        paquete.nombre[strcspn(paquete.nombre, "\n")] = 0; 
        /*fgets captura el "Enter" entonces lo que hace es reemplazarlo con un caracter nulo para que no haga el salto*/
        fprintf(AgregarPaquete, "ID: %d\nNombre: %s\n", paquete.id, paquete.nombre); 
        /*AgregarPaquete es el archivo donde se guardan estos datos, paquete.id es el 
        número de identificación del paquete, y paquete.nombre es el nombre que el usuario ingresó.
        */
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
       
        time_t t = time(NULL); //declara una variable para almacenar el tiempo
        struct tm tm = *localtime(&t); // un struct que contiene informacion sobre la fecha y la hora
        char fechaActual[11]; //arreglo para almacenar la fecha con el formato "yyyy-mm-dd"
        //snprintf se utiliza para reiniciar y almacenar una cadena en fechaactual
        //sizeof me da el size del buffer
        //tm_year + 1900 es para obtener el year actual 
        //tm_mon + 1 Es para obtener el mes actual
        //tm_mday Es para obtener el dia actual
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

    archivo = fopen("archivo.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }


    printf("Historial de Paquetes:\n");
    printf("------------------------------------------------------\n");
    
    //este while va al txt y manda a imprimir cada paquete en bloques para que el usuario sepa que paquete desea actualizar
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

    // se le pregunta al usuaio que ID desea actualizar
    printf("Ingrese el ID del paquete que desea actualizar: ");
    scanf("%d", &id);

    // se le pregunta al usuaio si desea actualizar el nombre o la descripcion(solo le di 2 opciones)

    printf("Seleccione lo que desea actualizar:\n");
    printf("1) Nombre\n");
    printf("2) Descripcion\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Ingrese el nuevo nombre: ");
        scanf(" %49[^\n]", nuevoNombre);
    } else if (opcion == 2) {
        printf("Ingrese la nueva descripcion: ");
        scanf(" %99[^\n]", nuevaDescripcion);
    } 
    

    archivo = fopen("archivo.txt", "r");
    temp = fopen("temp.txt", "w"); // este es el archivo temporal que utilizaremos para actualizar

    if (archivo == NULL || temp == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    /*este while se utiliza para cambiar el nombre o la descripcion de la persona dependiendo de lo que eligio, 
    busca el ID y cuando lo encuentra con el strcpy cambia el nombre o la descripcion*/
    while (fscanf(archivo, "ID: %d\nNombre: %49[^\n]\nDescripcion: %99[^\n]\nOrigen: %49[^\n]\nDestino: %49[^\n]\nRemitente: %49[^\n]\nFecha de Entrega: %10[^\n]\n",
                  &paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega) != EOF) {
        if (paquete.id == id) { //si encuentra el id entonces utilizara strcpy para cambiarlo
            if (opcion == 1) {
                strcpy(paquete.nombre, nuevoNombre); //La función strcpy copia la cadena de la segunda variable y se lo da a la primera variable para poder actualizar
            } else if (opcion == 2) {
                strcpy(paquete.descripcion, nuevaDescripcion);
            }
        }

        fprintf(temp, "ID: %d\nNombre: %s\nDescripcion: %s\nOrigen: %s\nDestino: %s\nRemitente: %s\nFecha de Entrega: %s\n",
                paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega);
    }

    fclose(archivo);
    fclose(temp);

    remove("archivo.txt"); //eliminamos archivo.txt ya que no esta actualizado
    rename("temp.txt", "archivo.txt"); //renombramos temp.txt ya que es el que esta actualizado

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
    temporal = fopen("temp.txt", "w");

    if (archivo == NULL || temporal == NULL) {
        printf("Error al abrir el archivo o crear el archivo temporal.\n");
        return;
    }

    // Mostrar lista de paquetes
    printf("Lista de paquetes:\n");
    printf("---------------------------------------\n");
    
    //un while de historial de paquetes para que sepa que paquete desea eliminar
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

    //si el usuario no confirma esto no podra eliminar ese archivo
    if (confirmacion == 's' || confirmacion == 'S') {
        archivo = fopen("archivo.txt", "r");

        // este bucle es para buscar todos los paquetes excepto el paquete con id que especifico el usuario
        while (fscanf(archivo, "ID: %d\nNombre: %[^\n]\nDescripcion: %[^\n]\nOrigen: %[^\n]\nDestino: %[^\n]\nRemitente: %[^\n]\nFecha de Entrega: %[^\n]\n", 
                      &paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega) != EOF) {
            if (paquete.id != idBorrar) { //agrega al archivo temporal todos los paquetes que no sean el paquete que puso el usuario esto para que en el archivo no aparezca y se elimina archivo.txt y renombre temp.txt
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

    //este bucle sirve para mandar a imprimi los paquetes en los cuales aun no han sido entregados
    while (fscanf(archivo, "ID: %d\nNombre: %[^\n]\nDescripcion: %[^\n]\nOrigen: %[^\n]\nDestino: %[^\n]\nRemitente: %[^\n]\nFecha de Entrega: %[^\n]\n", 
                  &paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega) != EOF) {
        if (strcmp(paquete.Fecha_Entrega, fechaActual) > 0) {// compara las fechas y verifica si la fecha de entrega del paquete es posterior a la fecha actual
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

    //este bucle sirve para mandar a imprimi los paquetes en los cuales ya han sido entregados
    while (fscanf(archivo, "ID: %d\nNombre: %[^\n]\nDescripcion: %[^\n]\nOrigen: %[^\n]\nDestino: %[^\n]\nRemitente: %[^\n]\nFecha de Entrega: %[^\n]\n", 
                  &paquete.id, paquete.nombre, paquete.descripcion, paquete.origen, paquete.destino, paquete.remitente, paquete.Fecha_Entrega) != EOF) {
        if (strcmp(paquete.Fecha_Entrega, fechaActual) <= 0) { // compara las fechas y verifica si la fecha de entrega del paquete es anterior o igual a la fecha actual
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

    //si encuentra al usuario entonces podra entrar al menu principal si no negra
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

//Registrar un nuevo usuario
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

        rewind(ptrf); //sirve para regresar al inicio del archivo para que lea todos los archivos(Creo xd)
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
    system("cls");
}

//Funcion para cambiar la password
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
    
    //Ingresa el usuario que desea cambiar la password
    printf("Ingrese su usuario para cambiar contraseña: \n");
    scanf("%s", usuario1);
    
    //ingresa la password anterior 
    printf("Ingrese su contraseña actual: \n");
    scanf("%s", oldPassword);
    printf("Ingrese su nuevo contraseña: \n");
    scanf("%s", newPassword);

    /*este while entra al txt y si encuentra un usuario con la misma password y nombre de 
    usuario entonces cambiara su password si no pus solo le mandara un mensaje de que no se pudo y ya*/
    while (fscanf(ptrf, "%s %s %s %d", sesion.usuario, sesion.password, sesion.nombre, &sesion.edad) != EOF) {
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
        printf("Contraseña cambiada exitosamente\n");
    } else {
        printf("Usuario o contraseña incorrectos\n");

    }

    system("pause");
    system("cls");
    Menu();
}

//Funcion del menu de inicio de sesion y pus o inicias sesion o te me vas a dormir
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
            cout << "Saliendo Del Programa \n";
            cout << "Tenga Bonito Dia \n";
            break;
        default:
            break;
    }
    
    } while (opc1 != 2);
    


}

extern void Buscar_PaquetesID() {
    
    Paquete paquete;
    bool encontrado = false;
    FILE* archivo = fopen("archivo.txt", "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo de paquetes.\n");
        return;
    }

    int idBuscar;
    printf("Ingrese el ID del paquete que desea buscar: \n");
    scanf("%d", &idBuscar);


    //Este while sirve para encontrar al remitente justamente con el mismo nombre si lo encuentra mandara a imprimir ese dato en la consola
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
    Paquete paquete;
    bool encontrado = false;
    FILE* archivo = fopen("archivo.txt", "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo de paquetes.\n");
        return;
    }

    char nombreBuscar[50];//es para el nombre
    printf("Ingrese el nombre del paquete que desea buscar: \n");
    getchar();  // Para consumir el salto de línea dejado por scanf
    fgets(nombreBuscar, sizeof(nombreBuscar), stdin);
    nombreBuscar[strcspn(nombreBuscar, "\n")] = 0;  // Eliminar el salto de línea



    //Este while sirve para encontrar al remitente justamente con el mismo nombre si lo encuentra mandara a imprimir ese dato en la consola
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
    Paquete paquete;
    bool encontrado = false;

    //mandamos a leer el archivo.txt para eso es la r de "read"
    FILE* archivo = fopen("archivo.txt", "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo de paquetes.\n");
        return;
    }
    
    char remitenteBuscar[50]; //variable para saber que remitente va a ser
    printf("Ingrese el remitente del paquete que desea buscar: \n");
    getchar();  // Para consumir el salto de línea dejado por scanf
    fgets(remitenteBuscar, sizeof(remitenteBuscar), stdin);
    remitenteBuscar[strcspn(remitenteBuscar, "\n")] = 0;  // Eliminar el salto de línea


    //Este while sirve para encontrar al remitente justamente con el mismo remitente si lo encuentra mandara a imprimir ese dato en la consola
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

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

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
    char usuario[50];
    char password[50];
    int edad;
    char nombre[50];
    char nombre2[50];
};

#endif // ESTRUCTURAS_H

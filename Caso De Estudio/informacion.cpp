/*
"r"	Abre para lectura. Si el archivo no existe o no se encuentra, la llamada _fsopen genera un error.
"w"	Abre un archivo vacío para escritura. Si el archivo especificado existe, se destruye su contenido.
"a"	Se abre para escribir al final del archivo (anexando); crea primero el archivo si no existe.
"r+"	Abre para lectura y escritura. (El archivo debe existir.)
"w+"	Abre un archivo vacío para lectura y escritura. Si el archivo especificado existe, se destruye su contenido.
"a+"	Abre para leer y anexar; crea primero el archivo si no existe.
*/


/* 

struct tm {
   int tm_sec;         // seconds,  range 0 to 59          
   int tm_min;         // minutes, range 0 to 59           
   int tm_hour;        // hours, range 0 to 23             
   int tm_mday;        // day of the month, range 1 to 31  
   int tm_mon;         // month, range 0 to 11             
   int tm_year;        // The number of years since 1900   
   int tm_wday;        // day of the week, range 0 to 6    
   int tm_yday;        // day in the year, range 0 to 365  
   int tm_isdst;       // daylight saving time      
   };       

*/
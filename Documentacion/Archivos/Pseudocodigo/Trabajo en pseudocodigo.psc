Función Agregar_Paquetes
	Definir paqueteID, paqueteNombre, remitente, destinatario, estado Como Cadena
	Definir cantidad Como Entero
	cantidad <- 1
	Dimensionar paquetesID(100)
	Dimensionar paquetesNombre(100)
	Dimensionar paquetesRemitente(100)
	Dimensionar paquetesDestinatario(100)
	Dimensionar paquetesDescripcion(100)
	Escribir 'Agregar Nuevo Paquete'
	paqueteID <- 'ID'+convertirATexto(cantidad+1)
	Escribir 'Ingrese el nombre del paquete:'
	Leer paqueteNombre
	Escribir 'Ingrese el remitente del paquete:'
	Leer remitente
	Escribir 'Ingrese el destinatario del paquete:'
	Leer destinatario
	Escribir 'Ingrese una descripcion del paquete:'
	Leer estado
	paquetesID[cantidad] <- paqueteID
	paquetesNombre[cantidad] <- paqueteNombre
	paquetesRemitente[cantidad] <- remitente
	paquetesDestinatario[cantidad] <- destinatario
	paquetesDescripcion[cantidad] <- estado
	cantidad <- cantidad+1
	Escribir 'Paquete agregado exitosamente con ID: ', paqueteID
FinFunción

Función Registrar_Usuario(usuario,CONTRASENA,nombre,edad,i)
	Escribir 'A continuación, regístrese'
	Escribir 'Cree su usuario'
	Leer usuario[i]
	Escribir 'Cree su contraseña'
	Leer CONTRASENA(i)
	Escribir 'Ingrese su Nombre'
	Leer nombre[i]
	Escribir 'Ingrese su edad'
	Leer edad[i]
	Escribir 'Registro exitoso'
FinFunción

Función Iniciar_Sesion(usuario1,CONTRASENA1,usuario,CONTRASENA,i)
	Escribir 'Iniciar sesión'
	Escribir 'Ingrese su usuario'
	Leer usuario1
	Escribir 'Ingrese su contraseña'
	Leer CONTRASENA1
	encontrado <- Falso
	Para j<-1 Hasta i-1 Hacer
		Si usuario1==usuario[j] Y CONTRASENA1==CONTRASENA(j) Entonces
			encontrado <- Verdadero
			Escribir 'Inicio de sesión exitoso'
			Si encontrado==Verdadero Entonces
				Limpiar Pantalla
				Menu()
			FinSi
		FinSi
	FinPara
	Si  NO encontrado Entonces
		Escribir 'Usuario o contraseña incorrecta'
	FinSi
FinFunción

Función Borrar_Paquetes
	Definir paqueteID Como Cadena
	Definir encontrado Como Lógico
	Definir cantidad, i, j Como Entero
	cantidad <- 5
	encontrado <- Falso
	Dimensionar paquetesID(100)
	Dimensionar paquetesNombre(100)
	Dimensionar paquetesRemitente(100)
	Dimensionar paquetesDestinatario(100)
	Dimensionar paquetesDescripcion(100)
	paquetesID[1] <- 'ID1'
	paquetesID[2] <- 'ID2'
	paquetesID[3] <- 'ID3'
	paquetesID[4] <- 'ID4'
	paquetesID[5] <- 'ID5'
	paquetesNombre[1] <- 'Paquete1'
	paquetesNombre[2] <- 'Paquete2'
	paquetesNombre[3] <- 'Paquete3'
	paquetesNombre[4] <- 'Paquete4'
	paquetesNombre[5] <- 'Paquete5'
	paquetesRemitente[1] <- 'Remitente1'
	paquetesRemitente[2] <- 'Remitente2'
	paquetesRemitente[3] <- 'Remitente3'
	paquetesRemitente[4] <- 'Remitente4'
	paquetesRemitente[5] <- 'Remitente5'
	paquetesDestinatario[1] <- 'Destinatario1'
	paquetesDestinatario[2] <- 'Destinatario2'
	paquetesDestinatario[3] <- 'Destinatario3'
	paquetesDestinatario[4] <- 'Destinatario4'
	paquetesDestinatario[5] <- 'Destinatario5'
	paquetesDescripcion[1] <- 'Pendiente'
	paquetesDescripcion[2] <- 'Entregado'
	paquetesDescripcion[3] <- 'Pendiente'
	paquetesDescripcion[4] <- 'Pendiente'
	paquetesDescripcion[5] <- 'Entregado'
	Escribir 'Eliminar Paquete'
	Escribir 'Ingrese el ID del paquete a eliminar:'
	Leer paqueteID
	Para i<-1 Hasta cantidad Hacer
		Si paquetesID[i]=paqueteID Entonces
			encontrado <- Verdadero
			Para j<-i Hasta cantidad-1 Hacer
				paquetesID[j] <- paquetesID[j+1]
				paquetesNombre[j] <- paquetesNombre[j+1]
				paquetesRemitente[j] <- paquetesRemitente[j+1]
				paquetesDestinatario[j] <- paquetesDestinatario[j+1]
				paquetesDescripcion[j] <- paquetesDescripcion[j+1]
			FinPara
			cantidad <- cantidad-1
			Escribir 'Paquete eliminado exitosamente'
		FinSi
	FinPara
	Si  NO encontrado Entonces
		Escribir 'Paquete no encontrado'
	FinSi
FinFunción

Función Actualizar_Paquetes
	Definir paqueteID, nuevoNombre, nuevoRemitente, nuevoDestinatario, nuevoEstado Como Cadena
	Definir encontrado Como Lógico
	Definir cantidad, i Como Entero
	cantidad <- 5
	encontrado <- Falso
	Dimensionar paquetesID(100)
	Dimensionar paquetesNombre(100)
	Dimensionar paquetesRemitente(100)
	Dimensionar paquetesDestinatario(100)
	Dimensionar paquetesDescripcion(100)
	paquetesID[1] <- 'ID1'
	paquetesID[2] <- 'ID2'
	paquetesID[3] <- 'ID3'
	paquetesID[4] <- 'ID4'
	paquetesID[5] <- 'ID5'
	paquetesNombre[1] <- 'Paquete1'
	paquetesNombre[2] <- 'Paquete2'
	paquetesNombre[3] <- 'Paquete3'
	paquetesNombre[4] <- 'Paquete4'
	paquetesNombre[5] <- 'Paquete5'
	paquetesRemitente[1] <- 'Remitente1'
	paquetesRemitente[2] <- 'Remitente2'
	paquetesRemitente[3] <- 'Remitente3'
	paquetesRemitente[4] <- 'Remitente4'
	paquetesRemitente[5] <- 'Remitente5'
	paquetesDestinatario[1] <- 'Destinatario1'
	paquetesDestinatario[2] <- 'Destinatario2'
	paquetesDestinatario[3] <- 'Destinatario3'
	paquetesDestinatario[4] <- 'Destinatario4'
	paquetesDestinatario[5] <- 'Destinatario5'
	paquetesDescripcion[1] <- 'Pendiente'
	paquetesDescripcion[2] <- 'Entregado'
	paquetesDescripcion[3] <- 'Pendiente'
	paquetesDescripcion[4] <- 'Pendiente'
	paquetesDescripcion[5] <- 'Entregado'
	Escribir 'Actualizar Paquete'
	Escribir 'Ingrese el ID del paquete a actualizar:'
	Leer paqueteID
	Para i<-1 Hasta cantidad Hacer
		Si paquetesID[i]=paqueteID Entonces
			Escribir 'Ingrese el nuevo nombre del paquete:'
			Leer nuevoNombre
			Escribir 'Ingrese el nuevo remitente del paquete:'
			Leer nuevoRemitente
			Escribir 'Ingrese el nuevo destinatario del paquete:'
			Leer nuevoDestinatario
			Escribir 'Ingrese el nuevo estado del paquete (Pendiente/Entregado):'
			Leer nuevoEstado
			paquetesNombre[i] <- nuevoNombre
			paquetesRemitente[i] <- nuevoRemitente
			paquetesDestinatario[i] <- nuevoDestinatario
			paquetesDescripcion[i] <- nuevoEstado
			encontrado <- Verdadero
			Escribir 'Paquete actualizado exitosamente'
		FinSi
	FinPara
	Si  NO encontrado Entonces
		Escribir 'Paquete no encontrado'
	FinSi
FinFunción



Función cambiarcontra(nuevacontra,CONTRASENA1,CONTRASENA,i)
	encontrado <- Falso
	Escribir 'Ingrese su contraseña anterior para continuar'
	Leer viejacontra
	Para j<-1 Hasta i-1 Hacer
		Si viejacontra==CONTRASENA(j) Entonces
			Escribir 'Ingrese su nueva contraseña'
			Leer nuevacontra
			Escribir 'Cambio de contraseña exitoso'
		FinSi
	FinPara
	Si  NO encontrado Entonces
		Escribir 'Contactatese con el servicio de asistencia'
	FinSi
FinFunción

Función BusquedaPaquetePorID
	Definir idBuscado Como Cadena
	Definir indice, cantidadPaquetes Como Entero
	Definir paqueteEncontrado Como Lógico
	Dimensionar ID(10), destinos(10), descripciones(10)
	ID[1] <- '101'
	ID[2] <- '102'
	ID[3] <- '103'
	ID[4] <- '104'
	ID[5] <- '105'
	ID[6] <- '106'
	ID[7] <- '107'
	ID[8] <- '108'
	ID[9] <- '109'
	ID[10] <- '110'
	Escribir 'Ingrese el nombre del id del paquete a buscar: '
	Leer remitenteBuscado
	paqueteEncontrado <- Falso
	cantidadPaquetes <- 10
	Para indice<-1 Hasta cantidadPaquetes Con Paso 1 Hacer
		Si ID[indice]=idBuscado Entonces
			paqueteEncontrado <- Verdadero
			Escribir 'Paquete encontrado - ID: ', ID[indice]
			Escribir 'Aqui estaria el Destinatario de la persona - Destinatario: ', destinos[indice]
			Escribir 'Paquete buscado por el remitente nada mas - Descripción: ', descripciones[indice]
		FinSi
	FinPara
	Si  NO paqueteEncontrado Entonces
		Escribir 'Paquete con remitente ', remitenteBuscado, ' no encontrado.'
	FinSi
FinFunción

Función BuscarPaquetePorRemitente
	Definir remitenteBuscado Como Cadena
	Definir indice, cantidadPaquetes Como Entero
	Definir paqueteEncontrado Como Lógico
	Dimensionar remitentes(10), destinos(10), descripciones(10)
	remitentes[1] <- 'Juan Perez'
	remitentes[2] <- 'Maria Lopez'
	remitentes[3] <- 'Pedro Ramirez'
	remitentes[4] <- 'Ana Martinez'
	remitentes[5] <- 'Jose Garcia'
	remitentes[6] <- 'Laura Rodriguez'
	remitentes[7] <- 'Carlos Sanchez'
	remitentes[8] <- 'Sofia Fernandez'
	remitentes[9] <- 'David Gonzalez'
	remitentes[10] <- 'Elena Diaz'
	Escribir 'Ingrese el nombre del remitente del paquete a buscar: '
	Leer remitenteBuscado
	paqueteEncontrado <- Falso
	cantidadPaquetes <- 10
	Para indice<-1 Hasta cantidadPaquetes Con Paso 1 Hacer
		Si remitentes[indice]=remitenteBuscado Entonces
			paqueteEncontrado <- Verdadero
			Escribir 'Paquete encontrado - Remitente: ', remitentes[indice]
			Escribir 'Aqui estaria el Destinatario de la persona - Destinatario: ', destinos[indice]
			Escribir 'Paquete buscado por el remitente nada mas - Descripción: ', descripciones[indice]
		FinSi
	FinPara
	Si  NO paqueteEncontrado Entonces
		Escribir 'Paquete con remitente ', remitenteBuscado, ' no encontrado.'
	FinSi
FinFunción

Función BuscarPaquetePorNombre
	Definir PaqueteBuscado Como Cadena
	Definir indice, cantidadPaquetes Como Entero
	Definir paqueteEncontrado Como Lógico
	Dimensionar Paquetes(10), destinos(10), descripciones(10)
	Paquetes[1] <- 'Caja de zapatos'
	Paquetes[2] <- 'Carro Azul'
	Paquetes[3] <- 'Laptop Gaming'
	Paquetes[4] <- 'Caja Amarilla'
	Paquetes[5] <- 'Queso Azul'
	Paquetes[6] <- 'Papas Quemadas'
	Paquetes[7] <- 'Tomate de Papa'
	Paquetes[8] <- 'Sombrero Vaquero'
	Paquetes[9] <- 'Balon de Futbol'
	Paquetes[10] <- 'Balon de Volleyball'
	Escribir 'Ingrese el nombre del remitente del paquete a buscar: '
	Leer remitenteBuscado
	paqueteEncontrado <- Falso
	cantidadPaquetes <- 10
	Para indice<-1 Hasta cantidadPaquetes Con Paso 1 Hacer
		Si Paquetes[indice]=PaqueteBuscado Entonces
			paqueteEncontrado <- Verdadero
			Escribir 'Paquete encontrado - Paquetes: ', Paquetes[indice]
			Escribir 'Aqui estaria el Destinatario de la persona - Destinatario: ', destinos[indice]
			Escribir 'Paquete buscado por el remitente nada mas - Descripción: ', descripciones[indice]
		FinSi
	FinPara
	Si  NO paqueteEncontrado Entonces
		Escribir 'El nombre del Paquete ', remitenteBuscado, ' no ha sido encontrado.'
	FinSi
FinFunción

Función PaquetesEntregado
	Definir nombrePaquete, estadoPaquete, fechaPaquete Como Cadena
	Definir idPaquete Como Entero
	Definir idBuscado Como Entero
	Definir indice, cantidadPaquetesEntregados Como Entero
	Definir paqueteEncontrado Como Lógico
	Dimensionar nombres(5), estados(5), fechas(5)
	Dimensionar ids(5)
	ids[1] <- 101
	ids[2] <- 202
	ids[3] <- 303
	ids[4] <- 404
	ids[5] <- 505
	nombres[1] <- 'Paquete A'
	nombres[2] <- 'Paquete B'
	nombres[3] <- 'Paquete C'
	nombres[4] <- 'Paquete D'
	nombres[5] <- 'Paquete E'
	estados[1] <- 'Entregado'
	estados[2] <- 'Entregado'
	estados[3] <- 'Entregado'
	estados[4] <- 'En camino'
	estados[5] <- 'Entregado'
	fechas[1] <- '2024-05-15'
	fechas[2] <- '2024-05-20'
	fechas[3] <- '2024-06-01'
	fechas[4] <- '2024-06-05'
	fechas[5] <- '2024-06-10'
	Escribir 'Ingrese el ID del paquete entregado a buscar: '
	Leer idBuscado
	paqueteEncontrado <- Falso
	cantidadPaquetesEntregados <- 5
	Para indice<-1 Hasta cantidadPaquetesEntregados Con Paso 1 Hacer
		Si ids[indice]=idBuscado Entonces
			Si estados[indice]='Entregado' Entonces
				paqueteEncontrado <- Verdadero
				nombrePaquete <- nombres[indice]
				estadoPaquete <- estados[indice]
				fechaPaquete <- fechas[indice]
			SiNo
				Escribir 'El paquete con ID ', idBuscado, ' no ha sido entregado aún.'
				paqueteEncontrado <- Verdadero
			FinSi
		FinSi
	FinPara
	Si paqueteEncontrado Entonces
		Escribir 'Nombre del paquete: ', nombrePaquete
		Escribir 'ID del paquete: ', idBuscado
		Escribir 'Estado del paquete: ', estadoPaquete
		Escribir 'Fecha de entrega: ', fechaPaquete
	SiNo
		Escribir 'Paquete con ID ', idBuscado, ' no encontrado o no ha sido entregado.'
	FinSi
FinFunción

Función PaquetesNoEntregado
	Definir nombrePaquete, estadoPaquete, fechaPaquete Como Cadena
	Definir idPaquete, cantidadPaquetes Como Entero
	Definir id_Buscado Como Entero
	Definir paqueteEncontrado Como Lógico
	Dimensionar nombres(5), estados(5), fechas(5)
	Dimensionar ids(5)
	ids[1] <- 101
	ids[2] <- 202
	ids[3] <- 303
	ids[4] <- 404
	ids[5] <- 505
	nombres[1] <- 'Paquete A'
	nombres[2] <- 'Paquete B'
	nombres[3] <- 'Paquete C'
	nombres[4] <- 'Paquete D'
	nombres[5] <- 'Paquete E'
	estados[1] <- 'En camino'
	estados[2] <- 'En almacén'
	estados[3] <- 'En tránsito'
	estados[4] <- 'En espera'
	estados[5] <- 'En espera'
	fechas[1] <- '2024-06-25'
	fechas[2] <- '2024-06-20'
	fechas[3] <- '2024-06-30'
	fechas[4] <- '2024-07-05'
	fechas[5] <- '2024-07-10'
	Escribir 'Ingrese el ID del paquete no entregado a buscar: '
	Leer idBuscado
	paqueteEncontrado <- Falso
	cantidadPaquetes <- 5
	Para indice<-1 Hasta cantidadPaquetes Con Paso 1 Hacer
		Si ids[indice]=idBuscado Entonces
			Si estados[indice]<>'Entregado' Entonces
				paqueteEncontrado <- Verdadero
				nombrePaquete <- nombres[indice]
				estadoPaquete <- estados[indice]
				fechaPaquete <- fechas[indice]
			SiNo
				Escribir 'El paquete con ID ', idBuscado, ' ya ha sido entregado.'
				paqueteEncontrado <- Verdadero
			FinSi
		FinSi
	FinPara
	Si paqueteEncontrado Entonces
		Escribir 'Nombre del paquete: ', nombrePaquete
		Escribir 'ID del paquete: ', idBuscado
		Escribir 'Estado del paquete: ', estadoPaquete
		Escribir 'Fecha estimada de entrega: ', fechaPaquete
	SiNo
		Escribir 'Paquete con ID ', idBuscado, ' no encontrado o ya ha sido entregado.'
	FinSi
FinFunción

Función historialPaquetes_entregados_no
	Definir matriz_nombre Como Cadena
	Definir matriz_destino Como Cadena
	Definir matriz_estado Como Cadena
	Definir filas, columnas Como Entero
	Dimensionar matriz_nombre(4,4)
	Dimensionar matriz_destino(4,4)
	Dimensionar matriz_estado(4,4)
	Para filas<-1 Hasta 4 Con Paso 1 Hacer
		Para columnas<-1 Hasta 4 Con Paso 1 Hacer
			Escribir 'Ingrese el nombre del paquete [', filas, ', ', columnas, ']:'
			Leer matriz_nombre[filas,columnas]
			Escribir 'Ingrese el destino del paquete [', filas, ', ', columnas, ']:'
			Leer matriz_destino[filas,columnas]
			Escribir 'Si su paquete fue entregado (si) o no (no) [', filas, ', ', columnas, ']:'
			Leer matriz_estado[filas,columnas]
		FinPara
	FinPara
	Para filas<-1 Hasta 4 Con Paso 1 Hacer
		Para columnas<-1 Hasta 4 Con Paso 1 Hacer
			Escribir 'Paquete [', filas, ', ', columnas, ']: '
			Escribir 'Nombre: ', matriz_nombre[filas,columnas], ', '
			Escribir 'Destino: ', matriz_destino[filas,columnas], ', '
			Escribir 'Estado: ', matriz_estado[filas,columnas]
		FinPara
		Escribir ' '
	FinPara
FinFunción

Función Menu
	Definir opc, bsq, Hist, Dtl, Set Como Entero
	Repetir
		Escribir 'InterPack'
		Escribir '*************************'
		Escribir 'Menu De Opciones'
		Escribir '1) Agregar Nuevo Paquete'
		Escribir '2) Borrar Paquete'
		Escribir '3) Actualizar Paquete'
		Escribir '4) Buscar Paquetes'
		Escribir '5) Historial de Paquetes'
		Escribir '6) Detalle de paquetes'
		Escribir '7) Registrar Usuario'
		Escribir '8) Ajustes'
		Escribir '9) Salir'
		Leer opc
		Si opc=1 Entonces
			Agregar_Paquetes()
		FinSi
		Si opc=2 Entonces
			Borrar_Paquetes()
		FinSi
		Si opc=3 Entonces
			Actualizar_Paquetes()
		FinSi
		Si opc=4 Entonces
			Escribir 'Desea Buscar el Paquete por:'
			Escribir '1) Paquete Por ID'
			Escribir '2) Paquete Por Nombre'
			Escribir '3) Paquete Por Remitente'
			Escribir '4) Salir'
			Leer bsq
			Si bsq=1 Entonces
				BusquedaPaquetePorID()
				Esperar Tecla
			FinSi
			Si bsq=2 Entonces
				Limpiar Pantalla
				BuscarPaquetePorNombre()
				Esperar Tecla
			FinSi
			Si bsq=3 Entonces
				Limpiar Pantalla
				BuscarPaquetePorRemitente()
				Esperar Tecla
			FinSi
			Si bsq=4 Entonces
				Escribir 'Saliendo de la búsqueda...'
			FinSi
			Si bsq<>1 Y bsq<>2 Y bsq<>3 Y bsq<>4 Entonces
				Escribir 'Opcion invalida'
			FinSi
		FinSi
		Si opc=5 Entonces
			Escribir 'Historial de paquetes:'
			historialPaquetes_entregados_no()
			Esperar Tecla
		FinSi
		Si opc=6 Entonces
			Escribir 'Detalles de Paquetes:'
			Escribir '1) Paquetes Entregados'
			Escribir '2) Paquetes No Entregados'
			Escribir '3) Salir'
			Leer Dtl
			Si Dtl=1 Entonces
				PaquetesEntregado()
				Esperar Tecla
			FinSi
			Si Dtl=2 Entonces
				PaquetesNoEntregado()
				Esperar Tecla
			FinSi
			Si Dtl=3 Entonces
				Escribir 'Saliendo de los detalles...'
			FinSi
			Si Dtl<>1 Y Dtl<>2 Y Dtl<>3 Entonces
				Escribir 'Opcion invalida'
			FinSi
		FinSi
		Si opc=7 Entonces
			Registrar_Usuario(usuario,CONTRASENA,nombre,edad,i)
			Esperar Tecla
		FinSi
		Si opc=8 Entonces
			Escribir 'Ajustes:'
			Escribir '1) Cambiar Password'
			Escribir '2) Info del app'
			Escribir '3) Salir'
			Leer Set
			Si Set=1 Entonces
			
			FinSi
			Si Set=2 Entonces
				Escribir 'Info del app'
				Escribir 'Aqui ponemos info de la app y demas demas demas'
				Escribir 'Tengo sueñoooooooooooooooooo'
				Esperar Tecla
			FinSi
			Si Set=3 Entonces
				Escribir 'Saliendo de ajustes...'
			FinSi
			Si Set<>1 Y Set<>2 Y Set<>3 Entonces
				Escribir 'Opcion invalida'
			FinSi
		FinSi
		Si opc=9 Entonces
			Escribir 'Saliendo del menú...'
		FinSi
		Si opc<>1 Y opc<>2 Y opc<>3 Y opc<>4 Y opc<>5 Y opc<>6 Y opc<>7 Y opc<>8 Y opc<>9 Entonces
			Escribir 'Opcion invalida'
		FinSi
	Hasta Que opc=9
FinFunción

Algoritmo Trabajo
	Definir usuario, CONTRASENA, nombre, edad, nuevacontra, viejacontra Como Cadena
	Definir i, cont, opc Como Entero
	Definir usuario1, CONTRASENA1 Como Cadena
	i <- 1
	cont <- 0
	Dimensionar usuario(100)
	Dimensionar CONTRASENA(100)
	Dimensionar nombre(100)
	Dimensionar edad(100)
	Definir opc1 Como Entero
	Mientras opc1<>3 Hacer
		Escribir 'Interpack'
		Escribir '**********************'
		Escribir 'Menu De Opciones'
		Escribir '1) Iniciar Sesion'
		Escribir '2) Registrar Sesion'
		Escribir '3) Salir'
		Leer opc1
		Si opc1==1 Entonces
			Iniciar_Sesion(usuario1,CONTRASENA1,usuario,CONTRASENA,i)
		FinSi
		Si opc1==2 Entonces
			Registrar_Usuario(usuario,CONTRASENA,nombre,edad,i)
			i <- i+1
			cont <- cont+1
			Limpiar Pantalla
		FinSi
	FinMientras
FinAlgoritmo

/*
 ============================================================================
 Name        : EjerciciosDeC.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "TADfiles.h"

char* criterioGenerico(t_list* lista) {
	return "hola | funco | xd";
}

void procesarArchivo(char caracterSeparador, int cantCamposPorLinea, char* (*criterio)(t_list*), char* path) {

	t_list* multiplesLineas = list_create();

	FILE* archivo = fopen(path,"r+t");

	while( !feof(archivo) )
	   {

		t_list* linea = list_create();

		linea = leerLinea(caracterSeparador,cantCamposPorLinea,archivo);

		list_add(multiplesLineas,linea); // int list_add(t_list *, void *element);
	   }

	txt_close_file(archivo); // Cerramos archivo en modo lectura, simil a fclose()

	archivo = txt_open_for_append(path); // Lo abrimos en modo write

	procesarMultiplesLineas(multiplesLineas,criterio,archivo); // Procesamos lineas

	txt_close_file(archivo); // Cerramos again
}

int main(void) {

	procesarArchivo(';',6,criterioGenerico,"/home/utnso/workspace/EjerciciosDeC/src/archivoTexto.txt");

	return EXIT_SUCCESS;
}





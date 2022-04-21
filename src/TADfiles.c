/*
 * TADfiles.c
 *
 *  Created on: 19 abr. 2022
 *      Author: utnso
 */


// Linea -> Lista de campos
// Lineas -> Lista de lineas

#include "TADfiles.h"


void procesarArchivo(char caracterSeparador, int cantCamposPorLinea, char* (*criterio)(t_list*)) {

	t_list* multiplesLineas = list_create();


	FILE* archivo = fopen("archivo.dat","r+b");

	while( !feof(archivo) )
	   {

		t_list* linea = list_create();

		linea = leerLinea(caracterSeparador,cantCamposPorLinea,archivo);

		list_add(multiplesLineas,linea); // int list_add(t_list *, void *element);

	   }

	 fclose(archivo);

	procesarMultiplesLineas(multiplesLineas,criterio,archivo);
}


t_list* leerLinea(char caracterSeparador, int cantCamposPorLinea, FILE* archivo){

	t_list*  linea = list_create();

	char ch = readChar(archivo);

	char* chCasteado = malloc(sizeof(char));

	*chCasteado = ch; // Transformamos el char a un string (char casteado)

	char* campoLinea = string_new();

	while(sizeof(linea) != cantCamposPorLinea)
	   {
			 // Busco elemento a elemento
			 if(ch != caracterSeparador){
				 string_append(&campoLinea, chCasteado); // No se puede concatenar char con char*
			 }
			 else{
				  list_add(linea,campoLinea);
				  campoLinea = string_new();
			 }

			 ch = readChar(archivo);
	   }

	free(chCasteado);

	return linea;

}

void procesarMultiplesLineas(t_list* multiplesLineas, char* (*criterio)(t_list*), FILE* archivo) {

	t_list_iterator* iteradorFuncion = list_iterator_create(multiplesLineas);

	t_list* lineaEncontrada = list_iterator_next(iteradorFuncion);

	while (list_iterator_has_next(iteradorFuncion)) {

		char* loQueDevuelve = criterio(lineaEncontrada); // a "criterio" le faltan parametros, ver .c de las commons
		txt_write_in_file(archivo, loQueDevuelve);
	}

	list_iterator_next(iteradorFuncion);
}


char readChar(FILE* f) {
   char x;

   fread(&x,sizeof(char),1,f);

   return x;
}



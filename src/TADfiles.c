// Linea -> Lista de campos
// Lineas -> Lista de lineas

#include "TADfiles.h"

t_list* leerLinea(char caracterSeparador, int cantCamposPorLinea, FILE* archivo){

	t_list*  linea = list_create();

	char ch = readChar(archivo);

	char* chCasteado = malloc(sizeof(char));

	*chCasteado = ch; // Transformamos el char a un string (char casteado)

	char* campoLinea = string_new();

	while(list_size(linea) != cantCamposPorLinea)
	   {
			 // Busco elemento a elemento
			 if(ch != caracterSeparador || ch != '\n'){
				 string_append(&campoLinea, chCasteado); // No se puede concatenar char con char*
			 }
			 else{
				  list_add(linea,campoLinea);
				  campoLinea = string_new();
			 }

			 ch = readChar(archivo);
			 *chCasteado = ch;
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



/*
 * TADfiles.h
 *
 *  Created on: 19 abr. 2022
 *      Author: utnso
 */

#ifndef TADFILES_H_
#define TADFILES_H_

#include <stdio.h>
#include <stdlib.h>
#include <commons/txt.h>
#include <commons/collections/list.h>
#include <commons/string.h>

// Funcion leer caracter de archivo
char readChar(FILE*);

// Funcion leer linea
t_list* leerLinea (char, int, FILE*);

// Funcion procesar MULTIPLES lineas
void procesarMultiplesLineas(t_list*, char* (*criterio)(t_list*), FILE*);

#endif /* TADFILES_H_ */

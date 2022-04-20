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

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	char * mail = "akalinin@frba.utn.ar";
	char* user;
	char* dominio;


	mail_split(mail,&user,&dominio);

	puts(user);
	puts(dominio);

	return EXIT_SUCCESS;
}


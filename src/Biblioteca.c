/*
 * Biblioteca.c
 *
 *  Created on: 18 abr. 2022
 *      Author: utnso
 */

#include "Biblioteca.h"

char* string_concat(const char* string1, const char* string2) {
    string_append(&string1, string2);
    return string1;
}


void string_concat_dinamyc(const char* string1, const char* string2, char** string3) {
    string_append(string3, string1);
    string_append(string3, string2);

}

void mail_split(const char* mail, char** user, char** dominio){

	char ** splitteado = string_split(mail, "@");
	*user =*(splitteado);
	*dominio = *(splitteado+1);

}



/*
 * TADfiles.h
 *
 *  Created on: 19 abr. 2022
 *      Author: utnso
 */

#ifndef TADFILES_H_
#define TADFILES_H_

#include <stdio.h>

 generic read(FILE* f)
{
   void * x;

   fread(&x,sizeof(T),1,f);

   return x;
}

template <typename T> void write(FILE* f, T v)
{
   fwrite(&v,sizeof(T),1,f);
}

template <typename T> void seek(FILE* f, int n)
{
   fseek(f,sizeof(T)*n,SEEK_SET);
}

template <typename T> long fileSize(FILE* f)
{
   int PosAct = ftell(f);
   fseek(f,0,SEEK_END);
   int cantReg=ftell(f)/sizeof(T);
   fseek(f,PosAct,SEEK_SET);
   return cantReg;
}

template <typename T> long filePos(FILE* f)
{
   return ftell(f)/sizeof(T);
}


#endif /* TADFILES_H_ */

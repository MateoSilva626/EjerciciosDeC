/*
 * TADfiles.c
 *
 *  Created on: 19 abr. 2022
 *      Author: utnso
 */


void procesarArchivo(char caracterSeparador, int cantCamposPorLinea) {


	coll<Lineas> lineas = ();

	FILE* f = fopen("archivo.dat","r+b");

	while( !feof(f) )
	   {

		Coll<campoLinea> linea = collCreate<linea>();

		linea = leerLinea(caracterSeparador,cantCamposPorLinea,f);

		agregarLineaA(lineas,linea);

	   }

	 fclose(f);
	//lo deberia de abrir para escribir
	procesarMultiplesLineas(lineas);
	//lo cierro de nuevo ?



}



coll<campoLinea> leerLinea (char caracterSeparador, int cantCamposPorLinea, FILE* archivo){

	Coll<campoLinea> linea = collCreate<linea>();

	char ch = read<char>(f);

	string campoLinea = "";

	while(size(linea) != cantCamposPorLinea)
	   {
			 //busco elemento a elemento
			 if(ch != caracterSeparador){
				 string_append(campoLinea, ch);
			 }
			 else{
				  agregragarALinea(campoLinea,linea);
				  campoLinea = "";
			 }

			 char ch = read<char>(f);
	   }

	return linea;

}


char* procesarLinea (Coll<campoLinea> linea, char* funcion()) {


	return funcion(linea[0],linea[1],linea[3])
}



void procesarLineas (coll<linea> lineas,funcion){

  //itera la coleccion  de linea y va procesando y guardando cada una en el archivo
	for(int i=0; i <= size(lineas)  ;i++){

		char* loQueDevuelve = procesarlinea(linea[i],funcion);
		escribirEnArchivo(loQueDevuelve);

	}

}



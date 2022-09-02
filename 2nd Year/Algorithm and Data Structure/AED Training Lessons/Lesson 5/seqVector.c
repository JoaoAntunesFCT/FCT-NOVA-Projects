#include <stdlib.h>
#include "iterador.h"
#include "sequencia.h"

/* Estrutura de dados: sequencia implementada em vector */
struct _sequencia{
	void * * elems; // apontador para vector de enderecos de elementos
	int numElems;
	int capacidade; // capacidade corrente do vector
};

sequencia criaSequencia(int cap){
	
	sequencia s;

    s = (sequencia) malloc(sizeof(struct _sequencia));
	if(s==NULL){

		return NULL;
	}

	s->elems = (void *) malloc(sizeof(void *)*cap);
	if(s->elems==NULL){

		free(s);
		return NULL;
	}
	s->numElems=0;
	s->capacidade=cap;
	return s;
}

void destroiSequencia(sequencia s ){
	
	free(s->elems);
	free(s);
}


void destroiSeqElems(sequencia s, void (*destroi)(void *) ){
	
	int i=0;
	//destroi 
	for (i=0; i<s->numElems; i++){
		destroi(s->elems[i]);
	}
	//destroi sequencia
	destroiSequencia(s);
}


int vaziaSequencia(sequencia s){
	
	if(s->elems[0]==NULL){
		return 1;
	}
	return 0;
}


int tamanhoSequencia(sequencia s){
	
	return s->numElems;
}


void * elementoPosSequencia(sequencia s, int i){
	
	return s->elems[i-1];
}


void adicionaPosSequencia(sequencia s, void * elem, int i){
	
	int k=0;

	if(tamanhoSequencia(s)== s->capacidade){

		//incrementar sequencia(s)
	}
	for(k=s->numElems;k>=i;k--){

		s->elems[k]=s->elems[k-1];
	}
	s->elems[i-1]=elem;
	s->numElems++;
}


void * removePosSequencia(sequencia s, int i){
	
	int k=0;

	void * temp = s->elems[i-1];

	if(tamanhoSequencia(s)==s->capacidade){

		//incrementar sequencia(s)
	}
	

	for(k=i;k<=s->numElems;k++){

		s->elems[k]=s->elems[k+1];
	}
	s->numElems--;
	return temp;
}


iterador iteradorSequencia(sequencia s){
	
	//CUIDADO: DEVE DAR AO ITERADOR UMA COPIA DO VECTOR A PERCORRER
	int i;
	void * aux = malloc(sizeof(void *)* s->numElems);

	for(i=0;i<s->numElems;i++){

		aux[i]=s->elems[i];
	}
	iterador it = iteradorSequencia(s);
	while(temSeguinteIterador(it)){
		s = (sequencia) seguinteIterador(it);
	}
	return aux;
}
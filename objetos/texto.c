#include "texto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct structTexto {
	int id;
	double x, y;
	char conteudo[128], corBorda[32], corPreenchimento[32];
};

typedef struct structTexto * ponteiroTexto;

static Texto* vetorTextos;

Texto criarTexto(int id, double x, double y, char* conteudo, char* corBorda, char* corPreenchimento) {

	ponteiroTexto texto;

	texto = malloc(sizeof(struct structTexto));

	texto->id = id;
	texto->x = x;
	texto->y = y;

	strcpy(texto->conteudo, conteudo);
	strcpy(texto->corBorda, corBorda);
	strcpy(texto->corPreenchimento, corPreenchimento);

	return texto;
}

// TODO: Arrumar para ser acessado fora
void freeTexto(Texto textoParametro) {
	free(textoParametro);
}

Texto* getVetorTextos() {
	return vetorTextos;
}

void alocarVetorTextos(int tamanho) {
	vetorTextos = getVetorTextos();
	vetorTextos = malloc(tamanho * sizeof(struct structTexto));
}

void inicializarVetorTextos(int tamanho) {
	for(int i = 0; i < tamanho; i++) {
		vetorTextos[i] = NULL;
	}
}

void freeVetorTextos(int tamanho) {
	for(int i = 0; i < tamanho; i++) {
		if(vetorTextos[i] != NULL) {
			freeTexto(vetorTextos[i]);
		}
	}
	free(vetorTextos);
}
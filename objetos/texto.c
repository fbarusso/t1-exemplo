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

static int contador = -1;

Texto texto_criar(int id, double x, double y, char* conteudo, char* corBorda, char* corPreenchimento) {

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

int texto_getContador() {
	contador++;
	return contador;
}

int texto_getId(Texto parametroTexto) {
	ponteiroTexto texto = (ponteiroTexto) parametroTexto;
	return texto->id;
}

double texto_getX(Texto parametroTexto) {
	ponteiroTexto texto = (ponteiroTexto) parametroTexto;
	return texto->x;
}

double texto_getY(Texto parametroTexto) {
	ponteiroTexto texto = (ponteiroTexto) parametroTexto;
	return texto->y;
}

char* texto_getConteudo(Texto parametroTexto) {
	ponteiroTexto texto = (ponteiroTexto) parametroTexto;
	return texto->conteudo;
}

char* texto_getCorBorda(Texto parametroTexto) {
	ponteiroTexto texto = (ponteiroTexto) parametroTexto;
	return texto->corBorda;
}

char* texto_getCorPreenchimento(Texto parametroTexto) {
	ponteiroTexto texto = (ponteiroTexto) parametroTexto;
	return texto->corPreenchimento;
}

// TODO: Arrumar para ser acessado fora
void texto_free(Texto textoParametro) {
	free(textoParametro);
}

Texto* texto_getVetor() {
	return vetorTextos;
}

void texto_alocarVetor(int tamanho) {
	vetorTextos = texto_getVetor();
	vetorTextos = malloc(tamanho * sizeof(struct structTexto));
}

void texto_inicializarVetor(int tamanho) {
	for(int i = 0; i < tamanho; i++) {
		vetorTextos[i] = NULL;
	}
}

void texto_freeVetor(int tamanho) {
	for(int i = 0; i < tamanho; i++) {
		if(vetorTextos[i] != NULL) {
			texto_free(vetorTextos[i]);
		}
	}
	free(vetorTextos);
}
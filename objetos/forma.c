#include "forma.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct structForma {
	int id;
	double x, y, r, w, h;
	char corBorda[32], corPreenchimento[32], tipo[4];
};

typedef struct structForma * ponteiroForma;

static Forma* vetorFormas;

Forma criarForma(int id, double x, double y, double r, double w, double h, char* corBorda, 
char* corPreenchimento, char* tipo) {

	ponteiroForma forma;

	forma = malloc(sizeof(struct structForma));

	forma->id = id;
	forma->r = r;
	forma->x = x;
	forma->y = y;
	forma->w = w;
	forma->h = h;

	strcpy(forma->corBorda, corBorda);
	strcpy(forma->corPreenchimento, corPreenchimento);
	strcpy(forma->tipo, tipo);

	return forma;
}

int getFormaId(Forma formaParametro) {
	ponteiroForma forma = (ponteiroForma) formaParametro;
	return forma->id;
}

char* getFormaTipo(Forma formaParametro) {
	ponteiroForma forma = (ponteiroForma) formaParametro;
	return forma->tipo;
}

// TODO: Arrumar para ser acessado fora
void freeForma(Forma formaParametro) {
	free(formaParametro);
}

Forma* getVetorFormas() {
	return vetorFormas;
}

void alocarVetorFormas(int tamanho) {
	vetorFormas = getVetorFormas();
	vetorFormas = malloc(tamanho * sizeof(struct structForma));
}

void inicializarVetorFormas(int tamanho) {
	for(int i = 0; i < tamanho; i++) {
		vetorFormas[i] = NULL;
	}
}

void freeVetorFormas(int tamanho) {
	for(int i = 0; i < tamanho; i++) {
		if(vetorFormas[i] != NULL) {
			freeForma(vetorFormas[i]);
		}
	}
	free(vetorFormas);
}
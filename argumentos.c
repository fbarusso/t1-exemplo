#include "argumentos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* caminhoEntradaGeo = NULL;
static char* caminhoEntradaQry = NULL;

static char* caminhoSaidaSvg = NULL;
static char* caminhoSaidaConsultaSvg = NULL;
static char* caminhoSaidaConsultaTxt = NULL;

static bool flagConsulta = false;

void setFlagConsulta() {
	flagConsulta = true;
}

bool getFlagConsulta() {
	return flagConsulta;
}

char* getCaminhoEntrada(char* diretorioEntrada, char* nomeEntrada) {
    char * caminhoEntrada;
    char * copiaDiretorioEntrada;
    int i, j, k;

    if(diretorioEntrada == NULL) {
        copiaDiretorioEntrada = (char*) malloc(3 * sizeof(char));
        strcpy(copiaDiretorioEntrada, "./");
    }

    else {
		copiaDiretorioEntrada = malloc((strlen(diretorioEntrada) + 1) * sizeof(char));
        strcpy(copiaDiretorioEntrada, diretorioEntrada);
    }

    if(copiaDiretorioEntrada[strlen(copiaDiretorioEntrada)-1] != '/') {
        k = strlen(copiaDiretorioEntrada);
        copiaDiretorioEntrada = realloc(copiaDiretorioEntrada, (strlen(copiaDiretorioEntrada) + 2) * sizeof(char));
        copiaDiretorioEntrada[k] = '/';
        copiaDiretorioEntrada[k+1] = '\0';
    }

	caminhoEntrada = (char * ) malloc((strlen(copiaDiretorioEntrada) + strlen(nomeEntrada) + 1) * sizeof(char));
    sprintf(caminhoEntrada, "%s%s", copiaDiretorioEntrada, nomeEntrada);

    free(copiaDiretorioEntrada);

    return caminhoEntrada;
}

char* formatarNomeEntrada(char* nomeEntrada) {
    int i, j, k;
    char * nomeEntradaFormatadoExtensao;
    char * nomeEntradaFormatado;

    for(i = strlen(nomeEntrada) - 1; i > 0; i--) {
        if(nomeEntrada[i] == '/') {
            break;
        }
    }

    k = strlen(nomeEntrada) - i;

    if(i != 0) {

        nomeEntradaFormatadoExtensao = (char*) malloc(k * sizeof(char));

        for(j = 0; j < k; j++) {
            nomeEntradaFormatadoExtensao[j] = nomeEntrada[j + i + 1];
        }

    }

    else {
        nomeEntradaFormatadoExtensao = (char*) malloc((strlen(nomeEntrada) + 1) * sizeof(char));
        strcpy(nomeEntradaFormatadoExtensao, nomeEntrada);
    }

    for(i = 0; i < strlen(nomeEntradaFormatadoExtensao); i++) {
        if (nomeEntradaFormatadoExtensao[i] == '.') {
            break;
        }
    }

    nomeEntradaFormatado = malloc((i + 1) * sizeof(char));

    for(j = 0; j < i; j++) {
        nomeEntradaFormatado[j] = nomeEntradaFormatadoExtensao[j];
    }

    nomeEntradaFormatado[i] = '\0';

    free(nomeEntradaFormatadoExtensao);

    return nomeEntradaFormatado;
}

// Formato 'g' -> diretorioSaida / nomeEntradaGeoFormatado . extensao
// Formato 'q' -> diretorioSaida / nomeEntradaGeoFormatado - nomeEntradaQryFormatado . extensao
char* getCaminhoSaida(char* diretorioSaida, char* nomeEntradaGeo, char* nomeEntradaQry, 
char extensao[], char formato) {
    char * nomeEntradaGeoFormatado = NULL;
    char * nomeEntradaQryFormatado = NULL;
    char * caminhoSaida = NULL;
    char * copiaDiretorioSaida = NULL;
    int k = 0;

    copiaDiretorioSaida = (char*) malloc((strlen(diretorioSaida) + 1) * sizeof(char));
    strcpy(copiaDiretorioSaida, diretorioSaida);

    if(copiaDiretorioSaida[strlen(copiaDiretorioSaida)-1] != '/') {
        k = strlen(copiaDiretorioSaida);
        copiaDiretorioSaida = realloc(copiaDiretorioSaida, (strlen(copiaDiretorioSaida) + 2) * sizeof(char));
        copiaDiretorioSaida[k] = '/';
        copiaDiretorioSaida[k+1] = '\0';
    }

    nomeEntradaGeoFormatado = formatarNomeEntrada(nomeEntradaGeo);

    if(formato == 'g') {
        caminhoSaida = malloc((strlen(copiaDiretorioSaida) + 
        strlen(nomeEntradaGeoFormatado) + 
        strlen(extensao) + 2) * sizeof(char));
        sprintf(caminhoSaida, "%s%s.%s", copiaDiretorioSaida, nomeEntradaGeoFormatado, extensao);
    }

    else if(formato == 'q') {
        nomeEntradaQryFormatado = formatarNomeEntrada(nomeEntradaQry);

        caminhoSaida = malloc((strlen(copiaDiretorioSaida) + strlen(nomeEntradaGeoFormatado) + strlen(nomeEntradaQryFormatado) + strlen(extensao) + 3) * sizeof(char));
        sprintf(caminhoSaida, "%s%s-%s.%s", copiaDiretorioSaida, nomeEntradaGeoFormatado, nomeEntradaQryFormatado, extensao);

        free(nomeEntradaQryFormatado);
    }

    free(copiaDiretorioSaida);
    free(nomeEntradaGeoFormatado);

    return caminhoSaida;
}

void setCaminhoEntradaGeo(char* diretorioEntrada, char* nomeEntradaGeo) {
    caminhoEntradaGeo = getCaminhoEntrada(diretorioEntrada, nomeEntradaGeo);
}

void setCaminhoEntradaQry(char* diretorioEntrada, char* nomeEntradaQry) {
    caminhoEntradaQry = getCaminhoEntrada(diretorioEntrada, nomeEntradaQry);
}

void setCaminhoSaidaSvg(char* diretorioSaida, char* nomeEntradaGeo) {
    caminhoSaidaSvg = getCaminhoSaida(diretorioSaida, nomeEntradaGeo, NULL, "svg", 'g');
}

void setCaminhoSaidaConsultaSvg(char* diretorioSaida, char* nomeEntradaGeo, char* nomeEntradaQry) {
    caminhoSaidaConsultaSvg = getCaminhoSaida(diretorioSaida, nomeEntradaGeo, nomeEntradaQry, "svg", 'q');
}

void setCaminhoSaidaConsultaTxt(char* diretorioSaida, char* nomeEntradaGeo, char* nomeEntradaQry) {
    caminhoSaidaConsultaTxt = getCaminhoSaida(diretorioSaida, nomeEntradaGeo, nomeEntradaQry, "txt", 'q');
}

char* getCaminhoEntradaGeo() {
    return caminhoEntradaGeo;
}

char* getCaminhoEntradaQry() {
    return caminhoEntradaQry;
}

char* getCaminhoSaidaSvg() {
    return caminhoSaidaSvg;
}

char* getCaminhoSaidaConsultaSvg() {
    return caminhoSaidaConsultaSvg;
}

char* getCaminhoSaidaConsultaTxt() {
    return caminhoSaidaConsultaTxt;
}

void freeCaminhos() {
    // Caminhos obrigatorios
    free(caminhoEntradaGeo);
	free(caminhoSaidaSvg);

    // Caminhos opcionais
    if(flagConsulta) {
		free(caminhoEntradaQry);
		free(caminhoSaidaConsultaSvg);
		free(caminhoSaidaConsultaTxt);
	}
}
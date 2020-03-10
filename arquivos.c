#include "arquivos.h"

#include <stdio.h>
#include <stdlib.h>
#include "argumentos.h"

static FILE* arquivoEntradaGeo = NULL;
static FILE* arquivoEntradaQry = NULL;
static FILE* arquivoSaidaSvg = NULL;
static FILE* arquivoSaidaConsultaSvg = NULL;
static FILE* arquivoSaidaConsultaTxt = NULL;

FILE* verificarArquivo(FILE* arquivo, char* caminho) {
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", caminho);
        exit(1);
    }
}

void setArquivoEntradaGeo() {
    arquivoEntradaGeo = fopen(getCaminhoEntradaGeo(), "r");
    verificarArquivo(arquivoEntradaGeo, getCaminhoEntradaGeo());
}

void setArquivoEntradaQry() {
    arquivoEntradaQry = fopen(getCaminhoEntradaQry(), "r");
    verificarArquivo(arquivoEntradaQry, getCaminhoEntradaQry());
}

void setArquivoSaidaSvg() {
    arquivoSaidaSvg = fopen(getCaminhoSaidaSvg(), "w");
    verificarArquivo(arquivoSaidaSvg, getCaminhoSaidaSvg());
}

void setArquivoSaidaConsultaSvg() {
    arquivoSaidaConsultaSvg = fopen(getCaminhoSaidaConsultaSvg(), "w");
    verificarArquivo(arquivoSaidaConsultaSvg, getCaminhoSaidaConsultaSvg());
}

void setArquivoSaidaConsultaTxt() {
    arquivoSaidaConsultaTxt = fopen(getCaminhoSaidaConsultaTxt(), "w");
    verificarArquivo(arquivoSaidaConsultaTxt, getCaminhoSaidaConsultaTxt());
}

FILE* getArquivoEntradaGeo() {
    return arquivoEntradaGeo;
}

FILE* getArquivoEntradaQry() {
    return arquivoEntradaQry;
}

FILE* getArquivoSaidaSvg() {
    return arquivoSaidaSvg;
}

FILE* getArquivoSaidaConsultaSvg() {
    return arquivoSaidaConsultaSvg;
}

FILE* getArquivoSaidaConsultaTxt() {
    return arquivoSaidaConsultaTxt;
}

void freeArquivos() {
    fclose(arquivoEntradaGeo);
    fclose(arquivoSaidaSvg);

    if(getFlagConsulta()) {
        fclose(arquivoEntradaQry);
        fclose(arquivoSaidaConsultaSvg);
        fclose(arquivoSaidaConsultaTxt);
    }
}
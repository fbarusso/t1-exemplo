#ifndef _ARQUIVOS_H_
#define _ARQUIVOS_H_

#include <stdio.h>

void setArquivoEntradaGeo();

void setArquivoEntradaQry();

void setArquivoSaidaSvg();

void setArquivoSaidaConsultaSvg();

void setArquivoSaidaConsultaTxt();

FILE* getArquivoEntradaGeo();

FILE* getArquivoEntradaQry();

FILE* getArquivoSaidaSvg();

FILE* getArquivoSaidaConsultaSvg();

FILE* getArquivoSaidaConsultaTxt();

void freeArquivos();

#endif

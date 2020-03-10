#ifndef _ARGUMENTOS_H_
#define _ARGUMENTOS_H_

#include <stdbool.h>

void setFlagConsulta();

bool getFlagConsulta();

void setCaminhoEntradaGeo(char* diretorioEntrada, char* nomeEntradaGeo);

void setCaminhoEntradaQry(char* diretorioEntrada, char* nomeEntradaQry);

void setCaminhoSaidaSvg(char* diretorioSaida, char* nomeEntradaGeo);

void setCaminhoSaidaConsultaSvg(char* diretorioSaida, char* nomeEntradaGeo, char* nomeEntradaQry);

void setCaminhoSaidaConsultaTxt(char* diretorioSaida, char* nomeEntradaGeo, char* nomeEntradaQry);

char* getCaminhoEntradaGeo();

char* getCaminhoEntradaQry();

char* getCaminhoSaidaSvg();

char* getCaminhoSaidaConsultaSvg();

char* getCaminhoSaidaConsultaTxt();

void freeCaminhos();

#endif

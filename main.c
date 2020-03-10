#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "argumentos.h"
#include "arquivos.h"
#include "processarEntrada.h"

int main(int argc, char * argv[]) {

	// Argumentos

	char * diretorioEntrada = NULL;
    char * nomeEntradaGeo = NULL;
    char * nomeEntradaQry = NULL;
    char * diretorioSaida = NULL;

	int i = 1;

	// Loop de argumentos

	while(i < argc) {
		if (strcmp("-e", argv[i]) == 0) {
			i++;
			diretorioEntrada = (char*) malloc((strlen(argv[i]) + 1) * sizeof(char));
			strcpy(diretorioEntrada, argv[i]);
		}

        if (strcmp("-f", argv[i]) == 0) {
			i++;
			nomeEntradaGeo = (char*) malloc((strlen(argv[i]) + 1) * sizeof(char));
			strcpy(nomeEntradaGeo, argv[i]);
		}

        if (strcmp("-q", argv[i]) == 0) {
			i++;
			nomeEntradaQry = (char*) malloc((strlen(argv[i]) + 1) * sizeof(char));
			strcpy(nomeEntradaQry, argv[i]);
			setFlagConsulta();
		}

        if (strcmp("-o", argv[i]) == 0) {
			i++;
			diretorioSaida = (char*) malloc((strlen(argv[i]) + 1) * sizeof(char));
			strcpy(diretorioSaida, argv[i]);
		}

		i++;
	}

	// Tratamento de argumentos

	setCaminhoEntradaGeo(diretorioEntrada, nomeEntradaGeo);
	setCaminhoSaidaSvg(diretorioSaida, nomeEntradaGeo);

	if(getFlagConsulta()) {
		setCaminhoEntradaQry(diretorioEntrada, nomeEntradaQry);
		setCaminhoSaidaConsultaSvg(diretorioSaida, nomeEntradaGeo, nomeEntradaQry);
		setCaminhoSaidaConsultaTxt(diretorioSaida, nomeEntradaGeo, nomeEntradaQry);
	}

	// Tratamento de arquivos

	setArquivoEntradaGeo();
	setArquivoSaidaSvg();

	if(getFlagConsulta()) {
		setArquivoEntradaQry();
		setArquivoSaidaConsultaSvg();
		setArquivoSaidaConsultaTxt();
	}

	// Funcao piloto

	processarEntrada();

	// Free

	freeCaminhos();
	freeArquivos();

	free(nomeEntradaGeo);
	free(diretorioSaida);

	if(diretorioEntrada != NULL) {
		free(diretorioEntrada);
	}

	if(nomeEntradaQry != NULL) {
		free(nomeEntradaQry);
	}

    return 0;
}
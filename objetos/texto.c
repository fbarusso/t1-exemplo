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


#ifndef __UTILS_H
#define __UTILS_H

// Biblioteca com funções auxiliares

#include <stdio.h>

// Conta quantas linhas um arquivo de entrada possui
int count_lines(FILE *fp);
// Lê e retorna quantas dimensões um ponto de um arquivo de entrada possui
int determine_dimensions(FILE *fp);
// Lê um arquivo de entrada (incompleto)
int read_input_file(FILE *fp, char **names, double *coordenates);

#endif

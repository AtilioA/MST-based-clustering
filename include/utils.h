#ifndef __UTILS_H
#define __UTILS_H

// Biblioteca com funções auxiliares

#include <stdio.h>
#include "../include/union_find.h"

// Conta quantas linhas um arquivo de entrada possui
int count_lines(FILE *fp);
// Lê e retorna quantas dimensões um ponto de um arquivo de entrada possui
int determine_dimensions(FILE *fp);
// Lê um arquivo de entrada
int read_input_file(FILE *fp, char **names, double *coordenates);
// Escreve os grupos num arquivo de saída
void write_output_file(FILE *fpOut, Point **points, UF *MST);

#endif

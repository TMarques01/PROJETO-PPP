#ifndef PROJETO_HEADER_PROJETO_H
#define PROJETO_HEADER_PROJETO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct cliente
{
    long telemovel;
    char nome[100];
};

struct horas
{
    int horas,minutos;
};

struct data
{
    int dia,mes,ano;
};

//STRUCT RESERVA

typedef struct reserva
{
    struct cliente Cliente;
    struct data Data; // FORMATO (DD/MM/AAAA);
    int tipo_reserva; //0 == MANUTENÇÃO || 1 == LAVAGEM  
    struct horas horas_inicio;
    struct horas horas_fim;
    struct reserva *prox;
}reserva;

typedef reserva *Reserva;

//STRUCT PRE_RESERVA

typedef struct pre_reserva
{
    struct reserva pre_reservaa;
    struct pre_reserva *prox;
}pre_reserva;

typedef pre_reserva *Pre_reserva;

typedef struct l_cliente
{
    struct reserva ord_cliente;
    char lista[50];
    struct l_cliente *prox;
}l_cliente;

typedef l_cliente *L_cliente;

#endif

#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
#include "ponto.h"

struct circulo{
	tPonto centro;
    float raio;
};

tCirculo Circulo_Cria (float x, float y, float r)
{
	tCirculo c = (tCirculo) calloc (1, sizeof(struct circulo));
	c -> centro = Pto_Cria(x, y);
	c -> raio = r;

	return c;
}

void Circulo_Apaga (tCirculo c)
{
	Pto_Apaga(c -> centro);
	free(c);
}

tPonto Circulo_Acessa_Centro (tCirculo c)
{
	return c -> centro;
}

float Circulo_Acessa_Raio (tCirculo c)
{
	return c -> raio;
}

void Circulo_Atribui_Centro (tCirculo c, tPonto p)
{
	c -> centro = p;
}

void Circulo_Atribui_Raio (tCirculo c, float r)
{
	c -> raio = r;
}

int Circulo_Interior (tCirculo c, tPonto p)
{
	float distancia;
	distancia = Pto_Distancia(c -> centro, p);
	if (distancia <= c -> raio)
		return 1;
	return 0;
}
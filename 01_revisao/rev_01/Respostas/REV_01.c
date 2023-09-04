#include <stdio.h>
#include <math.h>
#define PI 3.1415
/* se a distância de um ponto a outro for do tamanho do raio, então ele se colidem*/

int VerificarDistancia(double distancia_entre_pontos, float rA, float rD)
{
    float rMaior;
    rMaior = rA + rD;
    if (distancia_entre_pontos <= rMaior)
    {
        return 1;
    }
    return 0;
}

int VerificaColisao(float xA, float yA, float rA, float xD, float yD, float rD)
{
    float distanciaX, distanciaY;
    distanciaX = (xA - xD);
    distanciaY = (yA - yD);
    double distancia_entre_pontos;
    distancia_entre_pontos = sqrt((pow(distanciaX, 2)) + (pow(distanciaY, 2)));
    if (VerificarDistancia(distancia_entre_pontos, rA, rD) == 1)
    {
        return 1;
    }
        return 0;
}

void Imprimir (int verificar)
{
    if (verificar == 1)
    {
        printf("ACERTOU");
    }
    else if (verificar == 0)
    {
        printf("ERROU");
    }
    else
    {
        printf("Tem alguma coisa muito errada");
    }
}

int main()
{
    float xA, yA, rA;
    float xD, yD, rD;
    int verificar = 0;
    scanf("%f %f %f", &xA, &yA, &rA);
    scanf("%*c");
    scanf("%f %f %f", &xD, &yD, &rD);
    verificar = VerificaColisao(xA, yA, rA, xD, yD, rD);
    Imprimir(verificar);
    return 0;
}
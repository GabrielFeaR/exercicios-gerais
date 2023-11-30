#include <stdio.h>
#include "tadgen.h"

int main()
{
	printf("tad_gen_01\n");
	int tipo, num;
	printf("Digite o tipo e numero de elementos:");
	scanf("%d %d", &tipo, &num);
	tGeneric* generico = CriaGenerico(tipo, num);
	LeGenerico(generico);
	ImprimeGenerico(generico); 
	DestroiGenerico(generico);
	return 0;
}
#include "PECA.H"

struct peca{
	char cor;
};

Peca* criaPeca( char cor )
{
	Peca *nova = (Peca*) malloc (sizeof(Peca));
	nova->cor = cor;

	return nova;
}

void leCorPeca ( Peca *p )
{
	printf("Cor da Peça: %c\n", p->cor);
}

void destroiPeca( Peca *p )
{
	free(p);
}

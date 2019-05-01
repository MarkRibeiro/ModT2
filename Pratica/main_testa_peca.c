#include "PECA.H"

int main ()
{
	Peca *p[30];

	p[0] = criaPeca( 'b' );
	
	leCorPeca( p[0] );
	
	destroiPeca( p[0] );
	
	return 0;			
}
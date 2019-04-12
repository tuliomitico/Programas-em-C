#include <stdio.h>
#include <stdlib.h>
typedef struct reg{
	int k,carga;
	struct reg *esq,*dir;
} tree;

size_t b_bytes( void* buf );
size_t b_length( void* buf );
void b_deallocate( void* buf );
void* b_allocate( size_t siz, size_t len );

int main(void){
	tree* raiz,*folha,*noh;
	noh = (tree*) malloc( sizeof(tree));
	noh->k = 3;
	noh->dir = NULL;
	noh->esq = NULL;
	int i = 0;
	raiz = (tree*) malloc(sizeof(tree));
	raiz->k = 1;
	raiz->esq = NULL;
	raiz->dir = NULL;
	folha = (tree*) malloc(sizeof(tree));
	folha->k = 2;
	folha->dir = NULL;
	folha->esq = NULL;
	tree** node;
	node = (tree**) malloc (3 * sizeof (tree*));
	int  m =  4*sizeof(node);
	//node = b_allocate(sizeof(tree*), 4);
	*(node+0) =  raiz;
	*(node+1) =  folha;
	*(node+2) = noh;
	int n = /*b_bytes(node)*/ m/ sizeof(tree*);
	printf("%d\n",n);
	for (i; i < 3 ;i++)
		printf("%d\n",node[i]->k);
}

size_t* b_element_size_ptr_( void* buf )
{
    return ( size_t* )( ( char* )buf - sizeof( size_t ) );
}
 
size_t* b_length_ptr_( void* buf )
{
    return ( size_t* )( ( char* )buf - ( sizeof( size_t ) << 1 ) );
}
 
void* b_allocate( size_t siz, size_t len )
{
    char*
        buf = malloc( siz * len + ( sizeof( size_t ) << 1 ) );
    if( buf )
    {
        buf += sizeof( size_t ) << 1;
        *b_element_size_ptr_( buf ) = siz;
        *b_length_ptr_( buf ) = len;
    }
    return buf;
}
 
void b_deallocate( void* buf )
{
    if( buf )
        free( b_length_ptr_( buf ) );
}
 
size_t b_length( void* buf )
{
    return *b_length_ptr_( buf );
}
 
size_t b_bytes( void* buf )
{
    return b_length( buf ) * *b_element_size_ptr_( buf );
}

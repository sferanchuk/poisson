
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_HIST 10000
#define S_LEN 64000

int main( int argc, char **argv )
{
	FILE *f;
	char *buf;
	char *p[20];
	int *hist;
	int prevp;
	char prevchr[16];
	int n1 = 10, n2 = 11;
	int i, j, k;
	
	f = fopen( "chr_all.vcf", "rt" );
	buf = calloc( S_LEN, 1 );
	hist = calloc( N_HIST, sizeof( int ) );
	prevp = -1;
	prevchr[0] = 0;
	while ( fgets( buf, S_LEN, f ) )
	{
		if ( buf[0] == '#' ) continue;
		for ( i = 0, p[0] = strtok( buf, " \t" ); i < 20; i++, p[i] = strtok( 0, " \t" ) );
		if ( strcmp( p[0], prevchr ) != 0 )
		{
			strcpy( prevchr, p[0] );
			prevp = -1;
		}
		k = atoi( p[1] );
		if ( strcmp( p[ n1 ], p[ n2 ] ) == 0 ) continue;
		strrev( p[ n2 ] );
		if ( strcmp( p[ n1 ], p[ n2 ] ) == 0 ) continue;
		if ( prevp != -1 )
		{
			j = ( k - prevp ) / 10;
			if ( j < N_HIST ) hist[ j ]++;
		}
		prevp = k;
	}
	fclose( f );
	printf( "[" );
	for ( i = 0; i < N_HIST; i++ ) printf( "%d,", hist[i] );
	printf( "]\n" );
}
	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max_seq 500000

int cmp_int( const void *p1, const void *p2 )
{
	int i1 = *(int*)p1;
	int i2 = *(int*)p2;
	if ( i1 < i2 ) return 1;
	if ( i1 > i2 ) return -1;
	return 0;
}

int main( int argc, char **argv )
{
	FILE *f;
	char buf[4096];
	char *p;
	char **ids;
	int *cnt;
	int ns;
	int i, j, k;

	f = fopen( argv[1], "rt" );
	ns = 0;
	ids = calloc( max_seq, sizeof( void* ) );
	cnt = calloc( max_seq, sizeof( int ) );

	while ( fgets( buf, 4096, f ) )
	{
		if ( buf[0] == '@' ) continue;
		strtok( buf, "\t" );
		strtok( 0, "\t" );
		p = strtok( 0, "\t" );
		if ( p[0] == '*' ) continue;
		i = atoi( p ) - 1;
		if ( i + 1 > ns ) ns = i + 1;
		cnt[i]++;
	}
	fclose( f );
	qsort( cnt, ns, sizeof( int ), cmp_int );
	for ( k = 0; k < ns; )
	{
		printf( "[%d,%d],", k + 1, cnt[k] );
		if ( ns < 200 ) k = k + 1;
		else k += (int)( fmax( 1., exp( 0.2 * log( k + 1 ) ) ) );
	}
	printf( "\n" );
}


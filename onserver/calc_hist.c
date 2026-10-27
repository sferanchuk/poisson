
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IDS 20000000
#define MAX_HIST 10000
#define SSIZE 10000

int main( int argc, char **argv )
{
	FILE *f;
	char buf[4096];
	char **ids;
	int *lengths;
	int nseq;
	int **cnt;
	int *hist;
	char *p;
	int i, j, k;

	f = fopen( argv[1], "rt" );
	ids = malloc( MAX_IDS * sizeof( void* ) );
	lengths = malloc( MAX_IDS * sizeof( int ) );
	cnt = malloc( MAX_IDS * sizeof( void* ) );
	nseq = 0;
	while ( fgets( buf, 4096, f ) )
	{
		if ( buf[0] == '@' ) 
		{
			if ( strncmp( buf, "@SQ", 3 ) == 0 )
			{
				strtok( buf, " \t\n" );
				p = strtok( 0, " \t\n" );
				ids[ nseq ] = strdup( p + 3 );
				p = strtok( 0, " \t\n" );
				lengths[ nseq ] = atoi( p + 3 );
				cnt[ nseq ] = calloc( lengths[ nseq ] / SSIZE + 1, sizeof( int ) );
				nseq++;
			}
			continue;
		}
		strtok( buf, "\t" );
		strtok( 0, "\t" );
		p = strtok( 0, "\t" );
		if ( p[0] == '*' ) continue;
		k = atoi( strtok( 0, "\t" ) );
		k /= SSIZE;
		for ( i = 0; i < nseq; i++ )
		{
			if ( strcmp( p, ids[i] ) == 0 )
			{
				cnt[i][k]++; 
				break;
			}
		}
	}
	fclose( f );

	hist = calloc( MAX_HIST, sizeof( int ) );
	for ( i = 0; i < nseq; i++ )
	{
		for ( j = 0; j < lengths[i] / SSIZE; j++ )
		{
			k = cnt[i][j];
			if ( k < MAX_HIST ) hist[ k ]++;
		}
	}
	printf( "[" );
	for ( i = 0; i < MAX_HIST; i++ ) printf( "%d,", hist[i] );
	printf( "],\n" );
}

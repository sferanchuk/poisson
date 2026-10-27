
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_seq 500000000

int main( int argc, char **argv )
{
	FILE *f;
	char *seq;
	char buf[4096];
	char *p;
	int flen;
	int i, j, k, l;

	seq = calloc( max_seq, 1 );
	flen = atoi( argv[2] );
	f = fopen( argv[1], "rt" );
	i = 1;
	k = 0;
	while ( fgets( buf, 4096, f ) )
	{
		if ( buf[0] == '>' )
		{
			if ( k )
			{
				seq[k] = 0;
				for ( j = 0; j < k; j+= flen )
				{
					printf( ">%d\n%.*s\n", i, flen, seq + j );
					i++;
				}
				seq[0] = 0;
			}
			k = 0;
			continue;
		}
		l = strlen( buf ) - 1;
		strncpy( seq + k, buf, l );
		k += l;
	}
	if ( strlen( seq  ) )
	{
		for ( j = 0; j < strlen( seq ); j+= flen )
		{
			printf( ">%d\n%.*s\n", i, flen, seq + j );
			i++;
		}
	}
	fclose( f );
	free( seq );
}





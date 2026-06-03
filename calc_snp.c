
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MIN 3000
#define N_MAX 10000
#define L_MAX 100000

int main( int argc, char **argv )
{
	FILE *f;
	char buf[4096];
	char *seq1;
	char *seq2;
	int sl;
	int *hist;
	int lc;
	int state;
	int pos;
	char *p;
	int i, j, k;

	hist = calloc( N_MAX, sizeof( int ) );
	seq1 = malloc( L_MAX );
	seq2 = malloc( L_MAX );
	f = fopen( argv[1], "rt" );
	state = 0;
	lc = 0;
	while ( fgets( buf, 4096, f ) )
	{
		if ( buf[0] == '-' || buf[0] == '=' )
		{
			if ( lc > 0 && ( lc != strlen( seq1 ) || lc != strlen( seq2 ) ) )
			{
				fprintf( stderr, "%d %lu %lu\n", lc, strlen( seq1 ), strlen( seq2 ) );
			}
			if ( lc > N_MIN )
			{
				pos = -1;
				for ( i = 0; i < lc; i++ )
				{
					if ( seq1[i] != seq2[i] )
					{
						if ( seq1[i] == '.' || seq2[i] == '.' )
						{
							pos = -1;
							continue;
						}
						else
						{
							if ( pos != -1 )
							{
								j = i - pos;
								if ( j < N_MAX ) hist[j]++;
							}
							pos = i;
						}
					}
				}
			}
			state = 0;
			lc = 0;
		}
		else if ( buf[0] == ' ' || buf[0] == '\n' )
		{
			state = 1;
		}
		else
		{
			if ( lc < L_MAX - 80 )
			{
				strtok( buf, "\n" );
				strtok( buf, " " );
				p = strtok( 0, " " );
				if ( state == 1 ) 
				{
					strcpy( seq1 + lc, p );
					state = 2;
				}
				else if ( state == 2 )
				{
					strcpy( seq2 + lc, p );
					lc += strlen( p );
				}
			}
		}
	}

	printf( "[" );
	for ( i = 0; i < N_MAX; i++ ) printf( "%d,", hist[i] );
	printf( "],\n" );
}
		
			

	
#include <stdio.h>
#include <stdlib.h>


int main()
{
	double ** tm;
	int nr = 5;

	tm = (double**) malloc (nr * sizeof(double*));
	
	for(int i=0;i<nr;++i){
		tm[i] = malloc((i+1)*sizeof(double*));
	}

	for(int i = 0;i < nr;++i)
		for(int j = 0;j < i+1;j++)
			tm[i][j] = j+1;

	for(int i = 0;i < nr;++i)
	{
		printf("\n");
		for(int j = 0;j < i+1;j++)
			printf("%0.f ", tm[i][j]);
	}
		
	

	for(int i = 0;i < nr;++i)
		free(tm[i]);

	free(tm);



	return 0;
}
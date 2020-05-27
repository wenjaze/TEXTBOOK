#include <iostream>



int main()
{
	double ** tm;
	int nr = 5;

	tm = new double*[nr];
	
	for(int i=0;i<nr;++i){
		tm[i] = new double[i+1];
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
		delete [] tm[i];

	delete [] tm;



	return 0;
}
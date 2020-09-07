#include <stdlib.h>
#include <stdio.h>

int main()
{
	double ** tm;
	int sorSzam = 5;

	if ((tm = (double**) malloc(sorSzam * sizeof(double*))) == NULL)
		return -1;

	for (int i = 0;i < sorSzam;i++){
		if ((tm[i] = (double*) malloc ((i+1) * sizeof(double)))== NULL)
		{
			free(tm);
			return -1;
		}
	}
	int szamlalo = 0;
	// feltoltes ertekekkel
	for (int i = 0;i < sorSzam;i++)
	{
		for (int j = 0;j < i+1;j++){
			szamlalo++;
			tm[i][j] = szamlalo;
		}	
	}

	// kiiras formazva
	for (int i = 0;i < sorSzam;i++){
		for (int j = 0;j < i+1;j++){
			printf("%0.f ",tm[i][j]);
			if (tm[i][j] <= 9) printf(" ");
		}	
		printf("\n");
	}

	tm[3][0] = 42.0;
	(*(tm+3))[1] = 43.0; // ha nincsen zárójel akkor a [1]-nek magasabb a precedenciája mind a dereference operatornak
	*(tm[3]+2) = 44.0;
	*(*(tm+3)+3) = 45.0;


	// kiiras formazva ujra
	for (int i = 0;i < sorSzam;i++){
		for (int j = 0;j < i+1;j++){
			printf("%0.f ",tm[i][j]);
			if (tm[i][j] <= 9) printf(" ");
		}	
		printf("\n");
	}

	// elemek felszabaditasa
	for (int i = 0;i < sorSzam;i++){
		free(tm[i]);
	}


	// tm felszab
	free(tm);

	return 0;
}
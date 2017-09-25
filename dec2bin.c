#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

void get_dec_frac_in_argument(char number[], int *decimal, double *fraction) {
	
	bool is_already_passed_point = false;
	char dec[20];
	char frac[20];
	int i;
	int index_dec=0;
	int index_frac=0;
	for(i=0; number[i] != '\0'; i++) {
		if(number[i] == '.' || number[i] == ',') {
			is_already_passed_point =true;
			continue;
		}

		if(is_already_passed_point == false) {
			dec[index_dec]=number[i];
			index_dec++;
		}else{
			frac[index_frac] = number[i];
			index_frac++;
		}
	}	

	*decimal = atoi(dec);
	*fraction = atoi(frac)/(pow(10,strlen(frac)));
}

void KonvDes(ListStack *L,int Desimal, int Basis)
{
	while(Desimal != 0)
	{
		Push(&(*L),Desimal%Basis);
		Desimal=Desimal/Basis;
	}
}

void KonFrac(ListQue *L, double frac, int precision) 
{ 
	// printf("%lf\n",frac );
	while(precision--)
	{
		frac*=2;
		// printf("%lf\n",frac );
		int frac_bit = frac;
		if(frac_bit == 1) 
		{
			frac -= frac_bit;
			// printf("%lf\n",frac );
			Enque(&(*L),1);
		}
		else
		{
			Enque(&(*L),0);
		}	
	}
}

int main(int argc, char *argv[])
{
	ListStack stackDec;
	ListQue fracQue; 

	int decimal;
	double fraction;
    CreateListStack(&stackDec);
    CreateListQue(&fracQue);
	get_dec_frac_in_argument(argv[1],&decimal,&fraction);
	KonvDes(&stackDec,decimal,2);
	KonFrac(&fracQue,fraction, atoi(argv[2]));
    PrintInfoStack(stackDec);
    printf(".");
    PrintInfoQue(fracQue);
    printf("\n");
	return 0;
}









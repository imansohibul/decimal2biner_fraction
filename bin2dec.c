#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void get_dec_frac_in_argument(char number[], char decimal[], char fraction[]) {
	
	bool is_already_passed_point = false;
	int i;
	int index_dec=0;
	int index_frac=0;
	for(i=0; number[i] != '\0'; i++) {
		if(number[i] == '.') {
			is_already_passed_point =true;
			continue;
		}

		if(is_already_passed_point == false) {
			decimal[index_dec]=number[i];
			index_dec++;
		}else{
			fraction[index_frac] = number[i];
			index_frac++;
		}
	}	
}

int KonvDes(char desimal[])
{
	int i=0;
	int sum=0;
	int npow= strlen(desimal) -1;
	while(desimal[i] != '\0' && npow >= 0)
	{
		sum = sum + ((desimal[i]-'0')*pow(2,npow));
		npow--;
		i++;
	}

	return sum;
}

double KonvFrac(char frac[]) 
{ 

	int i=0;
	double sum=0;
	int npow= 1;
	printf("%s\n",frac );
	while(frac[i] != '\0')
	{
		sum = sum + ((frac[i] - '0')*(1/pow(2,npow)));
		npow++;
		i++;
	}

	return sum;

}

int main(int argc, char *argv[])
{
	char decimal[20];
	char fraction[20];
	get_dec_frac_in_argument(argv[1],decimal,fraction);
	int a=KonvDes(decimal);
	double b= KonvFrac(fraction);
	printf("%lf\n", a+b);
	return 0;
}









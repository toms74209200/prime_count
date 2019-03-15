/* 
 * Project: Prime number counter
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2018/12/04
 * Copyright (c) 2019 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	int i,j,k;
	int ary_prime[10000];
	int *p_prime;

	p_prime = &ary_prime[0];

	*(p_prime++) = 2;

	for(i=3;i<=10000;i+=2)
	{
		k=0;
		for(j=3;j<=sqrt(i);j+=2)
		{
			if(i%j==0)
			{
				k=1;
				break;
			}
		}

		if (k==0) {
			*(p_prime++) = i;
		}
	}

	p_prime = &ary_prime[0];

// Make data file
	FILE *data, *gp;
	char *data_file;
	int x;

	data_file="out.dat";
	data = fopen(data_file,"w");
		while(*p_prime){
			x = *(p_prime++);
			fprintf(data,"%d\n", x);
		}
	fclose(data);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

// woody >>>
// test2
// woody <<<
int main ()
{
        FILE *fp_default;
	char aline[20];
        int c;
	unsigned char j=1;

        /*fp_default = fopen("aaa.txt","w");
	fprintf(fp_default,"SMTP_Default=%d\n",j);
	fclose(fp_default);*/

        fp_default = fopen("aaa.txt","r");
	if(NULL != fp_default)
	{
		fgets(aline,20,fp_default);
		sscanf(aline,"SMTP_Default=%c",&j);
		printf("j = %c\n",j);
		fclose(fp_default);
	}


        /*while(1)
        {
                c = fgetc(fp);
                if( feof(fp) )
                { 
                        break ;
                }
                printf("%c", c);
        }*/

        return(0);
}

#include <stdio.h>
#include <string.h>
#include <math.h>
char binary[100000], tape[100000], sentence[100000];
int main()
{
    int decimal, i, j, k, len_tape, L=0, flag;

    flag=0;
    while(gets(tape))
    {
        len_tape=strlen(tape);

        for(i=0, k=0; i<len_tape; i++)
        {
            if(tape[i]=='o')
            {
                binary[k++]='1';
                flag=1;
            }
            else if(tape[i]==' ')
            {
                binary[k++]='0';
            }
        }
        binary[k]='\0';

        //printf("%s\n", binary);

        for(i=0, decimal=0; i<k; i++)
        {

            decimal+=pow(2, ((k-1)-i))*(binary[i]-'0');
        }

        sentence[L++]=decimal;

        if(tape[0]=='_' &&tape[1]=='_' &&tape[2]=='_' &&tape[3]=='_' &&tape[4]=='_' &&tape[5]=='_' &&tape[6]=='_' &&tape[7]=='_' &&tape[8]=='_' &&tape[9]=='_' &&tape[10]=='_')
        {
            for(i=0; i<L-1; i++)
                printf("%c", sentence[i]);
            L=0;
        }
    }
}

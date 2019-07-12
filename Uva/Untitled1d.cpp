#include <stdio.h>
#include <string.h>
const int ch[12]={0,128,64,32,16,8,0,4,2,1};
int main()
{
	int s,len,i;
	char a[15];
	while (gets(a)!=NULL)
	{
		s=0;
		if (a[0]!='|' ) continue;
		len=strlen(a);
		for(i=0;i<len;i++)
		{
			if(a[i]=='o') s+=ch[i];
		}

		putchar(s);
	}
	return 0;
}

#include<stdio.h>
#include<ctype.h>
int main()
{
   int key;
   char text[500],ch;
   printf("enter the text : ");
   scanf("%s",text);
   printf("enter the key val : ");
   scanf("%d",&key);
   for (int i=0; text[i]!='\0';i++)
   {
       ch=text[i];
		if(isalnum(ch))
		{
			ch=(ch-'a'+ key) %26+'a';
		}
		text[i]=ch;
	}
	printf("encrypted text :%s",text);
	for(int j=0;text[j]!='\0';j++)
	{
		   ch=text[j];
		if(isalnum(ch))
		{
			ch=(ch-'a'-key+26) %26+'a';
		}
		text[j]=ch;
	}
 printf("\ndecrypted text :%s",text);
 return 0;
}
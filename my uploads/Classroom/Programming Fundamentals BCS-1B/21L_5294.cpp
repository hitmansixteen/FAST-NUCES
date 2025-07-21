#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

void replace3(char para[],char find[],char replace[], int len_para, int len_find, int len_replace,int count,int i)
{
	int diff=len_find-len_replace;
	for(int j=len_para;j>=i;j--)
	{
		para[j]=para[j+diff];
	}

	for(int k=0;k<len_replace;k++)
	{
		para[k+i]=replace[k];
	}
}

void replace2(char para[],char find[],char replace[], int len_para, int len_find, int len_replace,int count,int i)
{
	int diff=len_find-len_replace;
	for(int j=i;para[j]!='\0';j++)
	{
		para[j]=para[j+diff];
	}
	
	for(int k=0;k<len_replace;k++)
	{
		para[k+i]=replace[k];
	}
}

void replace1(char para[],char find[],char replace[], int len_para, int len_find, int len_replace,int count,int i)
{

	for(int k=0;k<len_replace;k++)
	{
		para[k+i]=replace[k];
	}		
		
}


void findnReplaceText(char para[],char find[],char replace[])
{
	int count;
	int len_para = strlen(para);
	int len_find = strlen(find);
    int len_replace = strlen(replace);

	for(int i=0;i<len_para-len_find;i++)
	{
		count=0;
		for(int j=0;j<len_find;j++)
		{

			if(para[i+j]==find[j])
			{
				count++;
			}
		}
		if(count==len_find&&(para[i+len_find]==' '&&para[i-1]==' '))
		{
				
			if(len_find==len_replace)

				replace1(para,find,replace,len_para,len_find,len_replace,count,i);
			else if(len_find>len_replace)
				replace2(para,find,replace,len_para,len_find,len_replace,count,i);
			else
				replace3(para,find,replace,len_para,len_find,len_replace,count,i);
				
		}		
		
	
	}
	cout<<endl<<endl<<para;
		
    
}
int main()
{
	char para[500] = "Cheating is the getting of a reward for ability by dishonest means or finding an easy way out of an unpleasant situation. It is generally used in situations to gain unfair advantage in a competitive situation. This broad definition will necessarily include acts of bribery, cronyism, sleaze, nepotism and any situation where individuals are given preference using inappropriate criteria.";
	char find[10], replace[10];
	cout << "The paragraph:" << endl << para << endl << endl;
	cout << "What to Find: ";
	gets(find);
	cout << "What to Replace: ";
	gets(replace);
	cout << "the new text is ";
	findnReplaceText(para, find, replace); //...write function call here. 


		return 0;
}

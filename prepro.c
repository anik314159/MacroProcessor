#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int nooflines(FILE*fp)
{	
	int count=0;
	char ch = fgetc(fp);
	while(ch!=EOF)
	{	
		ch= fgetc(fp);
		if(ch=='\n')
		count++;
	}
	return count;
}
	

char* readline(FILE **fp)//char del)
{
	//fp is readable file;
	//fp =fopen("code.c","r");
	char*str=(char*)malloc(100) ;
	int	c=0;
	while(1)
	{
		char ch = fgetc(*fp);
		if(ch =='\n')
		return str;
	
		str[c++]=ch;
	    if(ch == EOF)
		return NULL;
	}
};
char* catchmacro(char mode, char* filelocation)
{
	FILE*finc = fopen(filelocation,"r");
	int n = nooflines(finc);
	fclose(finc);

	FILE* fin = fopen(filelocation,"r");
	char* search = (char*)malloc(30);
	char* replace = (char*)malloc(30);
	char* temp = (char*) malloc(100);
	
	for(int i = 0 ;i<n;i++)
	{
		char* line  = readline(&fin);
		strcpy(temp,line);
	
	
		if(strstr(temp,"#define")==temp)
		{
			int cnt=7;
			int cnt1;
			temp+=7;
			while(*temp)
			{
				if(*temp==' ')
				{
					cnt++;
				}
				temp++;
			}
			
			temp =line;
			
			strcpy(replace,&line[cnt+1]);
			temp[cnt]='\0';
			strcpy(search,&temp[8]);
			
		

		}
			
		fclose(fin);
		if(mode=='s')
		{
			return search;
		}
		else
		{
			return replace;
		}
		
	}
	
}
#
char* searchreplace(char* base,char* news,char* olds)
{
	char*result;
	int newlen=strlen(news);
	int oldlen=strlen(olds);
	int i, cnt=0;
	
	for( i =0 ;base[i]!='\0';i++)
	{
		if(strstr(base+i,olds)==base+i)
		{
			cnt++;
			i+=oldlen-1;
		}
	}
	int index=0;
	result = (char*)malloc(i+cnt*(abs(newlen-oldlen))+1);
	while(*base!='\0')
	{
		if(strstr(base,olds)==base)
		{
			strcpy(result+index,news);
			index+=newlen;
			base+=oldlen;
		}

		else
		{
			result[index]=*base;
			index++;
			base++;
		}


	}
	result[index]='\0';

	return result;
}
void writeline(FILE *fout , char*str)
{
	fputs(str,fout);
	fputs("\n",fout);
   
}
void  ctchmacro(char*str,char*search,char*replace)
{
	//for(int i = 0 ;i<n;i++)
	//{
				
		 search = (char*)malloc(30);
		 replace = (char*)malloc(30);
		
		char* temp = (char*) malloc(100);
		char* te = (char*) malloc(50);	

		strcpy(temp,str);	
	
		if(strstr(temp,"#define")==temp)
		{
			int cnt=8;
			int cnt1;
			temp+=8;
			te =temp;	
			

			while(*temp != ' ')
			{
				
			
				cnt++;
					
				
				temp++;
			}
			*temp='\0';

			strcpy(search,te);
			
			
			strcpy(replace,&str[cnt+1]);
			temp[cnt]='\0';
					

		}
//	}
//	printf("%s\n",search);
//	printf("%s\n",replace);


			
	
}

 
void Driver()
{
	FILE* fin = fopen("code.c","r");
//	char* filedeposit=(char*) malloc(16);
//	strcpy(filedeposit,".tmp");

	int count = nooflines(fin);
	fclose(fin);

	char A[10];
	char*lino = (char*)malloc(100);
	char*temp = (char*)malloc(100);
	char*search=(char*)malloc(30);
	char*replace = (char*)malloc(30);
	FILE * fin1 =fopen("code.c","r");
	while(1)
	{
		lino = readline(&fin1);
		temp =lino;
	//	fscanf(fin1,"%s",A);
		if(strstr(lino,"#define")==lino)
		{
			/*fscanf(fin,"%s",search);
			fscanf(fin,"%s",replace);
			printf("%s",search);
			printf("%s",replace);
			fclose(fin);*/
//			search =ctchmacro('s',"code.c");
//	i		replace =ctchmacro('r',"code.c");
			int cnt =8;
			temp=temp+8;
			char*te = temp;
			while(*temp!=' ')
			{
				cnt++;
				temp++;
			}
			*temp='\0';
			strcpy(search,te);
			strcpy(replace,&lino[cnt+1]);
			temp[cnt]='\0';


			
	//	ctchmacro(lino,search,replace);
			break;
		}
	}

//	search = catchmacro('s',"code.c");
//	replace = catchmacro('r',"code.c");

	FILE* fin2 = fopen("code.c","r");
	FILE* fout = fopen("code.tmp2.c","w");
	char* searched=(char*) malloc(10);
	for(int i =0 ;i<count;i++)
	{
		char*st = readline(&fin2);
		
		if(st[0]=='#')
		{
			writeline(fout,st);
			continue;
		}

		else
		{
			searched = searchreplace(st,replace,search);
			writeline(fout,searched);

		}

	}
	fclose(fout);
	fclose(fin2);
}



    


int main()
{
	/*FILE* fin ;
    FILE *fout;
	fin= fopen("code.c","r");
	fout= fopen("code.tmp.c","w");
	int count = nooflines(fin);
	fclose(fin);
    FILE* fin1= fopen("code.c","r");		
	for(int i =0 ;i<count;i++)
	{
		char* st = readline(&fin1);
		writeline(fout,st);		 
	
	}*/


	Driver();
		

}
		

	


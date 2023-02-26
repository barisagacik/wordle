#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

char words [][6] = {"ROKET","ARABA","BITKI","SEBZE","DENIZ"};
char word[5], guess[5], knownWords[5], table[6][5];
int indis, index, answer;

void createWord()
{
	srand(time(0));
	indis = rand()%5;
	int i = 0;
	while(i<5)
	{
		word[i]=words[indis][i];
		i++;
	}
	index = 0;
	answer = 0;
	
	
}

void green()
{
	HANDLE renk = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( renk, FOREGROUND_GREEN );
}

void baseColour()
{
	HANDLE renk = GetStdHandle(STD_OUTPUT_HANDLE ) ; 
	SetConsoleTextAttribute(renk, FOREGROUND_INTENSITY);
}

void blue()
{
HANDLE renk = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute(renk, FOREGROUND_BLUE);
}

int fillTable()
{
	int i;
	answer=1;
	for(i=0; i<5; i++)
	{
		if(word[i] != guess[i])
		{
			answer=0;
		}
		
		table[index][i]=guess[i];
	}
	index++;
	
	return answer;
}

void printTable()
{
	int i, j;

	
	for ( i =0; i<6; i++   ) 
	{
		printf("\t\t") ; 
		for(j=0; j<5; j++ )
		{
			if(i==index -1) 
			{
				if(word[j] == guess[j]) 
				{
				printf(" [ " ) ; 
				green(); 			
				printf("%c", table[i][j] ) ; 
				baseColour(); 			
				printf(" ] ") ; 	
				}
			
				else		
			printf(" [ %c ] ", table[i][j] ) ; 
								
			}
			else		
			printf(" [ %c ] ", table[i][j] ) ; 
			baseColour(); 
		}
		printf("\n\n") ;   
	 } 
	 
	green(); 
	baseColour(); 
		
	
	
	
}





int main(){

  int count = 0, n;
  createWord();
  while(count < 6)
  {
    printf(" Tahmininiz:\n\n ");
	scanf("%s",guess);
	strupr(guess);
	n = strlen(guess);
	if(n!=5)
	{
		printf(" 5 harfli bir kelime giriniz! \n");
		continue;
	}
	
	answer=fillTable();
	printTable();
	if(answer==1)
	break;
	
    count++;
  }
  
  if(answer==1)
  {
  	printf("\nTebrikler Bildiniz. \n"); 
	
  }
   else
  {
  	printf(" Bilemediniz!\n ");
  }
  
  
  
  
  return 0;
}

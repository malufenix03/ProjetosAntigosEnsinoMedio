
/*	Trabalho de FPD - Fundamentos de Processamentos de Dados
	
	Nomes:
	Luana Rodrigues nº 26
	Luís Fernando de Oliveira nº 28
	Sofia Ferreira Conti nº 33
	
	Turma: 71 BB	*/
	
//Bibliotecas----------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <time.h>

//struct----------------------------------------------------------------------------------------------------------------------------

struct stpersonagens
{
	int codigo;
	char nome[100];
	char lado;
	char poder[100];
	char tipo_aparicao;
	char nome_aparicao[100];
	char ano[100];
	char excluido;
} personagem;

//variaveis globais-----------------------------------------------------------------------------------------------------------------

FILE*fp;
int check;
int ajuda;
int volta=0;

//----------------------------------------------------------------------------------------------------------------------------------

text_info vActual = {0, 0, 79, 24, WHITE, WHITE, C80, 25, 80, 1, 1};

void textcolor(int newcolor)
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0xf0) | newcolor);
   vActual.attribute = (csbi.wAttributes & 0xf0) | newcolor;
}

//----------------------------------------------------------------------------------------------------------------------------------

void textbackground(int newcolor)
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0x0f) | (newcolor << 4));
   vActual.attribute = (csbi.wAttributes & 0x0f) | (newcolor << 4);
}

//----------------------------------------------------------------------------------------------------------------------------------

void cursor (int x) { // mostra ou não o cursor do prompt
	switch (x) {
		case 0: {//ocultar cursor
			CONSOLE_CURSOR_INFO cursor = {1, FALSE};
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
			break;
		}
		case 1: {//apresentar cursor
			CONSOLE_CURSOR_INFO cursor = {1, TRUE};
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
			break;
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------------------

void gotoxy(int x, int y)
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//----------------------------------------------------------------------------------------------------------------------------------

void abrir_arquivo_cad(const char modo[])
{
	check=1;
	{
		if((fp = fopen("herois.bin",modo)) == NULL) 
		{
			gotoxy(18,11);printf("Erro na abertura do arquivo");
			exit(1);
		}
		rewind(fp);
		while(fread(&personagem.codigo,sizeof(personagem.codigo),1,fp)==1)
		{
			if(check==personagem.codigo)
				check++;
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------------------

void abrir_arquivo(const char modo[])
{
	if((fp = fopen("herois.bin", modo)) == NULL) 
	{
		gotoxy(18,11);printf("Erro na abertura do arquivo");
	    exit(1);
	}	
}

//----------------------------------------------------------------------------------------------------------------------------------

void borda()
{
	for(int i=11; i<=30; i++)
	{
		textbackground(1);
		gotoxy(100,i);printf(" ");
	}
	for(int j=11; j<=30; j++)
	{
		textbackground(1);
		gotoxy(20,j);printf(" ");
	}
	for(int x=20; x<=100; x++)
	{
		textbackground(1);
		gotoxy(x,11);printf(" ");
	}
	for(int x=20; x<=100; x++)
	{
		textbackground(1);
		gotoxy(x,30);printf(" ");
	}
}

//----------------------------------------------------------------------------------------------------------------------------------

void borda_cadastro()
{
	for(int i=6; i<=29; i++)
	{
		textbackground(1);
		gotoxy(105,i);printf(" ");
	}
	for(int j=6; j<=29; j++)
	{
		textbackground(1);
		gotoxy(20,j);printf(" ");
	}
	for(int x=20; x<=105; x++)
	{
		textbackground(1);
		gotoxy(x,5);printf(" ");
	}
	for(int x=20; x<=105; x++)
	{
		textbackground(1);
		gotoxy(x,29);printf(" ");
	}
}

//----------------------------------------------------------------------------------------------------------------------------------

void logo_nome(int x, int y)
{
	cursor(0);
	setlocale(LC_ALL,"C");
	textcolor(5);
	gotoxy(x,y);printf("%c%c%c%c%c%c%c%c",201,203,205,205,205,205,203,187);
	gotoxy(x,y+1);printf("%c      %c",186,186);
	gotoxy(x,y+2);printf("%c      %c",186,186);
	gotoxy(x,y+3);printf("%c%c%c%c%c%c%c%c",200,202,205,205,205,205,202,188);
	//////////////////////////////////////////////////////////////
	textcolor(13);
	gotoxy(x+1,y+1);printf("%c    %c",186,186);
	gotoxy(x+1,y+2);printf("%c    %c",186,186);
	textcolor(9);
	gotoxy(x+2,y+1);printf("%cP%c%c",4,177,177);
	gotoxy(x+2,y+2);printf("%c%cM%c",177,177,4);
//	gotoxy(x+2,y+1);printf("%cP/%c",4,238);
//	gotoxy(x+2,y+2);printf("%c/M%c",95,4);
	setlocale(LC_ALL,NULL);
}

//----------------------------------------------------------------------------------------------------------------------------------

void esquadrao_suicida(int x, int y)
{
/*	/////////////////////////////linha 1////////////////////////////////////////////
	
	gotoxy(x+2,y-2);printf("________________");
	
	/////////////////////////////linha 2////////////////////////////////////////////
	
	gotoxy(x+1,y-1);printf("/                %c",92);
	
	/////////////////////////////linha 3////////////////////////////////////////////
	
	gotoxy(x,y);printf("/                  %c",92);
	
	/////////////////////////////linha 4////////////////////////////////////////////
	
	gotoxy(x-1,y+1);printf("/                    %c",92);
	
	/////////////////////////////linha 5////////////////////////////////////////////
	
	gotoxy(x-2,y+2);printf("/   /%c   /%c   /%c       %c",92,92,92,92);
	
	/////////////////////////////linha 6////////////////////////////////////////////
	
	gotoxy(x-3,y+3);printf("/    %c %c / /   %c %c /%c    %c",92,92,92,92,92,92);
	
	/////////////////////////////linha 7////////////////////////////////////////////
	
	gotoxy(x-4,y+4);printf("/      %c V /     %c V /     %c",92,92,92);
	
	/////////////////////////////linha 8////////////////////////////////////////////
	
	gotoxy(x-5,y+5);printf("|       / ^ %c    / ^ %c      |",92,92);
	setlocale(LC_ALL,"C");
	gotoxy(x+5,y+5);printf("%c",94);
	gotoxy(x+14,y+5);printf("%c",94);
	setlocale(LC_ALL,NULL);
	
	/////////////////////////////linha 9////////////////////////////////////////////
	
	gotoxy(x-5,y+6);printf("|      / / %c %c  / / %c/      |",92,92,92);
	
	/////////////////////////////linha 10////////////////////////////////////////////
	
	gotoxy(x-5,y+7);printf("|      %c/   %c/  %c/          | ",92,92,92);
	/////////////////////////////linha 11////////////////////////////////////////////
	
	gotoxy(x-5,y+8);printf("|                           |");
	
	/////////////////////////////linha 12////////////////////////////////////////////
	gotoxy(x-5,y+9);printf("| ___       /| |%c       _-  |",92);
	setlocale(LC_ALL,"C");
	gotoxy(x+21,y+9);printf("%c",213);
	setlocale(LC_ALL,NULL);
	
	/////////////////////////////linha 13////////////////////////////////////////////
	
	gotoxy(x-5,y+10);printf("| %c | __    %c| |/     __%c_| |",92,92,92);
	
	/////////////////////////////linha 14////////////////////////////////////////////
	gotoxy(x-5,y+11);printf("|  %c| %c %c  _   __ _- | |    |",92,92,92);
	
	/////////////////////////////linha 15////////////////////////////////////////////
	gotoxy(x-4,y+12);printf("%c   /%c%c| /_| | | %c_%c%c_|    /",92,92,92,92,92,92);
	
	/////////////////////////////linha 16////////////////////////////////////////////
	gotoxy(x-3,y+13);printf("%c     V  %c %c| |%c %c       /",92,92,92,92,92);
	setlocale(LC_ALL,"C");
	gotoxy(x,y+13);printf("%c%c",238,238);
	gotoxy(x+7,y+13);printf("%c",238);
	gotoxy(x+13,y+13);printf("%c",238);
	setlocale(LC_ALL,NULL);
	
	/////////////////////////////linha 17////////////////////////////////////////////
	gotoxy(x-2,y+14);printf("%c        %c|%c|  %c/      /",92,92,92,92);
	
	/////////////////////////////linha 18////////////////////////////////////////////
	gotoxy(x-1,y+15);printf("%c                    /",92);
	
	/////////////////////////////linha 19////////////////////////////////////////////
	
	gotoxy(x,y+16);printf("%c                  /",92);
	
	/////////////////////////////linha 20////////////////////////////////////////////
	gotoxy(x+1,y+17);printf("%c_______________  %c",92,92);
	
	/////////////////////////////linha 21////////////////////////////////////////////
	gotoxy(x+17,y+18);printf("%c  %c",92,92);
	
	/////////////////////////////linha 22////////////////////////////////////////////
	
	gotoxy(x+18,y+19);printf("%c |",92);
	
	/////////////////////////////linha 21////////////////////////////////////////////
	gotoxy(x+19,y+20);printf("%c|",92);
	*/
	/////////////////////////////linha 1////////////////////////////////////////////
	
//	gotoxy(x+2,y-2);printf("________________");
	
	/////////////////////////////linha 2////////////////////////////////////////////
	
//	gotoxy(x+1,y-1);printf("/                %c",92);
	
	/////////////////////////////linha 3////////////////////////////////////////////
	
//	gotoxy(x,y);printf("/                  %c",92);
	
	/////////////////////////////linha 4////////////////////////////////////////////
	
//	gotoxy(x-1,y+1);printf("/                    %c",92);
	
	/////////////////////////////linha 5////////////////////////////////////////////
	
	gotoxy(x-2,y+2);printf("   /%c   /%c  /%c",92,92,92);
	
	/////////////////////////////linha 6////////////////////////////////////////////
	
	gotoxy(x-3,y+3);printf("    %c %c / /  %c %c /%c",92,92,92,92,92);
	
	/////////////////////////////linha 7////////////////////////////////////////////
	
	gotoxy(x-4,y+4);printf("      %c V /    %c V /",92,92);
	
	/////////////////////////////linha 8////////////////////////////////////////////
	
	gotoxy(x-5,y+5);printf("       / ^ %c    / ^ %c",92,92);
	setlocale(LC_ALL,"C");
	gotoxy(x+4,y+5);printf("%c",94);
	gotoxy(x+13,y+5);printf("%c",94);
	setlocale(LC_ALL,NULL);
	
	/////////////////////////////linha 9////////////////////////////////////////////
	
	gotoxy(x-5,y+6);printf("      / / %c %c  / / %c/",92,92,92);
	
	/////////////////////////////linha 10////////////////////////////////////////////
	
	gotoxy(x-5,y+7);printf("      %c/   %c/  %c/",92,92,92);
	/////////////////////////////linha 11////////////////////////////////////////////
	
	gotoxy(x-5,y+8);printf("");
	
	/////////////////////////////linha 12////////////////////////////////////////////
	gotoxy(x-5,y+9);printf(" ___       /| |%c       _-",92);
	setlocale(LC_ALL,"C");
	gotoxy(x+20,y+9);printf("%c",213);
	setlocale(LC_ALL,NULL);
	
	/////////////////////////////linha 13////////////////////////////////////////////
	
	gotoxy(x-4,y+10);printf("%c | __    %c| |/     __%c_|",92,92,92);
	
	/////////////////////////////linha 14////////////////////////////////////////////
	gotoxy(x-3,y+11);printf("%c| %c %c  _   __ _- | |",92,92,92);
	
	/////////////////////////////linha 15////////////////////////////////////////////
	gotoxy(x-1,y+12);printf("/%c%c| /_| | | %c_%c%c_|",92,92,92,92,92);
	
	/////////////////////////////linha 16////////////////////////////////////////////
	gotoxy(x+2,y+13);printf("V  %c %c| |%c %c ",92,92,92,92);
	setlocale(LC_ALL,"C");
	gotoxy(x-1,y+13);printf("%c%c",238,238);
	gotoxy(x+6,y+13);printf("%c",238);
	gotoxy(x+12,y+13);printf("%c",238);
	setlocale(LC_ALL,NULL);
	
	/////////////////////////////linha 17////////////////////////////////////////////
	gotoxy(x+6,y+14);printf("%c| %c| %c/ ",92,92,92);
	
	/////////////////////////////linha 18////////////////////////////////////////////
//	gotoxy(x-1,y+15);printf("                    ");
	
	/////////////////////////////linha 19////////////////////////////////////////////
	
//	gotoxy(x,y+16);printf("%c                  /",92);
	
	/////////////////////////////linha 20////////////////////////////////////////////
//	gotoxy(x+1,y+17);printf("%c_______________  %c",92,92);
	
	/////////////////////////////linha 21////////////////////////////////////////////
//	gotoxy(x+17,y+18);printf("%c  %c",92,92);
	
	/////////////////////////////linha 22////////////////////////////////////////////
	
//	gotoxy(x+18,y+19);printf("%c |",92);
	
	/////////////////////////////linha 21////////////////////////////////////////////
//	gotoxy(x+19,y+20);printf("%c|",92);
}

//----------------------------------------------------------------------------------------------------------------------------------

void fundo_squad(int x, int y,int t)
{
	textbackground(t);
	textcolor(t);
	/////////////////////////////linha -2////////////////////////////////////////////
	
	gotoxy(x+3,y-4);printf("#################");

/////////////////////////////linha -1////////////////////////////////////////////

	gotoxy(x+2,y-3);printf("###################");
	
	/////////////////////////////linha 1////////////////////////////////////////////
	
	gotoxy(x+1,y-2);printf("#####################");
	
	/////////////////////////////linha 2////////////////////////////////////////////
	
	gotoxy(x,y-1);printf("#######################");
	
	/////////////////////////////linha 3////////////////////////////////////////////
	
	gotoxy(x-1,y);printf("#########################");
	
	/////////////////////////////linha 4////////////////////////////////////////////
	
	gotoxy(x-2,y+1);printf("###########################");
	
	/////////////////////////////linha 5////////////////////////////////////////////
	
	gotoxy(x-3,y+2);printf("#############################");
	
	/////////////////////////////linha 6////////////////////////////////////////////
	
	gotoxy(x-3,y+3);printf("#############################");
	
	/////////////////////////////linha 7////////////////////////////////////////////
	
	gotoxy(x-3,y+4);printf("#############################");
	
	/////////////////////////////linha 8////////////////////////////////////////////
	
	gotoxy(x-3,y+5);printf("#############################");
	
	/////////////////////////////linha 9////////////////////////////////////////////
	
	gotoxy(x-3,y+6);printf("#############################");
	
	/////////////////////////////linha 10////////////////////////////////////////////
	
	gotoxy(x-3,y+7);printf("#############################");
	/////////////////////////////linha 11////////////////////////////////////////////
	
	gotoxy(x-3,y+8);printf("#############################");
	
	/////////////////////////////linha 12////////////////////////////////////////////
	gotoxy(x-2,y+9);printf("###########################");
	/////////////////////////////linha 13////////////////////////////////////////////
	
	gotoxy(x-1,y+10);printf("#########################");
	
	/////////////////////////////linha 14////////////////////////////////////////////
	gotoxy(x,y+11);printf("#######################");
	
	/////////////////////////////linha 15////////////////////////////////////////////
	gotoxy(x+1,y+12);printf("#####################");
	
	/////////////////////////////linha 16////////////////////////////////////////////
	gotoxy(x+2,y+13);printf("###################");
	
	/////////////////////////////linha 17////////////////////////////////////////////
	gotoxy(x+3,y+14);printf("#################");
	
	/////////////////////////////linha 18////////////////////////////////////////////
//	gotoxy(x-1,y+15);printf("                             ");
	
	/////////////////////////////linha 19////////////////////////////////////////////
	
//	gotoxy(x,y+16);printf("                           ");
	
	/////////////////////////////linha 20////////////////////////////////////////////
//	gotoxy(x+1,y+17);printf("                         ");
	
	/////////////////////////////linha 21////////////////////////////////////////////
//	gotoxy(x+2,y+18);printf("                       ");
	
	/////////////////////////////linha 22////////////////////////////////////////////
	
//	gotoxy(x+3,y+19);printf("                     ");
	
	/////////////////////////////linha 23////////////////////////////////////////////
//	gotoxy(x+4,y+20);printf("                   ");
//	textbackground(15);
}

//----------------------------------------------------------------------------------------------------------------------------------

void xmen(int x, int y)
{
	////////////////linha 1//////////////////////////
	textcolor(7);
	textbackground(7);
	gotoxy(x,y);printf("##########");
	
	////////////////linha 2//////////////////////////
	
	gotoxy(x-2,y+1);printf("##");
	textbackground(0);
	printf("          ");
	textbackground(7);
	printf("##");
	
	////////////////linha 3//////////////////////////
	
	textbackground(7);
	gotoxy(x-4,y+2);printf("##XX");
	textbackground(0);
	printf("          ");
	textbackground(7);
	printf("XX##");
	
	////////////////linha 4//////////////////////////
	
	textbackground(7);
	gotoxy(x-6,y+3);printf("##");
	textbackground(0);
	printf("  ");
	textbackground(7);
	printf("XXX");
	textbackground(0);
	printf("        ");
	textbackground(7);
	printf("XXX");
	textbackground(0);
	printf("  ");
	textbackground(7);
	printf("##");
	
	////////////////linha 5//////////////////////////
	
	textbackground(7);
	gotoxy(x-7,y+4);printf("#");
	textbackground(0);
	printf("     ");
	textbackground(7);
	printf("XXX");
	textbackground(0);
	printf("      ");
	textbackground(7);
	printf("XXX");
	textbackground(0);
	printf("     ");
	textbackground(7);
	printf("#");
	
	////////////////linha 6//////////////////////////
	
	textbackground(7);
	gotoxy(x-7,y+5);printf("#");
	textbackground(0);
	printf("       ");
	textbackground(7);
	printf("XXX");
	textbackground(0);
	printf("  ");
	textbackground(7);
	printf("XXX");
	textbackground(0);
	printf("       ");
	textbackground(7);
	printf("#");
	
	////////////////linha 7////////////////////////// 
	
	textbackground(7);
	gotoxy(x-7,y+6);printf("#");
	textbackground(0);
	printf("        ");
	textbackground(7);
	printf("XXXXXX");
	textbackground(0);
	printf("        ");
	textbackground(7);
	printf("#");
	
	////////////////linha 8////////////////////////// 
	
	textbackground(7);
	gotoxy(x-7,y+7);printf("#");
	textbackground(0);
	printf("        ");
	textbackground(7);
	printf("XXXXXX");
	textbackground(0);
	printf("        ");
	textbackground(7);
	printf("#");
	
	////////////////linha 9////////////////////////// 
	
	textbackground(7);
	gotoxy(x-7,y+8);printf("#");
	textbackground(0);
	printf("       ");
	textbackground(7);
	printf("XXX");
	textbackground(0);
	printf("  ");
	textbackground(7);
	printf("XXX");
	textbackground(0);
	printf("       ");
	textbackground(7);
	printf("#");
	
	////////////////linha 10 ////////////////////////// 
	
	textbackground(7);
	gotoxy(x-7,y+9);printf("#");
	textbackground(0);
	printf("     ");
	textbackground(7);
	printf("XXX");
	textbackground(0);
	printf("      ");
	textbackground(7);
	printf("XXX");
	textbackground(0);
	printf("     ");
	textbackground(7);
	printf("#");
	
	////////////////linha 11 //////////////////////////
	
	textbackground(7);
	gotoxy(x-6,y+10);printf("##");
	textbackground(0);
	printf("  ");
	textbackground(7);
	printf("XXX");
	textbackground(0);
	printf("        ");
	textbackground(7);
	printf("XXX");
	textbackground(0);
	printf("  ");
	textbackground(7);
	printf("##");
	
	////////////////linha 12 //////////////////////////
	
	textbackground(7);
	gotoxy(x-4,y+11);printf("##XX");
	textbackground(0);
	printf("          ");
	textbackground(7);
	printf("XX##");
	
	////////////////linha 13 //////////////////////////
	
	gotoxy(x-2,y+12);printf("##");
	textbackground(0);
	printf("          ");
	textbackground(7);
	printf("##");
	
	////////////////linha 14 //////////////////////////
	
	textcolor(7);
	textbackground(7);
	gotoxy(x,y+13);printf("##########");
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void marvel_parado(int x, int y)
{
	textbackground(12);//espaço
	textcolor(12); 
	//textbackground(15); //asterisco
	//coluna 1
	gotoxy(x,y);printf("#");
	gotoxy(x,y+1);printf("#");
	gotoxy(x,y+2);printf("#");
	gotoxy(x,y+3);printf("#");
	gotoxy(x,y+4);printf("#");
	gotoxy(x,y+5);printf("#");
	gotoxy(x,y+6);printf("#");
	
	// coluna 2
	gotoxy(x+1,y);printf("#");
	gotoxy(x+1,y+1);printf("#");
	gotoxy(x+1,y+2);printf("#");
	gotoxy(x+1,y+3);printf("#");
	gotoxy(x+1,y+4);printf("#");
	gotoxy(x+1,y+5);printf("#");
	gotoxy(x+1,y+6);printf("#");
	
	// coluna 3
	gotoxy(x+2,y);printf("#");
	gotoxy(x+2,y+1);printf("#");
	gotoxy(x+2,y+2);printf("#");
	gotoxy(x+2,y+3);printf("#");
	gotoxy(x+2,y+4);printf("#");
	gotoxy(x+2,y+5);printf("#");
	gotoxy(x+2,y+6);printf("#");
	
	// coluna 4
	gotoxy(x+3,y);printf("#");
	gotoxy(x+3,y+1);printf("#");
	gotoxy(x+3,y+6);printf("#");
	
	// coluna 5
	gotoxy(x+4,y);printf("#");
	gotoxy(x+4,y+2);printf("#");
	gotoxy(x+4,y+3);printf("#");
	gotoxy(x+4,y+4);printf("#");
	gotoxy(x+4,y+5);printf("#");
	gotoxy(x+4,y+6);printf("#");
	
	// coluna 6
	gotoxy(x+5,y);printf("#");
	gotoxy(x+5,y+2);printf("#");
	gotoxy(x+5,y+3);printf("#");
	gotoxy(x+5,y+4);printf("#");
	gotoxy(x+5,y+5);printf("#");
	gotoxy(x+5,y+6);printf("#");
	
	// coluna 7
	gotoxy(x+6,y);printf("#");
	gotoxy(x+6,y+1);printf("#");
	gotoxy(x+6,y+3);printf("#");
	gotoxy(x+6,y+4);printf("#");
	gotoxy(x+6,y+5);printf("#");
	gotoxy(x+6,y+6);printf("#");
	
	// coluna 8
	gotoxy(x+7,y);printf("#");
	gotoxy(x+7,y+1);printf("#");
	gotoxy(x+7,y+2);printf("#");
	gotoxy(x+7,y+4);printf("#");
	gotoxy(x+7,y+5);printf("#");
	gotoxy(x+7,y+6);printf("#");
	
	//coluna 9
	gotoxy(x+8,y);printf("#");
	gotoxy(x+8,y+1);printf("#");
	gotoxy(x+8,y+3);printf("#");
	gotoxy(x+8,y+4);printf("#");
	gotoxy(x+8,y+5);printf("#");
	gotoxy(x+8,y+6);printf("#");
	
	//coluna 10
	gotoxy(x+9,y);printf("#");
	gotoxy(x+9,y+2);printf("#");
	gotoxy(x+9,y+3);printf("#");
	gotoxy(x+9,y+4);printf("#");
	gotoxy(x+9,y+5);printf("#");
	gotoxy(x+9,y+6);printf("#");
	
	//coluna 11
	gotoxy(x+10,y);printf("#");
	gotoxy(x+10,y+2);printf("#");
	gotoxy(x+10,y+3);printf("#");
	gotoxy(x+10,y+4);printf("#");
	gotoxy(x+10,y+5);printf("#");
	gotoxy(x+10,y+6);printf("#");
	
	// coluna 12
	gotoxy(x+11,y);printf("#");
	gotoxy(x+11,y+1);printf("#");
	gotoxy(x+11,y+6);printf("#");
	
	// coluna 13
	gotoxy(x+12,y);printf("#");
	gotoxy(x+12,y+1);printf("#");
	gotoxy(x+12,y+2);printf("#");
	gotoxy(x+12,y+3);printf("#");
	gotoxy(x+12,y+4);printf("#");
	gotoxy(x+12,y+5);printf("#");
	gotoxy(x+12,y+6);printf("#");
	
	// coluna 14
	gotoxy(x+13,y);printf("#");
	gotoxy(x+13,y+1);printf("#");
	gotoxy(x+13,y+2);printf("#");
	gotoxy(x+13,y+3);printf("#");
	gotoxy(x+13,y+4);printf("#");
	gotoxy(x+13,y+6);printf("#");
	
	// coluna 15
	gotoxy(x+14,y);printf("#");
	gotoxy(x+14,y+1);printf("#");
	gotoxy(x+14,y+2);printf("#");
	gotoxy(x+14,y+3);printf("#");
	gotoxy(x+14,y+5);printf("#");
	gotoxy(x+14,y+6);printf("#");
	// coluna 16
	gotoxy(x+15,y);printf("#");
	gotoxy(x+15,y+1);printf("#");
	gotoxy(x+15,y+2);printf("#");
	gotoxy(x+15,y+4);printf("#");
	gotoxy(x+15,y+5);printf("#");
	gotoxy(x+15,y+6);printf("#");
	
	// coluna 17
	gotoxy(x+16,y);printf("#");
	gotoxy(x+16,y+1);printf("#");
	gotoxy(x+16,y+4);printf("#");
	gotoxy(x+16,y+5);printf("#");
	gotoxy(x+16,y+6);printf("#");
	
	// coluna 18
	gotoxy(x+17,y);printf("#");
	gotoxy(x+17,y+2);printf("#");
	gotoxy(x+17,y+4);printf("#");
	gotoxy(x+17,y+5);printf("#");
	gotoxy(x+17,y+6);printf("#");
	
	// coluna 19
	gotoxy(x+18,y);printf("#");
	gotoxy(x+18,y+2);printf("#");
	gotoxy(x+18,y+4);printf("#");
	gotoxy(x+18,y+5);printf("#");
	gotoxy(x+18,y+6);printf("#");
	
	// coluna 20
	gotoxy(x+19,y);printf("#");
	gotoxy(x+19,y+1);printf("#");
	gotoxy(x+19,y+4);printf("#");
	gotoxy(x+19,y+5);printf("#");
	gotoxy(x+19,y+6);printf("#");
	
	// coluna 21
	gotoxy(x+20,y);printf("#");
	gotoxy(x+20,y+1);printf("#");
	gotoxy(x+20,y+2);printf("#");
	gotoxy(x+20,y+4);printf("#");
	gotoxy(x+20,y+5);printf("#");
	gotoxy(x+20,y+6);printf("#");
	
	// coluna 22
	gotoxy(x+21,y);printf("#");
	gotoxy(x+21,y+1);printf("#");
	gotoxy(x+21,y+2);printf("#");
	gotoxy(x+21,y+3);printf("#");
	gotoxy(x+21,y+5);printf("#");
	gotoxy(x+21,y+6);printf("#");
	
	// coluna 23
	gotoxy(x+22,y);printf("#");
	gotoxy(x+22,y+1);printf("#");
	gotoxy(x+22,y+2);printf("#");
	gotoxy(x+22,y+3);printf("#");
	gotoxy(x+22,y+4);printf("#");
	gotoxy(x+22,y+6);printf("#");
	
	// coluna 24
	gotoxy(x+23,y);printf("#");
	gotoxy(x+23,y+1);printf("#");
	gotoxy(x+23,y+2);printf("#");
	gotoxy(x+23,y+3);printf("#");
	gotoxy(x+23,y+4);printf("#");
	gotoxy(x+23,y+5);printf("#");
	gotoxy(x+23,y+6);printf("#");
	
	// coluna 25
	gotoxy(x+24,y);printf("#");
	gotoxy(x+24,y+6);printf("#");
	
	// coluna 26
	gotoxy(x+25,y);printf("#");
	gotoxy(x+25,y+2);printf("#");
	gotoxy(x+25,y+4);printf("#");
	gotoxy(x+25,y+5);printf("#");
	gotoxy(x+25,y+6);printf("#");
	
	// coluna 27
	gotoxy(x+26,y);printf("#");
	gotoxy(x+26,y+2);printf("#");
	gotoxy(x+26,y+4);printf("#");
	gotoxy(x+26,y+5);printf("#");
	gotoxy(x+26,y+6);printf("#");
	
	// coluna 28
	gotoxy(x+27,y);printf("#");
	//gotoxy(x+27,y+1);printf("#"); //ver se fica bom
	gotoxy(x+27,y+3);printf("#");
	gotoxy(x+27,y+5);printf("#");
	gotoxy(x+27,y+6);printf("#");
	
	// coluna 29
	gotoxy(x+28,y);printf("#");
	gotoxy(x+28,y+1);printf("#");
	gotoxy(x+28,y+2);printf("#");
	gotoxy(x+28,y+3);printf("#");
	gotoxy(x+28,y+4);printf("#");
	gotoxy(x+28,y+6);printf("#");
	
	// coluna 30
	gotoxy(x+29,y);printf("#");
	gotoxy(x+29,y+1);printf("#");
	gotoxy(x+29,y+2);printf("#");
	gotoxy(x+29,y+3);printf("#");
	gotoxy(x+29,y+4);printf("#");
	gotoxy(x+29,y+5);printf("#");
	gotoxy(x+29,y+6);printf("#");
	
	// coluna 31
	gotoxy(x+30,y);printf("#");
	gotoxy(x+30,y+2);printf("#");
	gotoxy(x+30,y+3);printf("#");
	gotoxy(x+30,y+4);printf("#");
	gotoxy(x+30,y+5);printf("#");
	gotoxy(x+30,y+6);printf("#");
	
	// coluna 32
	gotoxy(x+31,y);printf("#");
	gotoxy(x+31,y+1);printf("#");
	gotoxy(x+31,y+3);printf("#");
	gotoxy(x+31,y+4);printf("#");
	gotoxy(x+31,y+5);printf("#");
	gotoxy(x+31,y+6);printf("#");
	
	// coluna 33
	gotoxy(x+32,y);printf("#");
	gotoxy(x+32,y+1);printf("#");
	gotoxy(x+32,y+2);printf("#");
	gotoxy(x+32,y+4);printf("#");
	gotoxy(x+32,y+5);printf("#");
	gotoxy(x+32,y+6);printf("#");
	
	// coluna 34
	gotoxy(x+33,y);printf("#");
	gotoxy(x+33,y+1);printf("#");
	gotoxy(x+33,y+2);printf("#");
	gotoxy(x+33,y+3);printf("#");
	gotoxy(x+33,y+5);printf("#");
	gotoxy(x+33,y+6);printf("#");
	
	// coluna 35
	gotoxy(x+34,y);printf("#");
	gotoxy(x+34,y+1);printf("#");
	gotoxy(x+34,y+2);printf("#");
	gotoxy(x+34,y+3);printf("#");
	gotoxy(x+34,y+4);printf("#");
	gotoxy(x+34,y+6);printf("#");
	
	// coluna 36
	gotoxy(x+35,y);printf("#");
	gotoxy(x+35,y+1);printf("#");
	gotoxy(x+35,y+2);printf("#");
	gotoxy(x+35,y+3);printf("#");
	gotoxy(x+35,y+5);printf("#");
	gotoxy(x+35,y+6);printf("#");
	
	// coluna 37
	gotoxy(x+36,y);printf("#");
	gotoxy(x+36,y+1);printf("#");
	gotoxy(x+36,y+2);printf("#");
	gotoxy(x+36,y+4);printf("#");
	gotoxy(x+36,y+5);printf("#");
	gotoxy(x+36,y+6);printf("#");
	
	// coluna 38
	gotoxy(x+37,y);printf("#");
	gotoxy(x+37,y+1);printf("#");
	gotoxy(x+37,y+3);printf("#");
	gotoxy(x+37,y+4);printf("#");
	gotoxy(x+37,y+5);printf("#");
	gotoxy(x+37,y+6);printf("#");
	
	// coluna 39
	gotoxy(x+38,y);printf("#");
	gotoxy(x+38,y+2);printf("#");
	gotoxy(x+38,y+3);printf("#");
	gotoxy(x+38,y+4);printf("#");
	gotoxy(x+38,y+5);printf("#");
	gotoxy(x+38,y+6);printf("#");
	
	// coluna 40
	gotoxy(x+39,y);printf("#");
	gotoxy(x+39,y+1);printf("#");
	gotoxy(x+39,y+2);printf("#");
	gotoxy(x+39,y+3);printf("#");
	gotoxy(x+39,y+4);printf("#");
	gotoxy(x+39,y+5);printf("#");
	gotoxy(x+39,y+6);printf("#");
	
	// coluna 41
	gotoxy(x+40,y);printf("#");
	gotoxy(x+40,y+6);printf("#");
	
	// coluna 42
	gotoxy(x+41,y);printf("#");
	gotoxy(x+41,y+2);printf("#");
	gotoxy(x+41,y+4);printf("#");
	gotoxy(x+41,y+6);printf("#");
	
	// coluna 43
	gotoxy(x+42,y);printf("#");
	gotoxy(x+42,y+2);printf("#");
	gotoxy(x+42,y+4);printf("#");
	gotoxy(x+42,y+6);printf("#");
	
	// coluna 44
	gotoxy(x+43,y);printf("#");
	gotoxy(x+43,y+2);printf("#");
	gotoxy(x+43,y+3);printf("#");
	gotoxy(x+43,y+4);printf("#");
	gotoxy(x+43,y+6);printf("#");
	
	// coluna 45
	gotoxy(x+44,y);printf("#");
	gotoxy(x+44,y+2);printf("#");
	gotoxy(x+44,y+3);printf("#");
	gotoxy(x+44,y+4);printf("#");
	gotoxy(x+44,y+6);printf("#");
	
	// coluna 46
	gotoxy(x+45,y);printf("#");
	gotoxy(x+45,y+1);printf("#");
	gotoxy(x+45,y+2);printf("#");
	gotoxy(x+45,y+3);printf("#");
	gotoxy(x+45,y+4);printf("#");
	gotoxy(x+45,y+5);printf("#");
	gotoxy(x+45,y+6);printf("#");
	
	// coluna 47
	gotoxy(x+46,y);printf("#");
	gotoxy(x+46,y+6);printf("#");
	
	// coluna 48
	gotoxy(x+47,y);printf("#");
	gotoxy(x+47,y+1);printf("#");
	gotoxy(x+47,y+2);printf("#");
	gotoxy(x+47,y+3);printf("#");
	gotoxy(x+47,y+4);printf("#");
	gotoxy(x+47,y+6);printf("#");
	
	// coluna 49
	gotoxy(x+48,y);printf("#");
	gotoxy(x+48,y+1);printf("#");
	gotoxy(x+48,y+2);printf("#");
	gotoxy(x+48,y+3);printf("#");
	gotoxy(x+48,y+4);printf("#");
	gotoxy(x+48,y+6);printf("#");
	
	// coluna 50
	gotoxy(x+49,y);printf("#");
	gotoxy(x+49,y+1);printf("#");
	gotoxy(x+49,y+2);printf("#");
	gotoxy(x+49,y+3);printf("#");
	gotoxy(x+49,y+4);printf("#");
	gotoxy(x+49,y+6);printf("#");
	
	// coluna 51
	gotoxy(x+50,y);printf("#");
	gotoxy(x+50,y+1);printf("#");
	gotoxy(x+50,y+2);printf("#");
	gotoxy(x+50,y+3);printf("#");
	gotoxy(x+50,y+4);printf("#");
	gotoxy(x+50,y+6);printf("#");
	// coluna 52
	gotoxy(x+51,y);printf("#");
	gotoxy(x+51,y+1);printf("#");
	gotoxy(x+51,y+2);printf("#");
	gotoxy(x+51,y+3);printf("#");
	gotoxy(x+51,y+4);printf("#");
	gotoxy(x+51,y+5);printf("#");
	gotoxy(x+51,y+6);printf("#");
	// coluna 53
	gotoxy(x+52,y);printf("#");
	gotoxy(x+52,y+1);printf("#");
	gotoxy(x+52,y+2);printf("#");
	gotoxy(x+52,y+3);printf("#");
	gotoxy(x+52,y+4);printf("#");
	gotoxy(x+52,y+5);printf("#");
	gotoxy(x+52,y+6);printf("#");
	// coluna 54
	gotoxy(x+52,y);printf("#");
	gotoxy(x+52,y+1);printf("#");
	gotoxy(x+52,y+2);printf("#");
	gotoxy(x+52,y+3);printf("#");
	gotoxy(x+52,y+4);printf("#");
	gotoxy(x+52,y+5);printf("#");
	gotoxy(x+52,y+6);printf("#");
}

//----------------------------------------------------------------------------------------------------------------------------------

void ben10(int x, int y)
{
	///////////////////////////// fundo /////////////////////////////
	textcolor(0);
	textbackground(0);
	///////////linha 1
	gotoxy(x,y);printf("###########");
	
	///////////linha 2
	gotoxy(x-2,y+1);printf("##           ##");
	gotoxy(x+11,y+1);printf("##");
	
	///////////linha 3
	gotoxy(x-4,y+2);printf("##               ##");
	gotoxy(x+13,y+2);printf("##");
	///////////linha 4
	gotoxy(x-6,y+3);printf("##     #########     ##");
	gotoxy(x+15,y+3);printf("##");
	gotoxy(x+1,y+3);printf("#########");
	///////////linha 5
	gotoxy(x-7,y+4);printf("#        #######        #");
	gotoxy(x+16,y+4);printf("##");
	gotoxy(x+2,y+4);printf("#######");
	///////////linha 6
	gotoxy(x-7,y+5);printf("#         #####         #");
	gotoxy(x+16,y+5);printf("##");
	gotoxy(x+3,y+5);printf("#####");
	///////////linha 7
	gotoxy(x-7,y+6);printf("#          ###          #");
	gotoxy(x+16,y+6);printf("##");
	gotoxy(x+4,y+6);printf("###");
	///////////linha 8
	gotoxy(x-7,y+7);printf("#          ###          #");
	gotoxy(x+16,y+7);printf("##");
	gotoxy(x+4,y+7);printf("###");
	///////////linha 9
	gotoxy(x-7,y+8);printf("#         #####         #");
	gotoxy(x+16,y+8);printf("##");
	gotoxy(x+3,y+8);printf("#####");
	///////////linha 10
	gotoxy(x-7,y+9);printf("#        #######        #");
	gotoxy(x+16,y+9);printf("##");
	gotoxy(x+2,y+9);printf("#######");
	///////////linha 11
	gotoxy(x-6,y+10);printf("##     #########     ##");
	gotoxy(x+15,y+10);printf("##");
	gotoxy(x+1,y+10);printf("#########");
	
	///////////linha 12
	gotoxy(x-4,y+11);printf("##               ##");
	gotoxy(x+13,y+11);printf("##");
	
	///////////linha 13
	gotoxy(x-2,y+12);printf("##           ##");
	gotoxy(x+11,y+12);printf("##");
	
	///////////linha 14
	gotoxy(x,y+13);printf("###########");
	
	
	
	
	/////////////////desenho//////////////////////////////////////////
	
	
	textcolor(8);
	textbackground(8);
	///////////linha 1
	gotoxy(x,y);printf("###########");
	
	///////////linha 2
	gotoxy(x-2,y+1);printf("##");
	gotoxy(x+11,y+1);printf("##");
	
	///////////linha 3
	gotoxy(x-4,y+2);printf("##");
	gotoxy(x+13,y+2);printf("##");
	///////////linha 4
	gotoxy(x-6,y+3);printf("##");
	gotoxy(x+15,y+3);printf("##");
	textcolor(10);
	textbackground(10);
	gotoxy(x+1,y+3);printf("#########");
	///////////linha 5
	textcolor(8);
	textbackground(8);
	gotoxy(x-7,y+4);printf("##");
	gotoxy(x+16,y+4);printf("##");
	textcolor(10);
	textbackground(10);
	gotoxy(x+2,y+4);printf("#######");
	///////////linha 6
	textcolor(8);
	textbackground(8);
	gotoxy(x-7,y+5);printf("##");
	gotoxy(x+16,y+5);printf("##");
	textcolor(10);
	textbackground(10);
	gotoxy(x+3,y+5);printf("#####");
	///////////linha 7
	textcolor(8);
	textbackground(8);
	gotoxy(x-7,y+6);printf("##");
	gotoxy(x+16,y+6);printf("##");
	textcolor(10);
	textbackground(10);
	gotoxy(x+4,y+6);printf("###");
	///////////linha 8
	textcolor(8);
	textbackground(8);
	gotoxy(x-7,y+7);printf("##");
	gotoxy(x+16,y+7);printf("##");
	textcolor(10);
	textbackground(10);
	gotoxy(x+4,y+7);printf("###");
	///////////linha 9
	textcolor(8);
	textbackground(8);
	gotoxy(x-7,y+8);printf("##");
	gotoxy(x+16,y+8);printf("##");
	textcolor(10);
	textbackground(10);
	gotoxy(x+3,y+8);printf("#####");
	///////////linha 10
	textcolor(8);
	textbackground(8);
	gotoxy(x-7,y+9);printf("##");
	gotoxy(x+16,y+9);printf("##");
	textcolor(10);
	textbackground(10);
	gotoxy(x+2,y+9);printf("#######");
	///////////linha 11
	textcolor(8);
	textbackground(8);
	gotoxy(x-6,y+10);printf("##");
	gotoxy(x+15,y+10);printf("##");
	textcolor(10);
	textbackground(10);
	gotoxy(x+1,y+10);printf("#########");
	
	///////////linha 12
	textcolor(8);
	textbackground(8);
	gotoxy(x-4,y+11);printf("##");
	gotoxy(x+13,y+11);printf("##");
	
	///////////linha 13
	gotoxy(x-2,y+12);printf("##");
	gotoxy(x+11,y+12);printf("##");
	
	///////////linha 14
	gotoxy(x,y+13);printf("###########");
}

//----------------------------------------------------------------------------------------------------------------------------------

void validacao_vazia_string(char validar[],int x, int y)
{
	do
	{
		if (strlen(validar)==0||validar[0]==' ')
		 {
			  gotoxy(40,25);printf ("Resposta inv%clida! Redigite!",160);
			  gotoxy(x,y); printf ("                                  ");
			  gotoxy(x,y);gets(validar);
			  if(validar[0]=='0')
			  {
			  	gotoxy(40,25);printf("                             ");
			  	break;
			  }
			  gotoxy(40,25);printf("                             ");
		}
	}while(strlen(validar)==0||validar[0]==' ');
	return;
}

//----------------------------------------------------------------------------------------------------------------------------------

void validacao_vazia_alterar(char validar[],int x, int y)
{
	do
	{
		if (validar[0]==' ')
		 {
			  gotoxy(40,25);printf ("Resposta inv%clida! Redigite!",160);
			  gotoxy(x,y); printf ("                                  ");
			  gotoxy(x,y);gets(validar);
			  if(validar[0]=='0')
			  {
			  	gotoxy(40,25);printf("                             ");
			  	break;
			  }
			  gotoxy(40,25);printf("                             ");
		}
	}while(validar[0]==' ');
	return;
}

//----------------------------------------------------------------------------------------------------------------------------------

void salvar_dados()
{
	char conf;
	gotoxy(40,25);printf("Confirma os dados para grava%c%co ? (S/N): ",135,198);
	gotoxy(81,25); conf = getche();
	do
	{
		if(conf != 's' && conf != 'S'&& conf != 'n' && conf != 'N')
		{
			Sleep(500);
			gotoxy(40,26);printf("D%cgito inv%clido, redigite!",161,160);
			gotoxy(81,25);printf("                 ");
			gotoxy(81,25); conf = getche();
			gotoxy(40,26);printf("                                         ");
		}
	}while( conf != 's' && conf != 'S'&& conf != 'n' && conf != 'N' );
	    
	if( conf == 's' || conf == 'S' )
	{
		if(fwrite(&personagem, sizeof(personagem), 1, fp) != 1) 
		{
		    gotoxy(40,26);printf("Erro na escrita do arquivo");
		}
		else
		 {
				fflush( fp );
				gotoxy(40,26);printf ("Dados salvos com sucesso!",22);
				gotoxy(40,27);printf ("(tecle enter para continuar)");
				check++;
		 }
		getch(); 
	}
}

//----------------------------------------------------------------------------------------------------------------------------------

char valida_ano(char validar[])
{
	int aux=0;
	do
	{
		aux=0;
		for(int i=0; i<4; i++)
		{
			if(validar[i]!='0'&&validar[i]!='1'&&validar[i]!='2'&&validar[i]!='3'&&validar[i]!='4'&&validar[i]!='5'&&validar[i]!='6'&&validar[i]!='7'&&validar[i]!='8'&&validar[i]!='9')
			{
				aux=1;
			}
		}
		if(validar[0]!='0'&&validar[0]!='1'&&validar[0]!='2')
			aux=1;
		if (validar[0]=='2')
		{
			if(validar[1]!='0')
				aux=1;
			if(validar[2]!='0'&&validar[2]!='1')
				aux=1;
		}
		if (strlen(validar)!=4)
			aux=1;
		if (aux==1)
		{
			gotoxy(40,25);printf ("Resposta inv%clida! Redigite! ",160);
			gotoxy(70,19); printf ("                               ");
			gotoxy(70,19);gets(validar);
		    gotoxy(40,25);printf("                             ");
		}
	} while (aux==1);
}

//----------------------------------------------------------------------------------------------------------------------------------

char valida_ano_alterar(char validar[])
{
	int aux=0;
	do
	{
		aux=0;
		if(validar[0]=='\0')
			break;
		for(int i=0; i<4; i++)
		{
			if(validar[i]!='0'&&validar[i]!='1'&&validar[i]!='2'&&validar[i]!='3'&&validar[i]!='4'&&validar[i]!='5'&&validar[i]!='6'&&validar[i]!='7'&&validar[i]!='8'&&validar[i]!='9')
			{
				aux=1;
			}
		}
		if(validar[0]!='0'&&validar[0]!='1'&&validar[0]!='2')
			aux=1;
		if (validar[0]=='2')
		{
			if(validar[1]!='0')
				aux=1;
			if(validar[2]!='0'&&validar[2]!='1')
				aux=1;
		}
		if (strlen(validar)!=4||strlen(validar)==0)
			aux=1;
		if (aux==1)
		{
			gotoxy(40,25);printf ("Resposta inv%clida! Redigite! ",160);
			gotoxy(23,22); printf ("                               ");
			gotoxy(23,22);gets(validar);
		    gotoxy(40,25);printf("                             ");
		}
	} while (aux==1);
}

//----------------------------------------------------------------------------------------------------------------------------------

void pede_dados(const char *parte)
{
	system("cls");
	logo_nome(57,1);
	textbackground(11);
	gotoxy(2,2);printf("                                                    ");
	gotoxy(68,2);printf("                                                    ");
	marvel_parado(35,32);
	textbackground(12);
	gotoxy(2,35);printf("                                ");
	gotoxy(89,35);printf("                               ");
	borda_cadastro();
	textcolor(1);
	textbackground(15);
	cursor(1);
	gotoxy(50,8);printf("CADASTRO DE PERSONAGENS");
	gotoxy(25,14);printf("Nome (caso deseje sair, digite 0): ");
	gotoxy(25,15);printf("Vil%co ou her%ci (v ou h): ",198,162);
	gotoxy(25,16);printf("Qual %c o seu poder? ",130);
	gotoxy(25,17);printf("Sua primeira apari%c%co foi em filme (f), anima%c%co (a) ou nos quadrinhos (q)? ",135,198,135,198);
	gotoxy(25,19);printf("Qual o seu ano de lan%camento (4 caracteres)?",135);
	gotoxy(25,20);printf("\n");
}

//----------------------------------------------------------------------------------------------------------------------------------

void lanterna_verde(int, int);

//----------------------------------------------------------------------------------------------------------------------------------

void mostra_dados_aux(stpersonagens personagem_aux)
{
	textbackground(15);
	logo_nome(57,1);
	textbackground(11);
	gotoxy(2,2);printf("                                                    ");
	gotoxy(68,2);printf("                                                    ");
	gotoxy(2,39);printf("                                                                                                                      ");
	for(int i=2; i<=39; i++)
	{
		textbackground(11);
		gotoxy(2,i);printf(" ");
	}
	for(int i=2; i<=39; i++)
	{
		textbackground(11);
		gotoxy(119,i);printf(" ");
	}
	textbackground(15);
	cursor(1);
	textcolor(8);
	gotoxy(49,6);printf("ALTERA%c%cO DE PERSONAGENS",80,199);
	setlocale(LC_ALL,"C");
	textcolor(8);
	for(int i=48; i<=74; i++)
	{
		textcolor(8);
		gotoxy(i,5);printf("%c",196);
		gotoxy(i,7);printf("%c",196);
	}
	gotoxy(43,9);printf("%c",179);
	gotoxy(80,9);printf("%c",179);
	for(int i=43; i<=80; i++)
	{
		textcolor(8);
		gotoxy(i,10);printf("%c",196);
		gotoxy(i,8);printf("%c",196);
	}
	gotoxy(43,10); printf("%c",192);
	gotoxy(43,8); printf("%c",218);
	gotoxy(80,8); printf("%c",191);
	gotoxy(80,10); printf("%c",217);
	setlocale(LC_ALL,NULL);
	for(int i=13; i<=29; i++)
	{
		textbackground(1);
		gotoxy(70,i);printf(" ");
	}
	for(int j=13; j<=29; j++)
	{
		textbackground(1);
		gotoxy(14,j);printf(" ");
	}
	for(int x=14; x<=70; x++)
	{
		textbackground(1);
		gotoxy(x,13);printf(" ");
	}
	for(int x=14; x<=70; x++)
	{
		textbackground(1);
		gotoxy(x,29);printf(" ");
	}
	lanterna_verde(80,13);
	textbackground(15);
	gotoxy(18,15);printf("C%cdigo: ",162);
	gotoxy(26,15);printf("%d",personagem_aux.codigo);
	gotoxy(18,17);printf("Nome: ");
	gotoxy(24,17);puts(personagem_aux.nome);
	gotoxy(18,18);printf("Lado <v ou h>: ");
	gotoxy(33,18);printf("%c",personagem_aux.lado);
	gotoxy(18,19);printf("Poder: ");
	gotoxy(25,19);puts(personagem_aux.poder);
	gotoxy(18,20);printf("Tipo da apari%c%co <a, f ou q>: ",135,198);
	gotoxy(48,20);printf("%c",personagem_aux.tipo_aparicao);
	gotoxy(18,21);printf("Nome da apari%c%co: ",135,198);
	gotoxy(36,21);puts(personagem_aux.nome_aparicao);
	gotoxy(18,22);printf("Ano: ");
	gotoxy(23,22);puts(personagem_aux.ano);
}

//----------------------------------------------------------------------------------------------------------------------------------

void lanterna_verde(int,int);

//----------------------------------------------------------------------------------------------------------------------------------

void mostra_dados()
{
	gotoxy(18,15);printf("C%cdigo: ",162);
	gotoxy(26,15);printf("%d",personagem.codigo);
	gotoxy(18,17);printf("Nome: ");
	gotoxy(24,17);puts(personagem.nome);
	gotoxy(18,18);printf("Lado <v ou h>: ");
	gotoxy(33,18);printf("%c",personagem.lado);
	gotoxy(18,19);printf("Poder: ");
	gotoxy(25,19);puts(personagem.poder);
	gotoxy(18,20);printf("Tipo da apari%c%co <a, f ou q>: ",135,198);
	gotoxy(48,20);printf("%c",personagem.tipo_aparicao);
	gotoxy(18,21);printf("Nome da apari%c%co: ",135,198);
	gotoxy(36,21);puts(personagem.nome_aparicao);
	gotoxy(18,22);printf("Ano: ");
	gotoxy(23,22);puts(personagem.ano);
}

//----------------------------------------------------------------------------------------------------------------------------------

void mostra_dados_ex()
{
	gotoxy(14,15);printf("C%cdigo: ",162);
	gotoxy(22,15);printf("%d",personagem.codigo);
	gotoxy(14,17);printf("Nome: ");
	gotoxy(20,17);puts(personagem.nome);
	gotoxy(14,18);printf("Lado <v ou h>: ");
	gotoxy(29,18);printf("%c",personagem.lado);
	gotoxy(14,19);printf("Poder: ");
	gotoxy(21,19);puts(personagem.poder);
	gotoxy(14,20);printf("Tipo da apari%c%co <a, f ou q>: ",135,198);
	gotoxy(44,20);printf("%c",personagem.tipo_aparicao);
	gotoxy(14,21);printf("Nome da apari%c%co: ",135,198);
	gotoxy(32,21);puts(personagem.nome_aparicao);
	gotoxy(14,22);printf("Ano: ");
	gotoxy(19,22);puts(personagem.ano);
}

//----------------------------------------------------------------------------------------------------------------------------------

void digita_dados()
{
	cursor(1);
	do{
		pede_dados("CADASTRO");
		personagem.codigo=check;
		gotoxy(25,12);printf("C%cdigo: %d",162,personagem.codigo);
		fflush(stdin);
		gotoxy(60,14);gets(personagem.nome);
		if(personagem.nome[0]=='0')
		{
			break;			
		}
		validacao_vazia_string(personagem.nome,60,14);
		while (strlen(personagem.nome)>29)
		{
			if(strlen(personagem.nome)>29)
			{
				for(int i=60; i<=strlen(personagem.nome); i++)
					printf(" ");
				pede_dados("CADASTRO");
				gotoxy(40,25);printf ("Muitos caracteres (m%cximo 29). Redigite!",160);
				gotoxy(25,12);printf("C%cdigo: %d",162,personagem.codigo);
				gotoxy(60,14);gets(personagem.nome);
				gotoxy(40,25); printf ("                                          ");
				validacao_vazia_string(personagem.nome,60,14);
			}
		}
		if(personagem.nome[0]=='0')
		{
			break;			
		}
		gotoxy(50,15);personagem.lado=getche();
		do
		{
			 if (personagem.lado!='h'&&personagem.lado!='H'&&personagem.lado!='V'&&personagem.lado!='v')
			 {
				  gotoxy(40,25);printf ("Resposta inv%clida! Redigite!",160);
				  gotoxy(50,15); printf ("                                  ");
				  gotoxy(50,15);personagem.lado=getche();
				  gotoxy(40,25);printf("                             ");
			 }
		} while (personagem.lado!='h'&&personagem.lado!='H'&&personagem.lado!='V'&&personagem.lado!='v');
		fflush(stdin);
		gotoxy(45,16); gets(personagem.poder);
		validacao_vazia_string(personagem.poder,45,16);
		while (strlen(personagem.poder)>29)
		{
			if(strlen(personagem.poder)>29)
			{
				for(int i=60; i<=strlen(personagem.poder); i++)
					printf(" ");
				pede_dados("CADASTRO");
				gotoxy(40,25);printf ("Muitos caracteres (m%cximo 29). Redigite!",160);
				gotoxy(25,12);printf("C%cdigo: %d",162,personagem.codigo);
				gotoxy(25,14);printf("Nome (caso deseje sair, digite 0): %s", personagem.nome);
				gotoxy(25,15);printf("Vil%co ou her%ci (v ou h): %c",198,162, personagem.lado);
				gotoxy(45,16);gets(personagem.poder);
				gotoxy(40,25); printf ("                                          ");
				validacao_vazia_string(personagem.poder,45,16);
			}
		}
		fflush(stdin);
		gotoxy(101,17);personagem.tipo_aparicao=getche();
		do
		{
			 if (personagem.tipo_aparicao!='a'&&personagem.tipo_aparicao!='A'&&personagem.tipo_aparicao!='f'&&personagem.tipo_aparicao!='F'&&personagem.tipo_aparicao!='q'&&personagem.tipo_aparicao!='Q')
			 {
				  gotoxy(40,25);printf ("Resposta inv%clida! Redigite!",160);
				  gotoxy(101,17); printf ("  ");
				  gotoxy(101,17);personagem.tipo_aparicao=getche();
				  gotoxy(40,25);printf("                             ");
			 }
		} while (personagem.tipo_aparicao!='a'&&personagem.tipo_aparicao!='A'&&personagem.tipo_aparicao!='f'&&personagem.tipo_aparicao!='F'&&personagem.tipo_aparicao!='q'&&personagem.tipo_aparicao!='Q');
		fflush(stdin);
		if (personagem.tipo_aparicao=='a'||personagem.tipo_aparicao=='A')
		{
			gotoxy(25,18);printf("Qual o nome da anima%c%co? ",135,198); 
			gotoxy(50,18);gets(personagem.nome_aparicao);
			validacao_vazia_string(personagem.nome_aparicao,50,18);
			while (strlen(personagem.nome_aparicao)>29)
			{
				if(strlen(personagem.nome_aparicao)>29)
				{
					for(int i=60; i<=strlen(personagem.nome_aparicao); i++)
						printf(" ");
					pede_dados("CADASTRO");
					gotoxy(40,25);printf ("Muitos caracteres (m%cximo 29). Redigite!",160);
					gotoxy(25,12);printf("C%cdigo: %d",162,personagem.codigo);
					gotoxy(25,14);printf("Nome (caso deseje sair, digite 0): %s", personagem.nome);
					gotoxy(25,15);printf("Vil%co ou her%ci (v ou h): %c",198,162, personagem.lado);
					gotoxy(25,16);printf("Qual %c o seu poder? %s",130, personagem.poder);
					gotoxy(25,17);printf("Sua primeira apari%c%co foi em filme (f), anima%c%co (a) ou nos quadrinhos (q)? %c",135,198,135,198, personagem.tipo_aparicao);
					gotoxy(25,18);printf("Qual o nome da anima%c%co? ",135,198); 
					gotoxy(50,18);gets(personagem.nome_aparicao);
					gotoxy(40,25); printf ("                                          ");
					validacao_vazia_string(personagem.nome_aparicao,50,18);
				}
			}
		
		}
		else if (personagem.tipo_aparicao=='f'||personagem.tipo_aparicao=='F')
		{
		  	gotoxy(25,18);printf("Qual o nome do filme? ");
		  	gotoxy(47,18);gets(personagem.nome_aparicao);
		  	validacao_vazia_string(personagem.nome_aparicao,47,18);
		  	while (strlen(personagem.nome_aparicao)>29)
			{
				if(strlen(personagem.nome_aparicao)>29)
				{
					for(int i=60; i<=strlen(personagem.nome_aparicao); i++)
						printf(" ");
					pede_dados("CADASTRO");
					gotoxy(40,25);printf ("Muitos caracateres (m%cximo 30). Redigite!",160);
					gotoxy(25,12);printf("C%cdigo: %d",162,personagem.codigo);
					gotoxy(25,14);printf("Nome (caso deseje sair, digite 0): %s", personagem.nome);
					gotoxy(25,15);printf("Vil%co ou her%ci (v ou h): %c",198,162, personagem.lado);
					gotoxy(25,16);printf("Qual %c o seu poder? %s",130, personagem.poder);
					gotoxy(25,17);printf("Sua primeira apari%c%co foi em filme (f), anima%c%co (a) ou nos quadrinhos (q)? ",135,198,135,198);
					gotoxy(25,18);printf("Qual o nome do filme? ");
					gotoxy(47,18);gets(personagem.nome_aparicao);
					gotoxy(40,25); printf ("                                          ");
					validacao_vazia_string(personagem.nome_aparicao,47,18);
				}
			}
		}
		else if (personagem.tipo_aparicao=='q'||personagem.tipo_aparicao=='Q')
		{
			gotoxy(25,18);printf("Qual o nome do quadrinho? ");
			gotoxy(51,18);gets(personagem.nome_aparicao);
			validacao_vazia_string(personagem.nome_aparicao,51,18);
			while (strlen(personagem.nome_aparicao)>29)
			{
				if(strlen(personagem.nome_aparicao)>29)
				{
					for(int i=60; i<=strlen(personagem.nome_aparicao); i++)
						printf(" ");
					pede_dados("CADASTRO");
					gotoxy(40,25);printf ("Muitos caracateres (m%cximo 30). Redigite!",160);
					gotoxy(25,12);printf("C%cdigo: %d",162,personagem.codigo);
					gotoxy(25,14);printf("Nome (caso deseje sair, digite 0): %s", personagem.nome);
					gotoxy(25,15);printf("Vil%co ou her%ci (v ou h): %c",198,162, personagem.lado);
					gotoxy(25,16);printf("Qual %c o seu poder? %s",130, personagem.poder);
					gotoxy(25,17);printf("Sua primeira apari%c%co foi em filme (f), anima%c%co (a) ou nos quadrinhos (q)? ",135,198,135,198);
					gotoxy(25,18);printf("Qual o nome do quadrinho? ");
					gotoxy(51,18);gets(personagem.nome_aparicao);
					gotoxy(40,25); printf ("                                          ");
					validacao_vazia_string(personagem.nome_aparicao,51,18);
				}
			}
		}
		gotoxy(70,19);gets(personagem.ano);
		valida_ano(personagem.ano);
		fflush(stdin);
		
		personagem.excluido = 'n'; /* atribuição de 'n' para o campo excluído para indicar
		       //que o registro acabou de ser inserido */	
		salvar_dados();
	}while(true);
	cursor(0);
}


//----------------------------------------------------------------------------------------------------------------------------------
void borda_pesquisa()
{
	setlocale(LC_ALL,"C");
	textcolor(9);
	for(int i=12; i<=30; i++)
	{
		textbackground(1);
		gotoxy(105,i);printf(" ");
	}
	for(int j=12; j<=30; j++)
	{
		textbackground(1);
		gotoxy(20,j);printf(" ");
	}
	for(int x=20; x<=105; x++)
	{
		textbackground(1);
		gotoxy(x,11);printf(" ");
	}
	for(int x=20; x<=105; x++)
	{
		textbackground(1);
		gotoxy(x,30);printf(" ");
	}
	//////////////////////////////////////q
	
	for(int j=12; j<=29; j++)
	{
		textbackground(15);
		if(j!=15&&j!=18&&j!=21&&j!=24&&j!=27)
		{
			gotoxy(30,j);printf("%c",179);
			gotoxy(45,j);printf("%c",179);
			gotoxy(55,j);printf("%c",179);
			gotoxy(65,j);printf("%c",179);
			gotoxy(81,j);printf("%c",179);
			gotoxy(94,j);printf("%c",179);
		}
	}
	for(int x=21; x<=104; x++)
	{
		textbackground(15);
	//	gotoxy(x,6);printf("%c",196);
	//	gotoxy(x,9);printf("%c",196);
	//	gotoxy(x,12);printf("%c",196);
		gotoxy(x,15);printf("%c",196);
		gotoxy(x,18);printf("%c",196);
		gotoxy(x,21);printf("%c",196);
		gotoxy(x,24);printf("%c",196);
		gotoxy(x,27);printf("%c",196);
	//	gotoxy(x,30);printf("%c",196);
	//	gotoxy(x,33);printf("%c",196);
		if(x==30||x==45||x==55||x==65||x==81||x==94)
		{
	//		gotoxy(x,6);printf("%c",197);
	//		gotoxy(x,9);printf("%c",197);
	//		gotoxy(x,12);printf("%c",197);
			gotoxy(x,15);printf("%c",197);
			gotoxy(x,18);printf("%c",197);
			gotoxy(x,21);printf("%c",197);
			gotoxy(x,24);printf("%c",197);
			gotoxy(x,27);printf("%c",197);
	//		gotoxy(x,30);printf("%c",197);
	//		gotoxy(x,33);printf("%c",197);
		}
		setlocale(LC_ALL,NULL);
	}
}

//----------------------------------------------------------------------------------------------------------------------------------

void telas_pesquisa(int x, int y)
{
	borda_pesquisa();
	textbackground(15);
	gotoxy(22,13);printf("C%cdigo",162);
	gotoxy(32,13);printf("Nome");
	gotoxy(47,13);printf("Lado");
	gotoxy(57,13);printf("Poder");
	gotoxy(67,13);printf("Plataforma em");
	gotoxy(67,14);printf("que aparece");
	gotoxy(83,13);printf("Primeira");
	gotoxy(83,14);printf("apari%c%co",135,198);
	gotoxy(96,13);printf("Ano da");
	gotoxy(96,14);printf("apari%c%co",135,198);
	gotoxy(22,31);printf("< e > para mudar de p%cgina",160);
	//gotoxy(2,3);printf("pagina");
	gotoxy(22,32);printf("/\\ e \\/ para mover o cursor");
	//gotoxy(2,6);printf("o cursor");
	gotoxy(60,31);printf("Enter para ver com mais detalhes");
	//gotoxy(2,9);printf("mais detalhes");
	gotoxy(60,32);printf("Aperte esc para escolher outro filtro");
}

//-----------------------------------------------------------------------------------------------------------------------------------

void mostrar_detalhe(int lin,int pag,int fh,int fv, int fa, int ff, int fq,int nome, char pesquisa[])
{
	char g;
	char aux_nome[40];
	cursor(0);
	do
	{
		int aux=1;
		int y=17;
		rewind(fp); //rebobina o disco
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(2,i);printf(" ");
		}
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(119,i);printf(" ");
		}
		textbackground(15);
		logo_nome(57,1);
		textbackground(11);
		gotoxy(2,2);printf("                                                    ");
		gotoxy(68,2);printf("                                                    ");
		gotoxy(2,39);printf("                                                                                                                      ");
		textbackground(15);
		for(int i=12; i<=28; i++)
		{
			textbackground(0);
			gotoxy(23,i);printf(" ");
		}
		for(int j=12; j<=28; j++)
		{
			textbackground(0);
			gotoxy(67,j);printf(" ");
		}
		for(int x=23; x<=67; x++)
		{
			textbackground(0);
			gotoxy(x,12);printf(" ");
		}
		for(int x=23; x<=67; x++)
		{
			textbackground(0);
			gotoxy(x,28);printf(" ");
		}
		textbackground(15);
		setlocale(LC_ALL,"C");
		for(int i=53; i<=67; i++)
		{
			textcolor(0);
			gotoxy(i,9);printf("%c",196);
		}
		for(int i=53; i<=67; i++)
		{
			textcolor(0);
			gotoxy(i,7);printf("%c",196);
		}
		setlocale(LC_ALL,NULL);
		textcolor(8);
		textbackground(15);
		gotoxy(57,8);printf("DETALHE");
		textbackground(15);
		while(fread(&personagem,sizeof(personagem),1,fp)==1)  //ler o arquivo inteiro
		{	
			strcpy(aux_nome,personagem.nome);
			strupr(aux_nome);
			int filtro=1;
			char inicial[2];
			int tam;
			if(nome==1)
			{
				if(strstr(aux_nome,pesquisa)==NULL)
				{
					filtro=0;
				}
			}
			if(y>31)
			{
				y=17;
			//	system("cls");
				aux++;
			}
			/////////////////////////filtro//////////////////////////////////////////////////
			
			if(fh==0)
			{
				if(personagem.lado=='h'||personagem.lado=='H')
				{
					filtro=0;
				}
			}
			if(fv==0)
			{
				if(personagem.lado=='v'||personagem.lado=='V')
				{
					filtro=0;
				}
			}
			if(fa==0)
			{
				if(personagem.tipo_aparicao=='a'||personagem.tipo_aparicao=='A')
				{
					filtro=0;
				}
			}
			if(fq==0)
			{
				if(personagem.tipo_aparicao=='q'||personagem.tipo_aparicao=='Q')
				{
					filtro=0;
				}
			}
			if(ff==0)
			{
				if(personagem.tipo_aparicao=='f'||personagem.tipo_aparicao=='F')
				{
					filtro=0;
				}
			}
			
			
			//////////////////////mostrando dados///////////////////////////////////////////////
			
			
			    ////////////////////////////logo/////////////////////////////
			if(y==lin&&aux==pag&&filtro==1&&personagem.excluido=='n') //se for a linha e a página a ser mostrada
			{
				
				if(personagem.lado=='v'||personagem.lado=='V')
				{
					fundo_squad(77,16,0);
					textcolor(12);
					esquadrao_suicida(80,14);
					textbackground(15);
					textcolor(4); //testar 12
				}
				if(personagem.lado=='h'||personagem.lado=='H')
				{
					xmen(84,14);
					textbackground(15);
					textcolor(8);  //9 -azul
				}
					
					
				////////////////   codigo   ///////////////////////////////
				
				gotoxy(25,15);printf("C%cdigo: %d",162,personagem.codigo);
				
				////////////////   nome   ///////////////////////////////
				
				inicial[0]=personagem.nome[0];
				strupr(inicial);
				strlwr(personagem.nome);
				tam=strlen(personagem.nome);
				gotoxy(25,17);printf("Nome: ");
				putchar(inicial[0]);
				for (int i=1; i<tam;i++)
				{
					putchar(personagem.nome[i]);
				}
				
				////////////////   lado   //////////////////////////////
				
				if(personagem.lado=='V'||personagem.lado=='v')
				{
					gotoxy(25,18);puts("Vilao");
				}
				else
				{
					gotoxy(25,18);puts("Heroi");
				}
					
				////////////////   poder   //////////////////////////////
				
					
				inicial[0]=personagem.poder[0];
				strupr(inicial);
				strlwr(personagem.poder);
				tam=strlen(personagem.poder);
				gotoxy(25,19);printf("Poder: ");
				putchar(inicial[0]);
				for (int i=1; i<tam;i++)
				{
					putchar(personagem.poder[i]);
				}
				
					
				////////////////   aparicao   //////////////////////////////
					
				inicial[0]=personagem.nome_aparicao[0];
				strupr(inicial);
				strlwr(personagem.nome_aparicao);
				tam=strlen(personagem.nome_aparicao);
				
				////////////////   tipo   //////////////////////////////
			
				if(personagem.tipo_aparicao=='A'||personagem.tipo_aparicao=='a')
				{
					gotoxy(25,20);puts("Animacao: ");
					gotoxy(35,20);putchar(inicial[0]);
					for (int i=1; i<tam;i++)
					{
						putchar(personagem.nome_aparicao[i]);
					}
				}
				else if(personagem.tipo_aparicao=='f'||personagem.tipo_aparicao=='F')
				{
					gotoxy(25,20);puts("Filme: ");
					gotoxy(32,20);putchar(inicial[0]);
					for (int i=1; i<tam;i++)
					{
						putchar(personagem.nome_aparicao[i]);
					}
				}
				else
				{
					gotoxy(25,20);puts("Quadrinhos: ");
					gotoxy(37,20);putchar(inicial[0]);
					for (int i=1; i<tam;i++)
					{
						putchar(personagem.nome_aparicao[i]);
					}
				}
				
				////////////////   ano   //////////////////////////////
				
				gotoxy(25,21);printf("Ano: ");
				puts(personagem.ano);
				
				///////////////////////////////////////////////////////
				
				gotoxy(25,25);printf("Aperte qualquer tecla para voltar");
	//			lin=-4;
	//			break;
			}
			if(personagem.excluido=='n'&&filtro==1)
				y+=3;
		}
	//	if(lin==-4)
			volta=1;	//avisando que voltou do mostrar detalhe
			break;
	}while(true);
	g=getch();	//qualquer tecla volta para tabela
}

//-----------------------------------------------------------------------------------------------------------------------------------

void selecionar(int *selec, char r,int *at, int pag,int *aux, int lin,int y,int fh,int fv, int fa, int ff, int fq,int nome,char pesquiisa[])
{
	gotoxy(17,*selec);printf("  ");
	switch(r)
	{
		case 72:   //seta para cima
			*selec-=3;
			if(*selec<17)
			{
				*selec=17;
			}
			textcolor(9);
			gotoxy(17,*selec);printf("=%c",62);
			*at=0;
			*aux=pag; //armazena em aux o valor da página que deve ser mostrada
			
			telas_pesquisa(1,1);
			ajuda=1;
			break;
		case 80:     //seta para baixo
			*selec+=3;
			if(*selec>29)
			{
				*selec=29;
			}
			if(*selec>y-3)
			{
				*selec=y-3;
			}
			telas_pesquisa(1,1);
			textcolor(9);
			gotoxy(17,*selec);printf("=%c",62);
			*at=0;
			*aux=pag;
			ajuda=1;
			break;
		case 13:
			lin=*selec; //lin armazena a linha a ser mostrada com detalhe
			*aux=pag;	//aux armazena a página atual
			at=0;
			if(strcmp(pesquiisa,"0")!=0)
			{
				ajuda=3;
			}
			else
				ajuda=0;
			system("cls");
			mostrar_detalhe(lin, pag,fh,fv,fa,ff,fq,nome,pesquiisa);
			system("cls");
			for(int i=2; i<=39; i++)
			{
				textbackground(11);
				gotoxy(2,i);printf(" ");
			}
			for(int i=2; i<=39; i++)
			{
				textbackground(11);
				gotoxy(119,i);printf(" ");
			}
			textbackground(15);
			logo_nome(57,1);
			textbackground(11);
			gotoxy(2,2);printf("                                                    ");
			gotoxy(68,2);printf("                                                    ");
			gotoxy(2,39);printf("                                                                                                                      ");
			textbackground(15);
			telas_pesquisa(1,1);
			textcolor(9);
			*selec=17;	//volta cursor para o começo
			gotoxy(17,*selec);printf("=%c",62);
			*aux=pag;
			break;
		default:
			ajuda=0;
			break;
	}	
}

//----------------------------------------------------------------------------------------------------------------------------------

void pesquisa_geral(int selec,int fh,int fv, int fa, int ff, int fq)
{
	char pesquisa[40]="0";
	int nome=0;
	cursor(0);  //apaga cursor
	int aux;   //ajuda a ir na página certa com o movimento de setas
	int at=1;	//ajuda a ir na página certa com o movimento de setas(voltando)
	int lin;	//ir na linha certa na hora de mostrar com detalhe
	char r;	//vai pegar o getche()
	abrir_arquivo_cad("rb");
	textcolor(9);
	gotoxy(17,selec);printf("=%c",62);   //seta posicionada
	telas_pesquisa(1,1);		//borda
	do		//faz o arquivo não parar depois de ser lido até o final
	{
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(2,i);printf(" ");
		}
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(119,i);printf(" ");
		}
		textbackground(15);
		logo_nome(57,1);
		textbackground(11);
		gotoxy(2,2);printf("                                                    ");
		gotoxy(68,2);printf("                                                    ");
		gotoxy(2,39);printf("                                                                                                                      ");
		textbackground(15);
		setlocale(LC_ALL,"C");
		for(int i=53; i<=67; i++)
		{
			textcolor(0);
			gotoxy(i,9);printf("%c",196);
		}
		for(int i=53; i<=67; i++)
		{
			textcolor(0);
			gotoxy(i,7);printf("%c",196);
		}
		setlocale(LC_ALL,NULL);
		textcolor(8);
		gotoxy(53,8);printf("PESQUISA GERAL");
		textcolor(9);
		char inicial[2];	//vai armazenar a primeira letra maiúscula
		int tam;	//ver o tamnho da palavra
		volta=0;	//ajuda na volta do mostrar com detalhe
		int y=17;	//linha em que as informacoes vão aparecer
		rewind(fp);	//recomeca o arquivo
		int pag=1;	//página volta a ser 1
		while(fread(&personagem,sizeof(personagem),1,fp)==1)  //continua no while até ler o arquivo
		{	
			int filtro=1;
			/////////////////////////////////////filtro////////////////////////////////////////////////
			if(fh==0)
			{
				if(personagem.lado=='h'||personagem.lado=='H')
				{
					filtro=0;
				}
			}
			if(fv==0)
			{
				if(personagem.lado=='v'||personagem.lado=='V')
				{
					filtro=0;
				}
			}
			if(fa==0)
			{
				if(personagem.tipo_aparicao=='a'||personagem.tipo_aparicao=='A')
				{
					filtro=0;
				}
			}
			if(fq==0)
			{
				if(personagem.tipo_aparicao=='q'||personagem.tipo_aparicao=='Q')
				{
					filtro=0;
				}
			}
			if(ff==0)
			{
				if(personagem.tipo_aparicao=='f'||personagem.tipo_aparicao=='F')
				{
					filtro=0;
				}
			}
			
			
			if(y>31) //quando ler uma página
			{
				if(at==1&&filtro==1) //referente a seta esquerda, ele vai apenas ler o arquivo até achar a página certa
				{
					////////////////////////////////////////////////////movimento de setas e mostrar detalhe///////////////////////////////////////////////
					
					if(pag==1) //não pode usar seta da esquerda na primeira pagina
					{
						do
						{
						//	getch();
							r=getch();
						}while(r!=27&&r!=77&&r!=80&&r!=72&&r!=13);	//não vai aacontecer nada enquanto um desses não for clicado
					}
					else //se não for primeira pagina pode usar seta da esquerda
					{				
						do
						{
						//	getch();
							r=getch();
						}while(r!=27&&r!=77&&r!=75&&r!=80&&r!=72&&r!=13);  //não vai aacontecer nada enquanto um desses não for clicado
					}
					selecionar(&selec,r,&at,pag,&aux,lin,y,fh,fv,fa,ff,fq,nome,pesquisa);	//função do cursor e de qual vai ser selecionado  (mostrar detalhe)
					if(r==13) //relacionado com a volta da mostrar com detalhe (tem que sair para rebobinar o disco
					{
						break;		
					}
					if(r==27)	//se esc for pressionado
					{
						system("cls");
						fclose(fp);
						return;
					}
					if(r==77)  //seta para direita
					{
						for(int i=11; i<=30;i++)
						{
							gotoxy(22,i);printf("                                                                                        ");
						}
						selec=17;
						y=17;
						textcolor(9);
						gotoxy(17,selec);printf("=%c",62);
						telas_pesquisa(1,1);
						pag++;
						aux=pag;	
					}
					if(r==75) //seta para esquerda
					{
						if(pag>1)
						{						
							for(int i=11; i<=30;i++)
							{
								gotoxy(22,i);printf("                                                                                        ");
							}
							selec=17;
							textcolor(9);
							gotoxy(17,selec);printf("=%c",62);
							telas_pesquisa(1,1);
							y=17;
							at=0;
							pag--;
							aux=pag;
							ajuda=1;
						}
					}
					if(ajuda==1)  //referente ao cursor e a seta esquerda (necessário rebobinar o disco)
						break;
				}
			}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(y>31&&filtro==1)  //fim da página
			{
				y=17;
			//	system("cls");
				textcolor(9);
				gotoxy(17,selec);printf("=%c",62);
				telas_pesquisa(1,1);
				if(at==0&&ajuda==1) //se leu o fim da página e não exibiu, aumentar um na página e continuar até chegar na página correta
				{
					pag++;
				}
			}
			if(at==0)   //verifica se chegou na página correta
			{		
				if(aux==pag)  //se a variável auxiliar for igual a página atual
				{
					at=1;
				}
			}	
			
			//////////////////////////////////////////////mostrando os dados/////////////////////////////////////////////////////////////////
			
			if(at==1&&personagem.excluido=='n'&&filtro==1) //se at=1, esta é a página correta a ser visualizada
			{
				if(y==selec) //se y for igual a linha do cursor, as letras daquela linha vão ser vermelhas
				{
					textcolor(12);
				}
				else  //se não vão ser azuis
				{
					textcolor(9);
				}
					
					
				////////////////   codigo   ///////////////////////////////
				
				gotoxy(22,y);printf("%d",personagem.codigo);
				
				////////////////   nome   ///////////////////////////////
				
				inicial[0]=personagem.nome[0];  //armazena a primeira letra
				strupr(inicial);  //deixa ela maiúscula
				strlwr(personagem.nome); //deixa tudo minúsculo
				tam=strlen(personagem.nome);  //vê o tamanho
				gotoxy(32,y);putchar(inicial[0]);   //coloca a primeira letra que está maiúscula
				if (tam>12) //se passar de 12 vai ultrapassar a borda
				{
					for (int i=1; i<10; i++)
					{
						putchar(personagem.nome[i]);  //exibe da segunda letra até a nona
					}
					printf("..."); //coloca 3 pontinhos
				}
				else
				{
					for (int i=1; i<tam;i++) //se palavra for menor 
					{
						putchar(personagem.nome[i]);  //exibe ela inteira (com exceção da primeira letra que já foi exibida
					}
				}
				
				////////////////   lado   //////////////////////////////
				
				if(personagem.lado=='V'||personagem.lado=='v')
				{
					gotoxy(47,y);puts("Vilao");
				}
				else
				{
					gotoxy(47,y);puts("Heroi");
				}
					
				////////////////   poder   //////////////////////////////
				
					
				inicial[0]=personagem.poder[0];  //mesma lógica do nome
				strupr(inicial);
				strlwr(personagem.poder);
				tam=strlen(personagem.poder);
				gotoxy(57,y);putchar(inicial[0]);
				if (tam>8)
				{
					for (int i=1; i<5; i++)
					{
						putchar(personagem.poder[i]);
					}
					printf("...");
				}
				else
				{
					for (int i=1; i<tam;i++)
					{
						putchar(personagem.poder[i]);
					}
				}
				
				////////////////   tipo   //////////////////////////////
			
				if(personagem.tipo_aparicao=='A'||personagem.tipo_aparicao=='a')
				{
					gotoxy(67,y);puts("Animacao");
				}
				else if(personagem.tipo_aparicao=='f'||personagem.tipo_aparicao=='F')
				{
					gotoxy(67,y);puts("Filme");
				}
				else
				{
					gotoxy(67,y);puts("Quadrinhos");
				}
					
				////////////////   aparicao   //////////////////////////////
					
				inicial[0]=personagem.nome_aparicao[0];   //mesma lógica do nome
				strupr(inicial);
				strlwr(personagem.nome_aparicao);
				tam=strlen(personagem.nome_aparicao);
				gotoxy(83,y);putchar(inicial[0]);
				if (tam>11)
				{
					for (int i=1; i<8; i++)
					{
						putchar(personagem.nome_aparicao[i]);
					}
					printf("...");
				}
				else
				{
					for (int i=1; i<tam;i++)
					{
						putchar(personagem.nome_aparicao[i]);
					}
				}
				
				////////////////   ano   //////////////////////////////
				
				gotoxy(96,y);puts(personagem.ano);
				
				///////////////////////////////////////////////////////
			}
			if(personagem.excluido=='n'&&filtro==1)  //y está fora do if, pois mesmo que não exiba as variáveis ele deve ser contado para marcar o fim da página, a não ser que tenha excluído
				y+=3;
		}
		
		////////////////////////////movimento das setas caso na última página da tabela, arquivo foi todo lido///////////////////////////////////////////////
		
		if(at==1&&volta==0) //se não acabou de voltar do mostrar_detalhe
		{
			if(pag==1)   //primeira página sem seta da esquerda
			{
				do
				{
			//		getch();
					r=getch();
				}while(r!=27&&r!=80&&r!=72&&r!=13);
			}
			else
			{
				do
				{
				//	getch();
					r=getch();
				}while(r!=27&&r!=75&&r!=80&&r!=72&&r!=13); //como acabou de ler o arquivo não terá mais um página a direita, sem seta direita(r==77)
			}
			selecionar(&selec,r,&at,pag,&aux,lin,y,fh,fv,fa,ff,fq,nome,pesquisa);
			if(r==27) //esc
			{
				system("cls");
				fclose(fp);
				return;
			}
		/*	if(r==77)  //seta para direita	
			{
				if(pag<1)
				{
					system("cls");
					y=7;
					telas_pesquisa(1,1);
					pag++;
					aux=pag-1;	
				}
			}
		*/	if(r==75) //seta para esquerda
			{
				if(pag>1)	//necessário verificar se é primeira página, pois primeira pode também ser a última
				{						
					for(int i=11; i<=30;i++)
					{
						gotoxy(22,i);printf("                                                                                        ");
					}
					selec=17;
					textcolor(9);
					gotoxy(17,selec);printf("=%c",62);
					telas_pesquisa(1,1);	
					y=17;
					at=0;
					pag--;
					aux=pag;
					ajuda=1;
				}
			}
		}
	}while(true);
}

//-----------------------------------------------------------------------------------------------------------------------------------

void filtro()
{
	cursor(0);
	int escape=1;
	int opc1,opc2,opc3,opc4,opc5;
	int fv=1;
	int fh=1; 
	int fa=1;
	int ff=1;
	int fq=1;
	char f;
	int x=15;
	int y=12;
	system("cls");
	
	do
	{
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(2,i);printf(" ");
		}
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(119,i);printf(" ");
		}
		textbackground(15);
		logo_nome(57,1);
		textbackground(11);
		gotoxy(2,2);printf("                                                    ");
		gotoxy(68,2);printf("                                                    ");
		gotoxy(2,39);printf("                                                                                                                      ");
		textbackground(15);
		for(int i=10; i<=23; i++)
		{
			textbackground(0);
			gotoxy(6,i);printf(" ");
		}
		for(int j=10; j<=23; j++)
		{
			textbackground(0);
			gotoxy(115,j);printf(" ");
		}
		for(int m=6; m<=115; m++)
		{
			textbackground(0);
			gotoxy(m,10);printf(" ");
		}
		for(int n=6; n<=115; n++)
		{
			textbackground(0);
			gotoxy(n,23);printf(" ");
		}
		textbackground(15);
		setlocale(LC_ALL,"C");
		for(int i=53; i<=67; i++)
		{
			textcolor(0);
			gotoxy(i,8);printf("%c",196);
		}
		for(int i=53; i<=67; i++)
		{
			textcolor(0);
			gotoxy(i,6);printf("%c",196);
		}
		for(int i=11; i<=114; i++)
		{
			textcolor(0);
			gotoxy(i,14);printf("%c",196);
		}
		for(int i=11; i<=114; i++)
		{
			textcolor(0);
			gotoxy(i,17);printf("%c",196);
		}
		textbackground(15);
		setlocale(LC_ALL,NULL);
		textcolor(8);
		gotoxy(57,7);printf("FILTROS");
		textbackground(15);
		setlocale(LC_ALL,"C");
		textcolor(0);
		gotoxy(13,12);printf("%c",254);
		gotoxy(13,15);printf("%c",254);
		gotoxy(38,12);printf("%c",254);
		gotoxy(38,15);printf("%c",254);
		gotoxy(63,15);printf("%c",254);   //158 X  1 V
		
			////////////////////////////////EMOTES////////////////////////////////////	
		if(escape==1)
		{
			textcolor(2);
			gotoxy(12,12);printf("%c",1);
			gotoxy(12,15);printf("%c",1);
			gotoxy(37,12);printf("%c",1);
			gotoxy(37,15);printf("%c",1);
			gotoxy(62,15);printf("%c",1);
			fv=1;
			fh=1; 
			fa=1;
			ff=1;
			fq=1;
			escape=0;
		}
		
		////////////////////////////////////////////////////////////////////////////
		
		setlocale(LC_ALL,NULL);
		textcolor(9);
		gotoxy(14,12);printf("Vil%co",198);
		gotoxy(39,12);printf("Her%ci",162);
		gotoxy(14,15);printf("Filme");
		gotoxy(39,15);printf("Anima%c%co",135,198);
		gotoxy(64,15);printf("Quadrinhos");
		gotoxy(x-4,y);printf("%c",62);
		gotoxy(13,18);printf("Use as setas para mover cursor");
		setlocale(LC_ALL,"C");
		gotoxy(13,19);printf("Aperte espaco para selecionar(%c) ou apagar (%c) e enter para salvar as altera%c%ces e ver a tabela",1,158,135,228);
		setlocale(LC_ALL,NULL);
		gotoxy(13,20);printf("Aperte esc para voltar");
		do
		{
			gotoxy(x-4,y);printf("%c",62);
			f=getch();
			gotoxy(x-4,y);printf(" ");
			gotoxy(13,24);printf("                                             ");
		}while(f!=72&&f!=80&&f!=13&&f!=27&&f!=77&&f!=75&&f!=' ');  //cima baixo enter esc direita esquerda espaço
			switch (f)
			{
				case 27:  //esc
					system("cls");
					return;
					break;
				case 72:  //cima
					y-=3;
					if(y<12)
						y=12;
					if(x==65&&y<15)
						y=15;
					gotoxy(x-4,y);printf("%c",62);
					break;
				case 80:  //baixo
					y+=3;
					if(y>15);
						y=15;
					gotoxy(x-4,y);printf("%c",62);
					break;
				case 77:  //direita
					x+=25;
					if(x>65)
						x=65;
					if(y==12&&x>40)
						x=40;
					gotoxy(x-4,y);printf("%c",62);
					break;
				case 75:  //esquerda
					x-=25;
					if(x<15)
						x=15;
					gotoxy(x-4,y);printf("%c",62);
					break;
				case 13:  //enter
					system("cls");
					pesquisa_geral(17,fh,fv,fa,ff,fq);
					escape=1;
					break;
				default:  //espaço
					setlocale(LC_ALL,"C");
					switch(x)
					{
						case 15:
							if(y==12)
								if(fv==1)
								{
									fv=0;
									textcolor(12); //4
									gotoxy(x-3,y);printf("%c",158);
									if(fh==0)
									{
										setlocale(LC_ALL,NULL);
										textcolor(9);
										gotoxy(13,24);printf("Aviso, esta op%c%co n%co mostrar%c nada na tabela",135,198,198,160);
										setlocale(LC_ALL,"C");
									}
								}
								else
								{
									fv=1;
									textcolor(2);
									gotoxy(x-3,y);printf("%c",1);
								}
							if(y==15)
								if(ff==1)
								{
									ff=0;
									textcolor(12); //4
									gotoxy(x-3,y);printf("%c",158);
									if(fa==0&&fq==0)
									{
										setlocale(LC_ALL,NULL);
										textcolor(9);
										gotoxy(13,24);printf("Aviso, esta op%c%co n%co mostrar%c nada na tabela",135,198,198,160);
										setlocale(LC_ALL,"C");
									}
								}
								else
								{
									ff=1;
									textcolor(2);
									gotoxy(x-3,y);printf("%c",1);
								}
							break;
						case 40:
							if(y==12)
								if(fh==1)
								{
									fh=0;
									textcolor(12); //4
									gotoxy(x-3,y);printf("%c",158);
									if(fv==0)
									{
										setlocale(LC_ALL,NULL);
										textcolor(9);
										gotoxy(13,24);printf("Aviso, esta op%c%co n%co mostrar%c nada na tabela",135,198,198,160);
										setlocale(LC_ALL,"C");
									}
								}
								else
								{
									fh=1;
									textcolor(2);
									gotoxy(x-3,y);printf("%c",1);
								}
								if(y==15)
									if(fa==1)
									{
										fa=0;
										textcolor(12); //4
										gotoxy(x-3,y);printf("%c",158);
										if(ff==0&&fq==0)
										{
											setlocale(LC_ALL,NULL);
											textcolor(9);
											gotoxy(13,24);printf("Aviso, esta op%c%co n%co mostrar%c nada na tabela",135,198,198,160);
											setlocale(LC_ALL,"C");
										}
									}
									else
									{
										fa=1;
										textcolor(2);
										gotoxy(x-3,y);printf("%c",1);
									}
							break;
						case 65:
							if(fq==1)
							{
								fq=0;
								textcolor(12); //4
								gotoxy(x-3,y);printf("%c",158);
								if(fa==0&&ff==0)
								{
									setlocale(LC_ALL,NULL);
									textcolor(9);
									gotoxy(13,24);printf("Aviso, esta op%c%co n%co mostrar%c nada na tabela",135,198,198,160);
									setlocale(LC_ALL,"C");
								}
							}
							else
							{
								fq=1;
								textcolor(2);
								gotoxy(x-3,y);printf("%c",1);
							}
					}
					setlocale(LC_ALL,NULL);
					textcolor(9);
					gotoxy(x-4,y);printf("%c",62);
					break;
			}
	}while(true);
}

//----------------------------------------------------------------------------------------------------------------------------------

void pesquisa_codigo()
{
	int pesquisa, f;
	char aux_codigo[100];
	abrir_arquivo_cad("rb");
	char conf_codigo;
	char op;
	int salva=0;
	do
	{
		rewind(fp); //reposiciona o ponteiro no início do arquivo
		f = 0;
		cursor(1);
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(2,i);printf(" ");
		}
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(119,i);printf(" ");
		}
		textbackground(15);
		logo_nome(57,1);
		textbackground(11);
		gotoxy(2,2);printf("                                                    ");
		gotoxy(68,2);printf("                                                    ");
		gotoxy(2,39);printf("                                                                                                                      ");
		textbackground(15);
		cursor(1);
		textcolor(0);
		gotoxy(50,5);printf("PESQUISA POR C%cDIGO",224);
		setlocale(LC_ALL,"C");
		textcolor(8);
		gotoxy(42,8);printf("%c",179);
		gotoxy(79,8);printf("%c",179);
		for(int i=42; i<=79; i++)
		{
			textcolor(8);
			gotoxy(i,9);printf("%c",196);
		}
	
		for(int i=42; i<=79; i++)
		{
			textcolor(8);
			gotoxy(i,7);printf("%c",196);
		}
		gotoxy(42,9); printf("%c",192);
		gotoxy(42,7); printf("%c",218);
		gotoxy(79,7); printf("%c",191);
		gotoxy(79,9); printf("%c",217);
		
		setlocale(LC_ALL,NULL);
		textcolor(0);
		gotoxy(43,8);printf("Pesquisar (digite 0 para sair): ");

		do
		{
			salva=1;
			gotoxy(75,8);gets(aux_codigo);
			gotoxy(22,15);printf ("                            ");
			if (aux_codigo[0]=='0')
				return;
			if(strstr(aux_codigo,"a")!=NULL||strstr(aux_codigo,"b")!=NULL||strstr(aux_codigo,"c")!=NULL||strstr(aux_codigo,"d")!=NULL||strstr(aux_codigo,"e")!=NULL||strstr(aux_codigo,"f")!=NULL||strstr(aux_codigo,"g")!=NULL||strstr(aux_codigo,"h")!=NULL||strstr(aux_codigo,"i")!=NULL||strstr(aux_codigo,"j")!=NULL||strstr(aux_codigo,"k")!=NULL||strstr(aux_codigo,"l")!=NULL||strstr(aux_codigo,"m")!=NULL||strstr(aux_codigo,"n")!=NULL||strstr(aux_codigo,"o")!=NULL||strstr(aux_codigo,"p")!=NULL||strstr(aux_codigo,"q")!=NULL||strstr(aux_codigo,"r")!=NULL||strstr(aux_codigo,"s")!=NULL||strstr(aux_codigo,"t")!=NULL||strstr(aux_codigo,"u")!=NULL||strstr(aux_codigo,"v")!=NULL||strstr(aux_codigo,"w")!=NULL||strstr(aux_codigo,"x")!=NULL||strstr(aux_codigo,"y")!=NULL||strstr(aux_codigo,"z")!=NULL||strstr(aux_codigo,"A")!=NULL||strstr(aux_codigo,"B")!=NULL||strstr(aux_codigo,"C")!=NULL||strstr(aux_codigo,"D")!=NULL||strstr(aux_codigo,"E")!=NULL||strstr(aux_codigo,"F")!=NULL||strstr(aux_codigo,"G")!=NULL||strstr(aux_codigo,"H")!=NULL||strstr(aux_codigo,"I")!=NULL||strstr(aux_codigo,"J")!=NULL||strstr(aux_codigo,"K")!=NULL||strstr(aux_codigo,"L")!=NULL||strstr(aux_codigo,"M")!=NULL||strstr(aux_codigo,"N")!=NULL||strstr(aux_codigo,"O")!=NULL||strstr(aux_codigo,"P")!=NULL||strstr(aux_codigo,"Q")!=NULL||strstr(aux_codigo,"R")!=NULL||strstr(aux_codigo,"S")!=NULL||strstr(aux_codigo,"T")!=NULL||strstr(aux_codigo,"U")!=NULL||strstr(aux_codigo,"V")!=NULL||strstr(aux_codigo,"W")!=NULL||strstr(aux_codigo,"X")!=NULL||strstr(aux_codigo,"Y")!=NULL||strstr(aux_codigo,"Z")!=NULL)
			{
				gotoxy(22,15);printf ("C%cdigo invalido!",162);
				gotoxy(75,8);printf("   ");
				salva=0;
			}
			if(strlen(aux_codigo)>3)
			{
				gotoxy(75,8);
				for(int i=0; i<=strlen(aux_codigo); i++)
				{
					printf(" ");
				}
				cursor(1);
				for(int i=2; i<=39; i++)
				{
					textbackground(11);
					gotoxy(2,i);printf(" ");
				}
				for(int i=2; i<=39; i++)
				{
					textbackground(11);
					gotoxy(119,i);printf(" ");
				}
				textbackground(15);
				logo_nome(57,1);
				textbackground(11);
				gotoxy(2,2);printf("                                                    ");
				gotoxy(68,2);printf("                                                    ");
				gotoxy(2,39);printf("                                                                                                                      ");
				textbackground(15);
				cursor(1);
				textcolor(0);
				gotoxy(50,5);printf("PESQUISA POR C%cDIGO",224);
				setlocale(LC_ALL,"C");
				textcolor(8);
				gotoxy(42,8);printf("%c",179);
				gotoxy(79,8);printf("%c",179);
				for(int i=42; i<=79; i++)
				{
					textcolor(8);
					gotoxy(i,9);printf("%c",196);
				}
			
				for(int i=42; i<=79; i++)
				{
					textcolor(8);
					gotoxy(i,7);printf("%c",196);
				}
				gotoxy(42,9); printf("%c",192);
				gotoxy(42,7); printf("%c",218);
				gotoxy(79,7); printf("%c",191);
				gotoxy(79,9); printf("%c",217);
				
				setlocale(LC_ALL,NULL);
				textcolor(0);
				gotoxy(43,8);printf("Pesquisar (digite 0 para sair): ");
				
			}
		}while(strstr(aux_codigo,"a")!=NULL||strstr(aux_codigo,"b")!=NULL||strstr(aux_codigo,"c")!=NULL||strstr(aux_codigo,"d")!=NULL||strstr(aux_codigo,"e")!=NULL||strstr(aux_codigo,"f")!=NULL||strstr(aux_codigo,"g")!=NULL||strstr(aux_codigo,"h")!=NULL||strstr(aux_codigo,"i")!=NULL||strstr(aux_codigo,"j")!=NULL||strstr(aux_codigo,"k")!=NULL||strstr(aux_codigo,"l")!=NULL||strstr(aux_codigo,"m")!=NULL||strstr(aux_codigo,"n")!=NULL||strstr(aux_codigo,"o")!=NULL||strstr(aux_codigo,"p")!=NULL||strstr(aux_codigo,"q")!=NULL||strstr(aux_codigo,"r")!=NULL||strstr(aux_codigo,"s")!=NULL||strstr(aux_codigo,"t")!=NULL||strstr(aux_codigo,"u")!=NULL||strstr(aux_codigo,"v")!=NULL||strstr(aux_codigo,"w")!=NULL||strstr(aux_codigo,"x")!=NULL||strstr(aux_codigo,"y")!=NULL||strstr(aux_codigo,"z")!=NULL||strstr(aux_codigo,"A")!=NULL||strstr(aux_codigo,"B")!=NULL||strstr(aux_codigo,"C")!=NULL||strstr(aux_codigo,"D")!=NULL||strstr(aux_codigo,"E")!=NULL||strstr(aux_codigo,"F")!=NULL||strstr(aux_codigo,"G")!=NULL||strstr(aux_codigo,"H")!=NULL||strstr(aux_codigo,"I")!=NULL||strstr(aux_codigo,"J")!=NULL||strstr(aux_codigo,"K")!=NULL||strstr(aux_codigo,"L")!=NULL||strstr(aux_codigo,"M")!=NULL||strstr(aux_codigo,"N")!=NULL||strstr(aux_codigo,"O")!=NULL||strstr(aux_codigo,"P")!=NULL||strstr(aux_codigo,"Q")!=NULL||strstr(aux_codigo,"R")!=NULL||strstr(aux_codigo,"S")!=NULL||strstr(aux_codigo,"T")!=NULL||strstr(aux_codigo,"U")!=NULL||strstr(aux_codigo,"V")!=NULL||strstr(aux_codigo,"W")!=NULL||strstr(aux_codigo,"X")!=NULL||strstr(aux_codigo,"Y")!=NULL||strstr(aux_codigo,"Z")!=NULL);
		gotoxy(22,15);printf ("                 ");
		fflush(stdin);
		pesquisa=atoi(aux_codigo);
		gotoxy(22,15);printf ("                        ");
		while( fread( &personagem,sizeof(personagem),1,fp) == 1 )
		{
			if(pesquisa == personagem.codigo && personagem.excluido=='n')
			{
			
				f = 1;
				int tam;
				char inicial[2];
				for(int i=12; i<=28; i++)
				{
					textbackground(0);
					gotoxy(23,i);printf(" ");
				}
				for(int j=12; j<=28; j++)
				{
					textbackground(0);
					gotoxy(67,j);printf(" ");
				}
				for(int x=23; x<=67; x++)
				{
					textbackground(0);
					gotoxy(x,12);printf(" ");
				}
				for(int x=23; x<=67; x++)
				{
					textbackground(0);
					gotoxy(x,28);printf(" ");
				}
				ben10(85,14);
				textcolor(2);
				textbackground(15);
				gotoxy(25,14);printf("C%cdigo: %d",162,personagem.codigo);
				inicial[0]=personagem.nome[0];
				strupr(inicial);
				strlwr(personagem.nome);
				tam=strlen(personagem.nome);
				gotoxy(25,15);printf("Nome:");
				gotoxy(31,15);putchar(inicial[0]);
				for (int i=1; i<tam;i++)
				{
					putchar(personagem.nome[i]);
				}
				if(personagem.lado=='V'||personagem.lado=='v')
				{
					gotoxy(25,16);printf ("Lado: ");
					gotoxy(31,16);puts("Vilao");
				}
				else
				{
					gotoxy(25,16);printf ("Lado: ");
					gotoxy(31,16);puts("Heroi");
				}
				inicial[0]=personagem.poder[0];
				strupr(inicial);
				strlwr(personagem.poder);
				tam=strlen(personagem.poder);
				gotoxy(25,17);printf ("Poder: ");
				gotoxy(32,17);putchar(inicial[0]);
				for (int i=1; i<tam;i++)
				{
					putchar(personagem.poder[i]);
				}
				if(personagem.tipo_aparicao=='A'||personagem.tipo_aparicao=='a')
				{
					gotoxy(25,18);printf("Tipo da apari%c%co: ",135,198);
					gotoxy(43,18);puts("Animacao");
				}
				else if(personagem.tipo_aparicao=='f'||personagem.tipo_aparicao=='F')
				{
					gotoxy(25,18);printf("Tipo da apari%c%co: ",135,198);
					gotoxy(43,18);puts("Filme");
				}
				else
				{
					gotoxy(25,18);printf("Tipo da apari%c%co: ",135,198);
					gotoxy(43,18);puts("Quadrinhos");
				}
				inicial[0]=personagem.nome_aparicao[0];
				strupr(inicial);
				strlwr(personagem.nome_aparicao);
				tam=strlen(personagem.nome_aparicao);
				gotoxy(25,19);printf("Nome da apari%c%co: ",135,198);
				gotoxy(43,19);putchar(inicial[0]);
				for (int i=1; i<tam;i++)
				{
					putchar(personagem.nome_aparicao[i]);
				}
				gotoxy(25,20);printf ("Ano: ");
				gotoxy(30,20);puts(personagem.ano);
				gotoxy(25,25);printf("Deseja realizar outra pesquisa? (S/N): ");
				gotoxy(64,25); conf_codigo = getche();
				while( conf_codigo != 's' && conf_codigo != 'S'&& conf_codigo != 'n' && conf_codigo != 'N' )
				{
					gotoxy(25,27);printf("Resposta inv%clida, digite novamente!",160);
					gotoxy(25,25);printf("  ");
					gotoxy(64,25);conf_codigo = getche();
				}
				break;
			}
		}
		if(f == 0 && salva ==1)
		{
			gotoxy(75,8);printf("   ");
			gotoxy(22,15);printf ("C%cdigo n%co cadastrado!",162,198);
			Sleep(1000);
		}
		if(conf_codigo=='n'||conf_codigo=='N')
				break;
		else if(conf_codigo=='s'||conf_codigo=='S')
		{
			system("cls");
		}
	} while( true ); //fim do-while
}

//----------------------------------------------------------------------------------------------------------------------------------

void pesquisa_nome(int selec)
{
	int fa=1, ff=1, fh=1, fv=1,fq=1;
	int aux;
	int at=1;
	int lin;
	char r;
	char pesquisa[40];
	char aux_nome[40];
	char op;
	abrir_arquivo_cad("rb");
	while(true)
	{
	//	r=' ';
		cursor(1);
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(2,i);printf(" ");
		}
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(119,i);printf(" ");
		}
		textbackground(15);
		logo_nome(57,1);
		textbackground(11);
		gotoxy(2,2);printf("                                                    ");
		gotoxy(68,2);printf("                                                    ");
		gotoxy(2,39);printf("                                                                                                                      ");
		textbackground(15);
		cursor(1);
		textcolor(0);
		gotoxy(52,5);printf("PESQUISA POR NOME");
		setlocale(LC_ALL,"C");
		textcolor(8);
		gotoxy(33,8);printf("%c",179);
		gotoxy(88,8);printf("%c",179);
		for(int i=34; i<=87; i++)
		{
			textcolor(8);
			gotoxy(i,9);printf("%c",196);
		}
		gotoxy(33,9); printf("%c",192);
		gotoxy(33,7); printf("%c",218);
		gotoxy(88,7); printf("%c",191);
		gotoxy(88,9); printf("%c",217);
		for(int i=34; i<=87; i++)
		{
			textcolor(8);
			gotoxy(i,7);printf("%c",196);
		}
		setlocale(LC_ALL,NULL);
		textcolor(0);
		gotoxy(35,8);printf("Pesquisar <para sair digite 0>: ");
		gotoxy(67,8);gets(pesquisa);
		if (pesquisa[0]=='0')
			return;
		cursor(0);
		strupr(pesquisa);
		telas_pesquisa(1,1);
		textcolor(9);
		gotoxy(76,32);printf("                      ");
		gotoxy(76,32);printf("pesquisar novamente");
		
		gotoxy(17,selec);printf("=%c",62);
		do
		{
			char inicial[2];
			int tam;
			int nome=1;
			int y=17;
			rewind(fp);
			int pag=1;
			textcolor(0);
			gotoxy(52,5);printf("PESQUISA POR NOME");
			setlocale(LC_ALL,"C");
			textcolor(8);
			gotoxy(33,8);printf("%c",179);
			gotoxy(88,8);printf("%c",179);
			for(int i=34; i<=87; i++)
				{
				textcolor(8);
				gotoxy(i,9);printf("%c",196);
			}
			gotoxy(33,9); printf("%c",192);
			gotoxy(33,7); printf("%c",218);
			gotoxy(88,7); printf("%c",191);
			gotoxy(88,9); printf("%c",217);
			for(int i=34; i<=87; i++)
			{
				textcolor(8);
				gotoxy(i,7);printf("%c",196);
			}
			setlocale(LC_ALL,NULL);
			textcolor(0);
			gotoxy(35,8);printf("Pesquisar <para sair digite 0>: ");
			gotoxy(67,8);puts(pesquisa);
			textcolor(9);
			gotoxy(76,32);printf("                      ");
			gotoxy(76,32);printf("pesquisar novamente");
			while(fread(&personagem,sizeof(personagem),1,fp)==1)
			{	
				strcpy(aux_nome,personagem.nome);
				strupr(aux_nome);
				if(strstr(aux_nome,pesquisa)!=NULL && personagem.excluido=='n')
				{
					if(y>31)
					{
						if(at==1)
						{
							if(pag==1)
							{
								do
								{
								//	getch();
									r=getch();
								}while(r!=27&&r!=77&&r!=80&&r!=72&&r!=13);	
							}
							else
							{				
								do
								{
								//	getch();
									r=getch();
								}while(r!=27&&r!=77&&r!=75&&r!=80&&r!=72&&r!=13);
							}
							selecionar(&selec,r,&at,pag,&aux,lin,y,fh,fv,fa,ff,fq,nome,pesquisa);
							if(ajuda==3)
							{
								break;
							}
							textcolor(0);
							gotoxy(52,5);printf("PESQUISA POR NOME");
							setlocale(LC_ALL,"C");
							textcolor(8);
							gotoxy(33,8);printf("%c",179);
							gotoxy(88,8);printf("%c",179);
							for(int i=34; i<=87; i++)
							{
								textcolor(8);
								gotoxy(i,9);printf("%c",196);
							}
							gotoxy(33,9); printf("%c",192);
							gotoxy(33,7); printf("%c",218);
							gotoxy(88,7); printf("%c",191);
							gotoxy(88,9); printf("%c",217);
							for(int i=34; i<=87; i++)
							{
								textcolor(8);
								gotoxy(i,7);printf("%c",196);
							}
							setlocale(LC_ALL,NULL);
							textcolor(0);
							gotoxy(35,8);printf("Pesquisar <para sair digite 0>: ");
							gotoxy(67,8);puts(pesquisa);
							textcolor(9);
							gotoxy(76,32);printf("                      ");
							gotoxy(76,32);printf("pesquisar novamente");
							if(r==27)
							{
								break;
							}
							if(r==77)  //seta para direita
							{
								for(int i=11; i<=30;i++)
								{
									gotoxy(22,i);printf("                                                                                        ");
								}
								selec=17;
								y=17;
								gotoxy(17,selec);printf("=%c",62);
								telas_pesquisa(1,1);
								textcolor(0);
								gotoxy(52,5);printf("PESQUISA POR NOME");
								setlocale(LC_ALL,"C");
								textcolor(8);
								gotoxy(33,8);printf("%c",179);
								gotoxy(88,8);printf("%c",179);
								for(int i=34; i<=87; i++)
								{
									textcolor(8);
									gotoxy(i,9);printf("%c",196);
								}
								gotoxy(33,9); printf("%c",192);
								gotoxy(33,7); printf("%c",218);
								gotoxy(88,7); printf("%c",191);
								gotoxy(88,9); printf("%c",217);
								for(int i=34; i<=87; i++)
								{
									textcolor(8);
									gotoxy(i,7);printf("%c",196);
								}
								setlocale(LC_ALL,NULL);
								textcolor(0);
								gotoxy(35,8);printf("Pesquisar <para sair digite 0>: ");
								gotoxy(67,8);puts(pesquisa);
								textcolor(9);
								gotoxy(76,32);printf("                      ");
								gotoxy(76,32);printf("pesquisar novamente");
								pag++;
								aux=pag;	
							}
							if(r==75) //seta para esquerda
							{
								if(pag>1)
								{						
									for(int j=11; j<=30;j++)
									{
										gotoxy(22,j);printf("                                                                                        ");
									}
									selec=17;
									gotoxy(17,selec);printf("=%c",62);
									telas_pesquisa(1,1);
									textcolor(0);
									gotoxy(52,5);printf("PESQUISA POR NOME");
									setlocale(LC_ALL,"C");
									textcolor(8);
									gotoxy(33,8);printf("%c",179);
									gotoxy(88,8);printf("%c",179);
									for(int i=34; i<=87; i++)
									{
										textcolor(8);
										gotoxy(i,9);printf("%c",196);
									}
									gotoxy(33,9); printf("%c",192);
									gotoxy(33,7); printf("%c",218);
									gotoxy(88,7); printf("%c",191);
									gotoxy(88,9); printf("%c",217);
									for(int i=34; i<=87; i++)
									{
										textcolor(8);
										gotoxy(i,7);printf("%c",196);
									}
									setlocale(LC_ALL,NULL);
									textcolor(0);
									gotoxy(35,8);printf("Pesquisar <para sair digite 0>: ");
									gotoxy(67,8);puts(pesquisa);
									textcolor(9);
									gotoxy(76,32);printf("                      ");
									gotoxy(76,32);printf("pesquisar novamente");
									y=17;
									at=0;
									pag--;
									aux=pag;
									ajuda=1;
								}
							}
							if(ajuda==1)
								break;
						}
					}
					if(y>31)
					{
						y=17;
					//	system("cls");
						gotoxy(17,selec);printf("=%c",62);
						telas_pesquisa(1,1);
						textcolor(0);
						gotoxy(52,5);printf("PESQUISA POR NOME");
						setlocale(LC_ALL,"C");
						textcolor(8);
						gotoxy(33,8);printf("%c",179);
						gotoxy(88,8);printf("%c",179);
						for(int i=34; i<=87; i++)
						{
							textcolor(8);
							gotoxy(i,9);printf("%c",196);
						}
						gotoxy(33,9); printf("%c",192);
						gotoxy(33,7); printf("%c",218);
						gotoxy(88,7); printf("%c",191);
						gotoxy(88,9); printf("%c",217);
						for(int i=34; i<=87; i++)
						{
							textcolor(8);
							gotoxy(i,7);printf("%c",196);
						}
						setlocale(LC_ALL,NULL);
						textcolor(0);
						gotoxy(35,8);printf("Pesquisar <para sair digite 0>: ");
						gotoxy(67,8);puts(pesquisa);
						textcolor(9);
						gotoxy(76,32);printf("                      ");
						gotoxy(76,32);printf("pesquisar novamente");
						if(at==0&&ajuda==1)
						{
							pag++;
						}
					}
					if(at==0)
					{		
						if(aux==pag)
						{
							at=1;
						}
					}	
					if(at==1&&personagem.excluido=='n')
					{
						if(y==selec)
						{
							textcolor(12);
						}
						else
						{
							textcolor(9);
						}
							
							
						////////////////   codigo   ///////////////////////////////
						
						gotoxy(22,y);printf("%d",personagem.codigo);
						
						////////////////   nome   ///////////////////////////////
						
						inicial[0]=personagem.nome[0];
						strupr(inicial);
						strlwr(personagem.nome);
						tam=strlen(personagem.nome);
						gotoxy(32,y);putchar(inicial[0]);
						if (tam>12)
						{
							for (int i=1; i<10; i++)
							{
								putchar(personagem.nome[i]);
							}
							printf("...");
						}
						else
						{
							for (int i=1; i<tam;i++)
							{
								putchar(personagem.nome[i]);
							}
						}
						
						////////////////   lado   //////////////////////////////
						
						if(personagem.lado=='V'||personagem.lado=='v')
						{
							gotoxy(47,y);puts("Vilao");
						}
						else
						{
							gotoxy(47,y);puts("Heroi");
						}
							
						////////////////   poder   //////////////////////////////
						
							
						inicial[0]=personagem.poder[0];
						strupr(inicial);
						strlwr(personagem.poder);
						tam=strlen(personagem.poder);
						gotoxy(57,y);putchar(inicial[0]);
						if (tam>8)
						{
							for (int i=1; i<5; i++)
							{
								putchar(personagem.poder[i]);
							}
							printf("...");
						}
						else
						{
							for (int i=1; i<tam;i++)
							{
								putchar(personagem.poder[i]);
							}
						}
						
						////////////////   tipo   //////////////////////////////
					
						if(personagem.tipo_aparicao=='A'||personagem.tipo_aparicao=='a')
						{
							gotoxy(67,y);puts("Animacao");
						}
						else if(personagem.tipo_aparicao=='f'||personagem.tipo_aparicao=='F')
						{
							gotoxy(67,y);puts("Filme");
						}
						else
						{
							gotoxy(67,y);puts("Quadrinhos");
						}
							
						////////////////   aparicao   //////////////////////////////
							
						inicial[0]=personagem.nome_aparicao[0];
						strupr(inicial);
						strlwr(personagem.nome_aparicao);
						tam=strlen(personagem.nome_aparicao);
						gotoxy(83,y);putchar(inicial[0]);
						if (tam>11)
						{
							for (int i=1; i<8; i++)
							{
								putchar(personagem.nome_aparicao[i]);
							}
							printf("...");
						}
						else
						{
							for (int i=1; i<tam;i++)
							{
								putchar(personagem.nome_aparicao[i]);
							}
						}
						
						////////////////   ano   //////////////////////////////
						
						gotoxy(96,y);puts(personagem.ano);
						
						///////////////////////////////////////////////////////
					}
					y+=3;
				}
			}
			if(r==27)
				break;
			if(at==1&&ajuda!=3)
			{
				if(pag==1)
				{
					do
					{
					//	getch();
						r=getch();
					}while(r!=27&&r!=80&&r!=72&&r!=13);
				}
				else
				{
					do
					{
					//	getch();
						r=getch();
					}while(r!=27&&r!=75&&r!=80&&r!=72&&r!=13);
				}
				selecionar(&selec,r,&at,pag,&aux,lin,y,fh,fv,fa,ff,fq,nome,pesquisa);
				if(ajuda==3)
				{
					ajuda=0;
					at=1;
					pag=1;
				}
				textcolor(0);
				gotoxy(52,5);printf("PESQUISA POR NOME");
				setlocale(LC_ALL,"C");
				textcolor(8);
				gotoxy(33,8);printf("%c",179);
				gotoxy(88,8);printf("%c",179);
				for(int i=34; i<=87; i++)
				{
					textcolor(8);
					gotoxy(i,9);printf("%c",196);
				}
				gotoxy(33,9); printf("%c",192);
				gotoxy(33,7); printf("%c",218);
				gotoxy(88,7); printf("%c",191);
				gotoxy(88,9); printf("%c",217);
				for(int i=34; i<=87; i++)
				{
					textcolor(8);
					gotoxy(i,7);printf("%c",196);
				}
				setlocale(LC_ALL,NULL);
				textcolor(0);
				gotoxy(35,8);printf("Pesquisar <para sair digite 0>: ");
				gotoxy(67,8);puts(pesquisa);
				textcolor(9);
				gotoxy(76,32);printf("                      ");
				gotoxy(76,32);printf("pesquisar novamente");
				if(r==27)
				{
					r=1;
					break;
				}
				if(r==75) //seta para esquerda
				{
					if(pag>1)
					{						
						for(int j=11; j<=30;j++)
						{
							gotoxy(22,j);printf("                                                                                        ");
						}
						selec=17;
						gotoxy(17,selec);printf("=%c",62);
						telas_pesquisa(1,1);
						textcolor(0);
						gotoxy(52,5);printf("PESQUISA POR NOME");
						setlocale(LC_ALL,"C");
						textcolor(8);
						gotoxy(33,8);printf("%c",179);
						gotoxy(88,8);printf("%c",179);
						for(int i=34; i<=87; i++)
						{
							textcolor(8);
							gotoxy(i,9);printf("%c",196);
						}
						gotoxy(33,9); printf("%c",192);
						gotoxy(33,7); printf("%c",218);
						gotoxy(88,7); printf("%c",191);
						gotoxy(88,9); printf("%c",217);
						for(int i=34; i<=87; i++)
						{
							textcolor(8);
							gotoxy(i,7);printf("%c",196);
						}
						setlocale(LC_ALL,NULL);
						textcolor(0);
			 			gotoxy(35,8);printf("Pesquisar <para sair digite 0>: ");
						gotoxy(67,8);puts(pesquisa);
						textcolor(9);
						gotoxy(76,32);printf("                      ");
						gotoxy(76,32);printf("pesquisar novamente");
						y=17;
						at=0;
						pag--;
						aux=pag;
						ajuda=1;
					}
				}
			}
		}while(true);
		selec=17;
		cursor(1);
		textcolor(1);
		gotoxy(40,36);printf("Deseja pesquisar outro nome <s ou n>? ");
		gotoxy(78,36);op=getche();
		while(op!='n'&&op!='s')
		{
			gotoxy(40,37);printf("D%cgito inv%clido!",213,160);
			Sleep(500);
			gotoxy(78,36);printf("   ");
			gotoxy(40,37);printf("                 ");
			gotoxy(78,36);op=getche();	
		}
		if(op=='n')
		{
			gotoxy(40,37);printf("Aguarde um momento");
			cursor(0);
			Sleep(500);
			return;
		}
		else if(op=='s')
		{
			gotoxy(40,37);printf("Aguarde um momento");
			cursor(0);
			Sleep(500);
			system("cls");
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------------------

void viuvanegra(int x, int y)
{
	///////////////////////////// fundo /////////////////////////////
	textcolor(0);
	textbackground(0);
	///////////linha 1
	gotoxy(x,y);printf("###########");
	
	///////////linha 2
	gotoxy(x-2,y+1);printf("##           ##");
	gotoxy(x+11,y+1);printf("##");
	
	///////////linha 3
	gotoxy(x-4,y+2);printf("##               ##");
	gotoxy(x+13,y+2);printf("##");
	///////////linha 4
	gotoxy(x-6,y+3);printf("##     #########     ##");
	gotoxy(x+15,y+3);printf("##");
	gotoxy(x+1,y+3);printf("#########");
	///////////linha 5
	gotoxy(x-7,y+4);printf("#        #######        #");
	gotoxy(x+16,y+4);printf("##");
	gotoxy(x+2,y+4);printf("#######");
	///////////linha 6
	gotoxy(x-7,y+5);printf("#         #####         #");
	gotoxy(x+16,y+5);printf("##");
	gotoxy(x+3,y+5);printf("#####");
	///////////linha 7
	gotoxy(x-7,y+6);printf("#          ###          #");
	gotoxy(x+16,y+6);printf("##");
	gotoxy(x+4,y+6);printf("###");
	///////////linha 8
	gotoxy(x-7,y+7);printf("#          ###          #");
	gotoxy(x+16,y+7);printf("##");
	gotoxy(x+4,y+7);printf("###");
	///////////linha 9
	gotoxy(x-7,y+8);printf("#         #####         #");
	gotoxy(x+16,y+8);printf("##");
	gotoxy(x+3,y+8);printf("#####");
	///////////linha 10
	gotoxy(x-7,y+9);printf("#        #######        #");
	gotoxy(x+16,y+9);printf("##");
	gotoxy(x+2,y+9);printf("#######");
	///////////linha 11
	gotoxy(x-6,y+10);printf("##     #########     ##");
	gotoxy(x+15,y+10);printf("##");
	gotoxy(x+1,y+10);printf("#########");
	
	///////////linha 12
	gotoxy(x-4,y+11);printf("##               ##");
	gotoxy(x+13,y+11);printf("##");
	
	///////////linha 13
	gotoxy(x-2,y+12);printf("##           ##");
	gotoxy(x+11,y+12);printf("##");
	
	///////////linha 14
	gotoxy(x,y+13);printf("###########");
	
	
	
	
	/////////////////desenho//////////////////////////////////////////
	
	
	textcolor(12);
	textbackground(12);
	///////////linha 1
	gotoxy(x,y);printf("###########");
	
	///////////linha 2
	gotoxy(x-2,y+1);printf("##");
	gotoxy(x+11,y+1);printf("##");
	
	///////////linha 3
	gotoxy(x-4,y+2);printf("##");
	gotoxy(x+13,y+2);printf("##");
	///////////linha 4
	gotoxy(x-6,y+3);printf("##");
	gotoxy(x+15,y+3);printf("##");
	gotoxy(x+1,y+3);printf("#########");
	///////////linha 5
	gotoxy(x-7,y+4);printf("##");
	gotoxy(x+16,y+4);printf("##");
	gotoxy(x+2,y+4);printf("#######");
	///////////linha 6
	gotoxy(x-7,y+5);printf("##");
	gotoxy(x+16,y+5);printf("##");
	gotoxy(x+3,y+5);printf("#####");
	///////////linha 7
	gotoxy(x-7,y+6);printf("##");
	gotoxy(x+16,y+6);printf("##");
	gotoxy(x+4,y+6);printf("###");
	///////////linha 8
	gotoxy(x-7,y+7);printf("##");
	gotoxy(x+16,y+7);printf("##");
	gotoxy(x+4,y+7);printf("###");
	///////////linha 9
	gotoxy(x-7,y+8);printf("##");
	gotoxy(x+16,y+8);printf("##");
	gotoxy(x+3,y+8);printf("#####");
	///////////linha 10
	gotoxy(x-7,y+9);printf("##");
	gotoxy(x+16,y+9);printf("##");
	gotoxy(x+2,y+9);printf("#######");
	///////////linha 11
	gotoxy(x-6,y+10);printf("##");
	gotoxy(x+15,y+10);printf("##");
	gotoxy(x+1,y+10);printf("#########");
	
	///////////linha 12
	gotoxy(x-4,y+11);printf("##");
	gotoxy(x+13,y+11);printf("##");
	
	///////////linha 13
	gotoxy(x-2,y+12);printf("##");
	gotoxy(x+11,y+12);printf("##");
	
	///////////linha 14
	gotoxy(x,y+13);printf("###########");
}

//----------------------------------------------------------------------------------------------------------------------------------

void pesquisa()
{
	char c;
	int a=17;
	int sair;
	viuvanegra(20,13);
	viuvanegra(90,13);
	cursor(0);
	
	do
	{
		sair=1;
		textbackground(15);
		textcolor(9);
		textbackground(15);
		logo_nome(57,1);
		textbackground(11);
		gotoxy(2,2);printf("                                                    ");
		gotoxy(68,2);printf("                                                    ");
		gotoxy(2,39);printf("                                                                                                                      ");
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(2,i);printf(" ");
		}
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(119,i);printf(" ");
		}
		textbackground(15);
		for(int i=10; i<=27; i++)
		{
			textbackground(0);
			gotoxy(42,i);printf(" ");
		}
		for(int j=10; j<=27; j++)
		{
			textbackground(0);
			gotoxy(78,j);printf(" ");
		}
		for(int x=42; x<=78; x++)
		{
			textbackground(0);
			gotoxy(x,10);printf(" ");
		}
		for(int x=42; x<=78; x++)
		{
			textbackground(0);
			gotoxy(x,27);printf(" ");
		}
		textbackground(15);
		textcolor(12);
		gotoxy(49,14);printf("PESQUISA DE PERSONAGENS");
		textcolor(4);
		gotoxy(51,17);printf("Pesquisa Geral");
		           //135 é o caractere 'ç' e 198 é o caractere 'ã'
		gotoxy(51,19);printf("Pesquisa por c%cdigo",162);
		gotoxy(51,21);printf("Pesquisa por nome");
		gotoxy(51,23);printf("Voltar");
		gotoxy(49,a); printf("%c", 62);//62 é o caractere '>'
		c=getch();
		gotoxy(49,a); printf(" ");
	
		switch(c)//movimento das setas
		{
			case 72 : //seta para cima
				a-=2;
				if(a<17)
				{
					a=23;	
				}
				gotoxy(49,a); printf("%c", 62);
				break;
			case 80 : //seta para baixo
				a+=2;
				if(a>23)
				{
					a=17;
				}
				gotoxy(49,a); printf("%c", 62);
				break;
			case 13: //teclou enter
				if(a==17)
				{ 
					system("cls");
					filtro();
					system("cls");
					viuvanegra(20,13);
					viuvanegra(90,13);
				}
				else
				if(a==19)
				{
					system("cls");
					pesquisa_codigo();
					system("cls");
					viuvanegra(20,13);
					viuvanegra(90,13);
				}
				else
				if(a==21)
				{
					system("cls");
					pesquisa_nome(17);
					system("cls");
					viuvanegra(20,13);
					viuvanegra(90,13);
				}
				else
				if(a==23)
				{
					system("cls");
					sair=0;
				}
		}//final switch(c)
	}while(sair); //final do while
	return;
}

//----------------------------------------------------------------------------------------------------------------------------------

void lanterna_verde(int x, int y)
{
	textcolor(2);
	textbackground(2);
	
	///////////////////////// linha 1 //////////////////////////////////////////
	
	 gotoxy(x+2,y);printf("#########################");
	 
	 ///////////////////////// linha 2 //////////////////////////////////////////	 
	textbackground(15);
	gotoxy(x,y+1);printf("        ");
	textbackground(2);
	printf("#############");
	 
	 ///////////////////////// linha 3 ////////////////////////////////////////// 
	 textbackground(15);
	 gotoxy(x,y+2);printf("      ");
	  textbackground(2);
	 printf("###");
	  textbackground(15);
	 printf("           ");
	  textbackground(2);
	 printf("###");
	 ///////////////////////// linha 4 //////////////////////////////////////////
	 textbackground(15);
	 gotoxy(x,y+3);printf("     ");
	 textbackground(2);
	 printf("##");
	 textbackground(15);
	 printf("               ");
	 textbackground(2);
	 printf("##");
	 
	 ///////////////////////// linha 5 //////////////////////////////////////////	
	 textbackground(15);
	 gotoxy(x,y+4);printf("    ");
	 textbackground(2);
	 printf("##");
	 textbackground(15);
	 printf("                 ");
	 textbackground(2);
	 printf("##");
	 ///////////////////////// linha 6 //////////////////////////////////////////
	 textbackground(15);
 	 gotoxy(x,y+5);printf("   ");
 	 textbackground(2);
	 printf("##");
	 textbackground(15);
	 printf("                   ");
	 textbackground(2);
	 printf("##");
 	 
 	 ///////////////////////// linha 7 //////////////////////////////////////////
 	 textbackground(15);
 	 gotoxy(x,y+6);printf("  ");
 	 textbackground(2);
	 printf("##");
	 textbackground(15);
	 printf("                     ");
	 textbackground(2);
	 printf("##");
 	 
 	 ///////////////////////// linha 8 //////////////////////////////////////////
 	 textbackground(15);
   	 gotoxy(x,y+7);printf("  ");
 	 textbackground(2);
	 printf("##");
	 textbackground(15);
	 printf("                     ");
	 textbackground(2);
	 printf("##");
   	 
   	 ///////////////////////// linha 9 //////////////////////////////////////////
   	 textbackground(15);
 	 gotoxy(x,y+8);printf("  ");
 	 textbackground(2);
	 printf("##");
	 textbackground(15);
	 printf("                     ");
	 textbackground(2);
	 printf("##");
 	 
 	 ///////////////////////// linha 10 //////////////////////////////////////////
 	 textbackground(15);
	 gotoxy(x,y+9);printf("  ");
 	 textbackground(2);
	 printf("##");
	 textbackground(15);
	 printf("                     ");
	 textbackground(2);
	 printf("##");
	 
	 ///////////////////////// linha 11 //////////////////////////////////////////
 	 textbackground(15);
	 gotoxy(x,y+10);printf("  ");
 	 textbackground(2);
	 printf("##");
	 textbackground(15);
	 printf("                     ");
	 textbackground(2);
	 printf("##");
   	 
	 
	 ///////////////////////// linha 12 //////////////////////////////////////////
	 textbackground(15);
  	gotoxy(x,y+11);printf("   ");
 	 textbackground(2);
	 printf("##");
	 textbackground(15);
	 printf("                   ");
	 textbackground(2);
	 printf("##");
	
	///////////////////////// linha 13 //////////////////////////////////////////
	textbackground(15);
	gotoxy(x,y+12);printf("    ");
	 textbackground(2);
	 printf("##");
	 textbackground(15);
	 printf("                 ");
	 textbackground(2);
	 printf("##");
	
	///////////////////////// linha 14 //////////////////////////////////////////
	textbackground(15);
	gotoxy(x,y+13);printf("     ");
	 textbackground(2);
	 printf("##");
	 textbackground(15);
	 printf("               ");
	 textbackground(2);
	 printf("##");
	
	
	///////////////////////// linha 15//////////////////////////////////////////
	textbackground(15);
	gotoxy(x,y+14);printf("      ");
	  textbackground(2);
	 printf("###");
	  textbackground(15);
	 printf("           ");
	  textbackground(2);
	 printf("###");
	
	///////////////////////// linha 16 //////////////////////////////////////////
	textbackground(15);
	gotoxy(x,y+15);printf("        ");
	textbackground(2);
	printf("#############");
	
	///////////////////////// linha 17 //////////////////////////////////////////
	textbackground(2);
	gotoxy(x+2,y+16);printf("#########################");
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void mostra_dados();

//----------------------------------------------------------------------------------------------------------------------------------

void digita_dados_alterar(stpersonagens personagem_aux)
{
	fflush(stdin);	
	gotoxy(24,17);gets(personagem.nome);
	while (strlen(personagem.nome)>29)
	{
		if(strlen(personagem.nome)>29)
		{
			gotoxy(24,17);
			for(int i=0; i<=strlen(personagem.nome); i++)
				printf(" ");
			mostra_dados_aux(personagem_aux);
			gotoxy(22,25);printf ("Muitos caracteres (m%cximo 29). Redigite!",160);
			Sleep(1000);
			gotoxy(24,17);gets(personagem.nome);
			gotoxy(22,25); printf ("                                          ");
		}
	}

	gotoxy(33,18);personagem.lado=getche();
	do
		{
			 if (personagem.lado!='h'&&personagem.lado!='H'&&personagem.lado!='V'&&personagem.lado!='v'&& personagem.lado && personagem.lado!= '\r')
			 {
				gotoxy(22,25);printf ("Resposta inv%clida! Redigite!",160);
				Sleep(500);
				gotoxy(33,18); printf ("                                ");
		        gotoxy(22,25); printf ("                                ");
				gotoxy(33,18);personagem.lado=getche();
			 }
		} while (personagem.lado!='h'&&personagem.lado!='H'&&personagem.lado!='V'&&personagem.lado!='v' && personagem.lado!= '\r');
	fflush(stdin);
	gotoxy(25,19);gets(personagem.poder);
	while (strlen(personagem.poder)>29)
	{
		if(strlen(personagem.poder)>29)
		{
			gotoxy(25,19);
			for(int i=0; i<=strlen(personagem.poder); i++)
				printf(" ");
			mostra_dados_aux(personagem_aux);
			gotoxy(22,25);printf ("Muitos caracteres (m%cximo 29). Redigite!",160);
			gotoxy(24,17);printf("%s", personagem.nome);
			gotoxy(33,18);printf("%c",personagem.lado);
			gotoxy(25,19);gets(personagem.poder);
			gotoxy(22,25); printf ("                                          ");
		}
	}
	fflush(stdin);
	gotoxy(48,20);personagem.tipo_aparicao=getche();
	fflush(stdin);
	do
	{
		 if (personagem.tipo_aparicao!='a'&&personagem.tipo_aparicao!='A'&&personagem.tipo_aparicao!='f'&&personagem.tipo_aparicao!='F'&&personagem.tipo_aparicao!='q'&&personagem.tipo_aparicao!='Q' && personagem.tipo_aparicao!= '\r')
		 {
			  gotoxy(22,25);printf ("Resposta inv%clida! Redigite!",160);
			  Sleep(500);
			  gotoxy(48,20); printf ("                                ");
			  gotoxy(22,25); printf ("                                ");
			  gotoxy(48,20);personagem.tipo_aparicao=getche();
		 }
	} while (personagem.tipo_aparicao!='a'&&personagem.tipo_aparicao!='A'&&personagem.tipo_aparicao!='f'&&personagem.tipo_aparicao!='F'&&personagem.tipo_aparicao!='q'&&personagem.tipo_aparicao!='Q' && personagem.tipo_aparicao!= '\r');	
	gotoxy(36,21);gets(personagem.nome_aparicao);
	while (strlen(personagem.nome_aparicao)>29)
	{
		if(strlen(personagem.nome_aparicao)>29)
		{
			gotoxy(36,21);
			for(int i=0; i<=strlen(personagem.nome_aparicao); i++)
				printf(" ");
			mostra_dados_aux(personagem_aux);
			gotoxy(22,25);printf ("Muitos caracteres (m%cximo 29). Redigite!",160);
			gotoxy(24,17);printf("%s", personagem.nome);
			gotoxy(33,18);printf("%c",personagem.lado);
			gotoxy(25,19);printf("%s",personagem.poder);
			gotoxy(48,20);printf("%c",personagem.tipo_aparicao);
			gotoxy(36,21);gets(personagem.nome_aparicao);
			gotoxy(22,25); printf ("                                          ");
		}
	}
	validacao_vazia_alterar(personagem.nome_aparicao,36,21);
	gotoxy(23,22);gets(personagem.ano);
	valida_ano_alterar(personagem.ano);
}

//----------------------------------------------------------------------------------------------------------------------------------

void alterar()
{
	stpersonagens personagem_aux;
	int aux_codigo,F;
	long fposicao;
	char conf;
	char op;
	do
	{
		abrir_arquivo("rb+");
		textbackground(15);
		logo_nome(57,1);
		textbackground(11);
		gotoxy(2,2);printf("                                                    ");
		gotoxy(68,2);printf("                                                    ");
		gotoxy(2,39);printf("                                                                                                                      ");
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(2,i);printf(" ");
		}
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(119,i);printf(" ");
		}
		textbackground(15);
		cursor(1);
		textcolor(8);
		gotoxy(49,6);printf("ALTERA%c%cO DE PERSONAGENS",128,199);
		setlocale(LC_ALL,"C");
		textcolor(8);
		for(int i=48; i<=74; i++)
		{
			textcolor(8);
			gotoxy(i,5);printf("%c",196);
			gotoxy(i,7);printf("%c",196);
		}
		setlocale(LC_ALL,NULL);
		textcolor(8);
		gotoxy(33,9); printf("Digite o c¢digo a ser alterado (digite 0 para sair): ");
    	scanf("%d", &aux_codigo );
    	if (aux_codigo==0)
    		break;
    	F = 0;
    	do
    	{ 
			fread( &personagem,sizeof(personagem),1,fp);
			if ( personagem.codigo == aux_codigo && personagem.excluido=='n')//SOMENTE SE NÃO FOI EXCLUIDO	
			{
				cursor(1);
				for(int i=13; i<=29; i++)
				{
					textbackground(1);
					gotoxy(70,i);printf(" ");
				}
				for(int j=13; j<=29; j++)
				{
					textbackground(1);
					gotoxy(14,j);printf(" ");
				}
				for(int x=14; x<=70; x++)
				{
					textbackground(1);
					gotoxy(x,13);printf(" ");
				}
				for(int x=14; x<=70; x++)
				{
					textbackground(1);
					gotoxy(x,29);printf(" ");
				}
				lanterna_verde(80,13);
				textbackground(15);
		   		mostra_dados();
		   		personagem_aux = personagem;//salva os dados do registro atual numa estrutura aux
		   		digita_dados_alterar(personagem_aux);
		   		F = 1;
		   		fposicao = ftell(fp); //guarda a posição do registro atual do arquivouxiliar
				// ******> VERIFICA SE HOUVE ALTERAÇÃO EM CADA UM DOS CAMPOS
				if (personagem.nome[0] == '\x0')//checa se cada campo está vazio
				    strcpy(personagem.nome, personagem_aux.nome);
				if (personagem.lado == '\r')//checa se cada campo está vazio
					personagem.lado=personagem_aux.lado;				    
				if (personagem.poder[0] == '\x0')//checa se cada campo está vazio
				    strcpy(personagem.poder, personagem_aux.poder);
				if (personagem.tipo_aparicao == '\r')//checa se cada campo está vazio
				    personagem.tipo_aparicao=personagem_aux.tipo_aparicao;
				if (personagem.nome_aparicao[0] == '\x0')//checa se cada campo está vazio
				    strcpy(personagem.nome_aparicao, personagem_aux.nome_aparicao);
				if (personagem.ano[0] == '\x0')//checa se cada campo está vazio
				    strcpy(personagem.ano, personagem_aux.ano);
			   	gotoxy(25,24); printf("Confirma altera%c%co? (S/N): ",135,198);
			   	gotoxy(52,24); conf=getche();
			   	do
			   	{
			   		if(conf != 's' && conf != 'S' && conf != 'n' && conf != 'N')
			   		{
			   			gotoxy(25,25);printf("Inv%clido!",160);
				   		Sleep(1000);
				   		gotoxy(25,25);printf("           ");
						gotoxy(52,24);printf("           ");
						gotoxy(52,24); conf=getche();
					}
			   	}while( conf != 's' && conf != 'S' && conf != 'n' && conf != 'N' );
			   
			   	if( conf == 's' || conf == 'S' )
			   	{
			   		//posiciona o ponteiro do arquivo no registro alterado
					fseek (fp,fposicao-(sizeof(personagem)),SEEK_SET);//em stdio.h
					/* fposicao-(sizeof(agenda) significa:
					   >> fposicao: contem a posição onde começa o próximo registro.
					   >> sizeof(agenda): contem o tamanho total em bytes do registro.
					   >> A subtração (-) entre eles significa reposicionar o ponteiro no 
					      início do registro anterior que é onde se deseja alterar.
					*/
					//SEEK_SET indica o início do arquivo
					fwrite (&personagem,sizeof(personagem),1,fp);
					fflush (fp);
			   	}
			}
		} while ((!F) && (!feof(fp))); //enquanto F for diferente de 1 e não for o fim do arquivo
		if (F==0)
		{
			gotoxy(49,15);printf("C¢digo n%co encontrado",198);
			/*Sleep(1000);
			gotoxy(18,15);printf("                                   ");
			gotoxy(77,9);printf("  ");*/
			getch();
		}
		gotoxy(22,24);printf("Deseja alterar outro personagem <s ou n>? ");
		op=getche();
		do
	 	{
	 		if(op != 's' && op != 'S' && op != 'n' && op != 'N')
	 		{
	 			gotoxy(22,25);printf("Inv%clido!",160);
				Sleep(1000);
				gotoxy(67,24);printf("           ");
				gotoxy(67,24);op=getche();
			}
		}while( op != 's' && op != 'S' && op != 'n' && op != 'N' );
		if(op=='s'||op=='S')
		{
			system("cls");
		}
		else if(op=='n'||op=='N')
		{
			break;
		}
	}while(true);

}

//----------------------------------------------------------------------------------------------------------------------------------

void mulher_maravilha(int x, int y)
{
	textcolor(14);
	textbackground(12);
	gotoxy(x,y);printf("______________       /\\       _______________");
	gotoxy(x,y+1);printf("\\             -.    /  \\    .-              /");
	gotoxy(x,y+2);printf(" -._________    \\  /    \\  /    __________.- ");
	gotoxy(x,y+3);printf("  \\         -.   \\/      \\/   .-          /  ");
	gotoxy(x,y+4);printf("   -.________ \\      /\\      / _________.-   ");
	gotoxy(x,y+5);printf("    \\        -.\\    /  \\    /.-         /    ");
	gotoxy(x,y+6);printf("     -._____    \\  /    \\  /    ______.-     ");
	gotoxy(x,y+7);printf("            -.   \\/      \\/   .-             ");
	gotoxy(x,y+8);printf("              \\      /\\      /               ");
	gotoxy(x,y+9);printf("               \\    /  \\    /                ");
	gotoxy(x,y+10);printf("                \\  /    \\  /                 ");
	gotoxy(x,y+11);printf("                 \\/      \\/                  ");
}

//----------------------------------------------------------------------------------------------------------------------------------

void excluir()
{
	int aux_codigo,F;
	long fposicao;
	char conf;
	char excluir_outro;
	int ale;
	do
	{
		abrir_arquivo("rb+");
		textbackground(15);
		logo_nome(57,1);
		textbackground(11);
		gotoxy(2,2);printf("                                                    ");
		gotoxy(68,2);printf("                                                    ");
		gotoxy(2,39);printf("                                                                                                                      ");
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(2,i);printf(" ");
		}
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(119,i);printf(" ");
		}
		textbackground(15);
		cursor(1);
		textcolor(8);
		gotoxy(48,6);printf("EXCLUS%cO DE PERSONAGENS",199);
		setlocale(LC_ALL,"C");
		textcolor(8);
		for(int i=47; i<=71; i++)
		{
			textcolor(8);
			gotoxy(i,5);printf("%c",196);
			gotoxy(i,7);printf("%c",196);
		}
		setlocale(LC_ALL,NULL);
		textcolor(8);
		gotoxy(33,10); printf("Digite o c¢digo a ser exclu%cdo (digite 0 para encerrar): ",161);
		scanf("%d", &aux_codigo );
		fflush(stdin);
		    if (aux_codigo!=0)
		    {
				F = 0;
				rewind(fp);
			    do
			    {
					fread( &personagem,sizeof(personagem),1,fp);
					if ( personagem.codigo == aux_codigo && personagem.excluido == 'n')//|| personagem.excluido=='N') //SOMENTE SE NÃO FOI EXCLUIDO
					{
						for(int i=13; i<=29; i++)
						{
							textbackground(1);
							gotoxy(64,i);printf(" ");
						}
						for(int j=13; j<=29; j++)
						{
							textbackground(1);
							gotoxy(8,j);printf(" ");
						}
						for(int x=8; x<=64; x++)
						{
							textbackground(1);
							gotoxy(x,13);printf(" ");
						}
						for(int x=8; x<=64; x++)
						{
							textbackground(1);
							gotoxy(x,29);printf(" ");
						}
						textbackground(15);
						mulher_maravilha(68,16);
						textbackground(15);
						textcolor(8);
				   		F = 1;
				   		fposicao = ftell(fp); // guarda a posição do registro atual do arquivo
				   		mostra_dados_ex(); // um registro nunca pode ser excluído sem antes ser apresentado ao usuário
					   	gotoxy(21,24); printf("Confirma exclus%co? <s ou n>: ", 198);
						fflush(stdin);
						do 
					   	{
					    	gotoxy(51,24); conf = getche();
					   	} while( conf != 's' && conf != 'S' && conf != 'n' && conf != 'N' );
					   	if( conf == 's' || conf == 'S' )
					   	{
					   		//posiciona o ponteiro do arquivo no registro a ser excluido logicamente
							fseek (fp,fposicao-(sizeof(personagem)),SEEK_SET); //em stdio.h
							//SEEK_SET indica o início do arquivo
							personagem.excluido='s'; /*atribuição de 's' para o campo excluído para indicar 
								 que o registro foi excluído ou desativado (exclusão lógica) */
							if(fwrite (&personagem,sizeof(personagem),1,fp)==1)
							{
								fflush (fp);
								gotoxy(20,25);printf("Personagem exclu%cdo com sucesso!",161);
//								break;
							}
						}
		
					}
				} while ((!F) && (!feof(fp)));  	
			} // if (aux_codigo!=0)
			if (F==0 && aux_codigo!=0)
			{
				cursor(0);
				gotoxy(49,15);printf("C¢digo n%co encontrado", 198);
				getch();
//				system("cls");
//				break;
			}
	//		printf("%d",aux_codigo);
	//		getch();
			if(aux_codigo!=0)
			{
	//			printf("%d",aux_codigo);
	//			getch();
				gotoxy(16,26);printf("Deseja realizar outra exclus%co? (S/N): ", 198);
				gotoxy(56,26); excluir_outro = getche();
				while( excluir_outro != 's' && excluir_outro != 'S'&& excluir_outro != 'n' && excluir_outro != 'N' )
				{
					gotoxy(27,27);printf("Resposta inv%clida, digite novamente!",160);
					gotoxy(56,26);printf("  ");
					gotoxy(56,26);excluir_outro = getche();
				}
				if(excluir_outro=='n'||excluir_outro=='N')
					break;
				else if(excluir_outro=='s'||excluir_outro=='S')
				{
					system("cls");
				}
			}
			
	//		if(excluir_outro!='n'||excluir_outro!='N')
	//			ale=1;
	//		else
	//			ale=0;
	}while (aux_codigo!=0);
}

//----------------------------------------------------------------------------------------------------------------------------------

void sobre_nos()
{
	char op;
	logo_nome(57,1);
	for(int i=11; i<=30; i++)
	{
		textbackground(4);
		gotoxy(100,i);printf(" ");
	}
	for(int j=11; j<=30; j++)
	{
		textbackground(4);
		gotoxy(20,j);printf(" ");
	}
	for(int x=20; x<=100; x++)
	{
		textbackground(4);
		gotoxy(x,11);printf(" ");
	}
	for(int x=20; x<=100; x++)
	{
		textbackground(4);
		gotoxy(x,30);printf(" ");
	}
	textbackground(11);
	gotoxy(2,2);printf("                                                    ");
	gotoxy(68,2);printf("                                                    ");
	gotoxy(2,39);printf("                                                                                                                      ");
	for(int i=2; i<=39; i++)
	{
		textbackground(11);
		gotoxy(2,i);printf(" ");
	}
	for(int i=2; i<=39; i++)
	{
		textbackground(11);
		gotoxy(119,i);printf(" ");
	}
	textbackground(15);
	textcolor(4);
	gotoxy(55,13);printf("SOBRE N%cS",224);
	textcolor(6);
	gotoxy(26,16);printf("-> A Plataforma Multiverso %c um sistema de cadastro de personagens",130);
	gotoxy(26,17);printf("de filmes, quadrinhos e anima%c%ces de editoras de quadrinhos como",135,228);
	gotoxy(26,18);printf("Marvel e DC Comics.");
	gotoxy(26,19);printf("-> Criadores: ");
	gotoxy(29,20);printf("Luana Maravilha, tamb%cm conhecida como Luana Rodrigues (26).", 130);
	gotoxy(29,21);printf("Luis Aranha, tamb%cm conhecido como Luis Fernando de Oliveira (28).", 130);
	gotoxy(29,22);printf("Sofia Marvel, tamb%cm conhecida como Sofia Ferreira Conti (33).", 130);
	gotoxy(26,23);printf("-> Turma: 71B 2019.");
	gotoxy(26,24);printf("-> Parceiros: Super Ariane. (Orientadora Ariane Scarelli).");
	gotoxy(26,25);printf("-> Projeto realizado no CTI, Col%cgio Totalmente Imposs%cvel",130,214);
	gotoxy(26,26);printf(" (a n%co ser que voc%c tenha poderes).",198,136);
	gotoxy(26,28);printf("Aperte enter para voltar ao menu principal.");
	do
	{
		gotoxy(35,21);op=getch();
	}while(op!='\r');
}
//----------------------------------------------------------------------------------------------------------------------------------

void animasuperman1(int, int);
void animasuperman2(int, int);
void animasuperman3(int, int);
void limpar_superman1(int, int);
void limpar_superman2(int, int);
void limpar_superman3(int, int);

//----------------------------------------------------------------------------------------------------------------------------------

void animaflash1(int, int);
void animaflash2(int, int);
void animaflash3(int, int);
void animaflash4(int, int);
void limpar_flash1e3(int,int);
void limpar_flash2e4(int,int);

//----------------------------------------------------------------------------------------------------------------------------------

void vitoria(int x, int y, int fundo,int letra)
{
	textbackground(fundo);
	system("cls");
	textcolor(letra);
	   gotoxy(x,y);printf(" ____        ____    __    ______________    _________    _______    __          ___");
	 gotoxy(x,y+1);printf(" \\   \\      /   /   |  |  |_____    _____|  /         \\   | ___  \\  |  |        /   \\");
	 gotoxy(x,y+2);printf("  \\   \\    /   /    |  |        |  |        |    _    |   | |_/  |  |  |       /  ^  \\");
  	 gotoxy(x,y+3);printf("   \\   \\  /   /     |  |        |  |        |   / \\   |   |    __/  |  |      /  /_\\  \\");
	 gotoxy(x,y+4);printf("    \\   \\/   /      |  |        |  |        |   | |   |   | |\\ \\    |  |     /  _____  \\");
	 gotoxy(x,y+5);printf("     \\      /       |  |        |  |        |   \\_/   |   | | \\ \\   |  |    /  /     \\  \\");
	 gotoxy(x,y+6);printf("      \\    /        |  |        |  |        |         |   | |  \\ \\  |  |   /  /       \\  \\");
	 gotoxy(x,y+7);printf("       \\__/         |__|        |__|        \\_________/   |_|   \\_\\ |__|  /__/         \\__\\");
	 gotoxy(x,y-3);printf("                                                   __    ");
	 gotoxy(x,y-2);printf("                                                  /  /     ");
	gotoxy(x,y-1);printf("                                                 /__/   ");
}

//----------------------------------------------------------------------------------------------------------------------------------

void derrota(int x, int y,int fundo,int letra)
{	
	textbackground(fundo);
	system("cls");
	textcolor(letra);	
	   gotoxy(x,y);printf(" ______    ________   _______    _______     _________    ______________     ___");
	 gotoxy(x,y+1);printf(" |     \\   |  _____|  | ___  \\   | ___  \\   /         \\  |_____    _____|   /   \\");
	 gotoxy(x,y+2);printf(" |  _   \\  |  |___    | |_/  |   | |_/  |   |    _    |        |  |        /  ^  \\");
  	 gotoxy(x,y+3);printf(" | | \\  |  |  ___|    |    __/   |    __/   |   / \\   |        |  |       /  /_\\  \\");
	 gotoxy(x,y+4);printf(" | | |  |  |  |       | |\\ \\     | |\\ \\     |   | |   |        |  |      /  _____  \\");
	 gotoxy(x,y+5);printf(" | |_/  |  |  |       | | \\ \\    | | \\ \\    |   \\_/   |        |  |     /  /     \\  \\");
	 gotoxy(x,y+6);printf(" |      /  |  |_____  | |  \\ \\   | |  \\ \\   |         |        |  |    /  /       \\  \\");
	 gotoxy(x,y+7);printf(" |_____/   |_______|  |_|   \\_\\  |_|   \\_\\  \\_________/        |__|   /__/         \\__\\");
}

//----------------------------------------------------------------------------------------------------------------------------------

void limpar_nave(int x, int y)
{
	textcolor(15);
	gotoxy(x,y);printf("          ______");
	gotoxy(x,y+1);printf("       _.-      -._");
	gotoxy(x,y+2);printf("      /            \\");
	gotoxy(x,y+3);printf("     /              \\");
	gotoxy(x,y+4);printf("  _.--.____________.--._");
	gotoxy(x,y+5);printf(".-                      -.");
	gotoxy(x,y+6);printf(" -.                    .-");
	gotoxy(x,y+7);printf("   -.________________.-");
}

//----------------------------------------------------------------------------------------------------------------------------------

void limpar_explosao(int x, int y)
{
	textcolor(15);
	gotoxy(x,y);printf("         #      #    ");
	gotoxy(x,y+1);printf("   #     ##   # #  #");
	gotoxy(x,y+2);printf("    ##  #  ##    # #");
	gotoxy(x,y+3);printf("    ## #           #");
	gotoxy(x,y+4);printf("   #               #");
	gotoxy(x,y+5);printf(" #             #    # ");
	gotoxy(x,y+6);printf("#####    _#   # # ####");
	gotoxy(x,y+7);printf("     #   # # #   #     ");
	gotoxy(x,y+8);printf("      # #   #");
	gotoxy(x,y+9);printf("       #");	
}

//----------------------------------------------------------------------------------------------------------------------------------

void explosao_nave(int x, int y)
{
	textcolor(14);
	gotoxy(x,y);printf("         #      #    ");
	gotoxy(x,y+1);printf("   #     ##   # #  #");
	gotoxy(x,y+2);printf("    ##  #  ##    # #");
	gotoxy(x,y+3);printf("    ## #           #");
	gotoxy(x,y+4);printf("   #               #");
	gotoxy(x,y+5);printf(" #             #    # ");
	gotoxy(x,y+6);printf("#####    _#   # # ####");
	gotoxy(x,y+7);printf("     #   # # #   #     ");
	gotoxy(x,y+8);printf("      # #   #");
	gotoxy(x,y+9);printf("       #");
}

//----------------------------------------------------------------------------------------------------------------------------------

void foton (int x, int y)
{
	textcolor(14);
//	textbackground(14);
	gotoxy(x+1,y);printf("####");
	gotoxy(x,y+1);printf("######");
	gotoxy(x+1,y+2);printf("####");
}

//----------------------------------------------------------------------------------------------------------------------------------

void limpar_foton(int x, int y)
{
	textcolor(15);
	textbackground(15);
	gotoxy(x,y);printf(" ####");
	gotoxy(x,y+1);printf("######");
	gotoxy(x,y+2);printf(" ####");
}

//----------------------------------------------------------------------------------------------------------------------------------

void nave_espacial_1 (int x, int y)
{
	textcolor(0);
	gotoxy(x,y);printf("          ______");
	gotoxy(x,y+1);printf("       _.-      -._");
	gotoxy(x,y+2);printf("      /            \\");
	gotoxy(x,y+3);printf("     /              \\");
	gotoxy(x,y+4);printf("  _.--.____________.--._");
	gotoxy(x,y+5);printf(".-                      -.");
	gotoxy(x,y+6);printf(" -.                    .-");
	gotoxy(x,y+7);printf("   -.________________.-");
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void nave_espacial_2 (int x, int y)
{
	textcolor(0);
	  gotoxy(x,y);printf("          ______");
	gotoxy(x,y+1);printf("       _.-      -._");
	gotoxy(x,y+2);printf("      /            \\");
	gotoxy(x,y+3);printf("     /              \\");
	gotoxy(x,y+4);printf("  _.--.____________.--._");
	gotoxy(x,y+5);printf(".-                      -.");
	gotoxy(x,y+6);printf(" -.                    .-");
	gotoxy(x,y+7);printf("   -.________________.-");
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void nave_espacial_3 (int x, int y)
{
	textcolor(0);
	  gotoxy(x,y);printf("          ______");
	gotoxy(x,y+1);printf("       _.-      -._");
	gotoxy(x,y+2);printf("      /            \\");
	gotoxy(x,y+3);printf("     /              \\");
	gotoxy(x,y+4);printf("  _.--.____________.--._");
	gotoxy(x,y+5);printf(".-                      -.");
	gotoxy(x,y+6);printf(" -.                    .-");
	gotoxy(x,y+7);printf("   -.________________.-");
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void nave_espacial_4 (int x, int y)
{
	textcolor(0);
	  gotoxy(x,y);printf("          ______");
	gotoxy(x,y+1);printf("       _.-      -._");
	gotoxy(x,y+2);printf("      /            \\");
	gotoxy(x,y+3);printf("     /              \\");
	gotoxy(x,y+4);printf("  _.--.____________.--._");
	gotoxy(x,y+5);printf(".-                      -.");
	gotoxy(x,y+6);printf(" -.                    .-");
	gotoxy(x,y+7);printf("   -.________________.-");
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void limpar_capita (int x, int y)
{
		////////////////// linha 1
	textcolor(15);
	gotoxy(x,y);printf("      #");
	
	////////////////// linha 2
	gotoxy(x,y+1);printf("    ###");
	
	////////////////// linha 3
	gotoxy(x,y+2);printf("   ####");
//	textcolor(12);
	printf("  #");
	
	////////////////// linha 4
//	textcolor(14);
	gotoxy(x,y+3);printf("   #  #");
//	textcolor(9);
	printf(" #");
	
	////////////////// linha 5
//	textcolor(14);
	gotoxy(x,y+4);printf("    ##");
//	textcolor(9);
	printf(" #");
	
	////////////////// linha 6
//	textcolor(12);
	gotoxy(x,y+5);printf("   ####");
	
	////////////////// linha 7
//	textcolor(9);
	gotoxy(x,y+6);printf("  # ##");
	
	////////////////// linha 8
//	textcolor(9);
	gotoxy(x,y+7);printf(" #  ##");
	
	////////////////// linha 9
//	textcolor(12);
	gotoxy(x,y+8);printf("#   ##");
	
	////////////////// linha 10
//	textcolor(9);
	gotoxy(x,y+9);printf("   #  #");
	
	////////////////// linha 11
//	textcolor(9);
	gotoxy(x,y+10);printf("  #    #");
	
	////////////////// linha 12
//	textcolor(12);
	gotoxy(x,y+11);printf(" #      #");
	
}


void capita_marvel (int x, int y)
{
	////////////////// linha 1
	textcolor(14);
//	gotoxy(x,y);printf("      #");
	
	////////////////// linha 2
	gotoxy(x,y+1);printf("    ###");
	
	////////////////// linha 3
	gotoxy(x,y+2);printf("   ####");
	textcolor(12);
	printf("  #");
	
	////////////////// linha 4
	textcolor(14);
	gotoxy(x,y+3);printf("   #  #");
	textcolor(9);
	printf(" #");
	
	////////////////// linha 5
	textcolor(14);
	gotoxy(x,y+4);printf("    ##");
	textcolor(9);
	printf(" #");
	
	////////////////// linha 6
	textcolor(12);
	gotoxy(x,y+5);printf("   ####");
	
	////////////////// linha 7
	textcolor(9);
	gotoxy(x,y+6);printf("  # ##");
	
	////////////////// linha 8
	textcolor(9);
	gotoxy(x,y+7);printf(" #  ##");
	
	////////////////// linha 9
	textcolor(12);
	gotoxy(x,y+8);printf("#   ##");
	
	////////////////// linha 10
	textcolor(9);
	gotoxy(x,y+9);printf("   #  #");
	
	////////////////// linha 11
	textcolor(9);
	gotoxy(x,y+10);printf("  #    #");
	
	////////////////// linha 12
	textcolor(12);
	gotoxy(x,y+11);printf(" #      #");
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void limpar_fumaca(int x, int y)
{
	textcolor(15);
	gotoxy(x+1,y);printf("#");
	gotoxy(x,y+1);printf("#");
	gotoxy(x+2,y+2);printf("#");
}

//----------------------------------------------------------------------------------------------------------------------------------

void atirar(int x,int *des1,int *des2,int *des3,int *des4,int *ganhar)
{
	int y=18;
	for (y; y>9; y--)
	{
		foton(x+2,y);
		Sleep(200);
		limpar_foton(x+2,y);
	}
	limpar_nave(x-7,1);
	switch(x)
	{
		case 10:
			if(*des1==0)
			{
				explosao_nave(x-9,1);
				Sleep(500);
				limpar_explosao(x-9,1);
				limpar_fumaca(x+17,4);
			}
			*des1=1;
			break;
		case 40:
			if(*des2==0)
			{
				explosao_nave(x-9,1);
				Sleep(500);
				limpar_explosao(x-9,1);
				limpar_fumaca(x+17,4);
			}
			*des2=1;
			break;
		case 70:
			if(*des3==0)
			{
				explosao_nave(x-9,1);
				Sleep(500);
				limpar_explosao(x-9,1);
				limpar_fumaca(x+17,4);
			}
			*des3=1;
			break;
		case 100:
			if(*des4==0)
			{
				explosao_nave(x-9,1);
				Sleep(500);
				limpar_explosao(x-9,1);
				limpar_fumaca(x+17,4);
			}
			*des4=1;
			break;	
	}
	if(*des1==1&&*des2==1&&*des3==1&*des4==1)
		*ganhar=1;
}

//----------------------------------------------------------------------------------------------------------------------------------

void fumaca(int x, int y)
{
	textcolor(8);
	gotoxy(x+1,y);printf("#");
	gotoxy(x,y+1);printf("#");
	gotoxy(x+2,y+2);printf("#");
}

//----------------------------------------------------------------------------------------------------------------------------------

void jogo_capita_marvel()
{
	do
 	{
 		textbackground(15);
 		system("cls");
		cursor(0);
	 	/////////// destruido ou nao
	 	int des1=0;
	 	int des2=0;
	 	int des3=0;
	 	int des4=0;
	 	
	 	/////////// vai atirar ou nao
	 	
	 	int ati1=0;
	 	int ati2=0;
	 	int ati3=0;
	 	int ati4=0;
	 	
	 	////////////
	 	int qual=0;
	 	int muv=0;
	 	char a;
	 	char op;
	 	int x=10; int y=23;
	 	int ganhar=0;
	 	int perder=0;
	 	nave_espacial_1(3,1);
	 	nave_espacial_2(33,1);
	 	nave_espacial_3(63,1);
	 	nave_espacial_4(93,1);
	 	capita_marvel(x,y);
	 	srand(time(NULL));
	 	int F;
	 	do
	 	{
	 		F=1;
			qual=rand()%4+1;
			switch(qual)
			{
				case 1:
					if(des1==1)
						F=0;
					else
						fumaca(27,4);
					break;
				case 2:
					if(des2==1)
						F=0;
	 				else
	 					fumaca(57,4);
	 				break;
	 			case 3:
		 			if(des3==1)
		 				F=0;
					else
						fumaca(87,4);
					break;
				case 4:
					if(des4==1)
						F=0;
					else
						fumaca(117,4);
					break;
			}
		}while(F==0);
	 	do
	 	{
	 		a=getch();
	 		switch(a)
	 		{
	 			case 77:
	 				muv++;
					limpar_capita(x,y);
		 			x+=30;
		 			if (x>100)
		 				x=100;
		 			capita_marvel(x,y);
	 				if (muv%2==0)
	 				{
	 					int F;
	 					do
	 					{
	 						F=1;
		 					qual=rand()%4+1;
		 					switch(qual)
		 					{
		 						case 1:
		 							if(des1==1)
		 								F=0;
		 							else
		 								fumaca(27,4);
		 							break;
		 						case 2:
		 							if(des2==1)
		 								F=0;
		 							else
		 								fumaca(57,4);
		 							break;
		 						case 3:
		 							if(des3==1)
		 								F=0;
		 							else
		 								fumaca(87,4);
		 							break;
		 						case 4:
		 							if(des4==1)
		 								F=0;
		 							else
		 								fumaca(117,4);
		 							break;
							}
						}while(F==0);
					}
					else
					{
						switch(qual)
						{
							case 1:
								if(des1==0)
								{
								
									limpar_fumaca(27,4);
									textcolor(0);
									if(x==10)
									{
										textbackground(11);
										for(int i=9; i<23; i++)
										{
											gotoxy(15,i);printf(" ");
										}
										perder=1;
									}
									else
									{
										textbackground(11);
										for(int i=9; i<=35; i++)
										{
											gotoxy(15,i);printf(" ");
										}
										Sleep(500);
										textbackground(15);
										for(int i=9; i<=35; i++)
										{
											gotoxy(15,i);printf(" ");
										}
									}
									textbackground(15);
								}
								break;
							case 2:
								if(des2==0)
								{
									limpar_fumaca(57,4);
									textcolor(0);
									if(x==40)
									{
										textbackground(11);
										for(int i=9; i<23; i++)
										{									
											gotoxy(45,i);printf(" ");
										}
										perder=1;
									}
									else
									{
										textbackground(11);
										for(int i=9; i<=35; i++)
										{
											gotoxy(45,i);printf(" ");
										}
										Sleep(500);
										textbackground(15);
										for(int i=9; i<=35; i++)
										{
											gotoxy(45,i);printf(" ");
										}
									}
									textbackground(15);
								}
								break;
							case 3:
								if(des3==0)
								{
									limpar_fumaca(87,4);
									textcolor(0);
									if(x==70)
									{
										textbackground(11);
										for(int i=9; i<23; i++)
										{									
											gotoxy(75,i);printf(" ");
										}
										perder=1;
									}
									else
									{
										textbackground(11);
										for(int i=9; i<=35; i++)
										{
											gotoxy(75,i);printf(" ");
										}
										Sleep(500);
										textbackground(15);
										for(int i=9; i<=35; i++)
										{
											gotoxy(75,i);printf(" ");
										}
									}
									textbackground(15);
								}
								break;
							case 4:
								if(des4==0)
								{
									limpar_fumaca(117,4);
									textcolor(0);
									if(x==100)
									{
										textbackground(11);
										for(int i=9; i<23; i++)
										{									
											gotoxy(105,i);printf(" ");
										}
										perder=1;
									}
									else
									{
										textbackground(11);
										for(int i=9; i<=35; i++)
										{
											gotoxy(105,i);printf(" ");
										}
										Sleep(500);
										textbackground(15);
										for(int i=9; i<=35; i++)
										{
											gotoxy(105,i);printf(" ");
										}
									}
									textbackground(15);
								}
								break;
						}
					}
	 				break;
	 			case 75:
	 				muv++;
	 				limpar_capita(x,y);
	 				x-=30;
	 				if (x<10)
	 					x=10;
	 				capita_marvel(x,y);
	 				if (muv%2==0)
	 				{
	 					int F;
	 					do
	 					{
	 						F=1;
		 					qual=rand()%4+1;
		 					switch(qual)
		 					{
		 						case 1:
		 							if(des1==1)
		 								F=0;
		 							else
		 								fumaca(27,4);
		 							break;
		 						case 2:
		 							if(des2==1)
		 								F=0;
		 							else
		 								fumaca(57,4);
		 							break;
		 						case 3:
		 							if(des3==1)
		 								F=0;
		 							else
		 								fumaca(87,4);
		 							break;
		 						case 4:
		 							if(des4==1)
		 								F=0;
		 							else
		 								fumaca(117,4);
		 							break;
							}
						}while(F==0);
					}
					else
					{
						switch(qual)
						{
							case 1:
								if(des1==0)
								{
								
									limpar_fumaca(27,4);
									textcolor(0);
									if(x==10)
									{
										textbackground(11);
										for(int i=9; i<23; i++)
										{
											gotoxy(15,i);printf(" ");
										}
										perder=1;
									}
									else
									{
										textbackground(11);
										for(int i=9; i<=35; i++)
										{
											gotoxy(15,i);printf(" ");
										}
										Sleep(500);
										textbackground(15);
										for(int i=9; i<=35; i++)
										{
											gotoxy(15,i);printf(" ");
										}
									}
									textbackground(15);
								}
								break;
							case 2:
								if(des2==0)
								{
									limpar_fumaca(57,4);
									textcolor(0);
									if(x==40)
									{
										textbackground(11);
										for(int i=9; i<23; i++)
										{									
											gotoxy(45,i);printf(" ");
										}
										perder=1;
									}
									else
									{
										textbackground(11);
										for(int i=9; i<=35; i++)
										{
											gotoxy(45,i);printf(" ");
										}
										Sleep(500);
										textbackground(15);
										for(int i=9; i<=35; i++)
										{
											gotoxy(45,i);printf(" ");
										}
									}
									textbackground(15);
								}
								break;
							case 3:
								if(des3==0)
								{
									limpar_fumaca(87,4);
									textcolor(0);
									if(x==70)
									{
										textbackground(11);
										for(int i=9; i<23; i++)
										{									
											gotoxy(75,i);printf(" ");
										}
										perder=1;
									}
									else
									{
										textbackground(11);
										for(int i=9; i<=35; i++)
										{
											gotoxy(75,i);printf(" ");
										}
										Sleep(500);
										textbackground(15);
										for(int i=9; i<=35; i++)
										{
											gotoxy(75,i);printf(" ");
										}
									}
									textbackground(15);
								}
								break;
							case 4:
								if(des4==0)
								{
									limpar_fumaca(117,4);
									textcolor(0);
									if(x==100)
									{
										textbackground(11);
										for(int i=9; i<23; i++)
										{									
											gotoxy(105,i);printf(" ");
										}
										perder=1;
									}
									else
									{
										textbackground(11);
										for(int i=9; i<=35; i++)
										{
											gotoxy(105,i);printf(" ");
										}
										Sleep(500);
										textbackground(15);
										for(int i=9; i<=35; i++)
										{
											gotoxy(105,i);printf(" ");
										}
									}
									textbackground(15);
								}
								break;
						}
					}
	 				break;
	 			case 13:
	 				muv++;
	 				if(des1==1)
					{
						if(des2==1)
						{
							if(des3==1||des4==1)
							{
								atirar(x, &des1, &des2, &des3, &des4,&ganhar);	
							}
						}
						else
							if(des3==1&&des4==1)
							{
								atirar(x, &des1, &des2, &des3, &des4, &ganhar);
							}
					}
					else
						if(des2==1&&des3==1&&des4==1)
						{
							atirar(x, &des1, &des2, &des3, &des4,&ganhar);
						}
	 				if (muv%2==0)
	 				{
	 					int F;
	 					do
	 					{
	 						F=1;
		 					qual=rand()%4+1;
		 					switch(qual)
		 					{
		 						case 1:
		 							if(des1==1)
		 								F=0;
		 							else
		 								fumaca(27,4);
		 							break;
		 						case 2:
		 							if(des2==1)
		 								F=0;
		 							else
		 								fumaca(57,4);
		 							break;
		 						case 3:
		 							if(des3==1)
		 								F=0;
		 							else
		 								fumaca(87,4);
		 							break;
		 						case 4:
		 							if(des4==1)
		 								F=0;
		 							else
		 								fumaca(117,4);
		 							break;
							}
						}while(F==0);
					}
					else
					{
						switch(qual)
						{
							case 1:
								if(des1==0)
								{
								
									limpar_fumaca(27,4);
									textcolor(0);
									if(x==10)
									{
										textbackground(11);
										for(int i=9; i<23; i++)
										{
											gotoxy(15,i);printf(" ");
										}
										perder=1;
									}
									else
									{
										textbackground(11);
										for(int i=9; i<=35; i++)
										{
											gotoxy(15,i);printf(" ");
										}
										Sleep(500);
										textbackground(15);
										for(int i=9; i<=35; i++)
										{
											gotoxy(15,i);printf(" ");
										}
									}
									textbackground(15);
								}
								break;
							case 2:
								if(des2==0)
								{
									limpar_fumaca(57,4);
									textcolor(0);
									if(x==40)
									{
										textbackground(11);
										for(int i=9; i<23; i++)
										{									
											gotoxy(45,i);printf(" ");
										}
										perder=1;
									}
									else
									{
										textbackground(11);
										for(int i=9; i<=35; i++)
										{
											gotoxy(45,i);printf(" ");
										}
										Sleep(500);
										textbackground(15);
										for(int i=9; i<=35; i++)
										{
											gotoxy(45,i);printf(" ");
										}
									}
									textbackground(15);
								}
								break;
							case 3:
								if(des3==0)
								{
									limpar_fumaca(87,4);
									textcolor(0);
									if(x==70)
									{
										textbackground(11);
										for(int i=9; i<23; i++)
										{									
											gotoxy(75,i);printf(" ");
										}
										perder=1;
									}
									else
									{
										textbackground(11);
										for(int i=9; i<=35; i++)
										{
											gotoxy(75,i);printf(" ");
										}
										Sleep(500);
										textbackground(15);
										for(int i=9; i<=35; i++)
										{
											gotoxy(75,i);printf(" ");
										}
									}
									textbackground(15);
								}
								break;
							case 4:
								if(des4==0)
								{
									limpar_fumaca(117,4);
									textcolor(0);
									if(x==100)
									{
										textbackground(11);
										for(int i=9; i<23; i++)
										{									
											gotoxy(105,i);printf(" ");
										}
										perder=1;
									}
									else
									{
										textbackground(11);
										for(int i=9; i<=35; i++)
										{
											gotoxy(105,i);printf(" ");
										}
										Sleep(500);
										textbackground(15);
										for(int i=9; i<=35; i++)
										{
											gotoxy(105,i);printf(" ");
										}
									}
									textbackground(15);
								}
								break;
						}
					}
					if(perder==0&&ganhar==0)
					{
	 					atirar(x, &des1, &des2, &des3, &des4,&ganhar);
	 				}
	 				break;
	 			default:
	 				break;
			}
		}while(perder==0&&ganhar==0);
		if (ganhar==1)
		{
			vitoria(3,10,1,12);
			textcolor(11);
			gotoxy(10,30);printf("Deseja jogar novamente(S/N)? ");
			cursor(1);
			do
			{
				gotoxy(39,30);op=getche();
				gotoxy(10,33);printf("                           ");
			if(op!='s'&& op!='S'&& op!='n'&& op!='N')
				{
					gotoxy(10,33);printf("Resposta invalida, redigite");
					gotoxy(39,30);printf(" ");
				}
			}while(op!='s'&& op!='S'&& op!='n'&& op!='N');
			if (op=='n'|| op== 'N')
				return;
		}
		if (perder==1)
		{
			derrota(3,10,1,12);
			textcolor(11);
			gotoxy(10,30);printf("Deseja jogar novamente(S/N)? ");
			cursor(1);
			do
			{
				gotoxy(39,30);op=getche();
				gotoxy(10,33);printf("                           ");
				if(op!='s'&& op!='S'&& op!='n'&& op!='N')
				{
					gotoxy(10,33);printf("Resposta invalida, redigite");
					gotoxy(39,30);printf(" ");
				}
			}while(op!='s'&& op!='S'&& op!='n'&& op!='N');
			if (op=='n'|| op== 'N')
				return;
		}
	}while(true);
}

//----------------------------------------------------------------------------------------------------------------------------------

void instrucao_capita_mavel()
{
	char e;
	textbackground(15);
	textcolor(1);
	system("cls");
	cursor(0);
	gotoxy(20,10); printf("Instru%c%ces",135,228);
	textcolor(12);
	gotoxy(20,12); printf("Destrua todas as naves para vencer");
	gotoxy(20,13); printf("Use < > para mover a Capit%c Marvel",198);
	gotoxy(20,14); printf("Aperte enter para atirar nas naves");
	gotoxy(20,15); printf("Se a nave estiver soltando fuma%ca quer dizer que ela est%c prestes a atirar",135,160);
	gotoxy(20,16); printf("Se uma nave te atingir voc%c perde",136);
	gotoxy(20,17); printf("Dica: voc%c s%c conseguir%c atirar antes da nave quando estiver faltando uma",136,162,160);
	textcolor(4);
	gotoxy(20,21); printf("Aperte enter para continuar e esc para escolher outro jogo");
	do
	{
		e=getch();
		switch(e)
		{
			case 13:
				jogo_capita_marvel();
				break;
			case 27:
				return;
				break;
			default:
				break;
		}
	}while(e!=13);
}

//----------------------------------------------------------------------------------------------------------------------------------

void oraculo(int x, int y)
{
	///////////////////// linha 1
	
	textcolor(12);
	gotoxy(x,y);printf("  ####");
	///////////////////// linha 2
	
	textcolor(12);
	gotoxy(x,y+1);printf(" ##");
	textcolor(8);
	printf("##");
	textcolor(12);
	printf("##");
	///////////////////// linha 3
	
	textcolor(12);
	gotoxy(x,y+2);printf(" #");
	textcolor(8);
	printf("#  #");
	textcolor(12);
	printf("#");
	textcolor(8);
	printf(" #");
	///////////////////// linha 4
	
	textcolor(12);
	gotoxy(x,y+3);printf(" ##");
	textcolor(8);
	printf("##");
	textcolor(12);
	printf("##");
	textcolor(8);
	printf("#");
	///////////////////// linha 5
	
	textcolor(12);
	gotoxy(x,y+4);printf(" #");
	textcolor(8);
	printf("#####");
	///////////////////// linha 6
	
	textcolor(8);
	gotoxy(x,y+5);printf(" #");
	textcolor(12);
	printf("#");
	textcolor(8);
	printf("##");
	textcolor(12);
	printf("##");
	///////////////////// linha 7
	
	textcolor(8);
	gotoxy(x,y+6);printf("#  ##");
}

//----------------------------------------------------------------------------------------------------------------------------------

void batwoman(int x, int y)
{
	///////////////////// linha 1
	
	textcolor(0);
	gotoxy(x,y);printf("  #   #");
	///////////////////// linha 2
	
	textcolor(0);
	gotoxy(x,y+1);printf("  ## ##");

	///////////////////// linha 3
	
	textcolor(0);
	gotoxy(x,y+2);printf("  #");
	textcolor(12);
	printf("###");
	textcolor(0);
	printf("#");
	///////////////////// linha 4
	
	textcolor(12);
	gotoxy(x,y+3);printf(" #######");
	///////////////////// linha 5
	
	textcolor(12);
	gotoxy(x,y+4);printf("#########");
	///////////////////// linha 6
	
	textcolor(12);
	gotoxy(x,y+5);printf(" #######");

	///////////////////// linha 7
	
	textcolor(12);
	gotoxy(x,y+6);printf(" #######");
	///////////////////// linha 8
	
	textcolor(8);
	gotoxy(x,y+7);printf(" #");
	textcolor(12);
	printf("#####");
	textcolor(8);
	printf("#");
	///////////////////// linha 9
	
	textcolor(8);
	gotoxy(x,y+8);printf(" ##");
	textcolor(12);
	printf("###");
	textcolor(8);
	printf("##");
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void quadrado()
{
	textbackground(0);
	gotoxy(1,1);
	printf("                ");
	gotoxy(1,2);
	printf("                ");
	gotoxy(1,3);
	printf("                ");
	gotoxy(1,4);
	printf("                ");
	gotoxy(1,5);
	printf("                ");
	gotoxy(1,6);
	printf("                ");
	gotoxy(1,7);
	printf("                ");
	gotoxy(1,8);
	printf("                ");
	gotoxy(1,9);
	printf("                ");
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void falas()
{
	cursor(0);
	fflush(stdin);
	char a;
	textbackground(15);
	textcolor(0);
	gotoxy(18,4);printf("Ei, Batwoman, parece que tem uma interfer%cncia na conex%co.",136,198);
	gotoxy(18,30);printf("Aperte enter para continuar e esc para pular");
	a=getch();
	while (a!=13&&a!=27)
	{
		a=getch();
	}
	gotoxy(18,4);printf("                                                                     ");
	if(a==27)
	{
		gotoxy(18,30);printf("                                            ");
		return;
	}
	gotoxy(18,4);printf("Eu n%co consigo te escutar, mesmo que voc%c consiga me ouvir.",198,136);
	a=getch();
	while (a!=13&&a!=27)
	{
		a=getch();
	}
	gotoxy(18,4);printf("                                                                     ");
	if(a==27)
	{
		gotoxy(18,30);printf("                                            ");
		return;
	}
	gotoxy(18,3);printf("Na sua frente tem uma bomba que possuem fios para serem cortados,");
	gotoxy(18,4);printf("falarei as cores e voc%c segue a sequ%cncia.",136,136);
	a=getch();
	while (a!=13&&a!=27)
	{
		a=getch();
	}
	gotoxy(18,3);printf("                                                                                              ");
	gotoxy(18,4);printf("                                                                                              ");
	gotoxy(18,30);printf("                                            ");
}

//----------------------------------------------------------------------------------------------------------------------------------

void fio_cor(int x, int y, int cor)
{
	textbackground(cor);
	for (y; y<24; y++)
	{
		gotoxy(x,y);printf(" ");
	}
}

//----------------------------------------------------------------------------------------------------------------------------------

void bombinha(int x, int y)
{
	textbackground(0);
	textcolor(0);
	///////////////////// linha 1
//	gotoxy(x-14,y-4);printf("####");
//	gotoxy(x-8,y-4);printf("####");
	gotoxy(x-2,y-4);printf("####");
	gotoxy(x+4,y-4);printf("####");
	gotoxy(x+10,y-4);printf("####");
	gotoxy(x+16,y-4);printf("####");
	gotoxy(x+22,y-4);printf("####");
//	gotoxy(x+28,y-4);printf("####");
//	gotoxy(x+34,y-4);printf("####");
	
	///////////////////// linha 2
	textbackground(15);
	textcolor(15);
	gotoxy(x-14,y-3);printf("#");
	textbackground(15);
	textcolor(15);
	printf("####");
	textbackground(15);
	textcolor(15);
	printf("##");
	textbackground(15);
	textcolor(15);
	printf("####");
	textbackground(0);
	textcolor(0);
	printf("#");
	textbackground(12);
	textcolor(12);
	printf("####");
	textbackground(0);
	textcolor(0);
	printf("##");
	textbackground(12);
	textcolor(12);
	printf("####");
	textbackground(0);
	textcolor(0);
	printf("##");
	textbackground(12);
	textcolor(12);
	printf("####");
	textbackground(0);
	textcolor(0);
	printf("##");
	textbackground(12);
	textcolor(12);
	printf("####");
	textbackground(0);
	textcolor(0);
	printf("##");
	textbackground(12);
	textcolor(12);
	printf("####");
	textbackground(0);
	textcolor(0);
	printf("#");
//	textbackground(12);
//	textcolor(12);
//	printf("####");
//	textbackground(0);
//	textcolor(0);
//	printf("##");
//	textbackground(12);
//	textcolor(12);
//	printf("####");
//	textbackground(0);
//	textcolor(0);
//	printf("#");
	
	///////////////////// penúltima linha
	textbackground(15);
	textcolor(15);
	gotoxy(x-14,25);printf("#");
	textbackground(15);
	textcolor(15);
	printf("####");
	textbackground(15);
	textcolor(15);
	printf("##");
	textbackground(15);
	textcolor(15);
	printf("####");
	textbackground(0);
	textcolor(0);
	printf("#");
	textbackground(12);
	textcolor(12);
	printf("####");
	textbackground(0);
	textcolor(0);
	printf("##");
	textbackground(12);
	textcolor(12);
	printf("####");
	textbackground(0);
	textcolor(0);
	printf("##");
	textbackground(12);
	textcolor(12);
	printf("####");
	textbackground(0);
	textcolor(0);
	printf("##");
	textbackground(12);
	textcolor(12);
	printf("####");
	textbackground(0);
	textcolor(0);
	printf("##");
	textbackground(12);
	textcolor(12);
	printf("####");
	textbackground(0);
	textcolor(0);
	printf("#");
	
	///////////////////// última linha
	textbackground(0);
	textcolor(0);
	///////////////////// linha 1
//	gotoxy(x-14,y-4);printf("####");
//	gotoxy(x-8,y-4);printf("####");
	gotoxy(x-2,26);printf("####");
	gotoxy(x+4,26);printf("####");
	gotoxy(x+10,26);printf("####");
	gotoxy(x+16,26);printf("####");
	gotoxy(x+22,26);printf("####");
//	gotoxy(x+28,y-4);printf("####");
//	gotoxy(x+34,y-4);printf("####");
}

//----------------------------------------------------------------------------------------------------------------------------------

void bomba(int x, int y)
{
	int aux=y;
	textbackground(8);
	for(y; y<27; y++)
	{
		gotoxy(x-3,y-2);printf("                              ");
	}
	y=aux;
	textbackground(15);
	fio_cor(x,y,0);
	fio_cor(x+3,y,4);
	fio_cor(x+6,y,11);
	fio_cor(x+9,y,5);
	fio_cor(x+12,y,2);
	fio_cor(x+15,y,12);
	fio_cor(x+18,y,9);
	fio_cor(x+21,y,14);
	fio_cor(x+24,y,13);
	bombinha(x,y+1);
	textbackground(15);
}

//----------------------------------------------------------------------------------------------------------------------------------

int qual_falar(int cor,int confusa)
{
	switch(cor)  //0 2 4 5 9 11 12 13 14
	{
		case 0 ... 1:
			do
			{
				confusa=rand()%13;
			}while(confusa==7);
			textcolor(confusa);
			printf("Preto ");
			cor=0;
			break;
		case 2 ... 3:
			do
			{
				confusa=rand()%13;
			}while(confusa==7);
			textcolor(confusa);
			printf("Verde ");
			cor=2;
			break;
		case 4:  //7
			do
			{
				confusa=rand()%13;
			}while(confusa==7);
			textcolor(confusa);
			printf("Marrom ");
			cor=4;
			break;
		case 5 ... 6: 
			do
			{
				confusa=rand()%13;
			}while(confusa==7);
			textcolor(confusa);
			printf("Roxo ");
			cor=5;
			break;
		case 7:
			do
			{
				confusa=rand()%13;
			}while(confusa==7);
			textcolor(confusa);
			printf("Marrom ");
			cor=4;
			break;
		case 8 ... 9: 
			do
			{
				confusa=rand()%13;
			}while(confusa==7);
			textcolor(confusa);
			printf("Azul escuro ");
			cor=9;
			break;
		case 10 ... 11:
			do
			{
				confusa=rand()%13;
			}while(confusa==7);
			textcolor(confusa);
			printf("Azul claro ");
			cor=11;
			break;
		case 12:
			do
			{
				confusa=rand()%13;
			}while(confusa==7);
			textcolor(confusa);
			printf("Vermelho ");
			cor=12;
			break;
		case 13:
			do
			{
				confusa=rand()%13;
			}while(confusa==7);
			textcolor(confusa);
			printf("Rosa ");
			cor=13;
			break;
		case 14 ... 15:
			do
			{
				confusa=rand()%13;
			}while(confusa==7);
			textcolor(confusa);
			printf("Amarelo ");
			cor=14;
			break;
	}
	return cor;
}

//----------------------------------------------------------------------------------------------------------------------------------

void fala_cores(int vezes, int *cor1, int *cor2, int *cor3, int *cor4, int *cor5, int *cor6, int *cor7)
{
	srand(time(NULL));
	textbackground(15);
	int confusa;
	gotoxy(18,4);
	*cor1=qual_falar(*cor1, confusa);
	if(vezes>=2)
	{
		*cor2=qual_falar(*cor2, confusa);
		while(*cor2==*cor1)
		{
			gotoxy(18,4);printf("                                                                                             ");
			gotoxy(18,4);
			*cor1=qual_falar(*cor1, confusa);
			*cor2=qual_falar(*cor2, confusa);
			*cor2=rand()%16;
			gotoxy(18,4);printf("                                                                                             ");
			gotoxy(18,4);
			*cor1=qual_falar(*cor1, confusa);
			*cor2=qual_falar(*cor2, confusa);
		}
	}
	if(vezes>=3)
	{
		*cor3=qual_falar(*cor3, confusa);
		while(*cor3==*cor1||*cor3==*cor2)
		{
			gotoxy(18,4);printf("                                                                                             ");
			gotoxy(18,4);
			*cor1=qual_falar(*cor1, confusa);
			*cor2=qual_falar(*cor2, confusa);
			*cor3=qual_falar(*cor3, confusa);
			*cor3=rand()%16;
			gotoxy(18,4);printf("                                                                                             ");
			gotoxy(18,4);
			*cor1=qual_falar(*cor1, confusa);
			*cor2=qual_falar(*cor2, confusa);
			*cor3=qual_falar(*cor3, confusa);
		}
		
	}
	if(vezes>=4)
	{
		*cor4=qual_falar(*cor4, confusa);
		while(*cor4==*cor1||*cor4==*cor2||*cor4==*cor3)
		{
			gotoxy(18,4);printf("                                                                                             ");
			gotoxy(18,4);
			*cor1=qual_falar(*cor1, confusa);
			*cor2=qual_falar(*cor2, confusa);
			*cor3=qual_falar(*cor3, confusa);
			*cor4=qual_falar(*cor4, confusa);
			*cor4=rand()%16;
			gotoxy(18,4);printf("                                                                                             ");
			gotoxy(18,4);
			*cor1=qual_falar(*cor1, confusa);
			*cor2=qual_falar(*cor2, confusa);
			*cor3=qual_falar(*cor3, confusa);
			*cor4=qual_falar(*cor4, confusa);
		}
	}
	if(vezes>=5)
	{
		*cor5=qual_falar(*cor5, confusa);
		while(*cor5==*cor1||*cor5==*cor2||*cor5==*cor3||*cor5==*cor4)
		{
			gotoxy(18,4);printf("                                                                                             ");
			gotoxy(18,4);
			*cor1=qual_falar(*cor1, confusa);
			*cor2=qual_falar(*cor2, confusa);
			*cor3=qual_falar(*cor3, confusa);
			*cor4=qual_falar(*cor4, confusa);
			*cor5=qual_falar(*cor5, confusa);
			*cor5=rand()%16;
			gotoxy(18,4);printf("                                                                                             ");
			gotoxy(18,4);
			*cor1=qual_falar(*cor1, confusa);
			*cor2=qual_falar(*cor2, confusa);
			*cor3=qual_falar(*cor3, confusa);
			*cor4=qual_falar(*cor4, confusa);
			*cor5=qual_falar(*cor5, confusa);
		}
	}
	if(vezes>=6)
	{
		*cor6=qual_falar(*cor6, confusa);
		while(*cor6==*cor1||*cor6==*cor2||*cor6==*cor3||*cor6==*cor4||*cor6==*cor5)
		{
			gotoxy(18,4);printf("                                                                                             ");
			gotoxy(18,4);
			*cor1=qual_falar(*cor1, confusa);
			*cor2=qual_falar(*cor2, confusa);
			*cor3=qual_falar(*cor3, confusa);
			*cor4=qual_falar(*cor4, confusa);
			*cor5=qual_falar(*cor5, confusa);
			*cor6=qual_falar(*cor6, confusa);
			*cor6=rand()%16;
			gotoxy(18,4);printf("                                                                                             ");
			gotoxy(18,4);
			*cor1=qual_falar(*cor1, confusa);
			*cor2=qual_falar(*cor2, confusa);
			*cor3=qual_falar(*cor3, confusa);
			*cor4=qual_falar(*cor4, confusa);
			*cor5=qual_falar(*cor5, confusa);
			*cor6=qual_falar(*cor6, confusa);
		}
	}
	if(vezes>=7)
	{
		*cor7=qual_falar(*cor7, confusa);
		while(*cor7==*cor1||*cor7==*cor2||*cor7==*cor3||*cor7==*cor4||*cor7==*cor5||*cor7==*cor6)
		{
			gotoxy(18,4);printf("                                                                                             ");
			gotoxy(18,4);
			*cor1=qual_falar(*cor1, confusa);
			*cor2=qual_falar(*cor2, confusa);
			*cor3=qual_falar(*cor3, confusa);
			*cor4=qual_falar(*cor4, confusa);
			*cor5=qual_falar(*cor5, confusa);
			*cor6=qual_falar(*cor6, confusa);
			*cor7=qual_falar(*cor7, confusa);
			*cor7=rand()%16;
			gotoxy(18,4);printf("                                                                                             ");
			gotoxy(18,4);
			*cor1=qual_falar(*cor1, confusa);
			*cor2=qual_falar(*cor2, confusa);
			*cor3=qual_falar(*cor3, confusa);
			*cor4=qual_falar(*cor4, confusa);
			*cor5=qual_falar(*cor5, confusa);
			*cor6=qual_falar(*cor6, confusa);
			*cor7=qual_falar(*cor7, confusa);
		}
	}
	Sleep(4000);
	textbackground(15);
	gotoxy(18,4);printf("                                                                                             ");
}

//----------------------------------------------------------------------------------------------------------------------------------

void Cursor(int x, int y)
{
	setlocale(LC_ALL,"C");
	gotoxy(x,y);printf("%c",94);  //94
	setlocale(LC_ALL,NULL);
}

//----------------------------------------------------------------------------------------------------------------------------------

int checar(int VouF, int cor, int x)
{
	int cor_sel;
	switch(x)    //0 2 4 5 9 11 12 13 14
	{
		case 53:
			cor_sel=0;
			break;
		case 56:
			cor_sel=4;
			break;
		case 59:
			cor_sel=11;
			break;
		case 62:
			cor_sel=5;
			break;
		case 65:
			cor_sel=2;
			break;
		case 68:
			cor_sel=12;
			break;
		case 71:
			cor_sel=9;
			break;
		case 74:
			cor_sel=14;
			break;
		case 77:
			cor_sel=13;
			break;
	}
	if(cor==cor_sel)
	{
		VouF=1;
	}
	else
		VouF=0;
	return VouF;
}

//----------------------------------------------------------------------------------------------------------------------------------

void jogo_batwoman()
{
	do
	{
		textbackground(15);
		system("cls");
		char op;
		int ganhar=0;
		int perder=0;
		int VouF=3;
		int x=53;
		int y=24;
		char a;
		srand(time(NULL));
		int cor1=rand()%16;
		int cor2=rand()%16;
		int cor3=rand()%16;
		int cor4=rand()%16;
		int cor5=rand()%16;
		int cor6=rand()%16;
		int cor7=rand()%16;
		batwoman(80,27);
		quadrado();
		oraculo(4,3);
		bomba(53,9);
		falas();
		////////////////////// jogo ////////////////////////////////////
		do
		{
			fala_cores(1,&cor1, &cor2, &cor3, &cor4, &cor5, &cor6, &cor7);
			//gotoxy(30,1);printf("%d %d %d %d %d %d %d",cor1, cor2, cor3, cor4, cor5, cor6, cor7);
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor1, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			
			/////////////////////  duas cores ///////////////
			if(VouF==0)
			{
				perder=1;
				break;
			}
			fala_cores(2,&cor1, &cor2, &cor3, &cor4, &cor5, &cor6, &cor7);
			//gotoxy(30,1);printf("%d %d %d %d %d %d %d",cor1, cor2, cor3, cor4, cor5, cor6, cor7);
			x=53;
			y=24;
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor1, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor2, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			/////////////////////  tres cores ///////////////
			if(VouF==0)
			{
				perder=1;
				break;
			}
			fala_cores(3,&cor1, &cor2, &cor3, &cor4, &cor5, &cor6, &cor7);
			//gotoxy(30,1);printf("%d %d %d %d %d %d %d",cor1, cor2, cor3, cor4, cor5, cor6, cor7);
			x=53;
			y=24;
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor1, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor2, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor3, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			/////////////////////  quatro cores ///////////////
			if(VouF==0)
			{
				perder=1;
				break;
			}
			fala_cores(4,&cor1, &cor2, &cor3, &cor4, &cor5, &cor6, &cor7);
			//gotoxy(30,1);printf("%d %d %d %d %d %d %d",cor1, cor2, cor3, cor4, cor5, cor6, cor7);
			x=53;
			y=24;
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor1, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor2, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor3, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor4, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			/////////////////////  cinco cores ///////////////
			if(VouF==0)
			{
				perder=1;
				break;
			}
			fala_cores(5,&cor1, &cor2, &cor3, &cor4, &cor5, &cor6, &cor7);
			//gotoxy(30,1);printf("%d %d %d %d %d %d %d",cor1, cor2, cor3, cor4, cor5, cor6, cor7);
			x=53;
			y=24;
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor1, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor2, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor3, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor4, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor5, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			/////////////////////  seis cores ///////////////
			if(VouF==0)
			{
				perder=1;
				break;
			}
			fala_cores(6,&cor1, &cor2, &cor3, &cor4, &cor5, &cor6, &cor7);
			//gotoxy(30,1);printf("%d %d %d %d %d %d %d",cor1, cor2, cor3, cor4, cor5, cor6, cor7);
			x=53;
			y=24;
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor1, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor2, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor3, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor4, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor5, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor6, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			/////////////////////  sete cores ///////////////
			fala_cores(7,&cor1, &cor2, &cor3, &cor4, &cor5, &cor6, &cor7);
			//gotoxy(30,1);printf("%d %d %d %d %d %d %d",cor1, cor2, cor3, cor4, cor5, cor6, cor7);
			x=53;
			y=24;
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor1, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor2, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor3, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor4, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor5, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor6, x);
				}
				if(VouF==0)
				{
					perder=1;
					break;
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			textbackground(8);
			textcolor(0);
			Cursor(x,y);
			do
			{
				if(VouF==0)
				{
					perder=1;
					break;
				}
				do
				{
					a=getch();
				}while(a!=77&&a!=75&&a!=13);
				gotoxy(x,y);printf(" ");
				switch(a)
				{
					case 77:
						x+=3;
						if (x>77)
							x=77;
						Cursor(x,y);
						break;
					case 75:
						x-=3;
						if (x<53)
							x=53;
						Cursor(x,y);
						break;
					default:
						printf("\a");
						VouF=checar(VouF, cor7, x);
				}
			}while(a!=13);
			if(VouF==0)
			{
				perder=1;
				break;
			}
			if(VouF==1)
			{
				
				ganhar=1;
				break;
			}
			if(VouF==0)
			{
				perder=1;
				break;
			}
			if(VouF==1)
			{
			
				ganhar=1;
				break;
			}
		}while(true);
		if (ganhar==1)
		{
			vitoria(3,10,0,7);
			textcolor(14);
			gotoxy(10,30);printf("Deseja jogar novamente(S/N)? ");
			cursor(1);
			do
			{
				gotoxy(39,30);op=getche();
				gotoxy(10,33);printf("                           ");
			if(op!='s'&& op!='S'&& op!='n'&& op!='N')
				{
					gotoxy(10,33);printf("Resposta invalida, redigite");
					gotoxy(39,30);printf(" ");
				}
			}while(op!='s'&& op!='S'&& op!='n'&& op!='N');
			if (op=='n'|| op== 'N')
				return;
		}
		if (perder==1)
		{
			derrota(3,10,0,7);
			textcolor(14);
			gotoxy(10,30);printf("Deseja jogar novamente(S/N)? ");
			cursor(1);
			do
			{
				gotoxy(39,30);op=getche();
				gotoxy(10,33);printf("                           ");
				if(op!='s'&& op!='S'&& op!='n'&& op!='N')
				{
					gotoxy(10,33);printf("Resposta invalida, redigite");
					gotoxy(39,30);printf(" ");
				}
			}while(op!='s'&& op!='S'&& op!='n'&& op!='N');
			if (op=='n'|| op== 'N')
				return;
		}
	}while(true);
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void instrucao_batwoman()
{
	char e;
	textbackground(15);
	textcolor(6);
	system("cls");
	cursor(0);
	gotoxy(20,10); printf("Instru%c%ces",135,228);
	textcolor(0);
	gotoxy(20,12); printf("Espere a Or%cculo dizer as cores para cortar o fio.",160);
	gotoxy(20,13); printf("Use < > para mover o cursor.");
	gotoxy(20,14); printf("Aperte enter para selecionar que fio cortar.");
	gotoxy(20,15); printf("Esse %c um jogo da mem%cria, boa sorte!",130,162);
	textcolor(8);
	gotoxy(20,18); printf("Aperte enter para continuar e esc para escolher outro jogo");
	do
	{
		e=getch();
		switch(e)
		{
			case 13:
				jogo_batwoman();
				break;
			case 27:
				return;
				break;
			default:
				break;
		}
	}while(e!=13);
}

//----------------------------------------------------------------------------------------------------------------------------------

void limpar_parede(int x)
{
	cursor(0);
	int aux=x;
		for (int y=28; y>=18; y--)
			for(x=aux; x<=aux+2; x++)
			{
				textbackground(15);
				gotoxy(x,y);printf(" ");
			}
}

//----------------------------------------------------------------------------------------------------------------------------------

void parede1(int x, int xf, int p1, int p2)
{
	cursor(0);
	int aux=x;
		for (int y=28; y>=18; y--)
			for(x=aux; x<=aux+2; x++)
			{
				textbackground(6);
				gotoxy(x,y);printf(" ");
			}
}

//----------------------------------------------------------------------------------------------------------------------------------

void parede2(int x, int xf, int p1, int p2)
{
	cursor(0);
	int aux=x;
		for (int y=28; y>=18; y--)
			for(x=aux; x<=aux+2; x++)
			{
				textbackground(6);
				gotoxy(x,y);printf(" ");
			}
}

//----------------------------------------------------------------------------------------------------------------------------------

void parede3(int x, int xf, int p1, int p2)
{
	cursor(0);
	int aux=x;
		for (int y=28; y>=18; y--)
			for(x=aux; x<=aux+2; x++)
			{
				textbackground(6);
				gotoxy(x,y);printf(" ");
			}
}

//----------------------------------------------------------------------------------------------------------------------------------

void parede4(int x, int xf, int p1, int p2)
{
	cursor(0);
	int aux=x;
		for (int y=28; y>=18; y--)
			for(x=aux; x<=aux+2; x++)
			{
				textbackground(6);
				gotoxy(x,y);printf(" ");
			}
}

//----------------------------------------------------------------------------------------------------------------------------------

void limpar_bala(int x)
{
	textbackground(15);
	textcolor(15);
	gotoxy(x,23);printf("-");
}

//----------------------------------------------------------------------------------------------------------------------------------

void bala(int x, int xf, int p1, int p2)
{
	textbackground(15);
	textcolor(8);
	setlocale(LC_ALL,"C");
	gotoxy(x,23);printf("%c",22);
	setlocale(LC_ALL,NULL);
}

//----------------------------------------------------------------------------------------------------------------------------------

void bala2(int x, int xf, int p1, int p2)
{
	textbackground(15);
	textcolor(8);
	setlocale(LC_ALL,"C");
	gotoxy(x,23);printf("%c",22);
	setlocale(LC_ALL,NULL);
}

//----------------------------------------------------------------------------------------------------------------------------------

void bala3(int x, int xf, int p1, int p2)
{
	textbackground(15);
	textcolor(8);
	setlocale(LC_ALL,"C");
	gotoxy(x,23);printf("%c",22);
	setlocale(LC_ALL,NULL);
}

//----------------------------------------------------------------------------------------------------------------------------------

void bala4(int x, int xf, int p1, int p2)
{
	textbackground(15);
	textcolor(8);
	setlocale(LC_ALL,"C");
	gotoxy(x,23);printf("%c",22);
	setlocale(LC_ALL,NULL);
}

//----------------------------------------------------------------------------------------------------------------------------------

void chao()
{
		
		cursor(0);
		for (int y=30; y<=40; y++)
			for(int x=1; x<=120; x++)
			{
				textbackground(8);
				gotoxy(x,y);printf(" ");
			}
		
}
/*
           *******++                               
          *********+++                         *4    
        ****************                       #0 
        *****************                      +11
         ##          ##                            
                                                      
*/

//----------------------------------------------------------------------------------------------------------------------------------

void limpar_carro(int X)
{
	textbackground(15);
	///////////////////////////////////////////linha 1
	textbackground(15);
	textcolor(15);
	gotoxy(X+3,24);printf("#######");
	textbackground(15);
	textcolor(15);
	gotoxy(X+10,24);printf("##");
	
	///////////////////////////////////////////linha 2
	textbackground(15);
	textcolor(15);
	gotoxy(X+2,25);printf("########");
	textbackground(15);
	textcolor(15);
	gotoxy(X+10,25);printf("###");
	
	///////////////////////////////////////////linha 3
	textbackground(15);
	textcolor(15);
	gotoxy(X,26);printf("################");
	///////////////////////////////////////////linha 4
	textbackground(15);
	textcolor(15);
	gotoxy(X,27);printf("#################");
	///////////////////////////////////////////linha 5
	textbackground(15);
	textcolor(15);
	gotoxy(X+1,28);printf("##");
	gotoxy(X+13,28);printf("##");
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void carro(int X)
{
	textbackground(15);
	///////////////////////////////////////////linha 1
	textbackground(4);
	textcolor(4);
	gotoxy(X+3,24);printf("#######");
	textbackground(11);
	textcolor(11);
	gotoxy(X+10,24);printf("##");
	
	///////////////////////////////////////////linha 2
	textbackground(4);
	textcolor(4);
	gotoxy(X+2,25);printf("########");
	textbackground(11);
	textcolor(11);
	gotoxy(X+10,25);printf("###");
	
	///////////////////////////////////////////linha 3
	textbackground(4);
	textcolor(4);
	gotoxy(X,26);printf("################");
	///////////////////////////////////////////linha 4
	textbackground(4);
	textcolor(4);
	gotoxy(X,27);printf("#################");
	///////////////////////////////////////////linha 5
	textbackground(0);
	textcolor(0);
	gotoxy(X+1,28);printf("##");
	gotoxy(X+13,28);printf("##");
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void parede_quebrada(int x)
{
	int aux=x;
	cursor(0);
		for (int y=28; y>=18; y--)
			for(x=aux; x<=aux+2; x++)
			{
				if(x==16&&y==21)
				{
					textbackground(6);
					gotoxy(x,y);printf(" ");
				}
				if(x==17&&y==23)
				{
					textbackground(6);
					gotoxy(x,y);printf(" ");
				}
				if(x==16&&y==26)
				{
					textbackground(6);
					gotoxy(x,y);printf(" ");
				}
				if(x==16&&y==19)
				{
					textbackground(6);
					gotoxy(x,y);printf(" ");
				}
				if(x==17&&y==24)
				{
					textbackground(6);
					gotoxy(x,y);printf(" ");
				}
				if(x==18&&y==21)
				{
					textbackground(6);
					gotoxy(x,y);printf(" ");
				}
				if(x==18&&y==18)
				{
					textbackground(6);
					gotoxy(x,y);printf(" ");
				}
				if(x==18&&y==24)
				{
					textbackground(6);
					gotoxy(x,y);printf(" ");
				}
			}
}

//----------------------------------------------------------------------------------------------------------------------------------

void tela_flash(int speed, int vida, int progresso)
{
	textbackground(15);
	textcolor(0);
	gotoxy(3,3);printf("                                 ");
	textbackground(15);
	textcolor(0);
	gotoxy(3,3);printf("Velocidade: %d km/h",speed);
//	gotoxy(3,4);printf("%d",progresso);
	if(speed>=400)
		textcolor(12);
	else
		textcolor(8);
	gotoxy(33,3);printf("Subir a parede",speed);
	if(speed>=800)
		textcolor(12);
	else
		textcolor(8);
	gotoxy(63,3);printf("Atravessar objetos",speed);
	textbackground(8);
	gotoxy(110,30);printf("   ");
	setlocale(LC_ALL,"C");
	gotoxy(110,30);
	for (int i=0; i<vida; i++)
	{
		textbackground(8);
		textcolor(12);
		printf("%c",3);
	}
	setlocale(LC_ALL,NULL);
	textbackground(9);
	if(speed<300)
	{
		gotoxy(progresso,5);printf(" ");
	}
	else
		if(speed<600)
		{
			gotoxy(progresso,5);printf("  ");
		}
	else
		gotoxy(progresso,5);printf("   ");
	textbackground(15);
	textcolor(0);
	gotoxy(3,5);printf("Come%co",135);
	gotoxy(109,5);printf("Fim");
}

//----------------------------------------------------------------------------------------------------------------------------------

void limpar_sangue(int x)
{
	textcolor(15);
	textbackground(15);
	gotoxy(x,24);printf(",");
	gotoxy(x+2,23);printf(",");
	gotoxy(x-1,22);printf(",");
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void sangue(int x)
{
	textcolor(12);
	textbackground(15);
	gotoxy(x,24);printf(",");
	gotoxy(x+2,23);printf(",");
	gotoxy(x-1,22);printf(",");
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void jogo_flash()
{
	do
	{
		textbackground(15);
		system("cls");
		int ganhar=0;
		int perder=0;
		int Xc=102;
		char op;
		//////////////////////// paredes /////////////////
		
		int Xp=80;
		int Xp2=80;
		int Xp3=80;
		int Xp4=80;
		
		int des1=0;
		int des2=0;
		int des3=0;
		int des4=0;
		
		//////////////////////// balas /////////////////
		
		int Xb=80;
		int Xb2=80;
		int Xb3=80;
		int Xb4=80;
		
		int Des1=0;
		int Des2=0;
		int Des3=0;
		int Des4=0;
		
		
		int muv=1;     // mínimo 41   7 cada
		int speed=50;
		int vida=3;
		int bater=0;
		int progresso=3;
		char g;
		chao();
		carro(Xc);
		parede1(Xp, 2,1, 2);
		animaflash1(11,20);
		tela_flash(speed, vida,progresso);
	//	bala(Xb,3,2,3);
		do
		{
//			gotoxy(10,7);printf("%d  %d %d",muv, Xp2, des2);
			g=getch();
			switch(g)
			{
				case 77:    //seta para direita
				
				///////////////////// parede			
					if(Xp>8&&des1==0)
						limpar_parede(Xp);
					if(Xp2>8&&des2==0&&muv>8)
						limpar_parede(Xp2);
					if(Xp3>8&&des3==0&&muv>23)
						limpar_parede(Xp3);
					if(Xp4>8&&des4==0&&muv>47)
						limpar_parede(Xp4);
				///////////////////// bala			
					if(Xb>8&&Des1==0&&muv>15)
						limpar_bala(Xb);
					if(Xb2>8&&Des2==0&&muv>31)
						limpar_bala(Xb2);
					if(Xb3>8&&Des3==0&&muv>39)
						limpar_bala(Xb3);
					if(Xb4>8&&Des4==0&&muv>52)
						limpar_bala(Xb4);			
					limpar_flash1e3(11,20);
					limpar_flash2e4(11,20);
	//				Xb--;
				///////////////////// parede
					if(des1==0)
						Xp-=8;
					if(des2==0&&muv>8)
						Xp2-=8;
					if(des3==0&&muv>23)
						Xp3-=8;
					if(des4==0&&muv>47)
						Xp4-=8;
				///////////////////// bala			
					if(Des1==0&&muv>15)
						Xb-=8;
					if(Des2==0&&muv>31)
						Xb2-=8;
					if(Des3==0&&muv>39)
						Xb3-=8;
					if(Des4==0&&muv>52)
						Xb4-=8;
				///////////////////// parede	
					if(Xp>8&&des1==0)
						parede1(Xp,1,1,1);
					if(Xp2>8&&des2==0&&muv>8)
						parede2(Xp2,1,1,1);
					if(Xp3>8&&des3==0&&muv>23)
						parede3(Xp3,1,1,1);
					if(Xp4>8&&des4==0&&muv>47)
						parede4(Xp4,1,1,1);
				///////////////////// bala
					if(Xb>8&&Des1==0&&muv>15)
						bala(Xb,1,1,1);
					if(Xb2>8&&Des2==0&&muv>31)
						bala2(Xb2,1,1,1);
					if(Xb3>8&&Des3==0&&muv>39)
						bala3(Xb3,1,1,1);
					if(Xb4>8&&Des4==0&&muv>52)
						bala4(Xb4,1,1,1);
						
					else
					{
					///////////////////// parede
						if(Xp==8&&des1==0)
						{
							vida--;
							speed-=50;
							bater=1;
							parede_quebrada(16);
							if(muv%4==0)
							{
								animaflash4(11,20);
							}
							else 	if((muv+1)%4==0)
									{
										animaflash3(11,20);		
									}	
							else 	if((muv+2)%4==0)
									{
										animaflash2(11,20);		
									}
							else 	if((muv+3)%4==0)
									{
										animaflash1(11,20);		
									}
							Sleep(300);
							limpar_parede(16);
							des1=1;
						}
						if(Xp2==8&&des2==0&&muv>8)
						{
							vida--;
							speed-=50;
							bater=1;
							parede_quebrada(16);
							if(muv%4==0)
							{
								animaflash4(11,20);
							}
							else 	if((muv+1)%4==0)
									{
										animaflash3(11,20);		
									}	
							else 	if((muv+2)%4==0)
									{
										animaflash2(11,20);		
									}
							else 	if((muv+3)%4==0)
									{
										animaflash1(11,20);		
									}
							Sleep(300);
							limpar_parede(16);
							des2=1;
						}
						if(Xp3==8&&des3==0&&muv>23)
						{
							vida--;
							speed-=50;
							bater=1;
							parede_quebrada(16);
							if(muv%4==0)
							{
								animaflash4(11,20);
							}
							else 	if((muv+1)%4==0)
									{
										animaflash3(11,20);		
									}	
							else 	if((muv+2)%4==0)
									{
										animaflash2(11,20);		
									}
							else 	if((muv+3)%4==0)
									{
										animaflash1(11,20);		
									}
							Sleep(300);
							limpar_parede(16);
							des3=1;
						}
						if(Xp4==8&&des4==0&&muv>47)
						{
							vida--;
							speed-=50;
							bater=1;
							parede_quebrada(16);
							if(muv%4==0)
							{
								animaflash4(11,20);
							}
							else 	if((muv+1)%4==0)
									{
										animaflash3(11,20);		
									}	
							else 	if((muv+2)%4==0)
									{
										animaflash2(11,20);		
									}
							else 	if((muv+3)%4==0)
									{
										animaflash1(11,20);		
									}
							Sleep(300);
							limpar_parede(16);
							des4=1;
						}
						
					///////////////////// bala
					
					if(Xb==8&&Des1==0)
						{
							vida--;
							speed-=50;
							bater=1;
							if(muv%4==0)
							{
								animaflash4(11,20);
							}
							else 	if((muv+1)%4==0)
									{
										animaflash3(11,20);		
									}	
							else 	if((muv+2)%4==0)
									{
										animaflash2(11,20);		
									}
							else 	if((muv+3)%4==0)
									{
										animaflash1(11,20);		
									}
							Sleep(300);
							limpar_bala(16);
							sangue(16);
							Sleep(300);
							limpar_sangue(16);
							Des1=1;
						}
						if(Xb2==8&&Des2==0)
						{
							vida--;
							speed-=50;
							bater=1;
							if(muv%4==0)
							{
								animaflash4(11,20);
							}
							else 	if((muv+1)%4==0)
									{
										animaflash3(11,20);		
									}	
							else 	if((muv+2)%4==0)
									{
										animaflash2(11,20);		
									}
							else 	if((muv+3)%4==0)
									{
										animaflash1(11,20);		
									}
							Sleep(300);
							limpar_bala(16);
							sangue(16);
							Sleep(300);
							limpar_sangue(16);
							Des2=1;
						}
						if(Xb3==8&&Des3==0)
						{
							vida--;
							speed-=50;
							bater=1;
							if(muv%4==0)
							{
								animaflash4(11,20);
							}
							else 	if((muv+1)%4==0)
									{
										animaflash3(11,20);		
									}	
							else 	if((muv+2)%4==0)
									{
										animaflash2(11,20);		
									}
							else 	if((muv+3)%4==0)
									{
										animaflash1(11,20);		
									}
							Sleep(300);
							limpar_bala(16);
							sangue(16);
							Sleep(300);
							limpar_sangue(16);
							Des3=1;
						}
						if(Xb4==8&&Des4==0)
						{
							vida--;
							speed-=50;
							bater=1;
							if(muv%4==0)
							{
								animaflash4(11,20);
							}
							else 	if((muv+1)%4==0)
									{
										animaflash3(11,20);		
									}	
							else 	if((muv+2)%4==0)
									{
										animaflash2(11,20);		
									}
							else 	if((muv+3)%4==0)
									{
										animaflash1(11,20);		
									}
							Sleep(300);
							limpar_bala(16);
							sangue(16);
							Sleep(300);
							limpar_sangue(16);
							Des4=1;
						}
					}
					muv++;   //muv 8 fica na frente flash x=16;
					if (bater==0)
					{
						speed+=50;
					}
					if(speed<300)
						progresso++;
					else
						if(speed<600)
							progresso+=2;
					else
						progresso+=3;
					if(bater==0)
					{
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
					}
					else
						bater=0;
					break;
				case 72:    //seta para cima
					if(Xp==16&&speed>=400&&des1==0)
					{
						if(speed<300)
						progresso++;
						else
							if(speed<600)
								progresso+=2;
						else
							progresso+=3;
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						speed-=200;
						muv++;
						if(muv%4==0)
						{
							animaflash4(11,16);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,16);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,16);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,16);		
								}
						Sleep(300);
						limpar_flash1e3(11,16);
						limpar_flash2e4(11,16);
						if(muv%4==0)
						{
							animaflash4(11,12);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,12);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,12);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,12);		
								}
						Sleep(300);
						limpar_flash1e3(11,12);
						limpar_flash2e4(11,12);
						if(muv%4==0)
						{
							animaflash4(11,9);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,9);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,9);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,9);		
								}
						Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						if(Xp3>8&&des3==0&&muv>23)
							limpar_parede(Xp3);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						if(des1==0)
							Xp-=8;
						if(des2==0&&muv>8)
							Xp2-=8;
						if(des3==0&&muv>23)
							Xp3-=8;
						if(des4==0&&muv>47)
							Xp4-=8;
						if(Xp>8&&des1==0)
							parede1(Xp,1,1,1);
						if(Xp2>8&&des2==0&&muv>8)
							parede2(Xp2,1,1,1);
						if(Xp3>8&&des3==0&&muv>23)
							parede3(Xp3,1,1,1);
						if(Xp4>8&&des4==0&&muv>47)
							parede4(Xp4,1,1,1);
						Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						if(Xp3>8&&des3==0&&muv>23)
							limpar_parede(Xp3);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						if(des1==0)
							Xp-=8;
						if(des2==0&&muv>8)
							Xp2-=8;
						if(des3==0&&muv>23)
							Xp3-=8;
						if(des4==0&&muv>47)
							Xp4-=8;
						des1=1;
						if(Xp>8&&des1==0)
							parede1(Xp,1,1,1);
						if(Xp2>8&&des2==0&&muv>8)
							parede2(Xp2,1,1,1);
						if(Xp3>8&&des3==0&&muv>23)
							parede3(Xp3,1,1,1);
						if(Xp4>8&&des4==0&&muv>47)
							parede4(Xp4,1,1,1);
						limpar_flash1e3(11,9);
						limpar_flash2e4(11,9);
						if(muv%4==0)
						{
							animaflash4(11,12);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,12);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,12);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,12);		
								}
						Sleep(300);
						limpar_flash1e3(11,12);
						limpar_flash2e4(11,12);
						if(muv%4==0)
						{
							animaflash4(11,16);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,16);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,16);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,16);		
								}
						Sleep(300);
						limpar_flash1e3(11,16);
						limpar_flash2e4(11,16);
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
						
					}
					
					
					if(Xp2==16&&speed>=400&&muv>8&&des2==0)
					{
						if(speed<300)
						progresso++;
						else
							if(speed<600)
								progresso+=2;
						else
							progresso+=3;
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						speed-=200;
						muv++;
						if(muv%4==0)
						{
							animaflash4(11,16);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,16);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,16);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,16);		
								}
//						muv++;
						Sleep(300);
						limpar_flash1e3(11,16);
						limpar_flash2e4(11,16);
						if(muv%4==0)
						{
							animaflash4(11,12);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,12);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,12);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,12);		
								}
//						muv++;
						Sleep(300);
						limpar_flash1e3(11,12);
						limpar_flash2e4(11,12);
						if(muv%4==0)
						{
							animaflash4(11,9);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,9);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,9);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,9);		
								}
						Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						if(Xp3>8&&des3==0&&muv>23)
							limpar_parede(Xp3);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						if(des1==0)
							Xp-=8;
						if(des2==0)
							Xp2-=8;
						if(des3==0)
							Xp3-=8;
						if(des4==0)
							Xp4-=8;	
						if(Xp>8&&des1==0)
							parede1(Xp,1,1,1);
						if(Xp2>8&&des2==0&&muv>8)
							parede2(Xp2,1,1,1);
						if(Xp3>8&&des3==0&&muv>23)
							parede3(Xp3,1,1,1);
						if(Xp4>8&&des4==0&&muv>47)
							parede4(Xp4,1,1,1);
						Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						if(Xp3>8&&des3==0&&muv>23)
							limpar_parede(Xp3);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						if(des1==0)
							Xp-=8;
						if(des2==0)
							Xp2-=8;
						if(des3==0)
							Xp3-=8;
						if(des4==0)
							Xp4-=8;	
						des2=1;
//						muv++;
						limpar_flash1e3(11,9);
						limpar_flash2e4(11,9);
						if(muv%4==0)
						{
							animaflash4(11,12);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,12);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,12);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,12);		
								}
//						muv++;
						Sleep(300);
						limpar_flash1e3(11,12);
						limpar_flash2e4(11,12);
						if(muv%4==0)
						{
							animaflash4(11,16);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,16);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,16);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,16);		
								}
//						muv++;
						Sleep(300);
						limpar_flash1e3(11,16);
						limpar_flash2e4(11,16);
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
						
					}
					
					
					if(Xp3==16&&speed>=400&&muv>23&&des3==0)
					{
						if(speed<300)
						progresso++;
						else
							if(speed<600)
								progresso+=2;
						else
							progresso+=3;
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						speed-=200;
						muv++;
						if(muv%4==0)
						{
							animaflash4(11,16);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,16);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,16);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,16);		
								}
//						muv++;
						Sleep(300);
						limpar_flash1e3(11,16);
						limpar_flash2e4(11,16);
						if(muv%4==0)
						{
							animaflash4(11,12);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,12);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,12);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,12);		
								}
//						muv++;
						Sleep(300);
						limpar_flash1e3(11,12);
						limpar_flash2e4(11,12);
						if(muv%4==0)
						{
							animaflash4(11,9);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,9);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,9);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,9);		
								}
						Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						if(Xp3>8&&des3==0&&muv>23)
							limpar_parede(Xp3);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						if(des1==0)
							Xp-=8;
						if(des2==0)
							Xp2-=8;
						if(des3==0)
							Xp3-=8;
						if(des4==0)
							Xp4-=8;	
						if(Xp>8&&des1==0)
							parede1(Xp,1,1,1);
						if(Xp2>8&&des2==0&&muv>8)
							parede2(Xp2,1,1,1);
						if(Xp3>8&&des3==0&&muv>23)
							parede3(Xp3,1,1,1);
						if(Xp4>8&&des4==0&&muv>47)
							parede4(Xp4,1,1,1);
						Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						if(Xp3>8&&des3==0&&muv>23)
							limpar_parede(Xp3);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						if(des1==0)
							Xp-=8;
						if(des2==0)
							Xp2-=8;
						if(des3==0)
							Xp3-=8;
						if(des4==0)
							Xp4-=8;	
						des3=1;
//						muv++;
						limpar_flash1e3(11,9);
						limpar_flash2e4(11,9);
						if(muv%4==0)
						{
							animaflash4(11,12);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,12);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,12);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,12);		
								}
	//					muv++;
						Sleep(300);
						limpar_flash1e3(11,12);
						limpar_flash2e4(11,12);
						if(muv%4==0)
						{
							animaflash4(11,16);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,16);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,16);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,16);		
								}
	//					muv++;
						Sleep(300);
						limpar_flash1e3(11,16);
						limpar_flash2e4(11,16);
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
						
					}
					
					
					if(Xp4==16&&speed>=400&&muv>47&&des4==0)
					{
						if(speed<300)
						progresso++;
						else
							if(speed<600)
								progresso+=2;
						else
							progresso+=3;
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						speed-=200;
						muv++;
						if(muv%4==0)
						{
							animaflash4(11,16);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,16);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,16);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,16);		
								}
//						muv++;
						Sleep(300);
						limpar_flash1e3(11,16);
						limpar_flash2e4(11,16);
						if(muv%4==0)
						{
							animaflash4(11,12);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,12);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,12);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,12);		
								}
	//					muv++;
						Sleep(300);
						limpar_flash1e3(11,12);
						limpar_flash2e4(11,12);
						if(muv%4==0)
						{
							animaflash4(11,9);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,9);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,9);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,9);		
								}
						Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						if(Xp3>8&&des3==0&&muv>23)
							limpar_parede(Xp3);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						if(des1==0)
							Xp-=8;
						if(des2==0)
							Xp2-=8;
						if(des3==0)
							Xp3-=8;
						if(des4==0)
							Xp4-=8;	
						if(Xp>8&&des1==0)
							parede1(Xp,1,1,1);
						if(Xp2>8&&des2==0&&muv>8)
							parede2(Xp2,1,1,1);
						if(Xp3>8&&des3==0&&muv>23)
							parede3(Xp3,1,1,1);
						if(Xp4>8&&des4==0&&muv>47)
							parede4(Xp4,1,1,1);
						Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						if(Xp3>8&&des3==0&&muv>23)
							limpar_parede(Xp3);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						if(des1==0)
							Xp-=8;
						if(des2==0)
							Xp2-=8;
						if(des3==0)
							Xp3-=8;
						if(des4==0)
							Xp4-=8;	
						des4=1;
	//					muv++;
						limpar_flash1e3(11,9);
						limpar_flash2e4(11,9);
						if(muv%4==0)
						{
							animaflash4(11,12);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,12);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,12);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,12);		
								}
	//					muv++;
						Sleep(300);
						limpar_flash1e3(11,12);
						limpar_flash2e4(11,12);
						if(muv%4==0)
						{
							animaflash4(11,16);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,16);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,16);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,16);		
								}
	//					muv++;
						Sleep(300);
						limpar_flash1e3(11,16);
						limpar_flash2e4(11,16);
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
						
					}
					
					
					break;
				case 13:
					if(Xp==16&&speed>=800&&des1==0)
					{
						if(speed<300)
							progresso++;
						else
							if(speed<600)
								progresso+=2;
						else
							progresso+=3;
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						speed-=500;
						muv++;
	//					Sleep(300);
	
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						if(Xp3>8&&des3==0&&muv>23)
							limpar_parede(Xp3);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						if(des1==0)
							Xp-=8;
						if(des2==0)
							Xp2-=8;
						if(des3==0)
							Xp3-=8;
						if(des4==0)
							Xp4-=8;	
						Sleep(300);
						
						if(Xp>8&&des1==0)
							parede1(Xp,1,1,1);
						if(Xp2>8&&des2==0&&muv>8)
							parede2(Xp2,1,1,1);
						if(Xp3>8&&des3==0&&muv>23)
							parede3(Xp3,1,1,1);
						if(Xp4>8&&des4==0&&muv>47)
							parede4(Xp4,1,1,1);
						Sleep(300);
						
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						if(Xp3>8&&des3==0&&muv>23)
							limpar_parede(Xp3);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						if(Xp>8&&des1==0)
							parede1(Xp,1,1,1);
						if(Xp2>8&&des2==0&&muv>8)
							parede2(Xp2,1,1,1);
						if(Xp3>8&&des3==0&&muv>23)
							parede3(Xp3,1,1,1);
						if(Xp4>8&&des4==0&&muv>47)
							parede4(Xp4,1,1,1);
						des1=1;
						
						Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						if(Xp3>8&&des3==0&&muv>23)
							limpar_parede(Xp3);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						if(des1==0)
							Xp-=8;
						if(des2==0)
							Xp2-=8;
						if(des3==0)
							Xp3-=8;
						if(des4==0)
							Xp4-=8;	
						if(Xp>8&&des1==0)
							parede1(Xp,1,1,1);
						if(Xp2>8&&des2==0&&muv>8)
							parede2(Xp2,1,1,1);
						if(Xp3>8&&des3==0&&muv>23)
							parede3(Xp3,1,1,1);
						if(Xp4>8&&des4==0&&muv>47)
							parede4(Xp4,1,1,1);
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
					}
					if(Xp2==16&&speed>=800&&des2==0&&muv>8)
					{
						if(speed<300)
							progresso++;
						else
							if(speed<600)
								progresso+=2;
						else
							progresso+=3;
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						speed-=500;
						muv++;
	//					Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						if(Xp3>8&&des3==0&&muv>23)
							limpar_parede(Xp3);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						if(des1==0)
							Xp-=8;
						if(des2==0)
							Xp2-=8;
						if(des3==0)
							Xp3-=8;
						if(des4==0)
							Xp4-=8;	
						Sleep(300);
						if(des1==0)
						{
							parede1(Xp,1,1,1);
						}
						if(des2==0&&muv>8)
						{
							parede2(Xp2,1,1,1);
						}
						if(des3==0&&muv>23)
							parede3(Xp3,1,1,1);
						if(des4==0&&muv>47)
							parede4(Xp4,1,1,1);
						Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp3>8&&des3==0&&muv>8)
							limpar_parede(Xp3);
						limpar_parede(8);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						des2=1;
						Sleep(300);
						if(des1==0)
							Xp-=8;
						if(des2==0)
							Xp2-=8;
						if(des3==0)
							Xp3-=8;
						if(des4==0)
							Xp4-=8;	
						if(Xp>8&&des1==0)
						{

							parede1(Xp,1,1,1);
						}
						if(Xp2>8&&des2==0&&muv>8)
						{

							parede2(Xp2,1,1,1);
						}
						if(Xp3>8&&des3==0&&muv>23)
						{
							parede3(Xp3,1,1,1);
						}
						if(Xp4>8&&des4==0&&muv>47)
						{
							parede4(Xp4,1,1,1);
							
						}
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
					}
					
					
					
					if(Xp3==16&&speed>=800&&des3==0&&muv>23)
					{
						if(speed<300)
							progresso++;
						else
							if(speed<600)
								progresso+=2;
						else
							progresso+=3;
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						speed-=500;
						muv++;
	//					Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						if(Xp3>8&&des3==0&&muv>23)
							limpar_parede(Xp3);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						if(des1==0)
							Xp-=8;
						if(des2==0)
							Xp2-=8;
						if(des3==0)
							Xp3-=8;
						if(des4==0)
							Xp4-=8;	
						Sleep(300);
						if(des1==0)
						{
							parede1(Xp,1,1,1);
						}
						if(des2==0&&muv>8)
						{
							parede2(Xp2,1,1,1);
						}
						if(des3==0&&muv>23)
							parede3(Xp3,1,1,1);
						if(des4==0&&muv>47)
							parede4(Xp4,1,1,1);
						Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						limpar_parede(8);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						des3=1;
						Sleep(300);
						if(des1==0)
							Xp-=8;
						if(des2==0)
							Xp2-=8;
						if(des3==0)
							Xp3-=8;
						if(des4==0)
							Xp4-=8;	
						if(Xp>8&&des1==0)
						{

							parede1(Xp,1,1,1);
						}
						if(Xp2>8&&des2==0&&muv>8)
						{

							parede2(Xp2,1,1,1);
						}
						if(Xp3>8&&des3==0&&muv>23)
						{
							parede3(Xp3,1,1,1);
						}
						if(Xp4>8&&des4==0&&muv>47)
						{
							parede4(Xp4,1,1,1);
							
						}
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
					}
					
					if(Xp4==16&&speed>=800&&des4==0&&muv>47)
					{
						if(speed<300)
							progresso++;
						else
							if(speed<600)
								progresso+=2;
						else
							progresso+=3;
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						speed-=500;
						muv++;
	//					Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						if(Xp3>8&&des3==0&&muv>23)
							limpar_parede(Xp3);
						if(Xp4>8&&des4==0&&muv>47)
							limpar_parede(Xp4);
						if(des1==0)
							Xp-=8;
						if(des2==0)
							Xp2-=8;
						if(des3==0)
							Xp3-=8;
						if(des4==0)
							Xp4-=8;	
						Sleep(300);
						if(des1==0)
						{
							parede1(Xp,1,1,1);
						}
						if(des2==0&&muv>8)
						{
							parede2(Xp2,1,1,1);
						}
						if(des3==0&&muv>23)
							parede3(Xp3,1,1,1);
						if(des4==0&&muv>47)
							parede4(Xp4,1,1,1);
						Sleep(300);
						if(Xp>8&&des1==0)
							limpar_parede(Xp);
						if(Xp2>8&&des2==0&&muv>8)
							limpar_parede(Xp2);
						limpar_parede(8);
						if(Xp3>8&&des3==0&&muv>47)
							limpar_parede(Xp3);
						des4=1;
						Sleep(300);
						if(des1==0)
							Xp-=8;
						if(des2==0)
							Xp2-=8;
						if(des3==0)
							Xp3-=8;
						if(des4==0)
							Xp4-=8;	
						if(Xp>8&&des1==0)
						{

							parede1(Xp,1,1,1);
						}
						if(Xp2>8&&des2==0&&muv>8)
						{

							parede2(Xp2,1,1,1);
						}
						if(Xp3>8&&des3==0&&muv>23)
						{
							parede3(Xp3,1,1,1);
						}
						if(Xp4>8&&des4==0&&muv>47)
						{
							parede4(Xp4,1,1,1);
							
						}
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
					}
					if(Xb==16&&speed>=800&&Des1==0)
					{
						if(speed<300)
						progresso++;
						else
							if(speed<600)
								progresso+=2;
						else
							progresso+=3;
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
						speed-=200;
						muv++;
	//					Sleep(300);
						//////////////////////////bala
						if(Xb>8&&Des1==0&&muv>15)
							limpar_bala(Xb);
						if(Xb2>8&&Des2==0&&muv>31)
							limpar_bala(Xb2);
						if(Xb3>8&&Des3==0&&muv>39)
							limpar_bala(Xb3);
						if(Xb4>8&&Des4==0&&muv>52)
							limpar_bala(Xb4);
						//////////////////////////bala
						if(Des1==0&&muv>15)
							Xb-=8;
						if(Des2==0&&muv>31)
							Xb2-=8;
						if(Des3==0&&muv>39)
							Xb3-=8;
						if(Des4==0&&muv>52)
							Xb4-=8;
						//////////////////////////bala
						bala(Xb,1,1,1);
						if(Xb2>8&&Des2==0&&muv>31)
							bala2(Xb2,1,1,1);
						if(Xb3>8&&Des3==0&&muv>39)
							bala3(Xb3,1,1,1);
						if(Xb4>8&&Des4==0&&muv>52)
							bala4(Xb4,1,1,1);
						Sleep(300);
						//////////////////////////bala
						limpar_bala(Xb);
						if(Xb2>8&&Des2==0&&muv>31)
							limpar_bala(Xb2);
						if(Xb3>8&&Des3==0&&muv>39)
							limpar_bala(Xb3);
						if(Xb4>8&&Des4==0&&muv>52)
							limpar_bala(Xb4);
						Des1=1;
						Sleep(300);
						//////////////////////////bala
						if(Des1==0&&muv>15)
							Xb-=8;
						if(Des2==0&&muv>31)
							Xb2-=8;
						if(Des3==0&&muv>39)
							Xb3-=8;
						if(Des4==0&&muv>52)
							Xb4-=8;
						//////////////////////////bala
						if(Xb>8&&Des1==0&&muv>15)
							bala(Xb,1,1,1);
						if(Xb2>8&&Des2==0&&muv>31)
							bala2(Xb2,1,1,1);
						if(Xb3>8&&Des3==0&&muv>39)
							bala3(Xb3,1,1,1);
						if(Xb4>8&&Des4==0&&muv>52)
							bala4(Xb4,1,1,1);
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
					}
					if(Xb2==16&&speed>=800&&Des2==0)
					{
						if(speed<300)
						progresso++;
						else
							if(speed<600)
								progresso+=2;
						else
							progresso+=3;
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
						speed-=200;
						muv++;
	//					Sleep(300);
						//////////////////////////bala
						if(Xb>8&&Des1==0&&muv>15)
							limpar_bala(Xb);
						limpar_bala(Xb2);
						if(Xb3>8&&Des3==0&&muv>39)
							limpar_bala(Xb3);
						if(Xb4>8&&Des4==0&&muv>52)
							limpar_bala(Xb4);
						//////////////////////////bala
						if(Des1==0&&muv>15)
							Xb-=8;
						if(Des2==0&&muv>31)
							Xb2-=8;
						if(Des3==0&&muv>39)
							Xb3-=8;
						if(Des4==0&&muv>52)
							Xb4-=8;
						//////////////////////////bala
						bala2(Xb2,1,1,1);
						if(Xb>8&&Des1==0&&muv>15)
							bala(Xb,1,1,1);
						if(Xb3>8&&Des3==0&&muv>39)
							bala3(Xb3,1,1,1);
						if(Xb4>8&&Des4==0&&muv>52)
							bala4(Xb4,1,1,1);
						Sleep(300);
						//////////////////////////bala
						limpar_bala(Xb2);
						if(Xb>8&&Des1==0&&muv>15)
							limpar_bala(Xb);
						if(Xb3>8&&Des3==0&&muv>39)
							limpar_bala(Xb3);
						if(Xb4>8&&Des4==0&&muv>52)
							limpar_bala(Xb4);
						Des2=1;
						Sleep(300);
						//////////////////////////bala
						if(Des1==0&&muv>15)
							Xb-=8;
						if(Des2==0&&muv>31)
							Xb2-=8;
						if(Des3==0&&muv>39)
							Xb3-=8;
						if(Des4==0&&muv>52)
							Xb4-=8;
						//////////////////////////bala
						if(Xb>8&&Des1==0&&muv>15)
							bala(Xb,1,1,1);
						if(Xb2>8&&Des2==0&&muv>31)
							bala2(Xb2,1,1,1);
						if(Xb3>8&&Des3==0&&muv>39)
							bala3(Xb3,1,1,1);
						if(Xb4>8&&Des4==0&&muv>52)
							bala4(Xb4,1,1,1);
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
					}
					if(Xb3==16&&speed>=800&&Des3==0)
					{
						if(speed<300)
						progresso++;
						else
							if(speed<600)
								progresso+=2;
						else
							progresso+=3;
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
						speed-=200;
						muv++;
	//					Sleep(300);
						//////////////////////////bala
						if(Xb>8&&Des1==0&&muv>15)
							limpar_bala(Xb);
						if(Xb2>8&&Des2==0&&muv>31)
							limpar_bala(Xb2);
						limpar_bala(Xb3);
						if(Xb4>8&&Des4==0&&muv>52)
							limpar_bala(Xb4);
						//////////////////////////bala
						if(Des1==0&&muv>15)
							Xb-=8;
						if(Des2==0&&muv>31)
							Xb2-=8;
						if(Des3==0&&muv>39)
							Xb3-=8;
						if(Des4==0&&muv>52)
							Xb4-=8;
						//////////////////////////bala
						bala3(Xb3,1,1,1);
						if(Xb3>8&&Des3==0&&muv>15)
							bala3(Xb3,1,1,1);
						if(Xb2>8&&Des2==0&&muv>39)
							bala2(Xb2,1,1,1);
						if(Xb4>8&&Des4==0&&muv>52)
							bala4(Xb4,1,1,1);
						Sleep(300);
						//////////////////////////bala
						limpar_bala(Xb3);
						if(Xb>8&&Des1==0&&muv>15)
							limpar_bala(Xb);
						if(Xb2>8&&Des2==0&&muv>31)
							limpar_bala(Xb2);
						if(Xb4>8&&Des4==0&&muv>52)
							limpar_bala(Xb4);
						Des3=1;
						Sleep(300);
						//////////////////////////bala
						if(Des1==0&&muv>15)
							Xb-=8;
						if(Des2==0&&muv>31)
							Xb2-=8;
						if(Des3==0&&muv>39)
							Xb3-=8;
						if(Des4==0&&muv>52)
							Xb4-=8;
						//////////////////////////bala
						if(Xb>8&&Des1==0&&muv>15)
							bala(Xb,1,1,1);
						if(Xb2>8&&Des2==0&&muv>31)
							bala2(Xb2,1,1,1);
						if(Xb3>8&&Des3==0&&muv>39)
							bala3(Xb3,1,1,1);
						if(Xb4>8&&Des4==0&&muv>52)
							bala4(Xb4,1,1,1);
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
					}
					if(Xb4==16&&speed>=800&&Des4==0)
					{
						if(speed<300)
						progresso++;
						else
							if(speed<600)
								progresso+=2;
						else
							progresso+=3;
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
						speed-=200;
						muv++;
	//					Sleep(300);
						//////////////////////////bala
						if(Xb>8&&Des1==0&&muv>15)
							limpar_bala(Xb);
						if(Xb2>8&&Des2==0&&muv>31)
							limpar_bala(Xb2);
						if(Xb3>8&&Des3==0&&muv>39)
							limpar_bala(Xb3);
						if(Xb4>8&&Des4==0&&muv>52)
							limpar_bala(Xb4);
						//////////////////////////bala
						if(Des1==0&&muv>15)
							Xb-=8;
						if(Des2==0&&muv>31)
							Xb2-=8;
						if(Des3==0&&muv>39)
							Xb3-=8;
						if(Des4==0&&muv>52)
							Xb4-=8;
						//////////////////////////bala
						bala4(Xb4,1,1,1);
						if(Xb>8&&Des1==0&&muv>15)
							bala(Xb,1,1,1);
						if(Xb3>8&&Des3==0&&muv>39)
							bala3(Xb3,1,1,1);
						if(Xb2>8&&Des2==0&&muv>31)
							bala2(Xb2,1,1,1);
						Sleep(300);
						//////////////////////////bala
						limpar_bala(Xb4);
						if(Xb>8&&Des1==0&&muv>15)
							limpar_bala(Xb);
						if(Xb2>8&&Des2==0&&muv>31)
							limpar_bala(Xb2);
						if(Xb3>8&&Des3==0&&muv>39)
							limpar_bala(Xb3);
						Des4=1;
						Sleep(300);
						//////////////////////////bala
						if(Des1==0&&muv>15)
							Xb-=8;
						if(Des2==0&&muv>31)
							Xb2-=8;
						if(Des3==0&&muv>39)
							Xb3-=8;
						if(Des4==0&&muv>52)
							Xb4-=8;
						//////////////////////////bala
						if(Xb>8&&Des1==0&&muv>15)
							bala(Xb,1,1,1);
						if(Xb2>8&&Des2==0&&muv>31)
							bala2(Xb2,1,1,1);
						if(Xb3>8&&Des3==0&&muv>39)
							bala3(Xb3,1,1,1);
						if(Xb4>8&&Des4==0&&muv>52)
							bala4(Xb4,1,1,1);
						limpar_flash1e3(11,20);
						limpar_flash2e4(11,20);
						if(muv%4==0)
						{
							animaflash4(11,20);
						}
						else 	if((muv+1)%4==0)
								{
									animaflash3(11,20);		
								}	
						else 	if((muv+2)%4==0)
								{
									animaflash2(11,20);		
								}
						else 	if((muv+3)%4==0)
								{
									animaflash1(11,20);		
								}
					}
					break;
				default:
					break;
			}
			if(speed<300&&progresso+1>=108)
				ganhar=1;
			else
				if(speed<600&&progresso+2>=108)
					ganhar=1;
			else
				if(speed>=900&&progresso+3>=108)
					ganhar=1;
			if (vida==0)
			{
				perder=1;
				ganhar=0;
			}
			tela_flash(speed, vida, progresso);
		}while(ganhar==0&&perder==0);
		if (ganhar==1)
		{
			vitoria(3,10,4,14);
			textcolor(12);
			gotoxy(10,30);printf("Deseja jogar novamente(S/N)? ");
			cursor(1);
			do
			{
				gotoxy(39,30);op=getche();
				gotoxy(10,33);printf("                           ");
				if(op!='s'&& op!='S'&& op!='n'&& op!='N')
				{
					gotoxy(10,33);printf("Resposta inv%clida, redigite",160);
					gotoxy(39,30);printf(" ");
				}
			}while(op!='s'&& op!='S'&& op!='n'&& op!='N');
			if (op=='n'|| op== 'N')
				return;
		}
		
		if (perder==1)
		{
			derrota(3,10,4,14);
			textcolor(12);
			gotoxy(10,30);printf("Deseja jogar novamente(S/N)? ");
			cursor(1);
			do
			{
				gotoxy(39,30);op=getche();
				gotoxy(10,33);printf("                           ");
				if(op!='s'&& op!='S'&& op!='n'&& op!='N')
				{
					gotoxy(10,33);printf("Resposta inv%clida, redigite",160);
					gotoxy(39,30);printf(" ");
				}
			}while(op!='s'&& op!='S'&& op!='n'&& op!='N');
			if (op=='n'|| op== 'N')
				return;
		}
	}while(true);
}

//----------------------------------------------------------------------------------------------------------------------------------

void instrucao_flash()
{
	char e;
	textbackground(15);
	textcolor(12);
	system("cls");
	cursor(0);
	gotoxy(20,10); printf("Instru%c%ces",135,228);
	textcolor(4);
	gotoxy(20,12); printf("Use > para perseguir o carro.");
	gotoxy(20,13); printf("Desvie das paredes, usando seus poderes: subir a parede ou atravessar objeto.");
	gotoxy(20,14); printf("Para subir a parede use /\\ e para atravessar objeto tecle o enter.");
	gotoxy(20,15); printf("Desvie da bala usando seu poder de atravessar objetos.");
	gotoxy(20,16); printf("Quando o nome do poder estiver em cinza, n%co h%c velocidade suficiente para us%c-lo.",198,160,160);
	gotoxy(20,17); printf("Quando o nome do poder estiver em vermelho, voc%c pode us%c-lo.",136,160);
	gotoxy(20,18); printf("N%co deixe as paredes e as balas baterem no flash, voc%c tem tr%cs vidas.",198,136,136);
	gotoxy(20,19); printf("Chegue at%c o final para vencer, h%c uma barra indicando seu progresso.",130,160);
	textcolor(0);
	gotoxy(20,22); printf("Aperte enter para continuar e esc para escolher outro jogo.");
	do
	{
		e=getch();
		switch(e)
		{
			case 13:
				jogo_flash();
				break;
			case 27:
				return;
				break;
			default:
				break;
		}
	}while(e!=13);
}

//----------------------------------------------------------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////// asteroides ///////////////////////////////////////////////////

void limpar_asteroide (int x,int y)
{
	textcolor(15);
	textbackground(15);
	  gotoxy(x+2,y);printf("#####");            //105
	gotoxy(x,y+1);printf("########");
	gotoxy(x,y+2);printf("#######");
	  gotoxy(x+2,y+3);printf("####");
}

//----------------------------------------------------------------------------------------------------------------------------------

void asteroide1 (int x,int y)
{
	textcolor(8);
	textbackground(8);
	  gotoxy(x+2,y);printf("#####");            //105
	gotoxy(x,y+1);printf("########");
	gotoxy(x,y+2);printf("#######");
	  gotoxy(x+2,y+3);printf("####");
}

//----------------------------------------------------------------------------------------------------------------------------------

void asteroide2 (int x,int y)
{
	textcolor(8);
	textbackground(8);
	  gotoxy(x+2,y);printf("#####");            //105
	gotoxy(x,y+1);printf("########");
	gotoxy(x,y+2);printf("#######");
	  gotoxy(x+2,y+3);printf("####");
}

//----------------------------------------------------------------------------------------------------------------------------------

void asteroide3 (int x,int y)
{
	textcolor(8);
	textbackground(8);
	  gotoxy(x+2,y);printf("#####");            //105
	gotoxy(x,y+1);printf("########");
	gotoxy(x,y+2);printf("#######");
	  gotoxy(x+2,y+3);printf("####");
}

//----------------------------------------------------------------------------------------------------------------------------------

void asteroide4 (int x,int y)
{
	textcolor(8);
	textbackground(8);
	  gotoxy(x+2,y);printf("#####");            //105
	gotoxy(x,y+1);printf("########");
	gotoxy(x,y+2);printf("#######");
	  gotoxy(x+2,y+3);printf("####");
}

//----------------------------------------------------------------------------------------------------------------------------------

void asteroide5 (int x,int y)
{
	textcolor(8);
	textbackground(8);
	  gotoxy(x+2,y);printf("#####");            //105
	gotoxy(x,y+1);printf("########");
	gotoxy(x,y+2);printf("#######");
	  gotoxy(x+2,y+3);printf("####");
}

//----------------------------------------------------------------------------------------------------------------------------------

void asteroide6 (int x,int y)
{
	textcolor(8);
	textbackground(8);
	  gotoxy(x+2,y);printf("#####");            //105
	gotoxy(x,y+1);printf("########");
	gotoxy(x,y+2);printf("#######");
	  gotoxy(x+2,y+3);printf("####");
}

//----------------------------------------------------------------------------------------------------------------------------------

void asteroide7 (int x,int y)
{
	textcolor(8);
	textbackground(8);
	  gotoxy(x+2,y);printf("#####");            //105
	gotoxy(x,y+1);printf("########");
	gotoxy(x,y+2);printf("#######");
	  gotoxy(x+2,y+3);printf("####");
}

//----------------------------------------------------------------------------------------------------------------------------------

void asteroide8 (int x,int y)
{
	textcolor(8);
	textbackground(8);
	  gotoxy(x+2,y);printf("#####");            //105
	gotoxy(x,y+1);printf("########");
	gotoxy(x,y+2);printf("#######");
	  gotoxy(x+2,y+3);printf("####");
}

//----------------------------------------------------------------------------------------------------------------------------------

void asteroide9 (int x,int y)
{
	textcolor(8);
	textbackground(8);
	  gotoxy(x+2,y);printf("#####");            //105
	gotoxy(x,y+1);printf("########");
	gotoxy(x,y+2);printf("#######");
	  gotoxy(x+2,y+3);printf("####");
}

//----------------------------------------------------------------------------------------------------------------------------------

void asteroide10 (int x,int y)
{
	textcolor(8);
	textbackground(8);
	  gotoxy(x+2,y);printf("#####");            //105
	gotoxy(x,y+1);printf("########");
	gotoxy(x,y+2);printf("#######");
	  gotoxy(x+2,y+3);printf("####");
}

//----------------------------------------------------------------------------------------------------------------------------------

void asteroide11 (int x,int y)
{
	textcolor(8);
	textbackground(8);
	  gotoxy(x+2,y);printf("#####");            //105
	gotoxy(x,y+1);printf("########");
	gotoxy(x,y+2);printf("#######");
	  gotoxy(x+2,y+3);printf("####");
}

//----------------------------------------------------------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////////// animação explosão  //////////////////////////////////

void explosao (int x, int y)
{
	textcolor(8);
	textbackground(8);
	gotoxy(x,y);printf("##");            //105
	gotoxy(x+5,y+1);printf("#");
	gotoxy(x+3,y+2);printf("#####");
	gotoxy(x+4,y+3);printf("##");
	Sleep(100);
	textcolor(15);
	textbackground(15);
	gotoxy(x,y);printf("##");            //105
	gotoxy(x+5,y+1);printf("#");
	gotoxy(x+3,y+2);printf("#####");
	gotoxy(x+4,y+3);printf("##");
}

//----------------------------------------------------------------------------------------------------------------------------------

void laser1(int y, int Y, int X,int *des, int ap)
{
	y+=2;
	textcolor(12);
	textbackground(15);
	if(y-2!=Y)
		for (int x=23; x<115; x++)
		{
			gotoxy(x,y);printf("-");
			Sleep(20);
			gotoxy(x,y);printf(" ");
		}
	if (y-2==Y&&*des==0&&ap==1)
	{
		for (int x=23; x<X; x++)
		{
			gotoxy(x,y);printf("-");
			Sleep(20);
			gotoxy(x,y);printf(" ");
			
		}
		limpar_asteroide(X,Y);
		*des=1;
		explosao(X,Y);
	}
}

//----------------------------------------------------------------------------------------------------------------------------------

void jogo_superman()
 {
 	do
 	{
 		textbackground(15);
 		system("cls");
	 	cursor(0);
	 	/////////////////////// ganhar e perder //////////////////////////	
	 	
	 	int perder=0;
	 	int ganhar=0;
	 	
	 	///////////////////////já apareceu asteroides //////////////////////////
	 	
	 	int ap1=0;
	 	int ap2=0;
	 	int ap3=0;
	 	int ap4=0;
	 	int ap5=0;
	 	int ap6=0;   //10 vezes
	 	int ap7=0;
	 	int ap8=0;
	 //	int ap9=0;
	 	int ap10=0;
	 	int ap11=0;
	 	
	 	///////////////////////posição asteroides //////////////////////////
	 	
	 	int y=10;
	 	int Y1=20;
	 	int X1=105;
	 	int Y2=5;
	 	int X2=105;
	 	int Y3=25;
	 	int X3=105;
	 	int Y4=10;
	 	int X4=105;
	 	int Y5=15;
	 	int X5=105;
	 	int Y6=5;
	 	int X6=105;
	 	int Y7=15;
	 	int X7=105;
	 	int Y8=5;
	 	int X8=105;
	 //	int Y9=25;
	 //	int X9=105;
	 	int Y10=10;
	 	int X10=105;
	 	int Y11=20;
	 	int X11=105;
	 	///////////////////////movimentos //////////////////////////
	 	
	 	int muv=0;
	 	
	 	///////////////////////número asteroides //////////////////////////
	 	int num_ast=1;
	 	
	 	///////////////////////se foi destruído //////////////////////////
	 	int des1=0;
	 	int des2=0;
	 	int des3=0;
	 	int des4=0;
	 	int des5=0;
	 	int des6=0;   //10 vezes
	 	int des7=0;
	 	int des8=0;
	 //	int des9=0;
	 	int des10=0;
	 	int des11=0;
	 	
	 	/////////////////////// jogabilidade //////////////////////////
	 	
	 	char a;			//25 posição asteroide está perder
	 	char op;
	 	animasuperman1(8,y);
	 	asteroide1(X1,Y1);
	 	do
	 	{
	 		a=getch();
	 		limpar_superman1(8,y);
	 		limpar_superman2(8,y);
	 		limpar_superman3(8,y);
			switch(a)
			{
				case 72: //seta para cima
					y-=5;  
					if(y<5)
						y=5;
					animasuperman2(8,y);
					if (des1==0)
						limpar_asteroide(X1,Y1);
					if (des2==0)
						limpar_asteroide(X2,Y2);
					if (des3==0)
						limpar_asteroide(X3,Y3);
					if (des4==0)
						limpar_asteroide(X4,Y4);
					if (des5==0)
						limpar_asteroide(X5,Y5);
					if (des6==0)
						limpar_asteroide(X6,Y6);
					if (des7==0)
						limpar_asteroide(X7,Y7);
					if (des8==0)
						limpar_asteroide(X8,Y8);
			//		if (des9==0)
			//			limpar_asteroide(X9,Y9);
					if (des10==0)
						limpar_asteroide(X10,Y10);
					if (des11==0)
						limpar_asteroide(X11,Y11);
					muv++;
					if (muv==4)
						num_ast++;
						
					if(des1==0)
					{
						X1-=8;
						asteroide1(X1,Y1);
						ap1=1;
					}
					if(des2==0&&muv>3)
					{
						X2-=8;
						asteroide2(X2,Y2);
						ap2=1;
					}
					if(des3==0&&muv>6)
					{
						X3-=8;
						asteroide3(X3,Y3);
						ap3=1;
					}
					if(des4==0&&muv>9)
					{
						X4-=8;
						asteroide4(X4,Y4);
						ap4=1;
					}
					if(des5==0&&muv>9)
					{
						X5-=8;
						asteroide5(X5,Y5);
						ap5=1;
					}
					if(des6==0&&muv>11)
					{
						X6-=8;
						asteroide3(X6,Y6);
						ap6=1;
					}
					if(des7==0&&muv>13)
					{
						X7-=8;
						asteroide3(X7,Y7);
						ap7=1;
					}
					if(des8==0&&muv>14)
					{
						X8-=8;
						asteroide3(X8,Y8);
						ap8=1;
					}
	//				if(des9==0&&muv>14)
	//				{
	//					X9-=8;
	//					asteroide3(X9,Y9);
	//				}
					if(des10==0&&muv>15)
					{
						X10-=8;
						asteroide3(X10,Y10);
						ap10=1;
					}
					if(des11==0&&muv>15)
					{
						X11-=8;
						asteroide3(X11,Y11);
						ap11=1;
					}
					if(des1==1&&des2==1&&des3==1&&des4==1&&des5==1&&des6==1&&des7==1&&des8==1&&des10==1&&des11==1)
					{
						ganhar=1;
					}
					if(X1<25&&des1==0)
					{
						perder=1;
					}	
					if(X2<25&&des2==0)
						perder=1;
					if(X3<25&&des3==0)
						perder=1;
					if(X4<25&&des4==0)	
						perder=1;
					if(X5<25&&des5==0)	
						perder=1;
					if(X6<25&&des6==0)	
						perder=1;
					if(X7<25&&des7==0)	
						perder=1;
					if(X8<25&&des8==0)	
						perder=1;
					if(X10<25&&des10==0)	
						perder=1;
					if(X11<25&&des11==0)	
						perder=1;
					break;
				case 80: //seta para baixo
					y+=5; 
					if(y>30)
						y=30;
					if (des1==0)
						limpar_asteroide(X1,Y1);
					if (des2==0)
						limpar_asteroide(X2,Y2);
					if (des3==0)
						limpar_asteroide(X3,Y3);
					if (des4==0)
						limpar_asteroide(X4,Y4);
					if (des5==0)
						limpar_asteroide(X5,Y5);
					if (des6==0)
						limpar_asteroide(X6,Y6);
					if (des7==0)
						limpar_asteroide(X7,Y7);
					if (des8==0)
						limpar_asteroide(X8,Y8);
		//			if (des9==0)
		//				limpar_asteroide(X9,Y9);
					if (des10==0)
						limpar_asteroide(X10,Y10);
					if (des11==0)
						limpar_asteroide(X11,Y11);
					X1-=8;
					if (muv==4)
						num_ast++;
					animasuperman3(8,y);
					muv++;
										if(des1==0)
					{
						X1-=8;
						asteroide1(X1,Y1);
						ap1=1;
					}
					if(des2==0&&muv>3)
					{
						X2-=8;
						asteroide2(X2,Y2);
						ap2=1;
					}
					if(des3==0&&muv>6)
					{
						X3-=8;
						asteroide3(X3,Y3);
						ap3=1;
					}
					if(des4==0&&muv>9)
					{
						X4-=8;
						asteroide4(X4,Y4);
						ap4=1;
					}
					if(des5==0&&muv>9)
					{
						X5-=8;
						asteroide5(X5,Y5);
						ap5=1;
					}
					if(des6==0&&muv>11)
					{
						X6-=8;
						asteroide3(X6,Y6);
						ap6=1;
					}
					if(des7==0&&muv>13)
					{
						X7-=8;
						asteroide3(X7,Y7);
						ap7=1;
					}
					if(des8==0&&muv>14)
					{
						X8-=8;
						asteroide3(X8,Y8);
						ap8=1;
					}
	//				if(des9==0&&muv>14)
	//				{
	//					X9-=8;
	//					asteroide3(X9,Y9);
	//				}
					if(des10==0&&muv>15)
					{
						X10-=8;
						asteroide3(X10,Y10);
						ap10=1;
					}
					if(des11==0&&muv>15)
					{
						X11-=8;
						asteroide3(X11,Y11);
						ap11=1;
					}
					if(des1==1&&des2==1&&des3==1&&des4==1&&des5==1&&des6==1&&des7==1&&des8==1&&des10==1&&des11==1)
						ganhar=1;
					if(X1<25&&des1==0)
						perder=1;
					if(X2<25&&des2==0)
						perder=1;
					if(X3<25&&des3==0)
						perder=1;
					if(X4<25&&des4==0)	
						perder=1;
					if(X5<25&&des5==0)	
						perder=1;
					if(X6<25&&des6==0)	
						perder=1;
					if(X7<25&&des7==0)	
						perder=1;
					if(X8<25&&des8==0)	
						perder=1;
					if(X10<25&&des10==0)	
						perder=1;
					if(X11<25&&des11==0)	
						perder=1;
					break;
				case 13:  //enter
					animasuperman1(8,y);
					if (muv==4)
						num_ast++;
					else if(y==Y1&&des1==0)
							laser1(y, Y1,X1, &des1,ap1);
					else	if(y==Y2&&des2==0)
							laser1(y, Y2,X2, &des2,ap2);
					else	if(y==Y3&&des3==0)
							laser1(y, Y3,X3, &des3,ap3);
					else	if(y==Y4&&des4==0)
							laser1(y, Y4,X4, &des4,ap4);
					else	if(y==Y5&&des5==0)
							laser1(y, Y5,X5, &des5,ap5);
					else	if(y==Y6&&des6==0)
							laser1(y, Y6,X6, &des6,ap6);
					else	if(y==Y7&&des7==0)
							laser1(y, Y7,X7, &des7,ap7);
					else	if(y==Y8&&des8==0)
							laser1(y, Y8,X8, &des8,ap8);
				//	else	if(y==Y9&&des9==0)
				//			laser1(y, Y9,X9, &des9);
					else	if(y==Y10&&des10==0)
							laser1(y, Y10,X10, &des10,ap10);
					else	if(y==Y11&&des11==0)
							laser1(y, Y11,X11, &des11,ap11);
					else
						laser1(y, Y1,X1, &des1, ap1);
					if (des1==0)
						limpar_asteroide(X1,Y1);
					if (des2==0)
						limpar_asteroide(X2,Y2);
					if (des3==0)
						limpar_asteroide(X3,Y3);
					if (des4==0)
						limpar_asteroide(X4,Y4);
					if (des5==0)
						limpar_asteroide(X5,Y5);
					if (des6==0)
						limpar_asteroide(X6,Y6);
					if (des7==0)
						limpar_asteroide(X7,Y7);
					if (des8==0)
						limpar_asteroide(X8,Y8);
		//			if (des9==0)
		//				limpar_asteroide(X9,Y9);
					if (des10==0)
						limpar_asteroide(X10,Y10);
					if (des11==0)
						limpar_asteroide(X11,Y11);
					X1-=8;
					muv++;
					if(des1==0)
					{
						X1-=8;
						asteroide1(X1,Y1);
						ap1=1;
					}
					if(des2==0&&muv>3)
					{
						X2-=8;
						asteroide2(X2,Y2);
						ap2=1;
					}
					if(des3==0&&muv>6)
					{
						X3-=8;
						asteroide3(X3,Y3);
						ap3=1;
					}
					if(des4==0&&muv>9)
					{
						X4-=8;
						asteroide4(X4,Y4);
						ap4=1;
					}
					if(des5==0&&muv>9)
					{
						X5-=8;
						asteroide5(X5,Y5);
						ap5=1;
					}
					if(des6==0&&muv>11)
					{
						X6-=8;
						asteroide3(X6,Y6);
						ap6=1;
					}
					if(des7==0&&muv>13)
					{
						X7-=8;
						asteroide3(X7,Y7);
						ap7=1;
					}
					if(des8==0&&muv>14)
					{
						X8-=8;
						asteroide3(X8,Y8);
						ap8=1;
					}
	//				if(des9==0&&muv>14)
	//				{
	//					X9-=8;
	//					asteroide3(X9,Y9);
	//				}
					if(des10==0&&muv>15)
					{
						X10-=8;
						asteroide3(X10,Y10);
						ap10=1;
					}
					if(des11==0&&muv>15)
					{
						X11-=8;
						asteroide3(X11,Y11);
						ap11=1;
					}
					if(des1==1&&des2==1&&des3==1&&des4==1&&des5==1&&des6==1&&des7==1&&des8==1&&des10==1&&des11==1)
						ganhar=1;
					if(X1<25&&des1==0)
						perder=1;
					if(X2<25&&des2==0)
						perder=1;
					if(X3<25&&des3==0)
						perder=1;
					if(X4<25&&des4==0)	
						perder=1;
					if(X5<25&&des5==0)	
						perder=1;
					if(X6<25&&des6==0)	
						perder=1;
					if(X7<25&&des7==0)	
						perder=1;
					if(X8<25&&des8==0)	
						perder=1;
					if(X10<25&&des10==0)	
						perder=1;
					if(X11<25&&des11==0)	
						perder=1;
					break;
				default:
					animasuperman1(8,y);
					if(des1==1&&des2==1&&des3==1&&des4==1&&des5==1&&des6==1&&des7==1&&des8==1&&des10==1&&des11==1)
						ganhar=1;
					if(X1<25&&des1==0)
						perder=1;
					if(X2<25&&des2==0)
						perder=1;
					if(X3<25&&des3==0)
						perder=1;
					if(X4<25&&des4==0)	
						perder=1;
					if(X5<25&&des5==0)	
						perder=1;
					if(X6<25&&des6==0)	
						perder=1;
					if(X7<25&&des7==0)	
						perder=1;
					if(X8<25&&des8==0)	
						perder=1;
					if(X10<25&&des10==0)	
						perder=1;
					if(X11<25&&des11==0)	
						perder=1;
					break;
			}
		}while(ganhar==0&&perder==0);
		if (ganhar==1)
		{
			vitoria(3,10,11,12);
			textcolor(4);
			gotoxy(10,30);printf("Deseja jogar novamente(S/N)? ");
			cursor(1);
			do
			{
				gotoxy(39,30);op=getche();
				gotoxy(10,33);printf("                           ");
				if(op!='s'&& op!='S'&& op!='n'&& op!='N')
				{
					gotoxy(10,33);printf("Resposta inv%clida, redigite",160);
					gotoxy(39,30);printf(" ");
				}
			}while(op!='s'&& op!='S'&& op!='n'&& op!='N');
			if (op=='n'|| op== 'N')
				return;
		}
		
		if (perder==1)
		{
			derrota(3,10,11,12);
			textcolor(4);
			gotoxy(10,30);printf("Deseja jogar novamente(S/N)? ");
			cursor(1);
			do
			{
				gotoxy(39,30);op=getche();
				gotoxy(10,33);printf("                           ");
				if(op!='s'&& op!='S'&& op!='n'&& op!='N')
				{
					gotoxy(10,33);printf("Resposta inv%clida, redigite",160);
					gotoxy(39,30);printf(" ");
				}
			}while(op!='s'&& op!='S'&& op!='n'&& op!='N');
			if (op=='n'|| op== 'N')
				return;
		}
	}while(true);
 }
 
//----------------------------------------------------------------------------------------------------------------------------------

void instrucao_superman()
{
	char e;
	textbackground(15);
	textcolor(12);
	system("cls");
	cursor(0);
	gotoxy(20,10); printf("Instru%c%ces",135,228);
	textcolor(9);
	gotoxy(20,12); printf("Use /\\ e \\/ para mover o Superman.");
	gotoxy(20,13); printf("Aperter enter para destruir os meteoros.");
	gotoxy(20,14); printf("N%co deixe nenhum meteoro chegar na borda, ou voc%c perde.",198,136);
	gotoxy(20,15); printf("Destrua todos os meteoros para vencer.");
	textcolor(0);
	gotoxy(20,18); printf("Aperte enter para continuar e esc para escolher outro jogo.");
	do
	{
		e=getch();
		switch(e)
		{
			case 13:
				jogo_superman();
				break;
			case 27:
				return;
				break;
			default:
				break;
		}
	}while(e!=13);
}

//----------------------------------------------------------------------------------------------------------------------------------

void shield(int x, int y)
{
	textbackground(15);
	textcolor(0);
	gotoxy(x,y-2);printf("          ____________ ");
	gotoxy(x,y-1);printf("       _.-            -._");
	gotoxy(x,y);printf("     .-        ____      -.");
	gotoxy(x,y+1);printf("   .-         /    \\      -.");
	gotoxy(x,y+2);printf("  /  -.      /    -.\\   .-  \\");
	gotoxy(x,y+3);printf(" / /   -.   /     \\   .-  \\  \\");
	gotoxy(x,y+4);printf("| /-.    -./       \\.-   .-\\ |");
	gotoxy(x,y+5);printf("|/   -.                .-   \\|");
	gotoxy(x,y+6);printf("/   /  -.             .- \\   \\");
	gotoxy(x,y+7);printf("|  / /   -.         .-  \\ \\  |");
	gotoxy(x,y+8);printf(" \\/ /   /  -.     .- \\   \\ \\/");
	gotoxy(x,y+9);printf("  \\/   / /   -. .-  \\ \\   \\/");
	gotoxy(x,y+10);printf("   \\  / /   /  . \\   \\ \\  /");
	gotoxy(x,y+11);printf("    \\/_/   / /  \\ \\   \\_\\/");
	gotoxy(x,y+12);printf("       -._/ /    \\ \\_.-");
	gotoxy(x,y+13);printf("          --.____.--");	
}

//----------------------------------------------------------------------------------------------------------------------------------

void jogos()
{
	char c;
	int a=17;
	int sair;
	cursor(0);
	
	do
	{
		sair=1;
		textbackground(15);
		textcolor(9);
		textbackground(15);
		logo_nome(57,1);
		textbackground(11);
		gotoxy(2,2);printf("                                                    ");
		gotoxy(68,2);printf("                                                    ");
		gotoxy(2,39);printf("                                                                                                                      ");
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(2,i);printf(" ");
		}
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(119,i);printf(" ");
		}
		textbackground(15);
		for(int i=10; i<=29; i++)
		{
			textbackground(0);
			gotoxy(42,i);printf(" ");
		}
		for(int j=10; j<=29; j++)
		{
			textbackground(0);
			gotoxy(78,j);printf(" ");
		}
		for(int x=42; x<=78; x++)
		{
			textbackground(0);
			gotoxy(x,10);printf(" ");
		}
		for(int x=42; x<=78; x++)
		{
			textbackground(0);
			gotoxy(x,29);printf(" ");
		}
		textbackground(15);
		textcolor(12);
		setlocale(LC_ALL,"C");
		textcolor(8);
		for(int i=57; i<=63; i++)
		{
			textcolor(8);
			gotoxy(i,13);printf("%c",196);
			gotoxy(i,15);printf("%c",196);
		}
		setlocale(LC_ALL,NULL);
		shield(7,14);
		shield(84,14);
		textcolor(9);
		gotoxy(58,14);printf("JOGOS");
		textcolor(1);
		gotoxy(51,17);printf("Superman");
		           //135 é o caractere 'ç' e 198 é o caractere 'ã'
		gotoxy(51,19);printf("Flash");
		gotoxy(51,21);printf("Batwoman");
		gotoxy(51,23);printf("Capit%c Marvel",198);
		gotoxy(51,25);printf("Voltar");
		gotoxy(49,a); printf("%c", 62);//62 é o caractere '>'
		c=getch();
		gotoxy(49,a); printf(" ");
	
		switch(c)//movimento das setas
		{
			case 72 : //seta para cima
				a-=2;
				if(a<17)
				{
					a=25;	
				}
				gotoxy(49,a); printf("%c", 62);
				break;
			case 80 : //seta para baixo
				a+=2;
				if(a>25)
				{
					a=17;
				}
				gotoxy(49,a); printf("%c", 62);
				break;
			case 13: //teclou enter
				if(a==17)
				{ 
					system("cls");
					instrucao_superman();
					textbackground(15);
					system("cls");
				}
				else
				if(a==19)
				{
					system("cls");
					instrucao_flash();
					textbackground(15);
					system("cls");
				}
				else
				if(a==21)
				{
					system("cls");
					instrucao_batwoman();
					textbackground(15);
					system("cls");
				}
				else
				if(a==23)
				{
					system("cls");
					instrucao_capita_mavel();
					textbackground(15);
					system("cls");
				}
				else
				if(a==25)
				{
					system("cls");
					sair=0;
				}
		}//final switch(c)
	}while(sair); //final do while
	return;
} 

//-----------------------------------------------------------------------------------------------------------------------------

void limpar_ligadajustica(int x, int y)
{
	textbackground(15);
	textcolor(15);
	//////// linha 1
	gotoxy(x+14,y);printf("######");
	//////// linha 2
	gotoxy(x+13,y+1);printf("#");
	////////// linha 3
	gotoxy(x,y+2);printf("#######################");
	//////// linha 3
	gotoxy(x+13,y+3);printf("#");
	//////// linha 4
	gotoxy(x+14,y+4);printf("######");
}

//-----------------------------------------------------------------------------------------------------------------------------

void animaligadajustica(int x, int y)
{
	textbackground(15);
	textcolor(14);
	//////// linha 1
	gotoxy(x+14,y);printf("######");
	//////// linha 2
	gotoxy(x+13,y+1);printf("#");
	////////// linha 3
	gotoxy(x,y+2);printf("#######################");
	//////// linha 3
	gotoxy(x+13,y+3);printf("#");
	//////// linha 4
	gotoxy(x+14,y+4);printf("######");
}

//-----------------------------------------------------------------------------------------------------------------------------

void limpar_vingadores4(int x, int y)
{
	/////coluna 1/////  homem-aranha
	if(x-24>0)
	{
		textcolor(15);
		gotoxy(x-24,y+4);printf("#");
	}
	/////coluna 2/////  homem-aranha
	if(x-23>0)
	{
		textcolor(15);
		gotoxy(x-23,y+4);printf("#");
	}
	////coluna 3 ///////////  homem-aranha
	if(x-22>0)
	{
		textcolor(15);
		gotoxy(x-22,y+4);printf("#");
		textcolor(15);
		gotoxy(x-22,y+6);printf("#");
	}
	////coluna 4 ///////////  homem-aranha
	if(x-21>0)
	{
		textcolor(15);
		gotoxy(x-21,y+4);printf("#");
		textcolor(15);
		gotoxy(x-21,y+5);printf("#");
	}
	////coluna 5 ///////////  homem-aranha
	if(x-20>0)
	{
		textcolor(15);
		gotoxy(x-20,y+4);printf("#");
	}
	
	////coluna 6 ///////////   homem-aranha
	if(x-19>0)
	{
		textcolor(15);
		gotoxy(x-19,y+4);printf("#");
	}
	////coluna 7 ///////////   homem-aranha
	if(x-18>0)
	{
		textcolor(15);
		gotoxy(x-18,y+4);printf("#");
	}
	
	////coluna 8 ///////////  homem-aranha
	if(x-17>0)
	{
		textcolor(15);
		gotoxy(x-17,y+4);printf("#");
	}
	
	////coluna 9 ///////////  homem-aranha
	if(x-16>0)
	{
		textcolor(15);
		gotoxy(x-16,y+4);printf("#");
	}
	
	////coluna 10 ///////////  homem-aranha
	if(x-15>0)
	{
		textcolor(15);
		gotoxy(x-15,y+4);printf("#");
		textcolor(15);
		gotoxy(x-15,y+2);printf("#");
	}
	////coluna 11 ///////////   homem-aranha
	if(x-14>0)
	{
		textcolor(15);
		gotoxy(x-14,y+3);printf("#");
		textcolor(15);
		gotoxy(x-14,y+1);printf("#");
	}
	////coluna 12 ///////////   homem-aranha
	if(x-13>0)
	{
		textcolor(15);
		gotoxy(x-13,y+3);printf("#");
		textcolor(15);
		gotoxy(x-13,y+1);printf("#");
	}
	////coluna 13 ///////////  homem-aranha
	if(x-12>0)
	{
		textcolor(15);
		gotoxy(x-12,y+3);printf("#");
		textcolor(15);
		gotoxy(x-12,y+2);printf("#");
	}
	/////coluna 14 /////////  homem-aranha
	if(x-11>0)
	{
		textcolor(15);
		gotoxy(x-11,y+3);printf("#");
	}
	
	/////coluna 15 /////////  homem-aranha
	if(x-10>0)
	{
		textcolor(15);
		gotoxy(x-10,y+3);printf("#");
	}
	
	/////coluna 16 /////////  homem-aranha
	if(x-9>0)
	{
		textcolor(15);
		gotoxy(x-9,y+3);printf("#");
	}
	
	/////coluna 17 /////////  homem-aranha
	if(x-8>0)
	{
		textcolor(15);
		gotoxy(x-8,y+3);printf("#");
		gotoxy(x-8,y+4);printf("\\");
	}
	
	/////coluna 18 /////////  teia
	if(x-7>0)
	{
		textcolor(15);
		gotoxy(x-7,y+4);printf("_");
	}
	
	/////coluna 19 /////////  teia
	if(x-6>0)
	{
		textcolor(15);
		gotoxy(x-6,y+4);printf("_");
	}
	
	/////coluna 20 /////////  teia
	if(x-5>0)
	{
		textcolor(15);
		gotoxy(x-5,y+4);printf("_");
	}
	/////coluna 21 /////////  teia
	if(x-4>0)
	{
		textcolor(15);
		gotoxy(x-4,y+4);printf("_");
	}
	/////coluna 22 /////////  teia
	if(x-3>0)
	{
		textcolor(15);
		gotoxy(x-3,y+4);printf("_");
	}
	
	/////coluna 23 /////////  teia
	if(x-2>0)
	{
		textcolor(15);
		gotoxy(x-2,y+4);printf("_");
	}
	
	/////coluna 24 /////////  teia
	if(x-1>0)
	{
		textcolor(15);
		gotoxy(x-1,y+4);printf("X");
	}
	
	/////coluna 25////////// martelo
	if(x>0)
	{
		textcolor(15);
		gotoxy(x,y+4);printf("#");
	}
	
	/////coluna 26////////// martelo
	if(x+1>0)
	{
		textcolor(15);
		gotoxy(x+1,y+4);printf("#");
	}
	
	/////coluna 27////////// martelo
	if(x+2>0)
	{
		textcolor(15);
		gotoxy(x+2,y+4);printf("#");
	}
	
		/////coluna 28////////// martelo
	if(x+3>0)
	{
		textcolor(15);
		gotoxy(x+3,y+4);printf("#");
	}
	
		/////coluna 29////////// martelo
	if(x+4>0)
	{
		textcolor(15);
		gotoxy(x+4,y+4);printf("#");
	}
	
		/////coluna 30////////// martelo
	if(x+5>0)
	{
		textcolor(15);
		gotoxy(x+5,y+4);printf("#");
	}
	
			/////coluna 31////////// martelo
	if(x+6>0)
	{
		textcolor(15);
		gotoxy(x+6,y+4);printf("#");
	}
	
			/////coluna 32////////// martelo
	if(x+7>0)
	{
		textcolor(15);
		gotoxy(x+7,y+3);printf("#");
		gotoxy(x+7,y+4);printf("#");
		gotoxy(x+7,y+5);printf("#");
	}
			/////coluna 33////////// martelo
	if(x+8>0)
	{
		textcolor(15);
		gotoxy(x+8,y+3);printf("#");
		gotoxy(x+8,y+4);printf("#");
		gotoxy(x+8,y+5);printf("#");
	}
			/////coluna 34////////// martelo
	if(x+9>0)
	{
		textcolor(15);
		gotoxy(x+9,y+3);printf("#");
		gotoxy(x+9,y+4);printf("#");
		gotoxy(x+9,y+5);printf("#");
	}
			/////coluna 35////////// martelo
	if(x+10>0)
	{
		textcolor(15);
		gotoxy(x+10,y+3);printf("#");
		gotoxy(x+10,y+4);printf("#");
		gotoxy(x+10,y+5);printf("#");
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

void animavingadores4(int x, int y)
{
	/////coluna 1/////  homem-aranha
	if(x-24>0)
	{
		textcolor(12);
		gotoxy(x-24,y+4);printf("#");
	}
	/////coluna 2/////  homem-aranha
	if(x-23>0)
	{
		textcolor(12);
		gotoxy(x-23,y+4);printf("#");
	}
	////coluna 3 ///////////  homem-aranha
	if(x-22>0)
	{
		textcolor(9);
		gotoxy(x-22,y+4);printf("#");
		textcolor(12);
		gotoxy(x-22,y+6);printf("#");
	}
	////coluna 4 ///////////  homem-aranha
	if(x-21>0)
	{
		textcolor(9);
		gotoxy(x-21,y+4);printf("#");
		textcolor(9);
		gotoxy(x-21,y+5);printf("#");
	}
	////coluna 5 ///////////  homem-aranha
	if(x-20>0)
	{
		textcolor(9);
		gotoxy(x-20,y+4);printf("#");
	}
	
	////coluna 6 ///////////   homem-aranha
	if(x-19>0)
	{
		textcolor(12);
		gotoxy(x-19,y+4);printf("#");
	}
	////coluna 7 ///////////   homem-aranha
	if(x-18>0)
	{
		textcolor(12);
		gotoxy(x-18,y+4);printf("#");
	}
	
	////coluna 8 ///////////  homem-aranha
	if(x-17>0)
	{
		textcolor(12);
		gotoxy(x-17,y+4);printf("#");
	}
	
	////coluna 9 ///////////  homem-aranha
	if(x-16>0)
	{
		textcolor(12);
		gotoxy(x-16,y+4);printf("#");
	}
	
	////coluna 10 ///////////  homem-aranha
	if(x-15>0)
	{
		textcolor(12);
		gotoxy(x-15,y+4);printf("#");
		textcolor(12);
		gotoxy(x-15,y+2);printf("#");
	}
	////coluna 11 ///////////   homem-aranha
	if(x-14>0)
	{
		textcolor(12);
		gotoxy(x-14,y+3);printf("#");
		textcolor(12);
		gotoxy(x-14,y+1);printf("#");
	}
	////coluna 12 ///////////   homem-aranha
	if(x-13>0)
	{
		textcolor(12);
		gotoxy(x-13,y+3);printf("#");
		textcolor(12);
		gotoxy(x-13,y+1);printf("#");
	}
	////coluna 13 ///////////  homem-aranha
	if(x-12>0)
	{
		textcolor(12);
		gotoxy(x-12,y+3);printf("#");
		textcolor(12);
		gotoxy(x-12,y+2);printf("#");
	}
	/////coluna 14 /////////  homem-aranha
	if(x-11>0)
	{
		textcolor(12);
		gotoxy(x-11,y+3);printf("#");
	}
	
	/////coluna 15 /////////  homem-aranha
	if(x-10>0)
	{
		textcolor(12);
		gotoxy(x-10,y+3);printf("#");
	}
	
	/////coluna 16 /////////  homem-aranha
	if(x-9>0)
	{
		textcolor(12);
		gotoxy(x-9,y+3);printf("#");
	}
	
	/////coluna 17 /////////  homem-aranha
	if(x-8>0)
	{
		textcolor(12);
		gotoxy(x-8,y+3);printf("#");
		textcolor(7);
		gotoxy(x-8,y+4);printf("\\");
	}
	
	/////coluna 18 /////////  teia
	if(x-7>0)
	{
		textcolor(7);
		gotoxy(x-7,y+4);printf("_");
	}
	
	/////coluna 19 /////////  teia
	if(x-6>0)
	{
		textcolor(7);
		gotoxy(x-6,y+4);printf("_");
	}
	
	/////coluna 20 /////////  teia
	if(x-5>0)
	{
		textcolor(7);
		gotoxy(x-5,y+4);printf("_");
	}
	/////coluna 21 /////////  teia
	if(x-4>0)
	{
		textcolor(7);
		gotoxy(x-4,y+4);printf("_");
	}
	/////coluna 22 /////////  teia
	if(x-3>0)
	{
		textcolor(7);
		gotoxy(x-3,y+4);printf("_");
	}
	
	/////coluna 23 /////////  teia
	if(x-2>0)
	{
		textcolor(7);
		gotoxy(x-2,y+4);printf("_");
	}
	
	/////coluna 24 /////////  teia
	if(x-1>0)
	{
		textcolor(7);
		gotoxy(x-1,y+4);printf("X");
	}
	
	/////coluna 25////////// martelo
	if(x>0)
	{
		textcolor(4);
		gotoxy(x,y+4);printf("#");
	}
	
	/////coluna 26////////// martelo
	if(x+1>0)
	{
		textcolor(4);
		gotoxy(x+1,y+4);printf("#");
	}
	
	/////coluna 27////////// martelo
	if(x+2>0)
	{
		textcolor(4);
		gotoxy(x+2,y+4);printf("#");
	}
	
		/////coluna 28////////// martelo
	if(x+3>0)
	{
		textcolor(4);
		gotoxy(x+3,y+4);printf("#");
	}
	
		/////coluna 29////////// martelo
	if(x+4>0)
	{
		textcolor(4);
		gotoxy(x+4,y+4);printf("#");
	}
	
		/////coluna 30////////// martelo
	if(x+5>0)
	{
		textcolor(4);
		gotoxy(x+5,y+4);printf("#");
	}
	
			/////coluna 31////////// martelo
	if(x+6>0)
	{
		textcolor(4);
		gotoxy(x+6,y+4);printf("#");
	}
	
			/////coluna 32////////// martelo
	if(x+7>0)
	{
		textcolor(8);
		gotoxy(x+7,y+3);printf("#");
		gotoxy(x+7,y+4);printf("#");
		gotoxy(x+7,y+5);printf("#");
	}
			/////coluna 33////////// martelo
	if(x+8>0)
	{
		textcolor(8);
		gotoxy(x+8,y+3);printf("#");
		gotoxy(x+8,y+4);printf("#");
		gotoxy(x+8,y+5);printf("#");
	}
			/////coluna 34////////// martelo
	if(x+9>0)
	{
		textcolor(8);
		gotoxy(x+9,y+3);printf("#");
		gotoxy(x+9,y+4);printf("#");
		gotoxy(x+9,y+5);printf("#");
	}
			/////coluna 35////////// martelo
	if(x+10>0)
	{
		textcolor(8);
		gotoxy(x+10,y+3);printf("#");
		gotoxy(x+10,y+4);printf("#");
		gotoxy(x+10,y+5);printf("#");
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

void limpar_vingadores1e3(int x, int y)
{
	/////coluna 1/////  homem-aranha
	if(x-24>0)
	{
		textcolor(15);
		gotoxy(x-24,y+4);printf("#");
	}
	/////coluna 2/////  homem-aranha
	if(x-23>0)
	{
		textcolor(15);
		gotoxy(x-23,y+4);printf("#");
	}
	////coluna 3 ///////////  homem-aranha
	if(x-22>0)
	{
		textcolor(15);
		gotoxy(x-22,y+4);printf("#");
		textcolor(15);
		gotoxy(x-22,y+6);printf("#");
	}
	////coluna 4 ///////////  homem-aranha
	if(x-21>0)
	{
		textcolor(15);
		gotoxy(x-21,y+4);printf("#");
		textcolor(15);
		gotoxy(x-21,y+5);printf("#");
	}
	////coluna 5 ///////////  homem-aranha
	if(x-20>0)
	{
		textcolor(15);
		gotoxy(x-20,y+4);printf("#");
	}
	
	////coluna 6 ///////////   homem-aranha
	if(x-19>0)
	{
		textcolor(15);
		gotoxy(x-19,y+4);printf("#");
	}
	////coluna 7 ///////////   homem-aranha
	if(x-18>0)
	{
		textcolor(15);
		gotoxy(x-18,y+4);printf("#");
	}
	
	////coluna 8 ///////////  homem-aranha
	if(x-17>0)
	{
		textcolor(15);
		gotoxy(x-17,y+4);printf("#");
	}
	
	////coluna 9 ///////////  homem-aranha
	if(x-16>0)
	{
		textcolor(15);
		gotoxy(x-16,y+4);printf("#");
	}
	
	////coluna 10 ///////////  homem-aranha
	if(x-15>0)
	{
		textcolor(15);
		gotoxy(x-15,y+4);printf("#");
		textcolor(15);
		gotoxy(x-15,y+2);printf("#");
	}
	////coluna 11 ///////////   homem-aranha
	if(x-14>0)
	{
		textcolor(15);
		gotoxy(x-14,y+3);printf("#");
		textcolor(15);
		gotoxy(x-14,y+1);printf("#");
	}
	////coluna 12 ///////////   homem-aranha
	if(x-13>0)
	{
		textcolor(15);
		gotoxy(x-13,y+3);printf("#");
		textcolor(15);
		gotoxy(x-13,y+1);printf("#");
	}
	////coluna 13 ///////////  homem-aranha
	if(x-12>0)
	{
		textcolor(15);
		gotoxy(x-12,y+3);printf("#");
		textcolor(15);
		gotoxy(x-12,y+2);printf("#");
	}
	/////coluna 14 /////////  homem-aranha
	if(x-11>0)
	{
		textcolor(15);
		gotoxy(x-11,y+3);printf("#");
	}
	
	/////coluna 15 /////////  homem-aranha
	if(x-10>0)
	{
		textcolor(15);
		gotoxy(x-10,y+3);printf("#");
	}
	
	/////coluna 16 /////////  homem-aranha
	if(x-9>0)
	{
		textcolor(15);
		gotoxy(x-9,y+3);printf("#");
	}
	
	/////coluna 17 /////////  homem-aranha
	if(x-8>0)
	{
		textcolor(15);
		gotoxy(x-8,y+3);printf("#");
	}
	
	/////coluna 18 /////////  teia
	if(x-7>0)
	{
		textcolor(15);
		gotoxy(x-7,y+3);printf("_");
	}
	
	/////coluna 19 /////////  teia
	if(x-6>0)
	{
		textcolor(15);
		gotoxy(x-6,y+3);printf("_");
	}
	
	/////coluna 20 /////////  teia
	if(x-5>0)
	{
		textcolor(15);
		gotoxy(x-5,y+3);printf("_");
	}
	/////coluna 21 /////////  teia
	if(x-4>0)
	{
		textcolor(15);
		gotoxy(x-4,y+3);printf("_");
	}
	/////coluna 22 /////////  teia
	if(x-3>0)
	{
		textcolor(15);
		gotoxy(x-3,y+3);printf("_");
	}
	
	/////coluna 23 /////////  teia
	if(x-2>0)
	{
		textcolor(15);
		gotoxy(x-2,y+3);printf("/");
	}
	
	/////coluna 24 /////////  teia
	if(x-1>0)
	{
		textcolor(15);
		gotoxy(x-1,y+2);printf("X");
	}
	
	/////coluna 25////////// martelo
	if(x>0)
	{
		textcolor(15);
		gotoxy(x,y+2);printf("#");
	}
	
	/////coluna 26////////// martelo
	if(x+1>0)
	{
		textcolor(15);
		gotoxy(x+1,y+2);printf("#");
	}
	
	/////coluna 27////////// martelo
	if(x+2>0)
	{
		textcolor(15);
		gotoxy(x+2,y+2);printf("#");
	}
	
		/////coluna 28////////// martelo
	if(x+3>0)
	{
		textcolor(15);
		gotoxy(x+3,y+2);printf("#");
	}
	
		/////coluna 29////////// martelo
	if(x+4>0)
	{
		textcolor(15);
		gotoxy(x+4,y+2);printf("#");
	}
	
		/////coluna 30////////// martelo
	if(x+5>0)
	{
		textcolor(15);
		gotoxy(x+5,y+2);printf("#");
	}
	
			/////coluna 31////////// martelo
	if(x+6>0)
	{
		textcolor(15);
		gotoxy(x+6,y+2);printf("#");
	}
	
			/////coluna 32////////// martelo
	if(x+7>0)
	{
		textcolor(15);
		gotoxy(x+7,y+1);printf("#");
		gotoxy(x+7,y+2);printf("#");
		gotoxy(x+7,y+3);printf("#");
	}
			/////coluna 33////////// martelo
	if(x+8>0)
	{
		textcolor(15);
		gotoxy(x+8,y+1);printf("#");
		gotoxy(x+8,y+2);printf("#");
		gotoxy(x+8,y+3);printf("#");
	}
			/////coluna 34////////// martelo
	if(x+9>0)
	{
		textcolor(15);
		gotoxy(x+9,y+1);printf("#");
		gotoxy(x+9,y+2);printf("#");
		gotoxy(x+9,y+3);printf("#");
	}
			/////coluna 35////////// martelo
	if(x+10>0)
	{
		textcolor(15);
		gotoxy(x+10,y+1);printf("#");
		gotoxy(x+10,y+2);printf("#");
		gotoxy(x+10,y+3);printf("#");
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

void animavingadores1e3(int x, int y)
{
	/////coluna 1/////  homem-aranha
	if(x-24>0)
	{
		textcolor(12);
		gotoxy(x-24,y+4);printf("#");
	}
	/////coluna 2/////  homem-aranha
	if(x-23>0)
	{
		textcolor(12);
		gotoxy(x-23,y+4);printf("#");
	}
	////coluna 3 ///////////  homem-aranha
	if(x-22>0)
	{
		textcolor(9);
		gotoxy(x-22,y+4);printf("#");
		textcolor(12);
		gotoxy(x-22,y+6);printf("#");
	}
	////coluna 4 ///////////  homem-aranha
	if(x-21>0)
	{
		textcolor(9);
		gotoxy(x-21,y+4);printf("#");
		textcolor(9);
		gotoxy(x-21,y+5);printf("#");
	}
	////coluna 5 ///////////  homem-aranha
	if(x-20>0)
	{
		textcolor(9);
		gotoxy(x-20,y+4);printf("#");
	}
	
	////coluna 6 ///////////   homem-aranha
	if(x-19>0)
	{
		textcolor(12);
		gotoxy(x-19,y+4);printf("#");
	}
	////coluna 7 ///////////   homem-aranha
	if(x-18>0)
	{
		textcolor(12);
		gotoxy(x-18,y+4);printf("#");
	}
	
	////coluna 8 ///////////  homem-aranha
	if(x-17>0)
	{
		textcolor(12);
		gotoxy(x-17,y+4);printf("#");
	}
	
	////coluna 9 ///////////  homem-aranha
	if(x-16>0)
	{
		textcolor(12);
		gotoxy(x-16,y+4);printf("#");
	}
	
	////coluna 10 ///////////  homem-aranha
	if(x-15>0)
	{
		textcolor(12);
		gotoxy(x-15,y+4);printf("#");
		textcolor(12);
		gotoxy(x-15,y+2);printf("#");
	}
	////coluna 11 ///////////   homem-aranha
	if(x-14>0)
	{
		textcolor(12);
		gotoxy(x-14,y+3);printf("#");
		textcolor(12);
		gotoxy(x-14,y+1);printf("#");
	}
	////coluna 12 ///////////   homem-aranha
	if(x-13>0)
	{
		textcolor(12);
		gotoxy(x-13,y+3);printf("#");
		textcolor(12);
		gotoxy(x-13,y+1);printf("#");
	}
	////coluna 13 ///////////  homem-aranha
	if(x-12>0)
	{
		textcolor(12);
		gotoxy(x-12,y+3);printf("#");
		textcolor(12);
		gotoxy(x-12,y+2);printf("#");
	}
	/////coluna 14 /////////  homem-aranha
	if(x-11>0)
	{
		textcolor(12);
		gotoxy(x-11,y+3);printf("#");
	}
	
	/////coluna 15 /////////  homem-aranha
	if(x-10>0)
	{
		textcolor(12);
		gotoxy(x-10,y+3);printf("#");
	}
	
	/////coluna 16 /////////  homem-aranha
	if(x-9>0)
	{
		textcolor(12);
		gotoxy(x-9,y+3);printf("#");
	}
	
	/////coluna 17 /////////  homem-aranha
	if(x-8>0)
	{
		textcolor(12);
		gotoxy(x-8,y+3);printf("#");
	}
	
	/////coluna 18 /////////  teia
	if(x-7>0)
	{
		textcolor(7);
		gotoxy(x-7,y+3);printf("_");
	}
	
	/////coluna 19 /////////  teia
	if(x-6>0)
	{
		textcolor(7);
		gotoxy(x-6,y+3);printf("_");
	}
	
	/////coluna 20 /////////  teia
	if(x-5>0)
	{
		textcolor(7);
		gotoxy(x-5,y+3);printf("_");
	}
	/////coluna 21 /////////  teia
	if(x-4>0)
	{
		textcolor(7);
		gotoxy(x-4,y+3);printf("_");
	}
	/////coluna 22 /////////  teia
	if(x-3>0)
	{
		textcolor(7);
		gotoxy(x-3,y+3);printf("_");
	}
	
	/////coluna 23 /////////  teia
	if(x-2>0)
	{
		textcolor(7);
		gotoxy(x-2,y+3);printf("/");
	}
	
	/////coluna 24 /////////  teia
	if(x-1>0)
	{
		textcolor(7);
		gotoxy(x-1,y+2);printf("X");
	}
	
	/////coluna 25////////// martelo
	if(x>0)
	{
		textcolor(4);
		gotoxy(x,y+2);printf("#");
	}
	
	/////coluna 26////////// martelo
	if(x+1>0)
	{
		textcolor(4);
		gotoxy(x+1,y+2);printf("#");
	}
	
	/////coluna 27////////// martelo
	if(x+2>0)
	{
		textcolor(4);
		gotoxy(x+2,y+2);printf("#");
	}
	
		/////coluna 28////////// martelo
	if(x+3>0)
	{
		textcolor(4);
		gotoxy(x+3,y+2);printf("#");
	}
	
		/////coluna 29////////// martelo
	if(x+4>0)
	{
		textcolor(4);
		gotoxy(x+4,y+2);printf("#");
	}
	
		/////coluna 30////////// martelo
	if(x+5>0)
	{
		textcolor(4);
		gotoxy(x+5,y+2);printf("#");
	}
	
			/////coluna 31////////// martelo
	if(x+6>0)
	{
		textcolor(4);
		gotoxy(x+6,y+2);printf("#");
	}
	
			/////coluna 32////////// martelo
	if(x+7>0)
	{
		textcolor(8);
		gotoxy(x+7,y+1);printf("#");
		gotoxy(x+7,y+2);printf("#");
		gotoxy(x+7,y+3);printf("#");
	}
			/////coluna 33////////// martelo
	if(x+8>0)
	{
		textcolor(8);
		gotoxy(x+8,y+1);printf("#");
		gotoxy(x+8,y+2);printf("#");
		gotoxy(x+8,y+3);printf("#");
	}
			/////coluna 34////////// martelo
	if(x+9>0)
	{
		textcolor(8);
		gotoxy(x+9,y+1);printf("#");
		gotoxy(x+9,y+2);printf("#");
		gotoxy(x+9,y+3);printf("#");
	}
			/////coluna 35////////// martelo
	if(x+10>0)
	{
		textcolor(8);
		gotoxy(x+10,y+1);printf("#");
		gotoxy(x+10,y+2);printf("#");
		gotoxy(x+10,y+3);printf("#");
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

void limpar_vingadores2(int x, int y)
{
	/////coluna 1/////  homem-aranha
	if(x-24>0)
	{
		textcolor(15);
		gotoxy(x-24,y+4);printf("#");
	}
	/////coluna 2/////  homem-aranha
	if(x-23>0)
	{
		textcolor(15);
		gotoxy(x-23,y+4);printf("#");
	}
	////coluna 3 ///////////  homem-aranha
	if(x-22>0)
	{
		textcolor(15);
		gotoxy(x-22,y+4);printf("#");
		textcolor(15);
		gotoxy(x-22,y+6);printf("#");
	}
	////coluna 4 ///////////  homem-aranha
	if(x-21>0)
	{
		textcolor(15);
		gotoxy(x-21,y+4);printf("#");
		textcolor(15);
		gotoxy(x-21,y+5);printf("#");
	}
	////coluna 5 ///////////  homem-aranha
	if(x-20>0)
	{
		textcolor(15);
		gotoxy(x-20,y+4);printf("#");
	}
	
	////coluna 6 ///////////   homem-aranha
	if(x-19>0)
	{
		textcolor(15);
		gotoxy(x-19,y+4);printf("#");
	}
	////coluna 7 ///////////   homem-aranha
	if(x-18>0)
	{
		textcolor(15);
		gotoxy(x-18,y+4);printf("#");
	}
	
	////coluna 8 ///////////  homem-aranha
	if(x-17>0)
	{
		textcolor(15);
		gotoxy(x-17,y+4);printf("#");
	}
	
	////coluna 9 ///////////  homem-aranha
	if(x-16>0)
	{
		textcolor(15);
		gotoxy(x-16,y+4);printf("#");
	}
	
	////coluna 10 ///////////  homem-aranha
	if(x-15>0)
	{
		textcolor(15);
		gotoxy(x-15,y+4);printf("#");
		textcolor(15);
		gotoxy(x-15,y+2);printf("#");
	}
	////coluna 11 ///////////   homem-aranha
	if(x-14>0)
	{
		textcolor(15);
		gotoxy(x-14,y+3);printf("#");
		textcolor(15);
		gotoxy(x-14,y+1);printf("#");
	}
	////coluna 12 ///////////   homem-aranha
	if(x-13>0)
	{
		textcolor(15);
		gotoxy(x-13,y+3);printf("#");
		textcolor(15);
		gotoxy(x-13,y+1);printf("#");
	}
	////coluna 13 ///////////  homem-aranha
	if(x-12>0)
	{
		textcolor(15);
		gotoxy(x-12,y+3);printf("#");
		textcolor(15);
		gotoxy(x-12,y+2);printf("#");
	}
	/////coluna 14 /////////  homem-aranha
	if(x-11>0)
	{
		textcolor(15);
		gotoxy(x-11,y+3);printf("#");
	}
	
	/////coluna 15 /////////  homem-aranha
	if(x-10>0)
	{
		textcolor(15);
		gotoxy(x-10,y+3);printf("#");
	}
	
	/////coluna 16 /////////  homem-aranha
	if(x-9>0)
	{
		textcolor(15);
		gotoxy(x-9,y+3);printf("#");
	}
	
	/////coluna 17 /////////  homem-aranha
	if(x-8>0)
	{
		textcolor(15);
		gotoxy(x-8,y+3);printf("#");
	}
	
	/////coluna 18 /////////  teia
	if(x-7>0)
	{
		textcolor(15);
		gotoxy(x-7,y+3);printf("/");
	}
	
	/////coluna 19 /////////  teia
	if(x-6>0)
	{
		textcolor(15);
		gotoxy(x-6,y+2);printf("_");
	}
	
	/////coluna 20 /////////  teia
	if(x-5>0)
	{
		textcolor(15);
		gotoxy(x-5,y+2);printf("_");
	}
	/////coluna 21 /////////  teia
	if(x-4>0)
	{
		textcolor(15);
		gotoxy(x-4,y+2);printf("_");
	}
	/////coluna 22 /////////  teia
	if(x-3>0)
	{
		textcolor(15);
		gotoxy(x-3,y+2);printf("_");
	}
	
	/////coluna 23 /////////  teia
	if(x-2>0)
	{
		textcolor(15);
		gotoxy(x-2,y+2);printf("/");
	}
	
	/////coluna 24 /////////  teia
	if(x-1>0)
	{
		textcolor(15);
		gotoxy(x-1,y+1);printf("X");
	}
	
	/////coluna 25////////// martelo
	if(x>0)
	{
		textcolor(15);
		gotoxy(x,y+1);printf("#");
	}
	
	/////coluna 26////////// martelo
	if(x+1>0)
	{
		textcolor(15);
		gotoxy(x+1,y+1);printf("#");
	}
	
	/////coluna 27////////// martelo
	if(x+2>0)
	{
		textcolor(15);
		gotoxy(x+2,y+1);printf("#");
	}
	
		/////coluna 28////////// martelo
	if(x+3>0)
	{
		textcolor(15);
		gotoxy(x+3,y+1);printf("#");
	}
	
		/////coluna 29////////// martelo
	if(x+4>0)
	{
		textcolor(15);
		gotoxy(x+4,y+1);printf("#");
	}
	
		/////coluna 30////////// martelo
	if(x+5>0)
	{
		textcolor(15);
		gotoxy(x+5,y+1);printf("#");
	}
	
			/////coluna 31////////// martelo
	if(x+6>0)
	{
		textcolor(15);
		gotoxy(x+6,y+1);printf("#");
	}
	
			/////coluna 32////////// martelo
	if(x+7>0)
	{
		textcolor(15);
		gotoxy(x+7,y);printf("#");
		gotoxy(x+7,y+1);printf("#");
		gotoxy(x+7,y+2);printf("#");
	}
			/////coluna 33////////// martelo
	if(x+8>0)
	{
		textcolor(15);
		gotoxy(x+8,y);printf("#");
		gotoxy(x+8,y+1);printf("#");
		gotoxy(x+8,y+2);printf("#");
	}
			/////coluna 34////////// martelo
	if(x+9>0)
	{
		textcolor(15);
		gotoxy(x+9,y);printf("#");
		gotoxy(x+9,y+1);printf("#");
		gotoxy(x+9,y+2);printf("#");
	}
			/////coluna 35////////// martelo
	if(x+10>0)
	{
		textcolor(15);
		gotoxy(x+10,y);printf("#");
		gotoxy(x+10,y+1);printf("#");
		gotoxy(x+10,y+2);printf("#");
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

void animavingadores2(int x, int y)
{
	/////coluna 1/////  homem-aranha
	if(x-24>0)
	{
		textcolor(12);
		gotoxy(x-24,y+4);printf("#");
	}
	/////coluna 2/////  homem-aranha
	if(x-23>0)
	{
		textcolor(12);
		gotoxy(x-23,y+4);printf("#");
	}
	////coluna 3 ///////////  homem-aranha
	if(x-22>0)
	{
		textcolor(9);
		gotoxy(x-22,y+4);printf("#");
		textcolor(12);
		gotoxy(x-22,y+6);printf("#");
	}
	////coluna 4 ///////////  homem-aranha
	if(x-21>0)
	{
		textcolor(9);
		gotoxy(x-21,y+4);printf("#");
		textcolor(9);
		gotoxy(x-21,y+5);printf("#");
	}
	////coluna 5 ///////////  homem-aranha
	if(x-20>0)
	{
		textcolor(9);
		gotoxy(x-20,y+4);printf("#");
	}
	
	////coluna 6 ///////////   homem-aranha
	if(x-19>0)
	{
		textcolor(12);
		gotoxy(x-19,y+4);printf("#");
	}
	////coluna 7 ///////////   homem-aranha
	if(x-18>0)
	{
		textcolor(12);
		gotoxy(x-18,y+4);printf("#");
	}
	
	////coluna 8 ///////////  homem-aranha
	if(x-17>0)
	{
		textcolor(12);
		gotoxy(x-17,y+4);printf("#");
	}
	
	////coluna 9 ///////////  homem-aranha
	if(x-16>0)
	{
		textcolor(12);
		gotoxy(x-16,y+4);printf("#");
	}
	
	////coluna 10 ///////////  homem-aranha
	if(x-15>0)
	{
		textcolor(12);
		gotoxy(x-15,y+4);printf("#");
		textcolor(12);
		gotoxy(x-15,y+2);printf("#");
	}
	////coluna 11 ///////////   homem-aranha
	if(x-14>0)
	{
		textcolor(12);
		gotoxy(x-14,y+3);printf("#");
		textcolor(12);
		gotoxy(x-14,y+1);printf("#");
	}
	////coluna 12 ///////////   homem-aranha
	if(x-13>0)
	{
		textcolor(12);
		gotoxy(x-13,y+3);printf("#");
		textcolor(12);
		gotoxy(x-13,y+1);printf("#");
	}
	////coluna 13 ///////////  homem-aranha
	if(x-12>0)
	{
		textcolor(12);
		gotoxy(x-12,y+3);printf("#");
		textcolor(12);
		gotoxy(x-12,y+2);printf("#");
	}
	/////coluna 14 /////////  homem-aranha
	if(x-11>0)
	{
		textcolor(12);
		gotoxy(x-11,y+3);printf("#");
	}
	
	/////coluna 15 /////////  homem-aranha
	if(x-10>0)
	{
		textcolor(12);
		gotoxy(x-10,y+3);printf("#");
	}
	
	/////coluna 16 /////////  homem-aranha
	if(x-9>0)
	{
		textcolor(12);
		gotoxy(x-9,y+3);printf("#");
	}
	
	/////coluna 17 /////////  homem-aranha
	if(x-8>0)
	{
		textcolor(12);
		gotoxy(x-8,y+3);printf("#");
	}
	
	/////coluna 18 /////////  teia
	if(x-7>0)
	{
		textcolor(7);
		gotoxy(x-7,y+3);printf("/");
	}
	
	/////coluna 19 /////////  teia
	if(x-6>0)
	{
		textcolor(7);
		gotoxy(x-6,y+2);printf("_");
	}
	
	/////coluna 20 /////////  teia
	if(x-5>0)
	{
		textcolor(7);
		gotoxy(x-5,y+2);printf("_");
	}
	/////coluna 21 /////////  teia
	if(x-4>0)
	{
		textcolor(7);
		gotoxy(x-4,y+2);printf("_");
	}
	/////coluna 22 /////////  teia
	if(x-3>0)
	{
		textcolor(7);
		gotoxy(x-3,y+2);printf("_");
	}
	
	/////coluna 23 /////////  teia
	if(x-2>0)
	{
		textcolor(7);
		gotoxy(x-2,y+2);printf("/");
	}
	
	/////coluna 24 /////////  teia
	if(x-1>0)
	{
		textcolor(7);
		gotoxy(x-1,y+1);printf("X");
	}
	
	/////coluna 25////////// martelo
	if(x>0)
	{
		textcolor(4);
		gotoxy(x,y+1);printf("#");
	}
	
	/////coluna 26////////// martelo
	if(x+1>0)
	{
		textcolor(4);
		gotoxy(x+1,y+1);printf("#");
	}
	
	/////coluna 27////////// martelo
	if(x+2>0)
	{
		textcolor(4);
		gotoxy(x+2,y+1);printf("#");
	}
	
		/////coluna 28////////// martelo
	if(x+3>0)
	{
		textcolor(4);
		gotoxy(x+3,y+1);printf("#");
	}
	
		/////coluna 29////////// martelo
	if(x+4>0)
	{
		textcolor(4);
		gotoxy(x+4,y+1);printf("#");
	}
	
		/////coluna 30////////// martelo
	if(x+5>0)
	{
		textcolor(4);
		gotoxy(x+5,y+1);printf("#");
	}
	
			/////coluna 31////////// martelo
	if(x+6>0)
	{
		textcolor(4);
		gotoxy(x+6,y+1);printf("#");
	}
	
			/////coluna 32////////// martelo
	if(x+7>0)
	{
		textcolor(8);
		gotoxy(x+7,y);printf("#");
		gotoxy(x+7,y+1);printf("#");
		gotoxy(x+7,y+2);printf("#");
	}
			/////coluna 33////////// martelo
	if(x+8>0)
	{
		textcolor(8);
		gotoxy(x+8,y);printf("#");
		gotoxy(x+8,y+1);printf("#");
		gotoxy(x+8,y+2);printf("#");
	}
			/////coluna 34////////// martelo
	if(x+9>0)
	{
		textcolor(8);
		gotoxy(x+9,y);printf("#");
		gotoxy(x+9,y+1);printf("#");
		gotoxy(x+9,y+2);printf("#");
	}
			/////coluna 35////////// martelo
	if(x+10>0)
	{
		textcolor(8);
		gotoxy(x+10,y);printf("#");
		gotoxy(x+10,y+1);printf("#");
		gotoxy(x+10,y+2);printf("#");
	}
}

//----------------------------------------------------------------------------------------------------------------------------------

void limpar_superman3(int x, int y)
{

	//// linha 1 ////
	
	textcolor(15);
	gotoxy(x+4,y+1);printf("#####");
	textcolor(15);
	gotoxy(x+12,y+1);printf("##");
	
	//// linha 2 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x+9,y+2);printf("##");
	textbackground(15);
	textcolor(15);
	gotoxy(x+11,y+2);printf("#");
	gotoxy(x+14,y+2);printf("#");
	
	//// linha 3 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x,y+3);printf("##");
	textbackground(15);
	textcolor(15);
	gotoxy(x+2,y+3);printf("#####");
	textbackground(15);
	textcolor(15);
	gotoxy(x+7,y+3);printf("#");
	textcolor(15);
	gotoxy(x+8,y+3);printf("#########");
}

//-----------------------------------------------------------------------------------------------------------------------------

void animasuperman3(int x, int y)
{

	//// linha 1 ////
	
	textcolor(12);
	gotoxy(x+4,y+1);printf("#####");
	textcolor(0);
	gotoxy(x+12,y+1);printf("##");
	
	//// linha 2 ////
	
	textbackground(15);
	textcolor(12);
	gotoxy(x+9,y+2);printf("##");
	textbackground(15);
	textcolor(0);
	gotoxy(x+11,y+2);printf("#");
	gotoxy(x+14,y+2);printf("#");
	
	//// linha 3 ////
	
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+3);printf("##");
	textbackground(15);
	textcolor(9);
	gotoxy(x+2,y+3);printf("#####");
	textbackground(15);
	textcolor(12);
	gotoxy(x+7,y+3);printf("#");
	textcolor(9);
	gotoxy(x+8,y+3);printf("#########");
}

//-----------------------------------------------------------------------------------------------------------------------------

void limpar_superman2(int x, int y)
{
	///linha 1 ////
	textcolor(15);
	textbackground(15);
	gotoxy(x+6,y); printf("###");
	
	//// linha 2 ////
	
	gotoxy(x+7,y+1);printf("###");
	textcolor(15);
	gotoxy(x+12,y+1);printf("##");
	
	//// linha 3 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x+9,y+2);printf("##");
	textbackground(15);
	textcolor(15);
	gotoxy(x+11,y+2);printf("#");
	gotoxy(x+14,y+2);printf("#");
	
	//// linha 4 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x,y+3);printf("##");
	textbackground(15);
	textcolor(15);
	gotoxy(x+2,y+3);printf("#####");
	textbackground(15);
	textcolor(15);
	gotoxy(x+7,y+3);printf("#");
	textcolor(15);
	gotoxy(x+8,y+3);printf("#########");
}

//-----------------------------------------------------------------------------------------------------------------------------

void animasuperman2(int x, int y)
{
	///linha 1 ////
	textcolor(12);
	textbackground(15);
	gotoxy(x+6,y); printf("###");
	
	//// linha 2 ////
	
	gotoxy(x+7,y+1);printf("###");
	textcolor(0);
	gotoxy(x+12,y+1);printf("##");
	
	//// linha 3 ////
	
	textbackground(15);
	textcolor(12);
	gotoxy(x+9,y+2);printf("##");
	textbackground(15);
	textcolor(0);
	gotoxy(x+11,y+2);printf("#");
	gotoxy(x+14,y+2);printf("#");
	
	//// linha 4 ////
	
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+3);printf("##");
	textbackground(15);
	textcolor(9);
	gotoxy(x+2,y+3);printf("#####");
	textbackground(15);
	textcolor(12);
	gotoxy(x+7,y+3);printf("#");
	textcolor(9);
	gotoxy(x+8,y+3);printf("#########");
}

//-----------------------------------------------------------------------------------------------------------------------------

void limpar_superman1(int x, int y)
{
	///linha 1 ////
	textcolor(15);
	textbackground(15);
	gotoxy(x+7,y); printf("##");
	
	//// linha 2 ////
	
	gotoxy(x+6,y+1);printf("####");
	textcolor(15);
	gotoxy(x+12,y+1);printf("##");
	
	//// linha 3 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x+9,y+2);printf("##");
	textbackground(15);
	textcolor(15);
	gotoxy(x+11,y+2);printf("#");
	gotoxy(x+14,y+2);printf("#");
	
	//// linha 4 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x,y+3);printf("##");
	textbackground(15);
	textcolor(15);
	gotoxy(x+2,y+3);printf("#####");
	textbackground(15);
	textcolor(15);
	gotoxy(x+7,y+3);printf("#");
	textcolor(15);
	gotoxy(x+8,y+3);printf("#########");
}

//-----------------------------------------------------------------------------------------------------------------------------

void animasuperman1(int x, int y)
{
	///linha 1 ////
	textcolor(12);
	textbackground(15);
	gotoxy(x+7,y); printf("##");
	
	//// linha 2 ////
	
	gotoxy(x+6,y+1);printf("####");
	textcolor(0);
	gotoxy(x+12,y+1);printf("##");
	
	//// linha 3 ////
	
	textbackground(15);
	textcolor(12);
	gotoxy(x+9,y+2);printf("##");
	textbackground(15);
	textcolor(0);
	gotoxy(x+11,y+2);printf("#");
	gotoxy(x+14,y+2);printf("#");
	
	//// linha 4 ////
	
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+3);printf("##");
	textbackground(15);
	textcolor(9);
	gotoxy(x+2,y+3);printf("#####");
	textbackground(15);
	textcolor(12);
	gotoxy(x+7,y+3);printf("#");
	textcolor(9);
	gotoxy(x+8,y+3);printf("#########");
}

//----------------------------------------------------------------------------------------------------------------------------------

void animaflash4(int x, int y)
{
	///linha 1 ////
	textcolor(12);
	textbackground(15);
	gotoxy(x,y); printf("##");
	
	//// linha 2 ////
	
	gotoxy(x-1,y+1);printf("#");
	gotoxy(x+2,y+1);printf("#");
	
	//// linha 3 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-9,y+2);printf("______");
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+2);printf("##");
	textbackground(15);
	textcolor(4);
	gotoxy(x+3,y+2);printf("#");  //+
	
	//// linha 4 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-6,y+3);printf("___");
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+3);printf("#");
	textbackground(15);
	textcolor(4);
	gotoxy(x+1,y+3);printf("##");  //+
	//// linha 5 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-8,y+4);printf("____");
	textbackground(15);
	textcolor(12);
	gotoxy(x-1,y+4);printf("##");
	//// linha 6 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-5,y+5);printf("__");
	textbackground(15);
	textcolor(12);
	gotoxy(x-2,y+5);printf("#");
	textbackground(15);
	textcolor(4);
	gotoxy(x,y+5);printf("#"); //inverte
	textbackground(15);
	textcolor(12);
	gotoxy(x+1,y+5);printf("##");  //+ inverte
	///linha 7 ////
	textcolor(12);
	textbackground(15);
	gotoxy(x-2,y+6); printf("#");
	textbackground(15);
	textcolor(4);
	gotoxy(x,y+6);printf("#");  //inverte
	textbackground(15);
	textcolor(12);
	gotoxy(x+3,y+6);printf("#");  //+ inverte
	//// linha 8 ////
	
	textbackground(15);
	textcolor(4);
	gotoxy(x,y+7);printf("#");
	textbackground(15);
	textcolor(14);
	gotoxy(x+2,y+7);printf("#");  //+ inverte
	//// linha 9 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x,y+8);printf("#");
}

//----------------------------------------------------------------------------------------------------------------------------------

void animaflash2(int x, int y)
{
	///linha 1 ////
	textcolor(12);
	textbackground(15);
	gotoxy(x,y); printf("##");
	
	//// linha 2 ////
	
	gotoxy(x-1,y+1);printf("#");
	gotoxy(x+2,y+1);printf("#");
	
	//// linha 3 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-9,y+2);printf("______");
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+2);printf("##");
	textbackground(15);
	textcolor(4);
	gotoxy(x+3,y+2);printf("#");  //+
	
	//// linha 4 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-6,y+3);printf("___");
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+3);printf("#");
	textbackground(15);
	textcolor(4);
	gotoxy(x+1,y+3);printf("##");  //+
	//// linha 5 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-8,y+4);printf("____");
	textbackground(15);
	textcolor(12);
	gotoxy(x-1,y+4);printf("##");
	//// linha 6 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-5,y+5);printf("__");
	textbackground(15);
	textcolor(12);
	gotoxy(x-2,y+5);printf("#");
	gotoxy(x,y+5);printf("#");
	textbackground(15);
	textcolor(4);
	gotoxy(x+1,y+5);printf("##");  //+
	///linha 7 ////
	textcolor(12);
	textbackground(15);
	gotoxy(x-2,y+6); printf("#");
	gotoxy(x,y+6);printf("#");
	textbackground(15);
	textcolor(4);
	gotoxy(x+3,y+6);printf("#");  //+
	//// linha 8 ////
	
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+7);printf("#");
	textbackground(15);
	textcolor(14);
	gotoxy(x+2,y+7);printf("#");  //+
	//// linha 9 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x,y+8);printf("#");
	
	
}

//-----------------------------------------------------------------------------------------------------------------------------

void limpar_flash2e4(int x, int y)
{
	///linha 1 ////
	textcolor(15);
	textbackground(15);
	gotoxy(x,y); printf("##");
	
	//// linha 2 ////
	
	gotoxy(x-1,y+1);printf("#");
	gotoxy(x+2,y+1);printf("#");
	
	//// linha 3 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x-9,y+2);printf("______");
	textbackground(15);
	textcolor(15);
	gotoxy(x,y+2);printf("##");
	textbackground(15);
	textcolor(15);
	gotoxy(x+3,y+2);printf("#");  //+
	
	//// linha 4 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x-6,y+3);printf("___");
	textbackground(15);
	textcolor(15);
	gotoxy(x,y+3);printf("#");
	textbackground(15);
	textcolor(15);
	gotoxy(x+1,y+3);printf("##");  //+
	//// linha 5 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x-8,y+4);printf("____");
	textbackground(15);
	textcolor(15);
	gotoxy(x-1,y+4);printf("##");
	//// linha 6 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x-5,y+5);printf("__");
	textbackground(15);
	textcolor(15);
	gotoxy(x-2,y+5);printf("#");
	gotoxy(x,y+5);printf("#");
	textbackground(15);
	textcolor(15);
	gotoxy(x+1,y+5);printf("##");  //+
	///linha 7 ////
	textcolor(15);
	textbackground(15);
	gotoxy(x-2,y+6); printf("#");
	gotoxy(x,y+6);printf("#");
	textbackground(15);
	textcolor(15);
	gotoxy(x+3,y+6);printf("#");  //+
	//// linha 8 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x,y+7);printf("#");
	textbackground(15);
	textcolor(15);
	gotoxy(x+2,y+7);printf("#");  //+
	//// linha 9 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x,y+8);printf("#");
}

//-----------------------------------------------------------------------------------------------------------------------------

void animaflash3(int x, int y)
{
	///linha 1 ////
	textcolor(12);
	textbackground(15);
	gotoxy(x,y); printf("##");
	
	//// linha 2 ////
	
	gotoxy(x-1,y+1);printf("#");
	gotoxy(x+2,y+1);printf("#");
	
	
	//// linha 3 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-9,y+2);printf("______");
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+2);printf("##");
	
	//// linha 4 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-6,y+3);printf("___");
	textbackground(15);
	textcolor(4);
	gotoxy(x-1,y+3);printf("#");  //+
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+3);printf("#");
	gotoxy(x+3,y+3);printf("#");
	
	//// linha 5 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-8,y+4);printf("____");
	textbackground(15);
	textcolor(4);
	gotoxy(x-2,y+4);printf("#");  //+
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+4);printf("###");
	
	//// linha 6 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-5,y+5);printf("__");
	textbackground(15);
	textcolor(4);
	gotoxy(x-2,y+5);printf("#");  //+
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+5);printf("#");
	
	//// linha 7 ////
	gotoxy(x,y+6);printf("#");
	
	//// linha 8 ////
	
	textbackground(15);
	textcolor(4);
	gotoxy(x-1,y+7);printf("#");  //+
	textbackground(15);
	textcolor(12);
	gotoxy(x+1,y+7);printf("#");
	
	//// linha 9 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-2,y+8);printf("#");  //+
	gotoxy(x+2,y+8);printf("#");
}

//-----------------------------------------------------------------------------------------------------------------------------

void animaflash1(int x, int y)
{
	////////////////////frame 1//////////////////////////////////   frame 2 (x+12)  12# 4+  14bota  6ou14_____
	
	///linha 1 ////
	textcolor(12);
	textbackground(15);
	gotoxy(x,y); printf("##");
	
	//// linha 2 ////
	
	gotoxy(x-1,y+1);printf("#");
//	setlocale(LC_ALL,"C");
//	textbackground(15);
//	textcolor(0);
//	gotoxy(x,y+1);printf("%c",39);
//	textcolor(12);
//	gotoxy(x+1,y+1);printf("%c",218);
//	textbackground(12);
//	setlocale(LC_ALL,NULL);
	gotoxy(x+2,y+1);printf("#");
	
	
	//// linha 3 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-9,y+2);printf("______");
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+2);printf("##");
	
	//// linha 4 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-6,y+3);printf("___");
	textbackground(15);
	textcolor(4);
	gotoxy(x-1,y+3);printf("#");  //+
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+3);printf("#");
	gotoxy(x+3,y+3);printf("#");
	
	//// linha 5 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-8,y+4);printf("____");
	textbackground(15);
	textcolor(4);
	gotoxy(x-2,y+4);printf("#");  //+
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+4);printf("###");
	
	//// linha 6 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-5,y+5);printf("__");
	textbackground(15);
	textcolor(4);
	gotoxy(x-2,y+5);printf("#");  //+
	textbackground(15);
	textcolor(12);
	gotoxy(x,y+5);printf("#");
	
	//// linha 7 ////
	gotoxy(x,y+6);printf("#");
	
	//// linha 8 ////
	
	textbackground(15);
	textcolor(4);
	gotoxy(x-1,y+7);printf("#");  //+
	textbackground(15);
	textcolor(12);
	gotoxy(x+1,y+7);printf("#");
	
	//// linha 9 ////
	
	textbackground(15);
	textcolor(14);
	gotoxy(x-2,y+8);printf("#");  //+
	gotoxy(x+2,y+8);printf("#");
}

//-----------------------------------------------------------------------------------------------------------------------------

void limpar_flash1e3(int x, int y)
{
	///linha 1 ////
	textcolor(15);
	textbackground(15);
	gotoxy(x,y); printf("##");
	
	//// linha 2 ////
	
	gotoxy(x-1,y+1);printf("#");
	gotoxy(x+2,y+1);printf("#");
	
	
	//// linha 3 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x-9,y+2);printf("______");
	textbackground(15);
	textcolor(15);
	gotoxy(x,y+2);printf("##");
	
	//// linha 4 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x-6,y+3);printf("___");
	textbackground(15);
	textcolor(15);
	gotoxy(x-1,y+3);printf("#");  //+
	textbackground(15);
	textcolor(15);
	gotoxy(x,y+3);printf("#");
	gotoxy(x+3,y+3);printf("#");
	
	//// linha 5 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x-8,y+4);printf("____");
	textbackground(15);
	textcolor(15);
	gotoxy(x-2,y+4);printf("#");  //+
	textbackground(15);
	textcolor(15);
	gotoxy(x,y+4);printf("###");
	
	//// linha 6 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x-5,y+5);printf("__");
	textbackground(15);
	textcolor(15);
	gotoxy(x-2,y+5);printf("#");  //+
	textbackground(15);
	textcolor(15);
	gotoxy(x,y+5);printf("#");
	
	//// linha 7 ////
	gotoxy(x,y+6);printf("#");
	
	//// linha 8 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x-1,y+7);printf("#");  //+
	textbackground(15);
	textcolor(15);
	gotoxy(x+1,y+7);printf("#");
	
	//// linha 9 ////
	
	textbackground(15);
	textcolor(15);
	gotoxy(x-2,y+8);printf("#");  //+
	gotoxy(x+2,y+8);printf("#");
}

//----------------------------------------------------------------------------------------------------------------------------------

void nome (int x, int y)
{
	cursor(0);
	textbackground(11);
	system("cls");
	textcolor(5);
	//plataforma/////////////////////////////////////////////////////////////////

	gotoxy(x,y);printf(" ______	                           ___");
	gotoxy(x,y+1);printf("|  __  \\  ^               |              /   \\");
	gotoxy(x,y+2);printf("| |  \\  \\| \\	           |             /");
	gotoxy(x,y+3);printf("| |__/  /|  \\	       ____|____      __|___");
	gotoxy(x,y+4);printf("|  ____/ \\  |	           |            |	    ___    ___  ___             ");
	gotoxy(x,y+5);printf("| |       \\ |	  ____     |     ____   |   ___  |/	 |/   \\/   \\   ____");
	gotoxy(x,y+6);printf("| |	    \\|   /    \\    |	/    \\  | /___/\\ |	 |    V     | /    \\");
	gotoxy(x,y+7);printf("| |	     \\   |    |\\   \\    |    |\\ | |    | |	 |	    | |    |\\");
	gotoxy(x,y+8);printf("|_|          \\__\\____/ \\___\\___\\____/ \\| \\____/ |	 |	    | \\____/ \\_)");
	
	// multiverso////////////////////////////////////////////////////////////////
	
	gotoxy(x+1,y+10);printf("   #      #             #    ########### # #                  # ####### #####     ########      ########");
	gotoxy(x+1,y+11);printf("  ###    ###  #       # #         #      #  #                #  #       #    #   #       ##    #        #");
	gotoxy(x+1,y+12);printf(" ## ##  ## ## #       # #         #      #   #              #   #       #     #   #           # #      # #");
	gotoxy(x+1,y+13);printf("##  ## ##   # #       # #         #      #    #            #    #       #    #     #####     #   #    #   #");
	gotoxy(x+1,y+14);printf("##   ###    # #       # #         #      #     #          #     #####   #####           #   #     #  #     #");
	gotoxy(x+1,y+15);printf("##    #     # #       # #         #      #      #        #      #       #   #            #  #      #       #");
	gotoxy(x+1,y+16);printf("##          # #       # #         #      #       #      #       #       #    #            # #     #  #     #");
	gotoxy(x+1,y+17);printf("##          # #       # #         #      #        #    #        #       #     #  #       #   #   #    #   #");
	gotoxy(x+1,y+18);printf("##          #  #      # #         #      #         #  #         #       #      #  #     #     # #      # #");
	gotoxy(x+1,y+19);printf("##          #   ######  #######   #      #          ##          ####### #       #  #####       ########## ");
}

//----------------------------------------------------------------------------------------------------------------------------------

void liga_da_justica(int x, int y)
{
	textbackground(15);
	textcolor(0);
	gotoxy(x,y);  printf("  _________  ____");
	gotoxy(x,y+1);printf("  \\       | |   |");
	gotoxy(x,y+2);printf("   \\____  | |   |");
	gotoxy(x,y+3);printf("       |  | |   | ");
	gotoxy(x,y+4);printf("       |  | |   |   ");
	gotoxy(x,y+5);printf("   /|  |  | |   | ");
	gotoxy(x,y+6);printf("  / |  |  | |   |      _ ");
	gotoxy(x,y+7);printf(" |  |__|  | |   |   _-- |");
	gotoxy(x,y+8);printf(" |        | |   |_--   _|");
	gotoxy(x,y+9);printf(" \\________/ |       _--  ");
	gotoxy(x,y+10);printf("            |    _--");
	gotoxy(x,y+11);printf("            | _--    ");
}
 
//----------------------------------------------------------------------------------------------------------------------------------
 
void vingadores (int x, int y)
{
	textbackground(15);
	textcolor(0);
	gotoxy(x,y);  printf("             ______ ");
	gotoxy(x,y+1);printf("            /     |");
	gotoxy(x,y+2);printf("           /      |");
	gotoxy(x,y+3);printf("          /   /|  |");
	gotoxy(x,y+4);printf("         /   / |  |");
	gotoxy(x,y+5);printf("        /   /  |  |");
	gotoxy(x,y+6);printf("       /   /   |  |");
	gotoxy(x,y+7);printf("      /   /____|\\ |");
	gotoxy(x,y+8);printf("     /           \\|");
	gotoxy(x,y+9);printf("    /   ________ /|");
	gotoxy(x,y+10);printf("   /   /       |/_|");
	gotoxy(x,y+11);printf("  /   /");
	gotoxy(x,y+12);printf(" /___/");
}

//----------------------------------------------------------------------------------------------------------------------------------

void superman(int x, int y)
{
	textbackground(1);
	gotoxy(x+6,y-1);printf("          "); 
	gotoxy(x+4,y);printf("              ");
	gotoxy(x+2,y+1);printf("                  ");
	gotoxy(x,y+2);printf("                      ");
	gotoxy(x-1,y+3);printf("                        ");
	gotoxy(x-1,y+4);printf("                        ");
	gotoxy(x-1,y+5);printf("                        ");
	gotoxy(x-1,y+6);printf("                        ");
	gotoxy(x,y+7);printf("                      ");
	gotoxy(x+2,y+8);printf("                  ");
	gotoxy(x+4,y+9);printf("              ");
	gotoxy(x+6,y+10);printf("          ");   
	
	///////////////////////////////////////   fundo  ////////////////////////////////////////q
	textcolor(12);
	gotoxy(x+4,y);  printf(" ____________");
	gotoxy(x+4,y+1);printf("/            \\");
	gotoxy(x,y+2);printf("   /    _______   \\");
	gotoxy(x,y+3);printf("   \\   /       \\  /");
	gotoxy(x,y+4);printf("    \\  \\______   /");
	gotoxy(x,y+5);printf("     \\        \\ /");
	gotoxy(x,y+6);printf("      \\ \\_____//");
	gotoxy(x+4,y+7);printf("   \\      /");
	gotoxy(x+4,y+8);printf("    \\    /");
	gotoxy(x+4,y+9);printf("     \\  /");
	gotoxy(x+6,y+10);printf("    \\/");
}

//----------------------------------------------------------------------------------------------------------------------------------

void flash(int x, int y)
{
	textbackground(12);
	gotoxy(x+3,y-1);printf("          "); 
	gotoxy(x+1,y);printf("              ");
	gotoxy(x-1,y+1);printf("                  ");
	gotoxy(x-3,y+2);printf("                      ");
	gotoxy(x-4,y+3);printf("                        ");
	gotoxy(x-4,y+4);printf("                        ");
	gotoxy(x-4,y+5);printf("                        ");
	gotoxy(x-4,y+6);printf("                        ");
	gotoxy(x-3,y+7);printf("                      ");
	gotoxy(x-1,y+8);printf("                  ");
	gotoxy(x+1,y+9);printf("              ");
	gotoxy(x+3,y+10);printf("          ");   
	///////////////////////////    fundo    /////////////////////////////////////////
	textcolor(14);
	gotoxy(x,y);  printf("        /|");
	gotoxy(x,y+1);printf("       / |");
	gotoxy(x,y+2);printf("      /  |");
	gotoxy(x,y+3);printf("     /   |__");
	gotoxy(x,y+4);printf("    /      / ");
	gotoxy(x,y+5);printf("   /__    /");
	gotoxy(x,y+6);printf("     |   /");
	gotoxy(x,y+7);printf("     |  /");
	gotoxy(x,y+8);printf("     | / ");
	gotoxy(x,y+9);printf("     |/");
}

//----------------------------------------------------------------------------------------------------------------------------------

void limpar (int x, int y)
{
	for (int i=0; i<40; i++)
	{
		textbackground(15);
		gotoxy(x-4,y-3);printf("                                      ");
		gotoxy(x-4,y-2);printf("                                    ");
		gotoxy(x-4,y-1);printf("                                    ");
		gotoxy(x-4,y);printf("                                    ");
		gotoxy(x-4,y+1);printf("                                    ");
		gotoxy(x-4,y+2);printf("                                      ");
		gotoxy(x-4,y+3);printf("                                    ");
		gotoxy(x-4,y+4);printf("                                   ");
		gotoxy(x-4,y+5);printf("                             ");
		gotoxy(x-4,y+6);printf("                             ");
		gotoxy(x-4,y+7);printf("                             ");
		gotoxy(x-4,y+8);printf("                             ");
		gotoxy(x-4,y+9);printf("                             ");
		gotoxy(x-4,y+10);printf("                             ");
		gotoxy(x-4,y+11);printf("                             ");
		gotoxy(x-4,y+12);printf("                             ");
	}
}

//----------------------------------------------------------------------------------------------------------------------------------

void carregando (int x, int y)
{
	int aux=x;
	gotoxy(x,y-2);printf("Carregando");
	gotoxy(x,y);
	int X=0;
	for(int i=0; i<4; i++)
	{
		x=aux;
		textbackground(15);
		X=0;
		gotoxy(aux,y);printf("                                                                                                                       ");
		limpar(49,5);
		if(i==0)
			flash(50,5);
		if(i==1)
			vingadores(50,5);
		if(i==2)
			superman(50,5);
		if(i==3)
			liga_da_justica(50,5);
		int c=0;
		int C=0;
		for (int j=0; j<56; j++)
		{
			int w=j+1;
			if(w%16==0)
				c++;
			if(w%12==0)
				C++;
			if (i==0)
			{
			//	flash(50,5);
			//	gotoxy(2,2);printf("%d e %d e %d",c,4+4*c+12*c,(j+1)%16);
				if(j<4+4*c+12*c)
				{
					if(X==0)
						X=12;
					limpar_flash2e4(X,20);
					limpar_flash1e3(X,20);
					
					X+=2;
					if(X<120)
						animaflash1(X,20);  //maior logo 13 linhas
				}
				else
					if(j<8+4*c+12*c)
					{
						limpar_flash1e3(X,20);
						limpar_flash2e4(X,20);
						X+=2;
						if(X<110)
							animaflash2(X,20);
					}
				else	
					if(j<12+4*c+12*c)
					{
						limpar_flash1e3(X,20);
						limpar_flash2e4(X,20);
						X+=2;
						if(X<110)
							animaflash3(X,20);
					}
				else
					if(j<16+4*c+12*c)
					{
						limpar_flash1e3(X,20);
						limpar_flash2e4(X,20);
						X+=2;
						if(X<110)
							animaflash4(X,20);
					}
				else
					{
						limpar_flash1e3(X,20);
						limpar_flash2e4(X,20);
					}
			}
			if (i==1)
			{
			//	vingadores(50,5);
			//	gotoxy(2,2);printf("%d e %d e %d",c,4+4*c+12*c,(j+1)%16);
				textbackground(15);
				if(j<4+4*c+12*c)
				{
					limpar_vingadores4(X,18);
					limpar_vingadores2(X,21);
					limpar_vingadores1e3(X,20);
					if(X==0)
						X=12;
					X+=2;
					if(X<100)
						animavingadores1e3(X,20);  //maior logo 13 linhas
				}
				else
					if(j<8+4*c+12*c)
					{
						limpar_vingadores4(X,18);
						limpar_vingadores2(X,21);
						limpar_vingadores1e3(X,20);
						X+=2;
						if(X<100)
							animavingadores2(X,21);
					}
				else	
					if(j<12+4*c+12*c)
					{
						limpar_vingadores4(X,18);
						limpar_vingadores2(X,21);
						limpar_vingadores1e3(X,20);
						X+=2;
						if(X<100)
							animavingadores1e3(X,20);
					}
				else
					if(j<16+4*c+12*c)
					{
						limpar_vingadores4(X,18);
						limpar_vingadores2(X,21);
						limpar_vingadores1e3(X,20);
						X+=2;
						if(X<100)
							animavingadores4(X,18);
					}
				else
					{
						limpar_vingadores4(X,18);
						limpar_vingadores2(X,21);
						limpar_vingadores1e3(X,20);
					}
			}
			if (i==2)
			{
			//	superman(50,5);
			//	gotoxy(2,2);printf("%d e %d e %d",c,4+4*c+8*c,(j+1)%16);
				if(j<4+4*C+8*C)
				{
					limpar_superman1(X,20);
					limpar_superman2(X,20);
					limpar_superman3(X,20);
					if(X==0)
						X=12;
					X+=2;
					if(X<100)
						animasuperman1(X,20);  //maior logo 13 linhas
				}
				else
					if(j<8+4*C+8*C)
					{
						limpar_superman1(X,20);
						limpar_superman2(X,20);
						limpar_superman3(X,20);
						X+=2;
						if(X<100)
						{
							animasuperman2(X,20);
						}
					}
				else	
					if(j<12+4*C+8*C)
					{
						limpar_superman1(X,20);
						limpar_superman2(X,20);
						limpar_superman3(X,20);
						X+=2;
						if(X<100)
							animasuperman3(X,20);
					}
				else
				{
					limpar_superman1(X,20);
					limpar_superman2(X,20);
					limpar_superman3(X,20);
				}
			}
				if (i==3)
				{
				//	liga_da_justica(50,5);
					limpar_ligadajustica(X,20);
					X+=2;
					if(X<100)
						animaligadajustica(X,20);
				}
				textbackground(4);
				gotoxy(x,y);printf("  ");
				x+=2;
			//	getch();
				Sleep(30);
			}
		}
}

//----------------------------------------------------------------------------------------------------------------------------------

void inicial()
{
	carregando(5,32);
	nome(2,4);
	textcolor(5);
	gotoxy(5,30);printf("Aperte enter para iniciar");
	cursor(0);
	char comeco;
	do
	{
		comeco=getch();
		if (comeco=='\r')
		{
			cursor(1);
			system("cls");
			return;
		}
	}while(true);
	
}

//----------------------------------------------------------------------------------------------------------------------------------

void dc_logo(int x,int y)
{
	gotoxy(5,4);
	textbackground(11); //espaço
	//textbackground(15); //asterisco
	textcolor(11);
	//linha 1
	gotoxy(x,y);printf("#########");
	Sleep(50);
	//linha 2
	gotoxy(x-2,y+1);printf("##");
	gotoxy(x+9,y+1);printf("##");
	Sleep(50);
	//linha 3                               
	gotoxy(x-4,y+2);printf("##");
	gotoxy(x+11,y+2);printf("##");
	Sleep(50);
	//linha 4                                 
	gotoxy(x-6,y+3);printf("##");
	gotoxy(x-1,y+3);printf("###");
	gotoxy(x+6,y+3);printf("####");
	gotoxy(x+13,y+3);printf("##");
	Sleep(50);
	//linha 5                                   
	gotoxy(x-7,y+4);printf("#");
	gotoxy(x-1,y+4);printf("#");
	gotoxy(x+2,y+4);printf("#");
	gotoxy(x+5,y+4);printf("#");
	gotoxy(x+10,y+4);printf("#");
	gotoxy(x+15,y+4);printf("#");
	Sleep(50);
	//linha 6                          
	gotoxy(x-7,y+5);printf("#");
	gotoxy(x-1,y+5);printf("#");
	gotoxy(x+3,y+5);printf("#");
	gotoxy(x+5,y+5);printf("#");
	gotoxy(x+15,y+5);printf("#");
	Sleep(50);
	//linha 7
	gotoxy(x-7,y+6);printf("#");
	gotoxy(x-1,y+6);printf("#");
	gotoxy(x+3,y+6);printf("#");
	gotoxy(x+5,y+6);printf("#");
	gotoxy(x+15,y+6);printf("#");
	Sleep(50);
	//linha 8
	gotoxy(x-7,y+7);printf("#");
	gotoxy(x-1,y+7);printf("#");
	gotoxy(x+2,y+7);printf("#");
	gotoxy(x+5,y+7);printf("#");
	gotoxy(x+10,y+7);printf("#");
	gotoxy(x+15,y+7);printf("#");
	Sleep(50);
	//linha 9
	gotoxy(x-7,y+8);printf("#");
	gotoxy(x-1,y+8);printf("###");
	gotoxy(x+6,y+8);printf("####");
	gotoxy(x+15,y+8);printf("#");
	Sleep(50);
	//linha 10
	gotoxy(x-6,y+9);printf("##");
	gotoxy(x+13,y+9);printf("##");
	Sleep(50);
	//linha 11
	gotoxy(x-4,y+10);printf("##");
	gotoxy(x+11,y+10);printf("##");
	Sleep(50);
	//linha 12
	gotoxy(x-2,y+11);printf("##");
	gotoxy(x+9,y+11);printf("##");
	Sleep(50);
	//linha 13
	gotoxy(x,y+12);printf("#########");
	Sleep(50);
	textbackground(15);
	textcolor(6);
}

//----------------------------------------------------------------------------------------------------------------------------------

void marvel_logo(int x, int y)
{
	textbackground(12);//espaço
	textcolor(12); 
	//textbackground(15); //asterisco
	//coluna 1
	gotoxy(x,y);printf("#");
	gotoxy(x,y+1);printf("#");
	gotoxy(x,y+2);printf("#");
	gotoxy(x,y+3);printf("#");
	gotoxy(x,y+4);printf("#");
	gotoxy(x,y+5);printf("#");
	gotoxy(x,y+6);printf("#");
	Sleep(20);
	// coluna 2
	gotoxy(x+1,y);printf("#");
	gotoxy(x+1,y+1);printf("#");
	gotoxy(x+1,y+2);printf("#");
	gotoxy(x+1,y+3);printf("#");
	gotoxy(x+1,y+4);printf("#");
	gotoxy(x+1,y+5);printf("#");
	gotoxy(x+1,y+6);printf("#");
	Sleep(20);
	// coluna 3
	gotoxy(x+2,y);printf("#");
	gotoxy(x+2,y+1);printf("#");
	gotoxy(x+2,y+2);printf("#");
	gotoxy(x+2,y+3);printf("#");
	gotoxy(x+2,y+4);printf("#");
	gotoxy(x+2,y+5);printf("#");
	gotoxy(x+2,y+6);printf("#");
	Sleep(20);
	// coluna 4
	gotoxy(x+3,y);printf("#");
	gotoxy(x+3,y+1);printf("#");
	gotoxy(x+3,y+6);printf("#");
	Sleep(20);
	// coluna 5
	gotoxy(x+4,y);printf("#");
	gotoxy(x+4,y+2);printf("#");
	gotoxy(x+4,y+3);printf("#");
	gotoxy(x+4,y+4);printf("#");
	gotoxy(x+4,y+5);printf("#");
	gotoxy(x+4,y+6);printf("#");
	Sleep(20);
	// coluna 6
	gotoxy(x+5,y);printf("#");
	gotoxy(x+5,y+2);printf("#");
	gotoxy(x+5,y+3);printf("#");
	gotoxy(x+5,y+4);printf("#");
	gotoxy(x+5,y+5);printf("#");
	gotoxy(x+5,y+6);printf("#");
	Sleep(20);
	// coluna 7
	gotoxy(x+6,y);printf("#");
	gotoxy(x+6,y+1);printf("#");
	gotoxy(x+6,y+3);printf("#");
	gotoxy(x+6,y+4);printf("#");
	gotoxy(x+6,y+5);printf("#");
	gotoxy(x+6,y+6);printf("#");
	Sleep(20);
	// coluna 8
	gotoxy(x+7,y);printf("#");
	gotoxy(x+7,y+1);printf("#");
	gotoxy(x+7,y+2);printf("#");
	gotoxy(x+7,y+4);printf("#");
	gotoxy(x+7,y+5);printf("#");
	gotoxy(x+7,y+6);printf("#");
	Sleep(20);
	//coluna 9
	gotoxy(x+8,y);printf("#");
	gotoxy(x+8,y+1);printf("#");
	gotoxy(x+8,y+3);printf("#");
	gotoxy(x+8,y+4);printf("#");
	gotoxy(x+8,y+5);printf("#");
	gotoxy(x+8,y+6);printf("#");
	Sleep(20);
	//coluna 10
	gotoxy(x+9,y);printf("#");
	gotoxy(x+9,y+2);printf("#");
	gotoxy(x+9,y+3);printf("#");
	gotoxy(x+9,y+4);printf("#");
	gotoxy(x+9,y+5);printf("#");
	gotoxy(x+9,y+6);printf("#");
	Sleep(20);
	//coluna 11
	gotoxy(x+10,y);printf("#");
	gotoxy(x+10,y+2);printf("#");
	gotoxy(x+10,y+3);printf("#");
	gotoxy(x+10,y+4);printf("#");
	gotoxy(x+10,y+5);printf("#");
	gotoxy(x+10,y+6);printf("#");
	Sleep(20);
	// coluna 12
	gotoxy(x+11,y);printf("#");
	gotoxy(x+11,y+1);printf("#");
	gotoxy(x+11,y+6);printf("#");
	Sleep(20);
	// coluna 13
	gotoxy(x+12,y);printf("#");
	gotoxy(x+12,y+1);printf("#");
	gotoxy(x+12,y+2);printf("#");
	gotoxy(x+12,y+3);printf("#");
	gotoxy(x+12,y+4);printf("#");
	gotoxy(x+12,y+5);printf("#");
	gotoxy(x+12,y+6);printf("#");
	Sleep(20);
	// coluna 14
	gotoxy(x+13,y);printf("#");
	gotoxy(x+13,y+1);printf("#");
	gotoxy(x+13,y+2);printf("#");
	gotoxy(x+13,y+3);printf("#");
	gotoxy(x+13,y+4);printf("#");
	gotoxy(x+13,y+6);printf("#");
	Sleep(20);
	// coluna 15
	gotoxy(x+14,y);printf("#");
	gotoxy(x+14,y+1);printf("#");
	gotoxy(x+14,y+2);printf("#");
	gotoxy(x+14,y+3);printf("#");
	gotoxy(x+14,y+5);printf("#");
	gotoxy(x+14,y+6);printf("#");
	// coluna 16
	gotoxy(x+15,y);printf("#");
	gotoxy(x+15,y+1);printf("#");
	gotoxy(x+15,y+2);printf("#");
	gotoxy(x+15,y+4);printf("#");
	gotoxy(x+15,y+5);printf("#");
	gotoxy(x+15,y+6);printf("#");
	Sleep(20);
	// coluna 17
	gotoxy(x+16,y);printf("#");
	gotoxy(x+16,y+1);printf("#");
	gotoxy(x+16,y+4);printf("#");
	gotoxy(x+16,y+5);printf("#");
	gotoxy(x+16,y+6);printf("#");
	Sleep(20);
	// coluna 18
	gotoxy(x+17,y);printf("#");
	gotoxy(x+17,y+2);printf("#");
	gotoxy(x+17,y+4);printf("#");
	gotoxy(x+17,y+5);printf("#");
	gotoxy(x+17,y+6);printf("#");
	Sleep(20);
	// coluna 19
	gotoxy(x+18,y);printf("#");
	gotoxy(x+18,y+2);printf("#");
	gotoxy(x+18,y+4);printf("#");
	gotoxy(x+18,y+5);printf("#");
	gotoxy(x+18,y+6);printf("#");
	Sleep(20);
	// coluna 20
	gotoxy(x+19,y);printf("#");
	gotoxy(x+19,y+1);printf("#");
	gotoxy(x+19,y+4);printf("#");
	gotoxy(x+19,y+5);printf("#");
	gotoxy(x+19,y+6);printf("#");
	Sleep(20);
	// coluna 21
	gotoxy(x+20,y);printf("#");
	gotoxy(x+20,y+1);printf("#");
	gotoxy(x+20,y+2);printf("#");
	gotoxy(x+20,y+4);printf("#");
	gotoxy(x+20,y+5);printf("#");
	gotoxy(x+20,y+6);printf("#");
	Sleep(20);
	// coluna 22
	gotoxy(x+21,y);printf("#");
	gotoxy(x+21,y+1);printf("#");
	gotoxy(x+21,y+2);printf("#");
	gotoxy(x+21,y+3);printf("#");
	gotoxy(x+21,y+5);printf("#");
	gotoxy(x+21,y+6);printf("#");
	Sleep(20);
	// coluna 23
	gotoxy(x+22,y);printf("#");
	gotoxy(x+22,y+1);printf("#");
	gotoxy(x+22,y+2);printf("#");
	gotoxy(x+22,y+3);printf("#");
	gotoxy(x+22,y+4);printf("#");
	gotoxy(x+22,y+6);printf("#");
	Sleep(20);
	// coluna 24
	gotoxy(x+23,y);printf("#");
	gotoxy(x+23,y+1);printf("#");
	gotoxy(x+23,y+2);printf("#");
	gotoxy(x+23,y+3);printf("#");
	gotoxy(x+23,y+4);printf("#");
	gotoxy(x+23,y+5);printf("#");
	gotoxy(x+23,y+6);printf("#");
	Sleep(20);
	// coluna 25
	gotoxy(x+24,y);printf("#");
	gotoxy(x+24,y+6);printf("#");
	Sleep(20);
	// coluna 26
	gotoxy(x+25,y);printf("#");
	gotoxy(x+25,y+2);printf("#");
	gotoxy(x+25,y+4);printf("#");
	gotoxy(x+25,y+5);printf("#");
	gotoxy(x+25,y+6);printf("#");
	Sleep(20);
	// coluna 27
	gotoxy(x+26,y);printf("#");
	gotoxy(x+26,y+2);printf("#");
	gotoxy(x+26,y+4);printf("#");
	gotoxy(x+26,y+5);printf("#");
	gotoxy(x+26,y+6);printf("#");
	Sleep(20);
	// coluna 28
	gotoxy(x+27,y);printf("#");
	//gotoxy(x+27,y+1);printf("#"); //ver se fica bom
	gotoxy(x+27,y+3);printf("#");
	gotoxy(x+27,y+5);printf("#");
	gotoxy(x+27,y+6);printf("#");
	Sleep(20);
	// coluna 29
	gotoxy(x+28,y);printf("#");
	gotoxy(x+28,y+1);printf("#");
	gotoxy(x+28,y+2);printf("#");
	gotoxy(x+28,y+3);printf("#");
	gotoxy(x+28,y+4);printf("#");
	gotoxy(x+28,y+6);printf("#");
	Sleep(20);
	// coluna 30
	gotoxy(x+29,y);printf("#");
	gotoxy(x+29,y+1);printf("#");
	gotoxy(x+29,y+2);printf("#");
	gotoxy(x+29,y+3);printf("#");
	gotoxy(x+29,y+4);printf("#");
	gotoxy(x+29,y+5);printf("#");
	gotoxy(x+29,y+6);printf("#");
	Sleep(20);
	// coluna 31
	gotoxy(x+30,y);printf("#");
	gotoxy(x+30,y+2);printf("#");
	gotoxy(x+30,y+3);printf("#");
	gotoxy(x+30,y+4);printf("#");
	gotoxy(x+30,y+5);printf("#");
	gotoxy(x+30,y+6);printf("#");
	Sleep(20);
	// coluna 32
	gotoxy(x+31,y);printf("#");
	gotoxy(x+31,y+1);printf("#");
	gotoxy(x+31,y+3);printf("#");
	gotoxy(x+31,y+4);printf("#");
	gotoxy(x+31,y+5);printf("#");
	gotoxy(x+31,y+6);printf("#");
	Sleep(20);
	// coluna 33
	gotoxy(x+32,y);printf("#");
	gotoxy(x+32,y+1);printf("#");
	gotoxy(x+32,y+2);printf("#");
	gotoxy(x+32,y+4);printf("#");
	gotoxy(x+32,y+5);printf("#");
	gotoxy(x+32,y+6);printf("#");
	Sleep(20);
	// coluna 34
	gotoxy(x+33,y);printf("#");
	gotoxy(x+33,y+1);printf("#");
	gotoxy(x+33,y+2);printf("#");
	gotoxy(x+33,y+3);printf("#");
	gotoxy(x+33,y+5);printf("#");
	gotoxy(x+33,y+6);printf("#");
	Sleep(20);
	// coluna 35
	gotoxy(x+34,y);printf("#");
	gotoxy(x+34,y+1);printf("#");
	gotoxy(x+34,y+2);printf("#");
	gotoxy(x+34,y+3);printf("#");
	gotoxy(x+34,y+4);printf("#");
	gotoxy(x+34,y+6);printf("#");
	Sleep(20);
	// coluna 36
	gotoxy(x+35,y);printf("#");
	gotoxy(x+35,y+1);printf("#");
	gotoxy(x+35,y+2);printf("#");
	gotoxy(x+35,y+3);printf("#");
	gotoxy(x+35,y+5);printf("#");
	gotoxy(x+35,y+6);printf("#");
	Sleep(20);
	// coluna 37
	gotoxy(x+36,y);printf("#");
	gotoxy(x+36,y+1);printf("#");
	gotoxy(x+36,y+2);printf("#");
	gotoxy(x+36,y+4);printf("#");
	gotoxy(x+36,y+5);printf("#");
	gotoxy(x+36,y+6);printf("#");
	Sleep(20);
	// coluna 38
	gotoxy(x+37,y);printf("#");
	gotoxy(x+37,y+1);printf("#");
	gotoxy(x+37,y+3);printf("#");
	gotoxy(x+37,y+4);printf("#");
	gotoxy(x+37,y+5);printf("#");
	gotoxy(x+37,y+6);printf("#");
	Sleep(20);
	// coluna 39
	gotoxy(x+38,y);printf("#");
	gotoxy(x+38,y+2);printf("#");
	gotoxy(x+38,y+3);printf("#");
	gotoxy(x+38,y+4);printf("#");
	gotoxy(x+38,y+5);printf("#");
	gotoxy(x+38,y+6);printf("#");
	Sleep(20);
	// coluna 40
	gotoxy(x+39,y);printf("#");
	gotoxy(x+39,y+1);printf("#");
	gotoxy(x+39,y+2);printf("#");
	gotoxy(x+39,y+3);printf("#");
	gotoxy(x+39,y+4);printf("#");
	gotoxy(x+39,y+5);printf("#");
	gotoxy(x+39,y+6);printf("#");
	Sleep(20);
	// coluna 41
	gotoxy(x+40,y);printf("#");
	gotoxy(x+40,y+6);printf("#");
	Sleep(20);
	// coluna 42
	gotoxy(x+41,y);printf("#");
	gotoxy(x+41,y+2);printf("#");
	gotoxy(x+41,y+4);printf("#");
	gotoxy(x+41,y+6);printf("#");
	Sleep(20);
	// coluna 43
	gotoxy(x+42,y);printf("#");
	gotoxy(x+42,y+2);printf("#");
	gotoxy(x+42,y+4);printf("#");
	gotoxy(x+42,y+6);printf("#");
	Sleep(20);
	// coluna 44
	gotoxy(x+43,y);printf("#");
	gotoxy(x+43,y+2);printf("#");
	gotoxy(x+43,y+3);printf("#");
	gotoxy(x+43,y+4);printf("#");
	gotoxy(x+43,y+6);printf("#");
	Sleep(20);
	// coluna 45
	gotoxy(x+44,y);printf("#");
	gotoxy(x+44,y+2);printf("#");
	gotoxy(x+44,y+3);printf("#");
	gotoxy(x+44,y+4);printf("#");
	gotoxy(x+44,y+6);printf("#");
	Sleep(20);
	// coluna 46
	gotoxy(x+45,y);printf("#");
	gotoxy(x+45,y+1);printf("#");
	gotoxy(x+45,y+2);printf("#");
	gotoxy(x+45,y+3);printf("#");
	gotoxy(x+45,y+4);printf("#");
	gotoxy(x+45,y+5);printf("#");
	gotoxy(x+45,y+6);printf("#");
	Sleep(20);
	// coluna 47
	gotoxy(x+46,y);printf("#");
	gotoxy(x+46,y+6);printf("#");
	Sleep(20);
	// coluna 48
	gotoxy(x+47,y);printf("#");
	gotoxy(x+47,y+1);printf("#");
	gotoxy(x+47,y+2);printf("#");
	gotoxy(x+47,y+3);printf("#");
	gotoxy(x+47,y+4);printf("#");
	gotoxy(x+47,y+6);printf("#");
	Sleep(20);
	// coluna 49
	gotoxy(x+48,y);printf("#");
	gotoxy(x+48,y+1);printf("#");
	gotoxy(x+48,y+2);printf("#");
	gotoxy(x+48,y+3);printf("#");
	gotoxy(x+48,y+4);printf("#");
	gotoxy(x+48,y+6);printf("#");
	Sleep(20);
	// coluna 50
	gotoxy(x+49,y);printf("#");
	gotoxy(x+49,y+1);printf("#");
	gotoxy(x+49,y+2);printf("#");
	gotoxy(x+49,y+3);printf("#");
	gotoxy(x+49,y+4);printf("#");
	gotoxy(x+49,y+6);printf("#");
	Sleep(20);
	// coluna 51
	gotoxy(x+50,y);printf("#");
	gotoxy(x+50,y+1);printf("#");
	gotoxy(x+50,y+2);printf("#");
	gotoxy(x+50,y+3);printf("#");
	gotoxy(x+50,y+4);printf("#");
	gotoxy(x+50,y+6);printf("#");
	Sleep(20);
	// coluna 52
	gotoxy(x+51,y);printf("#");
	gotoxy(x+51,y+1);printf("#");
	gotoxy(x+51,y+2);printf("#");
	gotoxy(x+51,y+3);printf("#");
	gotoxy(x+51,y+4);printf("#");
	gotoxy(x+51,y+5);printf("#");
	gotoxy(x+51,y+6);printf("#");
	Sleep(20);
	// coluna 53
	gotoxy(x+52,y);printf("#");
	gotoxy(x+52,y+1);printf("#");
	gotoxy(x+52,y+2);printf("#");
	gotoxy(x+52,y+3);printf("#");
	gotoxy(x+52,y+4);printf("#");
	gotoxy(x+52,y+5);printf("#");
	gotoxy(x+52,y+6);printf("#");
	Sleep(20);
	// coluna 54
	gotoxy(x+52,y);printf("#");
	gotoxy(x+52,y+1);printf("#");
	gotoxy(x+52,y+2);printf("#");
	gotoxy(x+52,y+3);printf("#");
	gotoxy(x+52,y+4);printf("#");
	gotoxy(x+52,y+5);printf("#");
	gotoxy(x+52,y+6);printf("#");
	Sleep(20);
}

//----------------------------------------------------------------------------------------------------------------------------------


void dc_parado (int x, int y)
{
	gotoxy(5,4);
	textbackground(11); //espaço
	//textbackground(15); //asterisco
	textcolor(11);
	//linha 1
	gotoxy(x,y);printf("#########");
	
	//linha 2
	gotoxy(x-2,y+1);printf("##");
	gotoxy(x+9,y+1);printf("##");
	
	//linha 3                               
	gotoxy(x-4,y+2);printf("##");
	gotoxy(x+11,y+2);printf("##");
	
	//linha 4                                 
	gotoxy(x-6,y+3);printf("##");
	gotoxy(x-1,y+3);printf("###");
	gotoxy(x+6,y+3);printf("####");
	gotoxy(x+13,y+3);printf("##");
	
	//linha 5                                   
	gotoxy(x-7,y+4);printf("#");
	gotoxy(x-1,y+4);printf("#");
	gotoxy(x+2,y+4);printf("#");
	gotoxy(x+5,y+4);printf("#");
	gotoxy(x+10,y+4);printf("#");
	gotoxy(x+15,y+4);printf("#");
	
	//linha 6                          
	gotoxy(x-7,y+5);printf("#");
	gotoxy(x-1,y+5);printf("#");
	gotoxy(x+3,y+5);printf("#");
	gotoxy(x+5,y+5);printf("#");
	gotoxy(x+15,y+5);printf("#");
	
	//linha 7
	gotoxy(x-7,y+6);printf("#");
	gotoxy(x-1,y+6);printf("#");
	gotoxy(x+3,y+6);printf("#");
	gotoxy(x+5,y+6);printf("#");
	gotoxy(x+15,y+6);printf("#");
	
	//linha 8
	gotoxy(x-7,y+7);printf("#");
	gotoxy(x-1,y+7);printf("#");
	gotoxy(x+2,y+7);printf("#");
	gotoxy(x+5,y+7);printf("#");
	gotoxy(x+10,y+7);printf("#");
	gotoxy(x+15,y+7);printf("#");
	
	//linha 9
	gotoxy(x-7,y+8);printf("#");
	gotoxy(x-1,y+8);printf("###");
	gotoxy(x+6,y+8);printf("####");
	gotoxy(x+15,y+8);printf("#");
	
	//linha 10
	gotoxy(x-6,y+9);printf("##");
	gotoxy(x+13,y+9);printf("##");
	
	//linha 11
	gotoxy(x-4,y+10);printf("##");
	gotoxy(x+11,y+10);printf("##");
	
	//linha 12
	gotoxy(x-2,y+11);printf("##");
	gotoxy(x+9,y+11);printf("##");
	
	//linha 13
	gotoxy(x,y+12);printf("#########");
	
	textbackground(15);
	textcolor(6);
}

//----------------------------------------------------------------------------------------------------------------------------------

main(){
	
	char c;
	int a=16;
	int sair;
	
	textbackground(15);
	SetConsoleTitle("PLATAFORMA MULTIVERSO");
	system("mode con:cols=120 lines=40"); //aumenta a tela para 120 colunas e 40 linhas
	
	cursor(0);//ocultar cursor
	textbackground(15);
	system("cls");
	inicial();
	
	textcolor(6); // cor de letra
	textbackground(15); // cor de fundo
	system("cls"); // limpar/pintar a tela
	cursor(0);//ocultar cursor
	
	dc_logo(80,15);
	
	do
	{
		sair=1;
		dc_parado(80,15);
		borda();
		textbackground(15);
		textcolor(9);
		logo_nome(57,1);
		textbackground(11);
		gotoxy(2,2);printf("                                                    ");
		gotoxy(68,2);printf("                                                    ");
		gotoxy(2,39);printf("                                                                                                                      ");
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(2,i);printf(" ");
		}
		for(int i=2; i<=39; i++)
		{
			textbackground(11);
			gotoxy(119,i);printf(" ");
		}
		textcolor(9);
		textbackground(15);
		gotoxy(35,13);printf("PLATAFORMA MULTIVERSO");
		gotoxy(27,16);printf("Cadastro");
		           //135 é o caractere 'ç' e 198 é o caractere 'ã'
		gotoxy(27,18);printf("Pesquisa", 135, 198);
		gotoxy(27,20);printf("Alterar", 135, 198);
		gotoxy(27,22);printf("Excluir", 135, 198);
		gotoxy(27,24);printf("Jogos");
		gotoxy(27,26);printf("Sobre n%cs",162);
		gotoxy(27,28);printf("Sair");
		gotoxy(25,a); printf("%c", 62);//62 é o caractere '>'
		c=getch();
		gotoxy(25,a); printf(" ");
	
		switch(c)//movimento das setas
		{
			case 72 : //seta para cima
				a-=2;
				if(a<16)
				{
					a=28;	
				}
				gotoxy(25,a); printf("%c", 62);
				break;
			case 80 : //seta para baixo
				a+=2;
				if(a>28)
				{
					a=16;
				}
				gotoxy(25,a); printf("%c", 62);
				break;
			case 13: //teclou enter
				if(a==16)
				{ 
					system("cls");
					abrir_arquivo_cad("ab+");
					digita_dados();
					system("cls");
				}
				else
				if(a==18)
				{
					system("cls");
					pesquisa();
					system("cls");
				}
				else
				if(a==20)
				{
					system("cls");
					alterar();
					system("cls");
				}
				else
				if(a==22)
				{
					system("cls");
					excluir();
					system("cls");
				}
				else
				if(a==24)
				{
					system("cls");
					jogos();
					system("cls");
				}
				else
				if (a==26)
				{
					system("cls");
					sobre_nos();
					system("cls");	
				}
				if(a==28)
				{
					system("cls");
					gotoxy(40,10);printf("Obrigado por utilizar o nosso sistema!");
					sair=0;
				}
		}//final switch(c)

	}while(sair); //final do while
	cursor(1);//mostrar cursor
//	gotoxy(40,11);printf("N%co tecle nada, aguarde a pausa...", 198);
	Sleep(2000);
}

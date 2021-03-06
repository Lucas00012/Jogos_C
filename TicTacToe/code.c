#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

char cmc[10];
int jogoAtivo=1;
char t[3][3]={
							{' ',' ',' '},
							{' ',' ',' '},
							{' ',' ',' '}
											};
void jogar(int s);
void mostrarJogada(void);
void cpuJoga(void);
void vencedor(void);

void jogar(int s){
	if(jogoAtivo){
		if(s){
			int i,i1;
			puts("\n\n");
			printf("posicao? ");
			scanf("%d %d",&i,&i1);
			while(t[i][i1]!=' '){
				printf("JOGADA INVALIDA\n");
				printf("posicao? ");
				scanf("%d %d",&i,&i1);
			}
			t[i][i1]='x';
			mostrarJogada();
			vencedor();
			s=0;
		}
		else{
			cpuJoga();
			s=1;
		}
		jogar(s);
	}
}

void mostrarJogada(void){
	_clrscr();
	printf("====== TIC TAC TOE ======");
	puts("\n\n");
	printf("  0   1   2\n");
	printf("0 %c | %c | %c ",t[0][0],t[0][1],t[0][2]);
	printf("\n -----------\n");
	printf("1 %c | %c | %c ",t[1][0],t[1][1],t[1][2]);
	printf("\n -----------\n");
	printf("2 %c | %c | %c ",t[2][0],t[2][1],t[2][2]);
	printf("      QUEM COMECA: %s",cmc);
}

void vencedor(void){
	char p[]={'o','x'};
	int venceu=0;
	for(int i1=0;i1<2;i1++){
		if(t[0][0]==p[i1] && t[1][1]==p[i1] && t[2][2]==p[i1]) venceu=1;
		else if(t[0][2]==p[i1] && t[1][1]==p[i1] && t[2][0]==p[i1]) venceu=1;
		for(int i=0;i<3;i++){
			if(t[i][0]==p[i1] && t[i][1]==p[i1] && t[i][2]==p[i1]) venceu=1;
			else if(t[0][i]==p[i1] && t[1][i]==p[i1] && t[2][i]==p[i1]) venceu=1;
		}
	}
	int preenchido=1;
	for(int i1=0;i1<3;i1++){
		for(int i=0;i<3;i++) if(t[i][i1]==' ') preenchido=0;
	}
	if(venceu || preenchido){
		_gotoxy(1,15);
		printf("FIM DE JOGO!\n");
		jogoAtivo=0;
	}
}

void cpuJoga(void){
	char p[]={'o','x'};
	int jogou=0;
	for(int i1=0;i1<2;i1++){
		if(jogou==0){
			jogou=1;
			if(t[0][0]==' ' && t[1][1]==p[i1] && t[2][2]==p[i1]) t[0][0]='o';
			else if(t[0][0]==p[i1] && t[1][1]==' ' && t[2][2]==p[i1]) t[1][1]='o';
			else if(t[0][0]==p[i1] && t[1][1]==p[i1] && t[2][2]==' ') t[2][2]='o';
			else if(t[0][2]==' ' && t[1][1]==p[i1] && t[2][0]==p[i1]) t[0][2]='o';
			else if(t[0][2]==p[i1] && t[1][1]==' ' && t[2][0]==p[i1]) t[1][1]='o';
			else if(t[0][2]==p[i1] && t[1][1]==p[i1] && t[2][0]==' ') t[2][0]='o';
			else jogou=0;
			vencedor();
		}
		if(jogou==0){
			for(int i=0;i<3 && jogou==0;i++){
				jogou=1;
				if(t[i][0]==p[i1] && t[i][1]==p[i1] && t[i][2]==' ') t[i][2]='o';
				else if(t[i][0]==p[i1] && t[i][1]==' ' && t[i][2]==p[i1]) t[i][1]='o';
				else if(t[i][0]==' ' && t[i][1]==p[i1] && t[i][2]==p[i1]) t[i][0]='o';
				else if(t[0][i]==p[i1] && t[1][i]==p[i1] && t[2][i]==' ') t[2][i]='o';
				else if(t[0][i]==p[i1] && t[1][i]==' ' && t[2][i]==p[i1]) t[1][i]='o';
				else if(t[0][i]==' ' && t[1][i]==p[i1] && t[2][i]==p[i1]) t[0][i]='o';
				else jogou=0;
				vencedor();
			}
		}
	}
	if(jogou==0){
		int lin=rand()%3;
		int col=rand()%3;
		while(t[lin][col]!=' '){
			lin=rand()%3;
			col=rand()%3;
		}
		t[lin][col]='o';
	}
	mostrarJogada();
	vencedor();
}


int main(void){
	srand(time(NULL));
	char cpu[]="CPU";
	char player[]="PLAYER";
	int s=rand()%2;
	if(s){
		for(int i=0;i<8;i++) cmc[i]=player[i];
	}
	else{
		for(int i=0;i<5;i++) cmc[i]=cpu[i];
	}
	mostrarJogada();
	jogar(s);
	return 0;
}

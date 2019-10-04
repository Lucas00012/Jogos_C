#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
int jogoAtivo;
int vidas;
char palavras[][20]={
	"CARRO",
	"FACULDADE",
	"ESCOLA",
	"GELADEIRA",
	"COMPUTADOR",
	"HARDWARE",
	"COTONETE",
	"MELANCIA",
	"UVA",
	"ZEBRA",
	"ABACAXI",
	"ZOOLOGICO",
				};

void jogar(char v[],int n);
void mostrar(char v[]);
int t(char v[]);
int testeVitoria(char v[]);
void buscar(char v[],char letra,int n);

void buscar(char v[],char letra,int n){
	int achou=0;
	for(int i=0;i<t(v);i++) {
		if(palavras[n][i]==letra){
			v[i]=letra;
			achou=1;
		}
	}
	if(achou==0) vidas--;
	if(vidas==0 || testeVitoria(v)) jogoAtivo=0;
}

int testeVitoria(char v[]){
	for(int i=0;i<t(v);i++) if(v[i]=='_') return 0;
	return 1;
}

int t(char v[]){
	int i=0;
	while(v[i]) i++;
	return i;
}

void jogar(char v[],int n){
	if(jogoAtivo){
		char letra;
		printf("\n\nLetra? ");
		scanf("%c%c",&letra);
		while(letra<65 || letra>122){
			_clrscr();
			mostrar(v);
			puts("\n\nINVALIDO");
			printf("Letra? ");
			scanf("%c%c",&letra);
		}
		letra=toupper(letra);
		buscar(v,letra,n);
		_clrscr();
		mostrar(v);
		jogar(v,n);
	}
}

void mostrar(char v[]){
	printf("VIDAS: %d\n\n",vidas);
	printf("PALAVRA = ");
	for(int i=0;i<t(v);i++) printf("%c ",v[i]);
}

int main(void){
	srand(time(NULL));
	char novoJogo='S';
	while(novoJogo=='S'){
		_clrscr();
		vidas=5;
		jogoAtivo=1;
		int n=rand()%12;
		char sort[t(palavras[n])];
		int i;
		for(i=0;i<t(palavras[n]);i++) sort[i]='_';
		sort[i]='\0';
		mostrar(sort);
		jogar(sort,n);
		_gotoxy(1,10);
		puts("FIM DE JOGO!");
		printf("Jogar novamente? S/N\n");
		scanf("%c%c",&novoJogo);
		novoJogo=toupper(novoJogo);
		while(novoJogo!='S' && novoJogo!='N'){
			puts("INVALIDO\n");
			scanf("%c%c",&novoJogo);
			novoJogo=toupper(novoJogo);
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
int jogoAtivo=1;
int vidas=5;
int teste=0;

char palavras[][20]={
	"CARRO",
	"FACULDADE",
	"ESCOLA",
	"GELADEIRA",
	"COMPUTADOR",
	"HARDWARE",
	"COTONETE",
	"MELANCIA",
	"UVA"
				};

void jogar(char v[],int n);
void mostrar(char v[]);
int t(char v[]);
int testeVitoria(char v[]);
void buscar(char v[],char letra,int n);

void buscar(char v[],char letra,int n){
	teste++;
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
		scanf("%c",&letra);
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
	int n=rand()%9;
	char sort[t(palavras[n])];
	for(int i=0;i<t(palavras[n]);i++) sort[i]='_';
	mostrar(sort);
	jogar(sort,n);
	_gotoxy(1,10);
	puts("FIM DE JOGO!");
	printf("%d\n",teste);
	return 0;
}

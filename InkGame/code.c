#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main(void){
	int x=1,y=1,ativo=1,cor=7;
	char tecla;
	printf("================ INK GAME =================\n");
	printf("W-A-S-D: Mover cursor\nP: Cancelar pintura/Retornar pintura\nO: Trocar cor\nI: Borracha\n");
	printf("===========================================\n");
	printf("\n\n\n\n\nPressione qualquer tecla p/ comecar...");
	_getch();
	_clrscr();
	while(1){
		_gotoxy(x,y);
		_textcolor(cor);
		if(ativo==1) printf("%c",219);
		tecla=toupper(_getch());
		if(tecla=='W') y--;
		else if(tecla=='S') y++;
		else if(tecla=='D') x++;
		else if(tecla=='A') x--;
		else if(tecla=='P'){
			if(ativo==1) ativo=0;
			else ativo=1;
		}
		else if(tecla=='O'){
			cor++;
			if(cor==16) cor=1;
		}
		else if(tecla=='I') cor=0;
		if(x<1) x++;
		if(x>100) x--;
		if(y>28) y--;
		if(y<1) y++;
	}
	return 0;
}

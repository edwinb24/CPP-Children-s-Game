#include <dos.h>

#ifndef _RATON_H_
	#define _RATON_H_
	 //	int mirarRaton();
		void mostrarRaton();
		void ocultarRaton();
		int  posicionVertical();
		int  posicionHorizontal();
		int  botonPresionado();
    	union REGS i,o; //para el raton
#endif
		 
int  iniciarRaton(){
	i.x.ax=0;
	int86(0x33,&i,&o);
	return (o.x.ax);
}
/*
int mirarRaton(){
	asm xor ax, ax
	asm int 33h
	asm cmp ax, -1
	asm je  ExisteRaton
	return 0;

ExisteRaton:
return _BX;
} */

void mostrarRaton(){
 asm mov ax, 01h
 asm int 33h
}

void ocultarRaton(){
 asm mov ax, 02h
 asm int 33h
}

int posicionHorizontal(){
 asm mov ax, 03h
 asm int 33h
 return _CX;
}

int posicionVertical(){
 asm mov ax,03h
 asm int 33h
 return _DX;
 }

int botonPresionado(){
 asm mov ax, 03h
 asm int 33h
 return _BX;
}

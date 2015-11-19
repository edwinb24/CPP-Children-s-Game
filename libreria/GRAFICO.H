#include <dos.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef _GRAFICO_H_
	#define _GRAFICO_H_
		char corregirRGB(char c);
		int  imagen(int x1,int y1,char *imagen/*,int col*/);
		void menuprincipal(void);
		void secuencias_logicas(void);
		void mostrar_figuras(int combinacion);
		void busqueda_animales(void);
#endif

char corregirRGB(char color){
	switch(color){
		case  1: color= 4; break;      //BLUE 	 RED
		case  3: color= 6; break;      //CYAN 	 BROWN
		case  4: color= 1; break;      //RED 	   BLUE
		case  6: color= 3; break;      //BROWN   CYAN
		case  7: color= 8; break;      //LGRAY   DGRAY
		case  8: color= 7; break;      //DGRAY   LGRAY
		case  9: color=12; break;      //LBLUE   LRED
		case 11: color=14; break;      //LCYAN   YELLOW
		case 12: color= 9; break;      //LRED 	 LBLUE
		case 14: color=11; break;      //YELLOW  LCYAN
	}
	return color;
}


int imagen(int x1,int y1,char *imagen/*,int col*/){
	int cont=-1,tamx,tamy,c1,c2,x,y;
	FILE *fp;

	if((fp=fopen(imagen,"rb"))==NULL) return 0;

	while(cont++<=117){
		if(cont==18){
			tamx=fgetc(fp)|fgetc(fp)<<8;
			cont++;
		}
		else{
			if(cont==22)
			{
				tamy=fgetc(fp)|fgetc(fp)<<8;
				cont++;
			}
			else{
				fgetc(fp);
			}
		}
	}

	for(y=tamy+y1-1; y>=y1; y--){
		x=x1;
		while(x<tamx+x1){
			cont=0;
			while(cont++<4){

				c1=c2=fgetc(fp);
				c1>>=4;
				c2=c2&15;//saturacion?

				if(x++ < tamx+x1)
					putpixel(x-1, y, (c1=corregirRGB(c1))/* == col?getpixel(x,y):c1*/);
				if(x++ < tamx+x1)
					putpixel(x-1, y, (c2=corregirRGB(c2))/* == col?getpixel(x,y):c2*/);
			}
		}
	}

	fclose(fp);
	return 1;
}


/*MENU PRINCIPAL */

void menuprincipal(){
	setbkcolor(BLACK);
	imagen(0,0,"imagen\\fmenu.bmp"/*,0*/);
	setfillstyle(1,BLUE);
	setcolor(BLACK);
	rectangle(getmaxx()/4-1,getmaxy()/8-1,getmaxx()*3/4+1,getmaxy()/4+1);
	bar(getmaxx()/4,getmaxy()/8,getmaxx()*3/4,getmaxy()/4);

	settextstyle(7,HORIZ_DIR,6);
	setcolor(WHITE);
	outtextxy(getmaxx()/4+25,getmaxy()/8-5,"* MENU *");

	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
	setcolor(EGA_LIGHTBLUE);

	outtextxy(100,165,"1. Busqueda de animales.  ");
	outtextxy(100,205,"2. Juego de secuencias logicas. ");
	outtextxy(100,245,"3. Ordenar cosas. ");
	outtextxy(100,285,"4. Sus puntajes. ");
	outtextxy(100,325,"5. Salir. ");

	setfillstyle(1,GREEN);
	 setcolor(BLACK);
	 bar3d(500,170,550,190,2,1);
	setfillstyle(1,RED);
	 setcolor(BLACK);
	 bar3d(500,170+40,550,190+40,2,1);
	setfillstyle(1,MAGENTA);
	 setcolor(BLACK);
	 bar3d(500,170+80,550,190+80,2,1);
	setfillstyle(1,LIGHTBLUE);
	 setcolor(BLACK);
	 bar3d(500,170+120,550,190+120,2,1);
	setfillstyle(1,LIGHTGRAY);
	 setcolor(BLACK);
	 bar3d(500,170+160,550,190+160,2,1);
}


void busqueda_animales(){
	setbkcolor(MAGENTA);
	setcolor(BLACK);

 /*Titulo*/
	setfillstyle(1,WHITE);
	bar(getmaxx()/6,getmaxy()/10,getmaxx()*5/6,getmaxy()*2/10);
	rectangle(getmaxx()/6+1,getmaxy()/10+1,getmaxx()*5/6-1,getmaxy()*2/10-1);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	setcolor(BROWN);
	outtextxy(getmaxx()/6+20,getmaxy()/10+5,"EL MUNDO DE LOS NI¥OS");

 /*la imagen escogida*/
	setfillstyle(1,WHITE);
	bar(getmaxx()*9/16+20,getmaxy()/4,getmaxx()-30,getmaxy()*3/4);
	rectangle(getmaxx()*9/16+20-1,getmaxy()/4-1,getmaxx()-30+1,getmaxy()*3/4+1);
	rectangle(getmaxx()*9/16+22,getmaxy()/4+2,getmaxx()-30-2,getmaxy()*3/4-2);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	setcolor(RED);
	outtextxy(408,140+20,"Seleccione");
	outtextxy(405,200+20,"un animal");
	outtextxy(407,260+20,"de la lista");

 /*las imagenes aleatorias*/
	setfillstyle(1,DARKGRAY);
	setcolor(WHITE);
	bar(13,getmaxy()/4,getmaxx()*9/16+6,getmaxy()*3/4);
	rectangle(13,118,366,359);

 /*Los Nombres*/
	setfillstyle(1,YELLOW);
	setcolor(BLACK);
	bar(60,380,580,440);
	rectangle(61,381,579,439);
	line(61,409,579,409);

/*las 5 primeras*/
	line(61+103,381,61+103,409);
	line(61+206,381,61+206,409);
	line(61+312,381,61+312,409);
	line(61+418,381,61+418,409);

/*las 4 ultimas*/
	line(61+129,409,61+129,439);
	line(61+258,409,61+258,439);
	line(61+387,409,61+387,439);

/*Colocacion de los nombres*/
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
	setcolor(RED);

	outtextxy(61+25,381,"Bear");
	outtextxy(61+103+30,381,"Fish");
	outtextxy(61+206+30,381,"Frog");
	outtextxy(61+312+20,381,"Lamb");
	outtextxy(61+418+20,381,"Tiger");

	outtextxy(61+6,409,"Chipmunk");
	outtextxy(61+129+25,409,"Donkey");
	outtextxy(61+258+25,409,"Mouse");
	outtextxy(61+387+25,409,"Rabbit");
}

void secuencias_logicas(){
	setbkcolor(BLUE);
	setcolor(BLACK);

/*Titulo*/
	setfillstyle(1,WHITE);
	bar(getmaxx()/6,getmaxy()/10,getmaxx()*5/6,getmaxy()*2/10);
	rectangle(getmaxx()/6+1,getmaxy()/10+1,getmaxx()*5/6-1,getmaxy()*2/10-1);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	setcolor(RED);
	outtextxy(getmaxx()/6+20,getmaxy()/10+5,"EL MUNDO DE LOS NI¥OS");

/*la imagen del recuerdo*/
	setfillstyle(1,DARKGRAY);
	setcolor(GREEN);
	bar(getmaxx()*3/5,getmaxy()/3,getmaxx()*3/5+200,getmaxy()/3+200);
	rectangle(getmaxx()*3/5-1,getmaxy()/3-1,getmaxx()*3/5+200+1,getmaxy()/3+200+1);

	imagen(getmaxx()*3/5,getmaxy()/3,"imagen\\memoria.bmp"/*,0*/);

	setfillstyle(1,YELLOW);
	setcolor(RED);
	bar(30,getmaxy()/4,getmaxx()/2+20,getmaxy()*3/8);
	rectangle(30-1,getmaxy()/4-1,getmaxx()/2+20,getmaxy()*3/8+1);

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	setcolor(MAGENTA);
	outtextxy(30+20,getmaxy()/4+3,"JUEGO DE SECUENCIAS ");
	outtextxy(30+110,getmaxy()/4+28,"LOGICAS");

	bar(30,getmaxy()*3/8+10,getmaxx()/2+20,getmaxy()*3/4+20);
	rectangle(30,getmaxy()*3/8+10,getmaxx()/2+20,getmaxy()*3/4+20);

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	setcolor(GREEN);
	outtextxy(30+50,getmaxy()*5/8+30,"Memoriza el orden");
	outtextxy(30+70,getmaxy()*5/8+52,"de estas figuras.");
}


void figuras(int secuencia[]){
 int c, opc;
 randomize();
 setcolor(RED);
 setfillstyle(SOLID_FILL,RED);
 for(c=0;c<3;c++){
	opc=rand()%3;
	switch(opc){
	 case 0:
			 //triangulo
			 line(c*90+55,304,c*90+ 95,223);
			 line(c*90+55,304,c*90+135,304);
			 line(c*90+95,223,c*90+135,304);
			 secuencia[c]=0;
		 break;
	 case 1:
			 //estrella
			 line(c*90+ 95,223,c*90+106,252);  // 1 a 2
			 line(c*90+106,252,c*90+135,252);  // 2 a 3
			 line(c*90+135,252,c*90+112,270);  // 3 a 4
			 line(c*90+112,270,c*90+125,305);  // 4 a 5
			 line(c*90+125,305,c*90+ 95,283);  // 5 a 6
			 line(c*90+ 95,283,c*90+ 65,305);  // 6 a 7
			 line(c*90+ 65,305,c*90+ 78,270);  // 7 a 8
			 line(c*90+ 78,270,c*90+ 55,252);  // 8 a 9
			 line(c*90+ 55,252,c*90+ 85,252);  // 9 a 10
			 line(c*90+ 85,252,c*90+ 95,223);  // 10 a 1
			 secuencia[c]=1;
		 break;
	 case 2:
			 //circulo
			 circle(c*90+(50+45),220+45,40);
			 secuencia[c]=2;
		 break;
	}//cierra switch
	floodfill(c*90+78,290,RED);
 }//cierra for
}





int opciones(int secuencia[]){
 int f,c, opc,correcto=-1;
 randomize();
 setcolor(RED);
 setfillstyle(SOLID_FILL,RED);
 for(f=0;f<3;f++){
	if(correcto==-1 && (rand()%2==1 || f==2))
	 correcto=f;

	for(c=0;c<3;c++){
		if(f==correcto)
		 opc=secuencia[c];
		else
		 opc=rand()%3;

	switch(opc){
	 case 0:
			 //triangulo
			 line(c*90+55,f*90+194, c*90+ 95,f*90+113);
			 line(c*90+55,f*90+194, c*90+135,f*90+194);
			 line(c*90+95,f*90+113, c*90+135,f*90+194);
		 break;
	 case 1:
			 //estrella
			 line(c*90+ 95,f*90+113, c*90+106,f*90+142);  // 1 a 2
			 line(c*90+106,f*90+142, c*90+135,f*90+142);  // 2 a 3
			 line(c*90+135,f*90+142, c*90+112,f*90+160);  // 3 a 4
			 line(c*90+112,f*90+160, c*90+125,f*90+195);  // 4 a 5
			 line(c*90+125,f*90+195, c*90+ 95,f*90+173);  // 5 a 6
			 line(c*90+ 95,f*90+173, c*90+ 65,f*90+195);  // 6 a 7
			 line(c*90+ 65,f*90+195, c*90+ 78,f*90+160);  // 7 a 8
			 line(c*90+ 78,f*90+160, c*90+ 55,f*90+142);  // 8 a 9
			 line(c*90+ 55,f*90+142, c*90+ 85,f*90+142);  // 9 a 10
			 line(c*90+ 85,f*90+142, c*90+ 95,f*90+113);  // 10 a 1

		 break;
	 case 2:
			 //circulo
			 circle(c*90+(50+45),f*90+110+45,40);
		 break;
	}//cierra switch
	floodfill(c*90+95,f*90+155,RED);
	}//cierra for de columnas
 }//cierra for de filas
 return correcto;
}




void ordenar_cosas(){
	setbkcolor(CYAN);
	setcolor(WHITE);

 /*Titulo*/
	setfillstyle(1,RED);
	bar(getmaxx()/6,getmaxy()/10,getmaxx()*5/6,getmaxy()*2/10);
	rectangle(getmaxx()/6+1,getmaxy()/10+1,getmaxx()*5/6-1,getmaxy()*2/10-1);

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	setcolor(WHITE);
	outtextxy(getmaxx()/6+20,getmaxy()/10+5,"EL MUNDO DE LOS NI¥OS");

	outtextxy(200,120,"Ordenar Cosas");
	setfillstyle(SOLID_FILL,YELLOW);

	bar(getmaxx()/16,getmaxy()*3/8,getmaxx()*7/16,getmaxy()/2); setcolor(RED);
	rectangle(getmaxx()/16-1,getmaxy()*3/8-1,getmaxx()*7/16+1,getmaxy()/2+1); setcolor(DARKGRAY);
	rectangle(getmaxx()/16+3,getmaxy()*3/8+3,getmaxx()*7/16-3,getmaxy()/2-3);

	bar(getmaxx()/16,getmaxy()*3/8+80,getmaxx()*7/16,getmaxy()/2+80); setcolor(RED);
	rectangle(getmaxx()/16-1,getmaxy()*3/8+80-1,getmaxx()*7/16+1,getmaxy()/2+80+1); setcolor(DARKGRAY);
	rectangle(getmaxx()/16+3,getmaxy()*3/8+80+3,getmaxx()*7/16-3,getmaxy()/2+80-3);

	bar(getmaxx()/16,getmaxy()*3/8+160,getmaxx()*7/16,getmaxy()/2+160); setcolor(RED);
	rectangle(getmaxx()/16-1,getmaxy()*3/8+160-1,getmaxx()*7/16+1,getmaxy()/2+160+1); setcolor(DARKGRAY);
	rectangle(getmaxx()/16+3,getmaxy()*3/8+160+3,getmaxx()*7/16-3,getmaxy()/2+160-3);

	bar(getmaxx()*9/16-20,getmaxy()*3/8,getmaxx()*15/16-20,getmaxy()/2); setcolor(RED);
	rectangle(getmaxx()*9/16-1-20,getmaxy()*3/8-1,getmaxx()*15/16+1-20,getmaxy()/2+1); setcolor(DARKGRAY);
	rectangle(getmaxx()*9/16+3-20,getmaxy()*3/8+3,getmaxx()*15/16-3-20,getmaxy()/2-3);

	bar(getmaxx()*9/16-20,getmaxy()*3/8+80,getmaxx()*15/16-20,getmaxy()/2+80); setcolor(RED);
	rectangle(getmaxx()*9/16-1-20,getmaxy()*3/8+80-1,getmaxx()*15/16+1-20,getmaxy()/2+80+1); setcolor(DARKGRAY);
	rectangle(getmaxx()*9/16+3-20,getmaxy()*3/8+80+3,getmaxx()*15/16-3-20,getmaxy()/2+80-3);

	setfillstyle(SOLID_FILL,LIGHTBLUE);
	bar(getmaxx()*9/16-20,getmaxy()*3/8+160,getmaxx()*15/16-20,getmaxy()/2+160); setcolor(LIGHTGRAY);
	rectangle(getmaxx()*9/16-1-20,getmaxy()*3/8+160-1,getmaxx()*15/16+1-20,getmaxy()/2+160+1); setcolor(WHITE);
	rectangle(getmaxx()*9/16+3-20,getmaxy()*3/8+160+3,getmaxx()*15/16-3-20,getmaxy()/2+160-3);

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	setcolor(BLUE);
	outtextxy(getmaxx()/16+3+75,getmaxy()*3/8+15,"N£meros");
	outtextxy(getmaxx()/16+3+15,getmaxy()*3/8+80+15,"Letras del abecedario");
	outtextxy(getmaxx()/16+3+50,getmaxy()*3/8+160+15,"Meses del a¤o");
	outtextxy(getmaxx()*9/16+3-20+75,getmaxy()*3/8+15,"Palabras");
	outtextxy(getmaxx()*9/16+3-20+20,getmaxy()*3/8+80+15,"D¡as de la semana");
	setcolor(WHITE);
	outtextxy(getmaxx()*9/16+3-20+75,getmaxy()*3/8+160+15,"Regresar...");
}





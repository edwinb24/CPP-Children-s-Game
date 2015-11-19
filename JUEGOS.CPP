#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<ctype.h>
#include<stdlib.h>
#include<dos.h>
#include "libreria\raton.h"
#include "libreria\grafico.h"


void main(){
int monitor=VGA, modo=VGAHI;
int num[6], secuencia[3],correcto=-1;
int c1,c2,c3,b,x,y,fig=-1,n_res=0,n_ok=0,nv_imagen=-1,n_cuadro=-1,op_menu=0,op_menu1=0,op_menu3=0;
char *animal[9]={"imagen\\bear.bmp","imagen\\fish.bmp","imagen\\frog.bmp","imagen\\lamb.bmp","imagen\\tiger.bmp","imagen\\chipmunk.bmp","imagen\\donkey.bmp","imagen\\mouse.bmp","imagen\\rabbit.bmp"};
unsigned x_pos,y_pos,num_boton;
char r='n',s='n';

initgraph(&monitor,&modo,"\BGI");
cleardevice();
iniciarRaton();
menuprincipal();
mostrarRaton();
 do{
	x_pos=posicionHorizontal();
	y_pos=posicionVertical();
	num_boton=botonPresionado();

	if(num_boton==1){ //Revisa en el area de que boton, se hizo click
				if(x_pos>500 && x_pos<550 && y_pos>170       && y_pos<190      ) op_menu=1;
	 else if(x_pos>500 && x_pos<550 && y_pos>(170+40)  && y_pos<(190+40) ) op_menu=2;
	 else if(x_pos>500 && x_pos<550 && y_pos>(170+80)  && y_pos<(190+80) ) op_menu=3;
	 else if(x_pos>500 && x_pos<550 && y_pos>(170+120) && y_pos<(190+120)) op_menu=4;
	 else if(x_pos>500 && x_pos<550 && y_pos>(170+160) && y_pos<(190+160)) op_menu=5;
	}
	switch(op_menu){

		case 1:{
		do{
		 s='n';
		 cleardevice();
		 ocultarRaton();
		 busqueda_animales();
		 mostrarRaton();

		 //Llenado de num[] con numeros sin repetir de las imagenes a utilizar
		 randomize();
		 for(c1=0;c1<6;c1++){
			num[c1]=rand()%9;
			c2=0;
			while(c2<c1){ //revisa desde num[0] hasta la posicion que se acaba de escoger
			 if (num[c1]==num[c2])
				 c2=c1--;
			 c2++;
			}
		 }

		 //despliegue de las 6 imagenes seleccionadas
		 ocultarRaton();
		 c3=0;
		 for(c1=17;c1<=249;c1+=116)
			for(c2=122;c2<=240;c2+=118)
			 imagen(c1,c2,animal[num[c3++]]);
			 mostrarRaton();

		 do{
			x_pos=posicionHorizontal();
			y_pos=posicionVertical();
			num_boton=botonPresionado();

			if(num_boton==1){ //Revisa en el area de que dibujo, se hizo click
						if(x_pos> 17 && x_pos<133 && y_pos>122 && y_pos<238) op_menu1=1;
			 else if(x_pos> 17 && x_pos<133 && y_pos>240 && y_pos<356) op_menu1=2;
			 else if(x_pos>133 && x_pos<249 && y_pos>122 && y_pos<238) op_menu1=3;
			 else if(x_pos>133 && x_pos<249 && y_pos>240 && y_pos<356) op_menu1=4;
			 else if(x_pos>249 && x_pos<365 && y_pos>122 && y_pos<238) op_menu1=5;
			 else if(x_pos>249 && x_pos<365 && y_pos>240 && y_pos<356) op_menu1=6;
			}

			//impresion de imagen clickada
			if(1<=op_menu1 && op_menu1<=6){
			 ocultarRaton();
			 setfillstyle(1,DARKGRAY);
			 bar(getmaxx()*9/16+20,getmaxy()/4,getmaxx()-30,getmaxy()*3/4);
			 rectangle(378,getmaxy()/4-1,610,getmaxy()*3/4+1);
			 imagen(436,180,animal[num[op_menu1-1]]);
			 rectangle(436,180,550,295);    n_res=1;  n_cuadro=op_menu1; fig=num[op_menu1-1];
			 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
			 setcolor(WHITE);
			 outtextxy(383,120,"¨Cual es el nombre");
			 outtextxy(405,140,"de este animal?");
			 outtextxy(270,440,"opciones");
			 n_ok=0;
			 mostrarRaton();
			}

			// Revision de area textual clickada e impresion de nombre clickado + OK
			if(num_boton==1){
			 if(n_ok==1){
				setfillstyle(SOLID_FILL,RED);  bar(392,320,518,345);
				rectangle(392,320,518,345);  	setcolor(WHITE);
			 }

			 if(x_pos>61 && x_pos<164 && y_pos>382 && y_pos<408){
				outtextxy(430,315,"Bear");   	nv_imagen=1;
				n_ok=1;
			 }
			 else if(x_pos>164 && x_pos<267 && y_pos>382 && y_pos<408){
				outtextxy(430,315,"Fish");   	nv_imagen=2;
				n_ok=1;
			 }
			 else if(x_pos>267 && x_pos<373 && y_pos>382 && y_pos<408){
				outtextxy(430,315,"Frog");   	nv_imagen=3;
				n_ok=1;
			 }
			 else if(x_pos>373 && x_pos<479 && y_pos>382 && y_pos<408){
				outtextxy(425,315,"Lamb");    nv_imagen=4;
				n_ok=1;
			 }
			 else if(x_pos>479 && x_pos<579 && y_pos>382 && y_pos<408){
				outtextxy(430,315,"Tiger");   nv_imagen=5;
				n_ok=1;
			 }
			 else if(x_pos>61  && x_pos<190 && y_pos>410 && y_pos<438){
				outtextxy(397,315,"Chipmunk");  nv_imagen=6;
				n_ok=1;
			 }
			 else if(x_pos>190 && x_pos<319 && y_pos>410 && y_pos<438){
				outtextxy(420,315,"Donkey");	 nv_imagen=7;
				n_ok=1;
			 }
			 else if(x_pos>319 && x_pos<448 && y_pos>410 && y_pos<438){
				outtextxy(422,315,"Mouse");    nv_imagen=8;
				n_ok=1;
			 }
			 else if(x_pos>448 && x_pos<578 && y_pos>410 && y_pos<438){
				outtextxy(422,315,"Rabbit");   nv_imagen=9;
				n_ok=1;
			 }
			 if(n_ok==1){
				setcolor(BLUE);
				setfillstyle(SOLID_FILL,WHITE);
				bar(545,320,590,345);
				rectangle(545,320,590,345);
				outtextxy(550,315,"Ok");
			 }

			 //salida con Ok
			 if(n_ok==1 && n_cuadro>0 && x_pos>545 && x_pos<590 && y_pos>320 && y_pos<345)
				s='s';
			}

			mostrarRaton();
			op_menu1=0;//para que no vuelva a imprimir la imagen seleccionada
			n_res=0;
		 }while(s!='s');

		 //mensaje
		 ocultarRaton();
		 cleardevice();
		 setbkcolor(BLACK);
		 if((nv_imagen-1)==fig)
			imagen(0,0,"imagen\\bien.bmp");
		 else //if((nv_imagen-1)!=fig)
			imagen(0,0,"imagen\\suerte.bmp");

								 //desea continuar?
		 outtextxy(100,280,"¨ Deseas continuar ?");

		 settextstyle(TRIPLEX_FONT,HORIZ_DIR,1); setfillstyle(SOLID_FILL,WHITE);

		 bar(getmaxx()/4,getmaxy()*3/4-30,getmaxx()/4+40,getmaxy()*3/4-10);
		 rectangle(getmaxx()/4,getmaxy()*3/4-30,getmaxx()/4+40,getmaxy()*3/4-10);
		 outtextxy(getmaxx()/4+10,getmaxy()*3/4-33,"Si");

		 bar(getmaxx()/4+60,getmaxy()*3/4-30,getmaxx()/4+100,getmaxy()*3/4-10);
		 rectangle(getmaxx()/4+60,getmaxy()*3/4-30,getmaxx()/4+100,getmaxy()*3/4-10);
		 outtextxy(getmaxx()/4+70,getmaxy()*3/4-33,"No");

		 // Ver si presiono SI o NO  para continuar
		 do{
			 x_pos=posicionHorizontal();
			 y_pos=posicionVertical();
			 num_boton=botonPresionado();
			 mostrarRaton();

			 if(num_boton==1){
						 if(getmaxx()/4    < x_pos && x_pos < getmaxx()/4+ 40 && getmaxy()*3/4-30 < y_pos && y_pos < getmaxy()*3/4-10)
							n_res=1;
				else if(getmaxx()/4+60 < x_pos && x_pos < getmaxx()/4+100 && getmaxy()*3/4-30 < y_pos && y_pos < getmaxy()*3/4-10)
							n_res=2;
			 }
			}while(n_res!=1 && n_res!=2);

		}while(n_res==1);

		 n_cuadro=-1;
		 nv_imagen=-1;
		 n_res=0;
		 ocultarRaton();
		 cleardevice();
		 menuprincipal();
		}break;

		case 2:{
		 do{
			op_menu=0;
			n_res=0;
			ocultarRaton();
			cleardevice();
			secuencias_logicas();
			figuras(secuencia); //tira una secuencia
			delay(1000);
			cleardevice();
			ocultarRaton();
			secuencias_logicas();
			setfillstyle(1,YELLOW);
			setcolor(RED);
					 bar(30  ,getmaxy()/4-6,getmaxx()/2+20,getmaxy()*3/4+19);
			rectangle(30-1,getmaxy()/4-7,getmaxx()/2+20,getmaxy()*3/4+20);

			correcto=opciones(secuencia); //tira opciones y retorna la fila de la secuencia correcta

			//Seleccion de opciones
			do{
			 x_pos=posicionHorizontal();
			 y_pos=posicionVertical();
			 num_boton=botonPresionado();

			 mostrarRaton();

			 if(num_boton==1){ //Revisa en el area de que opcion, se hizo click
						 if(x_pos> 95 && x_pos<315 && y_pos>     113 && y_pos<     195) op_menu=1;
				else if(x_pos> 95 && x_pos<315 && y_pos>  90+113 && y_pos<  90+195) op_menu=2;
				else if(x_pos> 95 && x_pos<315 && y_pos>2*90+113 && y_pos<2*90+195) op_menu=3;
			 }
			}while(op_menu<1);


			//mensaje
			ocultarRaton();
			cleardevice();
			setbkcolor(BLACK);
			if(op_menu-1==correcto)
				imagen(0,0,"imagen\\bien.bmp");
			else
				imagen(0,0,"imagen\\suerte.bmp");

			//desea continuar?
			outtextxy(100,280,"¨ Deseas continuar ?");

			settextstyle(TRIPLEX_FONT,HORIZ_DIR,1); setfillstyle(SOLID_FILL,WHITE);

			bar(getmaxx()/4,getmaxy()*3/4-30,getmaxx()/4+40,getmaxy()*3/4-10);
			rectangle(getmaxx()/4,getmaxy()*3/4-30,getmaxx()/4+40,getmaxy()*3/4-10);
			outtextxy(getmaxx()/4+10,getmaxy()*3/4-33,"Si");

			bar(getmaxx()/4+60,getmaxy()*3/4-30,getmaxx()/4+100,getmaxy()*3/4-10);
			rectangle(getmaxx()/4+60,getmaxy()*3/4-30,getmaxx()/4+100,getmaxy()*3/4-10);
			outtextxy(getmaxx()/4+70,getmaxy()*3/4-33,"No");


			// Ver si presiono SI o NO  para continuar
			do{
			 x_pos=posicionHorizontal();
			 y_pos=posicionVertical();
			 num_boton=botonPresionado();
			 mostrarRaton();

			 if(num_boton==1){
						 if(getmaxx()/4    < x_pos && x_pos < getmaxx()/4+ 40 && getmaxy()*3/4-30 < y_pos && y_pos < getmaxy()*3/4-10)
							n_res=1;
				else if(getmaxx()/4+60 < x_pos && x_pos < getmaxx()/4+100 && getmaxy()*3/4-30 < y_pos && y_pos < getmaxy()*3/4-10)
							n_res=2;
			 }
			}while(n_res!=1 && n_res!=2);

			op_menu=-1;

		 }while(n_res==1);

		 n_res=0;
		 ocultarRaton();
		 cleardevice();
		 menuprincipal();
		}break;

		case 3:{


		cleardevice();
		 ocultarRaton();
		 ordenar_cosas();
		 mostrarRaton();


			do{
				x_pos=posicionHorizontal();
				y_pos=posicionVertical();
				num_boton=botonPresionado();

					if(num_boton==1 && x_pos>(getmaxx()/16+3)      && x_pos<(getmaxx()*7/16-3)     && y_pos>(getmaxy()*3/8+3)     && y_pos<(getmaxy()/2-3)) op_menu3=1;
					if(num_boton==1 && x_pos>(getmaxx()*9/16+3-20) && x_pos<(getmaxx()*15/16-3-20) && y_pos>(getmaxy()*3/8+3)     && y_pos<(getmaxy()/2-3)) op_menu3=2;
					if(num_boton==1 && x_pos>(getmaxx()/16+3)      && x_pos<(getmaxx()*7/16-3)     && y_pos>(getmaxy()*3/8+80+3)  && y_pos<(getmaxy()/2+80-3)) op_menu3=3;
					if(num_boton==1 && x_pos>(getmaxx()*9/16+3-20) && x_pos<(getmaxx()*15/16-3-20) && y_pos>(getmaxy()*3/8+80+3)  && y_pos<(getmaxy()/2+80-3)) op_menu3=4;
					if(num_boton==1 && x_pos>(getmaxx()/16+3)      &&	x_pos<(getmaxx()*7/16-3)     && y_pos>(getmaxy()*3/8+160+3) && y_pos<(getmaxy()/2+160-3)) op_menu3=5;
					if(num_boton==1 && x_pos>(getmaxx()*9/16+3-20) && x_pos<(getmaxx()*15/16-3-20) && y_pos>(getmaxy()*3/8+160+3) && y_pos<(getmaxy()/2+160-3)) op_menu3=6;

					 switch(op_menu3){
						case 1:{
						}break;

						case 2:{
						}break;

						case 3:{
						}break;

						case 4:{
						}break;

						case 5:{
						}break;

						case 6:{
						 s='s';
						}break;

					 }

				 mostrarRaton();
				 op_menu3=0;

				 }while(s!='s');

		 ocultarRaton();
		 cleardevice();
		 menuprincipal();
		}break;

		case 4:{}break;

		case 5:{r='s';
		}break;

	}
	//Esto solo es para imicializar nuevamente todo
	s='g';


	mostrarRaton();
	op_menu=0;//Esto debe ir siempre, sino se me lupea en la misma opcion

 }while(r!='s');

 closegraph();
}



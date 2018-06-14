/*	Test thu vien winbgim.h	*/

#include <winbgim.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

main(int argc, char *argv[])
{
	
	FILE *posicion;
	
	posicion = fopen("posicion.txt","a");
	
	float x,xini,xant,vxini,xm;
	float y,yini,yant,vyini,ym,yfut;
    float dt;
	int i,xf,yf;
	char posicionx[20],posiciony[20];
	
	
	
	cout<<"SIMULACION DE UNA PARTICULA EN UN CAMPO GRAVITACIONAL\n\n";
	initwindow(700, 500);					// init window graphics
								// set background
   	cleardevice();
	setcolor(14);							// set text color
	
	outtextxy(50,200,"INTRODUCE POSICIONES Y VELOCIDADES EN LA APLICACION DE CONSOLA");
	rectangle(10,10,600,400);   //La caja donde se encuentra la partícula
	
	
	
	printf("INTRODUCE LA POSICION INICIAL EN X y Y, EN ESE ORDEN (10<X<600,10<Y<400)\n");
	scanf("%f",&xini);
	scanf("%f",&yini);
	
		
	printf("INTRODUCE LAS VELOCIDADES EN X y Y, EN ESE ORDEN\n");
	scanf("%f",&vxini);
	scanf ("%f",&vyini);
	
	printf("\nAHORA VE A LA VENTANA GRAFICA Y PRESIONA ENTER");
	
	
	
	dt=0.0001;
	
	x=xini;
	y=yini;
	
	
	
	xant=x-(vxini*dt);
	yant=y-(vyini*dt);
	

	
	
	for(i=1;i<20000;i++) {
		
		
		
	
	if(x>=600){
		if(vxini>=0){
			vxini=(-1)*vxini;
			xant=x-(vxini*dt);
		    } else{vxini=vxini;
		    xant=x-(vxini*dt);
			}
	}
	
	if(y>=400){
		if(vyini>=0){
			vyini=(-1)*vyini;
			yant=y-(vyini*dt);
		    } else{vyini=vyini;
		    yant=y-(vyini*dt);
			}
	}
	
	if(x<=10){
		if(vxini>=0){
				vxini=vxini;
				xant=x-(vxini*dt);
			} else{vxini=-vxini;
			xant=x-(vxini*dt);
			}
	}
	
	if(y<=10){
		if(vyini>=0){
				vyini=vyini;
				yant=y-(vyini*dt);
		    } else { vyini=-vyini;
			yant=y-(vyini*dt);
			}	
	}
	
	xm=x;
	ym=y;
	
	x=(2*x)-xant;
	y=(2*y)-yant+2*50000*((dt*dt)/2);
		
		xf=floor(x+0.5);
		yf=floor(y+0.5);
		
	circle(x,y,2);         //Partícula
	
	fprintf(posicion,"%.4f\t%.4f\n",x,y);
	//printf("%.4f\t%.4f\n",x,y);	
	sprintf(posicionx,"%.4f",x);
	sprintf(posiciony,"%.4f",y);
	
	outtextxy(20,420,posicionx);
	outtextxy(100,420,posiciony);
	

			xant=xm;
			yant=ym;
			yfut=(2*y)-ym+2*50000*((dt*dt)/2);
			
	vyini=(yfut-ym)/(2*dt);	
	
	
	while(!kbhit()) delay(1);  
	cleardevice();
	rectangle(10,10,600,400);
	
	//delay(1); //Para hacer más lento el movimiento de la partícula
	
	
}

	fclose(posicion);
	//outtextxy(50,100,"Graphics in Dev-C++");// print text in window graphics
	while(!kbhit()) delay(1);				// pause screen	
}

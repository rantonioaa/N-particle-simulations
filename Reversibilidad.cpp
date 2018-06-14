/*	PROYECTO SERVICIO SOCIAL	*/

#include <winbgim.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

main(int argc, char *argv[])
{
	float *x,*xini,*xant,*xm,*vxini;
	float *y,*yini,*yant,*ym,*vyini,*yfut;
    float dt;
	int n,i,*xf,*yf,N,NUM=100,PASOS=3000;
	
	
	initwindow(700, 500);					// init window graphics
								// set background
   	cleardevice();
	setcolor(14);							// set text color
	

	rectangle(10,10,600,400);   //La caja donde se encuentra la partícula
	
	//setviewport(11,11,599,399,10); //determina el área que se va a estar borrando
	
	
	srand(time(NULL));
	
	N=NUM;
	
	x=new float [N];
	y=new float [N];
	
	xf=new int [N];
	yf=new int [N];
	
	xini=new float [N];
	yini=new float [N];
	

	xant=new float [N];
	yant=new float [N];
	
	vxini=new float [N];
	vyini=new float [N];
	
	xm=new float [N];
	ym=new float [N];
	
	yfut=new float [N];
	
		dt=0.0001;   //determina el intervalo
	
	for(N=1;N<=NUM;N++) {
		
		xini[N]= rand() % 300 + 150;   //posiciones iniciales determinadas por un número aleatorio
		yini[N]= rand() % 200 + 100;
	
		x[N]=xini[N];
		y[N]=yini[N];
		
		vxini[N]= (rand() % 10001 - 5000);    //velocidades determinadas por un número aleatorio 
		vyini[N]= (rand() % 10001 - 5000);
		
				
		xant[N]=x[N]-(vxini[N]*dt);
		yant[N]=y[N]-(vyini[N]*dt);
		
		}	
	
	
	
	for(i=1;i<=PASOS;i++) {    //ciclo de movimiento
	
		for(N=1;N<=NUM;N++) {
			
			
				if(i==(PASOS/2)){               //reversibilidad
			
			vxini[N]=-vxini[N];
			xant[N]=x[N]-(vxini[N]*dt);
			vyini[N]=-vyini[N];
			yant[N]=y[N]-(vyini[N]*dt);
			
		}
			
			
				
		if(x[N]>=599){               //rebotes en las paredes de la caja
			if(vxini[N]>0){
			vxini[N]=(-1)*vxini[N];
			xant[N]=x[N]-(vxini[N]*dt);
		    } else{vxini[N]=vxini[N];
		    xant[N]=x[N]-(vxini[N]*dt);
			}
		}
		
		if(y[N]>=399){
			if(vyini[N]>0){
			vyini[N]=(-1)*vyini[N];
			yant[N]=y[N]-(vyini[N]*dt);
		    } else{vyini[N]=vyini[N];
		    yant[N]=y[N]-(vyini[N]*dt);
			}
		}
		
		if(x[N]<=11){
			if(vxini[N]>0){
				vxini[N]=vxini[N];
				xant[N]=x[N]-(vxini[N]*dt);
			} else{vxini[N]=-vxini[N];
			xant[N]=x[N]-(vxini[N]*dt);
			}
		}
		
		if(y[N]<=14){
			if(vyini[N]>0){
				vyini[N]=vyini[N];
				yant[N]=y[N]-(vyini[N]*dt);
		    } else { vyini[N]=-vyini[N];
			yant[N]=y[N]-(vyini[N]*dt);
			}
		}
		
		
		
		
		xm[N]=x[N];
		ym[N]=y[N];
		
		x[N]=(2*x[N])-xant[N];
		y[N]=(2*y[N])-yant[N];
			
			xf[N]=floor(x[N]+0.5);       //posicion de la particula redondeando decimales
			yf[N]=floor(y[N]+0.5);
			
		circle(x[N],y[N],2);          //partícula
	    
	    
	    
	    
	   
			
			xant[N]=xm[N];
			yant[N]=ym[N];
		
		
		
	    
    	}
	
	while(!kbhit()) delay(1);  

	//clearviewport(); //borra el área determinada
	
	cleardevice();
	rectangle(10,10,600,400); 
	
	//delay(0.001); //Para hacer más lento el movimiento de la partícula
	
	
	}	
	//outtextxy(50,100,"Graphics in Dev-C++");// print text in window graphics
	while(!kbhit()) delay(1);				// pause screen	
}

/* Algoritmo MidPointCircle */
#include <graphics.h>
#include <stdio.h>
#include <math.h>

int basicCircle(int radius, int puntos[]);
void generaArchivo(int puntos[], int count);

int main()
{
	int gd=DETECT, gm;
	int radius;
	
	int puntos[10000];
	int count=0;
	
	printf("Entre el radio de la circunferencia: ");
	scanf("%d",&radius);
	
	initgraph(&gd, &gm, NULL);
	
	count = basicCircle(radius, puntos);
	
	generaArchivo(puntos, count);
	
	getch();
	closegraph();
	
	return 0;
}

/* Dibuja por simetría en todos los cuadrantes */
int circlePoints(int x, int y, int puntos[], int i)
{
	int maxx = getmaxx()/2;
	int maxy = getmaxy()/2;
	
	putpixel(maxx+x,maxy+y,WHITE);
	
	puntos[i]=maxx+x;
	puntos[i+1]=maxy+y;
	i+=2;
	
	putpixel(maxx-x,maxy+y,WHITE);
	putpixel(maxx+x,maxy-y,WHITE);
	putpixel(maxx-x,maxy-y,WHITE);
	return i;
}

/* Algoritmo BasicCircle */
int basicCircle(int radius, int puntos[])
{
	int x = 0, y = radius;
	int i = 0;
	
	i = circlePoints(x, y, puntos, i);
	
	while(x <= radius)
	{
		x++;
		y = sqrt(radius*radius - x*x);
		
		i = circlePoints(x, y, puntos, i);
	}
	
	return i;
}

/* Guardar los puntos dibujados en un archivo */
void generaArchivo(int puntos[], int count)
{
	FILE *fp;
	
	int i,np;
	
	fp=fopen("puntos.txt","w");

	fprintf(fp,"%s","Los puntos dibujados son:\n");

	np=0;

	for(i = 0; i < count; i += 2)
	{
		fprintf(fp,"(%d, %d) ", puntos[i], puntos[i+1]);

		np++;

		if(np==5) { fprintf(fp,"\n"); np=0; }
	}

	fclose(fp);
}
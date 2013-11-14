/* Algoritmo Punto Medio para el trazado de líneas */
#include <stdio.h>
#include <graphics.h>

typedef struct  {
	int x, y;
} Punto;

int MidPointLine(int x0, int y0, int x1, int y1, int puntos[]);
void Rectangulo(Punto p1, Punto p2);
void Triangulo (Punto A, Punto B, Punto C);

void generaArchivo(int puntos[], int count);


int main(int argc, char **argv)
{
	int x1, y1, x2, y2;
	int x11, y11, x21, y21;
	
	Punto p1, p2, p3;
	
	int gd = DETECT, gm = VGAMAX;
	
	int puntos[1000], count;
	
	/*printf("Entre el punto de origen [x1,y1]: ");
	scanf("%d,%d", &x1, &y1);

	printf("Entre el punto destino [x2,y2]: ");
	scanf("%d,%d", &x2, &y2);*/
	
	printf("Entre el punto 1 [x1,y1]: ");
	scanf("%d,%d", &p1.x, &p1.y);
	
	printf("Entre el punto 2 [x2,y2]: ");
	scanf("%d,%d", &p2.x, &p2.y);

	printf("Entre el punto 3 [x3,y3]: ");
	scanf("%d,%d", &p3.x, &p3.y);

	initgraph(&gd, &gm, NULL);

	//count = MidPointLine(x1, y1, x2, y2, puntos);

	//generaArchivo(puntos, count);
	
	//Rectangulo(p1, p2);
	Triangulo(p1, p2, p3);
	
	getch();

	closegraph();
	return 0;
}

int MidPointLine(int x0, int y0, int x1, int y1, int puntos[])
{
	int x, y, dx, dy, xend, yend, p, incE, incNE;
	int maxY;
	
	int i=0;
    
	dx = x1 - x0; 
    dy = y1 - y0; 
	
	maxY=getmaxy();
    
	p = 2 * dy - dx; 
    incE = 2 * dy;
    incNE = 2 * (dy - dx);
    
    /* determinar que punto usar para empezar, cual para terminar */
    if (x0 > x1) { 
		x = x1; 
		y = y1;
        xend = x0;
		yend = y0;
    }
    else {
        x = x0;
        y = y0;
        xend = x1;
		yend = y1;
    }
    
    /* se repite hasta llegar al extremo de la línea */
    if (x < xend)
	{
	while (x <= xend)
    {
        putpixel(x, maxY-y, WHITE); 
		
		puntos[i] = x;
		puntos[i+1] = y;
		i += 2;
		
		x = x + 1;
		
        if (p <= 0) {
            p = p + incE;
		}
        else {
            y = y + 1;
            p = p + incNE;
        }
    }
	}
	else {
	 while (y <= yend)
    {
        putpixel(x, maxY-y, WHITE); 
		
		puntos[i] = x;
		puntos[i+1] = y;
		i += 2;
		
		y = y + 1;
    }
	}
	
	return i;
}

void Rectangulo(Punto p1, Punto p2)
{
	int vector[3000];
	
	MidPointLine(p1.x, p1.y, p1.x, p2.y, vector);
	MidPointLine(p1.x, p1.y, p2.x, p1.y, vector);
	MidPointLine(p2.x, p1.y, p2.x, p2.y, vector);
	MidPointLine(p1.x, p2.y, p2.x, p2.y, vector);
}


void Triangulo (Punto p1, Punto p2, Punto p3)
{
	int vector[3000];
	
	MidPointLine(p1.x, p1.y, p2.x, p2.y, vector);
	MidPointLine(p1.x, p1.y, p3.x, p3.y, vector);
	MidPointLine(p3.x, p3.y, p2.x, p2.y, vector);
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
		fprintf(fp,"(%d, %d) \n", puntos[i], puntos[i+1]);

		//np++;

		//if(np==5) { fprintf(fp,"\n"); np=0; }
	}

	fclose(fp);
}
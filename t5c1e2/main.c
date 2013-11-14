/* Algoritmo Bresenham para el trazado de líneas */
#include <stdio.h>
#include <graphics.h>

int BresenhamLine(float x0, float y0, float x1, float y1, int puntos[]);
void generaArchivo(int puntos[], int count);

int main(int argc, char **argv)
{
	float x1, y1, x2, y2;
	
	int gd = DETECT, gm = VGAMAX;
	
	int puntos[1000], count;	
	
	printf("Entre el punto de origen [x1,y1]: ");
	scanf("%f,%f", &x1, &y1);

	printf("Entre el punto destino [x2,y2]: ");
	scanf("%f,%f", &x2, &y2);
	
	initgraph(&gd, &gm, NULL);

	count = BresenhamLine(x1, y1, x2, y2, puntos);
	
	generaArchivo(puntos, count);	

	getch();

	closegraph();
	return 0;
}

int BresenhamLine(float x0, float y0, float x1, float y1, int puntos[])
{
	int x, y, dx, dy, xend, p, incE, incNE;
	int maxY;
	
	int i=0;	
	
	dx = abs(x1 - x0); 
    dy = abs(y1 - y0); 
	
	maxY=getmaxy();
    
	p = 2 * dy - dx; 
    incE = 2 * dy;
    incNE = 2 * (dy - dx);
    
    /* determinar que punto usar para empezar, cual para terminar */
    if (x0 > x1) { 
		x = x1; 
		y = y1;
        xend = x0;
    }
    else {
        x = x0;
        y = y0;
        xend = x1;
    }
    
    /* se repite hasta llegar al extremo de la línea */
    while (x <= xend)
    {
        putpixel(x, maxY-y, WHITE); 
		puntos[i] = x;
		puntos[i+1] = y;
		i += 2;		
		x = x + 1;
        if (p < 0) {
            p = p + incE;
		}
        else {
            y = y + 1;
            p = p + incNE;
        }
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
		fprintf(fp,"(%d, %d) \n ", puntos[i], puntos[i+1]);

		//np++;

		//if(np==5) { fprintf(fp,"\n"); np=0; }
	}

	fclose(fp);
}
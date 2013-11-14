#include <stdio.h>
#include <graphics.h>
#include <math.h>

void dibujaEjes();
void traslada(float *, float *, float , float );
void rota(float *, float *, float , float, float );


int main(int argc, char **argv)
{
	float x, y, radius;
	float dx, dy;
	float px, py;
	float angulo;
	
	int gd = DETECT, gm = VGAMAX;	
	
	printf("Entre el centro de la circunferencia [x,y]: ");
	scanf("%f,%f", &x, &y);
	
	printf("Entre el radio de la circunferencia [r]: ");
	scanf("%f", &radius);

	printf("Entre el factor de desplazamiento [Dx,Dy]: ");
	scanf("%f,%f", &dx, &dy);
	
	printf("Entre el pivote de rotación [px,py]: ");
	scanf("%f,%f", &px, &py);
	
	printf("Entre el ángulo de rotación [angulo]: ");
	scanf("%f", &angulo);
	
	initgraph(&gd, &gm, NULL);

	dibujaEjes();
	
	int maxX = getmaxx();
	int maxY = getmaxy();
	
	int origenX = maxX / 2;
	int origenY = maxY / 2;
	
	circle(x + origenX, y + origenY, radius);
	
	traslada(&x, &y, dx, dy);	
	
	circle(x + origenX, y + origenY, radius);

	getch();

	closegraph();
	return 0;
}

void dibujaEjes()
{
	int maxX = getmaxx();
	int maxY = getmaxy();
	
	int origenX = maxX / 2;
	int origenY = maxY / 2;
	
	line( origenX, 0, origenX, maxY );
	line( 0, origenY, maxX, origenY );
}

void traslada(float * x0, float * y0, float dx, float dy)
{
	*x0 += dx;
	*y0 += dy;
}

void rota(float * x0, float * y0, float angulo, float px, float py )
{
	*x0 = 
}

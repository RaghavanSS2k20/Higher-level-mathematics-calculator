#include <graphics.h>
#include <math.h>
#include<stdlib.h>
#include<windows.h>
/*user defined function for gotoxy*/
COORD coord={0,0};
void gotoxy(int x,int y)
{
  	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
/*
**	Conversion of x coordinate - Window to Viewport
*/
double	transformx(double coor, int *w)
{
	if (!w)
		return coor;
	return (((coor - w[0]) / (w[2] - w[0])) * (w[6] - w[4])) + w[4];
}
/*
**	Conversion of y coordinate - Window to Viewport
*/
double	transformy(double coor, int *w)
{
	if (!w)
		return coor;
	return (((coor - w[1]) / (w[3] - w[1])) * (w[7] - w[5])) + w[5];
}


int	graphForf(int a,int b,int c,int d,int e,int x_axis, int y_axis, double k, int window[])/*f() means a mathematical function that why the name graphForf(x)*/
{
	double x = -x_axis, y, px, py, cx = getmaxx()/2, cy = getmaxy()/2;
	int flag = 1;

	while (x <= x_axis) {
		/* Calculate y with given x */
		y = a*x*x*x*x+ b*x*x*x + c*x*x + d*x + e;

		/* Calculate coordoninates to display */
		px = x * getmaxx() / 8 + cx;
		/* -cy because of origin point in window(top left corner) */
		py = y * -cy / y_axis + cy;

		if (px <= getmaxx() && px > -1 && py > -1 && py <= getmaxy())
		{
			if (flag) {// CP to start
				moveto(transformx(px, window), transformy(py, window));
				flag = 0;
			}
			px = transformx(px, window);
			py = transformy(py, window);
			/* Draw segment line */
			lineto(px, py);
			/* update CP */
			moveto(px, py);
		} else {flag = 1;}

		x += 0.01;
		delay(5);
	}
}


void	trigonometricf(int x_axis, int y_axis, int *window,int choice, int k)

{
	double x = -x_axis, y, px, py, cx = getmaxx()/2, cy = getmaxy()/2;


	while (x < x_axis) {
		/* Calculate y with given x */

    switch(choice)
        {
            case 1:{
            y = sin(k * x);
            break;
            }
            case 2:
                {
                    y = cos(k*x);
                    break;
                }
            case 3:
                {
                    y = tan(k*x);
                    break;
                }

        }


		/* Calculate coordoninates to display */
		px = x * cx / x_axis + cx;
		/* -cy because of origin point in window(top left corner) */
		py = y * -cy / y_axis + cy;
		if (px > getmaxx())
			break;

		if (x == -x_axis) // only for first loop
			moveto(transformx(px, window), transformy(py, window));
		/* Draw segment line */
		px = transformx(px, window);
		py = transformy(py, window);
		lineto(px, py);
		/* update CP */
		moveto(px, py);

		x += 0.01;
		delay(2);
	}
}



void draw_axis(char *left, char *right, char *top, char *bottom, int w[])
{
	int xmax = getmaxx(), ymax = getmaxy();

	line(transformx(20, w), transformy(ymax/2, w), transformx(xmax-20, w), transformy(ymax/2, w));
	line(transformx(xmax/2, w), transformy(20, w), transformx(xmax/2, w), transformy(ymax-20, w));
	outtextxy(transformx(xmax/2, w),	transformy(ymax/2, w), "O");
	outtextxy(transformx(20, w),		transformy(ymax/2, w), left);
	outtextxy(transformx(xmax-40, w),	transformy(ymax/2, w), right);
	outtextxy(transformx(xmax/2, w),	transformy(20, w), top);
	outtextxy(transformx(xmax/2, w),	transformy(ymax-40, w), bottom);
}

int main()
{
	int gd = DETECT, gm;

	initgraph(&gd, &gm, NULL);

	/* draw axis */
	int option;
	int window1[] = {0, 0, getmaxx(), getmaxy(), 0, 0, getmaxx()/2, getmaxy()/2};
	int window2[] = {0, 0, getmaxx(), getmaxy(), getmaxx()/2, 0, getmaxx(), getmaxy()/2};
	int window3[] = {0, 0, getmaxx(), getmaxy(), 0, getmaxy()/2, getmaxx(), getmaxy()};
	system("cls");
	mainmenu:
	    {

	gotoxy(75,10);printf("**YOU HAVE ENTERD FOR GRAPHING**");
	gotoxy(75,11);printf("T H I S   A P P L I C A T I O N  C A N  G R A P H  FOR :");
	gotoxy(75,14);printf("[1] MATHEMATICAL FUNCTION(HIGHEST DEGREE OF :- 4)");
	gotoxy(75,16);printf("[2] TRIGONOMETRIC FUNCTION(SINE/COSINE/TANGENT) DEPENDING ON USER CHOICE");

	gotoxy(75,20);printf("ENTER YOUR CHOICE [1/2]:");
	gotoxy(100,0);scanf("%d",&option);
	switch(option)
	{

    case 1:
        {
            rectangle(getmaxx()/2, 0, getmaxx(), getmaxy()/2);
            draw_axis("-6", "6", "12", "-12", window2);
            setcolor(GREEN);
            setlinestyle(SOLID_LINE, 0, 2);
            system("cls");
            gotoxy(75,10);printf("ENTER COEFF, OF X^4 (if none enter 'zero'): ");
            int coeffa;
            gotoxy(119,10);scanf("%d",&coeffa);
            gotoxy(75,12);
            printf("ENTER COEFF  OF x^3(if none enter 'zero'): ");
            int coeffb;
            gotoxy(119,12);scanf("%d",&coeffb);
            int coeffc;
            gotoxy(75,14); printf("ENTER COEFF OF X^2(if none enter 'zero'):");
            gotoxy(119,14);scanf("%d",&coeffc);
            int coeffd;
            gotoxy(75,16);printf("ENTER COEFF OF X^1(if none enter 'zero'): ");
            gotoxy(119,16);scanf("%d",&coeffd);
            gotoxy(75,18);printf("ENTER CONSTANT: ");
            int coeffe;
            gotoxy(119,18);scanf("%d",&coeffe);


            graphForf(coeffa,coeffb,coeffc,coeffd,coeffe,5, 12, 1, window2);


        }




    case 2:{

    setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, 1);
	rectangle(0, 0, getmaxx()/2, getmaxy()/2);

	draw_axis("-6", "6", "2", "-2", window3);
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 2);
	short choice;
	int radMultiple;
	system("cls");
	gotoxy(75,10);printf("ENTER YOUR REQUIREMENT:-");
	gotoxy(75,11);printf("[1] GRAPH FOR 'SINE' FUNCTION");
	gotoxy(75,12);printf("[2] GRAPH FOR 'COSINE' FUNCTION");
	gotoxy(75,13);printf("[3] GRAPH FOR 'TANGENT' FUNCTION");
	gotoxy(75,14);printf("ENTER YOUR CHOICE..: ");
	gotoxy(75,15);scanf("%hi",&choice);
	switch(choice)
	{
    case 1:
        {
            system("cls");
            gotoxy(75,10);printf("ENTER THE MULTIPLE OF THE ANGLE TO BE GRAPHED(if nothing enter one(1)..:");
            gotoxy(75,11);scanf("%d",&radMultiple);
            trigonometricf(6, 2, window3,1,radMultiple);
            break;
        }
    case 2:
        {
            system("cls");
             gotoxy(75,10);printf("ENTER THE MULTIPLE OF THE ANGLE TO BE GRAPHED(if nothing enter one(1)..:");
            gotoxy(75,11);scanf("%d",&radMultiple);
            trigonometricf(6, 2, window3,2,radMultiple);
            break;

        }
    case 3:
        {
            system("cls");
             gotoxy(75,10);printf("ENTER THE MULTIPLE OF THE ANGLE TO BE GRAPHED(if nothing enter one(1)..:");
            gotoxy(75,11);scanf("%d",&radMultiple);
            trigonometricf(6, 2, window3,3,radMultiple);
            break;
        }

        }

	}



	getch();
	closegraph();
	return (0);
    }
	    }
}

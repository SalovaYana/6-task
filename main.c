
#include <stdio.h>
#include <graphics.h> //подключение графической библиотеки
#include <math.h>
#include <locale.h>
void minitr(int kol,float x1,float y1,float x2,float y2,float x3,float y3, int rec)
{

    line(x2,y2,x3,y3);
    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);     // линии между вершинами


    if (kol<rec)
        {

        minitr(
            kol+1,
            (x1 + x2) / 2 + (x2 - x3) / 2,
            (y1 + y2) / 2 + (y2 - y3) / 2,
            (x1 + x2) / 2 + (x1 - x3) / 2,
            (y1 + y2) / 2 + (y1 - y3) / 2,
            (x1 + x2) / 2,
            (y1 + y2) / 2, rec
               );


        minitr(
            kol+1,
            (x3 + x2) / 2 + (x2 - x1) / 2,
            (y3 + y2) / 2 + (y2 - y1) / 2,
            (x3 + x2) / 2 + (x3 - x1) / 2,
            (y3 + y2) / 2 + (y3 - y1) / 2,
            (x3 + x2) / 2,
            (y3 + y2) / 2, rec
               );

       minitr(
            kol+1,
            (x1 + x3) / 2 + (x3 - x2) / 2,
            (y1 + y3) / 2 + (y3 - y2) / 2,
            (x1 + x3) / 2 + (x1 - x2) / 2,
            (y1 + y3) / 2 + (y1 - y2) / 2,
            (x1 + x3) / 2,
            (y1 + y3) / 2, rec
              );

    }
}
 void osnova (float x1,float y1,float x2,float y2,float x3,float y3, int rec)
{
    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);
    line(x2,y2,x3,y3);


    float ax,ay,bx,by,cx,cy;
    ax=(x1+x2)/2;
    ay=(y1+y2)/2;
    bx=(x1+x3)/2;
    by=(y1+y3)/2;
    cx=(x2+x3)/2;
    cy=(y2+y3)/2;


    return minitr(1,ax,ay,bx,by,cx,cy, rec);

}
int main()
{   setlocale(LC_ALL,"Rus");

    int rec;

    printf("Введите глубину рекурсии:\n");
    scanf("%d", &rec);


    int gd = CUSTOM;
    int gm = CUSTOM_MODE(1200,800);
    initgraph(&gd, &gm,""); //открытие графического режима

    setbkcolor(0);
    cleardevice();

    setlinestyle(0,0,2);
    setcolor(5);
    osnova(100,550,1000,550,550,50, rec);

    getch();
    closegraph();

    return 0;
}

#include<graphics.h>
int main()
{
    int gd = 0, gm;
    initgraph(&gd, &gm, "");

    //setcolor(RED);

    //setbkcolor(BLUE);

    setfillstyle(SOLID_FILL,GREEN);
    //circle(100,100,50);
    bar(0,0,640,10);
    bar(0,470,640,480);
    bar(0,0,10,480);
    bar(630,0,640,480);


    bar3d(100,80,140,140,10,90);

    //outtextxy(250,250,"TEJAS");

   // rectangle(20,60,250,80);
   // floodfill(21,61,15);


    getch();
    closegraph();
    return 0;
}

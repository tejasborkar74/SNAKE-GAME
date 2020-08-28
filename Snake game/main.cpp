#include <bits/stdc++.h>
#include<graphics.h>

using namespace std;

void endfn(int l,int a)
{
    setfillstyle(SOLID_FILL,YELLOW);
    bar(0,0,640,480);
    setfillstyle(SOLID_FILL,RED);
    bar(0,0,640,480);

    outtextxy(250,240,"GAME OVER");



    system("cls");

    if(a==1)
    {
        cout<<"Died outside of Boundary"<<endl;
    }
    else
    {
        cout<<"Died by biting yourself"<<endl;
    }

    cout<<"Your score is "<<l<<endl;

    getch();
    return;
}



int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    int x[200]={0},y[200]={0};
    x[0]=200,y[0]=200;

    int xr=200,yr=200;//food location


    int pre = 1 , dir= 1,len=0;

    while(1)
    {
        setfillstyle(SOLID_FILL,BLACK);
        bar(0,0,640,480);
        setfillstyle(SOLID_FILL,GREEN);
         bar(0,0,640,10);
        bar(0,470,640,480);
        bar(0,0,10,480);
        bar(630,0,640,480);

        //head == food
        if(x[0] == xr && y[0] == yr)
        {
            len+=1;

            setfillstyle(SOLID_FILL,BLACK);
            bar(xr,yr,xr+10,yr+10);

            do
            {
                //calc new food
                xr = (1+rand()%630);
                yr = (1+rand()%470);

            }while(getpixel(xr,yr) !=0 && xr>100 && yr >10);
            xr = xr/10;
            xr = xr*10;
            yr = yr/10;
            yr = yr*10;
        }

        //display food

        setfillstyle(SOLID_FILL,YELLOW);
        bar(xr,yr,xr+10,yr+10);

        //Now keys

        if(GetAsyncKeyState(VK_RIGHT)){dir=1;}
        else if(GetAsyncKeyState(VK_LEFT)){dir=2;}
        else if(GetAsyncKeyState(VK_UP)){dir=3;}
        else if(GetAsyncKeyState(VK_DOWN)){dir=4;}
        else {dir=0;}

        if(pre==1 && dir==2 ||pre==2 && dir==1 )dir=0;
        if(pre==3 && dir==4 ||pre==4 && dir==3 )dir=0;

        //NOw snake
        switch(dir)
        {
            case 0 : if(pre==1){x[0] = x[0]+10;}
                    else if(pre==2){x[0] = x[0]-10;}
                    else if(pre==3){y[0] = y[0]-10;}
                    else if(pre==4){y[0] = y[0]+10;}
                    else{dir=0;}
                    break;

            case 1 : x[0] = x[0]+10;
                        pre = dir;
                        break;

            case 2 : x[0] = x[0]-10;
                        pre = dir;
                        break;

            case 3 : y[0] = y[0]-10;
                        pre = dir;
                        break;

            case 4 : y[0] = y[0]+10;
                        pre = dir;
                        break;

        }

        setfillstyle(SOLID_FILL,GREEN);
        for(int i=0;i<len;i++)
        {
            bar(x[i],y[i],x[i]+10,y[i]+10);
        }
        for(int i=199;i>0;i--)
        {
            x[i] = x[i-1];
            y[i] = y[i-1];
        }

        delay(80);

        //game end

        if(x[0] <= 0 || x[0] >= 640 || y[0]<=0 || y[0]>=480)
        {
            endfn(len,1);
            break;
        }
        int chk=200,f=0;
        for(int i=2;i<len;i++)
        {
            if(x[i] == x[0]&& y[i]==y[0])
            {
                chk=i;
                endfn(len,2);
                f=1;
                break;
            }
        }
        if(f==1)break;





    }



    getch();

    closegraph();

    return 0;
}



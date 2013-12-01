/*----------------------
/	Menu
/
/-------------------------------*/

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

using namespace std;

char Key;
int SelectX,SelectY,Status,Now;

void Menu();
void Intro();
void Game();
void HowToPlay();
void AboutUs();
void MoveCntl();

/*Game COntrolling Function*/
void MoveCntl()
{
    if(kbhit())
    {
        Key = getch();
        if(Key == 72)
        {
            readimagefile("Black.jpg",SelectX,SelectY, SelectX+100,SelectY+50);

            SelectY -= 50;
            Status--;

            if(SelectY < 200)
            {
                SelectY = 350;
                Status = 4;
            }

        }
        else if(Key == 80)
        {
            readimagefile("Black.jpg",SelectX,SelectY, SelectX+100,SelectY+50);

            SelectY += 50;
            Status++;

            if(SelectY > 350)
            {
                SelectY = 200;
                Status = 1;
            }
        }

        else if(Key == 13)
        {
            switch(Status)
            {
            case 1:
                Game();
                break;
            case 2:
                HowToPlay();
                break;
            case 3:
                AboutUs();
                break;
            case 4:
                exit(1);

            }
        }
    }

}

void Intro()
{
    cleardevice();
    setfillstyle(SOLID_FILL,BLACK);
    setbkcolor(BLACK);

    setcolor(YELLOW);
    settextstyle(10,0,10);
    setfillstyle(8,12);

    bgiout<<"M E N U";
    outstreamxy(130,50);

    setcolor(12);
    settextstyle(10,0,6);

    bgiout<<"START";
    outstreamxy(320,200);

    setcolor(6);
    bgiout<<"How To Play";
    outstreamxy(320,250);

    setcolor(3);
    bgiout<<"About Us";
    outstreamxy(320,300);

    setcolor(RED);
    bgiout<<"Quit";
    outstreamxy(320,350);


}

void HowToPlay()
{
    cleardevice();
    readimagefile("HowToPlay-1.jpg",0,0,800,600);
    getch();
    cleardevice();
    Menu();
}

void AboutUs()
{
    cleardevice();
    readimagefile("AboutUs-2.jpg",0,0,800,600);
    getch();
    cleardevice();
    Menu();
}


void Menu()
{
    cleardevice();
    Intro();
    SelectX = 210;
    SelectY = 200;
    Status = 1;

    while(1)
    {
        readimagefile("Bulet2.jpg",SelectX,SelectY, SelectX+100,SelectY+50);
        if(kbhit())
        {
            MoveCntl();
        }
    }
    cleardevice();
}

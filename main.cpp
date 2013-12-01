/*--------------------------------------------------------------------------------------/
/                                                                                       /
/   MD MAHADI HASAN NAHID                                                               /
/                                                                                       /
/--------------------------------------------------------------------------------------*/



#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

using namespace std;

int WeaponX,WeaponY,W_Position,BuletX,BuletY,Balloon1X,Balloon1Y,Balloon2X,Balloon2Y,Balloon3X,Balloon3Y,Score,Life,Level;
int Time,Speed,BalloonN,Point;
char Hit;


char *imgpointer=NULL;

void Menu();
void Loading();
void HowToPlay();
void AboutUs();
void Intro();

void Game();
void MoveWeapon();
void MoveBulet();
void GameOver();
void LifeScoreLevel();
void BalloonFly1(int);
void BalloonFly2(int);
void BalloonFly3(int);

void Loading()
{
    cleardevice();

    settextstyle(10,0,6);
    setcolor(RED);
    bgiout<<"L";
    outstreamxy(210,200);
    delay(100);
    setcolor(RED);
    bgiout<<"O";
    outstreamxy(250,200);
    delay(100);
    setcolor(2);
    bgiout<<"A";
    outstreamxy(290,200);
    delay(100);
    setcolor(5);
    bgiout<<"D";
    outstreamxy(330,200);
    delay(100);
    setcolor(3);
    bgiout<<"I";
    outstreamxy(370,200);
    delay(100);
    setcolor(8);
    bgiout<<"N";
    outstreamxy(410,200);
    delay(100);
    setcolor(6);
    bgiout<<"G";
    outstreamxy(450,200);
    delay(100);
    setcolor(9);
    bgiout<<". ";
    outstreamxy(490,200);
    delay(100);
    setcolor(12);
    bgiout<<". ";
    outstreamxy(530,200);
    delay(100);
    setcolor(13);
    bgiout<<".";
    outstreamxy(570,200);
    delay(100);
    setfillstyle(SOLID_FILL,6);
    bar(200,300,300,330);
    delay(800);
    setfillstyle(SOLID_FILL,8);
    bar(350,300,450,330);
    delay(500);
    setfillstyle(SOLID_FILL,GREEN);
    bar(500,300,600,330);
    delay(500);
    cleardevice();
}


void Game()
{
    cleardevice();
    setfillstyle(SOLID_FILL,WHITE);
    bar(-5,-5,805,605);

    WeaponX = 0;
    WeaponY = 280;
    W_Position = 250;
    Time = 0;
    BuletX = 0;
    BuletY = 280;
    Balloon1X = 750;
    Balloon1Y = 550;
    Balloon2X = 700;
    Balloon2Y = 500;
    Balloon3X = 650;
    Balloon3Y = 450;
    Speed = 1;
    Score = 0;
    Point = 5;
    Life = 5;
    Level = 1;
    BalloonN = 1;

    while(1)
    {
        setfillstyle(SOLID_FILL,WHITE);

        LifeScoreLevel();

        if(Life <= 0)
        {
            GameOver();
            delay(2000);
            cleardevice();
            Menu();
            break;
        }
        if(Level > 3)
        {
            Level = 3;
        }
        if(Level == 1)
        {
            BalloonFly1(BalloonN);
        }
        else if(Level == 2)
        {
            BalloonFly2(BalloonN);
        }
        else if(Level == 3)
        {
            BalloonFly3(BalloonN);
        }

        readimagefile("AK47.jpg",WeaponX,WeaponY,WeaponX+100,WeaponY+100);

        if(kbhit())
        {
            MoveWeapon();
        }
    }
    cleardevice();
}

void MoveWeapon()
{
    Hit = getch();

    if(Hit == 72)
    {
        WeaponY-=15;
        BuletY= WeaponY+25;

        if(WeaponY < -100)
        {
            WeaponY = 500;
        }

    }
    else if(Hit == 80)
    {
        WeaponY+=15;
        BuletY= WeaponY+25;

        if(WeaponY > 600)
        {
            WeaponY = 5;
        }

    }
    else if(Hit == 13)
    {
        readimagefile("Bulet.jpg", BuletX+100,BuletY,BuletX+150,BuletY+50);
        MoveBulet();
        BuletX = 105;
    }

    return;
}

void MoveBulet()
{
    while(BuletX < 800)
    {
        readimagefile("BuletClose.jpg", BuletX+100,BuletY,BuletX+150,BuletY+50);
        BuletX += 15;
        readimagefile("Bulet.jpg", BuletX+100,BuletY,BuletX+150,BuletY+50);

        if((BuletY >= Balloon3Y-20) && (BuletY <= Balloon3Y+55)&& (WeaponY != W_Position))
        {
            Balloon3Y = 450;
            Score += Point;
            W_Position = WeaponY;
            BalloonN = rand() % 4;
        }

        if((BuletY >= Balloon2Y-20) && (BuletY <= Balloon2Y+55)&& (WeaponY != W_Position))
        {
            Balloon2Y = 550;
            Score += Point;
            W_Position = WeaponY;
            BalloonN = rand() % 4;
        }

        if((BuletY >= Balloon1Y-20) && (BuletY <= Balloon1Y+55)&& (WeaponY != W_Position))
        {
            Balloon1Y = 600;
            Score += Point;
            W_Position = WeaponY;
            BalloonN = rand() % 4;
        }
    }
}

void BalloonFly1(int BalloonN)
{
    while(1)
    {
        if(BalloonN == 1)
            readimagefile("B3.jpg",Balloon1X,Balloon1Y,Balloon1X+55,Balloon1Y+100);
        else if(BalloonN == 2)
            readimagefile("B1.jpg",Balloon1X,Balloon1Y,Balloon1X+55,Balloon1Y+100);
        else
            readimagefile("B4.jpg",Balloon1X,Balloon1Y,Balloon1X+55,Balloon1Y+100);

        Balloon1Y -= Speed;

        if(Balloon1Y < -100)
        {
            Balloon1Y = 430;
            Life-=1;
            BalloonN = rand() % 4;
        }
        break;
    }

}
void BalloonFly2(int BalloonN)
{
    while(1)
    {
        if(BalloonN == 1)
        {

            readimagefile("B2.jpg",Balloon1X,Balloon1Y,Balloon1X+55,Balloon1Y+100);
            readimagefile("B3.jpg",Balloon2X,Balloon2Y,Balloon2X+55,Balloon2Y+100);
        }
        else if(BalloonN == 2)
        {

            readimagefile("B1.jpg",Balloon1X,Balloon1Y,Balloon1X+55,Balloon1Y+100);
            readimagefile("B4.jpg",Balloon2X,Balloon2Y,Balloon2X+55,Balloon2Y+100);
        }
        else
        {
            readimagefile("B4.jpg",Balloon1X,Balloon1Y,Balloon1X+55,Balloon1Y+100);
            readimagefile("B2.jpg",Balloon2X,Balloon2Y,Balloon2X+55,Balloon2Y+100);
        }

        Balloon1Y -= Speed;
        Balloon2Y -= Speed;

        if(Balloon1Y < -100)
        {
            Balloon1Y = 320;
            Life-=1;
            BalloonN = rand() % 4;
        }

        if(Balloon2Y < -100)
        {
            Balloon2Y = 410;
            Life-=1;
            BalloonN = rand() % 4;
        }

        break;
    }

}

void BalloonFly3(int BalloonN)
{
    while(1)
    {
        if(BalloonN == 1)
        {

            readimagefile("B2.jpg",Balloon1X,Balloon1Y,Balloon1X+55,Balloon1Y+100);
            readimagefile("B4.jpg",Balloon2X,Balloon2Y,Balloon2X+55,Balloon2Y+100);
            readimagefile("B3.jpg",Balloon3X,Balloon3Y,Balloon3X+55,Balloon3Y+100);

        }
        else if(BalloonN == 2)
        {

            readimagefile("B3.jpg",Balloon1X,Balloon1Y,Balloon1X+55,Balloon1Y+100);
            readimagefile("B1.jpg",Balloon2X,Balloon2Y,Balloon2X+55,Balloon2Y+100);
            readimagefile("B4.jpg",Balloon3X,Balloon3Y,Balloon3X+55,Balloon3Y+100);
        }

        else
        {

            readimagefile("B4.jpg",Balloon1X,Balloon1Y,Balloon1X+55,Balloon1Y+100);
            readimagefile("B3.jpg",Balloon2X,Balloon2Y,Balloon2X+55,Balloon2Y+100);
            readimagefile("B1.jpg",Balloon3X,Balloon3Y,Balloon3X+55,Balloon3Y+100);
        }

        Balloon1Y -= Speed;
        Balloon2Y -= Speed;
        Balloon3Y -= Speed;



        if(Balloon1Y < -100)
        {
            Balloon1Y = 490;
            Life-=1;
            BalloonN = rand() % 4;
        }
        if(Balloon2Y < -100)
        {
            Balloon2Y = 320;
            Life-=1;
            BalloonN = rand() % 4;
        }
        if(Balloon3Y < -100)
        {
            Balloon3Y = 235;
            Life-=1;
            BalloonN = rand() % 4;
        }

        break;
    }

}

void LifeScoreLevel()
{
    settextstyle(10,0,6);
    setbkcolor(WHITE);
    setcolor(BLUE);
    bgiout<<"SCORE: "<< Score;
    outstreamxy(250,30);
    setcolor(GREEN);
    bgiout<<"LIFE : "<< Life;
    outstreamxy(250,80);
    setcolor(RED);
    bgiout<<"LEVEL: "<< Level;
    outstreamxy(250,130);

    if(Score == 20)
    {
        Level = 2;
        Point = 10;
        Speed = 1.5;
        Score += 20;
    }
    else if(Score == 200)
    {
        Level = 3;
        Speed = 2;
        Score += 50;
    }

    if(Score == 650)
    {
        Speed = 3;
    }

    return;
}

void GameOver()
{
    setfillstyle(SOLID_FILL,BLACK);
    bar(-5,-5,805,605);
    settextstyle(10,0,6);
    setcolor(RED);
    setbkcolor(BLACK);
    bgiout<<"GAME OVER"<<"\n";
    outstreamxy(265,200);
    setcolor(GREEN);
    bgiout<<"YOUR SCORE: "<<Score;
    outstreamxy(200,300);

    return;
}


int main(int argc, char** argv)
{
    initwindow(800,600, "SHOOT BALLOON");

    Loading();
    Menu();
    delay(10000);

    return 0;
}

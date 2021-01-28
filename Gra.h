#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;
bool player_dead = false;

int command;
int lvl = 1;
int x = 2;
int y = 2;
int hp, dmg, fhp, fdmg;
int rhp, rdmg, rfdmg;
float exp, nexp = 100;
string movement;


void menu();
void gra();
void map();
void staty();
void input();
void logic();
void which_class();
void fight();
void rat();


void menu()
{
    system("cls");
    cout << "Cool game title" << endl << endl;
    cout << "Start new game" << endl;
    cout << "Exit" << endl;
    cin >> command;

     switch (command)
      {
         case 1:
             {
                which_class();
             }break;
         case 2:
            {
                cout << "Too bad you are living us :/" << endl;
                exit(0);
            }break;
         default:
            {
                cout << "It seems that we heaven't this function yet" << endl; Sleep(1500);
                menu();
            }break;
      }

    }

void which_class()
{
    system("cls");
    cout<<"Choose your character class" << endl << endl;
    cout << "Warrior" << endl;
    cout << "Thief" << endl;
    cout << "Wizard" << endl;
    cout << "Jew" << endl;
    cin >> command;

    switch(command)
    {
case 1:
    {
        hp = 40;
        dmg = 4;
        gra();
    }break;
case 2:
    {
        hp = 30;
        dmg = 6;
        gra();
    }break;
case 3:
    {
        hp = 25;
        dmg = 9;
        gra();
    }break;
case 4:
    {
        hp = 15;
        dmg = 15;
        gra();
    }break;
default:
    {
        cout << "We haven't got this typ of class" << endl; Sleep(1500);
        cout << "At least for now" << endl; Sleep(500);
        which_class();
    }break;
    }
}

void gra()
{
    system("cls");
    map();
    staty();
    input();
    logic();
}
void map()
{
    if(x == 2 && y == 2)
    {
        cout << "Main Location" << endl;
    }
    if(x == 1 && y == 1)
    {
        cout << "City" << endl;
    }
    if(x == 3 && y == 3)
    {
        cout << "Village" << endl;
    }
    if(x == 5 && y == 5)
    {
        cout << "Swamp" << endl;
    }
}
void staty()
{
    cout << "Current Position X:" <<x << " Y:" << y << endl;
    cout << "HP:" << hp << " DMG:" << dmg << " LVL:" << lvl << " EXP:" << "/" << nexp << endl;
}
void input()
{
    cin >> movement;

    if(movement == "w")
    {
        y+=1;

    }
    else if(movement == "s")
    {
        y-=1;

    }
    else if(movement == "a")
    {
        x+=1;

    }
    else if(movement == "d")
    {
        x-=1;

    }
    else if(movement == "fight")
    {
        rat();
        fight();
    }
    else
    {
        cout << "I use all of my brain power and I can't find this command :/" << endl; Sleep(1500);
        gra();
    }
}
void logic()
{
    if(exp>=nexp)
    {
        exp=0;
        lvl+=1;
        hp+=2;
        dmg+=2;
        nexp*=1.15;
    }
}
void fight()
{
    cout << "Fight has been started" << endl; Sleep(1000);
    system("cls");

    fhp=hp;

    while(rhp>=1 && fhp>=1)
    {
        system("cls");
        cout << "You -> HP:" << hp << " DMG:" << dmg << " LVL:" << lvl << " EXP:" << "/" << nexp << endl;
        cout << "Opponent -> HP:" << rhp << " DMG:" << rdmg << endl << endl;

        fdmg = rand() % dmg;
        cout << "Your dmg: " << fdmg << endl;
        rhp-=fdmg;
        Sleep(500);

        rdmg = rand() % dmg;
        cout << "Opponent dmg: " << rfdmg << endl << endl;
        hp-=rfdmg;
        Sleep(500);
    }
    gra();
}
void rat()
{
    rhp = 10;
    rdmg = 2;
}

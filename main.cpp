#include<iostream>
#include "console.h"
#include<vector>
#include<conio.h>
#include<stdio.h>
#include<time.h>
using namespace std;
int snake_long = 4;
int check;

struct snake_seg
{
    int x;
    int y;
};
snake_seg newXY;
snake_seg last;
vector<snake_seg>snake;
void drawMap(); //draw a map
void drawSnake(int x,int y); //draw the snake
void pause();
void startGame();
bool gameOn();
bool touchBack();
snake_seg apple;
bool touchApp();
int score = 0;
int main()
{
    srand(time(0));
    apple = {rand()%100-1,rand()%26};
    Console::SetCursorPosition(apple.x,apple.y);
    cout << "*";
    Console::SetTitle("Snake");
   drawMap();
   drawSnake(50,13);
   while(gameOn())
   {
    startGame();
    if(touchApp())
    {
        apple = {rand()%100-10,rand()%26-1};
        Console::SetCursorPosition(apple.x,apple.y);
        cout << "*";
        snake.push_back(last);
        score++;
    }
    Console::SetCursorPosition(1,28);
    cout << score;
   }
   Console::SetCursorPosition(1,28);
   cout << "thua roi nhe" << endl;
   cout << "diem so hien tai la: " <<score;
}

void drawMap()
{
    for(int x = 10;x<=100;x+=90)
    {
        for(int y = 1;y<=26;y++)
        {
            Console::SetCursorPosition(x,y);
            cout << "X";
        }
    }
    for(int y = 1;y<=26;y+=25)
    {
        for(int x = 10;x<=100;x++)
        {
            Console::SetCursorPosition(x,y);
            cout << "X";
        }
    }
}
void drawSnake(int x,int y)
{
    for(int i = 0;i<snake_long;i++)
    {
        snake_seg t = {x,y};
        snake.push_back(t);
        x--;
    }
    for(int i = 0; i<snake.size();i++)
    {
        Console::SetCursorPosition(snake[i].x,snake[i].y);
        if(i==0)
        {
            cout << "O";
        }
        else
        {
            cout << "o";
        }
    }
}


void startGame()
{

    if(kbhit())
       {
           char ch = getch();
           if(ch=='w'&&check!=1)
           {
            check = 0;
           }

            if(ch=='s'&&check!=0)
            {
            check = 1;
            }

            if(ch=='a'&&check!=3)
            {
            check = 2;
            }

            if(ch=='d'&&check!=2)
            {
            check = 3;
            }

       }

       if(check==0){
        newXY = {snake[0].x,snake[0].y-1};
       }

        if(check==1){
        newXY = {snake[0].x,snake[0].y+1};
        }
        if(check==2){
        newXY = {snake[0].x-1,snake[0].y};
        }

        if(check==3){
        newXY = {snake[0].x+1,snake[0].y};
        }

       snake.insert(snake.begin(),newXY);
       snake.pop_back();

       last = snake[snake.size()-1];
       for(int i = 0;i<snake.size();i++)
       {
           Console::SetCursorPosition(snake[i].x,snake[i].y);
           cout << "o";
       }
       Sleep(100);
       Console::SetCursorPosition(last.x,last.y);
       cout << " ";
       }

bool gameOn()
{
    if(snake[0].y==1||snake[0].y==26)
    {
        return false;
    }
    else if(snake[0].x==10||snake[0].x==100)
    {
        return false;
    }
    else if(touchBack()==true)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool touchBack()
{
    for(int i = 1;i<snake.size();i++)
    {
        if(snake[0].x==snake[i].x&&snake[0].y==snake[i].y)
        {
            return true;
        }
    }
}

bool touchApp()
{
    if(snake[0].x==apple.x&&snake[0].y==apple.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

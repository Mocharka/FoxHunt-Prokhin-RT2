#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class FOX{
    public:
int x;
int y;
};

void gotoxy (int x, int y){
    COORD p = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
    }



void DrawBoard(){
for (int x = 0; x < 11; x++){
   for (int y = 0; y < 21; y++){
        gotoxy(4 * x, y);
        cout<< "|";
    }
}
for (int x = 0; x < 10; x++){
    for (int y = 0; y < 11; y++){
        gotoxy(1 + 4 * x , 2 * y);
        cout<< "---";
}
}
 cout<< "\n\n\n";
}




int FoxInitialize(){
    int a;
    int b;
    a = rand();
    b = rand();
    while (a >= 10)
    a = a % 10;
    return a+1;
}

int checking(int a, int b, int a1, int b1, int c){
int v1 = 1;
while ((a1 - v1) > 0 && (b1 - v1) > 0 ){
if (a == (a1 - v1) && b == (b1 - v1)){c++;}
v1++;
}

  int v2 = 1;
    while (a1 - v2 > 0 && b1 - v2 <= 10 ){
if (a == a1 - v2 && b == b1 + v2){c++;}
v2++;
}

int v3 = 1;
    while (a1 - v3 <= 10 && b1 - v3 > 0 ){
if (a == a1 + v3 && b == b1 - v3){c++;}
v3++;
}

int v4 = 1;
        for (int f = 0; f < 10; f++){
if (a == a1 + v4 && b == b1 + v4){c++;}
v4++;
}
return c;
}










int main()
{
FOX fox[6];
int userX;
int userY;
int x1;
int y1;
int FoxesInCell = 0;
int Count = 0;
int win;
int steps = 0;



DrawBoard();                                                // Draw a board
srand(time(NULL));

for (int i = 0; i < 7; i++){                                // Assign random coords
fox[i].x = FoxInitialize();
};
for (int i = 0; i < 7; i++){
fox[i].y = FoxInitialize();
};


while (win < 7){
steps++;
gotoxy(0, 21);
cout << "Select x coordinate(1 to 10):";
cin >> userX;
gotoxy(0, 22);
cout << "Select y coordinate(1 to 10):";
cin >> userY;

for (int i = 0; i < 7; i++){

Count = checking(fox[i].x, fox[i].y, userX, userY, Count);

if (fox[i].x == userX && fox[i].y == userY ){       // at the point
   FoxesInCell++;
}

if (fox[i].x == userX && fox[i].y != userY)         // vertical check
    Count++;

if (fox[i].x != userX && fox[i].y == userY)         // horizontal check
    Count++;

}

gotoxy(1 + 4 * (userX - 1), 1 + 2 * (userY - 1));   // diagonal check

win = win + FoxesInCell;
if (FoxesInCell == 0){
    cout << " " << Count;
    Count = 0;
};
if (FoxesInCell == 1)
    cout << "*!*";
if (FoxesInCell == 2)
    cout << "!x2";
if (FoxesInCell == 3)
    cout << "!x3";
FoxesInCell = 0;
gotoxy(0, 24);
cout << "Steps:"<< steps <<endl;

gotoxy(29, 21);
cout << "  ";
gotoxy(29, 22);
cout << "  ";
}





gotoxy(0, 24);
cout << "You win!!!" << endl;
}

#include <stdio.h>
#include <conio.h>
#include <windows.h>

// Function to set the console cursor position
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to draw the road
void drawRoad() {
    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 40; j++) {
            if (i == 0 || i == 19) {
                printf("-");
            } else if (j == 10 || j == 30) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to draw the car at a specific position
void drawCar(int x, int y) {
    gotoxy(x, y);
    printf("###");
    gotoxy(x, y + 1);
    printf("|_|");
}

// Function to move the car left or right
void moveCar(int *carX, char direction) {
    if (direction == 'a') {
        *carX -= 1;
    } else if (direction == 'd') {
        *carX += 1;
    }
}

int main() {
    int carX = 15; // Initial position of the car
    int carY = 18;

    char input;

    while (1) {
        if (kbhit()) {
            input = getch();
            moveCar(&carX, input);
        }

        system("cls"); // Clear the console

        drawRoad();
        drawCar(carX, carY);

        Sleep(50); // Delay to control the game speed
    }

    return 0;
}

#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

// Global variables for coordinates and center
int x1, y_1, x2, y2, mx, my, depth;

void translate3DBar(int transX, int transY) {
    // Translate the coordinates
    x1 += transX;
    y_1 += transY;
    x2 += transX;
    y2 += transY;

    // Clear the device and redraw the translated bar
    
    bar3d(x1, y_1, x2, y2, depth, 1);
    outtextxy(x1 + 50, y_1 + 15, (char*)"Translated");
}

void rotate3DBar(float angle) {
    // Convert angle to radians
    float rad = angle * (3.14 / 180);

    // Calculate new positions for the rectangle corners after rotation
    float x1r = mx + (x1 - mx) * cos(rad) - (y_1 - my) * sin(rad);
    float y_1r = my + (x1 - mx) * sin(rad) + (y_1 - my) * cos(rad);
    float x2r = mx + (x2 - mx) * cos(rad) - (y2 - my) * sin(rad);
    float y2r = my + (y2 - my) * cos(rad) + (y2 - my) * sin(rad);

    int a1 = (int)x1r;
    int b1 = (int)y_1r;
    int a2 = (int)x2r;
    int b2 = (int)y2r;

    // Determine depth based on the rotated coordinates
    if (a2 > a1)
        depth = (a2 - a1) / 4;
    else
        depth = (a1 - a2) / 4;

    
    bar3d(a1, b1, a2, b2, depth, 1);
    outtextxy(a1 - 50, b1 - 50, (char*)"Rotated");
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    printf("\n3D Translation and Rotation");

    // Default values for the coordinates
    x1 = 100;
    y_1 = 100;
    x2 = 250;
    y2 = 150;

    mx = (x1 + x2) / 2;
    my = (y_1 + y2) / 2;
    depth = (x2 - x1) / 4;

    // Draw the original 3D bar
    bar3d(x1, y_1, x2, y2, depth, 1);
    outtextxy(x1 + 50, y_1 - 15, (char*)"Object");
    getch();
    cleardevice();

    // Example: translating by (50, 50)
    translate3DBar(50, 50);
    getch();
//    cleardevice();

    // Example: rotating by 180 degrees
    rotate3DBar(180);

    getch();

    closegraph();
    return 0;
}

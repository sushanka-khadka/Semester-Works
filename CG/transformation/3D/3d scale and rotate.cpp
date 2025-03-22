#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

// Global variables for coordinates and center
int x1, y_1, x2, y2, mx, my, depth;

void scale3DBar(float scaleX, float scaleY) {
    // Calculate scaled coordinates
    x1 = mx + (x1 - mx) * scaleX;
    y_1 = my + (y_1 - my) * scaleY;
    x2 = mx + (x2 - mx) * scaleX;
    y2 = my + (y2 - my) * scaleY;

    // Determine depth based on the scaled coordinates
    depth = abs(x2 - x1) / 4;

    // Draw the scaled 3D bar
    bar3d(x1, y_1, x2, y2, depth, 1);
    outtextxy(x1 + 20, y_1 + 15, (char*)"Scaled");
}

void rotate3DBar(float angle) {
    // Convert angle to radians
    float rad = angle * (3.14 / 180);

    // Calculate new positions for the rectangle corners after rotation
    float x1r = mx + (x1 - mx) * cos(rad) - (y_1 - my) * sin(rad);
    float y_1r = my + (x1 - mx) * sin(rad) + (y_1 - my) * cos(rad);
    float x2r = mx + (x2 - mx) * cos(rad) - (y2 - my) * sin(rad);
    float y2r = my + (y2 - my) * cos(rad) + (y2 - my) * sin(rad);

    // Determine depth based on the rotated coordinates
    depth = abs(x2r - x1r) / 4;

    // Draw the rotated 3D bar
    bar3d((int)x1r, (int)y_1r, (int)x2r, (int)y2r, depth, 1);
    outtextxy((int)x1r + 50, (int)y_1r - 50, (char*)"Rotated");
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    printf("\n3D Scaling and Rotation");

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

    // Example: scaling by 1.5 in both x and y directions
    scale3DBar(1.5, 1.5);
    getch();
//    cleardevice();

    // Example: rotating by 270 degrees
    rotate3DBar(270);
    getch();

    closegraph();
    return 0;
}

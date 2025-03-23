#include <graphics.h>
#include <conio.h>
#include <stdio.h>

// Global variables for coordinates and center
int x1, y_1, x2, y2, mx, my, depth;

void draw();
void scale3DBar(float scaleX = 1.0, float scaleY = 1.0);
void translate3DBar(int transX = 0, int transY = 0);

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    printf("\n3D Scaling and Translation");

    // Default values for the coordinates
    x1 = 100;
    y_1 = 100;
    x2 = 200;
    y2 = 200;

    mx = (x1 + x2) / 2;
    my = (y_1 + y2) / 2;
    depth = (x2 - x1) / 4;

    draw();
    getch();
    cleardevice();

    // Example: scaling by 1.5 in both x and y directions
    scale3DBar(1.5, 1.5);

    getch();
//    cleardevice();

    // Example: translating by (50, 50)
    translate3DBar(160, 150);

    getch();
    closegraph();
    return 0;
}

void draw() {
    bar3d(x1, y_1, x2, y2, depth, 1);
    outtextxy(x1 + 50, y_1 - 15, (char*)"Object");
}

void scale3DBar(float scaleX, float scaleY) {
    // Calculate scaled coordinates
    int sx1 = mx + (x1 - mx) * scaleX;
    int sy_1 = my + (y_1 - my) * scaleY;
    int sx2 = mx + (x2 - mx) * scaleX;
    int sy2 = my + (y2 - my) * scaleY;

    int sdepth = depth; // Depth remains the same for scaling

    // Draw the scaled 3D bar
    bar3d(sx1, sy_1, sx2, sy2, sdepth, 1);
    outtextxy(sx1 + 50, sy_1 - 15, (char*)"Scaled");
    setcolor(15);
}

void translate3DBar(int transX, int transY) {
    // Calculate translated coordinates based on the scaled coordinates
    int tx1 = mx + (x1 - mx) * 1.5 + transX;
    int ty_1 = my + (y_1 - my) * 1.5 + transY;
    int tx2 = mx + (x2 - mx) * 1.5 + transX;
    int ty2 = my + (y2 - my) * 1.5 + transY;

    // Draw the translated 3D bar
    bar3d(tx1, ty_1, tx2, ty2, depth, 1);
    outtextxy(tx1 + 50, ty_1 - 15, (char*)"Translated");
    setcolor(15);
}

#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Function to display pixels
void disp(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, 7);
    putpixel(xc - x, yc + y, 7);
    putpixel(xc + x, yc - y, 7);
    putpixel(xc - x, yc - y, 7);
}

int main() {
    int gd = DETECT, gm;
    int xc, yc, rx, ry;
    float x, y, p1, p2;

    // Initialize graphics
    initgraph(&gd, &gm, NULL);

    // Input center and radii
    printf("Enter the center point (xc, yc): ");
    scanf("%d%d", &xc, &yc);
    printf("Enter the value for Rx and Ry: ");
    scanf("%d%d", &rx, &ry);

    x = 0;
    y = ry;

    // Initial decision parameter for region 1
    p1 = (ry * ry) - (rx * rx * ry) + (rx * rx) / 4.0;

    // Region 1
    while ((2.0 * ry * ry * x) <= (2.0 * rx * rx * y)) {
        disp(xc, yc, (int)x, (int)y);
        x++;
        if (p1 <= 0) {
            p1 = p1 + (2.0 * ry * ry * x) + (ry * ry);
        } else {
            y--;
            p1 = p1 + (2.0 * ry * ry * x) - (2.0 * rx * rx * y) + (ry * ry);
        }
    }

    // Initial decision parameter for region 2
    p2 = (ry * ry * (x + 0.5) * (x + 0.5)) + (rx * rx * (y - 1) * (y - 1)) - (rx * rx * ry * ry);

    // Region 2
    while (y >= 0) {
        disp(xc, yc, (int)x, (int)y);
        y--;
        if (p2 > 0) {
            p2 = p2 + (rx * rx) - (2.0 * rx * rx * y);
        } else {
            x++;
            p2 = p2 + (2.0 * ry * ry * x) - (2.0 * rx * rx * y) + (rx * rx);
        }
    }

    getch();
    closegraph();

    return 0;
}
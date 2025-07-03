#include <stdio.h>
  #include <conio.h>
  #include <math.h>
  #include <time.h>
  #include <dos.h>

  /*
   * finds the points at 0, 30, 60,..,360 degrees
   * on the given circle.  x value corresponds to
   * radius * cos(angle) and y value corresponds 
   * to radius * sin(angle).
   */
  void calcPoints(int radius, int midx, int midy, int x[12], int y[12]) {
        int x1, y1;

        /* 90, 270, 0, 180 degrees */
        x[0] = midx, y[0] = midy - radius;
        x[6] = midx, y[6] = midy + radius;
        x[3] = midx + radius, y[3] = midy;
        x[9] = midx - radius, y[9] = midy;

        /* 30, 150, 210, 330 degrees */
        x1 = (int) ((radius / 2) * sqrt(3));
        y1 = (radius / 2);
        x[2] = midx + x1, y[2] = midy - y1;
        x[4] = midx + x1, y[4] = midy + y1;
        x[8] = midx - x1, y[8] = midy + y1;
        x[10] = midx - x1, y[10] = midy - y1;

        /* 60, 120, 210, 300 degrees */
        x1 = radius / 2;
        y1 = (int) ((radius / 2)  * sqrt(3));
        x[1] = midx + x1, y[1] = midy - y1;
        x[5] = midx + x1, y[5] = midy + y1;
        x[7] = midx - x1, y[7] = midy + y1;
        x[11] = midx - x1, y[11] = midy - y1;

        return;
  }


  int main() {
        /* request auto detection */
        int gdriver = DETECT, gmode, err;
        int i, j, midx, midy, radius;
        int x[12], y[12];

        /* initialize graphic mode */
        initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
        err = graphresult();

        if (err != grOk) {
                /* error occurred */
                printf("Graphics Error: %s",
                                grapherrormsg(err));
                return 0;
        }

        /* mid position at x-axis & y-axis correspondingly */
        midx = getmaxx() / 2;
        midy = getmaxy() / 2;

        /* radius of rim */
        radius = 200;

        /* finds the position of spokes */
        calcPoints(radius, midx, midy, x, y);

        /* drawing rim of the wheel */
        setlinestyle(SOLID_LINE, 1, 3);
        circle(midx, midy, radius);

        /* rotate wheel until user hits any key on the keyboard */
        while (!kbhit()) {
                setcolor(WHITE);
                /* spokes at angle 30, 90, 150, 210, 270, 330 */
                for (i = 0; i < 12; i++) {
                        if (i % 2 == 0) {
                                line(midx, midy, x[i], y[i]);
                        }
                }

                /* sleep for 100 milliseconds */
                delay(100);

                /* erase the above drawn spokes to get rotating illusion */
                for (i = 0; i < 12; i++) {
                        setcolor(BLACK);
                        if (i % 2 == 0) {
                                line(midx, midy, x[i], y[i]);
                                setcolor(WHITE);
                                putpixel(x[i], y[i], WHITE);
                        }
                }

                /* spokes at 60, 120, 180, 240, 300, 360 */
                setcolor(WHITE);
                for (i = 0; i < 12; i++) {
                        if (i % 2 != 0) {
                                line(midx, midy, x[i], y[i]);
                        }
                }

                delay(100);

                /* erase the above drawn spokes to get rotating illusion */
                for (i = 0; i < 12; i++) {
                        setcolor(BLACK);
                        if (i % 2 != 0) {
                                line(midx, midy, x[i], y[i]);
                                setcolor(WHITE);
                                putpixel(x[i], y[i], WHITE);
                        }
                }
        }

        getch();

        /* deallocate memory allocated for graphic screen */
        closegraph();
        return 0;
  }
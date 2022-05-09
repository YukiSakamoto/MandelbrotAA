#include <stdio.h>
#include <math.h>

const int times = 200;
const double x_max = 1;
const double x_min =-2;
const double y_max = 1;
const double y_min =-1;
const double dx = 0.02;
const double dy = 0.02;


/* If mandelbrot() function returns zero, that inidicates divergence.   */
int mandelbrot(double c_x, double c_y, int n)
{
    double x_n = 0;
    double y_n = 0;
    double x_n_1;
    double y_n_1;
    int i;
    for(i = 0; i < n; i++) {
        x_n_1 = pow(x_n, 2) - pow(y_n, 2) + c_x;
        y_n_1 = 2 * x_n * y_n + c_y;
        if ( pow(x_n_1, 2) + pow(y_n_1, 2) > 4.0 ){
            return n;
        } else {
            x_n = x_n_1;
            y_n = y_n_1;
        }
    }
    return 0;
}

int main(void)
{
    double x;
    double y;
    int x_length = (x_max - x_min) / dx;
    for(y = y_max; y > y_min; y -= dy) {
        for(x = x_min; x < x_max; x += dx) {
            putchar(mandelbrot(x, y, 300) == 0 ? '*' : ' ');
        }
        putchar('\n');
    }
    return 0;
}

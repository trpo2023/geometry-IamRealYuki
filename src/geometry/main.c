#include <libgeometry/geometry.h>
#include <stdio.h>

int main()
{
    double a, p;
    figure[0];

    while (1) {
        fgets(figure, 64, stdin);
        if (figure[0] == 'e') {
            return 0;
        }
        if (circle(figure) == 0) {
            p = perimeter(figure);
            a = area(figure);
            printf("\nperimeter: %f\narea: %f\n", p, a);
        }
    }
    return 0;
}
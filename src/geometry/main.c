#include <malloc.h>
#include <stdio.h>

#include <libgeometry/calc.h>
#include <libgeometry/geometry.h>

int main()
{
    double a, p;
    struct FigureInfo* current
            = (struct FigureInfo*)malloc(sizeof(struct FigureInfo));
    current->prev = NULL;
    while (1) {
        current->circle = (char*)malloc(sizeof(struct FigureInfo));
        fgets(current->circle, 64, stdin);
        if (current->circle[0] == 'e') {
            return 0;
        }
        if (circle(current->circle) == 0) {
            current->next
                    = (struct FigureInfo*)malloc(sizeof(struct FigureInfo));
            p = perimeter(current->circle, current);
            a = area(current->circle, current);
            printf("perimeter: %f\narea: %f\n", p, a);
            intersections(current->circle, current);
            struct FigureInfo* node = current;
            current = current->next;
            current->prev = node;
        }
    }
    return 0;
}
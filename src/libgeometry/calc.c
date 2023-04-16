#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libgeometry/calc.h"

double FindRadius(char* str)
{
    int length = 0;
    char radius[10];
    while (str[length] != ',') {
        length++;
    }

    length++;
    int current = 0;
    while (str[length] != ')') {
        radius[current] = str[length];
        current++;
        length++;
    }
    radius[current + 2] = '\0';
    double Radius = atof(radius);
    return Radius;
}

double perimeter(char str[])
{
    double radius = FindRadius(str);
    double result = M_PI * radius * 2;
    return result;
}

double area(char str[])
{
    double radius = FindRadius(str);
    double result = M_PI * radius * radius;
    return result;
}
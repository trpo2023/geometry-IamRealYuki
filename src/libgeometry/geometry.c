#include <ctype.h>
#include <libgeometry/geometry.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double FindRadius(char* str)
{
    int length = strlen(str);
    char radius[10];
    while (str[length] != ',') {
        length--;
    }

    length++;

    while (str[length] == ' ') {
        length++;
    }

    int current = 0;
    while (str[length] != ' ' && str[length] != ')') {
        radius[current] = str[length];
        current++;
        length--;
    }
    radius[current + 1] = '\0';
    double a = atof(radius);
    return a;
}
double perimeter(char str[])
{
    double radius = FindRadius(str);
    double a = 3.14 * radius * 2;
    return a;
}

double area(char str[])
{
    double radius = FindRadius(str);
    double a = 3.14 * radius * radius;
    return a;
}

int check_num(char figure[], int* ptr)
{
    int current_el = *ptr;

    char str2[13] = "-.0123456789";

    while (figure[current_el] == ' ') {
        current_el++;
    }

    if (figure[current_el] == '0') {
        if (figure[current_el + 1] != '.'
            && strchr(str2, figure[current_el + 1]) != NULL) {
            printf("Error at column %d: expected '.' \n", current_el);
            return 0;
        }
    }

    if (strchr(str2, figure[current_el]) == NULL) {
        printf("Error at column %d: unexpected character\n", current_el);
        return 0;
    }

    while (strchr(str2, figure[current_el]) != NULL) {
        current_el++;
    }

    if (figure[current_el] == ',' || figure[current_el] == ')') {
        printf("Error at column %d: expected number\n", current_el);
        return 0;
    }

    if (figure[current_el] != ' ') {
        printf("Error at column %d: expected ' '\n", current_el);
        return 0;
    }

    while (figure[current_el] == ' ') {
        current_el++;
    }

    if (figure[current_el] == '0') {
        if (figure[current_el + 1] != '.'
            && strchr(str2, figure[current_el + 1]) != NULL) {
            printf("Error at column %d: expected '.'\n", current_el);
            return 0;
        }
    }

    if (strchr(str2, figure[current_el]) == NULL) {
        printf("Error at column %d: unexpected character\n", current_el);
        return 0;
    }

    while (strchr(str2, figure[current_el]) != NULL) {
        current_el++;
    }

    while (figure[current_el] == ' ') {
        current_el++;
    }

    current_el++;
    *ptr = current_el;
    return 1;
}

int circle(char* figure)
{
    char str[6] = "circle";
    char substr[13] = "-.0123456789";

    for (int i = 0; i < 5; i++) {
        figure[i] = tolower(figure[i]);

        if (figure[i] != str[i]) {
            char strerr[6];
            strncpy(strerr, figure, 6);
            strerr[6] = '\0';
            printf("Error at column 0: expected 'circle' instead of %s\n",
                   strerr);
            return -1;
        }
    }

    int k = 7;

    if (figure[6] != '(') {
        printf("Error at column %d: expected '('\n", k);
        return -1;
    }

    if (check_num(figure, &k) == 0) {
        return -1;
    }

    if (figure[k - 1] != ',') {
        printf("Error at column %d: expected ','\n", k);
    }

    while (figure[k] == ' ') {
        k++;
    }

    if (figure[k] == '0') {
        if (figure[k + 1] != '.' && strchr(substr, figure[k + 1]) != NULL) {
            printf("Error at column %d: expected '.'\n", k);
            return -1;
        }
    }

    if (strchr(substr, figure[k]) == NULL) {
        printf("Error at column %d: unexpected character\n", k);
        return -1;
    }

    while (strchr(substr, figure[k]) != NULL) {
        k++;
    }

    if (figure[k] != ')') {
        printf("Error at column %d: expected ')'\n", k);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>

void capture();
double get_side(int position_count);
bool triangle_check(double a, double b, double c);
double perimeter(double a, double b, double c);
double area(double a, double b, double c, double p);
double height(double side, double area);
double median(double a, double b, double c, double p);
double bisector(double a, double b, double c, double p);
bool continue_calculation();
void clear_console();

char* positions[3] = {"First", "Second", "Third"};

// Main function
 
int main()
{
    // Sides

    double a = 0;
    double b = 0;
    double c = 0;

    int position_count;

    // Autor and title

    clear_console();

    capture();

    do
    {
        // Get sides

        do
        {
            // Get all sides of the triangle

            // Get first side

            do
            {
                position_count = 0;
                a = get_side(position_count);
            } 
            while (a == -1);

            // Get second side

            do
            {
                position_count = 1;
                b = get_side(position_count);
            } 
            while (b == -1);

            // Get third side

            do
            {
                position_count = 2;
                c = get_side(position_count);
            } 
            while (c == -1);

        }
        while (!triangle_check(a, b, c) && continue_calculation());

    // Calculations

    double P = perimeter(a, b, c);
    double p = P / 2;

    double S = area(a, b, c, p);

    printf("\nArea: %lf\n\n", S);

    printf("Perimeter: %lf\n\n", P);

    printf("Height drawn to the first side: %lf\n", height(a, S));
    printf("Height drawn to the second side: %lf\n", height(b, S));
    printf("Height drawn to the third side: %lf\n\n", height(c, S));

    printf("Median drawn to the first side: %lf\n", median(a, b, c, p));
    printf("Median drawn to the second side: %lf\n", median(b, a, c, p));
    printf("Median drawn to the third side: %lf\n\n", median(c, a, b, p));

    printf("Bisector drawn to the first side: %lf\n", bisector(a, b, c, p));
    printf("Bisector drawn to the first side: %lf\n", bisector(b, a, c, p));
    printf("Bisector drawn to the first side: %lf\n", bisector(c, a, b, p));

    } 
    while (continue_calculation());
    
    
    return 0;
}

void clear_console() 
{
    system("cls");
}

void capture()
{
    // Author

    printf("\nNadiia Rybak 2023\n");

    // Title

    printf("\nTRIANGLE CALCULATOR\n");

    // Decription

    printf("\nCalculate perimeter, area, length of all heights, medians and bisectors based on the sides of your triangle.\n\n");
}

double get_side(int position_count)
{
    // Get input

    char input[10];

    printf("\n%s side of the triangle (up to 10 symbols): ", positions[position_count]);
    scanf("%s", input);
    
    // Check input

    // Check is that a number

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isdigit(input[i]) == 0 && input[i] != '.' && input[i] != '-')
        {
            printf("\nYour input is invalid\n");
            return -1;
        }
    }

    // Check size and positivity

    double number = atof(input);

    if (number <= 0) 
    {
        printf("\nSide length must be a positive number\n");
        return -1;
    }

    return number;
}

bool triangle_check(double a, double b, double c)
{
    if (a + b <= c || b + c <= a || c + a <= b)
    {
        printf("\nThis triangle cannot exist. Please, enter all of the sides again.\n");
        return false;
    }

    return true;
}

double perimeter(double a, double b, double c)
{
    return (a + b + c);
}

double area(double a, double b, double c, double p)
{
    return (sqrt(p*(p-a)*(p-b)*(p-c)));
}

double height(double side, double area)
{
    return ((2 * area) / side);
}

double median(double a, double b, double c, double p)
{
    return (0.5 * sqrt(2 * (b * b) + 2 * (c * c) - (a * a)));
}

double bisector(double a, double b, double c, double p)
{
    return (2 * sqrt(b * c * p * (p - a)) / (b + c));
}

bool continue_calculation()
{
    printf("\nDo you want to enter all of the sides one more time? (enter/esc) \n");

    while(1)
    {
        char response = getch(); 

        if (response == 13)  
        {
            return true;
        }
        else if (response == 27)  
        {
            return false;
        }
    }
}
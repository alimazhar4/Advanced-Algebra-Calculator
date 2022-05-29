/*
Copyright by TetraGeek (https://www.tetrageek.com)
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
---> The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
---> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

void intro();
double quad_eq();
double simult_eq();
float poly_eq();
void sum_product_poly_roots();
float point_dis();
void triangle_centroid();
void triangle_incentre();
void slope_intercept();
void line_properties();
void pos_of_point();
void intersection_of_lines();
void point_line_dis();
void triangle_region_area();
void help();
void lineprint(float, float, float);


int main(int argc, char* argv)
{

    int option, repeat = 1;

    intro();
    while (1)
    {
        system("color F0");

        printf("\n\t\t\t\t\t\tALGE-BRO\n\n");         //title

        // main menu with cyan background color
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x30);
        printf("\t                                                                                             \n");
        printf("\t MAIN MENU:                                                                                  \n");
        printf("\t                                                                                             ");
        printf("\n\t  Problem #     Topic                                       Category                         \n");
        printf("\t                                                                                             \n");
        printf("\t   1    ....    Roots of Quadratic Equations                Algebra                          \n");
        printf("\t   2    ....    Simultaneous Equations                      Algebra                          \n");
        printf("\t   3    ....    Solution of Polynomial Equations            Algebra                          \n");
        printf("\t   4    ....    Sum and Product of Polynomial Roots         Algebra                          \n");
        printf("\t   5    ....    Distance between two points                 Analytical Geometery             \n");
        printf("\t   6    ....    Slope-Intercept from points                 Analytical Geometery             \n");
        printf("\t   7    ....    Properties of Straight Line                 Analytical Geometery             \n");
        printf("\t   8    ....    Position of a point with respect to line    Analytical Geometery             \n");
        printf("\t   9    ....    Point of intersection of two lines          Analytical Geometery             \n");
        printf("\t   10   ....    Distance of a Point to a line               Analytical Geometery             \n");
        printf("\t   11   ....    Area of a Triangular Region                 Triangular Geometery             \n");
        printf("\t   12   ....    Centroid of a Triangle                      Triangular Geometery             \n");
        printf("\t   13   ....    In Centre of a Triangle                     Triangular Geometery             \n");
        printf("\t                                                                                             ");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
        printf("\n\n\t  Which type of mathematical problem you want to solve? Entre the problem #.\n\t  Entre 0 to know How To Use ALGE-BRO\n\t  Entre -1 to exit\n");
        printf("\t  >>>> ");

        scanf_s("%d", &option);
        printf("\n __________________________________________________________________________________________________________\n");
        if (option == 1)
            quad_eq();
        else if (option == 2)
            simult_eq();
        else if (option == 3)
            poly_eq();
        else if (option == 4)
            sum_product_poly_roots();
        else if (option == 5)
            point_dis();
        else if (option == 6)
            slope_intercept();
        else if (option == 7)
            line_properties();
        else if (option == 8)
            pos_of_point();
        else if (option == 9)
            intersection_of_lines();
        else if (option == 10)
            point_line_dis();
        else if (option == 11)
            triangle_region_area();
        else if (option == 12)
            triangle_centroid();
        else if (option == 13)
            triangle_incentre();
        else if (option == -1)
        {
            printf("\n\n\t\t\tThank you for using ALGE-BRO\n");
            char a = getchar();
            a = getchar();
            exit(0);
        }
        else if (option == 0)
            help();
        else
        {
            system("cls");
            printf("\n\t OOPSIE\n");
            printf("\n\t Please enter a valid number!\n\t Note: The number should be in the MAIN MENU list.\n\t If you don't know how to use ALGE-BRO, press 0 in the MAIN MENU\n\n\t ");
            system("pause");
            system("cls");
            continue;
        }
        printf("\n __________________________________________________________________________________________________________\n");
        printf("\n Press 1 to go to the MAIN MENU. Press 0 to exit\n >>>> ");
        scanf_s("%d", &repeat);
        if (repeat == 0)
            break;
        else if (repeat == 1)
            system("cls");
    }
    printf("\n\n\t\t\tThank you for using ALGE-BRO\n");
    char c = getchar();

    return 0;
}

void intro()
{
    system("color 30");     // applying cyan background and black foreground color
    printf("\n\n\n\n\n\n\n\n");
    printf("       _________             _________   ________          ________    ________     ________\n");
    printf("      |         | |         |         | |                 |        \\  |        \\   /        \\\n");
    printf("      |         | |         |           |                 |         ) |         ) /          \\ \n");
    printf("      |_________| |         |           |________   ___   |________/  |        / (            )\n");
    printf("      |         | |         |   ______  |                 |        \\  |_______/   \\          / \n");
    printf("      |         | |         |         | |                 |         ) |       \\    \\        / \n");
    printf("      |         | |________ |_________| |________         |________/  |        \\    \\______/       by TetraGeek.com\n");

    printf("\n\n\t\t\t\tWelcome to ALGE-BRO, Press enter key to continue....\n");
    char c = getchar();
    system("cls");
}

// function to solve the roots of quadratic equation starts here
double quad_eq()
{
    int restart;
    while (1)
    {
        system("cls");      // clear the screen 
        double a, b, c, discriminant, root1, root2, realPart, imagPart;

        printf("\n\t\t\t\t\tRoots of Quadratic Equations\n");
        printf("\n\n For the Quadratic equation in the form ax^2 + bx + c\n Write the coefficient values of a, b and c\n");
        printf("  a = ");
        scanf_s("%lf", &a);
        printf("  b = ");
        scanf_s("%lf", &b);
        printf("  c = ");
        scanf_s("%lf", &c);

        printf("\n The entered quadratic equation >>> ");
        if (a >= 0 && b >= 0 && c >= 0)
            printf(" %.1fx^2 + %.1fx + %.1f = 0\n", a, b, c);
        else if (a < 0 && b >= 0 && c >= 0)
            printf(" -%.1fx^2 + %.1fx + %.1f = 0\n", (float)abs(a), b, c);
        else if (a >= 0 && b < 0 && c >= 0)
            printf(" %.1fx^2 - %.1fx + %.1f = 0\n", a, (float)abs(b), c);
        else if (a >= 0 && b >= 0 && c < 0)
            printf(" %.1fx^2 + %.1fx - %.1f = 0\n", a, b, (float)abs(c));
        else if (a < 0 && b < 0 && c >= 0)
            printf(" -%.1fx^2 - %.1fx + %.1f = 0\n", (float)abs(a), (float)abs(b), c);
        else if (a < 0 && b >= 0 && c < 0)
            printf(" -%.1fx^2 + %.1fx - %.1f = 0\n", (float)abs(a), b, (float)abs(c));
        else if (a >= 0 && b < 0 && c < 0)
            printf(" %.1fx^2 - %.1fx - %.1f = 0\n", a, (float)abs(b), (float)abs(c));
        else if (a < 0 && b < 0 && c < 0)
            printf(" -%.1fx^2 - %.1fx - %.1f = 0\n", (float)abs(a), (float)abs(b), (float)abs(c));
        // general formula to find the discriminant
        discriminant = b * b - 4 * a * c;

        // setting the color of the Results box to green
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
        printf("\n\t Results:                           \n");
        // condition for real and different roots
        if (discriminant > 0) {
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b - sqrt(discriminant)) / (2 * a);
            printf("\t    The roots are Real and Distinct \n");
            printf("\t    root1 = %.3lf                  \n", root1);
            printf("\t    root2 = %.3lf                  ", root2);
        }
        // condition for real and equal roots
        else if (discriminant == 0) {
            root1 = root2 = -b / (2 * a);
            printf("\t    The roots are real and Equal    \n");
            printf("\t    root1 = root2 = %.2lf            ", root1);
        }
        // if roots are not real
        else {
            realPart = -b / (2 * a);
            imagPart = sqrt(-discriminant) / (2 * a);
            printf("\t    The roots are Imaginary         \n");
            printf("\t    root1 = %.2lf+%.2lfi             \n\t    root2 = %.2f-%.2fi             ", realPart, imagPart, realPart, imagPart);
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
        printf("\n\n Do want to solve again?\n 1 = yes , 0 = No\n >>>> ");
        scanf_s("%d", &restart);
        if (restart == 0)
            break;
    }
    return 0;
}

// function to solve simultaneous equations start here
double simult_eq()
{
    int restart;
    while (1)
    {
        system("cls");
        double a, b, c, p, q, r, x, y;

        printf("\n\t\t\t\t\tSolutions of Simultaneous Equations\n");

        printf("\n\nEnter the coefficents of the first equation of the form ax + by = c\n");
        printf(" a = ");
        scanf_s("%lf", &a);
        printf(" b = ");
        scanf_s("%lf", &b);
        printf(" c = ");
        scanf_s("%lf", &c);

        printf("Enter the coefficents of the second equation of the form px + qy = r\n");
        printf(" p = ");
        scanf_s("%lf", &p);
        printf(" q = ");
        scanf_s("%lf", &q);
        printf(" r = ");
        scanf_s("%lf", &r);

        // displaying the equations according to the inputs
        printf("\n The entered equations are:\n");
        if (a >= 0 && b >= 0)
            printf("    %.1fx + %.1fy = %.1f\n", a, b, c);
        else if (a < 0 && b >= 0)
            printf("   -%.1fx + %.1fy = %.1f\n", (float)abs(a), b, c);
        else if (a >= 0 && b < 0)
            printf("    %.1fx - %.1fy = %.1f\n", a, (float)abs(b), c);
        else if (a < 0 && b < 0)
            printf("   -%.1fx - %.1fy = %.1f\n", (float)abs(a), (float)abs(b), c);

        if (p >= 0 && q >= 0)
            printf("    %.1fx + %.1fy = %.1f\n", p, q, r);
        else if (p < 0 && q >= 0)
            printf("   -%.1fx + %.1fy = %.1f\n", (float)abs(p), q, r);
        else if (p >= 0 && q < 0)
            printf("    %.1fx - %.1fy = %.1f\n", p, (float)abs(q), r);
        else if (p < 0 && q < 0)
            printf("   -%.1fx - %.1fy = %.1f\n", (float)abs(p), (float)abs(q), r);

        // setting the background color of the results box to green
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
        printf("\n\t Result:                                    ");
        if ((a * q - p * b) != 0 && (b * r - q * a) != 0)
        {
            //In this case we have a unique solution and display x and y
            printf("\n\t    The solution to the equations is unique \n");

            // the general formulas to solve x and y in simultaneous equations
            x = (c * q - r * b) / (a * q - p * b);
            y = (c * p - r * a) / (b * p - q * a);

            printf("\t    The value of x = %.3lf                  \n", x);
            printf("\t    The value of y = %.3lf                  \n", y);
        }

        else if (((a * q - p * b) == 0) && ((b * p - q * a) == 0) && ((c * q - r * b) == 0) && ((c * p - r * a) == 0))
            //In such condition we can have infinitely many solutions to the equation.
        {
            printf("\n\t    Infinitely many solutions are possible  \n");
            printf("\t    The value of x can be varied and y can  \n\t    be calculated according to x's value    \n\t    using relation                          \n");
            printf("\t    y = %.3lf + (%.3lf)x                   ", (c / b), (-1 * a / b));
        }
        else
            if (((a * q - p * b) == 0) && ((b * p - q * a) == 0) && ((c * q - r * b) != 0) && ((c * p - r * a) != 0))
                //In such condition no solutions are possible.
                printf("\n\t    No solutions are possible               ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
        printf("\n\n Do want to solve again?\n 1 = yes , 0 = No\n >>>> ");
        scanf_s("%d", &restart);
        if (restart == 0)
            break;
    }
    return 0;
}

// function to solve the solution of polynomial equations start here
float poly_eq()
{
    int restart;
    while (1)
    {
        system("cls");
        int coefficients[30] = { 0 };
        int i, degree, power;
        float xVal, polySum;

        printf("\n\t\t\t\t\tSolution of Polynomial Equations\n");
        printf("\n\n Enter the order/degree of the polynomial: ");
        scanf_s("%d", &degree);

        // Read the coefficients into an array
        power = degree;
        for (i = 0; i <= degree; i++)
        {
            printf(" Enter the Coefficient of x^%d: ", power);
            scanf_s("%d", &coefficients[i]);
            power--;
        }
        power = degree;

        // output according to the values entered
        printf("\n The entered polynomial is: \n");
        for (i = 0; i <= degree; i++)
        {
            if (power < 0)
            {
                break;
            }
            //printing the proper polynomial function
            if (coefficients[i] > 0)
                printf(" + ");
            else if (coefficients[i] < 0)
                printf(" - ");
            else
                printf(" ");
            printf("%dx^%d", abs(coefficients[i]), power--);
        }
        printf("\n\n Enter the value of x: ");
        scanf_s("%f", &xVal);
        polySum = (float)coefficients[0];
        for (i = 1; i <= degree; i++)
        {
            polySum = polySum * xVal + coefficients[i];
        }
        // setting the background colors of results to green
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
        printf("\n\t Result:                          ");
        printf("\n\t   Sum of the polynomial = %.2f ", polySum);
        printf("\n\t                                  ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
        printf("\n\n Do want to solve again?\n 1 = yes , 0 = No\n >>>> ");
        scanf_s("%d", &restart);
        if (restart == 0)
            break;
    }
    return 0;
}

// function to find the sum and products of the polynomial roots start here
void sum_product_poly_roots()
{
    int restart;
    while (1)
    {
        system("cls");
        int coefficients[30] = { 0 };
        int i, degree = 1, power;
        double rootsum, rootprod;

        printf("\n\t\t\t\t\tSum and Product of Polynomial Roots\n");
        printf("\n\n Enter the order/degree of the polynomial: ");
        scanf_s("%d", &degree);

        // Read the coefficients into an array
        power = degree;
        for (i = 0; i <= degree; i++)
        {
            printf(" Enter the Coefficient of x^%d: ", power);
            scanf_s("%d", &coefficients[i]);
            power--;
        }
        power = degree;

        // output the polynomial according to the values entered
        printf("\n The entered polynomial is: \n  ");
        for (i = 0; i <= degree; i++)
        {
            if (power < 0)
                break;
            //printing the proper polynomial function
            if (coefficients[i] > 0)
                printf(" + ");
            else if (coefficients[i] < 0)
                printf(" - ");
            else
                printf(" ");
            printf("%dx^%d", abs(coefficients[i]), power--);
        }
        rootsum = -((double)coefficients[1] / (double)coefficients[0]);
        rootprod = (double)pow(-1, degree) * (double)coefficients[degree] / (double)coefficients[0];

        // setting the background color of results to green
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
        printf("\n\n\t Results:                          \n");
        printf("\t   - Sum of the Roots = %.2f       \n", rootsum);
        printf("\t   - Product of the Roots = %.2f   ", rootprod);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0); // restting the background color back to white
        printf("\n\n Do want to solve again?\n 1 = yes , 0 = No\n >>>> ");
        scanf_s("%d", &restart);
        if (restart == 0)
            break;
    }
}

// function to find the distance of two points start here
float point_dis()
{
    int restart;
    while (1)
    {
        system("cls");
        double x1, y1, x2, y2, dis;
        printf("\n\t\t\t\t\tDistance between two Coordinate points\n");

        printf("\n Entre the coordinates of the first point:\n");
        printf(" x = ");
        scanf_s("%lf", &x1);
        printf(" y = ");
        scanf_s("%lf", &y1);

        printf("\n Entre the coordinates of the second point:\n");
        printf(" x = ");
        scanf_s("%lf", &x2);
        printf(" y = ");
        scanf_s("%lf", &y2);

        printf("\n Entered points >>> ( %.1f , %.1f ) and ( %.1f , %.1f )\n", x1, y1, x2, y2);

        // calculating distance according to its mathematical formula
        dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
        printf("\n\t Result:             ");
        printf("\n\t    Distance = %.3f ", dis);
        printf("\n\t                     ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
        printf("\n\n Do want to solve again?\n 1 = yes , 0 = No\n >>>> ");
        scanf_s("%d", &restart);
        if (restart == 0)
            break;
    }
    return 0;
}

// function to find the centroid of the traingle starts here
void triangle_centroid()
{
    int restart;
    while (1)
    {
        system("cls");
        float x1, y1, x2, y2, x3, y3, centroidx, centroidy;

        printf("\n\t\t\t\t\tCentroid of a Triangle\n");

        printf("\n For the coordinates in the form (x , y)\n");
        printf("\n Entre the coordinates of first point:\n");
        printf(" x = ");
        scanf_s("%f", &x1);
        printf(" y = ");
        scanf_s("%f", &y1);

        printf("\n Entre the coordinates of second point:\n");
        printf(" x = ");
        scanf_s("%f", &x2);
        printf(" y = ");
        scanf_s("%f", &y2);

        printf("\n Entre the coordinates of third point:\n");
        printf(" x = ");
        scanf_s("%f", &x3);
        printf(" y = ");
        scanf_s("%f", &y3);

        printf("\n Entered coordinates >>> (%.1f , %.1f) , (%.1f , %.1f) and (%.1f , %.1f)", x1, y1, x2, y2, x3, y3);

        // calculating the coordinates of the centroid
        centroidx = (x1 + x2 + x3) / 3;
        centroidy = (y1 + y2 + y3) / 3;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
        printf("\n\n\t Result:                                       ");
        printf("\n\t    Centroid of this triangle is (%.2f , %.2f) ", centroidx, centroidy);
        printf("\n\t                                               ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
        printf("\n\n Do want to solve again?\n 1 = yes , 0 = No\n >>>> ");
        scanf_s("%d", &restart);
        if (restart == 0)
            break;
    }
}

// function to find the incentre of triangle starts here
void triangle_incentre()
{
    int restart;
    while (1)
    {
        system("cls");
        double x1, y1, x2, y2, x3, y3, sideA, sideB, sideC, incentreX, incentreY;
        printf("\n\t\t\t\t\tIn centre of a Triangle\n\n");

        printf("Consider\n Points of the triangle   >>>    A(x , y)    B(x , y)    C(x , y)\n");
        printf(" Coresponding vertices    >>>     a           b           c\n");

        printf("\n Entre the coordinates of point A(x , y)\n");
        printf(" x = ");
        scanf_s("%lf", &x1);
        printf(" y = ");
        scanf_s("%lf", &y1);

        printf("\n Entre the coordinates of point B(x , y)\n");
        printf(" x = ");
        scanf_s("%lf", &x2);
        printf(" y = ");
        scanf_s("%lf", &y2);

        printf("\n Entre the coordinates of point C(x , y)\n");
        printf(" x = ");
        scanf_s("%lf", &x3);
        printf(" y = ");
        scanf_s("%lf", &y3);

        // finding the lengths of the corresponding sides 
        sideA = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
        sideB = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
        sideC = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

        printf("\n\nEntered information:\n");
        printf("     Coordinates     >>>   A(%.1f , %.1f)  B(%.1f , %.1f)  C(%.1f , %.1f)\n", x1, y1, x2, y2, x3, y3);
        printf("     Vertice Length  >>>    a = %.2f      b = %.2f      c = %.2f\n", sideA, sideB, sideC);

        // calculating the values of the in centre coordinates
        incentreX = (sideA * x1 + sideB * x2 + sideC * x3) / (sideA + sideB + sideC);
        incentreY = (sideA * y1 + sideB * y2 + sideC * y3) / (sideA + sideB + sideC);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
        printf("\n\t Result:                                   ");
        printf("\n\t    InCentre coordinates >>> (%.2f , %.2f) ", incentreX, incentreY);
        printf("\n\t                                           ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
        printf("\n\n Do want to solve again?\n 1 = yes , 0 = No\n >>>> ");
        scanf_s("%d", &restart);
        if (restart == 0)
            break;
    }
}

// function to solve the slope intercept form
void slope_intercept()
{
    int restart;
    while (1)
    {
        system("cls");
        double x1, y1, x2, y2, slope, c;    // c = y-intercept
        printf("\n\t\t\t\t\tSlope Intercept Form\n");

        printf("\n Entre the coordinates of the first point:\n");
        printf(" x = ");
        scanf_s("%lf", &x1);
        printf(" y = ");
        scanf_s("%lf", &y1);

        printf("\n Entre the coordinates of the second point:\n");
        printf(" x = ");
        scanf_s("%lf", &x2);
        printf(" y = ");
        scanf_s("%lf", &y2);

        printf("\n Entered points >>> ( %.1f , %.1f ) and ( %.1f , %.1f )\n", x1, y1, x2, y2);

        // calculating the values of the gradient and y-intercept
        slope = (y2 - y1) / (x2 - x1);
        c = y1 - slope * x1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
        printf("\n\t Results:                          \n");
        printf("\t    Slope = %.2f                   \n", slope);
        printf("\t    y-intercept = %.2f            \n", c);
        if (c != 0)
            printf("\t    Equation >>> y = %.2fx + %.2f ", slope, c);
        else
            printf("\t    Equation >>> y = %.2fx        ", slope);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
        printf("\n\n Do want to solve again?\n 1 = yes , 0 = No\n >>>> ");
        scanf_s("%d", &restart);
        if (restart == 0)
            break;
    }
}

// function to find the properties of a staright starts here
void line_properties()
{
    int restart;
    while (1)
    {
        system("cls");
        double a, b, c, slope, yinter, xinter, origin_dis;
        printf("\n\t\t\t\t\tProperties of a Straight Line\n");

        printf("\n For the line equation in the form ax + by + c = 0");
        printf("\n Entre the values of a, b and c:\n");
        printf(" a = ");
        scanf_s("%lf", &a);
        printf(" b = ");
        scanf_s("%lf", &b);
        printf(" c = ");
        scanf_s("%lf", &c);

        printf("\n Entered equation >>> ");
        lineprint(a, b, c);

        // calculating the values of gradient, x-intercept, y-intercept and the distance from the origin
        slope = -(a / b);
        xinter = -(c / a);
        yinter = -(c / b);
        origin_dis = abs(c) / sqrt(a * a + b * b);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
        printf("\n\t Results:                        \n");
        printf("\t    Slope = %.3f                \n", slope);
        printf("\t    x-intercept = %.2f          \n", xinter);
        printf("\t    y-intercept = %.2f           \n", yinter);
        printf("\t    Distance from origin = %.3f \n", origin_dis);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
        printf("\n\n Do want to solve again?\n 1 = yes , 0 = No\n >>>> ");
        scanf_s("%d", &restart);
        if (restart == 0)
            break;
    }
}

// function to find the position of a point with respect to a line starts here
void pos_of_point()
{
    int restart;
    while (1)
    {
        system("cls");
        printf("\n\t\t\tPosition of a point with respect to a Straight Line\n");
        float x, y, a, b, c, eq_solution, point_loc;
        printf("\n For the coordinates in the form (x , y)\n");
        printf(" Entre the coordinates of the point:\n");
        printf("  x = ");
        scanf_s("%f", &x);
        printf("  y = ");
        scanf_s("%f", &y);

        printf("\n For the line equation in the form ax + by + c = 0");
        printf("\n Entre the values of a, b and c:\n");
        printf("  a = ");
        scanf_s("%f", &a);
        printf("  b = ");
        scanf_s("%f", &b);
        printf("  c = ");
        scanf_s("%f", &c);

        printf("\n Entered Information:\n");
        printf("    Entered point >>> (%.1f , %.1f)\n", x, y);
        printf("    Entered line equation >>> ");
        lineprint(a, b, c);

        // finding the location of the point
        eq_solution = a * x + b * y + c;
        point_loc = b * eq_solution;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
        printf("\n\t Results:                                                                       ");
        if (point_loc > 0)
            printf("\n\t   - The point (%.1f , %.1f) lies above the line                                  ", x, y);
        else if (point_loc < 0)
            printf("\n\t   - The point (%.1f , %.1f) lies below the line                                  ", x, y);
        if (eq_solution * c >= 0)
            printf("\n\t   - The point (%.1f , %.1f) and the origin are on the same side of the line      ", x, y);
        if (eq_solution * c < 0)
            printf("\n\t   - The point (%.1f , %.1f) and the origin are on the opposite sides of the line ", x, y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
        printf("\n\n Do want to solve again?\n 1 = yes , 0 = No\n >>>> ");
        scanf_s("%d", &restart);
        if (restart == 0)
            break;
    }
}

// function to find the point of intersection of two lines start here
void intersection_of_lines()
{
    int restart;
    while (1)
    {
        system("cls");
        printf("\n\t\t\tPoint of intersection of two straight lines\n");
        float a, b, c, p, q, r;

        printf("\n Entre the values of the first equation of the form ax + by + c = 0\n");
        printf("  a = ");
        scanf_s("%f", &a);
        printf("  b = ");
        scanf_s("%f", &b);
        printf("  c = ");
        scanf_s("%f", &c);

        printf("\n Entre the values of the second equation of the form px + qy + r = 0\n");
        printf("  p = ");
        scanf_s("%f", &p);
        printf("  q = ");
        scanf_s("%f", &q);
        printf("  r = ");
        scanf_s("%f", &r);

        printf("\n Entered Information:\n");
        printf("    First line  >>> ");
        lineprint(a, b, c);
        printf("    Second line >>> ");
        lineprint(p, q, r);

        float denominator = a * q - p * b;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
        printf("\n\t Results:                                        \n");
        // checking whether the denominator is zero or not and outputting accordingly
        if (denominator == 0)
        {
            float slope = -(a / b);
            printf("\t   - Both the lines are parallel having slope = %.2f and thus do not intersect", slope);
        }
        else
        {
            float intersectionX = (b * r - q * c) / denominator;
            float intersectionY = (p * c - a * r) / denominator;
            printf("\t   - The point of intersection >>> (%.1f , %.1f) \n", intersectionX, intersectionY);
            printf("\t                                                 "); // just a blank line to make the result box look better
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
        printf("\n\n Do want to solve again?\n 1 = yes , 0 = No\n >>>> ");
        scanf_s("%d", &restart);
        if (restart == 0)
            break;
    }
}

// function to find the shortest distance from a point to a line starts here
void point_line_dis()
{
    int restart;
    while (1)
    {
        system("cls");
        printf("\n\t\t\tShortest Distance of a point to a line\n");
        double a, b, c, x, y, dis;

        printf("\n For the coordinates in the form (x , y)\n");
        printf(" Entre the coordinates of the point:\n");
        printf("  x = ");
        scanf_s("%lf", &x);
        printf("  y = ");
        scanf_s("%lf", &y);

        printf("\n Entre the values of a,b and c for the line having form ax + by + c = 0\n");
        printf("  a = ");
        scanf_s("%lf", &a);
        printf("  b = ");
        scanf_s("%lf", &b);
        printf("  c = ");
        scanf_s("%lf", &c);

        printf("\n Entered Information:\n");
        printf("    Point >>> (%.1f , %.1f)\n", x, y);
        printf("    Line  >>> ");
        lineprint(a, b, c);

        // calculating the distance according to the information entered
        dis = (a * x + b * y + c) / sqrt(a * a + b * b);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
        printf("\n\t Result:                ");
        printf("\n\t    Distance >>> %.3f  ", dis);
        printf("\n\t                        ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
        printf("\n\n Do want to solve again?\n 1 = yes , 0 = No\n >>>> ");
        scanf_s("%d", &restart);
        if (restart == 0)
            break;
    }
}

// function to find the area of a triangular geometric region
void triangle_region_area()
{
    int restart;
    while (1)
    {
        system("cls");
        printf("\n\t\t\tArea of a Triangular Region\n");
        float x1, x2, x3, y1, y2, y3, area;

        printf("Consider\n Points of the triangle   >>>    A(x , y)    B(x , y)    C(x , y)\n");
        printf("\n Entre the coordinates of the first point:\n");
        printf("  x = ");
        scanf_s("%f", &x1);
        printf("  y = ");
        scanf_s("%f", &y1);
        printf(" Entre the coordinates of the second point:\n");
        printf("  x = ");
        scanf_s("%f", &x2);
        printf("  y = ");
        scanf_s("%f", &y2);
        printf(" Entre the coordinates of the third point:\n");
        printf("  x = ");
        scanf_s("%f", &x3);
        printf("  y = ");
        scanf_s("%f", &y3);

        printf("\n Entered Information:\n");
        printf("    Points >>>   A(%.1f , %.1f)   B(%.1f , %.1f)   C(%.1f , %.1f)\n", x1, y1, x2, y2, x3, y3);

        // calculating the area
        area = ((float)abs((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3))) / (float)2;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
        printf("\n\t Result:           ");
        printf("\n\t    Area >>> %.3f ", area);
        printf("\n\t                   ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
        printf("\n\n Do want to solve again?\n 1 = yes , 0 = No\n >>>> ");
        scanf_s("%d", &restart);
        if (restart == 0)
            break;
    }
}

// the help function defining the guidelines on how to use ALGE-BRO
void help()
{
    int restart;
    while (1)
    {
        system("color 70");
        int option;

        system("cls");
        printf("\n HELP MENU:                                                                                  \n");
        printf("                                                                                             ");
        printf("\n  Problem #     Topic                                       Category                         \n");
        printf("                                                                                             \n");
        printf("   1            Roots of Quadratic Equations                Algebra                          \n");
        printf("   2            Simultaneous Equations                      Algebra                          \n");
        printf("   3            Solution of Polynomial Equations            Algebra                          \n");
        printf("   4            Sum and Product of Polynomial Roots         Algebra                          \n");
        printf("   5            Distance between two points                 Analytical Geometery             \n");
        printf("   6            Slope-Intercept from points                 Analytical Geometery             \n");
        printf("   7            Properties of Straight Line                 Analytical Geometery             \n");
        printf("   8            Position of a point with respect to line    Analytical Geometery             \n");
        printf("   9            Point of intersection of two lines          Analytical Geometery             \n");
        printf("   10           Distance of a Point to a line               Analytical Geometery             \n");
        printf("   11           Area of a Triangular Region                 Triangular Geometery             \n");
        printf("   12           Centroid of a Triangle                      Triangular Geometery             \n");
        printf("   13           In Centre of a Triangle                     Triangular Geometery             \n");
        printf("                                                                                             ");

        printf("\n Entre the command # of the topic regarding which you need help\n");
        printf("  >>>> ");
        scanf_s("%d", &option);
        printf("\n __________________________________________________________________________________________________________\n");
        if (option == 1)
        {
            system("cls");
            printf("\n Quadratic Equations:  In algebra, a quadratic equation is any equation that can be rearranged in standard \n form as ax^2+bx+c=0 where x represents an unknown and a, b, and c represent known numbers.\n\n To solve Quadratic Equations on ALGE-BRO follow these steps:\n - Press 1 in the MAIN MENU\n - The Quadratics Equation solver panel will appear\n - Entre the values for a, b and c for the equation ax^2 + bx + c\n - Give a space after every entry and then press entre\n - Your entered equation, nature of the roots and the root values will appear on the screen\n");
            printf("\n A sample output is shown below: \n\n");
            printf(" For the Quadratic equation in the form ax^2 + bx + c\n Write the coefficient values of a, b and c\n  a = 2\n  b = 6\n  c = 3\n\n The entered quadratic equation >>>  2.0x + 6.0y + 3.0 = 0\n\n\t Results:\n\t    The roots are Real and Distinct\n\t    root1 = -0.634\n\t    root2 = -2.366\n");
            printf("\n __________________________________________________________________________________________________________\n");
        }
        else if (option == 2)
        {
            system("cls");
            printf("\n Simultaneous Equations:   In mathematics, a set of simultaneous equations, also known as a system of \n equations or an equation system, is a finite set of equations for which common solutions are sought.\n\n To solve Simultaneous Equations on ALGE-BRO follow these steps:\n - Press 2 in the MAIN MENU\n - The Simultaneous Equation solver panel will appear\n - Entre the coefficient values for both equations and press enter\n - a , b and c are the coefficients of the first equation\n - p , q and r are the coefficients of the second equation\n - Your entered equations, nature of the solution and solution values will appear on the screen\n");
            printf("\n A sample output is shown below: \n\n");
            printf(" Enter the coefficents of the first equation of the form ax + by = c\n a = 2\n b = 4\n c = 1\n Enter the coefficents of the second equation of the form px + qy = r\n p = 6\n q = 7\n r = 12\n\n The entered equations are:\n    2.0x + 4.0y = 1.0\n    6.0x + 7.0y = 12.0\n\n\t Result:\n\t    The solution to the equations is unique\n\t    The value of x = 4.100\n\t    The value of y = -1.800\n\n");
            printf("\n __________________________________________________________________________________________________________\n");
        }
        else if (option == 3)
        {
            system("cls");
            printf("\n Polynomial Equations:  In mathematics, a polynomial is an expression consisting of variables (also called\n indeterminates) and coefficients, that involves only the operations of addition, subtraction,\n multiplication, and non-negative integer exponentiation of variables\n\n To find the solution of Polynomial Equations on ALGE-BRO, follow these steps:\n - Enter 3 in the MAIN MENU\n - The Polynomial Equation Solution panel will appear\n - Entre the degree. Degree is the highest power of x in the polynomial\n - Entre the required coefficients\n - The entered polynomial will appear on the screen\n - Entre the value of x for which you want to solve your entered polynomial and press enter\n - The solution of the entered polynomial for that value of x will appear on the screen\n");
            printf("\n A sample output is shown below: \n\n");
            printf(" Enter the order/degree of the polynomial: 2\n Enter the Coefficient of x^2: 3\n Enter the Coefficient of x^1: 2\n Enter the Coefficient of x^0: 1\n\n The entered polynomial is:\n + 3x^2 + 2x^1 + 1x^0\n\n Enter the value of x: 6\n\n\t Result:\n\t   Sum of the polynomial = 121.00\n");
            printf("\n __________________________________________________________________________________________________________\n");
        }
        else if (option == 4)
        {
            system("cls");
            printf("\n Polynomial Equations:  In mathematics, a polynomial is an expression consisting of variables (also called\n indeterminates) and coefficients, that involves only the operations of addition, subtraction,\n multiplication, and non-negative integer exponentiation of variables\n\n To find the sum and product of the polynomial roots on ALGE-BRO, follow these steps:\n Entre 4 in the MAIN MENU\n - The Sum/Product of Polynomial roots panel will appear\n - Entre the degree. Degree is the highest power of x in the polynomial\n - Enter the required coefficents\n - The entered polynomial along with the sum and product of its roots will appear on the screen\n");
            printf("\n A sample output is shown below: \n\n");
            printf(" Enter the order/degree of the polynomial: 2\n Enter the Coefficient of x^2: 3\n Enter the Coefficient of x^1: 6\n Enter the Coefficient of x^0: 2\n\n The entered polynomial is:\n   + 3x^2 + 6x^1 + 2x^0\n\n\t Results:\n\t   - Sum of the Roots = -2.00\n\t   - Product of the Roots = 0.67\n");
            printf("\n __________________________________________________________________________________________________________\n");
        }
        else if (option == 5)
        {
            system("cls");
            printf("\n To find the shortest distance of two points using ALGE-BRO, follow these steps:\n - Entre 5 in the MAIN MENU\n - The Coordinate distance panel will appear\n - Enter the x and y coordinates of the first point and then the x and y coordinates of the second point\n - After the coordinates, press Enter\n - The distance between the two points will appear on the screen\n");
            printf("\n A sample output is shown below: \n\n");
            printf(" Entre the coordinates of the first point:\n x = 4\n y = 2\n\n Entre the coordinates of the second point:\n x = 3\n y = 9\n\n Entered points >>> ( 4.0 , 2.0 ) and ( 3.0 , 9.0 )\n\n\t Result:\n\t    Distance = 7.071\n");
            printf("\n __________________________________________________________________________________________________________\n");
        }
        else if (option == 6)
        {
            system("cls");
            printf("\n Slope-Intercept Form: A non-vertical line can be defined by its slope m, and its y-intercept c (the y\n coordinate of its intersection with the y-axis). In this case its linear equation can be written\n as y = mx + c\n\n To find the slope, y-intercept and equation from a pair of points, follow these steps:\n - Enter 6 in the MAIN MENU\n - The Slope-Intercept panel will appear\n - Entre the x and y coordinates of both points and hit enter\n - Your entered information containing the points will appear\n  - The value of slope, y-intercept and the equation formed from these points will appear on the screen\n");
            printf("\n A sample output is shown below: \n\n");
            printf(" Entre the coordinates of the first point:\n x = 3\n y = 2\n\n  Entre the coordinates of the second point:\n x = 1\n y = -6\n\n Entered points >>> ( 3.0 , 2.0 ) and ( 1.0 , -6.0 )\n\n\t Results:\n\t    Slope = 4.00\n\t    y-intercept = -10.00\n\t    Equation >>> y = 4.00x + -10.00\n");
            printf("\n __________________________________________________________________________________________________________\n");
        }
        else if (option == 7)
        {
            system("cls");
            printf("\n Properties of a straight line include its slope (gradient), y-intercept, x-interept\n and distance from origin\n\n To find the properties of a straight line using ALGEB-BRO, follow these steps:\n - Entre 7 in the MAIN MENU\n - The Straight Line properties panel will open\n - Entre the values of three coefficients\n - For ax + by + c = 0, a,b and c are the coefficients\n - Now press enter, your entered line will appear on the screen \n - In the results section, the slope, x-intercept, y-intercept and the distance from origin will appear\n");
            printf("\n A sample output is shown below: \n\n");
            printf(" For the line equation in the form ax + by + c = 0\n a = 2\n b = 4\n c = 1\n\n Entered equation >>>  2.0x + 4.0y + 1.0 = 0\n\n\t Results:\n\t    Slope = -0.500\n\t    x-intercept = -0.50\n\t    y-intercept = -0.25\n\t    Distance from origin = 0.224\n");
            printf("\n __________________________________________________________________________________________________________\n");
        }
        else if (option == 8)
        {
            system("cls");
            printf("\n Position of a point with respect to a Straight line means whether the point lies below or above the line\n and is the origin on the same side or not.\n\n To find the position of a point with respect to a staright line on ALGE-BRO, follow these steps:\n - Enter 8 in the MAIN MENU\n - The point line position panel will appear\n - Enter the coordinates of the point\n - Enter the three coefficients of the line\n - For ax + by + c = 0, a,b and c are the coefficients\n - After hitting enter, the your entered information will appear on the screen which would include the\n   point and the line\n - In the result section, the position of the point with respect to the line and in realtionship to\n   origin will be given\n");
            printf("\n A sample output is shown below: \n\n");
            printf(" For the coordinates in the form (x , y)\n Entre the coordinates of the point:\n  x = 2\n  y = 4\n\n For the line equation in the form ax + by + c = 0\n Entre the values of a, b and c:\n  a = 1\n  b = -4\n  c = -21\n\n Entered Information:\n    Entered point >>> (2.0 , 4.0)\n    Entered line equation >>>  1.0x - 4.0y - 21.0 = 0\n\n\t Results:\n\t   - The point (2.0 , 4.0) lies above the line\n\t   - The point (2.0 , 4.0) and the origin are on the same side of the line\n");
            printf("\n __________________________________________________________________________________________________________\n");
        }
        else if (option == 9)
        {
            system("cls");
            printf("\n The point of intersection is where the both lines cut/meet each other\n\n To find the point of intersection on ALGE-BRO, follow these steps:\n - Enter 9 in the MAIN MENU\n - The line intersection panel will open\n - Enter the coefficients of the both lines\n - For ax + by + c = 0, a,b and c are the coefficients\n - For px + qy + r = 0, p,q and r are the coefficients\n - after hitting enter, your entered lines will be displayed\n - In the Result box, the point of intersection will be shown\n");
            printf("\n A sample output is shown below: \n\n");
            printf(" Entre the values of the first equation of the form ax + by + c = 0\n  a = 2\n  b = 5\n  c = 3\n\n Entre the values of the second equation of the form px + qy + r = 0\n  p = 6\n  q = -3\n  r = -1\n\n Entered Information:\n    First line  >>>  2.0x + 5.0y + 3.0 = 0\n    Second line >>>  6.0x - 3.0y - 1.0 = 0\n\n\t Results:\n\t   - The point of intersection >>> (-0.1 , -0.6)\n");
            printf("\n __________________________________________________________________________________________________________\n");
        }
        else if (option == 10)
        {
            system("cls");
            printf("\n To find the shortest distance from a point to a line, follow these steps:\n - Enter 10 in the MAIN MENU\n - Enter the coordinates of the point\n - Enter the three coefficients of the line\n - For the line in the form ax + by + c = 0, a,b and c are the coefficients\n - After hitting enter your entered information which includes the point and line will appear on the screen\n - Under the results heading, the shortest distance will be displayed\n\n");
            printf("\n A sample output is shown below: \n\n");
            printf(" For the coordinates in the form (x , y)\n Entre the coordinates of the point:\n  x = 2\n  y = -4\n\n Entre the values of a,b and c for the line having form ax + by + c = 0\n  a = 2\n  b = -8\n  c = -5\n\n Entered Information:\n    Point >>> (2.0 , -4.0)\n    Line  >>>  2.0x - 8.0y - 5.0 = 0\n\n\t Results:\n\t    Distance >>> 3.759\n");
            printf("\n __________________________________________________________________________________________________________\n");
        }
        else if (option == 11)
        {
            system("cls");
            printf("\n to find the area of a triangular region in geometery, follow these steps:\n - Enter 11 in the MAIN MENU\n - The Triangular region area panel will open\n - For the three points A,B and C, enter their coordinates\n - After pressing enter, you entered information which include the three points will appear\n - The area of the traingular formed by those points will be displayed under the result heading\n");
            printf("\n A sample output is shown below: \n\n");
            printf("Consider\n  Points of the triangle   >>>    A(x , y)    B(x , y)    C(x , y)\n\n Entre the coordinates of the first point:\n  x = 1\n  y = 3\n Entre the coordinates of the second point:\n  x = 4\n  y = 5\n Entre the coordinates of the third point:\n  x = 2\n  y = 1\n\n Entered information:\n    Points >>>   A(1.0 , 3.0)   B(4.0 , 5.0)   C(2.0 , 1.0)\n\n\t Results:\n\t    Area >>> 4.000\n");
            printf("\n __________________________________________________________________________________________________________\n");
        }
        else if (option == 12)
        {
            system("cls");
            printf("\n Centroid of Triangle: The centroid of a triangle is the point of intersection of its medians (the lines\n joining each vertex with the midpoint of the opposite side).\n\n To find the centroid of a triangle using ALGE-BRO, follow these steps:\n - Enter 12 in the MAIN MENU\n - The Triangle centroid panel will open\n - Enter the coordinates of the three points\n - These points are the edges of the triangle\n - After pressing enter, your entered cordinates will be displayed on the screen\n - Under the Results heading, the coordinates of the centroid will be shown\n");
            printf("\n A sample output is shown below: \n\n");
            printf(" For the coordinates in the form (x , y)\n\n Entre the coordinates of first point:\n x = 1\n y = 1\n\n Entre the coordinates of second point:\n x = 3\n x = 2\n\n Entre the coordinates of third point:\n x = 1\n y = 3\n\n Entered coordinates >>> (1.0 , 1.0) , (3.0 , 2.0) and (1.0 , 3.0)\n\n\t Results:\n\t    Centroid of this triangle is (1.67 , 2.00)\n");
            printf("\n __________________________________________________________________________________________________________\n");
        }
        else if (option == 13)
        {
            system("cls");
            printf("\n triangle In Centre: The incenter is one of the triangle's points of concurrency formed by the\n intersection of the triangle's 3 angle bisectors. These three angle bisectors are always concurrent\n and always meet in the triangle's interior\n\n To find the incentre of a triangle using ALGE-BRO, follow these steps:\n - Enter 13 in the MAIN MENU\n - The Triangle In Centre panel will appear\n - entre the coordinates of the three points\n - These three points are the edges of the triangle\n - After pressing enter, your entered points and the corresponding lengths of the vertices will be\n   displayed\n - Under the Results headings, the coordinates of the in centre will be shown\n");
            printf("\n A sample output is shown below: \n\n");
            printf("Consider\n Points of the triangle   >>>    A(x , y)    B(x , y)    C(x , y)\n Coresponding vertices    >>>     a           b           c\n\n Entre the coordinates of point A(x , y)\n x = 1\n y = 1\n\n Entre the coordinates of point B(x , y)\n x = 3\n y = 2\n\n Entre the coordinates of point C(x , y)\n x = 1\n y = 7\n\n\n Entered information:\n     Coordinates  >>>   A(1.0 , 1.0)  B(3.0 , 2.0)  C(1.0 , 7.0)\n     Vertices     >>>    a = 5.39      b = 6.00      c = 2.24\n\n\t Results:\n\t    InCentre coordinates >>> (1.88 , 2.43)\n");
            printf("\n __________________________________________________________________________________________________________\n");
        }

        printf("\n\n Do want help again?\n 1 = yes , 0 = No\n >>>> ");
        scanf_s("%d", &restart);
        if (restart == 0)
            break;
    }
}

// function used to print out the equation of straight line according to the different inputs given
// the three parameters are the coefficients of that line 
void lineprint(float a, float b, float c)
{
    if (a >= 0 && b >= 0 && c >= 0)
        printf(" %.1fx + %.1fy + %.1f = 0\n", a, b, c);
    else if (a < 0 && b >= 0 && c >= 0)
        printf(" -%.1fx + %.1fy + %.1f = 0\n", (float)abs(a), b, c);
    else if (a >= 0 && b < 0 && c >= 0)
        printf(" %.1fx - %.1fy + %.1f = 0\n", a, (float)abs(b), c);
    else if (a >= 0 && b >= 0 && c < 0)
        printf(" %.1fx + %.1fy - %.1f = 0\n", a, b, (float)abs(c));
    else if (a < 0 && b < 0 && c >= 0)
        printf(" -%.1fx - %.1fy + %.1f = 0\n", (float)abs(a), (float)abs(b), c);
    else if (a < 0 && b >= 0 && c < 0)
        printf(" -%.1fx + %.1fy - %.1f = 0\n", (float)abs(a), b, (float)abs(c));
    else if (a >= 0 && b < 0 && c < 0)
        printf(" %.1fx - %.1fy - %.1f = 0\n", a, (float)abs(b), (float)abs(c));
    else if (a < 0 && b < 0 && c < 0)
        printf(" -%.1fx - %.1fy - %.1f = 0\n", (float)abs(a), (float)abs(b), (float)abs(c));
}
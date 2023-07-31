#include <stdio.h>

#define PI 3.14159

int calculate_area_and_volume_of_cylinder(double, double, double *, double *);

int main(void)
{
    double radius = 1;
    double height = 1;

    printf("Enter radius and height in that order: ");
    scanf("%lf %lf", &radius, &height);

    while (radius != 0 && height != 0)
    {
        double total_area = 0;
        double volume = 0;

        if (calculate_area_and_volume_of_cylinder(radius, height, &total_area, &volume) == 1)
        {
            printf("%s%lf%s%lf\n", "The total area of the cylinder is ", total_area, " and the volume is ", volume);
        }
        else
        {
            printf("Invalid input! Enter new values:\n");
        }

        scanf("%lf %lf", &radius, &height);
    }

    return 1;
}

int calculate_area_and_volume_of_cylinder(double radius, double height, double *area, double *volume)
{
    if (radius <= 0 || height <= 0)
    {
        return -1;
    }

    *area = 2 * PI * radius * height + 2 * PI * radius;
    *volume = PI * radius * radius * height;

    return 1;
}

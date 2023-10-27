#include "geometric.h"

#define PI 3.14159265358979323846

double getTriangleArea(const struct Triangle* triangle){
    return (triangle->base * triangle->height) / 2;
}

double getTrianglePerimeter(const struct Triangle* triangle){
    //Assuming it's an equilateral triangle
    return triangle->base * 3;
}

double getRectangleArea(const struct Rectangle* rectangle) {
    return rectangle->longbase * rectangle->shortbase;
}

double getRectanglePerimeter(const struct Rectangle* rectangle) {
    return 2.0 * (rectangle->longbase + rectangle->shortbase);
}

double getCircleArea(const struct Circle* circle) {
    return PI * circle->radius * circle->radius;
}

double getCirclePerimeter(const struct Circle* circle) {
    return 2.0 * PI * circle->radius;
}
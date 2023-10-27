// HEADER FILE
// SHAPES TRIANGLE RECTANGLE CIRCLE


//Triangle
struct Triangle
{
    double base{};
    double height{};
};
double geTriangleArea(const Triangle* triangle);
double geTrianglePerimeter(const Triangle* triangle);

//Rectangle
struct Rectangle{
    double longbase{};
    double shortbase{};
};
double geRectangleArea(const Rectangle* rectangle);
double geRectanglePerimeter(const Rectangle* rectangle);

//Circle
struct Circle {
    double radius{};
};
double geCircleArea(const Circle* circle);
double geCirclePerimeter(const Circle* circle);

from geometric import Triangle, Rectangle, Circle


# Create objects
my_triangle = Triangle(5.0, 4.0)
my_rectangle = Rectangle(3.0, 6.0)
my_circle = Circle(2.0)

# Calculate area and perimeter
triangle_area = my_triangle.get_area()
triangle_perimeter = my_triangle.get_perimeter()

rectangle_area = my_rectangle.get_area()
rectangle_perimeter = my_rectangle.get_perimeter()

circle_area = my_circle.get_area()
circle_perimeter = my_circle.get_perimeter()

print(f"Triangle area: {triangle_area}, perimeter: {triangle_perimeter}")
print(f"Rectangle area: {rectangle_area}, perimeter: {rectangle_perimeter}")
print(f"Circle area: {circle_area}, perimeter: {circle_perimeter}")
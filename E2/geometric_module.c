#include <Python.h>
#include "geometric.h"


// Function to calculate the area of a Triangle
static PyObject* Triangle_get_area(PyObject* self, PyObject* args) {
    struct Triangle* triangle;
    if (!PyArg_ParseTuple(args, "O", &triangle)) {
        return NULL;
    }

    double area = getTriangleArea(triangle);
    return PyFloat_FromDouble(area);
}

// Function to calculate the perimeter of a Triangle
static PyObject* Triangle_get_perimeter(PyObject* self, PyObject* args) {
    struct Triangle* triangle;
    if (!PyArg_ParseTuple(args, "O", &triangle)) {
        return NULL;
    }

    double perimeter = getTrianglePerimeter(triangle);
    return PyFloat_FromDouble(perimeter);
}

// Function to create a new Triangle object
static PyObject* Triangle_new(PyTypeObject* type, PyObject* args, PyObject* kwargs) {
    struct Triangle* self;
    self = (struct Triangle*)type->tp_alloc(type, 0);
    return (PyObject*)self;
}

// Function to initialize a Triangle object
static int Triangle_init(struct Triangle* self, PyObject* args, PyObject* kwargs) {
    double base, height;
    if (!PyArg_ParseTuple(args, "dd", &base, &height)) {
        return -1;
    }

    self->base = base;
    self->height = height;
    return 0;
}

// Function to deallocate memory for a Triangle object
static void Triangle_dealloc(struct Triangle* self) {
    Py_TYPE(self)->tp_free((PyObject*)self);
}

// Define the methods for the Triangle type
static PyMethodDef Triangle_methods[] = {
    {"get_area", Triangle_get_area, METH_VARARGS, "Calculate the area of the triangle."},
    {"get_perimeter", Triangle_get_perimeter, METH_VARARGS, "Calculate the perimeter of the triangle."},
    {NULL, NULL, 0, NULL}
};

// Define the Triangle type
static PyTypeObject TriangleType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "geometric_shapes.Triangle",   // Module and class name
    sizeof(struct Triangle),       // Object size
    0,                            // Flags
    (destructor)Triangle_dealloc, // Deallocator
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    Py_TPFLAGS_DEFAULT,           // Type flags
    "Triangle objects",           // Docstring
    0,                            // Traverse
    0,                            // Clear
    0,                            // Richcompare
    0,                            // Weaklistoffset
    0,                            // Iter
    0,                            // Iternext
    Triangle_methods,             // Methods
    0,                            // Members
    0,                            // Getset
    0,                            // Base
    0,                            // Dict
    0,                            // Description
    0,                            // Number
    0,                            // Internal
    0,                            // Module
    Triangle_new,                 // New
    0,                            // Init
    0,                            // Alloc
    Triangle_init                 // Init with args
};

// Initialize the module
static struct PyModuleDef geometric_shapes_module = {
    PyModuleDef_HEAD_INIT,
    "geometric_shapes",
    "A Python module for geometric shapes.",
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_geometric_shapes(void) {
    PyObject* m;
    if (PyType_Ready(&TriangleType) < 0) {
        return NULL;
    }

    m = PyModule_Create(&geometric_shapes_module);
    if (m == NULL) {
        return NULL;
    }

    Py_INCREF(&TriangleType);
    PyModule_AddObject(m, "Triangle", (PyObject*)&TriangleType);

    return m;
}

// Function to calculate the area of a Rectangle
static PyObject* Rectangle_get_area(PyObject* self, PyObject* args) {
    struct Rectangle* rectangle;
    if (!PyArg_ParseTuple(args, "O", &rectangle)) {
        return NULL;
    }

    double area = getRectangleArea(rectangle);
    return PyFloat_FromDouble(area);
}

// Function to calculate the perimeter of a Rectangle
static PyObject* Rectangle_get_perimeter(PyObject* self, PyObject* args) {
    struct Rectangle* rectangle;
    if (!PyArg_ParseTuple(args, "O", &rectangle)) {
        return NULL;
    }

    double perimeter = getRectanglePerimeter(rectangle);
    return PyFloat_FromDouble(perimeter);
}

// Function to create a new Rectangle object
static PyObject* Rectangle_new(PyTypeObject* type, PyObject* args, PyObject* kwargs) {
    struct Rectangle* self;
    self = (struct Rectangle*)type->tp_alloc(type, 0);
    return (PyObject*)self;
}

// Function to initialize a Rectangle object
static int Rectangle_init(struct Rectangle* self, PyObject* args, PyObject* kwargs) {
    double width, height;
    if (!PyArg_ParseTuple(args, "dd", &width, &height)) {
        return -1;
    }

    self->width = width;
    self->height = height;
    return 0;
}

// Function to deallocate memory for a Rectangle object
static void Rectangle_dealloc(struct Rectangle* self) {
    Py_TYPE(self)->tp_free((PyObject*)self);
}

// Define the methods for the Rectangle type
static PyMethodDef Rectangle_methods[] = {
    {"get_area", Rectangle_get_area, METH_VARARGS, "Calculate the area of the rectangle."},
    {"get_perimeter", Rectangle_get_perimeter, METH_VARARGS, "Calculate the perimeter of the rectangle."},
    {NULL, NULL, 0, NULL}
};

// Define the Rectangle type
static PyTypeObject RectangleType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "geometric_shapes.Rectangle",   // Module and class name
    sizeof(struct Rectangle),       // Object size
    0,                            // Flags
    (destructor)Rectangle_dealloc, // Deallocator
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    Py_TPFLAGS_DEFAULT,           // Type flags
    "Rectangle objects",           // Docstring
    0,                            // Traverse
    0,                            // Clear
    0,                            // Richcompare
    0,                            // Weaklistoffset
    0,                            // Iter
    0,                            // Iternext
    Rectangle_methods,             // Methods
    0,                            // Members
    0,                            // Getset
    0,                            // Base
    0,                            // Dict
    0,                            // Description
    0,                            // Number
    0,                            // Internal
    0,                            // Module
    Rectangle_new,                 // New
    0,                            // Init
    0,                            // Alloc
    Rectangle_init                // Init with args
};

// Function to calculate the area of a Circle
static PyObject* Circle_get_area(PyObject* self, PyObject* args) {
    struct Circle* circle;
    if (!PyArg_ParseTuple(args, "O", &circle)) {
        return NULL;
    }

    double area = getCircleArea(circle);
    return PyFloat_FromDouble(area);
}

// Function to calculate the perimeter of a Circle
static PyObject* Circle_get_perimeter(PyObject* self, PyObject* args) {
    struct Circle* circle;
    if (!PyArg_ParseTuple(args, "O", &circle)) {
        return NULL;
    }

    double perimeter = getCirclePerimeter(circle);
    return PyFloat_FromDouble(perimeter);
}

// Function to create a new Circle object
static PyObject* Circle_new(PyTypeObject* type, PyObject* args, PyObject* kwargs) {
    struct Circle* self;
    self = (struct Circle*)type->tp_alloc(type, 0);
    return (PyObject*)self;
}

// Function to initialize a Circle object
static int Circle_init(struct Circle* self, PyObject* args, PyObject* kwargs) {
    double radius;
    if (!PyArg_ParseTuple(args, "d", &radius)) {
        return -1;
    }

    self->radius = radius;
    return 0;
}

// Function to deallocate memory for a Circle object
static void Circle_dealloc(struct Circle* self) {
    Py_TYPE(self)->tp_free((PyObject*)self);
}

// Define the methods for the Circle type
static PyMethodDef Circle_methods[] = {
    {"get_area", Circle_get_area, METH_VARARGS, "Calculate the area of the circle."},
    {"get_perimeter", Circle_get_perimeter, METH_VARARGS, "Calculate the perimeter of the circle."},
    {NULL, NULL, 0, NULL}
};

// Define the Circle type
static PyTypeObject CircleType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "geometric_shapes.Circle",   // Module and class name
    sizeof(struct Circle),       // Object size
    0,                            // Flags
    (destructor)Circle_dealloc, // Deallocator
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    Py_TPFLAGS_DEFAULT,           // Type flags
    "Circle objects",           // Docstring
    0,                            // Traverse
    0,                            // Clear
    0,                            // Richcompare
    0,                            // Weaklistoffset
    0,                            // Iter
    0,                            // Iternext
    Circle_methods,             // Methods
    0,                            // Members
    0,                            // Getset
    0,                            // Base
    0,                            // Dict
    0,                            // Description
    0,                            // Number
    0,                            // Internal
    0,                            // Module
    Circle_new,                 // New
    0,                            // Init
    0,                            // Alloc
    Circle_init                // Init with args
};

// Initialize the module
static struct PyModuleDef geometric_shapes_module = {
    PyModuleDef_HEAD_INIT,
    "geometric_shapes",
    "A Python module for geometric shapes.",
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_geometric_shapes(void) {
    PyObject* m;
    if (PyType_Ready(&TriangleType) < 0) {
        return NULL;
    }
    if (PyType_Ready(&RectangleType) < 0) {
        return NULL;
    }
    if (PyType_Ready(&CircleType) < 0) {
        return NULL;
    }

    m = PyModule_Create(&geometric_shapes_module);
    if (m == NULL) {
        return NULL;
    }

    Py_INCREF(&TriangleType);
    PyModule_AddObject(m, "Triangle", (PyObject*)&TriangleType);
    Py_INCREF(&RectangleType);
    PyModule_AddObject(m, "Rectangle", (PyObject*)&RectangleType);
    Py_INCREF(&CircleType);
    PyModule_AddObject(m, "Circle", (PyObject*)&CircleType);

    return m;
}
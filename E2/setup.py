
from setuptools import setup, Extension

setup(
    name='geometric',
    version='1.0',
    ext_modules=[
        Extension('geometric', sources=['geometric_module.c', 'geometric.c']),
    ],
)
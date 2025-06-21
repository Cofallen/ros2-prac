from setuptools import find_packages
from setuptools import setup

setup(
    name='chap4_interface',
    version='0.0.0',
    packages=find_packages(
        include=('chap4_interface', 'chap4_interface.*')),
)

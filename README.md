# Dragonfly 5.2

Below it is shown how the programme is structured and how it declares 3D geometric figures.

## Class diagram

![Cuboid in 3D](/readme_pics/class_diagram.png)

To see more indepth diagrams and documentation go to /documentation dir.

## Cuboid

This is how (default) cuboid looks like in the project: (made using [Geogebra](https://www.geogebra.org/3d?lang=pl))

![Cuboid in 3D](/readme_pics/cuboid3D.png)

## Prism

This is how (default) prism looks like in the project: (made using [Geogebra](https://www.geogebra.org/3d?lang=pl))

![Prism in 3D](/readme_pics/prism3D.png)

## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Example:

``` bash
> mkdir build && cd build
> cmake .. -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release]
> make
> ./main         # Runs program
> make test      # Makes and runs the tests.
> make coverage  # Generate a coverage report.
> make doc       # Generate html documentation.
```

## Running
Program does everything that the task obliged it to do. It is fully functional, has the modification implemented (see in menu), everything is tested and seems to work fine.

## Documentation
To see documentation go to /documentation dir and search for index.html. You can generate your own documentation in doxygen using:
```
make doc
```
in the build dir.

## Tests

Tests are made using doctests.
There are two different ways to initiate tests:
``` bash
> cmake .. -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release]
> make
> ./unit_tests
```
OR:
``` bash
> cmake .. -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release]
> make fulltest
```

Results of tests on my local machine: (using *./unit_tests*)
```
===============================================================================
[doctest] test cases: 292 | 292 passed | 0 failed | 0 skipped
[doctest] assertions: 695 | 695 passed | 0 failed |
[doctest] Status: SUCCESS!
```
There are tests included for counting Vectors, class inheritence, all algebraic operations on vectors and matrices,
cuboid and prism contruction assertion and more.

**Important note:** there are problems while using *make fulltest* command. Tests that write data to *.dat* files will be shown as failed while using this command.
In case *./unit_tests* is used, all tests have success status. The problematic tests have also been done manually and everything seems to work good.

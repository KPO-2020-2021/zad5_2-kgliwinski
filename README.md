# Dragonfly 5.2

Below it is shown how the programme is structured and how it declares 3D geometric figures.

## Class diagram

![Class diagram](/readme_pics/class_diagram.png)

To see more indepth diagrams and documentation go to /documentation dir.

## Cuboid

This is how (default) cuboid looks like in the project: (made using [Geogebra](https://www.geogebra.org/3d?lang=pl))

![Cuboid in 3D](/readme_pics/cuboid3D.png)

## Prism

This is how (default) prism looks like in the project: (made using [Geogebra](https://www.geogebra.org/3d?lang=pl))

![Prism in 3D](/readme_pics/prism3D.png)

## Deformations of Cuboid and Prism

Scene objects included deformated Cuboid and Prism objects such as: Tent, Circus, Triangular and more.
Their construction is breifly explained in the class header files and in documentation. These objects are simple enough for me not to include their full declarations in 3D space.

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
[doctest] test cases: 383 | 383 passed | 0 failed | 0 skipped
[doctest] assertions: 870 | 870 passed | 0 failed |
[doctest] Status: SUCCESS!

```
There are tests included for counting Vectors, class inheritence, all algebraic operations on vectors and matrices,
cuboid and prism contruction assertion and more.

**Important note:** there are problems while using *make fulltest* command. Tests that write data to *.dat* files will be shown as failed while using this command.
In case *./unit_tests* is used, all tests have success status. The problematic tests have also been done manually and everything seems to work good.

## datasets directory
It is important for the program to work that there is a datasets directory (that also includes main dircetory which contains final and sample dirs) for the file to operate. Here is a simple diagram:
```
|----zad5_2-kgliwinski
|    |----datasets
|         |----main
|              |---final
|              |---sample
```

# Informacje w kontek??cie zadania dron 5.2
Zawarte informacje o zrealizowanych rozszerzeniach i og??lnej funkcjonalno??ci programu w kontek??cie zadania projektowego.

## Program realizuje r??wnie?? podstawowe za??o??enia zadania
         1. Drony oraz elementy powierzchni znajduj?? si?? na liscie std::list przy uzyciu std::shared_ptr
         2. Elementy powierzchni tworzone sa na liscie poprzez niejawne rzutowanie w gore
         3. Mozna dodawac i usuwac elementy powierzchni, program uruchamia sie z paroma podstawowymi elementami
         4. Program zachowa?? funkcjonalno??ci z fazy 1
         5. Dla ka??dego elementu powierzchni zdefiniowano osobne klasy

## Zrealizowane rozszerzenia
         1. Zadaj??c po??o??enie elementu mo??na r??wnie?? zmieni?? jego orientacj?? wok???? osi OZ o zadany k??t.
         2. Elementy powierzchni mog?? by?? r??wnie?? deformowanym graniastos??upem.
         3. Zmiana po??o??enia element??w powierzchni

## Komentarze
         1. Jak wida??, po usuni??ciu elementu powierzchni zmniejsza si?? ilo???? aktualnych obiekt??w Vector3D
         2. Analogicznie, po dodaniu ilo??c ta si?? zwi??ksza
         3. Drony s?? przechowywane jako wska??niki na li??cie obiekt??w w klasie scena, mimo ??e one same s?? zaimplementowane w dwuwymiarowej tablicy.

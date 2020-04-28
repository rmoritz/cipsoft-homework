This is my submission for a homework assignment set by Cipsoft. The assignment
is described in German in [Hausaufgabe-Programmierer.pdf](Hausaufgabe-Programmierer.pdf).

The solution is coded in modern C++, and consists of a console application,
[src/driver.cc](src/driver.cc), and logic module [src/minmax.cc](src/minmax.cc).
The problem itself is solved by the function `getMinMaxPartition` (see [include/minmax.hh](include/minmax.hh)).

Building
========

Prerequisites
-------------

The code has no external dependencies and should be buildable with any compiler
that supports C++11 or newer. I am using Clang 10.0 with GNU Make on Linux.

Build all the things
--------------------

To build the code, generate API docs (Doxygen), and run unit tests, just type:

```
make
```

This will create a new sub-directory called `build` containing:

```
build
├── docs
│   ├── html
│   │   ├── index.html
│   │   └── ...
│   └── latex
│       ├── ...
├── solver
└── tests
```

- `docs` - API documentation for the `getMinMaxPartition` function.
           *N.B. This will only be generated if `doxygen` was found in your path.*
- `solver` - Console application that reads input from stdin, calls the
             `getMinMaxPartition` function, and writes the results to stdout.
- `tests` - Console test runner. Executes unit tests and writes summary
            to stdout.

Running
=======

There are several example input files in the `data` subdirectory. These can be
fed to the solver via stdin. Here an example under Linux:

```
$ ./build/solver < data/input1
1. Tag: 11 km
2. Tag: 26 km
3. Tag: 22 km

Maximum: 26 km
```

____

Ralph Moeritz

Regensburg, 28.04.2020


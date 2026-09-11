*This project has been created as part of the 42 curriculum by ymoumene.*

# C++ Modules

## Description

C++ Modules is a collection of 38 exercises completed as part of the 42 curriculum. The project introduces object-oriented programming in C++ through ten progressive modules, from basic classes and memory management to templates, containers and algorithms.

Every exercise is an independent program with its own `Makefile`. The entire project targets the C++98 standard and is compiled with strict warning flags.

## Features

- Classes, encapsulation and member functions.
- Stack and heap memory management.
- Pointers, references and function pointers.
- Orthodox Canonical Form and operator overloading.
- Inheritance, multiple inheritance and polymorphism.
- Abstract classes and interfaces.
- Exception handling and custom exceptions.
- C++ type casts and runtime type identification.
- Function and class templates.
- STL containers, iterators and algorithms.
- Parsing, validation and error handling.
- Algorithm implementation and performance comparison.

## Module overview

| Module | Main topics | Exercises |
| --- | --- | --- |
| [CPP00](./CPP00) | Namespaces, classes, member functions, streams, initialization lists, `static` and `const` | Megaphone, PhoneBook, Account |
| [CPP01](./CPP01) | Memory allocation, pointers, references, function pointers and files | Zombie, ZombieHorde, Brain, Weapon, Replace, Harl, HarlFilter |
| [CPP02](./CPP02) | Orthodox Canonical Form, fixed-point numbers and operator overloading | Fixed, BSP |
| [CPP03](./CPP03) | Inheritance and multiple inheritance | ClapTrap, ScavTrap, FragTrap, DiamondTrap |
| [CPP04](./CPP04) | Subtype polymorphism, deep copies, abstract classes and interfaces | Animal, Brain, AAnimal, Materia |
| [CPP05](./CPP05) | Exceptions, grades, forms and object factories | Bureaucrat, Form, AForm, Intern |
| [CPP06](./CPP06) | C++ type conversion and dynamic type identification | ScalarConverter, Serializer, Base |
| [CPP07](./CPP07) | Function templates and class templates | Whatever, Iter, Array |
| [CPP08](./CPP08) | Templated containers, iterators and algorithms | EasyFind, Span, MutantStack |
| [CPP09](./CPP09) | STL containers and algorithmic problem-solving | Bitcoin Exchange, RPN, PmergeMe |

## Requirements

- A Unix-like environment such as Linux, macOS or WSL.
- A C++ compiler available as `c++`.
- `make`.
- `git` to clone the repository.

Each Makefile compiles its exercise with the following flags:

```sh
-Wall -Wextra -Werror -std=c++98
```

## Instructions

### Installation

```sh
git clone git@github.com:Zoryan7/Module-CPP-42.git
cd Module-CPP-42
```

### Compilation

Move into the exercise you want to build and run `make`:

```sh
cd CPP03/ex03
make
```

Useful Makefile targets are:

```sh
make clean   # Remove object files
make fclean  # Remove object files and the executable
make re      # Clean and rebuild
```

An exercise can also be compiled from the repository root:

```sh
make -C CPP06/ex00
```

### Execution

Run the executable generated in the selected exercise directory. For example:

```sh
./CPP06/ex00/convert 42.0f
```

The executable name is defined by the `NAME` variable in each exercise's `Makefile`.

## Usage examples

### Megaphone

```sh
make -C CPP00/ex00
./CPP00/ex00/megaphone "Hello, 42!"
```

### PhoneBook

```sh
make -C CPP00/ex01
./CPP00/ex01/Phonebook
```

The application accepts the interactive commands `ADD`, `SEARCH` and `EXIT`.

### File replacement

```sh
make -C CPP01/ex04
./CPP01/ex04/replace input.txt old_string new_string
```

The program creates `input.txt.replace` without modifying the original file.

### Scalar Converter

```sh
make -C CPP06/ex00
./CPP06/ex00/convert 42.0f
```

### Reverse Polish Notation

```sh
make -C CPP09/ex01
./CPP09/ex01/RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

### PmergeMe

```sh
make -C CPP09/ex02
./CPP09/ex02/PmergeMe 3 5 9 7 4
```

### Bitcoin Exchange

`CPP09/ex00` expects a `data.csv` exchange-rate database in its working directory. This file is supplied with the exercise subject and is not included in this repository.

Once the database and an input file are available:

```sh
cd CPP09/ex00
make
./btc input.txt
```

The input file uses the following format:

```text
date | value
2011-01-03 | 3
2012-01-11 | 1.5
```

## Testing

Each exercise contains a `main` program with test cases for its required behavior. Build and run exercises independently so their output can be checked against the corresponding subject.

For exercises that accept command-line arguments, test valid input as well as malformed values and incorrect argument counts. Example cases include:

```sh
# Scalar conversion
./CPP06/ex00/convert 0
./CPP06/ex00/convert nan
./CPP06/ex00/convert +inff

# RPN validation
./CPP09/ex01/RPN "8 9 * 2 /"
./CPP09/ex01/RPN "1 2 + +"

# PmergeMe validation and timing
./CPP09/ex02/PmergeMe 3 5 9 7 4
./CPP09/ex02/PmergeMe 3 -1 5
```

## Technical choices

- **C++98:** all solutions stay within the language version required by the curriculum and avoid features introduced in later standards.
- **One exercise, one build:** every exercise has its own sources, headers, entry point and Makefile so that it can be evaluated independently.
- **Orthodox Canonical Form:** copy constructors, copy-assignment operators and destructors are implemented where required to make object lifetime and copy semantics explicit.
- **Standard containers:** the later modules select containers according to the problem being solved, including `vector`, `deque`, `list`, `map` and `stack`.
- **Strict compilation:** warnings are treated as errors to expose unsafe conversions, unused code and other potential defects early.

## Project structure

```text
.
├── CPP00
│   ├── ex00
│   ├── ex01
│   └── ex02
├── CPP01
│   └── ...
├── CPP02
├── CPP03
├── CPP04
├── CPP05
├── CPP06
├── CPP07
├── CPP08
├── CPP09
│   ├── ex00
│   ├── ex01
│   └── ex02
└── README.md
```

Most exercises use the following internal layout:

```text
exXX/
├── includes/   # Header files
├── srcs/       # Source files
└── Makefile
```

- `CPP00/` and `CPP01/`: C++ syntax, classes, memory and references.
- `CPP02/` and `CPP03/`: canonical classes, operators and inheritance.
- `CPP04/` and `CPP05/`: polymorphism, interfaces and exceptions.
- `CPP06/` and `CPP07/`: casts and templates.
- `CPP08/` and `CPP09/`: STL containers and algorithms.

## Resources

- [C++ language reference](https://en.cppreference.com/w/cpp/language): classes, inheritance, templates and exceptions.
- [C++ standard library containers](https://en.cppreference.com/w/cpp/container): container properties and interfaces.
- [C++ standard library algorithms](https://en.cppreference.com/w/cpp/algorithm): generic algorithms and iterator requirements.
- [CPlusPlus.com tutorial](https://cplusplus.com/doc/tutorial/): introductory explanations and examples.

### Use of artificial intelligence

Artificial intelligence was used as a support tool to review and improve the project documentation.

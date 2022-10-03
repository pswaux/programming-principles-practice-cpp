# Programming: Principles and Practice Using C++

<p align="center">
   <img src="https://user-images.githubusercontent.com/24891489/193471428-0dc1e7dc-3229-4b57-87ce-fc1d2cdde06f.jpg" />
</p>

This repository contains my own solutions to programming exercises (not try this and drills).\
I created this repository just for self-study and fun. I didn't graduate from any computer or related fields.\
I'm not even a professional programmer.

My system is 64-bit Fedora-35 running GCC 11.3.1. I used Vim as an editor and CLI to compile programs.

## Some compiler commands
```bash
  $ g++ foo.c -o foo
  $ g++ -std=c++14 foo.c -o foo  // compile with specific language standard
  $ g++ -Wall -g foo.c -o foo    // all warnings enabled and debug information generated
  $ g++ src/foo.c -o bin/foo     // separate source codes and binaries
```

Also I've added a Makefile into each chapter.
## Usage
```bash
  $ make             // builds all files
  $ make p8_01 p8_04 // builds file(s) individually
  $ make clean       // cleans all executables
  
  Default build mode is release (with DNDEBUG flag). Debug mode can be activated by either 
  modifying the Makefile or calling the make with the mode option;
  
  $ make mode=debug            // builds all files with -g flag
  $ make mode=debug ex5_05     // builds file(s) individually
```

## Table of Contents
* Chapter 0 - Notes to the Reader
* Chapter 1 - Computers, People, and Programming
* Chapter 2 - Hello, World!
* Chapter 3 - Objects, Types, and Values
* Chapter 4 - Computation
* Chapter 5 - Errors
* Chapter 6 - Writing a Program
* Chapter 7 - Completing a Program
* Chapter 8 - Technicalities: Functions, etc.
* Chapter 9 - Technicalities: Classes, etc.
* Chapter 10 - Input and Output Streams
* Chapter 11 - Customizing Input and Output
* Chapter 12 - A Display Model
* Chapter 13 - Graphics Classes
* Chapter 14 - Graphics Class Design
* Chapter 15 - Graphing Functions and Data
* Chapter 16 - Graphical User Interfaces
* Chapter 17 - Vector and Free Store
* Chapter 18 - Vectors and Arrays
* Chapter 19 - Vector, Templates, and Exceptions
* Chapter 20 - Containers and Iterators
* Chapter 21 - Algorithms and Maps
* Chapter 22 - Ideals and History
* Chapter 23 - Text Manipulation
* Chapter 24 - Numerics
* Chapter 25 - Embedded Systems Programming
* Chapter 26 - Testing
* Chapter 27 - The C Programming Language

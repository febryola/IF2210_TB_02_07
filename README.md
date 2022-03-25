# Mojang!

## Description
This program implements the crafting system of Minecraft in C++ with object-oriented programming.

## Requirement
Make sure you are using Linux with C++17. WSL also works if you are using Windows.  
To install the requirements:
```
sudo apt-get install make g++
make all
```

## Running the Program
To run the program:
```
make compile && ./main
```
To run automated tests:
```
make all
```

## Automated Tests
This program accepts automated tests taken from the `tests` folder. Tests consists of two files, input with "in" extension and answer with "ans" extension. Each test should have exactly one EXPORT command which exports the current inventory into an "out" file in the tests folder. Please refer to the sample tests. Checking will be done by comparing the answer file and the output file.
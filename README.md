# Mojang!

> _This program is created to fullfil an assignment of the course `Object-Oriented Programming (IF2210)`_ <br/>
>
> _Program Studi Teknik Informatika <br/>
> Sekolah Teknik Elektro dan Informatika <br/>
> Institut Teknologi Bandung <br/>
> Semester II Tahun 2021/2022 <br/>_

## Table of Content
* [Description](#Description)
* [Requirements](#Requirements)
* [Running the Program](#Running-the-Program)
* [Automated Tests](#Automated-Tests)
* [Project Status](#Project-Status)
* [Authors](#Authors)

## Description
This program implements the crafting system of Minecraft in C++ with object-oriented programming.

## Requirements
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

## Project Status
> **Project is: _complete_**

## Authors
<table>
    <tr>
      <td><a href="https://github.com/chryes220"><b>Christine Hutabarat</b></a></td>
      <td><b>13520005</b></td>
    </tr>
    <tr>
      <td><a href="https://github.com/FelineJTD"><b>Felicia Sutandijo</b></a></td>
      <td><b>13520050</b></td>
    </tr>
    <tr>
      <td><a href="https://github.com/sivaren"><b>Rava Naufal Attar</b></a></td>
      <td><b>13520077</b></td>
    </tr>
    <tr>
      <td><a href="https://github.com/febryola"><b>Febryola Kurnia Putri</b></a></td>
      <td><b>13520140</b></td>
    </tr>
    <tr>
      <td><a href="https://github.com/hcarissa"><b>Hilda Carissa Widelia</b></a></td>
      <td><b>13520164</b></td>
    </tr>
</table>
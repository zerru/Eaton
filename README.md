# Eaton
Test for Eaton Prague (C language)

## Introduction

The test requirements were quite open, and as it didn´t come to my mind any specific easy utility, I decided to mix the requirements of another test I made almost one year ago for another company. This old test is also in GitHub and it is my unique experience with Java (without taking into account my experience with Android Studio):
[Go to the Old Test](https://github.com/zerru/rovers/).


## Functionality description (based on the previous test)

There are unknown number of robotic rovers on a plateau on Mars. This plateau, which is curiously rectangular, is divided up into a grid to simplify navigation. The plateau must be navigated by the rovers so that their on-board measurement machine can get the main element (symbolised with 4 letters) and the percentage of the element´s purity (% between 1 and 100). A rover’s position is represented by a combination of x and y coordinates, and each rover has its own number (from 01 to 99). For example, a message from the rover 03, which is in the position [2, 2] and has measured "GOLD" with a purity of 95% should be like this:

**R03 2 2 GOLD 95**

We can get the information of each grid, we must write "GET" followed by the coordenates, for example:

**GET 2 2**

We will receive the element and the purity of this grid, and we will receive also the number of measurements made by any rover.

If we receive 2 measurents of the same grid [x, y] with different elements, the information of this grid won´t be valid, it will be in error forever. We will calculate the average of the purity with the measurements done.


## Example

R03 2 2 GOLD 80

GET 2 2

**Expected Output: GOLD 80%**

R43 2 2 GOLD 20

GET 2 2 

**Expected Output: GOLD 50%**

R01 2 2 SILV 50

GET 2 2

**Expected Output: Result: Error**


## How to run

Run Eaton_dev.exe, which is inside "Default" folder. 

*Note: This .exe file has to have always the libgcc_s_dw2-1.dll file in the same folder.


## TODO & imprevements


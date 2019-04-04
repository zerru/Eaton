# Eaton
Test for Eaton Prague (C language)

## Introduction

The test requirements were quite open, and as it didn´t come to my mind any specific easy utility, I decided to mix the requirements of another test I made almost one year ago for another company. This old test is also in GitHub and it is my unique experience with Java (without taking into account my experience with Android Studio):
[Go to the Old Test](https://github.com/zerru/rovers/).


## Functionality description (based on the previous test)

There are unknown number of robotic rovers on a plateau on Mars. This plateau, which is curiously rectangular, is divided up into a grid to simplify navigation. We have to add the plateau coordenates, for example:

**3, 4**

The plateau must be navigated by the rovers so that their on-board measurement machine can get the main element (symbolised with 4 letters) and the percentage of the element´s purity (% between 1 and 100). A rover’s position is represented by a combination of x and y coordinates, and each rover has its own number (from 01 to 99). For example, a message from the rover 03, which is in the position [2, 2] and has measured "GOLD" with a purity of 95% should be like this:

**R03 2 2 GOLD 95**

We can get the information of each grid, we must write "GET" followed by the coordenates, for example:

**GET 2 2**

We will receive the element and the purity of this grid, and we will receive also the number of measurements made by any rover.

If we receive 2 measurents of the same grid [x, y] with different elements, the information of this grid won´t be valid, it will be in error forever. We will calculate the average of the purity with the measurements done.


## Example

5, 5 (separated by a comma)

R03 2 2 GOLD 80 (separated by spaces)

GET 2 2 (separated by spaces)

**Expected Output: GOLD 80%**

R43 2 2 GOLD 20

GET 2 2 

**Expected Output: GOLD 50%**

R01 2 2 SILV 50

GET 2 2

**Expected Output: Error**


## How to run

Run Eaton_dev.exe, which is inside "Default" folder. 

*Note: This .exe file has to have always the libgcc_s_dw2-1.dll file in the same folder.


## Possible TODO-s & improvements

- If the different messages could arrive very fast and simultaneously, it would be interesting to implement a stack.
- In order to process messages faster from the same rover, it would be interesting to receive multiple measurements in the same message using movement commands: R01 1 1 GOLD 95 **L SILV 90**, so the element SILV with 90% of purity was measured in the position 0 1, which is the left (L command) grid of the previous.
- As we would know where there are all the rovers, we could know if could be a crash between 2 of them and manage it. In the old project I was detecting the crashes.
- If the same grid is measured with different elements, it will be in error forever. I should be any way to delete the error, for example it could show the one has higher purity.
- In the struct we could save in a array the rovers that have made the measurements in each grid. Like that we could check if one rover has its measument machine broken.
- It would be interesting to check the last purity measurement with the previous measurements, and go to error if the different is too high.


#Thank you!!

Asier Lejarza

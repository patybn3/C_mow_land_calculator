//
//  main.c
//  assignment3_2_patriciaantlitz
//
//  Created by Patricia Antlitz on 2/10/21.

/*---------------------------------------------------------------------*/
     /* Student Name: Patricia Antlitz                                 */
     /* Submission Date: Feb 10, 2021                                  */
     /* Program 2: Write a program that takes the length and width     */
     /*   of a rectangular yard and the length and width of a          */
     /*   rectangular house situated in the yard. Your program should  */
     /*   compute the time required to cut the grass at the rate of two*/
     /*   square feet a second.                                        */
 
 /*
 *
 * Week #: 2
 * Problem #: 2
 * Filename: assignment3_2_patriciaantlitz.c
 *
 * Notes:
 *        -  This program works when compiled and ran on the CLI or when
            compiled by a IDE
          -  This program was developed using other sources:
  https://www.calcunation.com/calculators/miscellaneous/lawn-time-requirement.php?width=42&speed=2&area=1000&eff=80&calc=yes&Calculate=Calculate+Time+Required
 
 * Sample Output:
    
  Grass Cut Calculator

  This program will calculate the time spent to cut the grass of a rectangular or square piece of land

  Please enter the length of the land in feet:
  400
  Please enter the width of the land in feet:
  200
  Please enter the length of the house, if any, in feet:
  0
  Please enter the width of the house, if any, in feet:
  0
  What is the width of your mower blade in inches?
  42
  It would take you H:3:58:5, or 14285.71 seconds to mow.
  Program ended with exit code: 0
     
 *
 */
/*-----------------------------------------------------------------------*/

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    //variables lemgthRec and widthRec will store the lenght and width in feet of the land
    double lengthRec, widthRec;
    //variables houseLen and houseWid will store the lenght and width in feet of a house in the land, if any
    double houseLen, houseWid;
    /* Variables areaHouse and areaLand will store the values assigned to the area of the land, the area
     of the house. Variable areaTotal will store the difference between the values of areaLand and aresHouse */
    double areaHouse, areaLand, areaTotal;
    //variable blade will store the size of the mower blade in inches
    double blade;
    //variable sqfSec stores the speed per second in sqf
    double sqfSec = 2.0;
    //variable averageEfficiency sets the average percentage of how efficient mowers are
    double averageEfficiency = 0.8;
    
    //secInHr get secs in a hour
    int secInHr = 60 * 60;
    //second in a minute
    int secInMin = 60;
    //variable hour, min and secs will store time
    int hour, min, secs;
    //variables timeToCut and time will hold the calculation for cutting the grass
    double timeToCut, time;
    
    //the first and sencond print outs explains to the use what the program does
    printf("Grass Cut Calculator\n\n");
    printf("This program will calculate the time spent to cut the grass of a rectangular or square plot of land\n\n");
    //asks the user to enter the length of the land
    printf("Please enter the length of the land in feet:\n");
    //gets user input
    scanf("%lf", &lengthRec);
    //asks the user to enter the width of the land
    printf("Please enter the width of the land in feet:\n");
    //gets user input
    scanf("%lf", &widthRec);
    //if the land has a house, takes the input of the length and of the width of the house
    printf("Please enter the length of the house, if any, in feet:\n");
    scanf("%lf", &houseLen);
    printf("Please enter the width of the house, if any, in feet:\n");
    scanf("%lf", &houseWid);
    //asks the user for the width of the mowers blade
    printf("What is the width of your mower blade in inches?\n");
    scanf("%lf", &blade);
    
    //calls variable areaLand and assign the product of legthRec and widthRec entered by the user ex. 100 x 200 = 20,000
    areaLand = lengthRec * widthRec;
    
    //calls areaHouse and assifn the product of houseLen and houseWid entered by the user ex. 50 x 20 = 1000
    areaHouse = houseLen * houseWid;
    
    //calls areaTotal and assigns the difference of areaLand and areaHouse ex. 20,000 - 1000 = 19,000
    areaTotal = areaLand - areaHouse;
    
    //calls variable blade and takes the value entered by the user and divides it by 12 to convert it from inches to feet ex. 42 / 12 =  3.5
    blade = blade / 12;
    
    /* calls variable timeToCut and assign the value of variable blade when multiplied by the average mower
     efficiency and the speed in sq feet, then divide the total by the value assigned to variable areaTotal
     ex 19,000 / (3.5 * 0.8 * 2.0 ) = 3392.86 */
    timeToCut = areaTotal / (blade * averageEfficiency * sqfSec);
    
    //calls variable hour and assign the value of variable timeToCut when divided by the seconds in a hour, ex. 3392.86 / 3600 = 0.95
    hour = timeToCut / secInHr;
    
    //calls variable time and assigns the product of variable hour by variable secInhr and subtracts it by variable timeToCut, ex. 3392.86 - (0.95 * 3600) = -27.14
    time = timeToCut - (hour * secInHr);
    
    //calls variable min and assigns the value of variable time when divided by secInMin ex. 3392.86 - (-26.14 / 60) = 3393.31
    min = time / secInMin;
    
    //assigns the value of time minus the product of min when multiplied by secInMin ex. -27.14 - (3393.31 * 60) = -203625.74
    time = time - (min * secInMin);
    //adds calculation to variable sec
    secs = time;
    
    //prints the total
    printf("It would take you H:%d:%d:%dsec, or %.2lf seconds to mow.\n\n", hour, min, secs, timeToCut);
    
    //if successful, returns status 0
    return 0;
}
//end.

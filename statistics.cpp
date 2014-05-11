/*//////////////////////////////////////////////////////////////
//Program: statistics.cpp
//Author: Robert Payne
//Lab section: L15
//Date: 4/07/1512
//Purpose:  The user inputs 15 values into an array. The program
//          Then takes those values, and calculates arithmetic
//          mean and standard deviation. The program also
//          does a selection sort on the array and organizes
//          the data from lowest to highest. After that,
//          the program outputs the min, max, range, median
//          mean and standard deviation of the array.
//
///////////////////////////////////////////////////////////////*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float dataInput[15];//data input by the user
    float tempData;     //for the selection sort
    float aMeanData=0;  //used to calculate the arithmetic mean
    float stdData=0;    //standard deviation
    int i;              //iterator

    //user inputs the 15 values to fill the array
    for(i = 0; i < 15; i++)
    {
        cout<<"Input a value for data #"<<i+1<<": ";
        cin>>dataInput[i];
    }

    //Calculating the arithmetic mean
    for(i= 0; i < 15; i++)
    {
        aMeanData += dataInput[i];
    }
    aMeanData /= 15;

    //Calculating Standard Deviation
    for(i= 0; i < 15; i++)
    {
        stdData += pow((dataInput[i] - aMeanData),2);
    }
    stdData = sqrt((stdData/15));

    //selection sort; makes the min max and range code much easier
    for(i= 0; i < 15; i++)
    {
        for(int a = 0; a < 15; a++)
        {
            if(dataInput[i] < dataInput[a])
            {
                tempData = dataInput[i];
                dataInput[i] = dataInput[a];
                dataInput[a] = tempData;
            }
        }
    }

    //outputs the min, max, range, mean, median and standard deviation
    cout<<"=======================================================\n";
    cout<<"|\n";
    cout<<"|\tMin:\t"<<dataInput[0]<<endl;
    cout<<"|\tMax:\t"<<dataInput[14]<<endl;
    cout<<"|\tRange:\t"<<dataInput[14] - dataInput[0]<<endl;
    cout<<"|\tMean:\t"<<aMeanData<<endl;
    cout<<"|\tMedian:\t"<<dataInput[7]<<endl;
    cout<<"|\n";
    cout<<"|\tStandard deviation from mean:\t"<<stdData<<endl;
    cout<<"|\n";
    cout<<"|\n";
    cout<<"=======================================================\n";

    return 0;
}

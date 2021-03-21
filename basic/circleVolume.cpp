/*
    Tính thể tích hình tròn theo công thức: V = (4*pi*R^3)/3 và S = 4*pi*R^2 với pi = 3.14
*/

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

const double pi = 3.14;

float circleVolume(float R)
{
    return 4 * pi * pow(R, 3) / 3;
}


int main()
{
    float R;
    cout << "\nBan kinh: R = ";
    cin >> R;
    float v = circleVolume(R);
    printf("The tich hinh tron: V = %.2f", v);

    return 0;
}
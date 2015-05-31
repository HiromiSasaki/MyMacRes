//
//  main.cpp
//  test
//
//  Created by 佐々木博弥 on 2015/04/18.
//  Copyright (c) 2015年 hrio. All rights reserved.
//


#include <iostream>
#include <math.h>
#include <fstream>
#include <random>

#define e 0.1
#define xn 1.5
#define yn -2.0

using namespace std;

int main()
{
    ofstream ofs("/Users/hiromi/Desktop/Circle2.txt");
    
    for(int i = 0; i < 1000; )
    {
        double x;
        mt19937_64 mt1(rand());
        x = (double)rand();
        x /= RAND_MAX;//正規化
        x = fmod(x,e*2) - e;
        
        double y;
        mt19937_64 mt2(rand());
        y= (double)rand();
        y /= RAND_MAX;//正規化
        y = fmod(y,e*2) - e;
        
        if(x*x + y*y < e*e)
        {
            i++;
            ofs << x << ' ' << y << endl;
        }
        
    }
    
    
    
    
    return 0;
}


//曲座標を用いた円内乱数プロット
//int main()
//{
//    double x,y;
//    
//    ofstream ofs("/Users/hiromi/Desktop/Circle.txt");
//    
//    for(int i = 0; i < 1000; i++)
//    {
//        double xx,r,angle;
//        random_device rnd;
//        mt19937_64 mt(rand());
//        //mt19937 mt((int)time());
//        xx = (double)rand();
//        xx /= RAND_MAX;
//        
//        r = fmod(sqrt(2*xx),e);
//        angle = xx * 2 * 3.141592;
//        
//        x = r*cos(angle);
//        y = r*sin(angle);
//        ofs << x << ' ' << y << endl;
//    }
//    return 0;
//}
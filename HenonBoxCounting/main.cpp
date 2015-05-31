//
//  main.cpp
//  HenonBoxCount
//
//  Created by 佐々木博弥 on 2015/05/29.
//  Copyright (c) 2015年 hrio. All rights reserved.
//

#include <iostream>
#include <fstream>

#define N 10000

using namespace std;

int main()
{
    double a, b, x[N], y[N];
    int n;
    
    x[0] = 0.1; y[0] = 0.0;
    a = 1.4; b =0.3;
    
    ofstream ofs("/Users/hiromi/Desktop/HenonBoxCount.txt");
    
    for (n = 0; n < N; n++)
    {
        double xx,yy;
        xx = 1.0 - a*x[0]*x[0] + y[0];
        yy = b*x[0];
        x[0] = xx;
        y[0] = yy;
    }
    for (n = 0; n < N-1; n++)
    {
        x[n+1] = 1.0 - a*x[n]*x[n] + y[n];
        y[n+1] = b*x[n];
    }
    
    double Xmax = x[0];
    double Xmin = x[0];
    double Ymax = y[0];
    double Ymin = y[0];
    
    for(n = 1; n < N; n++)
    {
        if(Xmax < x[n])
            Xmax = x[n];
        if(Xmin > x[n])
            Xmin = x[n];
        if(Ymax < y[n])
            Ymax = y[n];
        if(Ymin > y[n])
            Ymin = y[n];
    }
    
    //cout << Xmax << endl << Xmin << endl << Ymax << endl << Ymin << endl;
    
    
    double lnx[190],lny[190];
    for(int i = 10; i < 200; i++)
    {
        double Xbox = (Xmax - Xmin) / i;
        double Ybox = (Ymax - Ymin) / i;
        int count = 0;
        
        for(int xx = 0; xx < i; xx++)
            for(int yy = 0; yy < i; yy++)
                for(n = 0; n < N; n++)
                    if(Xmin+Xbox*xx <= x[n] <= Xmin+Xbox*(xx+1) && Ymin+Xbox*yy <= y[n] <= Ymin+Ybox*(yy+1))
                    {
                        count++;
                        break;
                    }
        
        
        
    }

    return 0;
    
}

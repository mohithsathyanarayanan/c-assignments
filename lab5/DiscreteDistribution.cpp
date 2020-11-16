#pragma once //to prevent multiple inclusions of this file in test.cpp.
using namespace std ;
#include<iomanip>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

class DiscreteDstribution
{
    
    public:
         
    DiscreteDstribution()
    {
    
    }


    double Manhattan_distance(vector <double> &v1, vector <double> &v2,int n)
    {
        double sum = 0 ;
        double temp ;
        for(int i =0 ; i<=n ; i++)
        {
            temp = abs(v1[i]-v2[i]) ;
            sum=sum+temp ;
        }

        return sum ;
    }


    double euclidian_distance(vector <double> &v1, vector <double> v2,int n)
    {
        double dist=0 ;
        double temp ;
        for(int i = 0 ;i<=n ; i++)
        {
            temp =pow((v1[i]-v2[i]),2) ;
            dist = dist + temp ;
        }

        return pow(dist,0.5) ;
    }
        
    double chebyshev_distance(vector <double> &v1,vector <double> &v2 , int n)
    {
        double dist=0 ;
        float diff ;
        for(int i =0 ; i<=n; i++)
        {
            diff =abs(v1[i]-v2[i]) ;

            if(dist<diff)
            {
                dist = diff ;
            }
        }

        return dist ;
    }


    double kl_distance(vector <double> &v1 , vector <double> &v2,int n)
    {
        double sum=0 ;
        for(int i=0;i<=n;i++)
        {
		    if(v2[i] >0 && v2[i] > 0)
            {
                sum = sum + log(v1[i]/v2[i])*v1[i];
                sum = sum + log(v2[i]/v1[i])*v2[i]; 
    	    }      
	    }
        return sum;

    }

    double js_distance(vector <double> &v1 , vector <double> &v2,int n)
    {
        double sum=0,m = 0, JS_dist = 0;

        for(int i=0;i<n;i++)
        {
	if(v1[i] > 0 && v2[i] > 0){
            m = (v1[i]+v2[i])/2;
            sum = sum + v1[i]*(log(v1[i]/m));
            sum = sum + v2[i]*(log(v2[i]/m));
	}
        }

        JS_dist = (sum)/2;
        JS_dist = sqrt(JS_dist);

        return JS_dist ;

    }



};
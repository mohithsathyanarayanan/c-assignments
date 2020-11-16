using namespace std ;
#include<iomanip>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include"DiscreteDistribution.cpp"


class PoissonDistribution :public DiscreteDstribution
{
    public:
    float m ;
    int n ;

    PoissonDistribution(float rate,int bins ) : DiscreteDstribution()
    {
        m=rate ;
        n=bins ;
    }


    int factorial(int n) 
    { 
        if (n == 0)
        { 
            return 1; 
        }
        return n * factorial(n - 1); 
    } 

    float pmf(int k,float m)
    {
        float pi = 0 ;
        pi = (pow(m,k) * exp(-m))/factorial(k) ;
        return pi ;
    }

    vector <double> distribution(float m)
    {
        float pm ;
        vector <double> v1 ;
        for(int i = 0 ; i<101 ; i++)
        {
            pm = pmf(i,m) ;
            v1.push_back(pm) ;
        }

        return v1 ;
    }

    float get_mean()
    {
        return m ;
    }    

    float get_variance()
    {
        return m ;
    }

    float get_mode()
    {
        float mode = floor(m) - 1 ;
        return mode ;
    }

    float get_median()
    {
        float median = floor(m + 0.33 - (0.02/m)) ;
        return median ;
    }

    int get_signature() //finite support,means signature is 0 and infinite support means signature is 1..
    {
        int signature= 1 ;
        return signature ;

    }   
};
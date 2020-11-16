using namespace std ;
#include<iomanip>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include"DiscreteDistribution.cpp"

class NBdistribution :public DiscreteDstribution
{
    public:
    int success ;
    float prob ; 

    NBdistribution(int r , float p) : DiscreteDstribution()
    {
        success = r ;
        prob = p ;
    }

    double nCr(int n, int r) 
    { 
    
        if (r > n / 2)
        { 
            r = n - r; 
        }
        double answer = 1; 
        for (int i = 1; i <= r; i++) 
        { 
            answer *= (n - r + i); 
            answer /= i;
        } 
    
        return answer; 
    } 

    float pmf(int k , int r , float p)
    {
        float pm ;
        pm = nCr(k+r-1,r-1) * pow(1-p,k) * pow(p,r) ;
        return pm ;
    }

    vector <double> distribution(float p,int r)
    {
        vector <double> v ;
        float pm ;
        for(int i = 0 ; i<101 ; i++)
        {
            pm = pmf(i,r,p) ;
            v.push_back(pm) ;
        }

        return v ;
    }


    float get_mean(int r,float p)
    {
        float mean = p*r/(1-p) ;
        return mean ;
    }

    float get_mode(int r , float p)
    {
        float mode = floor(p*(r-1)/(1-p)) ;
        return mode ;
    }

    float get_variance(int r,float p)
    {
        float var ;
        var = p*r / pow(1-p,2) ;
        return var ;
    }

    int get_signature() //finite support,means signature is 0 and infinite support means signature is 1..
    {
        int signature = 1 ;
        return signature ;
    }
};

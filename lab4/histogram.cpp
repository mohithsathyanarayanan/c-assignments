#include<math.h>
#include <iostream>
#include <vector> 
#include <stdio.h>
#include <stdlib.h>
using namespace std ;

class histogram
{
    public :
    float p ;
    int n ;

    histogram(float p1,int num)
    {
        p=p1 ;
        n= num ;
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
  

    double binomialProbability(int n, int k, float p) 
    { 
        return nCr(n, k) * pow(p, k) * pow(1 - p, n - k); 
    } 
      

    vector <double> create_bin(float p,int n)
    {
        vector <double> v1 ;
        float binomial_dis ;
        int nck ;
        for(int i = 0 ; i<= n  ; i++)
        {
            binomial_dis= binomialProbability(n,i,p);
            v1.push_back(binomial_dis);
        }

        return v1 ;
    }


    int bin_length(vector <double> &v1,vector <double> &v2)
    {

        int v1_l = v1.size() ;
        int v2_l = v2.size() ;

        if(v1_l=v2_l)
        {
            return 1 ;
        }

        else
        {
            return 0 ;
        }

    }


};




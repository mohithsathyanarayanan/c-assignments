using namespace std ;
#include<iomanip>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include"DiscreteDistribution.cpp"

class BinomialDistribution : public DiscreteDstribution
{
    public:
    float p ;
    int n ;

    BinomialDistribution(float pr, int num) : DiscreteDstribution()
    {
        p=pr ;
        n=num ;
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

    //all the formulae for mean, mode, variance , median hacve been taken from wikipedia.. 

    float get_mean(int n , float p)
    {
        float mean = n*p ;
        return  mean ;
    }

    float get_mode(int n , float p)
    {
        float mode = floor((n+1)*p) ;
        return mode ;
    }

    float get_variance(int n , float p)
    {
        float var = n*p*(1-p) ;
        return var ;
    }

    float get_median(int n, float p)
    {
        float median = floor(n*p) ;
        return median ;
    }

    int get_signature() // finite support,means signature is 0 and infinite support means signature is 1..
    {
        int signature=0 ;
        return signature ;
    }


};
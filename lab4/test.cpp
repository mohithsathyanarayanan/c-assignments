#include <iomanip> 
#include <iostream>
#include <vector> 
#include <stdio.h>
#include <stdlib.h>
using namespace std ;
#include "binomildistribution.cpp"
#include <math.h> 

int main()
{
    float p1,p2 ;
    int n ;
    scanf("%d%f%f", &n,&p1,&p2 );

    histogram h1(p1,n) ;
    histogram h2(p2,n) ;

    vector <double>  v1 ;
    vector <double> v2  ;

    v1=h1.create_bin(p1,n) ;
    v2=h2.create_bin(p2,n) ;

    binomial_distribution bd1(p1,n) ;
    binomial_distribution bd2(p2,n) ;    

    double md= bd1.Manhattan_distance(v1,v2,n);
    
    


    double ed = bd1.euclidian_distance(v1,v2,n) ;

    


    double cd = bd1.chebyshev_distance(v1,v2,n) ;

    

    double kl = bd1.kl_distance(v1,v2,n) ;

    

    double js = bd1.js_distance(v1,v2,n) ;

    
    
    std::cout << std::setprecision(5) << md << "," << std::setprecision(4) << ed << "," << std::setprecision(5) << cd << "," << std::setprecision(5) << kl << "," << std::setprecision(5) << js <<endl  ;

}


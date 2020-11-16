using namespace std ;
#include<iomanip>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include "BinomialDistribution.cpp"
#include "PoissonDistribution.cpp"
#include "NBdistribution.cpp"
#include <bits/stdc++.h>

int main()
{
    char input[100] ;
    cin.getline(input,100) ;
    string num_str = "" ;
    vector <float> v1 ;
    float num  ;
    int type_d = int (input[1])-48 ;
    for(int i =3 ; i<100 ; i++)
    {
        string element = string(1,input[i]) ;
        if(element.compare(" ")!= 0 and element.compare(",") )
        {
            num_str=num_str+element ;
        }

        if(element.compare(" ")==0 or element.compare(",")==0)
        {
            
            num = stof(num_str) ;
            v1.push_back(num) ;
            num_str = "" ;
        }
    }
    vector <int> sig ;
    vector <vector <double>> bin_vector ;
    vector <DiscreteDstribution*> dd ;
    int length=0 ;
    float array[4] ;
    for(float x : v1)
    {
         
        if(x!=-1)
        {
            array[length]=x ;
            length=length+1 ;
            
        }

        if(x==-1 and length>0)
        {
            if(length==1 and  x==-1)//pd
            {
                PoissonDistribution pd(array[0],100) ;
                PoissonDistribution *ptr ;
                ptr = &pd ;
                dd.push_back(ptr) ;
                bin_vector.push_back(pd.distribution(array[0])) ;
                std::cout<< pd.get_mean() <<","<< pd.get_median() <<","<< pd.get_mode() <<","<< pd.get_variance()<<" "<<"-1"<<" " ;
                sig.push_back(pd.get_signature()) ;
            }

            if(length==2)
            {
                if(array[0]<0) //nbd
                {
                    NBdistribution nd(array[0],array[1]);
                    NBdistribution *ptr2 ;
                    ptr2 = &nd ;
                    dd.push_back(ptr2) ;
                    std::cout<< nd.get_mean(-1*array[0],array[1]) <<","<< nd.get_mode(-1*array[0],array[1]) <<","<< nd.get_variance(-1*array[0],array[1])<<" "<<"-1"<<" " ;              
                    bin_vector.push_back(nd.distribution(array[1],array[0])) ;
                    sig.push_back(nd.get_signature()) ;
                }

                if(array[0]>0) //bd
                {
                    BinomialDistribution bd(array[0],array[1]) ;
                    BinomialDistribution *ptr3 ;
                    ptr3 = &bd ;
                    dd.push_back(ptr3);
                    std::cout<<bd.get_mean(array[0],array[1]) << "," << bd.get_median(array[0],array[1]) << "," << bd.get_mode(array[0],array[1]) << "," << bd.get_variance(array[0],array[1]) << " " << "-1" <<" " ;
                    bin_vector.push_back(bd.create_bin(array[1],array[0])) ;
                    sig.push_back(bd.get_signature()) ;
                }
            }
                
            length=0 ;
        }
    }

    std::cout<<endl ;
    std::cout  << "distance-matrix" << endl << endl ;

 
    // Iterator for the 2-D vector
    vector<vector<double>>::iterator it1;
 
    // Iterator for each vector inside the 2-D vector
    vector<double>::iterator it2;
 
    // Traversing a 2-D vector using iterators
    for(it1 = bin_vector.begin();it1 != bin_vector.end();it1++)
    {
        for(it2 = it1->begin();it2 != it1->end();it2++)
            cout<<*it2<<" ";
        cout<<endl;
    }
    int s1,s2 ;
    for(int i= 0 ; i<bin_vector.size(); i++)
    {
        s1 = sig[i] ;
        for(int j = 0 ; j<bin_vector[i].size(); i++)
        {

        }
    }

    















}



























































































//ignore all  below code

/*
    int sig1,sig2 ;
    vector <float> bin1 ;
    vector <float> bin2 ;
    for(float x : v1)
    {
         
        if(x!=-1)
        {
                array[length]=x ;
                length=length+1 ;
        }


        if(x==-1 and length>0)
        {
            if(length==1 and x==-1)
            {
                PoissonDistribution pd(array[0],100) ;
                sig1=pd.get_signature() ;               
                bin1= pd.distribution(array[0]) ;
            }

            if(length==2)
            {
                
                if(array[0]<0)
                {
                    NBdistribution nb(array[0],array[1]) ;
                    sig1 = nb.get_signature() ;
                    bin1 = nb.distribution(array[1],array[0]) ;
                }
            

                if(array[0]>0)
                {
                    BinomialDistribution bd(array[0],array[1]) ;
                    bin1 = bd.create_bin(array[1],array[0]) ;
                    sig1 = bd.get_signature() ;
                }
            }
            length=0 ;

        }

        for(float z:v1)
        {
            if(z!=-1)
            {
                array[length] = z ;
                length=length +1 ;
            }

            if(z==-1 and length>0)
            {
                if(length==1 and x==-1)
                {
                    PoissonDistribution pd(array[0],100) ;
                    bin2 = pd.distribution(array[0]) ;
                    sig2=pd.get_signature() ;
                }

                if(length==2 )
                {
                    if(array[0]<0)
                    {
                        NBdistribution nb(array[0],array[1]) ;
                        bin2=nb.distribution(array[1],array[0]) ;
                        sig2 = nb.get_signature() ;
                    }

                    if(array[0]>0)
                    {
                        BinomialDistribution bd(array[0],array[1]) ;
                        bin2 = bd.create_bin(array[1],10) ;
                        sig2= bd.get_signature() ;
                    }
                }
                length=0 ;
            }    
        }

            
    }

    
}*/



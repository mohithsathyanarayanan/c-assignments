    #include "Histogram.cpp"
    #include "Datasequence.cpp"
    #include <iostream>  
    #include<string.h>  
    using namespace std;  
string convertToString(char* a, int size) 
{ 
    int i; 
    string s = ""; 
    for (i = 0; i < size; i++) 
    { 
        s = s + a[i]; 
    } 
    return s; 
} 
 


int main()  
{  
    char input[1000]; // array declaration    
    cin.getline(input, 1000); // implementing getline() function  
    string input_string = convertToString(input,50) ; 
    int n = (float) input_string[0] - 48 ; // to convert ASCII value to int we subtract by 48 
    int array[1000] ;
    int j =0 ;
    float number[1000] ;
    string a = "" ;
    char b = input_string[8] ;
    char c = input_string[1] ;
    for(int i = 1 ; i<10000 ; i++)
    {
        if(input_string[i+4]!= b)
        {
           a=a+input_string[i+4] ;
        }
        if(input_string[i+4]==b || input_string[i+4]==c)
        {
           float num = stof(a) ; 
           number[j]= num ;
           j=j+1 ;
           a="" ;  
            
        }        
    }
    
    // the array "numbers" contains the entire input. so create another array which contains only, the stats .
    float stats[n];
    for(int i =0 ; i<n ; i++)
    {
        stats[i]=number[i] ;
    }

    float *ptr ;
    ptr = &stats[0] ;  
  
    string output="" ;
    Datasequence d1(ptr) ; 
    d1.selectionsort(stats,ptr,n) ;
    
    float min= d1.get_min(ptr) ;
    output=output+ std::to_string(min)+" "+"-1"+" " ;

    float mean = d1.get_mean(ptr,n);
    output=output+std::to_string(mean) +" "+ "-1"+" " ;

    float median = d1.get_median(ptr,n) ;
    output=output+std::to_string(median)+" "+"-1"+" " ;

    float max = d1.get_max(ptr,n) ;
    output=output+std::to_string(max)+" "+"-1"+" " ;

     
    int number_bins = number[n+1] ; 
    float bin_numbers[number_bins+1] ;
    Histogram h1(number_bins,ptr) ;
    h1.bin_values(stats[0],stats[n-1],number_bins,n,ptr,output) ;



    



        
}   

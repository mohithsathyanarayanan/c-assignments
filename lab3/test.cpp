#include <string>    
#include <stdio.h>
using namespace std ;
#include<iostream>
#include <vector>
#include "datasequence.cpp"
#include "fivenumber.cpp"
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

vector <float> string_to_number(int pos, string input_string, vector <float> v)
{
    //pos is i=on first number 
    bool flag = false ;
    string num_str="" ;
    int i = 0 ;
    string instr[2] = {",", " "} ; 
    while(!flag)
    {
        char element = input_string[pos];
        string s(1,element) ; 
        if(instr[0].compare(s)!=0 and instr[1].compare(s)!=0 )
        {
            num_str=num_str+s ;
            pos=pos+1 ;
        }

        if(instr[0].compare(s)==0)
        {
            float n = stof(num_str) ;
            pos=pos+1 ;
            v.push_back(n) ;
            num_str="" ;
        }

        if(instr[1].compare(s)==0)
        {
            flag=true ;
            float n= stof(num_str);
            v.push_back(n) ;
            return v ;
        }
    
    }
    return  v ;
}


int main()
{
    char input[1000]; // array declaration    
    cin.getline(input, 1000); // implementing getline() function  
    string input_string = convertToString(input,1000) ; 
    char a = input_string[1] ; //","
    char b = input_string[3] ; // " "
    string instructions[3] ;
    instructions[0]="N" ; 
    instructions[1]="A" ;  
    vector <int> array_n ; //store locations of all N in input
    vector <int> array_a ; // store ocations of all A in input
    int count_n = 0 ;
    int count_a =0 ; 
    for(int i = 0 ; i<150 ; i++)
    {
        char element = input_string[i] ;
        string s(1,element) ;
        if(s.compare(instructions[0])==0)
        {
           array_n.push_back(i) ; 
        }

        if(s.compare(instructions[1])==0)
        {
            array_a.push_back(i) ;
        }
    }

    int v_count = 0 ;
    string output = "" ;
    
    for(int x : array_n)
    {
        vector <float> v ;
        int pos = x+4 ;
        v=string_to_number(pos,input_string,v);

        for(int y : array_a)
        {
            int pos2 = (int) input_string[y+2] - 48 ;
            if(v_count==pos2)
            {
                v=string_to_number(y+4, input_string,v);
            }
        }

        v_count=v_count+1 ;

        float *ptr ;
        ptr=&v[0] ;

        datasequence DS(ptr) ;

        DS.selectionsort(v,ptr,v.size()) ;
        float min = DS.get_min(ptr) ;
        output=output+ to_string(min)+"," ;

        float q1 = DS.get_q1(v,v.size()) ;
        output=output+to_string(q1)+"," ;
        
        float median = DS.get_median(ptr,v.size());
        output=output+to_string(median)+"," ;

        float q3 = DS.get_q3(v,v.size());
        output=output+to_string(q3)+"," ;

        float max =DS.get_max(ptr,v.size());
        output=output+to_string(max)+"," ;

        fivenumber f5(min,q1,median,q3,max) ; //updating five number for every DS

        DS.bin_values(min,max,v.size(),output,v,array_n.size()) ; //calling histogram's bin_values for binvalues and normalized binfrequency on DS obj.
        output="" ;

               






    }
    

     

}
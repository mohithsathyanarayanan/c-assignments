    #include<iostream>  
    #include<string.h>  
    using namespace std;

    class fivenumber
    {
        public :
        float min ;
        float fq ;
        float median ;
        float tq ;
        float max ;

        fivenumber(float mi,float f,float me,float t,float ma)
        {
            min=mi ;
            fq = f ;
            median = me ;
            tq = t ;
            max = ma ; 
        }

       float get_min()
       {
           return min ;
       }

       float get_fq()
       {
           return fq ;
       }

       float get_med()
       {
           return median ;
       }

       float get_max()
       {
           return max ;
       }

       float get_tq()
       {
           return tq ;
       }

    };
    #include<iostream>  
    #include<string.h>  
    using namespace std;

    class Datasequence
    {
        public:
        float *pointer ;
        Datasequence(float *p)
        {
            pointer=p ;
        }

        void swap(float *a,float *b) //for swapping in selection sort
        {
            float temp= *b;
            *b=*a ;
            *a=temp ;
        }

        void selectionsort(float array[], float *p,int size)
        {
            for(int step = 0 ; step<size-1;step++)
            {
                int min_index=step ;
                for(int i = step+1;i<size;i++)
                {
                    if(array[i]<array[min_index])
                    {
                        min_index=i ;
                    }
                }
                swap(&array[min_index],&array[step]);
            }
        }

        float get_min(float *ptr)
        {
            float min = *ptr ;
            return min ;
        }

        float get_max(float *ptr,int n)
        {
            float max = *(ptr+n-1)  ;
            return max ;
        }

        float get_median(float *ptr , int n)
        {
        
            float median ;

            if(n%2!=0) 
            {
                n=n/2 ;
                median= *(ptr+n) ;
            }

            if(n%2==0)
            {
                float a = *(ptr+(n/2)-1) ;
                float b = *(ptr+(n/2)) ;
                median = (a+b)/2.0 ;
            }

            return median ;
                        
        }

        float get_mean(float *ptr, int n)
        {
            float total=0 ;
            for(int i = 0 ; i<n ; i++)
            {
                 total = total + *(ptr+i) ;
            }

            float mean = total/n ;
            return mean ;
        }
};

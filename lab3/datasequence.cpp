    #include<iostream>  
    #include<string.h>  
    using namespace std;
    #include "histogram.cpp"
    class datasequence
    {
        public:
        float *pointer ;
        datasequence(float *p)
        {
            pointer=p ;
        }

        void swap(float *a,float *b) //for swapping in selection sort
        {
            float temp= *b;
            *b=*a ;
            *a=temp ;
        }

        void selectionsort( vector <float> &array, float *p,int size)
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

       static float get_median(float *ptr , int n)
        {
        
            float median ;
            if(n%2==1) 
            {   int i ;
                i=n/2 ;
                median= *(ptr+i) ;
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


        float get_q1(vector <float> &v , int size)
        {
            if(size%2==0)
            {
                int mid = size/2 ;
                float lower[mid] ;
                float upper[mid] ;
                for(int i = 0; i<mid ; i++)
                {
                        lower[i]=v[i] ;
                }

                for(int j = mid ; j<size;j++)
                {
                    upper[j]=v[j] ;
                }

                float *p1 ;
                float *p2 ;
                p1=&lower[0] ;
                p2=&upper[0] ;
                float q1 = get_median(p1,mid);
                float q3 = get_median(p2,mid) ;
                return q1 ;      
            }
            float q1 ;
            if(size%2==1)
            {
                int mid = size/2 ;
                float lower[mid+1] ;
                float upper[mid+1] ;

                for(int i = 0 ; i<mid+1 ; i++)
                {
                    lower[i]=v[i] ;
                }

                for(int j = mid ; j<size ; j++)
                {
                    upper[j]=v[j] ;
                }

                float *p1 ;
                float *p2 ;
                p1=&lower[0] ;
                p2=&upper[0] ;
                float q1 = get_median(p1,mid+1);
                float q3 = get_median(p2,mid+1);
                return q1 ;
            }

            return q1 ;

        }

        float get_q3(vector <float> &v , int size)
        {
            int mid = size/2 ;
            int counter = 0 ; 
            if(size%2==0)
            {
                float upper[mid] ;
                for(int i = mid ; i<size ; i++)
                {
                    upper[counter]=v[i] ;
                    counter=counter+1 ;
                }
                float *p ;
                p=&upper[0];
                float q3 = get_median(p,mid) ;
                return q3 ;
            }

            if(size%2==1)
            {
                float upper[mid+1] ;

                for(int j = mid ; j<size ; j++ )
                {
                    upper[counter]=v[j] ;
                    counter=counter+1 ;
                }

                float *q ;
                q=&upper[0] ;
                float q3 = get_median(q,mid+1) ;
                return q3 ;
            }
            float q3 ;
            return q3 ;
        }

    void bin_values(float min,float max,int size,string output, vector <float> &v,int v_count)
    {
        float diff = (max-min)/10 ;
        float bin_values[11] ;
        int bin_size = 10 ;
        bin_values[0] = min ;
        output = output+to_string(bin_values[0]) ;
        for(int i = 1 ; i<=bin_size ; i++) 
        {
            min = diff+min ;
            bin_values[i]=min ; 
            output=output+std::to_string(min)+"," ;
        }

        float freq[10] ;
        for(int i = 0 ; i<11;i++)
        {
            freq[i]=0 ;
        }
 
        for(int j=0;j<v.size()+1; j++)
        {
            float num = v[j] ; 
            for(int k = 0 ; k<bin_size+1 ; k++)
            {

                if(num<bin_values[k])
                {
                    freq[k]=freq[k]+1 ;
                    break ;

                }

                if(num==bin_values[k])
                {
                    freq[k]=freq[k]+1 ;
                    break ;
                }
            }
        }
        for(float x : freq)
        {
            x=x/10 ;
            output=output+to_string(x) ;
        }

        output=output+" "+"-1"+" " ;

        std:: cout << output ;
    }





};

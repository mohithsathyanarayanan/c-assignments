#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define max 10000

struct vector{
    int vec_size;
    double *vector_val;
    double magnitude;
};

int get_array(struct vector *vec);
double cal_manhattan_dist(struct vector vect1,struct vector vect2);
double eculidean_dist(struct vector vect1, struct vector vect2);
double chebyshev_dist(struct vector vect1,struct vector vect2);
double kl_divergece(struct vector vect1,struct vector vect2);
double JS_dist(struct vector vect1,struct vector vect2);

int main(){

    int delimiter,check,size;
    struct vector vect[2];

    scanf("%d",&size);
    scanf("%d",&delimiter);
    if( (size<=0) || (delimiter != -1) ){
        printf("-1\n");
        return 0;
    }
    for(int i=0;i<2;i++){
        vect[i].vec_size = size;
        vect[i].vector_val = (double *)malloc(sizeof(double)*vect[i].vec_size);
    
        check = get_array(&vect[i]);
        if(check == 1){
            printf("-1\n");
            return 0;
        }
    }
    double cal_man,cal_ecu,cal_che,cal_KL,cal_JS;
    cal_man = cal_manhattan_dist(vect[0],vect[1]);
    cal_ecu = eculidean_dist(vect[0],vect[1]);
    cal_che = chebyshev_dist(vect[0],vect[1]);
    cal_KL  = kl_divergece(vect[0],vect[1]);
    cal_JS  = JS_dist(vect[0],vect[1]);
    printf("%0.4f,%0.4f,%0.4f,%0.4f,%0.4f\n",cal_man,cal_ecu,cal_che,cal_KL,cal_JS);

    return 0;
        
}


int get_array(struct vector *vec){
    char string[max];
    int delimiter;

    scanf("%s",string);
    char *token = strtok(string,","); 
    int i=0;
    while(token != NULL)
    {
        vec->vector_val[i] = atof(token);
        token = strtok(NULL,",");
        i++;
    }
    if(i != vec->vec_size)
        return 1;
    scanf("%d",&delimiter);
    if(delimiter != -1){
        return 1;
    }
    vec->magnitude =0;
    for(int i=0;i<vec->vec_size;i++){
        if(vec->vector_val[i] <= 0)
            return 1;
        vec->magnitude = vec->magnitude + vec->vector_val[i];
    }
    //vec->magnitude = sqrt(vec->magnitude);
    for(int i=0;i<vec->vec_size;i++){
        vec->vector_val[i]= vec->vector_val[i]/(double) vec->magnitude;
    }
    return 0;
}

double cal_manhattan_dist(struct vector vect1,struct vector vect2){
    double sum=0,temp;
    for(int i=0;i<vect1.vec_size;i++){
        temp = vect1.vector_val[i] - vect2.vector_val[i];
        if(temp<0){
            temp = -temp;
        }
        sum += temp;
    }
    return sum;
}
double eculidean_dist(struct vector vect1, struct vector vect2){
    double sum =0;
    for(int i=0;i<vect1.vec_size;i++){
        sum = sum + pow(vect1.vector_val[i] - vect2.vector_val[i],2);
    }
    sum = sqrt(sum);
    return sum;
}

double chebyshev_dist(struct vector vect1,struct vector vect2){
    double sum = 0,temp;
    for(int i=0;i<vect1.vec_size;i++){
        temp = vect1.vector_val[i] - vect2.vector_val[i];
        if(temp <0)
            temp = -temp;
        if(temp>sum)
            sum = temp;
    }
    return sum;
    
}

double kl_divergece(struct vector vect1,struct vector vect2){
    double sum=0 ;
    for(int i=0;i<vect1.vec_size;i++){
        sum = sum + log(vect1.vector_val[i]/vect2.vector_val[i])*vect1.vector_val[i];
        sum = sum + log(vect2.vector_val[i]/vect1.vector_val[i])*vect2.vector_val[i];
    }
    return sum;
}

double JS_dist(struct vector vect1,struct vector vect2){
    double sum=0,m = 0, JS_dist = 0;

    for(int i=0;i<vect1.vec_size;i++){
        m = (vect1.vector_val[i]+vect2.vector_val[i])/2;
        sum = sum + vect1.vector_val[i]*(log(vect1.vector_val[i]/m));
        sum = sum + vect2.vector_val[i]*(log(vect2.vector_val[i]/m));
    }

    JS_dist = (sum)/2;
    JS_dist = sqrt(JS_dist);

    return JS_dist ;
}
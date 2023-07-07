#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float train[][2] = {
    {0, 0},
        {1, 2},
        {2, 4},
        {3, 6},
        {4, 8},
        {5, 10},
        {6, 12},
        {7, 14},
        {8, 16},
        {9, 18},
        {10, 20},
        {11, 22},
        {12, 24},
        {13, 26},
        {14, 28},
        {15, 30},
        {16, 32},
        {17, 34},
        {18, 36},
        {19, 38}
};
// y = x * w; 

#define train_count (float)(sizeof(train)/sizeof(train[0]))

float rand_float(void)
{
    return (float) rand() / (float) RAND_MAX;
}

//cost function
// float cost(float w, float b)
// {
//     float result = 0.0f;
//     for(size_t i = 0; i < train_count; i++)
//     {
//         float x = train[i][0];
//         float y = train[i][1];
//         float y_p = x * w + b;

//         float d = y_p - y;
//         result += d*d;
//     }
//     result /= train_count;
//     return result;

// }

int main()
{
    srand(69);
    float w = rand_float()*10.0f;
    float b = rand_float()*10.0f;

    //float eps = 1e-4;
    float rate = 1e-1;

   
    for(size_t i = 0; i < 1000; i++)
    {
        float x = train[i][0];
        float y = train[i][1];
        float y_p = x * w + b;
        float cost = (1/train_count) * (y - y_p) * (y - y_p);
        float dw = -(2/train_count) * (x*(y - y_p));
        float db = -(2/train_count) * (y - y_p);
        w -= rate*dw;
        b -= rate*db;
        printf("cost = %f w = %f b = %f\n", cost, w, b);
        
    }

    printf("--------------\n");
    

    

    return 0;
}
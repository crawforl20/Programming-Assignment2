//Jake Nguyen & Logan Crawford - OS Homework

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <iostream>

using namespace std;
#define INTERVAL 20000
template <typename tan>

struct pickPoint{
    tan x;
    tan y;
};

typedef struct{
    pickPoint<int> center;
    int rad;
}Circle;

typedef struct{
    pickPoint<int> tl;
    pickPoint<int> br;
}Square;

int count_circle_points = 0, count_square_points = 0;
double randomDouble(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}


void *Calcpoint(void *threaddid )
{
    double x1;
    double y2;
    x1 = ((double) rand() / (RAND_MAX));
    if (rand() % 2 == 0 )
    {
        x1 = x1*(-1);
    }
    y2 = ((double) rand() / (RAND_MAX));
    if (rand() % 2 == 0 )
    {
        y2 = y2*(-1);
    }
    // Define a circle
    Circle _circle;
    Square _square;

    // (0,0), rad = 1
    _circle.center.x=0;
    _circle.center.y=0;
    _circle.rad=1;

    // Base of the relationship between the circle in the square
    _square.tl.x=_circle.center.x-_circle.rad;
    _square.tl.y=_circle.center.y+_circle.rad;

    _square.br.x=_circle.center.x+_circle.rad;
    _square.br.y=_circle.center.y-_circle.rad;



    cout << "Circle("<< _circle.center.x << "," << _circle.center.y << "), R=" << _circle.rad << endl;
    cout << "Square TL("<< _square.tl.x << "," << _square.tl.y << ")"<<", BL("<< _square.br.x << "," << _square.br.y << ")" << endl<<endl;

    //if (x1 <= _square.tl.x && y2 <= _square.tl.y)


    if ( (x1*x1) + (y2*y2) <= (_circle.rad)*(_circle.rad))
    {
        count_circle_points++;
    }
    return NULL;
}


int main(int argc, char * args[])
{

    int N = 50;
    count_square_points = N;


    pthread_t* threadN = (pthread_t*)malloc(sizeof(pthread_t) *N);
    int i;
    for (i = 0; i < N; i++)
    {
        pthread_create(&threadN[i], NULL,*Calcpoint, NULL);
    }
    //the counter will stop when hit the N thread
    for (i=0; i< N; i++)
    {
        pthread_join(threadN[i],NULL);
    }

    double pi = ( 4*(count_circle_points)/(double)(count_square_points));

    cout << "Pi Estimation = " << pi  << "\n" ;

    return 0;
}

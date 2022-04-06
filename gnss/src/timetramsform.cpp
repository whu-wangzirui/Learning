#include"head.h"

double timetramsform(int hour,int min )
{
    double sec=0;
    sec=((hour*60)+min)*60;
    return sec;
}
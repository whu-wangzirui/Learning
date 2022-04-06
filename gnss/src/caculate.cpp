#include "head.h"


//a function
double Avarnge_angle_v(double sqrt_A)
{
    double n0=0;
    n0=sqrt(constantnumber::GM)/(sqrt_A*sqrt_A*sqrt_A);
    return n0;
}//计算卫星运动平均角速度n0

double Caculate_Mean_Anomaly(double n0,double t,double M0_toe,double n_delta,double toe)
{
    double M=M0_toe+(n0+n_delta)*(t-toe);
    return M;
}//计算平近点角

double Caculate_Ellentric_Anomaly(double M,double e)
{
    double dE;
    double E0,E;
    E0=M;
    while (dE>1e-09)
    {
       
        E=M+e*sin(E0);
        dE=abs(E-E0);
        E0=E;
    }
    return E;
    
}//计算偏近点角
double Caculate_True_Anomaly(double E,double e)
{
    double f;
    f=atan(sqrt(1-e*e)*sin(E)/(cos(E)-e));
    return f;
}//计算真近点角

double Caculate_Perturbation_Correction(double u,double C_c,double C_s)
{
    double delta;
    delta=C_c*cos(2*u)+C_s*sin(2*u);
    return delta;
}//计算摄动改正项

double Caculate_u(double u_privous,double delta_u)
{
    double u;
    u=u_privous+delta_u;
    return u;
}//计算进行升交角改正

double Cacluate_r(double sqrtA,double e,double E,double delta_r)
{
    double r;
    r=sqrtA*sqrtA*(1-e*cos(E))+delta_r;
    return r;
}//进行卫星矢径改正

double Cacluate_i(double i0,double delta_i,double i_dot,double t,double toe)
{
    double i;
    i=i0+delta_i+i_dot*(t-toe);
    return i;
}//进行轨道倾角改正

double L_Caculate(double Omiga_0,double Omiga_dot,double omiga_e,double t,double toe)
{
    double L;
    L=Omiga_0+(Omiga_dot-omiga_e)*t-Omiga_dot*toe;
    return L;
}//计算大地经度





 

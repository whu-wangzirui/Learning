#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <eigen3/Eigen/Dense>
#include <vector>
#include <algorithm>
#include<iomanip>
using namespace Eigen;




namespace constantnumber
{
    constexpr double GM = 3.986005e14;
    constexpr double omiga_e = 7.292115e-5;
} // namespace constantnumber

double Avarnge_angle_v(double sqrt_A);
double timetramsform(int hour, int min);
double Caculate_Mean_Anomaly(double n0,double t,double M0_toe,double n_delta,double toe);
double Caculate_Ellentric_Anomaly(double M,double e);
double Caculate_True_Anomaly(double E,double e);
double Caculate_Perturbation_Correction(double u, double C_c, double C_s);
double Caculate_u(double u_privous, double delta_u);
double Cacluate_r(double sqrtA, double e, double E, double delta_r);
double Cacluate_i(double i0, double delta_i, double i_dot, double t, double toe);
double L_Caculate(double Omiga_0, double Omiga_dot, double omiga_e, double t, double toe);
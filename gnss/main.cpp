#include "head.h"


int main(int argc, char const *argv[])
{
    std::string satellite; //卫星编号
    double sqrtA;          //轨道长半径平方根
    double M0_toe;         // teo时平近点角
    double n_delta;        //平均运动修正量
    double e;              //卫星轨道偏心率
    double omiga;          //近地点角距
    double Crs;            //轨道半径正弦改正数
    double Cuc;            //维度幅角余弦改正项
    double Cus;            //纬度幅角正弦改正项
    double Cic;            //轨道倾角余弦调和项
    double Cis;            //轨道倾角正弦项
    double Crc;            //轨道半径余弦调和项
    double I;              //轨道倾角
    double I_dot;          //轨道倾角变化率
    double OMIGA_dot;      //生交点赤经变化率
    double OMIGA;          //升交点赤经
    double toe;            //星历的基准时间

    int year;
    int mouth;
    int day;
    int hour;
    int min;
    int sec;
    freopen("../output/output.txt", "w", stdout);
    std::ifstream ifs("../data/20191201.eph.txt");
    int lines = 1;
    std::string beforeword;
    for (lines; lines < 12; lines++)
    {
        std::string tmpstring;

        getline(ifs, tmpstring);

        beforeword = beforeword + tmpstring;
    }
    // std::cout<<beforeword;
    // std::cout<<lines<<std::endl;
    while (lines > 11 && lines < 3864)
    {
        int line_block = 1;
        for (int i = 1; i < 9; i++)
        {
            // std::cout<<i<<std::endl;
            std::string templine;
            std::getline(ifs, templine);
            // std::cout<<templine<<std::endl;
            if (line_block == 1)
            {
                std::string temp_satellite = templine.substr(0, 3);
                // std::cout << temp_satellite << '\t';
                satellite = temp_satellite;

                std::string temp_year = templine.substr(4, 4);
                // std::cout << temp_year << '\t';
                year = std::stoi(temp_year);

                std::string temp_mouth = templine.substr(9, 2);
                // std::cout << temp_mouth << '\t';
                mouth = std::stoi(temp_mouth);

                std::string temp_day = templine.substr(12, 2);
                // std::cout << temp_day << '\t';
                day = std::stoi(temp_day);

                std::string temp_hour = templine.substr(15, 2);
                // std::cout << temp_hour << '\t';
                hour = std::stoi(temp_hour);

                std::string temp_min = templine.substr(18, 2);
                // std::cout << temp_min << '\t';
                min = std::stoi(temp_min);

                std::string temp_sec = templine.substr(21, 2);
                // std::cout << temp_sec << std::endl;
                sec = std::stoi(temp_sec);

                std::string temp_clock_delta = templine.substr(23, 19);
                // std::cout << temp_clock_delta << '\t';
                std::string temp_clock_delta_2 = templine.substr(42, 19);
                // std::cout << temp_clock_delta_2 << '\t';
                std::string temp_clock_delta_3 = templine.substr(61, 19);
                // std::cout << temp_clock_delta_3 << std::endl;

                line_block = line_block + 1;
                lines = lines + 1;
                continue;
            }
            if (line_block == 2)
            {
                std::string temp_Crs = templine.substr(23, 19);
                // std::cout << temp_Crs << '\t';
                Crs = std::stod(temp_Crs);
                std::string temp_n_delta = templine.substr(42, 19);
                // std::cout << temp_n_delta << '\t';
                n_delta = std::stod(temp_n_delta);
                std::string temp_M0_toe = templine.substr(61, 19);
                // std::cout << temp_M0_toe << std::endl;
                M0_toe = std::stod(temp_M0_toe);
                line_block = line_block + 1;
                lines = lines + 1;
                continue;
            }
            if (line_block == 3)
            {
                std::string temp_Cuc = templine.substr(4, 19);
                // std::cout << temp_Cuc << '\t';
                Cuc = std::stod(temp_Cuc);

                std::string temp_e = templine.substr(23, 19);
                // std::cout << temp_e << '\t';
                e = std::stod(temp_e);

                std::string temp_Cus = templine.substr(42, 19);
                // std::cout << temp_Cus << '\t';
                Cus = std::stod(temp_Cus);

                std::string temp_sqrtA = templine.substr(61, 19);
                // std::cout << temp_sqrtA << std::endl;
                sqrtA = std::stod(temp_sqrtA);
                line_block = line_block + 1;
                lines = lines + 1;
                continue;
            }
            if (line_block == 4)
            {
                std::string temp_toe = templine.substr(4, 19);
                // std::cout << temp_toe << '\t';
                toe = std::stod(temp_toe);

                std::string temp_Cic = templine.substr(23, 19);
                // std::cout << temp_Cic << '\t';
                Cic = std::stod(temp_Cic);

                std::string temp_OMIGA = templine.substr(42, 19);
                // std::cout << temp_OMIGA << '\t';
                OMIGA = std::stod(temp_OMIGA);

                std::string temp_Cis = templine.substr(61, 19);
                // std::cout << temp_Cis << std::endl;

                line_block = line_block + 1;
                lines = lines + 1;
                continue;
            }
            if (line_block == 5)
            {
                std::string temp_I = templine.substr(4, 19);
                // std::cout << temp_I << '\t';
                I = std::stod(temp_I);

                std::string temp_Crc = templine.substr(23, 19);
                // std::cout << temp_Crc << '\t';
                Crc = std::stod(temp_Crc);

                std::string temp_omiga = templine.substr(42, 19);
                // std::cout << temp_omiga << '\t';
                omiga = std::stod(temp_omiga);

                std::string temp_OMIGA_dot = templine.substr(61, 19);
                // std::cout << temp_OMIGA_dot << std::endl;
                OMIGA_dot = std::stod(temp_OMIGA_dot);

                line_block = line_block + 1;
                lines = lines + 1;
                continue;
            }
            if (line_block == 6)
            {
                std::string temp_I_dot = templine.substr(4, 19);
                // std::cout << temp_I_dot << std::endl;
                I_dot = std::stod(temp_I_dot);

               
                line_block = line_block + 1;
                lines = lines + 1;
                continue;
            }
            if (line_block == 7)
            {
                line_block = line_block + 1;
                lines = lines + 1;
                continue;
            }
            if (line_block == 8)
            {
                double t;  //历元差
                double n0; //平均角速度
                n0 = Avarnge_angle_v(sqrtA);
                t = timetramsform(hour, min);

                double M; //平近点角
                M = Caculate_Mean_Anomaly(n0, t, M0_toe, n_delta, toe);

                double E; //偏近点角
                E = Caculate_Ellentric_Anomaly(M, e);

                double f; //真近点角
                f = Caculate_True_Anomaly(E, e);

                double u_privous; //升交角距离
                u_privous = omiga + f;

                double delta_u, delta_r, delta_i; //计算摄动改正项u升交角距，r卫星矢径，i轨道倾角
                delta_u = Caculate_Perturbation_Correction(u_privous, Cuc, Cus);
                delta_r = Caculate_Perturbation_Correction(u_privous, Crc, Crs);
                delta_i = Caculate_Perturbation_Correction(u_privous, Cic, Cis);

                double u, r, i;
                u = Caculate_u(u_privous, delta_u);
                i = Cacluate_i(I, delta_i, I_dot, t, toe);
                r = Cacluate_r(sqrtA, e, E, delta_r);

                double x, y; //计算卫星在轨道面坐标系中的位置
                x = r * cos(u);
                y = r * sin(u);

                double L; //计算大地经度
                L = L_Caculate(OMIGA, OMIGA_dot, constantnumber::omiga_e, t, toe);

                double X, Y, Z; //地球瞬时坐标系下卫星坐标
                X = x * cos(L) - y * cos(i) * sin(L);
                Y = x * sin(L) + y * cos(i) * cos(L);
                Z = y * sin(i);
                std::cout << satellite << '\t'
                          << hour << '\t' //<< t << std::endl
                                          //           << n0 << std::endl
                                          //           << M << std::endl
                                          //           << E << std::endl
                                          //           << f << std::endl
                                          //           << u_privous << std::endl
                                          //           << delta_u << std::endl
                                          //           << delta_r << std::endl
                                          //           << delta_i << std::endl
                                          //           << u << "    " << r << "      " << i << std::endl
                                          //           << L << std::endl
                          << std::setw(19) << std::fixed << std::setprecision(8) << X << '\t'
                          << std::setw(19) << std::fixed << std::setprecision(8) << Y << '\t'
                          << std::setw(19) << std::fixed << std::setprecision(8) << Z << std::endl;
                line_block = line_block + 1;
                lines = lines + 1;
                continue;
            }

            // std::cout<<templine<<std::endl;
        }
    }

    return 0;
}

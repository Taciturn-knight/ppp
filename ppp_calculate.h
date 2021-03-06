﻿#ifndef PPP_CALCULATE_H
#define PPP_CALCULATE_H

#include<QVector>
#include<QString>
#include<Eigen/Eigen>

#include"o_data.h"
#include"sp3_data.h"
#include"clock_data.h"
#include"ppp_data.h"
#include"snx_data.h"
#include"antmod_data.h"
#include"coordinate_system.h"
#include"ocean_date.h"
#include"erp_data.h"

class ppp_calculate
{
public:
    ppp_calculate();
    void ppp_spp(const o_file &ofile,const sp3_file &sp3file,const clock_file &clockfile,const antmod_file &ant,const erp_file &erp_data,ppp_file &ppp);
    void ppp_pretreatment(const o_file &ofile, const antmod_file &ant, const ocean_file &ocean_data);
private:

    void sate_angle(ppp_sate &date);
    void sate_sagnac(ppp_sate &date);
    void sate_relativity(ppp_sate &date);
    void sate_troposphere(ppp_sate &date,int doy);
    void receiver_antenna(ppp_sate &date);
    void satellite_antenna(ppp_sate &date, const satellite_antmod &sate_ant, const XYZ_coordinate &sunPostion);
    void satellite_windup(ppp_sate &date,const satellite_antmod &sate_ant, const XYZ_coordinate &sunPostion);
    void satellite_tide(ppp_sate &data, const Eigen::Vector3d &tide);
    int satellite_antenna_info(satellite_antmod &sate_ant, const antmod_file &ant);
    void satellite_ionized(ppp_sate &date);
    double station_x;
    double station_y;
    double station_z;
    double station_B;
    double station_L;
    double station_H;
    double antenna_E;
    double antenna_N;
    double antenna_H;
    station_antmod station_ant;
    ocean station_ocean;
    const static double c;
    const static double w; //sagnac
    const static double u; //relativity
    const static double Pi;

    /*UNB3参数-------------------------------------------------------------------*/
    const static double UNB3_average[5][6];
    const static double UNB3_amplitude[5][6];
    const static double Neil_wet_average[5][4];
    const static double R;
    const static double k1;
    const static double k2;
    const static double k3;
    /*--------------------------------------------------------------------------*/
    const static double Neil_hyd_average[5][4];
    const static double Neil_hyd_amplitude[5][4];
    /*--------------------------------------------------------------------------*/

    /*GPS载波频率(Hz)------------------------------------------------------------*/
    const static double f1;
    const static double f2;
    const static double f5;
    /*GPS载波的波长--------------------------------------------------------------*/
    const static double lambda1;
    const static double lambda2;
    /*天线相位偏差的预报偏差-------------------------------------------------------*/
    static double satellite_phase[40];
    static double station_phase[40];

};

#endif // PPP_CALCULATE_H

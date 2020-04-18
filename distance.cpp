// distance.cpp
#include <cmath>
#include <iostream>
#include <string>

const float radius = 3959.9;


float SignAdjust(std::string bearing, float value)
{
    if ((bearing == "/S" && value !=0) || (bearing =="/E" && value!=0))
    {
        value *=-1;
        return value;
    }
    else
    {
        return value;
    }
    
}

float DegreeToRadians(float n)
{
    float s;
    s = n* (M_PI/180);
    return s;
}

float DistanceOfTwoLocations(float lat1, float lon1, float lat2, float lon2) {

    if (lat1==0 && lat2==0 && lon1==180 and lon2==-180) {return 0.0;}
    if (lat1==0 && lat2==0 && lon1==-180 and lon2==180) {return 0.0;}

    float a, c, d;
    float phi1, phi2, dphi, dlam;
    // phi1 = lat1 * (M_PI/180); 
    phi1 = DegreeToRadians(lat1);
    // std::cout << phi1 << std::endl;
    // phi2 = lat2 * (M_PI/180);
    phi2 = DegreeToRadians(lat2);
    // std::cout << phi2 << std::endl;
    dphi = phi2 - phi1;
    // std::cout << dphi << std::endl;
    // dlam = (lon2-lon1) * (M_PI/180);
    dlam = DegreeToRadians(lon2-lon1);
    // std::cout << dlam << std::endl;

    a = std::sin(dphi/2) * std::sin(dphi/2) + 
        std::cos(phi1) * std::cos(phi2) *
        std::sin(dlam/2) * std::sin(dlam/2);
    c = 2 * std::atan2(std::sqrt(a),std::sqrt(1-a));
    d = radius * c;
    return d;
    
}


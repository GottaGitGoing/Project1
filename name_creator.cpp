// name_creator.cpp
#include <string>
#include <iostream>

std::string CreateLocName(float lat, std::string ns, float lon, std::string ew,std::string name)
{
    // float sign_adjusted_lat;
    if (lat<0) 
    {
        lat *= -1.0;
    }
    if (lon <0)
    {
        lon *= -1.0;
    } 
    std::string full_info;
    full_info = std::to_string(lat) + ns + " " + std::to_string(lon)
              + ew + " ("+name+")";
    return full_info;
}


int CreateOutputResult(std::string start,std::string min,std::string max,
                        float min_dis, float max_dis)
{
    std::cout << "Start Location: " << start << std::endl;
    std::cout << "Closest Location: " << min << " (" << std::to_string(min_dis) << " miles)" << std::endl;
    std::cout << "Farthest Location: " << max << " (" << std::to_string(max_dis) << " miles)" << std::endl;
    
    return 0;
}
#include <iostream>
#include "distance.hpp"
#include "name_creator.hpp"




int StartLoop()
{
    // Neccessary Declarations For the Code.
    int target;
    int i=0;
    float start_lat;
    float start_lon;
    float distance;
    float min,max;
    float dest_lat, dest_lon;
    std::string start_ns;
    std::string start_ew;
    std::string start_name;
    std::string dest_ns,dest_ew,dest_name;
    std::string min_name, max_name;


    // Parse the start information from the input buffer
    std::cin >> start_lat >> start_ns >> start_lon >> start_ew;
    std::cin.ignore(1); 
    std::getline(std::cin,start_name);

    // sign adjust, if East or South, to negative
    start_lat = SignAdjust(start_ns, start_lat);
    start_lon = SignAdjust(start_ew, start_lon);

    
    
    min = max = 0;
    std::cin >> target;
    std::cin.ignore(1);
    
    
    while (target != 0)
    {
        // Asks for Destination Information
        std::cin >> dest_lat >> dest_ns >> dest_lon >> dest_ew;
        std::cin.ignore(1); // Just added ----------------------------------
        std::getline(std::cin,dest_name);

        // sign adjust if East or South to negative
        dest_lat = SignAdjust(dest_ns, dest_lat);
        dest_lon = SignAdjust(dest_ew, dest_lon);


        // Users haversine to calculate the distance        
        distance = DistanceOfTwoLocations(start_lat,start_lon,dest_lat,dest_lon);
        if (distance >= max)
        {
            if (i==0) 
            {
                // neccessary for the first loop or cases where user only enters 1 location
                min = max = distance;
                min_name = max_name = CreateLocName(dest_lat,dest_ns,dest_lon,dest_ew,dest_name);
                i++;
            }
            else
            {
                // sets max, and will create full location Nametag
                max = distance;
                max_name = CreateLocName(dest_lat,dest_ns,dest_lon,dest_ew,dest_name);
            }
        }
        else
        { 
            // sets min, and create full location Nametag
            min = distance;
            min_name = CreateLocName(dest_lat,dest_ns,dest_lon,dest_ew,dest_name);
        }
        
        target--; 
    }
   
    // Prepares start_location's full name creates the final name output
    std::string start_full = CreateLocName(start_lat,start_ns, start_lon,start_ew,start_name);
    CreateOutputResult(start_full,min_name,max_name,min,max);

    return 0;
}
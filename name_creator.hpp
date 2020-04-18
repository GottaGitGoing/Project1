// name creator hpp

#ifndef NAME_CREATOR_HPP
#define NAME_CREATOR_HPP


std::string CreateLocName(float lat, std::string ns, float lon, std::string ew,
                          std::string name);


int CreateOutputResult(std::string start,std::string min,std::string max,
                        float min_dis, float max_dis);


#endif


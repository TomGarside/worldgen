//
//  worldgen.h
//  worldgen
//
//  Created by tom garside on 10/10/18.
//  Copyright © 2018 tom garside. All rights reserved.
//  extensible world builder using json
//

#ifndef worldgen_h
#define worldgen_h
#include world.h
#include json11.hpp

class gen_world{
    
private:
    world Game_world;
    
    json11::json parameterJson;
    
    //constructor loads parameter json and initializes building process
    gen_world(json11::json params){
        parameterJson = json;
    }
    
    //all data is based on a json file some required others are optional eg extra fields can be added and they will not
    // affect generation eg descriptions of stars cities etc from tweakable parameter json
    
    
    //based on a simplified model of stars stored in a json object
    json11::json gen_star(json11::json);
    
    //will affect environmental conditions
    int gen_distance_from_star(string star);
    
    //based on a sampe of known panets (inc  exo planets if possible)
    int gen_planet_mass();

    //calculate the regions tropical tundra etc based on latitude and distance from star
    json11::json CalcEnvironmentRegions(int);
    
    //generate the percentage not covered by ocean geerate within bounds that will make it similar to earth
    //maybe load a json with parameters
    int calcPercentageLandmass();
    
    //json object describing each continnent (rough draw planes on globe? elevations and coastlines can be generated)
    json11::json genContinents(json11::json);
    
    //place mountian ranges (random draw lines on globe spliting procedurally then gen elevations)
    json!!::json genMountains(json11::json);
    
    //place rivers similar to mountain ranges can use similar algo and select starting points based on elevation
    json!!::json genRiversAndLakes(json11::json)
    
    
public:
    string gen_world();
    
    string chooseRandItem(json11::json);
    
}
#endif /* worldgen_h */

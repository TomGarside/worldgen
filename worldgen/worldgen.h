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
#include "json11.hpp"
#include "stdio.h"
#include <iostream>
#include <random>

class gen_world{

private:
    
    json11::Json inputJson;
    
    
    std::string error;

    //generates output object
    void generate_world();
    
    json11::Json chooseRandItem(json11::Json);
    
public:
    json11::Json::object outputJson;
    
    //constructor loads input str initializes building process and sets seed for random gen
    gen_world(std::string inputJsonStr, int seed = int(time(NULL))){
        srand(seed);
        inputJson = json11::Json::parse(inputJsonStr, error);
        gen_world::generate_world();
    }
    
    json11::Json getOutput();
    
    std::string geterr();
    
};
#endif /* worldgen_h */

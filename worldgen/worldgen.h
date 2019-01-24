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

class gen_world{
    
    
    
private:
    
    json11::Json inputJson;
    
    json11::Json outputJson;
    
    std::string error;
    
 
    //generates output object
    void generate_world();
    
    json11::Json chooseRandItem(json11::Json);
    
public:
    //constructor loads input str initializes building process
    gen_world(std::string inputJsonStr){
        inputJson = json11::Json::parse(inputJsonStr, error);
        gen_world::generate_world();
    }
    
    json11::Json getOutput();
    
    std::string geterr();
    
 
    
};
#endif /* worldgen_h */

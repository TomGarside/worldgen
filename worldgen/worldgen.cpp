//
//  worldgen.cpp
//  worldgen
//
//  Created by tom garside on 23/1/19.
//  Copyright © 2019 tom garside. All rights reserved.
//


#include "worldgen.h"

json11::Json gen_world::getOutput(){
    return gen_world::outputJson;
}

std::string gen_world::geterr(){
    return gen_world::error;
}

void gen_world::generate_world(){
    
    std::map<std::string,json11::Json> topLevel = inputJson.object_items();
        
    for( auto const& pair : topLevel ){
        std::cout<<pair.first<<std::endl;
        
    }
    
    
    
    
    gen_world::outputJson = gen_world::inputJson;
}



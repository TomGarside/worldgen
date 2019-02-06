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

//add seed for real random
json11::Json gen_world::chooseRandItem(json11::Json inputProbmap){
    json11::Json outResult;
    int probTotal = 100;
    int randInt = rand() % 100;
    std::cout<<randInt<<std::endl;
    
    for (auto const& items: inputProbmap.array_items()){
        json11::Json item = items.object_items();
        int prob = item["prob"].int_value();
        if( randInt > (probTotal - prob)){
            //std::cout<<item["name"].string_value()<<std::endl;
            outResult = item;
            break;
        }
        probTotal = probTotal - prob;
        
    }
    
    return outResult;
}

void gen_world::generate_world(){
    
    // iterate through all of th high level items
    std::map<std::string,json11::Json> topLevel = inputJson.object_items();
    for( auto const& pair : topLevel ){
       
        std::string defaultVal = pair.second["default"].string_value();
        std::vector<json11::Json> dependentList = pair.second["dependent"].array_items();
        json11::Json localProbmap;
        
        //if dependent list is populated then see if any of the variables are in current output
        // if so then select related probability map
        if(dependentList.size()>0){
            for(int i =0; i<dependentList.size();i++){
                if(gen_world::outputJson.count(dependentList[i].string_value()) > 0){
                    localProbmap = pair.second[dependentList[i].string_value()];
                    break;
                }
            }
        }
        // else select default prob map
        std::cout<<json11::Json(gen_world::outputJson).dump()<<std::endl;
        if(localProbmap.is_null())
            localProbmap = pair.second[defaultVal];
        
        json11::Json result;
        result = gen_world::chooseRandItem(localProbmap);
        outputJson[result["name"].string_value()] = result["misc"];
        
    }
}

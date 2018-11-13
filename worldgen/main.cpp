//
//  main.cpp
//  worldgen
//
//  Created by tom garside on 10/10/18.
//  Copyright © 2018 tom garside. All rights reserved.
//

#include <iostream>
#include "json11.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    json11::Json my_json = json11::Json::object {
        { "key1", "value1" },
        { "key2", false },
        { "key3", json11::Json::array { 1, 2, 3 } },
    };
    
    std::cout<<my_json.dump()<<std::endl;
    
    return 0;
}

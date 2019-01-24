//
//  main.cpp
//  worldgen
//
//  Created by tom garside on 10/10/18.
//  Copyright © 2018 tom garside. All rights reserved.
//

#include <iostream>
#include "json11.hpp"
#include "worldgen.h"
#include <string>
#include <sstream>
#include <fstream>





int main(int argc, const char * argv[]) {

    std::ifstream inFile;
    inFile.open("/Users/tom_garside/Dropbox/worldgen/worldgen/Text.json");//open the input file
    std::stringstream strStream;
    strStream << inFile.rdbuf();//read the file
    std::string str = strStream.str();//str holds the content of the file
    
    gen_world generator = *new gen_world(str);
    
    //std::cout<<generator.getOutput().dump()<<" "<<generator.geterr()<<std::endl;
   
   
    return 0;
}

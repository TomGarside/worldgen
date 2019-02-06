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
#include <unistd.h>
#include <iostream>

int main(int argc,char* const argv[]) {
    
    std::ifstream inFile;
    unsigned seed = unsigned(time(NULL)); // random seed for generation
    int arg;
    std::string outfilename = "";
    
    const char * args = "s:f:o:";
    while ((arg = getopt(argc, argv, args)) != -1) {
        switch (arg) {
            case 's':
                std::cout<<"seed is :"<<optarg<<std::endl; // user specified seed
                seed = atoi(optarg);
                break;
            case 'f':
                std::cout<<"opening file :"<<optarg<<std::endl; // file path
                inFile.open(optarg);
                break;
            case 'o':
                outfilename = optarg;
                
                break;
                
            default:
                break;
        }
    }

    
    if(!inFile.is_open()){ // validate that a file was provided
        std::cout<<"no file provided"<<std::endl;
        return 0;
    }
    std::stringstream strStream;
    strStream << inFile.rdbuf(); //read the file
    std::string str = strStream.str(); //str holds the content of the file
    
    gen_world generator = *new gen_world(str,seed);
    
    std::cout<<generator.getOutput().dump()<<" "<<generator.geterr()<<std::endl;
    
    if(outfilename!= ""){
        std::ofstream outfile;
        outfile.open(outfilename);
        outfile<<generator.getOutput().dump();
    }
   
    return 0;
}

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
    bool debug = false;
    bool print = false;
    std::string outfilename = "";
    
    const char * args = "s:f:o:dp";
    while ((arg = getopt(argc, argv, args)) != -1) {
        switch (arg) {
            case 's':
                seed = atoi(optarg);
                break;
            case 'f':
                inFile.open(optarg);
                break;
            case 'o':
                outfilename = optarg;
                break;
            case 'd':
                debug = true;
                break;
            case 'p':
                print = true;
                break;
                
            default:
                break;
        }
    }

    
    if(!inFile.is_open()){ // validate that a file was provided
        std::cout<<"no file provided"<<std::endl;
        return 0;
    }
    if (debug){
        std::cout<<"opening file :"<<optarg<<std::endl; // file path
        std::cout<<"seed is :"<<seed<<std::endl; // user specified seed
    }
    
    std::stringstream strStream;
    strStream << inFile.rdbuf(); //read the file
    std::string str = strStream.str(); //str holds the content of the file
    
    gen_world generator = *new gen_world(str,seed);
    if (print)
        std::cout<<generator.getOutput().dump()<<" "<<generator.geterr()<<std::endl;
    
    if(outfilename!= ""){
        std::ofstream outfile;
        outfile.open(outfilename);
        outfile<<generator.getOutput().dump();
    }
    std::cout<<generator.outputJson["Group1"]["name"].string_value()+" are "+generator.outputJson["Working"]["name"].string_value()+" "+generator.outputJson["Group2"]["name"].string_value()+" to "+generator.outputJson["Action"]["name"].string_value()+" in order to "+generator.outputJson["Goal"]["name"].string_value()+"!"<<std::endl;
    return 0;
}

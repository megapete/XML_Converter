//
//  main.cpp
//  XML_Converter
//
//  Created by Peter Huber on 2019-12-11.
//  Copyright © 2019 Peter Huber. All rights reserved.
//



#include "ImpModel.hpp"




int main(int argc, const char * argv[])
{
    
    ImpModel testXML;
    
    testXML.InitializeWith("/Users/peterhuber/Google Drive (huberistech@gmail.com)/Design Stuff/ImpulseSimulationProgramFIles/ImpulseSimulationDesignXML.impmdl");

    return 0;
}

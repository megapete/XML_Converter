//
//  ImpModel.hpp
//  XML_Converter
//
//  Created by Peter Huber on 2019-12-11.
//  Copyright © 2019 Peter Huber. All rights reserved.
//

#ifndef ImpModel_hpp
#define ImpModel_hpp

#include <stdio.h>
#include "CoilSectionData.hpp"
#include "Phase.hpp"

#include <string>
#include <vector>

struct ImpModel
{
    typedef enum pch_Units
    {
        inches = 0,
        mm = 1,
        meters = 2
        
    } Units;
    
    Phase phase;
    Units units;
    CoilSection *model;
    
    // constructors & destructors
    ImpModel();
    ~ImpModel();
    
    std::vector<std::string> testKeys;
    
    // Method to initialize a model from a Mac-created XML file (ie: created using NSKeyedArchiver)
    bool InitializeWith(const std::string &fileName);
    
};

#endif /* ImpModel_hpp */

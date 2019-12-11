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
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>

struct ImpModel
{
    typedef enum pch_Units
    {
        inches = 0,
        mm = 1,
        meters = 2
        
    } Units;
    
    Units units;
    CoilSection *model;
    
};

#endif /* ImpModel_hpp */

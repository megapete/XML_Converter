//
//  Phase.hpp
//  XML_Converter
//
//  Created by Peter Huber on 2019-12-11.
//  Copyright © 2019 Peter Huber. All rights reserved.
//

#ifndef Phase_hpp
#define Phase_hpp

#include <stdio.h>
#include "Coil.hpp"
#include "Core.hpp"

struct Phase
{
    Core core;
    Coil *coils;
};

#endif /* Phase_hpp */

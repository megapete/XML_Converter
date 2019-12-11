//
//  ImpModel.cpp
//  XML_Converter
//
//  Created by Peter Huber on 2019-12-11.
//  Copyright © 2019 Peter Huber. All rights reserved.
//

#include "ImpModel.hpp"

#include "PCH_C_Logging.h"

ImpModel::ImpModel()
{
    this->model = NULL;
}

ImpModel::~ImpModel()
{
    if (this->model != NULL)
    {
        delete[] model;
    }
}

bool ImpModel::InitializeWith(const std::string &fileName)
{
    
    
    return true;
}

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

#include <cstddef>
#include <cassert>
#define RAPIDXML_NO_STDLIB
#define RAPIDXML_NO_EXCEPTIONS
#include "rapidxml.hpp"

/*
#if defined(RAPIDXML_NO_EXCEPTIONS)
void rapidxml::parse_error_handler(const char* what, void* where) {
    printf("Parse error(@%p): %s\n", where, what);
    std::abort();
}
#endif
 */

#include <string>
#include <vector>
#include <fstream>
#include <cerrno>
#include <cstdint>

struct ImpModel
{
public:
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
    bool InitializeWith(const std::string &filePath);
    
private:
    std::string GetFileContents(std::string filePath);
    void EvaluateNode(const rapidxml::xml_node<>* node);
};

#endif /* ImpModel_hpp */

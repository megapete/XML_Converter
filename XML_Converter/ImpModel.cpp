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

bool ImpModel::InitializeWith(const std::string &filePath)
{
    std::string fileString = GetFileContents(filePath);
    
    enum
    {
        PARSE_FLAGS = rapidxml::parse_non_destructive
    };

    // NOTE : the cons_cast<char*> thing is required or the compiler doesn't recognize the function.
    rapidxml::xml_document<> xmlDoc;
    xmlDoc.parse<PARSE_FLAGS>(const_cast<char*>(fileString.c_str()));
    // xmlDoc.parse<PARSE_FLAGS>(fileString.c_str());
    // walk(xmlDoc.first_node());
    
    return true;
}

void ImpModel::EvaluateNode(const rapidxml::xml_node<>* node)
{
    const rapidxml::node_type t = node->type();
    
    switch(t) {
    case rapidxml::node_element:
        {
            printf("<%.*s", (int)node->name_size(), node->name());
            for(const rapidxml::xml_attribute<>* a = node->first_attribute()
                ; a
                ; a = a->next_attribute()
            ) {
                printf(" %.*s", (int)a->name_size(), a->name());
                printf("='%.*s'", (int)a->value_size(), a->value());
            }
            printf(">\n");

            for(const rapidxml::xml_node<>* n = node->first_node()
                ; n
                ; n = n->next_sibling()
            ) {
                walk(n, indent+1);
            }
            printf("%s</%.*s>\n", ind.c_str(), (int)node->name_size(), node->name());
        }
        break;

    case rapidxml::node_data:
        printf("DATA:[%.*s]\n", (int)node->value_size(), node->value());
        break;

    default:
        printf("NODE-TYPE:%d\n", t);
        break;
    }
}


std::string ImpModel::GetFileContents(std::string filePath)
{
    // This is the "C++ Method" from http://insanecoding.blogspot.com/2011/11/how-to-read-in-file-in-c.html
    std::ifstream in(filePath.c_str(), std::ios::in | std::ios::binary);
    if (in)
    {
      std::string contents;
      in.seekg(0, std::ios::end);
      contents.resize(in.tellg());
      in.seekg(0, std::ios::beg);
      in.read(&contents[0], contents.size());
      in.close();
      return(contents);
    }
    throw(errno);
    
}

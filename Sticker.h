#pragma once

#include <string>
#include "Category.h"

using std::string;

class Sticker
{
private:

    int number;
    string name;

    Category* category;

    int appearances;

public:

    Sticker(Category* category, int number, string name)
    {
        this->category = category;
        this->number = number;
        this->name = name;

        this->appearances = 0;
    }

    int get_number()
    {
        return this->number;
    }

    string get_code()
    {
        return category->get_code() + std::to_string(this->number);
    }

    string get_name()
    {
        return this->name;
    }

    Category* get_category() {
        return this->category;
    }

    void mark() {
        this->appearances++;
        
    }

    void unmark() {
        if (appearances == 0)
        {
            appearances == 0;
        }
        else
        {
            this->appearances--;
        }
    }

    string is_marked() {
        if(appearances >0)
        {
            return "verdadero";
        }
        else
        {
            return "falso";
        }
    }

    bool is_repeated() {
        return this->appearances >1;
    }

    int get_appeareances() {
        return this->appearances;
    }

    int get_repeat() {
        if (appearances == 0)
        {
            return 0;
        }
        return appearances - 1;
    }
};
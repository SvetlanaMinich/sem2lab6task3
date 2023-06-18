#pragma once
#ifndef SPLITHTABLE_H
#define SPLITHTABLE_H
#include "htable.h"

class SplitHTable:public HTable<int>
{
public:
    void splitKeys(HTable<int>& one, HTable<int>& two);
};

#endif // SPLITHTABLE_H

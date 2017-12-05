//
// Created by dasch on 04.12.2017.
//

#ifndef CALCULATOR_TREEBUILD_H
#define CALCULATOR_TREEBUILD_H

#include <assert.h>
#include <math.h>
#include <ctype.h>
#include "tree.h"

struct Tree *Tree_Build(char *thing);
struct Leaf *GetG0(char *what);
struct Leaf *Get_E();
struct Leaf *Get_T();
struct Leaf *Get_S();
struct Leaf *Get_P();
struct Leaf *Get_N();

#endif //CALCULATOR_TREEBUILD_H

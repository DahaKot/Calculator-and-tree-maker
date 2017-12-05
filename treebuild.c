//
// Created by dasch on 04.12.2017.
//
#include "treebuild.h"

char *s = NULL;
size_t p = 0;

struct Tree *Tree_Build(char *thing) {
    struct Tree *new_one = Tree_Construct(thing);
    new_one->root = GetG0(thing);
    Tree_SParameters_Set(new_one);

    Human_Dump(new_one);
    Tree_Dump(new_one, __LINE__);

    return new_one;
}

struct Leaf *GetG0(char *what) {
    s = what;
    p = 0;
    struct Leaf *val = Get_E();
    assert(s[p] == '\0');
    return val;
}

struct Leaf *Get_E() {
    struct Leaf *left = Get_T();
    struct Leaf *root = left;
    while(s[p] == '+' || s[p] == '-') {
        int op = s[p] == '+' ? 1 : (-1);
        p++;
        struct Leaf *right = Get_T();
        struct Leaf *new = Leaf_Construct(op == 1 ? "+" : "-");
        new->left = root;
        new->right = right;
        root = new;
    }
    return root;
}

struct Leaf *Get_T() {
    struct Leaf *left = Get_S();
    struct Leaf *root = left;
    while (s[p] == '*' || s[p] == '/') {
        int op = s[p];
        p++;
        struct Leaf *right = Get_S();
        struct Leaf *new = Leaf_Construct(op == '*' ? "*" : "/");
        new->left = root;
        new->right = right;
        root = new;
    }
    return root;
}

struct Leaf *Get_S() {
    struct Leaf *left = Get_P();
    struct Leaf *root = left;
    while (s[p] == '^') {
        p++;
        struct Leaf *right = Get_S();
        struct Leaf *new = Leaf_Construct("^");
        new->left = root;
        new->right = right;
        root = new;
    }
    return root;
}

struct Leaf *Get_P() {
    if (s[p] == '(') {
        p++;
        struct Leaf *root = Get_E();
        assert(s[p] == ')');
        p++;
        return root;
    }
    else {
        return Get_N();
    }
}

struct Leaf *Get_N() {
    if (isdigit(s[p])) {
        double val = 0;
        char *end_ptr = s+p;
        val = strtod(s+p, &end_ptr);
        p += (end_ptr - (s+p));
        return Leaf_Construct_N(val);
    }
    else {
        char *c = calloc(1, sizeof(char));
        strncpy(c, s+p, 1);
        p++;
        return Leaf_Construct(c);
    }
}
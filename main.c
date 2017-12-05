#include <stdio.h>
#include <stdlib.h>
#include "treebuild.h"

/*double Get_G0(char *what);
double GetE();
double GetT();
double GetS();
double GetP();
double GetN();

char *s = NULL;
size_t p = 0;

double Calculate(char *thing) {
    return Get_G0(thing);
}

double Get_G0(char *what) {
    s = what;
    p = 0;
    double val = GetE();
    assert(s[p] == '\0');
    return val;
}

double GetE() {
    double val = GetT();
    while(s[p] == '+' || s[p] == '-') {
        int op = s[p] == '+' ? 1 : (-1);
        p++;
        double val2 = GetT();
        val += val2*op;
    }
    return val;
}

double GetT() {
    double val = GetS();
    while (s[p] == '*' || s[p] == '/') {
        int op = s[p];
        p++;
        double val2 = GetS();
        val = (op == '*') ? val*val2 : val/val2;
    }
    return val;
}

double GetS() {
    double val = GetP();
    while (s[p] == '^') {
        p++;
        double val2 = GetP();
        val = pow(val, val2);
    }
    return val;
}

double GetP() {
    if (s[p] == '(') {
        p++;
        double val = GetE();
        assert(s[p] == ')');
        p++;
        return val;
    }
    else {
        return GetN();
    }
}

double GetN() {
    double val = 0;
    char *end_ptr = s+p;
    val = strtod(s+p, &end_ptr);
    p += (end_ptr - (s+p));
    return val;
}*/
//Альфред, Уйман. Теория иснтаксического анализа и компиляции
// книжка, в первой главе разобраны множества, т. конечных автоматов, лексический анализ
int main() {
    char *string = calloc(1024, sizeof(char));
    scanf("%s", string);
    //printf("%lg\n", Calculate(string));

    Tree_Build(string);

    free(string);

    return 0;
}
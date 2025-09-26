#ifndef GENERIC_H
#define GENERIC_H

union generic {
    int intValue;
    char charValue;
    float floatValue;
    double doubleValue;
};

union generic createGeneric(int type, void* value);

#endif
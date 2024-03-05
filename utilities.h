#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

std::string convertToChessNotation(int x, int y);
bool convertFromChessNotation(const std::string& notation, int& x, int& y);

#endif

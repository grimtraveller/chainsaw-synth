/*
 * util.cpp
 *
 *  Created on: Nov 14, 2010
 *      Author: suva
 */

#include <util.h>
#include <math.h>

double linToLog(double v) {
        return 1 - log10((1 - v) * 9.0 + 1.0);
}

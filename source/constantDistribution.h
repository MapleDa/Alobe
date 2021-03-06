#ifndef __ALOBE__CONSTANT_DISTRIBUTION__
#define __ALOBE__CONSTANT_DISTRIBUTION__

#include "tabulatedDistribution.h"

/**
 * Constant distribution
 * Inherits GeneratedDistribution
 *
 * An exponential distribution
 */
class ConstantDistribution: public TabulatedDistribution
{
    public:
        ConstantDistribution(float probability);
};

#endif // __ALOBE__CONSTANT_DISTRIBUTION__

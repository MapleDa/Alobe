#ifndef __ALOBE__TILE__
#define __ALOBE__TILE__

#include <iostream>
#include <map>
#include <string>

#include "configuration.h"
#include "actor.h"
#include "being.h"

using namespace std;

/**
 * Tile
 * Inherits Actor
 *
 * Tile in the simulation
 */
class Tile: public Actor
{
    public:
        Tile(unique_ptr<Graphics> graphics);
        vector<Being *> getBeings() const;     // Getter for the beings
        unsigned long getBeingsNumber() const; // Retrieve the number of beings
        void attachBeing(Being * being);       // Attach a being
        bool detachBeing(Being * being);       // Detach a being
        void applyChanges(Stepper & stepper);  // Apply changes after a step
        void trace();                          // Trace the tile

    private:
        unsigned long smoothedMove(
            unsigned long position,
            long long speed,
            unsigned long minimum,
            unsigned long maximum,
            float turnover
        ) const;                               // Smoothed move next step
        vector<Being *> my_beings;
        vector<Being *> mod_beings;
};

#endif // __ALOBE__TILE__

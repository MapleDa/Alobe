#ifndef __ALOBE__BEING__
#define __ALOBE__BEING__

#include <string>
#include <map>
#include <memory>
#include <vector>
#include <stdlib.h>

#include "actor.h"
#include "chromosome.h"
#include "state.h"

class Tile;

using namespace std;

/**
 * Being
 * Inherits Actor
 *
 * A being in the simulation
 */
class Being : public Actor
{
    public:
        Being(string name, vector<shared_ptr<Chromosome> > chromosomes);
        string getName() const;                                                 // Getter for the being name
        vector<Being *> getParents() const;                                     // Getter for the being parents
        vector<Being *> getChildren() const;                                    // Getter for the being children
        vector< shared_ptr<Chromosome> > getChromosomes() const;				// Getter for the being chromosomes
        void addChromosome(shared_ptr<Chromosome> chromsome);                   // Add a chromosome
        void addState(unique_ptr<State> state);                                 // Add a state
        void removeState(State & state);                                        // Remove a state by reference
        void removeState(string stateId);                                       // Remove a state by id
        bool isDead();                                                          // Is the being dead?
        void applyChanges(Stepper & stepper);                                   // Apply changes after a step
        string migrate(map<string, Tile *> neighboringTiles);                   // Generate the being migration
                                                                                // 5 neighboring tiles are expected,
                                                                                // with keys "north", "south", "east", "west" and "here"
		vector<shared_ptr<Chromosome> > setChildChromosomes(Being & mate);		// Create a genome for a potential child
		bool isReadyToMate(Being & mate);                                       // Test if being will mate with an other being
		vector<shared_ptr<Chromosome> > getBeingHalfChromosomes() const;		// Getter for half of the genome

    private:
        string my_name;
        vector<shared_ptr<Chromosome> > my_chromosomes;
        map<string, unique_ptr<State> > my_states;
        vector<Being *> my_parents;
        vector<Being *> my_children;

	//shared_ptr<Being> mate(Being &partner, string name);
};

#endif // __ALOBE__BEING__

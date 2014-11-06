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
#include "behaviour.h"

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
        string getName() const;                                          // Getter for the being name
        vector< shared_ptr<Chromosome> > getChromosomes() const;	     // Getter for the being chromosomes

        bool isDead(); // Is the being dead?
        void kill();   // Kill the being

        shared_ptr<Behaviour> getBehaviour(string behaviourName);                 // Getter for a behaviour
        void addBehaviour(string behaviourName, shared_ptr<Behaviour> behaviour); // Add a behaviour

        State * getState(string stateName);                       // Getter for a state
        bool hasState(string stateName) const;                    // Is the state defined for the being ?
        void addState(string stateName, unique_ptr<State> state); // Add a state
        void removeState(string stateName);                       // Remove a state by id

        vector<Being *> getParents() const; // Getter for the being parents
        void addParent(Being & parent);     // Add a parent

        vector<Being *> getChildren() const; // Getter for the being children
        void addChild(Being & child);        // Add a child

        void applyChanges(Stepper & stepper); // Apply changes after a step

		//vector<shared_ptr<Chromosome> > setChildChromosomes(Being & mate); // Create a genome for a potential child
		//bool isReadyToMate(Being & mate);                                  // Test if being will mate with an other being
		//vector<shared_ptr<Chromosome> > getBeingHalfChromosomes() const;	 // Getter for half of the genome

    private:
        string my_name;
        vector<shared_ptr<Chromosome> > my_chromosomes;
        bool my_dead;
        map<string, shared_ptr<Behaviour> > my_behaviours;
        map<string, unique_ptr<State> > my_states;
        vector<Being *> my_parents;
        vector<Being *> my_children;
};

#endif // __ALOBE__BEING__

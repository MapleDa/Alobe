#include <iostream>
#include <map>
#include <memory>

#include "simulation.h"
#include "stepper.h"
#include "land.h"
#include "being.h"
#include "normal_law.h"
#include "migrationEvent.h"

using namespace std;

int main()
{
    // Set seed for random methods
    // Should be added to proba somehow
    srand(static_cast<unsigned int>(time(NULL)));
    
    // normal law test
    Normal_law norm(5.0, 2.0);
    norm.sample(1000);
    cout << norm.map_to_string();

    // Test simulation, stepper, actors
    unique_ptr<Simulation> simulation = make_unique<Simulation>();
    cout
        << "Created a "
        << simulation->getLand()->getWidth()
        << " by "
        << simulation->getLand()->getHeight()
        << " land. ("
        << simulation->getLand()->getTilesNumber()
        << " tiles)"
    << endl;

    simulation->getPopulation()->randomBeing();
    simulation->getPopulation()->randomBeing();
    simulation->getPopulation()->randomBeing();
    simulation->getPopulation()->randomBeing();

    // migrationEvent test
    simulation->getLand()->attachEvent(make_shared<MigrationEvent>());

    // apply changes before start (should be called in a larger "init simulation" method
    // will be implemented with conf file reader
    simulation->getPopulation()->applyChanges(*(simulation->getStepper()));
    simulation->getLand()->applyChanges(*(simulation->getStepper()));

    // Print beings positions before simulation
    for (unsigned long x = 0; x < simulation->getLand()->getWidth(); ++x) {
        for (unsigned long y = 0; y < simulation->getLand()->getHeight(); ++y) {

            unsigned long beingsNumber = simulation->getLand()->getTile(x, y)->getBeingsNumber();

            if (beingsNumber > 0) {

                string designator = "being";
                if (beingsNumber > 1) {
                    designator = "beings";
                }

                cout
                    << beingsNumber
                    << " "
                    << designator
                    << " on tile ("
                    << x
                    << ", "
                    << y
                    << ")"
                << endl;
            }
        }
    }

	simulation->toStep(10);

    // Print beings positions after simulation
    for (unsigned long x = 0; x < simulation->getLand()->getWidth(); ++x) {
        for (unsigned long y = 0; y < simulation->getLand()->getHeight(); ++y) {

            unsigned long beingsNumber = simulation->getLand()->getTile(x, y)->getBeingsNumber();

            if (beingsNumber > 0) {

                string designator = "being";
                if (beingsNumber > 1) {
                    designator = "beings";
                }

                cout
                    << beingsNumber
                    << " "
                    << designator
                    << " on tile ("
                    << x
                    << ", "
                    << y
                    << ")"
                << endl;
            }
        }
    }

	return 0;
}
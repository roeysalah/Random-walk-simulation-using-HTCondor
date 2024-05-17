#ifndef HEADER_H_
#define HEADER_H_

#include <stdbool.h>

// Define the structure of a particle
typedef struct particle {
    float x; // x-axis 
    float y; // y-axis 
}particle_t;

// Function to create a new particle and return its pointer
particle_t *generate_particle();

// Function to initialize an experiment with particles
particle_t **init_experiment();

// Function to release memory allocated for the experiment
void release_experiment(particle_t **experiment);

// Function to perform a step of the experiment
void perform_step(particle_t **experiment, int* counter);

// Function to move an individual particle as part of one step
bool move_individual(particle_t* part);

#endif /* HEADER_H_ */


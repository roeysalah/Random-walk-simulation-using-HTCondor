#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Main function
int main(int argc, char** argv) {
    int counter = 0; // Counter to track the number of particles that have reached the end
    float stopping_point = 0.8f; // Stopping point for the experiment
    if (argc < 2) { // Check if job number is provided
        fprintf(stderr, "Enter  The job number\n");
        return 1;
    }
    srand((unsigned int)atoi(argv[1])); // Seed the random number generator
    struct particle **experiment = init_experiment(); // Initialize the experiment
    if (experiment == NULL) { // Check if experiment initialization was successful
        return 1;
    }

    // Perform the experiment until the stopping point is reached
    while (counter < 10000 *stopping_point) {
        perform_step(experiment, &counter); // Perform a step of the experiment
    }
    release_experiment(experiment); // Release memory allocated for the experiment
    return 0;
}

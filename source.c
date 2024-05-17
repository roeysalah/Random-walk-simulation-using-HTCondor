#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"


// Function to generate a new particle
particle_t* generate_particle() {
    particle_t* new_particle = (particle_t*)malloc(sizeof(particle_t)); // Allocate memory for the particle
    if (new_particle == NULL) { // Check if memory allocation was successful
        fprintf(stderr, "allocation error\n");
        return NULL;
    }
    new_particle->x = 0.0f; // Initialize x-coordinate
    new_particle->y = 0.0f; // Initialize y-coordinate
    return new_particle;
}

// Function to initialize an experiment with particles
particle_t** init_experiment() {
    int i = 0;
    // Allocate memory for the experiment
    particle_t** experiment = (particle_t**)malloc(sizeof(particle_t*) * 10000);
    if (experiment == NULL) { // Check if memory allocation was successful
        fprintf(stderr, "allocation error\n");
        return NULL;
    }
    // Generate particles for the experiment
    for (i = 0; i < 10000; i++) {
        experiment[i] = generate_particle();
        if (experiment[i] == NULL) { // Check if particle generation was successful
            return NULL;
        }
    }
    return experiment;
}

// Function to release memory allocated for the experiment
void release_experiment(particle_t** experiment) {
    if (experiment != NULL) {
        int i = 0;
        // Free memory allocated for each particle
        for (i = 0; i < 10000; i++) {
            free(experiment[i]);
        }
        free(experiment); // Free memory allocated for the experiment
    }
    else {
        fprintf(stderr, "Failed to initialized\n");
    }
}

// Function to perform a step of the experiment
void perform_step(particle_t** experiment, int* counter) {
    bool finished = false;
    int i = 0;
    for (i = 0; i < 10000; i++) {
        if (experiment[i]->x > 0.9999) continue; // Skip particles that have reached the end
        finished = move_individual(experiment[i]); // Move the particle
        if (finished) {
            (*counter)++; // Increment counter if particle has reached the end
            printf("%f\n", experiment[i]->y); // Print the y-coordinate of the particle
        }
    }
}

// Function to move an individual particle as part of one step
bool move_individual(particle_t* part) {
    double move = (double)rand() / RAND_MAX; // Generate a random value between 0 and 1
    if (move < 0.65) { // Move the particle +0.1 in the x-axis
        part->x += 0.1f;
        if (part->x > 0.9999) { // Check if particle has reached the end
            return true;
        }
        return false;
    }
    else if (move < 0.8) { // Move the particle +0.1 in the y-axis
        if (part->y < 0.5) part->y += 0.1f;
        return false;
    }
    else if (move < 0.95) { // Move the particle -0.1 in the y-axis
        if (part->y > -0.5) part->y -= 0.1f;
        return false;
    }
    else { // Move the particle -0.1 in the x-axis
        if (part->x > 0.0f) part->x -= 0.1f;
        return false;
    }
}

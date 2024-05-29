# Desired Model Compensation-Based Position Constrained Control of Robotic Manipulators

This repository contains the simulation and experiment projects associated with the paper "Desired Model Compensation-Based Position Constrained Control of Robotic Manipulators".

## Table of Contents

1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Simulation](#simulation)
5. [Experiment](#experiment)
6. [Results](#results)
7. [Contributing](#contributing)
8. [License](#license)
9. [Acknowledgements](#acknowledgements)

## Introduction

This project demonstrates the application of a control method for robotic manipulators that ensures position constraints are met using desired model compensation. The method is implemented and tested through simulations using MATLAB Simulink, with controllers and dynamics written in C.

The key objectives of this project are to:
- Develop a robust control strategy for robotic manipulators that accounts for position constraints.
- Implement the control strategy in a simulated environment to validate its effectiveness.
- Provide a detailed analysis of the simulation results to demonstrate the performance improvements achieved by the proposed method.

## Prerequisites

- MATLAB with Simulink
- C compiler (e.g., GCC)
- MATLAB Coder (if generating C code from MATLAB)

## Usage

Instructions on how to run the simulations and experiments.

### Running the Simulation

1. Open the Simulink model:

    ```matlab
    open('model_name.slx');
    ```

2. Run the simulation from the Simulink interface.

### Running the Experiment

1. Ensure the C code is compiled. You can use the provided Makefile:

    ```bash
    cd path_to_c_code
    make
    ```

2. Execute the compiled program:

    ```bash
    ./compiled_program
    ```

## Simulation

Detailed information about the simulation setup, parameters, and how to execute it.

- Description of the Simulink model and its components.
- Instructions on how to modify parameters within the Simulink model.
- Example commands or steps to run different simulation scenarios.

### Simulink Schematic

![Simulation Schematic](path/to/simulation_schematic.png)

## Experiment

Details about the experimental setup, including hardware and software requirements.

- Description of the robotic manipulator and other equipment used.
- Instructions on setting up the hardware.
- Steps to replicate the experiment, including how to interface the C code with the hardware.

### Simulink Schematic

![Experiment Schematic](path/to/experiment_schematic.png)

## Results

Presentation of the results obtained from the simulations and experiments.

- Graphs, charts, and tables showcasing the performance of the control method.
- Analysis and discussion of the results.
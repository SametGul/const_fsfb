# Desired Model Compensation-Based Position Constrained Control of Robotic Manipulators

This repository contains the simulation and experiment projects associated with the paper "Desired Model Compensation-Based Position Constrained Control of Robotic Manipulators".

## Table of Contents

1. [Summary of the Study](#summary-of-the-study)
2. [Prerequisites](#prerequisites)
3. [Simulation](#simulation)
4. [Experiment](#experiment)
5. [Results](#results)

## Summary of the Study

This work presents the design and the corresponding stability analysis of a desired model-based, joint position constrained, controller formulation for robotic manipulators. Specifically, provided that the initial joint position tracking error signal starts within some predefined region, the proposed controller ensures that the joint tracking error signal remains inside this region and approaches to zero asymptotically. Extensive numerical simulations and experimental studies performed on a two-link direct-drive planar robot are provided in order to illustrate the effectiveness and feasibility of the proposed controller.

## Prerequisites

- MATLAB with Simulink (MATLAB R2021a or above)
- Mex C Compiler (if you want to make changes and compile C files)
- Real-Time Desktop Kernel (in order to work on the Experiment Project)

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
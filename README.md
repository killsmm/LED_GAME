# Untitled

# Description

- Defined HAL abstract class and corresponding Factory class for portability.
- To migrate to another platform, steps:
    - Inherit the HAL class and implement the virtual member functions
    - add the class to HAL Factory class
    - set up the cross-tools and build it by cmake

# Test Plan

# 1. Unit test

- Cover the core logics in Game.cpp (Done)
- Result
    
    <img width="525" alt="test2" src="https://github.com/killsmm/LED_GAME/assets/10162729/f60d371e-5276-45a9-9b38-df23fdb2d750">
    

# 2. Integration Test

Run LED_GAME_INTEGRATION_TEST, which could display the target sequence every time, based on the random target sequence. 

Testers could input anything to see if the results meet the expectations.

- Result
    
    <img width="476" alt="test1" src="https://github.com/killsmm/LED_GAME/assets/10162729/d2e8873f-df3b-42ba-807b-8613fa7fcd3e">

# Project Overview
This project is heavily based on the work of Nils Chur. <br>
https://github.com/NilsChur/CTSE_Mapping_Properties <br>

Focus of this project is on providing feedback on difficulties and challenges <br>
encountered during the formal verification of automatically generated source code.

## Chapter 1 - Literature Review (23.01.2025)
- Research on various controllers.
- Results stored in `./Papers`.
- Project focuses on the first three papers:
  - Quadcopter
  - Satellite
  - UAV

## Chapter 2 - Getting Started with Simulink and MATLAB (29.01.2025)
- Initial setup and familiarization with Simulink and MATLAB.

## Chapter 3 - Modeling Controllers in Simulink (05.02.2025)
- Implementation of controllers from Chapter 1.
- Results stored in `./Implementations`.

## Chapter 4 - Performance Evaluation (12.02.2025)
- Determination of performance-relevant values:
  - Rise Time
  - Settling Time
  - Maximum Overshoot
  - Steady State Error
- Results stored in:
  - `./Implementations/UAV/Performance_UAV_Pitch_Control`

## Chapter 5 - C++ Code Generation (19.02.2025)
- Automatic code generation using Simulink Coder.
- Results stored in `./Implementations/*/*_grt_rtw/`.

## Chapter 6 - Code Analysis (26.02.2025)
- Understanding the generated C++ code and its structure.

## Chapter 7 - Download and setup DIVINE Model Checker (05.03.2025)
- Used version: 4.4.2
- Used source: https://divine.fi.muni.cz/manual.html
- 4.4.4 had no manual at the time of this project.

## Chapter 8 - Get started with DIVINE (19.03.2025)
- Familiarization with its functionality and documentation

## Chapter 9 - Include an observer as FSM (26.03.2025)
- Modified files: `main.cpp` , `MODEL.cpp`, `MODEL.h`, `CMakeLists.txt`
- Added files: `Observer.h`, `Observer.cpp`, `ObserverState.h`,<br>
  `ConcreteObserverStates.h`, `ConcreteObserverStates.cpp`

## Chapter 10 - Configuration (02.04.2025)
- Integrate DIVINE and the observer into the source code.
- Create a Makefile to manage the build process.
  - Make-Command: `make -f MODEL.mk divine-build`
- Test the observer by checking visited states
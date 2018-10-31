*MotorSimulator* is open source motor control firmware that enables high quality servo motor control for advanced robotics projects.

The main goals of the code are:
* fixed frequency interrupt based foc and main control loops
* parameter system upload/download/store/tune parameters on device
* hardware abstraction for both simulator and potentially multiple embedded controllers
* profiler tracking of loop timing
* realtime communication - first implementation with USB
* C API - enables easy realtime PC control through MATLAB, Simulink or C

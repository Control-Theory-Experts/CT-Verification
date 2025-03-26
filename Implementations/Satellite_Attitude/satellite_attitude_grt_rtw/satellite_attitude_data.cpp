/*
 * satellite_attitude_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "satellite_attitude".
 *
 * Model version              : 1.12
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C++ source code generated on : Tue Mar 18 20:02:36 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "satellite_attitude.h"

/* Block parameters (default storage) */
P_satellite_attitude_T satellite_attitude::satellite_attitude_P{
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S29>/Derivative Gain'
   */
  1.98,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S33>/Integral Gain'
   */
  0.0564,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S31>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_e
   * Referenced by: '<S36>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S39>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S41>/Proportional Gain'
   */
  9.0,

  /* Computed Parameter: SatellitestructurePlant_A
   * Referenced by: '<Root>/Satellite structure (Plant)'
   */
  { -0.0, -0.0 },

  /* Computed Parameter: SatellitestructurePlant_C
   * Referenced by: '<Root>/Satellite structure (Plant)'
   */
  { 0.0, 1.25 },

  /* Computed Parameter: Actuator_A
   * Referenced by: '<Root>/Actuator'
   */
  { -1815.4, -24466.0 },

  /* Computed Parameter: Actuator_C
   * Referenced by: '<Root>/Actuator'
   */
  { 78.3, 0.0 },

  /* Computed Parameter: Amplifier_A
   * Referenced by: '<Root>/Amplifier'
   */
  -10.0,

  /* Computed Parameter: Amplifier_C
   * Referenced by: '<Root>/Amplifier'
   */
  2400.0
};

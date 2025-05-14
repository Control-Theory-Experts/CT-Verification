/*
 * satellite_attitude.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "satellite_attitude".
 *
 * Model version              : 1.14
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C++ source code generated on : Tue Apr 15 17:31:50 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "satellite_attitude.h"
#include "rtwtypes.h"
#include "satellite_attitude_private.h"

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
void satellite_attitude::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t { rtsiGetT(si) };

  time_T tnew { rtsiGetSolverStopTime(si) };

  time_T h { rtsiGetStepSize(si) };

  real_T *x { rtsiGetContStates(si) };

  ODE4_IntgData *id { static_cast<ODE4_IntgData *>(rtsiGetSolverData(si)) };

  real_T *y { id->y };

  real_T *f0 { id->f[0] };

  real_T *f1 { id->f[1] };

  real_T *f2 { id->f[2] };

  real_T *f3 { id->f[3] };

  real_T temp;
  int_T i;
  int_T nXc { 7 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  satellite_attitude_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  this->step();
  satellite_attitude_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  this->step();
  satellite_attitude_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  this->step();
  satellite_attitude_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void satellite_attitude::step()
{
  real_T rtb_errorDesiredActualAttitude;
  if (rtmIsMajorTimeStep((&satellite_attitude_M))) {
    /* set solver stop time */
    if (!((&satellite_attitude_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&satellite_attitude_M)->solverInfo,
                            (((&satellite_attitude_M)->Timing.clockTickH0 + 1) *
        (&satellite_attitude_M)->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&satellite_attitude_M)->solverInfo,
                            (((&satellite_attitude_M)->Timing.clockTick0 + 1) *
        (&satellite_attitude_M)->Timing.stepSize0 + (&satellite_attitude_M)
        ->Timing.clockTickH0 * (&satellite_attitude_M)->Timing.stepSize0 *
        4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&satellite_attitude_M))) {
    (&satellite_attitude_M)->Timing.t[0] = rtsiGetT(&(&satellite_attitude_M)
      ->solverInfo);
  }

  /* TransferFcn: '<Root>/Actuator' */
  satellite_attitude_B.actuatorForce = 78.3 * satellite_attitude_X.Actuator[0];

  /* TransferFcn: '<Root>/Satellite structure (Plant)' */
  rtb_errorDesiredActualAttitude = 0.0 *
    satellite_attitude_X.Satellite_structure[0] + 1.25 *
    satellite_attitude_X.Satellite_structure[1];

  /* TransferFcn: '<Root>/Actuator' */
  satellite_attitude_B.actuatorForce += 0.0 * satellite_attitude_X.Actuator[1];

  /* Outport: '<Root>/ActualAttitude' */
  satellite_attitude_Y.ActualAttitude = rtb_errorDesiredActualAttitude;

  /* Sum: '<Root>/Sum' incorporates:
   *  Inport: '<Root>/DesiredAttitude'
   */
  rtb_errorDesiredActualAttitude = satellite_attitude_U.desiredAttitude -
    rtb_errorDesiredActualAttitude;

  /* Gain: '<S39>/Filter Coefficient' incorporates:
   *  Gain: '<S29>/Derivative Gain'
   *  Integrator: '<S31>/Filter'
   *  Sum: '<S31>/SumD'
   */
  satellite_attitude_B.FilterCoefficient = (1.98 *
    rtb_errorDesiredActualAttitude - satellite_attitude_X.Filter_CSTATE) * 100.0;

  /* Sum: '<S45>/Sum' incorporates:
   *  Gain: '<S41>/Proportional Gain'
   *  Integrator: '<S36>/Integrator'
   */
  satellite_attitude_B.Sum = (9.0 * rtb_errorDesiredActualAttitude +
    satellite_attitude_X.Integrator_CSTATE) +
    satellite_attitude_B.FilterCoefficient;

  /* Gain: '<S33>/Integral Gain' */
  satellite_attitude_B.IntegralGain = 0.0564 * rtb_errorDesiredActualAttitude;

  /* TransferFcn: '<Root>/Amplifier' */
  satellite_attitude_B.amplifiedSignal = 2400.0 * satellite_attitude_X.Amplifier;


/* Is this the time information? If so jackpott 
    * Could be passed to the Observer and can serve as guards */
    time_T timing = rtsiGetT(&(&satellite_attitude_M)->solverInfo);
    
    /* 
    *
    * Pass values to the Observer
    * The error of the system is captured by the variable:        rtb_e
    * The reference is captrued by the variable:                  Velocity_Controlled_Vehicle_B.ref
    * The output of the system is captured by the variable:       (Velocity_Controlled_Vehicle_P.car_transfer_fcn_C[0] * Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[0] + Velocity_Controlled_Vehicle_P.car_transfer_fcn_C[1] * Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[1])
    * 
    */

    ObserverFSM.setExternalInput(satellite_attitude_U.desiredAttitude, rtb_errorDesiredActualAttitude, satellite_attitude_Y.ActualAttitude, timing);
    ObserverFSM.transition();

  if (rtmIsMajorTimeStep((&satellite_attitude_M))) {
    /* Matfile logging */
    rt_UpdateTXYLogVars((&satellite_attitude_M)->rtwLogInfo,
                        ((&satellite_attitude_M)->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep((&satellite_attitude_M))) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal((&satellite_attitude_M))!=-1) &&
          !((rtmGetTFinal((&satellite_attitude_M))-(&satellite_attitude_M)
             ->Timing.t[0]) > (&satellite_attitude_M)->Timing.t[0] *
            (DBL_EPSILON))) {
        rtmSetErrorStatus((&satellite_attitude_M), "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&(&satellite_attitude_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&satellite_attitude_M)->Timing.clockTick0)) {
      ++(&satellite_attitude_M)->Timing.clockTickH0;
    }

    (&satellite_attitude_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&satellite_attitude_M)->solverInfo);
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void satellite_attitude::satellite_attitude_derivatives()
{
  XDot_satellite_attitude_T *_rtXdot;
  _rtXdot = ((XDot_satellite_attitude_T *) (&satellite_attitude_M)->derivs);

  /* Derivatives for Integrator: '<S31>/Filter' */
  _rtXdot->Filter_CSTATE = satellite_attitude_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S36>/Integrator' */
  _rtXdot->Integrator_CSTATE = satellite_attitude_B.IntegralGain;

  /* Derivatives for TransferFcn: '<Root>/Satellite structure (Plant)' */
  _rtXdot->Satellite_structure[0] = -0.0 *
    satellite_attitude_X.Satellite_structure[0];

  /* Derivatives for TransferFcn: '<Root>/Actuator' */
  _rtXdot->Actuator[0] = -1815.4 * satellite_attitude_X.Actuator[0];

  /* Derivatives for TransferFcn: '<Root>/Satellite structure (Plant)' */
  _rtXdot->Satellite_structure[0] += -0.0 *
    satellite_attitude_X.Satellite_structure[1];

  /* Derivatives for TransferFcn: '<Root>/Actuator' */
  _rtXdot->Actuator[0] += -24466.0 * satellite_attitude_X.Actuator[1];

  /* Derivatives for TransferFcn: '<Root>/Satellite structure (Plant)' */
  _rtXdot->Satellite_structure[1] = satellite_attitude_X.Satellite_structure[0];
  _rtXdot->Satellite_structure[0] += satellite_attitude_B.actuatorForce;

  /* Derivatives for TransferFcn: '<Root>/Actuator' */
  _rtXdot->Actuator[1] = satellite_attitude_X.Actuator[0];
  _rtXdot->Actuator[0] += satellite_attitude_B.amplifiedSignal;

  /* Derivatives for TransferFcn: '<Root>/Amplifier' */
  _rtXdot->Amplifier = -10.0 * satellite_attitude_X.Amplifier;
  _rtXdot->Amplifier += satellite_attitude_B.Sum;
}

/* Model initialize function */
void satellite_attitude::initialize()
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&satellite_attitude_M)->solverInfo,
                          &(&satellite_attitude_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&satellite_attitude_M)->solverInfo, &rtmGetTPtr
                ((&satellite_attitude_M)));
    rtsiSetStepSizePtr(&(&satellite_attitude_M)->solverInfo,
                       &(&satellite_attitude_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&satellite_attitude_M)->solverInfo, &(&satellite_attitude_M
                 )->derivs);
    rtsiSetContStatesPtr(&(&satellite_attitude_M)->solverInfo, (real_T **)
                         &(&satellite_attitude_M)->contStates);
    rtsiSetNumContStatesPtr(&(&satellite_attitude_M)->solverInfo,
      &(&satellite_attitude_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&satellite_attitude_M)->solverInfo,
      &(&satellite_attitude_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&satellite_attitude_M)->solverInfo,
      &(&satellite_attitude_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&satellite_attitude_M)->solverInfo,
      &(&satellite_attitude_M)->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&(&satellite_attitude_M)->solverInfo, (boolean_T**)
      &(&satellite_attitude_M)->contStateDisabled);
    rtsiSetErrorStatusPtr(&(&satellite_attitude_M)->solverInfo,
                          (&rtmGetErrorStatus((&satellite_attitude_M))));
    rtsiSetRTModelPtr(&(&satellite_attitude_M)->solverInfo,
                      (&satellite_attitude_M));
  }

  rtsiSetSimTimeStep(&(&satellite_attitude_M)->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&(&satellite_attitude_M)->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&(&satellite_attitude_M)->solverInfo, false);
  (&satellite_attitude_M)->intgData.y = (&satellite_attitude_M)->odeY;
  (&satellite_attitude_M)->intgData.f[0] = (&satellite_attitude_M)->odeF[0];
  (&satellite_attitude_M)->intgData.f[1] = (&satellite_attitude_M)->odeF[1];
  (&satellite_attitude_M)->intgData.f[2] = (&satellite_attitude_M)->odeF[2];
  (&satellite_attitude_M)->intgData.f[3] = (&satellite_attitude_M)->odeF[3];
  (&satellite_attitude_M)->contStates = ((X_satellite_attitude_T *)
    &satellite_attitude_X);
  (&satellite_attitude_M)->contStateDisabled = ((XDis_satellite_attitude_T *)
    &satellite_attitude_XDis);
  (&satellite_attitude_M)->Timing.tStart = (0.0);
  rtsiSetSolverData(&(&satellite_attitude_M)->solverInfo, static_cast<void *>(&(
    &satellite_attitude_M)->intgData));
  rtsiSetSolverName(&(&satellite_attitude_M)->solverInfo,"ode4");
  rtmSetTPtr((&satellite_attitude_M), &(&satellite_attitude_M)->Timing.tArray[0]);
  rtmSetTFinal((&satellite_attitude_M), 10.0);
  (&satellite_attitude_M)->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (nullptr);
    (&satellite_attitude_M)->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo((&satellite_attitude_M)->rtwLogInfo, (nullptr));
    rtliSetLogXSignalPtrs((&satellite_attitude_M)->rtwLogInfo, (nullptr));
    rtliSetLogT((&satellite_attitude_M)->rtwLogInfo, "tout");
    rtliSetLogX((&satellite_attitude_M)->rtwLogInfo, "");
    rtliSetLogXFinal((&satellite_attitude_M)->rtwLogInfo, "");
    rtliSetLogVarNameModifier((&satellite_attitude_M)->rtwLogInfo, "rt_");
    rtliSetLogFormat((&satellite_attitude_M)->rtwLogInfo, 0);
    rtliSetLogMaxRows((&satellite_attitude_M)->rtwLogInfo, 0);
    rtliSetLogDecimation((&satellite_attitude_M)->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[1];
      rt_LoggedOutputSignalPtrs[0] = &satellite_attitude_Y.ActualAttitude;
      rtliSetLogYSignalPtrs((&satellite_attitude_M)->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] {
        1
      };

      static int_T rt_LoggedOutputDimensions[] {
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] {
        (nullptr)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] {
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] {
        (nullptr)
      };

      static const char_T *rt_LoggedOutputLabels[]{
        "actualAttitude" };

      static const char_T *rt_LoggedOutputBlockNames[]{
        "satellite_attitude/ActualAttitude" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (nullptr),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (nullptr),
          (nullptr),
          (nullptr),

          { rt_LoggedOutputBlockNames },

          { (nullptr) },
          (nullptr),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo((&satellite_attitude_M)->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY((&satellite_attitude_M)->rtwLogInfo, "yout");
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime((&satellite_attitude_M)->rtwLogInfo, 0.0,
    rtmGetTFinal((&satellite_attitude_M)), (&satellite_attitude_M)
    ->Timing.stepSize0, (&rtmGetErrorStatus((&satellite_attitude_M))));

  /* InitializeConditions for Integrator: '<S31>/Filter' */
  satellite_attitude_X.Filter_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S36>/Integrator' */
  satellite_attitude_X.Integrator_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Satellite structure (Plant)' */
  satellite_attitude_X.Satellite_structure[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Actuator' */
  satellite_attitude_X.Actuator[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Satellite structure (Plant)' */
  satellite_attitude_X.Satellite_structure[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Actuator' */
  satellite_attitude_X.Actuator[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Amplifier' */
  satellite_attitude_X.Amplifier = 0.0;
}

/* Model terminate function */
void satellite_attitude::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
satellite_attitude::satellite_attitude() :
  satellite_attitude_U(),
  satellite_attitude_Y(),
  satellite_attitude_B(),
  satellite_attitude_X(),
  satellite_attitude_XDis(),
  satellite_attitude_M(),
  ObserverFSM()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
satellite_attitude::~satellite_attitude() = default;

/* Real-Time Model get method */
RT_MODEL_satellite_attitude_T * satellite_attitude::getRTM()
{
  return (&satellite_attitude_M);
}

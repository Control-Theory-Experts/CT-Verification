Unterschied zwischen main.cpp

Ich liste auf, was Nils in seiner main hinzugefügt hat. Die Zeilenangaben (a-b,c) bedeuten:
Nils hat in seiner Datei die Zeilen a-b hinzugefügt in Zeile c in der Originaldatei.

------------------------------------------------------------------------------------------------------------------------------------------------
(74-83, 75) Hier werden die Includes gemacht.


#include "Velocity_Controlled_Vehicle.h"
#include "Observer.h"
// #pragma "Observer.h" reason why pragma?

#include <iostream>
// For DIVINE
#include <dios.h>
#include <sys/divm.h>
#include <stdbool.h>
#include <map>
------------------------------------------------------------------------------------------------------------------------------------------------
(169-315, 232-354) Die Funktion static void rt_OneStep(MODEL_CLASSNAME & mdl) sieht syntaxmäßig leicht verschieden aus, aber ich denke, es ist nur syntaxmäßig. Es scheint, als wären in der alten Version Funktionen geschrieben und in der neuen stattdessen Makros verwendet worden. Hier scheint nichts nachträglich geändert worden zu sein.

------------------------------------------------------------------------------------------------------------------------------------------------ 
(350-378,389-423) static int_T rt_TermModel(MODEL_CLASSNAME & mdl)
Das gleiche wie bei rt_OneStep(MODEL_CLASSNAME & mdl)
------------------------------------------------------------------------------------------------------------------------------------------------
(380-,424) Hier wird der Büchi Automat initialisiert.

/*
 * 
 * In the following section the büchi automata will be implemented with are constructed via the Spot online tool
 * To get the boolen if a state was visited the Observer itself provied a method for each state, here a short listing:
 * - (...).ObserverFSM.wasRestVisited(); return a boolen if the state Rest was visited
 * - (...).ObserverFSM.wasTransientVisited(); return a boolen if the state Transient was visited
 * - (...).ObserverFSM.wasRiseVisited(); return a boolen if the state Rise was visited
 * - (...).ObserverFSM.wasOvershootVisited(); return a boolen if the state Overshoot was visited
 * - (...).ObserverFSM.wasBoundedVisited(); return a boolen if the state Bounded was visited
 * 
*/

// Checks if the system reaches the rise state
int nextRise(int state, bool RiseAP){
    /*
    never { Frise 
    T0_init:
        if
        :: (rise) -> goto accept_all
        :: (!(rise)) -> goto T0_init
        fi;
    accept_all:
        skip
    }
    */
    __dios_trace_f("Rise: %x", RiseAP);
    switch(state) {
        case -1:
            return 1;

        case 0:
            __vm_ctl_flag(0, _VM_CF_Accepting);
            if(RiseAP) {return 0;}

        case 1:
            
            if(RiseAP) {return 0;}
            if(!RiseAP) {return 1;}

        default:
            return state;
    }
};

// Checks if the system reaches the overshoot state
int nextOvershoot(int state, bool OvershootAP){
    /* never { G!overshoot 
    accept_init:
        if
        :: (!(overshoot)) -> goto accept_init
        :: (overshoot) -> goto T0_S1
        fi;
    T0_S1:
        if
        :: (true) -> goto T0_S1
        fi;
    }
    */
    __dios_trace_f("Overshoot; %x", OvershootAP);
    switch (state) {
        case -1: // initial state
            return 0; // state is now initilized but not visited

        case 0:
            __vm_ctl_flag(0, _VM_CF_Accepting);
            if(!OvershootAP) {return 0;}
            if(OvershootAP) {return 1;}

        case 1:
            __vm_ctl_flag(0, _VM_CF_Error);
            if (OvershootAP) {return 1;}

        default:
            return state;

   }
};

// Checks if the system reaches a bounded state, therfore, is stable but not necesseraly within settling time 
int nextBounded(int state, bool BoundedAP){
    /*
    never { Fbounded
    T0_init:
    if
        :: (bounded) -> goto accept_all
        :: (!(bounded)) -> goto T0_init
        fi;
    accept_all:
       skip
    }
    */
   __dios_trace_f("Bounded: %x", BoundedAP); 
    switch(state) {
        case -1:
            return 1;

        case 0:
            __vm_ctl_flag(0, _VM_CF_Accepting);
            if(BoundedAP) {return 0;}

        case 1:
            if(BoundedAP) {return 0;}
            if(!BoundedAP) {return 1;}

        default:
            return state;
    }
};

// Checks if the system reaches a stable state within the settling time
int nextSettlingTime(int state, bool StableAP){
    /*
    never { Fsettling_time
    T0_init:
        if
        :: (settling_time) -> goto accept_all
        :: (!(settling_time)) -> goto T0_init
        fi;
    accept_all:
        skip
    }
    */
   __dios_trace_f("Settling Time: %x", StableAP); 
   switch(state) {
    case -1:
        return 1;

    case 0:
        __vm_ctl_flag(0, _VM_CF_Accepting);
        if(StableAP) {return 0;}

    case 1:
        if(StableAP) {return 0;}
        if(!StableAP) {return 1;}

    default:
        return state;
   }
};

------------------------------------------------------------------------------------------------------------------------------------------------
(521-,450-) main-Methode. Sie unterscheiden sich nur wie angegeben:
(563-596,483) 
    /***********************************************************************
     *  Instructions to embed property
     *  while ( true )
     *   {
     *       __dios_reschedule();
     *       system_step();
     *       buchi_step();
     *   }
     * */


    /*
    * Initialize Observer thresholds epsilon, overshoot, rise level, rise time and settling time
    */
    MODEL_INSTANCE.ObserverFSM.initialThreshold(5.0, 10.0, 90.0, 1.5, 5.0);

    /* 
     * Init states for model checking with Divine
     * For each büchi automata an old and current state is needed
    */
    int stateRise = -1, oldStateRise = 0;
    int stateOvershoot = -1, oldStateOvershoot = 0;
    int stateBounded = -1, oldStateBounded = 0;
    int stateSettlingTime = -1, oldStateSettlingTime = 0;


    //while (rtmGetErrorStatus(MODEL_INSTANCE.getRTM()) == NULL &&
           //!rtmGetStopRequested(MODEL_INSTANCE.getRTM())) {
    while(true){    
        __dios_reschedule();
        oldStateRise = stateRise; 
        oldStateOvershoot = stateOvershoot;
        oldStateBounded = stateBounded;
        oldStateSettlingTime = stateSettlingTime;

(610-616,524-525)
/*
        * 
        * No need for to explicit call the observer transitions, because the observer is part of the model.
        * Everytime the model does a step is "automatically" updates the observer. 
        * Therefore, rt_OneStep(...) also updates the Observer.
        * 
        */

(619-661, 525-526))
        // Each Büchi automaton is updated 
        stateRise = nextRise(stateRise, MODEL_INSTANCE.ObserverFSM.wasRiseVisited());
        stateOvershoot = nextOvershoot(stateOvershoot, MODEL_INSTANCE.ObserverFSM.wasOvershootVisited());
        stateBounded = nextBounded(stateBounded, MODEL_INSTANCE.ObserverFSM.wasBoundedVisited());
        stateSettlingTime = nextSettlingTime(stateSettlingTime, MODEL_INSTANCE.ObserverFSM.wasRestVisited());


        __dios_trace_f( "state rise: %d -> %d", oldStateRise, stateRise );
        __dios_trace_f( "state stable: %d -> %d", oldStateSettlingTime, stateSettlingTime );
        __dios_trace_f( "state overshoot: %d -> %d", oldStateOvershoot, stateOvershoot );
        __dios_trace_f( "state bounded: %d -> %d", oldStateBounded, stateBounded );

        /* // !!! Test !!!
        * Choose which property to test, multiple simulaniously testin is not possible (i think) 
        * Options:
        * 1 = Rise
        * 2 = Settle
        * 3 = Overshoot
        * 4 = Bounded 
        * Default is Overshoot 
        

        string propertyToBeTested = 3;
        
        switch (propertyToBeTested)
        {
        case 1:
            __dios_trace_f( "state rise: %d -> %d", oldStateRise, stateRise );
            break;
        case 2:
            __dios_trace_f( "state stable: %d -> %d", oldStateSettlingTime, stateSettlingTime );
            break;
        case 3:
            __dios_trace_f( "state overshoot: %d -> %d", oldStateOvershoot, stateOvershoot );
            break;
        case 4:
             __dios_trace_f( "state bounded: %d -> %d", oldStateBounded, stateBounded );
             break;
        default:
            __dios_trace_f( "state overshoot: %d -> %d", oldStateOvershoot, stateOvershoot );
            break;
        }
        */

------------------------------------------------------------------------------------------------------------------------------------------------

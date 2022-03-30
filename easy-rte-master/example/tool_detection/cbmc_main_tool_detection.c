
//This file should be called cbmc_main_tool_detection.c
//This is autogenerated code. Edit by hand at your peril!

//It can be used with the cbmc model checker
//Call it using the following command: 
//$ cbmc cbmc_main_tool_detection.c F_tool_detection.c


#include "F_tool_detection.h"
#include <stdio.h>
#include <stdint.h>

int main() {


	//I/O and state for tool_detection
	enforcervars_tool_detection_t enf_tool_detection;
    inputs_tool_detection_t inputs_tool_detection;
    outputs_tool_detection_t outputs_tool_detection;

	//set values to known state
    tool_detection_init_all_vars(&enf_tool_detection, &inputs_tool_detection, &outputs_tool_detection);

	//introduce nondeterminism
    //a nondet_xxxxx function name tells cbmc that it could be anything, but must be unique
    //randomise inputs
	inputs_tool_detection.T1 = nondet_tool_detection_input_0();
	inputs_tool_detection.T2 = nondet_tool_detection_input_1();
	inputs_tool_detection.T3 = nondet_tool_detection_input_2();
	inputs_tool_detection.T4 = nondet_tool_detection_input_3();
	inputs_tool_detection.T5 = nondet_tool_detection_input_4();
	inputs_tool_detection.T6 = nondet_tool_detection_input_5();
	inputs_tool_detection.T7 = nondet_tool_detection_input_6();
	

	//randomise enforcer state, i.e. clock values and position (excepting violation state)
	
	enf_tool_detection._policy_p1_state = nondet_tool_detection_enf_p1_state() % 2;
	enf_tool_detection.v = nondet_tool_detection_enf_p2_0();
	
	enf_tool_detection._policy_p2_state = nondet_tool_detection_enf_p2_state() % 2;
	

    //run the enforcer (i.e. tell CBMC to check this out)
	tool_detection_run_via_enforcer(&enf_tool_detection, &inputs_tool_detection, &outputs_tool_detection);

}


void tool_detection_run(inputs_tool_detection_t *inputs, outputs_tool_detection_t *outputs) {
    //randomise controller

    outputs->res = nondet_tool_detection_output_0();
	 
}


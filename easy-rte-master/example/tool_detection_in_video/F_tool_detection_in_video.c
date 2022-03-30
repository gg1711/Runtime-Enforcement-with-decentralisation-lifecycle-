
//This file should be called F_tool_detection_in_video.c
//This is autogenerated code. Edit by hand at your peril!
#include "F_tool_detection_in_video.h"

void tool_detection_in_video_init_all_vars(enforcervars_tool_detection_in_video_t* me, inputs_tool_detection_in_video_t* inputs, outputs_tool_detection_in_video_t* outputs) {
	//set any input vars with default values
	
	//set any output vars with default values
	

	
	me->_policy_p1_state = POLICY_STATE_tool_detection_in_video_p1_s0;
	//input policy internal vars
	
	
	me->_policy_p2_state = POLICY_STATE_tool_detection_in_video_p2_s0;
	//input policy internal vars
	
	me->v = 0;
	
	
}

void tool_detection_in_video_run_via_enforcer(enforcervars_tool_detection_in_video_t* me, inputs_tool_detection_in_video_t* inputs, outputs_tool_detection_in_video_t* outputs) {
	//run the policies in reverse order for the inputs (last policies have highest priority)
	
	 tool_detection_in_video_run_input_enforcer_p2(me, inputs);
	 tool_detection_in_video_run_input_enforcer_p1(me, inputs);
	

	tool_detection_in_video_run(inputs, outputs);

	//run policies in specified order for outputs
	tool_detection_in_video_run_output_enforcer_p1(me, inputs,outputs);
	tool_detection_in_video_run_output_enforcer_p2(me, inputs,outputs);
	
}


//input policies

//INPUT POLICY p1 BEGIN
//This will run the input enforcer for tool_detection_in_video's policy p1
void tool_detection_in_video_run_input_enforcer_p1(enforcervars_tool_detection_in_video_t* me, inputs_tool_detection_in_video_t* inputs) {
	switch(me->_policy_p1_state) {
		case POLICY_STATE_tool_detection_in_video_p1_s0:
			
			
			break;

		case POLICY_STATE_tool_detection_in_video_p1_s1:
			
			if(inputs->T7) {
				//transition s1 -> violation on T7
				//select a transition to solve the problem
				
				//Recovery instructions manually provided.
				
			} 
			
			break;

		
	}
}

//INPUT POLICY p1 END

//INPUT POLICY p2 BEGIN
//This will run the input enforcer for tool_detection_in_video's policy p2
void tool_detection_in_video_run_input_enforcer_p2(enforcervars_tool_detection_in_video_t* me, inputs_tool_detection_in_video_t* inputs) {
	switch(me->_policy_p2_state) {
		case POLICY_STATE_tool_detection_in_video_p2_s0:
			
			
			break;

		case POLICY_STATE_tool_detection_in_video_p2_s1:
			
			if(inputs->T2 && me->v > 10) {
				//transition s1 -> violation on T2 and v > 10
				//select a transition to solve the problem
				
				//Recovery instructions manually provided.
				
			} 
			
			break;

		
	}
}

//INPUT POLICY p2 END



//output policies

//OUTPUT POLICY p1 BEGIN
//This will run the input enforcer for tool_detection_in_video's policy p1
void tool_detection_in_video_run_output_enforcer_p1(enforcervars_tool_detection_in_video_t* me, inputs_tool_detection_in_video_t* inputs, outputs_tool_detection_in_video_t* outputs) {
	//advance timers
	
	
	//run enforcer
	switch(me->_policy_p1_state) {
		case POLICY_STATE_tool_detection_in_video_p1_s0:
			

			break;

		case POLICY_STATE_tool_detection_in_video_p1_s1:
			
			if(inputs->T7) {
				//transition s1 -> violation on ( T7 )
				//select a transition to solve the problem
				
				//Recovery instructions manually provided.
				outputs->res = 1;
				
			} 

			break;

		
	}

	//select transition to advance state
	switch(me->_policy_p1_state) {
		case POLICY_STATE_tool_detection_in_video_p1_s0:
			
			if( !(inputs->T2)) {
				//transition s0 -> s0 on !T2
				me->_policy_p1_state = POLICY_STATE_tool_detection_in_video_p1_s0;
				//set expressions
				
				break;
			} 
			if(inputs->T2) {
				//transition s0 -> s1 on T2
				me->_policy_p1_state = POLICY_STATE_tool_detection_in_video_p1_s1;
				//set expressions
				
				break;
			} 
			
			//ensure a transition was taken in this state
			assert(false && "tool_detection_in_video_p1_s0 must take a transition"); //if we are still here, then no transition was taken and we are no longer satisfying liveness

			break;

		case POLICY_STATE_tool_detection_in_video_p1_s1:
			
			if( !(inputs->T7)) {
				//transition s1 -> s1 on !T7
				me->_policy_p1_state = POLICY_STATE_tool_detection_in_video_p1_s1;
				//set expressions
				
				break;
			} 
			if(inputs->T7) {
				//transition s1 -> violation on ( T7 )
				me->_policy_p1_state = POLICY_STATE_tool_detection_in_video_p1_violation;
				//set expressions
				
				break;
			} 
			
			//ensure a transition was taken in this state
			assert(false && "tool_detection_in_video_p1_s1 must take a transition"); //if we are still here, then no transition was taken and we are no longer satisfying liveness

			break;

		
	}

	//ensure we did not violate (i.e. we did not enter violation state)
	assert(me->_policy_p1_state != POLICY_STATE_tool_detection_in_video_p1_violation);
}

//OUTPUT POLICY p1 END

//OUTPUT POLICY p2 BEGIN
//This will run the input enforcer for tool_detection_in_video's policy p2
void tool_detection_in_video_run_output_enforcer_p2(enforcervars_tool_detection_in_video_t* me, inputs_tool_detection_in_video_t* inputs, outputs_tool_detection_in_video_t* outputs) {
	//advance timers
	
	me->v++;
	
	//run enforcer
	switch(me->_policy_p2_state) {
		case POLICY_STATE_tool_detection_in_video_p2_s0:
			

			break;

		case POLICY_STATE_tool_detection_in_video_p2_s1:
			
			if(inputs->T2 && me->v > 10) {
				//transition s1 -> violation on ( T2 and v > 10 )
				//select a transition to solve the problem
				
				//Recovery instructions manually provided.
				outputs->res = 2;
				
			} 

			break;

		
	}

	//select transition to advance state
	switch(me->_policy_p2_state) {
		case POLICY_STATE_tool_detection_in_video_p2_s0:
			
			if(inputs->T2) {
				//transition s0 -> s1 on T2
				me->_policy_p2_state = POLICY_STATE_tool_detection_in_video_p2_s1;
				//set expressions
				
				me->v = 0;
				break;
			} 
			if( !(inputs->T2)) {
				//transition s0 -> s0 on !T2
				me->_policy_p2_state = POLICY_STATE_tool_detection_in_video_p2_s0;
				//set expressions
				
				break;
			} 
			
			//ensure a transition was taken in this state
			assert(false && "tool_detection_in_video_p2_s0 must take a transition"); //if we are still here, then no transition was taken and we are no longer satisfying liveness

			break;

		case POLICY_STATE_tool_detection_in_video_p2_s1:
			
			if(inputs->T2 && me->v <= 10) {
				//transition s1 -> s1 on ( T2 and v <= 10 )
				me->_policy_p2_state = POLICY_STATE_tool_detection_in_video_p2_s1;
				//set expressions
				
				break;
			} 
			if( !(inputs->T2)) {
				//transition s1 -> s0 on !T2
				me->_policy_p2_state = POLICY_STATE_tool_detection_in_video_p2_s0;
				//set expressions
				
				break;
			} 
			if(inputs->T2 && me->v > 10) {
				//transition s1 -> violation on ( T2 and v > 10 )
				me->_policy_p2_state = POLICY_STATE_tool_detection_in_video_p2_violation;
				//set expressions
				
				break;
			} 
			
			//ensure a transition was taken in this state
			assert(false && "tool_detection_in_video_p2_s1 must take a transition"); //if we are still here, then no transition was taken and we are no longer satisfying liveness

			break;

		
	}

	//ensure we did not violate (i.e. we did not enter violation state)
	assert(me->_policy_p2_state != POLICY_STATE_tool_detection_in_video_p2_violation);
}

//OUTPUT POLICY p2 END



//This function is provided in "F_tool_detection_in_video.c"
//It will check the state of the enforcer monitor code
//It returns one of the following:
//0: currently true (safe)
//1: always true (safe)
//-1: currently false (unsafe)
//-2: always false (unsafe)
//It will need to do some reachability analysis to achieve this


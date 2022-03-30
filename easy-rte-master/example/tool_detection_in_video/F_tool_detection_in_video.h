
//This file should be called F_tool_detection_in_video.h
//This is autogenerated code. Edit by hand at your peril!

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

//the dtimer_t type
typedef uint64_t dtimer_t;

//For each policy, we need an enum type for the state machine

enum tool_detection_in_video_policy_p1_states { 
	POLICY_STATE_tool_detection_in_video_p1_s0, 
	POLICY_STATE_tool_detection_in_video_p1_s1,
	POLICY_STATE_tool_detection_in_video_p1_violation 
};

enum tool_detection_in_video_policy_p2_states { 
	POLICY_STATE_tool_detection_in_video_p2_s0, 
	POLICY_STATE_tool_detection_in_video_p2_s1,
	POLICY_STATE_tool_detection_in_video_p2_violation 
};


//Inputs to the function tool_detection_in_video
typedef struct {
	int16_t T1;
	int16_t T2;
	int16_t T3;
	int16_t T4;
	int16_t T5;
	int16_t T6;
	int16_t T7;
	
} inputs_tool_detection_in_video_t;

//Outputs from the function tool_detection_in_video
typedef struct {
	int16_t res;
	
} outputs_tool_detection_in_video_t;

//enforcer state and vars:
typedef struct {
	enum tool_detection_in_video_policy_p1_states _policy_p1_state;
	//internal vars
	
	
	enum tool_detection_in_video_policy_p2_states _policy_p2_state;
	//internal vars
	dtimer_t v;
	
	
	
} enforcervars_tool_detection_in_video_t;




//This function is provided in "F_tool_detection_in_video.c"
//It sets up the variable structures to their initial values
void tool_detection_in_video_init_all_vars(enforcervars_tool_detection_in_video_t* me, inputs_tool_detection_in_video_t* inputs, outputs_tool_detection_in_video_t* outputs);

//This function is provided in "F_tool_detection_in_video.c"
//It will run the synthesised enforcer and call the controller function
void tool_detection_in_video_run_via_enforcer(enforcervars_tool_detection_in_video_t* me, inputs_tool_detection_in_video_t* inputs, outputs_tool_detection_in_video_t* outputs);

//This function is provided from the user
//It is the controller function
extern void tool_detection_in_video_run(inputs_tool_detection_in_video_t* inputs, outputs_tool_detection_in_video_t* outputs);

//enforcer functions


//This function is provided in "F_tool_detection_in_video.c"
//It will run the input enforcer for tool_detection_in_video's policy p1
void tool_detection_in_video_run_input_enforcer_p1(enforcervars_tool_detection_in_video_t* me, inputs_tool_detection_in_video_t* inputs);

//This function is provided in "F_tool_detection_in_video.c"
//It will run the input enforcer for tool_detection_in_video's policy p1
void tool_detection_in_video_run_output_enforcer_p1(enforcervars_tool_detection_in_video_t* me, inputs_tool_detection_in_video_t* inputs, outputs_tool_detection_in_video_t* outputs);

//This function is provided in "F_tool_detection_in_video.c"
//It will check the state of the enforcer monitor code
//It returns one of the following:
//0: currently true (safe)
//1: always true (safe)
//-1: currently false (unsafe)
//-2: always false (unsafe)
//It will need to do some reachability analysis to achieve this
int tool_detection_in_video_check_rv_status_p1(enforcervars_tool_detection_in_video_t* me);


//This function is provided in "F_tool_detection_in_video.c"
//It will run the input enforcer for tool_detection_in_video's policy p2
void tool_detection_in_video_run_input_enforcer_p2(enforcervars_tool_detection_in_video_t* me, inputs_tool_detection_in_video_t* inputs);

//This function is provided in "F_tool_detection_in_video.c"
//It will run the input enforcer for tool_detection_in_video's policy p2
void tool_detection_in_video_run_output_enforcer_p2(enforcervars_tool_detection_in_video_t* me, inputs_tool_detection_in_video_t* inputs, outputs_tool_detection_in_video_t* outputs);

//This function is provided in "F_tool_detection_in_video.c"
//It will check the state of the enforcer monitor code
//It returns one of the following:
//0: currently true (safe)
//1: always true (safe)
//-1: currently false (unsafe)
//-2: always false (unsafe)
//It will need to do some reachability analysis to achieve this
int tool_detection_in_video_check_rv_status_p2(enforcervars_tool_detection_in_video_t* me);


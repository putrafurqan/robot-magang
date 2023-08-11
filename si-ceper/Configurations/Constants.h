#pragma once

#include "../../KRAI_Library/Pinout/F446RE_MASTER_2022.h"

# define PI 3.1415926535

/*
    LM = Left Motor
    RM = Right Motor
*/

// PIN Encoder
#define CHA_LM F446RE_MASTER_ENCODER_A_A_A
#define CHB_LM F446RE_MASTER_ENCODER_A_A_B
#define PPR_LM 538

#define CHA_RM F446RE_MASTER_ENCODER_A_B_A
#define CHB_RM F446RE_MASTER_ENCODER_A_B_B
#define PPR_RM 538

// Rotary Encoder
#define CHA_ROT F446RE_MASTER_ENCODER_A_D_A
#define CHB_ROT F446RE_MASTER_ENCODER_A_D_B

// PIN Motor
#define PWM_LM F446RE_MASTER_PWM_MOTOR_FL
#define FOR_LM F446RE_MASTER_FOR_MOTOR_FL
#define REV_LM F446RE_MASTER_REV_MOTOR_FL

#define PWM_RM F446RE_MASTER_PWM_MOTOR_FR
#define FOR_RM F446RE_MASTER_FOR_MOTOR_FR
#define REV_RM F446RE_MASTER_REV_MOTOR_FR

#define MAXOUT 1
#define VFF 0
#define RPF 1000
#define MAXIN 1000
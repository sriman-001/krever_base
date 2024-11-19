/*****************************************************************************
| File        :   MotorDriver.h
| Author      :   Custom
| Function    :   Drive L298N Motor Drivers
| Info        :   
               L298N is a dual H-bridge motor driver used to control DC motors.
               Uses two input signals (IN1, IN2) and an enable pin (ENA, ENB) for speed and direction control.
*----------------
| This version:   V2.0
| Date        :   2024-11-15
| Info        :   Updated for L298N Motor Drivers
*
******************************************************************************/
#ifndef __MOTOR_DRIVER_H__
#define __MOTOR_DRIVER_H__

#include <wiringPi.h>
#include <softPwm.h>
#include <stdint.h>
#include <stdbool.h>

/* GPIO Pin Definitions */
// Motor A (Left Motor) Configuration
#define AIN1    17      // GPIO pin for Motor A IN1
#define AIN2    27      // GPIO pin for Motor A IN2
#define ENA     22      // GPIO pin for Motor A Enable (PWM)

// Motor B (Right Motor) Configuration
#define BIN1    23      // GPIO pin for Motor B IN1
#define BIN2    24      // GPIO pin for Motor B IN2
#define ENB     25      // GPIO pin for Motor B Enable (PWM)

/* Motor Identifiers */
#define MOTORA  0       // Left Motor ID
#define MOTORB  1       // Right Motor ID

/* Motor Parameters */
#define PWM_RANGE   100     // PWM range (0-100)
#define PWM_MIN     0       // Minimum PWM value
#define PWM_MAX     100     // Maximum PWM value

/* Motor Direction Enumeration */
typedef enum {
    BACKWARD = 0,
    FORWARD = 1,
} DIR;

/* Function Prototypes */
/**
 * @brief Initialize motor driver GPIO and PWM
 * @return void
 */
void Motor_Init(void);

/**
 * @brief Run specified motor with direction and speed
 * @param motor Motor identifier (MOTORA or MOTORB)
 * @param dir Direction (FORWARD or BACKWARD)
 * @param speed PWM speed value (0-100)
 * @return void
 */
void Motor_Run(unsigned char motor, DIR dir, uint16_t speed);

/**
 * @brief Stop specified motor
 * @param motor Motor identifier (MOTORA or MOTORB)
 * @return void
 */
void Motor_Stop(unsigned char motor);

/**
 * @brief Get current direction of specified motor
 * @param motor Motor identifier (MOTORA or MOTORB)
 * @return Current direction (FORWARD or BACKWARD)
 */
unsigned char Motor_Direction(unsigned char motor);

/**
 * @brief Move specified motor for a duration
 * @param motor_id Motor identifier (MOTORA or MOTORB)
 * @return bool Success status
 */
bool move_motor(int motor_id);

#endif // MOTOR_DRIVER_H__
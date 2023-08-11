#include "mbed.h"
#include "../../KRAI_Library/encoderKRAI/encoderKRAI.h"
#include "../../KRAI_Library/Motor/Motor.h"
#include "../../KRAI_Library/PIDAaronBerk/PIDAaronBerk.h"
#include "../../KRAI_Library/MovingAverage/MovingAverage.h"
#include "Configurations/Constants.h"
#include "Configurations/Setup.h"
#include "ShooterMotor/ShooterMotor.h"

// Inisialisasi Pengendali Motor Shooter
ShooterMotor controlShooterMotor(&leftMotor, &rightMotor, &encLeftMotor, &encRightMotor, &pidLeftMotor, &pidRightMotor, &movAvgLM, &movAvgRM);

int main()
{
    float trySetPoint = 250.0f; // SetPoint PID (RPM)

    while (1)
    {
        
        if (us_ticker_read() - timeLast > samplingPID)
        {
            // printf("%d\n", rotEncAdjSpeed.getPulses());
            // controlShooterMotor.controlOmegaShooter((float)rotEncAdjSpeed.getPulses()); 
            controlShooterMotor.controlOmegaShooter(trySetPoint); 
            timeLast = us_ticker_read();
        }
    }

    return 0;
}
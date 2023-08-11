#ifndef TFMINI_H
#define TFMINI_H

#include "../mbed.h"

// Pinout List
#define tfmini_SDA PB_3  // SDA pin for I2C communication
#define tfmini_SCL PB_10 // SCL pin for I2C communication

// Address List
#define tfmini1_ADD 0x10 // default I2C address for TFmini

// Register List
#define ADD_REG         0x0026  // Register for address change command


class TFmini {
    
    I2C* i2c; // I2C object to handle communication with the sensor
    int  i2cAddress; // I2C address of the sensor
    
    
    public:
        // Constructor for TFmini objects
        // Initializes the I2C object and writes initialization commands to the sensor
        TFmini(PinName TF_SDA, PinName TF_SCL, char address);
        
        // Writes the command to read data to the sensor and reads the returned data
        // Separates the returned data into distance, signal strength, and mode
        void olahData();
        
        // Changes the I2C address of the sensor
        // Sends a command to the sensor to change its address and then updates i2cAddress
        void changeAddress(char new_add);
        
        // Resets the sensor and sets i2cAddress to the default address
        void reset_tf();
        
        // Scans all possible I2C addresses and prints the addresses at which a device is found
        void findAddress();
        
        // Distance reading from the sensor
        int dist_HL;
        
        // Signal strength reading from the sensor
        int strength_HL;
        
        // Mode of the sensor
        int mode_tf;
        
        // Methods that were potentially meant to calculate and return sensor data in various forms
        // Currently commented out
        // float getTheta();
        // float getX();
        // float getY();
        // int getMode()

    private:
        // Buffer to store the data read from the sensor
        char data[7];
};

#endif /* TFMINI_H */

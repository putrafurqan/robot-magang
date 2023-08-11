#include "TFMini.h"
#include <math.h>

// Command codes for the TFmini sensor
const char DIST_REG[3] = {0x01, 0x02, 0x07};       // Register to request distance data
const char RESET_MINI_REG[2] = {0x00, 0x06};       // Register to reset the sensor
const char LIMIT_DISABLED[2] = {0x0055, 0x00};     // Command to disable limit
const char LONG_MODE[2] = {0x0050, 0x07};          // Command to enable long mode

// Constructor to initialize the sensor
TFmini::TFmini(PinName TF_SDA, PinName TF_SCL, char address) {
    i2c = new I2C(TF_SDA, TF_SCL);                  // Initialize I2C object
    i2c->frequency(100);                            // Set I2C frequency to 100kHz
    i2cAddress = address << 1;                      // Shift address to left

    i2c->write(i2cAddress, LIMIT_DISABLED, sizeof(LIMIT_DISABLED));  // Disable limit on sensor
    i2c->write(i2cAddress, LONG_MODE, sizeof(LONG_MODE));            // Enable long mode on sensor

    // Initialize sensor data to 0
    dist_HL = 0;
    strength_HL = 0;
    mode_tf = 0;
}

// Function to read and parse data from the sensor
void TFmini::olahData() {
    i2c->write(i2cAddress, DIST_REG, 3, true);      // Write distance register address to sensor
    i2c->read(i2cAddress, data, 7, false);          // Read data from sensor

    // Parse the received data
    dist_HL = (data[3]) << 8 | (data[2]);           // Extract distance from data
    strength_HL = (data[5]) << 8 | (data[4]);       // Extract signal strength from data
    mode_tf = data[6];                              // Extract mode from data
}

// Function to change the I2C address of the sensor
void TFmini::changeAddress(char new_add) {
    char reg_change[2] = {ADD_REG, new_add << 1};   // Prepare command to change address
    i2c->write(i2cAddress, reg_change, 2);          // Send address change command to sensor
    i2cAddress = new_add << 1;                      // Update i2cAddress to new address
}

// Function to reset the sensor
void TFmini::reset_tf() {
    i2c->write(i2cAddress, RESET_MINI_REG, 2);      // Send reset command to sensor
    i2cAddress = 0x10;                              // Reset i2cAddress to default
}

// Function to find and print the I2C addresses of all connected devices
void TFmini::findAddress() {
    printf("I2CU! Searching for I2C devices...\n");

    int deviceCount = 0;
    for (int address=0; address<256; address+=2) {  // Iterate over all possible I2C addresses
        if (!i2c->write(address, NULL, 0)) {        // Try to write to the current address
            printf(" - I2C device found at address 0x%02X\n", address);  // If successful, print the address
            deviceCount++;                          // Increment count of found devices
        }
    }
    printf("%d devices found\n", deviceCount);      // Print the total number of devices found
}
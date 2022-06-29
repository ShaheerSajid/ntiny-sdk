#ifndef GY_80_H
#define GY_80_H

#include <stdint.h>



struct GY80_scaled
{
    float a_x;
    float a_y;
    float a_z;

    float m_x;
    float m_y;
    float m_z;

    float g_x;
    float g_y;
    float g_z;

    float p;
    float t;
};

struct GY80_raw
{
    int16_t a_x;
    int16_t a_y;
    int16_t a_z;

    int16_t m_x;
    int16_t m_y;
    int16_t m_z;

    int16_t g_x;
    int16_t g_y;
    int16_t g_z;

    uint32_t p;
    uint16_t t;
};

struct GY80_single_raw
{
    int16_t x;
    int16_t y;
    int16_t z;
};

struct GY80_single_scaled
{
    float x;
    float y;
    float z;
};

struct GY80_p_calibration_type
{
    int ac1;
    int ac2;
    int ac3;
    unsigned int ac4;
    unsigned int ac5;
    unsigned int ac6;
    int b1;
    int b2;
    int mb;
    int mc;
    int md;
    long b5;
} p_calib;


    void GY80_init();

    void begin();

    struct GY80_raw read_raw();
    struct GY80_scaled read_scaled();

    //magnetometer HMC5883L
    void m_set_mode(uint8_t mode);
    void m_set_scale(uint8_t scale);
    struct GY80_single_raw m_read_raw();
    struct GY80_single_scaled m_read_scaled();
    //accelerometer
    void a_set_scale(uint8_t scale);
    void a_set_bw(uint8_t bw);
    struct GY80_single_raw a_read_raw();
    struct GY80_single_scaled a_read_scaled();
    //gyro
    void g_set_scale(uint8_t scale);
    struct GY80_single_raw g_read_raw();
    struct GY80_single_scaled g_read_scaled();
    //pressure
    uint32_t p_read_raw();
    float p_read_scaled();
    float p_read_altitude();
    //temperature
    uint16_t t_read_raw();
    float t_read_scaled();


    /// utility fucntions
    void m_init();
    void a_init();
    void g_init();
    void p_init();

    void write(uint8_t device, uint8_t address, uint8_t data);
    uint8_t* read(uint8_t device, uint8_t address, uint8_t length);

   

#endif // GY80_H

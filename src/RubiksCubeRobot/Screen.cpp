//
// Screen.cpp
//
// Define functions for manipulating ILI9341 based resistive touch screen.
//
// Copyright Anders Liu.
//
// For more information, visit https://github.com/anders-liu/arduino-rubikscube-robot
//

#include "Screen.h"

RgbColor Screen_backColor;
RgbColor Screen_foreColor;
uint8_t Screen_textScale;

#define CMD_SOFT_RESET 0x01
#define CMD_SLEEP_IN 0x10
#define CMD_SLEEP_OUT 0x11
#define CMD_DISP_OFF 0x28
#define CMD_DISP_ON 0x29
#define CMD_COL_ADDR_SET 0x2A
#define CMD_PAGE_ADDR_SET 0x2B
#define CMD_MEMORY_WRITE 0x2C
#define CMD_MEMORY_ACCESS_CONTROL 0x36
#define CMD_PIXEL_FORMAT_SET 0x3A

#define PF_16BIT 0x55
#define PF_18BIT 0x66

#define MA_MIRROR_X 0x80
#define MA_MIRROR_Y 0x40
#define MA_ROW_COL_EX 0x20
#define MA_V_ORDER 0x10
#define MA_RGB 0x08
#define MA_H_ORDER 0x04

#define MA_SO_PORTRAIT1 (MA_MIRROR_Y | MA_RGB)
#define MA_SO_PORTRAIT2 (MA_MIRROR_X | MA_RGB)
#define MA_SO_LANDSCAPE1 (MA_ROW_COL_EX | MA_RGB | MA_MIRROR_X | MA_MIRROR_Y)
#define MA_SO_LANDSCAPE2 (MA_ROW_COL_EX | MA_RGB)

#define BEGIN_BUS                     \
    {                                 \
        pinMode(SCREEN_RS, OUTPUT);   \
        pinMode(SCREEN_CS, OUTPUT);   \
        digitalWrite(SCREEN_CS, LOW); \
    }

#define END_BUS                        \
    {                                  \
        digitalWrite(SCREEN_CS, HIGH); \
    }

#define BEGIN_CMD                     \
    {                                 \
        SCREEN_DDR = 0xFF;            \
        digitalWrite(SCREEN_RS, LOW); \
    }

#define BEGIN_DATA_OUT                 \
    {                                  \
        SCREEN_DDR = 0xFF;             \
        digitalWrite(SCREEN_RS, HIGH); \
    }

#define BEGIN_DATA_IN                  \
    {                                  \
        SCREEN_DDR = 0x00;             \
        digitalWrite(SCREEN_RS, HIGH); \
    }

#define WRITE_BYTE(b)                  \
    {                                  \
        SCREEN_PORT = b;               \
        digitalWrite(SCREEN_WR, LOW);  \
        digitalWrite(SCREEN_WR, HIGH); \
    }

#define READ_BYTE(b)                   \
    {                                  \
        digitalWrite(SCREEN_RD, LOW);  \
        b = SCREEN_PIN;                \
        digitalWrite(SCREEN_RD, HIGH); \
    }

#define GET_COLOR_2BYTE(color, b1, b2) \
    {                                  \
        uint16_t cv = toRgb565(color); \
        b1 = cv >> 8;                  \
        b2 = cv;                       \
    }

static void setUpdateArea(uint16_t x, uint16_t y, uint16_t w, uint16_t h);

void Screen_setup()
{
    pinMode(SCREEN_RST, OUTPUT);
    pinMode(SCREEN_CS, OUTPUT);
    pinMode(SCREEN_RS, OUTPUT);
    pinMode(SCREEN_WR, OUTPUT);
    pinMode(SCREEN_RD, OUTPUT);
    digitalWrite(SCREEN_RST, LOW);
    digitalWrite(SCREEN_CS, LOW);
    digitalWrite(SCREEN_RS, LOW);
    digitalWrite(SCREEN_WR, HIGH);
    digitalWrite(SCREEN_RD, HIGH);
    digitalWrite(SCREEN_RST, HIGH);

    BEGIN_BUS;
    BEGIN_CMD;
    WRITE_BYTE(CMD_SOFT_RESET);
    delay(150);
    WRITE_BYTE(CMD_DISP_OFF);
    WRITE_BYTE(CMD_PIXEL_FORMAT_SET);
    BEGIN_DATA_OUT;
    WRITE_BYTE(PF_16BIT);
    BEGIN_CMD;
    WRITE_BYTE(CMD_MEMORY_ACCESS_CONTROL);
    BEGIN_DATA_OUT;
    WRITE_BYTE(MA_SO_LANDSCAPE2);
    BEGIN_CMD;
    WRITE_BYTE(CMD_SLEEP_OUT);
    delay(150);
    WRITE_BYTE(CMD_DISP_ON);
    END_BUS;

    Screen_textScale = 1;
}

void Screen_off()
{
    BEGIN_BUS;
    BEGIN_CMD;
    WRITE_BYTE(CMD_DISP_OFF);
    END_BUS;
}

void Screen_on()
{
    BEGIN_BUS;
    BEGIN_CMD;
    WRITE_BYTE(CMD_DISP_ON);
    END_BUS;
}

void Screen_fillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
    BEGIN_BUS;
    setUpdateArea(x, y, w, h);
    BEGIN_CMD;
    WRITE_BYTE(CMD_MEMORY_WRITE);

    uint8_t b1, b2;
    GET_COLOR_2BYTE(Screen_backColor, b1, b2);
    uint32_t count = (uint32_t)w * (uint32_t)h;
    BEGIN_DATA_OUT;
    while (count--)
    {
        WRITE_BYTE(b1);
        WRITE_BYTE(b2);
    }
    END_BUS;
}

void Screen_drawText(uint16_t x, uint16_t y, const char *str)
{
}

void setUpdateArea(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
    BEGIN_CMD;
    WRITE_BYTE(CMD_COL_ADDR_SET);

    BEGIN_DATA_OUT;
    WRITE_BYTE((uint8_t)(x >> 8));
    WRITE_BYTE((uint8_t)x);
    x = x + w - 1;
    WRITE_BYTE((uint8_t)(x >> 8));
    WRITE_BYTE((uint8_t)x);

    BEGIN_CMD;
    WRITE_BYTE(CMD_PAGE_ADDR_SET);

    BEGIN_DATA_OUT;
    WRITE_BYTE((uint8_t)(y >> 8));
    WRITE_BYTE((uint8_t)y);
    y = y + h - 1;
    WRITE_BYTE((uint8_t)(y >> 8));
    WRITE_BYTE((uint8_t)y);
}

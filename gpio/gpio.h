#pragma once

#include <cstdint>

namespace GpioPin {
const uint8_t PIN_03 = 2;
const uint8_t PIN_05 = 3;
const uint8_t PIN_07 = 4;
const uint8_t PIN_08 = 14;
const uint8_t PIN_10 = 15;
const uint8_t PIN_11 = 17;
const uint8_t PIN_12 = 18;
const uint8_t PIN_13 = 27;
const uint8_t PIN_15 = 22;
const uint8_t PIN_16 = 23;
const uint8_t PIN_18 = 24;
const uint8_t PIN_19 = 10;
const uint8_t PIN_21 = 9;
const uint8_t PIN_22 = 25;
const uint8_t PIN_23 = 11;
const uint8_t PIN_24 = 8;
const uint8_t PIN_26 = 7;
}

enum class GpioDirection
{
  INPUT,
  OUTPUT
};

enum class GpioState
{
  OFF,
  ON
};

void setupGpio(uint8_t iGpioPin, GpioDirection iGpioDirection);

void setGpio(uint8_t iGpioPin, GpioState iGpioState);

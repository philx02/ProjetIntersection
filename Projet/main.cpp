#include "../gpio/gpio.h"

#include <iostream>
#include <thread>

const uint8_t R1R2 = GpioPin::PIN_11;
const uint8_t V3V4 = GpioPin::PIN_12;
const uint8_t J3J4 = GpioPin::PIN_13;
const uint8_t R3R4 = GpioPin::PIN_15;
const uint8_t J1J2 = GpioPin::PIN_16;
const uint8_t V1V2 = GpioPin::PIN_18;

int main()
{
  setupGpio(R1R2, GpioDirection::OUTPUT);
  setupGpio(V3V4, GpioDirection::OUTPUT);
  setupGpio(J3J4, GpioDirection::OUTPUT);
  setupGpio(R3R4, GpioDirection::OUTPUT);
  setupGpio(J1J2, GpioDirection::OUTPUT);
  setupGpio(V1V2, GpioDirection::OUTPUT);

  while (true)
  {
    setGpio(R1R2, GpioState::ON);
    setGpio(J1J2, GpioState::OFF);
    setGpio(R3R4, GpioState::OFF);
    setGpio(V3V4, GpioState::ON);

    std::this_thread::sleep_for(std::chrono::seconds(15));

    setGpio(J3J4, GpioState::ON);
    setGpio(V3V4, GpioState::OFF);

    std::this_thread::sleep_for(std::chrono::seconds(3));

    setGpio(R3R4, GpioState::ON);
    setGpio(J3J4, GpioState::OFF);
    setGpio(V1V2, GpioState::ON);
    setGpio(R1R2, GpioState::OFF);

    std::this_thread::sleep_for(std::chrono::seconds(25));

    setGpio(J1J2, GpioState::ON);
    setGpio(V1V2, GpioState::OFF);

    std::this_thread::sleep_for(std::chrono::seconds(3));
  }

  return 0;
}

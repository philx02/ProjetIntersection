#include "gpio.h"

#include <string>
#include <fstream>

static const std::string sPath("/sys/class/gpio/");

void setupGpio(uint8_t iGpioPin, GpioDirection iGpioDirection)
{
  std::string wGpioPin(std::to_string(static_cast< uint8_t >(iGpioPin)));
  {
    std::ofstream wExport((sPath + "export").c_str());
    wExport << wGpioPin;
  }
  {
    std::ofstream wDirection((sPath + "gpio" + wGpioPin + "/direction").c_str());
    wDirection << (iGpioDirection == GpioDirection::INPUT ? "in" : "out");
  }
}

void setGpio(uint8_t iGpioPin, GpioState iGpioState)
{
  std::string wGpioPin(std::to_string(static_cast< uint8_t >(iGpioPin)));
  std::ofstream wValue((sPath + "gpio" + wGpioPin + "/value").c_str());
  wValue << (iGpioState == GpioState::ON ? "1" : "0");
}

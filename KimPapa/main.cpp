#include "../gpio/gpio.h"

#include <iostream>
#include <thread>

int main()
{
  setupGpio(GpioPin::PIN_07, GpioDirection::OUTPUT);

  std::cout << "Programme de papa et Kim." << std::endl;
  std::cout << "Entrer un chiffre entre 1 et 9: ";
  int chiffre;
  std::cin >> chiffre;
  std::cout << "Je flash la lumiere " << chiffre << " fois." << std::endl;

  while (chiffre > 0)
  {
    setGpio(GpioPin::PIN_07, GpioState::ON);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    setGpio(GpioPin::PIN_07, GpioState::OFF);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    chiffre = chiffre - 1;
  }

  return 0;
}

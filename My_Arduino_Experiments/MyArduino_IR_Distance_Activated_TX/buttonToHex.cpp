#include "buttonToHex.h"

static const unsigned long buttonCodes[] = {
  4278255362, // 0: On-Off
  4211408642, // 1: 10% light
  4194696962, // 2: 20% light
  4177985282, // 3: 30% light
  4144561922, // 4: 40% light
  4127850242, // 5: 50% light
  4111138562, // 6: 60% light
  4077715202, // 7: 70% light
  4061003522, // 8: 80% light
  4044291842, // 9: 90% light
  4244832002, // 10: Max Light
  4010868482, // 11: Flash Mode
  3994156802, // 12: Speed +
  3977445122  // 13: Speed -
};

unsigned long buttonToHex(int buttonNr) {

  if (buttonNr < 0 || buttonNr >= (int)(sizeof(buttonCodes) / sizeof(buttonCodes[0]))) {
    return 0;
  }

  return buttonCodes[buttonNr];
}

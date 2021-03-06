#include "buttonToHex.h"

long buttonToHex(int buttonNr){
  switch (buttonNr+1){
    case 1:
      return 4278255362;
      break;
    case 2:
      return 4244832002;
      break;
    case 3:
      return 4211408642;
      break;
    case 4:
      return 4194696962;
      break;
    case 5:
      return 4177985282;
      break;
    case 6:
      return 4144561922;
      break;
    case 7:
      return 4127850242;
      break;
    case 8:
      return 4111138562;
      break;
    case 9:
      return 4077715202;
      break;
    case 10:
      return 4061003522;
      break;
    case 11:
      return 4044291842;
      break;
    case 12:
      return 4010868482;
      break;
    case 13:
      return 3994156802;
      break;
    case 14:
      return 3977445122;
      break;
    default:
      return 0;
      break;
        }
}

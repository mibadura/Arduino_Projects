const char* interpretReceived(long recv_thing){
  switch (recv_thing){
    case 0xFF00FF02:
      return("#0 On/Off");
      break;
    case 0xFD02FF02:
      return("#1 Light Max");
      break;
    case 0xFB04FF02:
      return("#2 10%");
      break;
    case 0xFA05FF02:
      return("#3 20%");
      break;
    case 0xF906FF02:
      return("#4 30%");
      break;
    case 0xF708FF02:
      return("#5 40%");
      break;
    case 0xF609FF02:
      return("#6 50%");
      break;
    case 0xF50AFF02:
      return("#7 60%");
      break;
    case 0xF30CFF02:
      return("#8 70%");
      break;
    case 0xF20DFF02:
      return("#9 80%");
      break;
    case 0xF10EFF02:
      return("#10 90%");
      break;
    case 0xEF10FF02:
      return("#11 Flash");
      break;
    case 0xEE11FF02:
      return("#12 Button +");
      break;
    case 0xED12FF02:
      return("#13 Button -");
      break;
    default:
      return("unknown");
      break;
  }
}
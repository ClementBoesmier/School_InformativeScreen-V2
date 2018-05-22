void findScheduleT() {
    for (size_t i = 1; i <= Gset; i++) {
        if(timeColour[i][0] == hour){
            if (timeColour[i][1] == min) {
              scheduleOK = i;
              actu = 1;
              timeS = 1;
            }
        }
          Serial.print("Time schedule OK :");
          Serial.println(scheduleOK);
        }
  if (type == 0) {
    scheduleOK = 0;
  }
}

void afficheSchedule(){
  if (actu == 1 && (timeS =! 0 || type ==0)) {
    matrix.setTextSize(1);
    matrix.setCursor(2, 0);
    switch (timeColour[scheduleOK][5]) {
      case 0:
        matrix.fillScreen(matrix.Color333(0,0,0));
      break;
      case 1:
        matrix.setTextColor(matrix.Color333(timeColour[scheduleOK][2],timeColour[scheduleOK][3],timeColour[scheduleOK][4]));
        matrix.print("Accueil ouvert");
      break;
      case 2:
        matrix.setTextColor(matrix.Color333(timeColour[scheduleOK][2],timeColour[scheduleOK][3],timeColour[scheduleOK][4]));
        matrix.print("Accueil Fermee");
    }
    actu == 0;
  }
  if (timeColour[scheduleOK][5] != 0) {
    RTCprint();
  }
}



void RTCprint() {
    if (minEx != min) {
        minEx = min;
        matrix.fillRect(36, 23, 63, 32, matrix.Color333(0, 0, 0));
    }
    matrix.setTextSize(1);
    matrix.setCursor(37, 24);
    if (hour <= 9) {
        matrix.print('0');
        matrix.print(hour, DEC);
    }
    else{
        matrix.print(hour, DEC);
    }

    matrix.drawRect(49, 25, 2, 2, matrix.Color333(7, 7, 7));
    matrix.drawRect(49, 28, 2, 2, matrix.Color333(7, 7, 7));

    matrix.setCursor(52, 24);
    if (min <= 9) {
        matrix.print('0');
        matrix.print(min, DEC);
    }
    else{
        matrix.print(min, DEC);
    }
}

void colorSave(){
    Serial.println(color);
    for (size_t i = 0; i < 3; i++) {
        timeColour[set][i+2] = color.charAt(i)-48;
        Serial.println(color.charAt(i));
    }
}

void saveTime() {
    if (type == 2) {
        for (size_t i = 0; i < 2; i++) {
            timeColour[set][i] = saveTimeT[i];
        }

        if (info.equals("suppr") && set != 0) {
            timeColour[set][0] = 25;
            timeColour[set][1] = 61;
        }
    }

    for (size_t i = 0; i <= set; i++) {
        Serial.print("Set : ");
        Serial.println(i);
        Serial.print("time : ");
        Serial.print(timeColour[i][0]);
        Serial.print(" h ");
        Serial.println(timeColour[i][1]);
        Serial.print("R : ");
        Serial.println(timeColour[i][2]);
        Serial.print("V : ");
        Serial.println(timeColour[i][3]);
        Serial.print("B : ");
        Serial.println(timeColour[i][4]);
    }
}
void rtcsync(){
  if (type == 1 && info.indexOf("h") != -1) {
    Serial.print("change rtc pour : ");
    Serial.print(info);
    rtc.set(&sec, saveTimeT[0], saveTimeT[1], &day, &month, &year);
  }
}

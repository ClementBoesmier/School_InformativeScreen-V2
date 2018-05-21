void colorSave(){
    Serial.println(color);
    for (size_t i = 0; i < 3; i++) {
        timeColour[set][i+2] = color.charAt(i)-48;
        Serial.println(color.charAt(i));
    }
}
void saveTime() {
    for (size_t i = 0; i < 2; i++) {
      timeColour[set][i] = saveTimeT[i]
    }


    for (size_t i = 0; i <= set; i++) {
        Serial.print("Set : ");
        Serial.println(i);
        Serial.print("time : ");
        Serial.print(timeColour[i][0]);
        Serial.print(" h ")
        Serial.println(timeColour[i][1])
        Serial.print("R : ");
        Serial.println(timeColour[i][2]);
        Serial.print("V : ");
        Serial.println(timeColour[i][3]);
        Serial.print("B : ");
        Serial.println(timeColour[i][4]);
    }


}

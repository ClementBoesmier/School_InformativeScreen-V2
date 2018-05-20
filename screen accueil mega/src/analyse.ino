void colorSave(){
    Serial.println(color);
    for (size_t i = 0; i < 3; i++) {
        timeColour[coloneT][i+2] = color.charAt(i)-48;
        Serial.println(color.charAt(i));
    }
    for (size_t i = 0; i <= coloneT; i++) {
        Serial.print("case : ");
        Serial.println(i);
        Serial.print("rouge : ");
        Serial.println(timeColour[i][2]);
        Serial.print("vert : ");
        Serial.println(timeColour[i][3]);
        Serial.print("bleu : ");
        Serial.println(timeColour[i][4]);
    }
}
void saveTime() {
    /* code */
}

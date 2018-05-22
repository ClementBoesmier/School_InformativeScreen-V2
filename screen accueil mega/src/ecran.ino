void afficheSchedule() {
    for (size_t i = 1; i <= set; i++) {
        if(timeColour[i][0] == hour){
            Theure = i;
            Serial.print(Theure);
        }

    }
}

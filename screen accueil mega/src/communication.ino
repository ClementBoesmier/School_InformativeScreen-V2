void lectureTrame() {
    if (Serial.available()) { // If a message is receive on the serial
        bufferTrame = Serial.readString(); // Read it and affect it to bufferTrame String object
        Serial.println(bufferTrame); // When this is finished display it on the serial monitor
    }
}

void decodeTrameType() {
    switch (bufferTrame.charAt(switchCase)) {
        case 'n':
            Serial.println("now OK");
            switchCase = 17 ;
        break;
        case 'c':
            Serial.println("customText OK");
            switchCase = 24;
        break;
        case 's':
            Serial.println("schedule OK");
            switchCase = 22;
    }
}

void decodeTrameColor() {
    int vCleaner = 0;
    switch (bufferTrame.charAt(switchCase)) {
        case 'd':
            color = bufferTrame.substring(switchCase + 5,switchCase + 10);
            for (size_t i = 0; i < 2; i++) {
                vCleaner = color.indexOf(",");
                color.remove(vCleaner,1);
            }
            switchCase = switchCase + 21;
        break;
        case 'n':
            Serial.println("none OK");
            switchCase = switchCase + 14;
            color = "000";
    }
}

void decodeTrameAnimate() {
    switch (bufferTrame.charAt(switchCase)) {
        case 'n':
            Serial.println("none animate");
            switchCase = switchCase + 9;
    }
}

void decodeTrameSet() {
    if (bufferTrame != "") {
        String setString = bufferTrame.substring(switchCase +1 ,switchCase + 3);
        set = setString.toInt();
        Serial.println(set);
        colorSave();

    }

}

void decodeTrameSetInfo (){
    info = bufferTrame;
    if (bufferTrame != ""){
        info.remove(0, switchCase +4);
        info = info.substring(info.indexOf("[")+1,info.indexOf("]"));
        Serial.println(info);
        if (info.indexOf("/") != -1 || info == ("suppr")) {
            String heureP = info.substring(0,2);
            Serial.println (heureP);
            String minP = info.substring(3,5);
            Serial.println(minP);
            saveTimeT[0]=heureP.toInt();
            saveTimeT[1]=minP.toInt();
            saveTime();
        }
    }
}

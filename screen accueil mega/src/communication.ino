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
            coloneT = 0;
        break;
        case 'c':
            Serial.println("customText OK");
            switchCase = 24;
        break;
        case 's':
            Serial.println("schedule OK");
            switchCase = 22;
            coloneCounter++;
            coloneT = coloneCounter;
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

    }

}
void decodeTrameSetInfo (){
    if (bufferTrame != ""){
        String info = bufferTrame;
        info.remove(0, switchCase +4);
        info = info.substring(info.indexOf("[")+1,info.indexOf("]"));
        Serial.println(info);

        bufferTrame = "";
        switchCase = 6;
    }
}
/*    if (bufferTrame.charAt(0) == "n") {
        Serial.println("ok");

        bufferTrame = "";
    }
    else{
        //Serial.println("non");
        //delay(100);
    }
}
/*

Lire le caractère 7
    si c'est un s = schedule
    si c'est un n = now / currently
    si c'est un c = customText
        {Lire le caractère 30
            Valeur de 0 à 7 rouge
        Lire le caractère 32
            Valeur de 0 à 7 verte
        Lire le caractère 34
            Valeur de 0 à 7 bleu}
        Lire le caractère 46

    si c'est un i = initialisation
        Lire le caractère 54
            etalonner l'heure
*/

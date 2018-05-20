void RTCprint() {

    if (minEx != min) {
        minEx = min;
        matrix.fillRect(36, 23, 63, 32, matrix.Color333(0, 0, 0));
    }
    matrix.setTextSize(1);
    matrix.setTextWrap(false);
    matrix.setCursor(2, 0);
    matrix.print("Accueil");

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

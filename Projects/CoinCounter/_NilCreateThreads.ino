NIL_THREADS_TABLE_BEGIN()
NIL_THREADS_TABLE_ENTRY("CoinSensor", CoinSensor, NULL, coinSensor, sizeof(coinSensor))
NIL_THREADS_TABLE_ENTRY("Display", Display, NULL, display, sizeof(display))
NIL_THREADS_TABLE_ENTRY("LedBuzzer", LedBuzzer, NULL, ledBuzzer, sizeof(ledBuzzer))
NIL_THREADS_TABLE_ENTRY("Buttons", Buttons, NULL, buttons, sizeof(buttons))
NIL_THREADS_TABLE_END()

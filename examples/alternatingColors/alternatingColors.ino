#include <PatternSequencer.h>
#include <FadePattern.h>
int8_t pins[8] = { PIN_SERIAL1_RX, PIN_SERIAL1_TX, 11, 13, 5, SDA, A4, A3 };
Adafruit_NeoPXL8 strip(93, pins, NEO_BRG);
PatternSequencer runner(&strip);
AllPixelGroup all;

int intensity = 30;
FadePattern blueToRed(&all, 0,0,intensity,  0,intensity,0, 0, 2000);
FadePattern redToBlue(&all, 0,intensity,0,  0,0,intensity, 0, 2000);

void setup() {
  strip.begin();

  runner.addPattern(&blueToRed);
  runner.addPattern(&redToBlue);

  delay(2000);
  Serial.begin(115200);
  Serial.println("done setup");
}

void loop() {

  runner.run();
}

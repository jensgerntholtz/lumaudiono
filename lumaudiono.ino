#include <Adafruit_NeoPixel.h>
// This corresponds to the data pin you've connected your LEDs with
#define PIN 6
#define LED_COUNT 600

Adafruit_NeoPixel strip = Adafruit_NeoPixel(136, PIN, NEO_GRB + NEO_KHZ800);

int incomingByte = 0;
int currentByte = 0;

void setup()
{
    Serial.setTimeout(10);
    // This seems to bum out at any higher rate
    Serial.begin(19200);
    while (!Serial)
    {
        ;
    }
    strip.begin();
    strip.show();
}

void loop()
{
    if (Serial.available() > 0)
    {
        //  Expecting audio peeking scale in the form of an int from 0-50 (sent at the matching baud-rate, 19200)
        incomingByte = Serial.parseInt();

        if (incomingByte != currentByte)
        {
            currentByte = incomingByte;
            int byteAsPercent = (currentByte * 100 / 50);
            strip.clear();

            // Depending on high the audio peak is the more leds are light up in the rainbow colour wheel
            for (int i = 0; i < LED_COUNT * byteAsPercent / 100; i++)
            {
                strip.setPixelColor(i, Wheel(((i * 256 / LED_COUNT)) & 255));
            }

            strip.show();
        }
    }
}

uint32_t Wheel(byte WheelPos)
{
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85)
    {
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if (WheelPos < 170)
    {
        WheelPos -= 85;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

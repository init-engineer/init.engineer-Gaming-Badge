#include <Libraries/FastLED/FastLED.h>

#define LED_PIN 10             // Arduino 腳位 10
#define NUM_LEDS 8             // 燈珠數量 8
#define BRIGHTNESS 255         // 亮度 255
#define LED_TYPE WS2811        // 燈條模式
#define COLOR_ORDER GRB        // 顏色排列
#define UPDATES_PER_SECOND 100 // 更新速度

CRGB leds[NUM_LEDS];

CRGBPalette16 currentPalette;
TBlendType currentBlending;

void setup()
{
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */
  fillLEDsFromPaletteColors(startIndex);
  currentPalette = RainbowStripeColors_p;
  currentBlending = LINEARBLEND;
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}

void fillLEDsFromPaletteColors(uint8_t colorIndex)
{
  uint8_t brightness = 255;

  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = ColorFromPalette(currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 8;
  }
}
#include <FastLED.h> //FastLED 3.3.2 Ver.

#define LED_PIN 10 //ArduinoProMini版本腳位10 ATtiny85版本腳位1
#define NUM_LEDS 8 //燈珠數量8
#define BRIGHTNESS 255 //亮度0~255 (預設255)
#define LED_TYPE WS2811 //燈條模式
#define COLOR_ORDER GRB //顏色排列
#define UPDATES_PER_SECOND 100 //更新速度
CRGB leds[NUM_LEDS];

CRGB black = CRGB::Black;

CRGB RGBcolor1(255, 0, 0); //1號燈色RGB值(紅0~255,綠0~255,藍0~255)
CRGB RGBcolor2(255, 97, 0); //2號燈色RGB值(紅0~255,綠0~255,藍0~255)
CRGB RGBcolor3(255, 255, 0); //3號燈色RGB值(紅0~255,綠0~255,藍0~255)
CRGB RGBcolor4(0, 255, 0); //4號燈色RGB值(紅0~255,綠0~255,藍0~255)
CRGB RGBcolor5(0, 0, 255); //5號燈色RGB值(紅0~255,綠0~255,藍0~255)
CRGB RGBcolor6(25, 25, 112); //6號燈色RGB值(紅0~255,綠0~255,藍0~255)
CRGB RGBcolor7(160, 32, 240); //7號燈色RGB值(紅0~255,綠0~255,藍0~255)
CRGB RGBcolor8(255, 255, 255); //8號燈色RGB值(紅0~255,綠0~255,藍0~255)

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

int LightMode;
int ModeCount;

//呼吸燈或脈衝設定值
int fadeAmount = 5; //呼吸燈或脈衝漸變層次
int brightnessBreathe = 0;
int BreatheSpeed = 30; //呼吸燈或脈衝速度

void setup()
{
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
  /*
    以下代號擇一替換
    1.彩虹跑馬燈(預設)
    2.彩虹漸變
    3.單色恆亮(至前面行數之"1號燈色RGB值"調整)
    4.脈衝(至前面行數之"1號燈色RGB值"調整)
    5.圓環(至前面行數之"1~4號燈色RGB值"調整)
    6.單色呼吸燈(至前面行數之"1號燈色RGB值"調整)
    7.蠟燭(至前面行數之"1號燈色RGB值"調整)
    8.指定燈色恆亮(至前面行數之"1~8號燈色RGB值"調整)
    9.燈朱隨機燈色
  */
  LightMode = 1/*(代號)*/;
  //DemoMode();
  LightModeCode();
}

void LightModeCode()
{
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1;
  FillLEDsFromPaletteColors(startIndex);
  switch (LightMode)
  {
    case 1: //1.彩虹跑馬燈(預設)
      ModeCount = 1;
      currentPalette = RainbowStripeColors_p;
      currentBlending = LINEARBLEND;
      FastLED.delay(1000 / UPDATES_PER_SECOND);
      break;
    case 2: //2.彩虹漸變
      ModeCount = 2;
      currentPalette = RainbowColors_p;
      currentBlending = LINEARBLEND;
      FastLED.delay(1000 / UPDATES_PER_SECOND);
      break;
    case 3: //3.單色恆亮(至前面行數之"1號燈色RGB值"調整)
      fill_solid(leds, NUM_LEDS, RGBcolor1);
      FastLED.show();
      delay(10);
      break;
    case 4: //4.脈衝(至前面行數之"1號燈色RGB值"調整)
      brightnessBreathe = brightnessBreathe - fadeAmount;
      if (brightnessBreathe <= 0)
      {
        brightnessBreathe = 255;
      }
      fill_solid(leds, NUM_LEDS, RGBcolor1);
      FastLED.setBrightness(brightnessBreathe);
      FastLED.show();
      delay(30);
      break;
    case 5: //5.圓環(至前面行數之"1~4號燈色RGB值"調整)
      ModeCount = 1;
      currentPalette = CRGBPalette16(RGBcolor1, RGBcolor1, black, black,
                                     RGBcolor2, RGBcolor2, black, black,
                                     RGBcolor3, RGBcolor3, black, black,
                                     RGBcolor4, RGBcolor4, black, black);
      currentBlending = LINEARBLEND;
      FastLED.delay(1000 / UPDATES_PER_SECOND);
      break;
    case 6: //6.單色呼吸燈(至前面行數之"1號燈色RGB值"調整)
      brightnessBreathe = brightnessBreathe + fadeAmount;
      if (brightnessBreathe <= 0 || brightnessBreathe >= 255)
      {
        fadeAmount = -fadeAmount;
      }
      fill_solid(leds, NUM_LEDS, RGBcolor1);
      FastLED.setBrightness(brightnessBreathe);
      FastLED.show();
      delay(30);
      break;
    case 7: //7.蠟燭(至前面行數之"1號燈色RGB值"調整)
      fill_solid(leds, NUM_LEDS, RGBcolor1);
      FastLED.setBrightness(random(127,255));
      FastLED.show();
      delay(100);
      break;
    case 8: //8.指定燈色恆亮(至前面行數之"1~8號燈色RGB值"調整)
      leds[0] = RGBcolor1;
      leds[1] = RGBcolor2;
      leds[2] = RGBcolor3;
      leds[3] = RGBcolor4;
      leds[4] = RGBcolor5;
      leds[5] = RGBcolor6;
      leds[6] = RGBcolor7;
      leds[7] = RGBcolor8;
      FastLED.show();
      delay(10);
      break;
    case 9: //9.燈朱隨機燈色
      for (int i = 0; i <= 7; i++)
      {
        leds[i] = CRGB(random(256),random(256),random(256));
      }
      FastLED.show();
      delay(500);
      break;
    default:
      break;
  }
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
  uint8_t brightness = 255;
  for ( int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);

    switch (ModeCount)
    {
      case 1:
        colorIndex += 8;
        break;
      case 2:
        colorIndex += 0;
        break;
    }
  }
}

void DemoMode()
{
  uint8_t secondHand = (millis() / 1000) % 45;
  static uint8_t lastSecond = 99;
  if (lastSecond != secondHand)
  {
    lastSecond = secondHand;
    if(secondHand == 0) {LightMode = 1;}
    if(secondHand == 5) {LightMode = 2;}
    if(secondHand == 10){LightMode = 3;}
    if(secondHand == 15){LightMode = 4;}
    if(secondHand == 20){LightMode = 5;}
    if(secondHand == 25){LightMode = 6;}
    if(secondHand == 30){LightMode = 7;}
    if(secondHand == 35){LightMode = 8;}
    if(secondHand == 40){LightMode = 9;}
  }
}

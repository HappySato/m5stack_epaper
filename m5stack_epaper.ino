#include <GxFont_GFX.h>
#include <GxEPD.h>
#include <GxGDEW075Z09/GxGDEW075Z09.h>
#include <Fonts/FreeMonoBold24pt7b.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

GxIO_Class io(SPI, SS, 17, 16);
GxEPD_Class display(io, 16, 2);

void setup()
{
  display.init(115200);
  display.drawPaged(showFontCallback);
}

void loop(){}

void showFontCallback()
{
  const char* name = "M5STAFF";
  const GFXfont* f = &FreeMonoBold24pt7b;
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(15, 50);
  display.println(name);
  display.setCursor(170, 350);
  display.println("GitHub:HappySato");

  display.setTextColor(GxEPD_RED);
  display.setCursor(75, 200);
  display.println("Let's tey M5Stack");
}


#include <main.h>
#include <stm32h735g_discovery.h>
#include <stm32h735g_discovery_lcd.h>
#include <stm32h735g_discovery_ts.h>

extern "C" int appmain(void) {
  if (BSP_LCD_InitEx(0, LCD_ORIENTATION_LANDSCAPE, LCD_PIXEL_FORMAT_RGB565,
                     LCD_DEFAULT_WIDTH, LCD_DEFAULT_HEIGHT) != 0) {
    Error_Handler();
  }

  uint32_t lcd_width, lcd_height;
  BSP_LCD_GetXSize(0, &lcd_width);
  BSP_LCD_GetYSize(0, &lcd_height);
  BSP_LCD_DisplayOn(0);
  BSP_LCD_SetActiveLayer(0, 0);

  TS_Init_t hTS;
  hTS.Width = LCD_DEFAULT_WIDTH;
  hTS.Height = LCD_DEFAULT_HEIGHT;
  hTS.Orientation = TS_SWAP_XY | TS_SWAP_Y;
  hTS.Accuracy = 0;
  /* Touchscreen initialization */
  if (BSP_TS_Init(0, &hTS) != 0) {
    Error_Handler();
  }

  return 0;
}
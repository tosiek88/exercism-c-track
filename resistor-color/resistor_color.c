#include "resistor_color.h"

int color_code(resistor_band_t color) { return (int)color; }

resistor_band_t COLORS[] = {BLACK, BROWN, RED,    ORANGE, YELLOW,
                            GREEN, BLUE,  VIOLET, GREY,   WHITE};

resistor_band_t *colors() { return COLORS; }

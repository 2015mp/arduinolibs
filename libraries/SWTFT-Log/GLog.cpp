#if ARDUINO >= 100
size_t GLog::write(uint8_t c) {
#else
void GLog::write(uint8_t c) {
#endif
  if (c == '\n') {
    cursor_y += textsize*8;
	if (cursor_y > _height)
		cursor_y=0;
    cursor_x  = 0;
  } else if (c == '\r') {
    // skip em
  } else {
    Adafruit_GFX::drawChar(cursor_x, cursor_y, c, textcolor, textbgcolor, textsize);
    cursor_x += textsize*6;
    if (wrap && (cursor_x > (_width - textsize*6))) {
      cursor_y += textsize*8;
      cursor_x = 0;
    }
  }
#if ARDUINO >= 100
  return 1;
#endif
}
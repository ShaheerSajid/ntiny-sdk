#ifndef LCD_H_ 					// Dot Matrix Display
#define LCD_H_


void lcd(int Rs, int En, int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7);
void lcd_data_write(unsigned char);
void lcd_cmd_write(unsigned char);
void lcd_print(char*);
void lcd_init();
void lcd_scroll();
void lcd_setCursor(unsigned char, unsigned char);
void lcd_clear();

#endif

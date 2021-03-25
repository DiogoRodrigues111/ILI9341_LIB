// Created by Diogo Rodrigues Roessler

/**
 * Register data
 * */
#define EEPROM_Data_Register        0x20  // 0x20 (0x40)
#define The_EEPROM_Control_Register 0x1F

/**
 * PORT ATmega328P
 * */
#define PORTB       0x05
#define DDRB        0x04

/**
 * LCD
 * */
#define RS
#define CS
#define RES
#define SDI_SDA

/**
 * LCD PORT
 * */
#define D7           0x07
#define D6           0x06
#define D5           0x05
#define D4           0x04
#define D3           0x03
#define D2           0x02
#define D1           0x01
#define D0           0x00

/**
 * LCD Command Set
 * Regulative Command Set
 * */
#define Display_OFF    0x28
#define Display_ON     0x29
#define Normal_Display_Mode_ON 0x13
#define Sleep_OUT      0x11
#define Enter_Sleep_Mode   0x10
#define Read_Display_Signal_Mode    0x0E
#define Read_Display_Image_Format   0x0D
#define Read_Display_Pixel_Format   0x0C
#define Read_Display_MADCTL         0x0B
#define Read_Display_Power_Mode     0x0A
#define Read_Display_Status         0x09
#define Read_Display_Identification_Information      0x04
#define Software_Reset              0x01
#define No_Operation                0x00
#define Display_Inversion_OFF       0x20
#define Display_Inversion_ON        0x21
#define Gamma_Set                   0x26
#define Column_Address_Set          0x2A
#define Page_Address_Set            0x2B
#define Memory_Write                0x2C
#define Color_SET                   0x2D
#define Memory_Read                 0x2E
#define Partial_Area                0x30
#define Partial_Area_End            0x3F
#define Vertical_Scrolling_Definition     0x33
#define Tearing_Effect_Line_OFF     0x34
#define Tearing_Effect_Line_ON      0x35
#define Memory_Access_Control       0x36
#define Vertical_Scrolling_Start_Address      0x37
#define Idle_Mode_OFF               0x38
#define Idle_Mode_ON                0x39
#define Pixel_Format_Set            0x3A
#define Write_Memory_Continue       0x3C
#define Read_Memory_Continue        0x3E
#define Set_Tear_Scanline           0x44
#define Get_Scanline                0x45
#define Write_Display_Brightness    0x51
#define Read_Display_Brightness     0x52
#define Write_CTRL_Display          0x53
#define Read_CTRL_Display           0x54
#define Write_Content_Adaptive_Brightness_Control     0x55
#define Read_Content_Adaptive_Brightness_Control      0x56
#define Write_CABC_Minimum_Brightness                 0x5E
#define Read_CABC_Minimum_Brightness                  0x5F
#define Read_ID1                                      0xDA
#define Read_ID2                                      0xDB
#define Read_ID3                                      0xDC

/**
 * LCD Command Set
 * Extended Command Set
 * */
#define RGB_Interface_Signal_Control           0xB0
#define Frame_Control__In_Normal_Mode          0xB1
#define Frame_Control__In_Idle_Mode            0xB2
#define Frame_Control__In_Partial_Mode         0xB3
#define Display_Inversion_Control              0xB4
#define Blanking_Porch_Control                 0xB5
#define Display_Function_Control               0xB6
#define Entry_Mode_Set                         0xB7
#define Backlight_Control_1                    0xB8
#define Backlight_Control_2                    0xB9
#define Backlight_Control_3                    0xBA
#define Backlight_Control_4                    0xBB
#define Backlight_Control_5                    0xBC
#define Backlight_Control_7                    0xBE
#define Backlight_Control_8                    0xBF
#define Power_Control_1                        0xC0
#define Power_Control_2                        0xC1
#define VCOM_Control_1                         0xC5
#define VCOM_Control_2                         0xC7
#define NV_Memory_Write                        0xD0
#define NV_Memory_Protection_Key               0xD1
#define NV_Memory_Status Read                  0xD2
#define Read_ID4                               0xD3
#define Positive_Gamma_Correction              0xE0
#define Negative_Gamma_Correction              0xE1
// 1st Parameter 1  1 (^Up) :                      16th Parameter   1  1 (^Up)
// RCA0 [3:0] BCA0 [3:0]    RCAx [3:0] BCAx [3:0]  RCA15 [3:0] BCA15 [3:0]
#define Digital_Gamma_Control_1                0xE2

// 1st Parameter 1  1 (^Up) :                      64th Parameter   1  1 (^Up)
// RFA0 [3:0] BFA0 [3:0]    RFAx [3:0] BFAx [3:0]  RFA63 [3:0] BFA63 [3:0]
#define Digital_Gamma_Control_2                0xE3

#define Interface_Control                      0xF6

/* Implements */
#define _SERIALIZE_IMPLEMENT(C)                (*(volatile unsigned short *)(C))

/* PORTB SERIALIZE */
#define _SERIALIZE_PORTB(B)                    _SERIALIZE_IMPLEMENT((B) + EEPROM_Data_Register)
#define _PORTB_STATUS_W                        _SERIALIZE_PORTB(PORTB)
#define _PORTB_SUCCESS                         _PORTB_STATUS_W

/* DDRB SERIALIZE */
#define _SERIALIZE_DDRB(B)                     _SERIALIZE_IMPLEMENT((B) + EEPROM_Data_Register)
#define _DDRB_STATUS_W                         _SERIALIZE_DDRB(DDRB)
#define _DDRB_SUCCESS                          _DDRB_STATUS_W

/* RS SERIALIZE */
#define _SERIALIZE_RS(B)                       _SERIALIZE_IMPLEMENT((B) + EEPROM_Data_Register)
#define _RS_STATUS_W                           _SERIALIZE_RS(DDRB)
#define _RS_SUCCESS                            _RS_STATUS_W

/* CS SERIALIZE */
#define _SERIALIZE_CS(B)                      _SERIALIZE_IMPLEMENT((B) + EEPROM_Data_Register)
#define _CS_STATUS_W                          _SERIALIZE_CS(DDRB)
#define _CS_SUCCESS                           _CS_STATUS_W


enum color_types {
  /* GRAY Colors */
  BLACK   = 0x000000,
  GREY_11 = 0x1C1C1C,
  GREY_21 = 0x363636,
  GREY_32 = 0x4F4F4F,
  DIMGRAY = 0x696969,
  GRAY    = 0x808080,
  DRAKGRAY= 0xA9A9A9,
  SILVER  = 0xC0C0C0,
  LIGHTGREY = 0xD3D3D3,
  GAINSBORO = 0xDCDCDC,
  /* Blue colors */
  SLATEBLUE   = 0x6A5ACD,
  SLATEBLUE1  = 0x836FFF,
  SLATEBLUE3  = 0x6959CD,
  DARKSLATEBLUE = 0x483D8B,
  MIDNIGHTBLUE  = 0x191970,
  NAVY          = 0x000080,
  DARKBLUE      = 0x00008B,
  MEDIUMBLUE    = 0x0000CD,
  BLUE          = 0x0000FF,
  CORNFLOWERBLUE= 0x6495ED,
  ROYALBLUE     = 0x4169E1,
  DODGERBLUE    = 0x1E90FF,
  DEEPSKYBLUE   = 0x00BFFF,
  LIGHTSKYBLUE  = 0x87CEFA,
  SKYBLUE       = 0x87CEEB,
  LIGHTBLUE     = 0xADD8E6,
  STEELBLUE     = 0x4682B4,
  LIGHTSTEELBLUE= 0xB0C4DE,
  SLATEGRAY     = 0x708090,
  LIGHTSLATEGRAY= 0x778899,
  /* CYAN colors*/
  AQUACYAN      = 0x00FFFF,
  DARKTURQUOISE = 0x00CED1,
  TURQUOISE     = 0x40E0D0,
  MEDIUMTURQUOISE = 0x48D1CC,
  LIGHTSEAGREEN = 0x20B2AA,
  DARKCYAN      = 0x008B8B,
  TEAL          = 0x008080,
  AQUAMARINE    = 0x7FFFD4,
  MEDIUMAQUAMARINE = 0x66CDAA,
  CADETBLUE     = 0x5F9EA0,
  /* GREEN colors */
  MEDIUMSPRINGGREEN  = 0x00FA9A,
  SPRINGGREEN        = 0x00FF7F,
  PALEGREEN          = 0x98FB98,
  LIGHTGREEN         = 0x90EE90,
  DARKSEAGREEN       = 0x8FBC8F,
  MEDIUMSEAGREEN     = 0x3CB371,
  SEAGREEN           = 0x2E8B57,
  DARKGREEN          = 0x006400,
  GREEN              = 0x008000,
  FORESTGREEN        = 0x228B22,
  LIMEGREEN          = 0x32CD32,
  LIME               = 0x00FF00,
  LAWNGREEN          = 0x7CFC00,
  CHARTREUSE         = 0x7FFF00,
  GREENYELLOW        = 0xADFF2F,
  YELLOWGREEN        = 0x9ACD32,
  OLIVEDRAB          = 0x6B8E23,
  DARKOLIVEGREEN     = 0x556B2F,
  OLIVE              = 0x808000,
  /* BROWN colors */
  DARKKHAKI          = 0xBDB76B,
  GOLDENROD          = 0xDAA520,
  DARKGOLDENROD      = 0xB8860B,
  SADDLEBROWN        = 0x8B4513,
  SIENNA             = 0xA0522D,
  ROSYBROWN          = 0xBC8F8F,
  PERU               = 0xCD853F,
  CHOCOLATE          = 0xD2691E,
  SANDYBROWN         = 0xF4A460,
  NAVAJOWHITE        = 0xFFDEAD,
  WHEAT              = 0xF5DEB3,
  BURLYWOOD          = 0xDEB887,
  TAN                = 0xD2B48C,
  /* PURPLE colors */
  MEDIUMSLATEBLUE    = 0x7B68EE,
  MEDIUMPURPLE       = 0x9370DB,
  BLUEVIOLET         = 0x8A2BE2,
  INDIGO             = 0x4B0082,
  DARKVIOLET         = 0x9400D3,
  DARKORCHID         = 0x9932CC,
  MEDIUMORCHID       = 0xBA55D3,
  PURPLE             = 0xA020F0,
  DARKMAGENTA        = 0x8B008B,
  FUCHSIAMAGENTA     = 0xFF00FF,
  VIOLET             = 0xEE82EE,
  ORCHID             = 0xDA70D6,
  PLUM               = 0xDDA0DD,
  /* PINK colors */
  /* RED colors */
  MAROON             = 0x800000,
  DARKRED            = 0x8B0000,
  FIREBRINK          = 0xB22222,
  BROWN              = 0xA52A2A,
  SALMON             = 0xFA8072,
  DARKSALMON         = 0xE9967A,
  LIGHTSALMON        = 0xFFA07A,
  CORAL              = 0xFF7F50,
  TOMATO             = 0xFF6347,
  RED                = 0xFF0000,
  /* ORANGE colors */
  ORANGERED          = 0xFF4500,
  DARKORANGE         = 0xFF8C00,
  ORANGE             = 0xFFA500,
  /* YELLOW colors */
  GOLD               = 0xFFD700,
  YELLOW             = 0xFFFF00,
  KHAKI              = 0xF0E68C
};

int main (void) {

  while(1) {

  }
}
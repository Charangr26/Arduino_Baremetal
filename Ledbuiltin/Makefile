MCU = atmega328p
F_CPU = 16000000UL
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os
OBJCPY = avr-objcopy
AVRDUDE = "C:\WinAVR\bin\avrdude.exe"
AVRDUDE_CONF = "C:\WinAVR\bin\avrdude.conf"
PORT = COM3  # Change this to your actual Arduino port
TARGET  = ledbuiltin

all: $(TARGET).hex

$(TARGET).elf: $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET).elf $(TARGET).c

$(TARGET).hex: $(TARGET).elf
	$(OBJCPY) -O ihex -R .eeprom $(TARGET).elf $(TARGET).hex

upload: $(TARGET).hex
	$(AVRDUDE) -C $(AVRDUDE_CONF) -v -p atmega328p -c arduino -P$(PORT) -b 115200 -D -U flash:w:$(TARGET).hex:i

clean:
	rm -f $(TARGET).elf $(TARGET).hex

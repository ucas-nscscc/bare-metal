TOOL    :=  loongarch32r-linux-gnusf-
CC      :=  $(TOOL)gcc
OBJCOPY :=  $(TOOL)objcopy
OBJDUMP :=  $(TOOL)objdump
QEMU    :=  /home/haooops/Documents/qemu-la64/build/qemu-system-loongarch64

.PHONY: clean qemu

all: inst_ram.coe inst_ram.mif

main.elf: start.S main.c bare-metal.ld
	$(CC) -nostdlib -T bare-metal.ld start.S main.c -O0 -o $@

main.bin: main.elf
	$(OBJCOPY) -O binary main.elf main.bin

inst_ram.coe inst_ram.mif: main.bin convert
	./convert

convert: convert.c
	gcc ./convert.c -o convert

test.S: main.elf
	$(OBJDUMP) -d main.elf > $@

qemu: main.bin
	$(QEMU) -m 1G -bios main.bin -nographic

qemu-debug: main.bin
	$(QEMU) -m 2G -bios main.bin -nographic -s -S

clean:
	rm -rf main.elf main.bin test.S inst_ram.coe inst_ram.mif rom.vlog convert

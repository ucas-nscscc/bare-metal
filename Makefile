TOOL    :=  loongarch32r-linux-gnusf-
CC      :=  $(TOOL)gcc
OBJCOPY :=  $(TOOL)objcopy
OBJDUMP :=  $(TOOL)objdump
QEMU    :=  /home/haooops/Documents/qemu-la64/build/qemu-system-loongarch64

.PHONY: clean qemu

start.elf: start.S main.c lab0.ld
	$(CC) -nostdlib -T lab0.ld start.S main.c -O1 -o $@

start.bin: start.elf
	$(OBJCOPY) -O binary start.elf start.bin

test.S: start.elf
	$(OBJDUMP) -d start.elf > $@

qemu: start.bin
	$(QEMU) -m 1G -bios start.bin -nographic

qemu-debug: start.bin
	$(QEMU) -m 2G -bios start.bin -nographic -s -S

clean:
	rm start.elf

CROSS_COMPILE:=loongarch32r-linux-gnusf-
CC           :=$(CROSS_COMPILE)gcc
LD           :=$(CROSS_COMPILE)ld
OBJCOPY      :=$(CROSS_COMPILE)objcopy
OBJDUMP      :=$(CROSS_COMPILE)objdump
QEMU         :=qemu-system-loongarch64

HOST_CC:=gcc

BUILD_HOME:=./build
OBJ_HOME  :=$(BUILD_HOME)/obj
SRC_HOME  :=./src
INC_HOME  :=$(SRC_HOME)/include
INCLUDE    =$(addprefix -I, $(INC_HOME))
TOOLS_HOME:=./tools

CFLAGS :=-nostdlib -O0 $(INCLUDE)
LDFLAGS:=$(CFLAGS)

SRCS     :=$(shell find $(SRC_HOME) -name "*.c")
BOOT_SRCS:=$(SRC_HOME)/boot.S
TOOLS    :=$(shell find $(TOOLS_HOME) -name "*.c")

OBJS     :=$(SRCS:$(SRC_HOME)/%.c=$(OBJ_HOME)/%.o)
BOOT_OBJS:=$(BOOT_SRCS:$(SRC_HOME)/%.S=$(OBJ_HOME)/%.o)

ELF:=$(BUILD_HOME)/main.elf
BIN:=$(BUILD_HOME)/main.bin
TOOLS:=$(BUILD_HOME)/convert

.PHONY: clean qemu

all: inst_ram.coe inst_ram.mif $(BUILD_HOME)/test.S

inst_ram.coe inst_ram.mif: $(BIN) $(TOOLS)
	@cd $(BUILD_HOME) && ./convert

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(ELF): $(BOOT_OBJS) $(OBJS) bare-metal.ld
	$(LD) $(LDLAGS) -T bare-metal.ld $(BOOT_OBJS) $(OBJS) -o $@

$(OBJ_HOME)/%.o: $(SRC_HOME)/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_HOME)/%.o: $(SRC_HOME)/%.S
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_HOME)/convert: $(TOOLS_HOME)/convert.c
	$(HOST_CC) $< -o $@

$(BUILD_HOME)/test.S: $(ELF)
	$(OBJDUMP) -d $< > $@

qemu: main.bin
	$(QEMU) -m 1G -bios main.bin -nographic

qemu-debug: main.bin
	$(QEMU) -m 2G -bios main.bin -nographic -s -S

clean:
	rm -rf build

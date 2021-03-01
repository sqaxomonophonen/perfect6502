OBJS=perfect6502.o netlist_sim.o
OBJS+=cbmbasic/cbmbasic.o cbmbasic/runtime.o cbmbasic/runtime_init.o cbmbasic/plugin.o cbmbasic/console.o cbmbasic/emu.o
#OBJS+=measure.o
OPT=-O3
#OPT=-pg -O0 # << for gprof profiling
CFLAGS=-Wall $(OPT)
CC=cc

all: cbmbasic

cbmbasic: $(OBJS)
	$(CC) $(OPT) -o cbmbasic/cbmbasic $(OBJS)

clean:
	rm -f $(OBJS) cbmbasic/cbmbasic


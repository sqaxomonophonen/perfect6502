#include "../perfect6502.h"
#include "runtime.h"
#include "runtime_init.h"

// #define CYCLE_LIMIT 15000 // gprof doesn't like ^C, so define this to quit automatically

int main(int argc, char** argv) {
	int clk = 0;

	void *state = initAndResetChip();

	/* set up memory for user program */
	init_monitor();

	/* emulate the 6502! */
	int cycle = 0;
	for (;;) {
		step(state);
		clk = !clk;
		if (clk)
			handle_monitor(state);

		cycle++;
		#ifdef CYCLE_LIMIT
		if (cycle > CYCLE_LIMIT) break;
		#endif

//		chipStatus(state);
	};

	return 0;
}

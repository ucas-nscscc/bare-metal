#include <mysoc.h>
#include <soc.h>
#include <time.h>

//delay (reps) ms
void delay(int reps) {
  volatile unsigned int i;

  SOC_TIMER = 0;
  while(get_us()<1000*reps)    //1ms*reps
    ;	// delay 
}

int main()
{
	unsigned int i = 0;
	SOC_LED = 0xffff;

	while(1) {
		SOC_LED = 0xffff;
		SOC_LED = ~(1 << i);
		// delay(1000);
		
		i = (i + 1) % 16;
	}

	return 0;
}

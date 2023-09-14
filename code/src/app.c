#include "../lib/demo_system.h"
#include "../lib/dev_access.h"
#include "../lib/timer.h"

#define CALL(NAME, FUN) CONCAT(NAME, FUN)
#define CONCAT(NAME, FUN)  NAME ## _ ## FUN()

#define _STRINGIFY(s) #s
#define STRINGIFY(s) _STRINGIFY(s)

/*U-Mode Code*/
int app(){
    uint64_t start_time = 0;
    uint64_t end_time = 0;
    uint64_t elapsed_time = 0; 
    uint64_t start_clock_cycle=0;
    uint64_t end_clock_cycle = 0;
    uint64_t elapsed_clock_cycles = 0; 


    puts("[U-Mode] "STRINGIFY(BENCHNAME)" Benchmark Test Start!\n");
    start_clock_cycle = timer_read();
    start_time = get_elapsed_time();

    // Exec the Benchmark 
    CALL(BENCHNAME, init);
    CALL(BENCHNAME, main);

    end_time = get_elapsed_time();
    end_clock_cycle = timer_read();
    elapsed_time = end_time - start_time;
    elapsed_clock_cycles = end_clock_cycle - start_clock_cycle;
    
    puts("time: ");
    //putdec(elapsed_time); 
    //puts("\n");   
    //puts("clock cycle: ");
    putdec(elapsed_clock_cycles);
    puts("\n");   
 
    return 0;
}

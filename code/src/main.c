#include <string.h>
#include "../lib/demo_system.h"
#include "../lib/dev_access.h"
#include "../lib/pmp.h"
#include "../lib/grt.h"
#include "../lib/timer.h"

#define _STRINGIFY(s) #s
#define STRINGIFY(s) _STRINGIFY(s)
#define RPM_SIZE 32
#define DEBUGTRIE 0

extern char _bss_start;  
extern char _bss_end;

// Assembly function to transition to user mode
extern void transition_to_user_mode(void);

static void clear_bss(){    
    char *dest = &_bss_start;
    while (dest < &_bss_end) {
        *dest++ = 0;
    }
}

int nopmr_pmp_config(){
    //TASK-1
    // Regions 
    set_pmp_addr(0,0x00100000,0x10000);
    set_pmp_addr(1,0x00110000,0x10000);
    set_pmp_addr(2,0x80000000,0x40000);
    set_pmp_addr(3,0x80040000,0x40000);
    // Permissions
    set_pmp_cfg(0,0x1b1b1f1f);

    //TASK-2
    // Regions 
    set_pmp_addr(4,0x00120000,0x10000);
    set_pmp_addr(5,0x00130000,0x10000);
    set_pmp_addr(6,0x80080000,0x40000);
    set_pmp_addr(7,0x80040000,0x40000);
    // Permissions
    set_pmp_cfg(1,0x1b1b1f1f);

    return 0;
}

int tabpmr_pmp_config(){
    //TASK-1
    // Regions 
    set_pmp_addr(0,0x00100000,0x10000);
    set_pmp_addr(1,0x00110000,0x10000);
    set_pmp_addr(2,0x80000000,0x40000);
    set_pmp_addr(3,0x80040000,0x40000);
    // Permissions
    set_pmp_cfg(0,0x1b1b1f1f);

    set_pmp_rel(0,0x00000000);
    set_pmp_rel(1,0x00000000);
    set_pmp_rel(2,0x00000000);
    set_pmp_rel(3,0x00000000);

    //TASK-2 RELOCATED
    // Regions 
    set_pmp_addr(4,0x60100000,0x10000);
    set_pmp_addr(5,0x60110000,0x10000);
    set_pmp_addr(6,0x80080000,0x40000);
    set_pmp_addr(7,0x80040000,0x40000);
    // Permissions
    set_pmp_cfg(1,0x1b1b1f1f);


    set_pmp_rel(4,0xE0000000);
    set_pmp_rel(5,0xE0000000);
    set_pmp_rel(6,0x00000000);
    set_pmp_rel(7,0x00000000);

    return 0;
}

int grtpmr_pmp_config(){
    uint32_t* rpm =(uint32_t *)0x70003000;

#ifdef PLATFORM
    // Initialize the Trie 
    grtInit();

    if(!strcmp(STRINGIFY(PLATFORM), "Large")){
        puts("[M-Mode] PLATFORM = Large\n");
        
        // Insert addresses 
        insertAddr(0x01000000);
        insertAddr(0x02000000);
        insertAddr(0x04000000);
        insertAddr(0x08000000);
        insertAddr(0x10000000);
        insertAddr(0x20000000); 
        insertAddr(0x40000000);
        insertAddr(0x80000000);
        insertAddr(0x00000000);

        // Insert limit table
        setAddrCfg(0x01000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x02000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x04000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x08000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x10000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x20000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x40000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x80000000, 0x00000000, 0x00100000, 0b111);
        setAddrCfg(0x00000000, 0x00000000, 0x00120000, 0b111);    
    }else if(!strcmp(STRINGIFY(PLATFORM), "Medium_dynamic")){
        puts("[M-Mode] PLATFORM = Medium_dynamic\n");

        // Insert addresses 
        insertAddr(0x04000000);
        insertAddr(0x08000000);
        insertAddr(0x10000000);
        insertAddr(0x20000000); 
        insertAddr(0x40000000);
        insertAddr(0x80000000);
        insertAddr(0x00000000);

        // Insert limit table
        setAddrCfg(0x04000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x08000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x10000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x20000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x40000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x80000000, 0x00000000, 0x00100000, 0b111);
        setAddrCfg(0x00000000, 0x00000000, 0x00120000, 0b111);    
    }else if(!strcmp(STRINGIFY(PLATFORM), "Medium_static")){
        puts("[M-Mode] PLATFORM = Medium_static\n");

        // Insert addresses 
        insertAddr(0x10000000);
        insertAddr(0x20000000); 
        insertAddr(0x40000000);
        insertAddr(0x80000000);
        insertAddr(0x00000000);

        // Insert limit table
        setAddrCfg(0x10000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x20000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x40000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x80000000, 0x00000000, 0x00100000, 0b111);
        setAddrCfg(0x00000000, 0x00000000, 0x00120000, 0b111);    
    }else if(!strcmp(STRINGIFY(PLATFORM), "Small")){
        puts("[M-Mode] PLATFORM = Small\n");

        // Insert addresses 
        insertAddr(0x40000000);
        insertAddr(0x80000000);
        insertAddr(0x00000000);

        // Insert limit table
        setAddrCfg(0x40000000, 0x00000000, 0x80000000, 0b111); 
        setAddrCfg(0x80000000, 0x00000000, 0x00100000, 0b111);
        setAddrCfg(0x00000000, 0x00000000, 0x00120000, 0b111);    
    }else{
        puts("[M-Mode] PLATFORM = ");
        puts(STRINGIFY(PLATFORM));
        puts(" is not a valid expression!\n");
        return -1;
    }

    // Write the Trie in the RPM    
    writeRPM(rpm);

    if (DEBUGTRIE){
        //Print the Trie (DEBUG)
        printLevelOrder();

        // Print RPM
        puts("[M-Mode] RPM MEMORY:\n");
        puts("[M-Mode] BANK 0\n");
        for(int i = 0; i < RPM_SIZE/2; i++){
            puts("[M-Mode] ");
            putdec(i);
            puts("\t");
            puthex(rpm[i]);
            puts("\t");
            //puthex(rpm+i);
            puts("\n");
        }
        puts("[M-Mode] BANK 1\n");
        for(int i = 128; i < 128+(RPM_SIZE/2); i++){
            puts("[M-Mode] ");
            putdec(i);
            puts("\t");
            puthex(rpm[i]);
            puts("\t");
            //puthex(rpm+i);
            puts("\n");
        }
    }

    deleteTree();
    return 0;
#else 
    puts("[M-Mode] No PLATFORM selected!\n");
    return -1;
#endif 
}

/*M-Mode code*/
int main(){

    const uint64_t time_base = 4000; //4000 clock cycles are 100ms in a 40khz processor
    int err=0;
    // Zero out the bss section
    puts("[M-Mode] Clear bss\n");
    clear_bss();

    //Other initialization ...
    //puts("[M-Mode] Programming the timer\n");    
    //timer_init();
    //timer_enable(time_base); 


    //PMP initializzation
    puts("[M-Mode] Programming the PMP\n");

#ifdef PMR
    if(!strcmp(STRINGIFY(PMR), "no")){
        puts("[M-Mode] PMR = NO\n");
        err = nopmr_pmp_config();    
        if(err == -1) return -1; 
    }else if(!strcmp(STRINGIFY(PMR), "tab")){
        puts("[M-Mode] PMR = TAB\n");
        err = tabpmr_pmp_config();
        if(err == -1) return -1; 
    }else if(!strcmp(STRINGIFY(PMR), "grt")){
        puts("[M-Mode] PMR = GRT\n");
        err = grtpmr_pmp_config(); 
        if(err == -1) return -1; 
    }else{
        puts("[M-Mode] PMR = ");
        puts(STRINGIFY(PMR));
        puts(" is not a valid expression!\n");
        return -1;
    }
#else 
    puts("[M-Mode] No PMR selected!\n");
    return -1;
#endif   
   
    //Go to User Mode
    puts("[M-Mode] Switch to user mode!\n");
    transition_to_user_mode();


    //timer_disable();

    return 0;
}

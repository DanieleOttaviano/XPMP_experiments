#include "grt.h"

#define RPM_SIZE 32

int main() {
    // Fake RPM for the test
    uint32_t rpm[RPM_SIZE];
    for(int i = 0; i < RPM_SIZE; i++){
        rpm[i]=0;
    }

    // Initialize the Trie
    grtInit(); 

    // Insert addresses
    insertAddr(0b1000);
    insertAddr(0b1010);
    insertAddr(0b1100);
    insertAddr(0b10000000000000000000000000000000);

    // Insert limit table
    setAddrCfg(0b1000, 0xE000, 0b1000,0b101);
    setAddrCfg(0b1010, 0b100, 0b10000,0b111);
    setAddrCfg(0b1100, 0b0, 0b100000,0b011);
    setAddrCfg(0b10000000000000000000000000000000, 0b110,0b100000,0b111);

    // Print the Trie 
    printLevelOrder();

    // Write the Trie in the RPM    
    writeRPM(rpm);

    // Print RPM
    printf("\nRPM MEMORY:\n");
    for(int i = 0; i < RPM_SIZE; i++){
        if(i == 0 ){
            printf("BANK 0\n");
        } else if(i == RPM_SIZE/2){
            printf("BANK 1\n");
        }

        printf("%d:\t%08x\t[%08x]\n",i,rpm[i],(rpm+i));
    }
 
    deleteTree();
    
    return 0;
}


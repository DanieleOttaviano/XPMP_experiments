#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "demo_system.h"

// WARNING: Nodes without limit tables have variable limit=0 (this is true also if the node has no chidren)

#define ADDR_SIZE  32
#define NPTR_SIZE  13
#define VALID_SIZE 1
#define LIMIT_SIZE 1
#define GSIZE_SIZE 5
#define HINT_SIZE  12
#define RANGE_SIZE 29 
#define PERM_SIZE  3 
#define RELOC_SIZE 32

#define NPTR_SHIFT  (VALID_SIZE + LIMIT_SIZE + GSIZE_SIZE + HINT_SIZE)
#define VALID_SHIFT (LIMIT_SIZE + GSIZE_SIZE + HINT_SIZE)
#define LIMIT_SHIFT (GSIZE_SIZE + HINT_SIZE)
#define GSIZE_SHIFT (HINT_SIZE)
#define HINT_SHIFT  0

#define BANK_OFFSET 128
#define MAX_Q_SIZE 500

// limit node structure
struct limit_node{
    uint32_t range;
    uint8_t perm;
    uint32_t reloc_off;
};
typedef struct limit_node limit_node;

// grt node structure
struct grt_node {
    uint8_t level;
    uint8_t checkedsize;
    uint32_t guard; // bank 0
    uint8_t gsize;
    bool valid; // 0: false, 1: true
    bool limit; // 0: false, 1: true
    uint16_t hint;  // 0: no children, 1: left child, 2: right child, 3: both children
    struct grt_node* left;
    struct grt_node* right;
    struct limit_node* limit_table;
};
typedef struct grt_node grt_node;

// Print utilities
void printTree();
void printLevelOrder();      

// Trie
int grtInit();
int insertAddr(const uint32_t addr);
int setAddrCfg(const uint32_t addr, const uint32_t reloc_off, 
                    const uint32_t range, const uint8_t perm);

int writeRPM(uint32_t * rpm);
void deleteTree();

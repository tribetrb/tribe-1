#ifndef TRIBE_CHAINPARAMSSEEDS_H
#define TRIBE_CHAINPARAMSSEEDS_H
/**
 * List of fixed seed nodes for the tribe network
 * AUTOGENERATED by contrib/seeds/generate-seeds.py
 *
 * Each line contains a 16-byte IPv6 address and a port.
 * IPv4 as well as onion addresses are wrapped inside a IPv6 address accordingly.
 */
static SeedSpec6 pnSeed6_main[] = {
};

static SeedSpec6 pnSeed6_test[] = {
    // {{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x0d,0x51,0x52,0x1c}, 19399},
    // {{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x0d,0x5f,0xc6,0xe5}, 19399}
};

#include "arith_uint256.h"
void MineGenesisBlock(CBlock &genesis);

void MineGenesisBlock(CBlock &genesis)
{
    arith_uint256 best = arith_uint256();
    int n=0;
    arith_uint256 hashTarget = arith_uint256().SetCompact(genesis.nBits);
    while (UintToArith256(genesis.GetHash()) > hashTarget) {
        arith_uint256 c=UintToArith256(genesis.GetHash());

        if(c < best || n==0)
        {
            best = c;
            n=1;
            std::cout << genesis.GetHash().GetHex().c_str() << " -- "  << hashTarget.GetHex().c_str() << " -- " << best.GetHex().c_str() << std::endl;
        }
        ++genesis.nNonce;
        if (genesis.nNonce == 0) 
            ++genesis.nTime;
    }
    //printf("HASH IS: %s\n", UintToArith256(genesis.GetHash()).ToString().c_str());
    std::cout << "Converting genesis hash to string: " << genesis.ToString().c_str() << std::endl; 
}
#endif // TRIBE_CHAINPARAMSSEEDS_H

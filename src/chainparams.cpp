// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;

#include "chainparamsseeds.h"

/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nMaxReorganizationDepth = 500;
        consensus.nMajorityEnforceBlockUpgrade = 750;
        consensus.nMajorityRejectBlockOutdated = 950;
        consensus.nMajorityWindow = 1000;
        consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimitV2 = uint256S("000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nTargetTimespan = 16 * 60; // 16 mins
        consensus.nTargetSpacingV1 = 2 * 60;
        consensus.nTargetSpacing = 2 * 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.nProtocolV1RetargetingFixedTime = 1395631999;
        consensus.nProtocolV2Time = 9999999999;
        consensus.nProtocolV3Time = 9999999999;
        consensus.nLastPOWBlock = 1000;
        consensus.nStakeTimestampMask = 0xf;
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0x32;
        pchMessageStart[1] = 0x5e;
        pchMessageStart[2] = 0x6f;
        pchMessageStart[3] = 0x86;
        vAlertPubKey = ParseHex("0486bce1bac0d543f104cbff2bd23680056a3b9ea05e1137d2ff90eeb5e08472eb500322593a2cb06fbf8297d7beb6cd30cb90f98153b5b7cce1493749e41e0284");

        nDefaultPort = 6325;
        nMinerThreads = 0;
        nMaxTipAge = 24 * 60 * 60;
        nPruneAfterHeight = 100000;

        /**
         * Build the genesis block. Note that the output of its generation
         * transaction cannot be spent since it did not originally exist in the
         * database.
         *
         * CBlock(hash=000001faef25dec4fbcf906e6242621df2c183bf232f263d0ba5b101911e4563, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=12630d16a97f24b287c8c2594dda5fb98c9e6c70fc61d44191931ea2aa08dc90, nTime=1393221600, nBits=1e0fffff, nNonce=164482, vtx=1, vchBlockSig=)
         *   Coinbase(hash=12630d16a9, ver=1, nTime=1393221600, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(0000000000, 4294967295), coinbase 00012a24323020466562203230313420426974636f696e2041544d7320636f6d6520746f20555341)
         *     CTxOut(empty)
         *   vMerkleTree: 12630d16a9
         */
        const char* pszTimestamp = "21jul2017 - Neblio First Net Launches";
        CMutableTransaction txNew;
        txNew.nTime = 1500674579;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 0 << CScriptNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].SetEmpty();
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock.SetNull();
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1500674579;
        genesis.nBits    = 0x207fffff;
        genesis.nNonce   = 8485;

        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x7286972be4dbc1463d256049b7471c252e6557e222cab9be73181d359cd28bcc"));
        assert(genesis.hashMerkleRoot == uint256S("0x203fd13214321a12b01c0d8b32c780977cf52e56ae35b7383cd389c73291aee7"));

        vSeeds.push_back(CDNSSeedData("nebl.io", "seed.nebl.io"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,53);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,112);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,181);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = false;

        checkpointData = (Checkpoints::CCheckpointData) {
            boost::assign::map_list_of
            (     0, uint256S("0x7286972be4dbc1463d256049b7471c252e6557e222cab9be73181d359cd28bcc"))
            (   500, uint256S("0x00000342c5dc5f7fd4a8ef041d4df4e569bd40756405a8c336c5f42c77e097a2"))
            (  1000, uint256S("0x00000c60e3a8d27dedb15fc33d91caec5cf714fae60f24ea22a649cded8e0cca"))
            (  5000, uint256S("0x074873095a26296d4f0033f697f46bddb7c1359ffcb3461f620e346bc516a1d2"))
            ( 25000, uint256S("0x9c28e51c9c21092909fe0a6ad98ae335f253fa9c8076bb3cca154b6ba5ee03ab"))
            ( 50000, uint256S("0x81b660d3f960d2d3efa213744135f6d396a180df7c5a7d5388981cdf1814c4ba"))
            (100000, uint256S("0xbb13aedc5846fe5d384601ef4648492262718fc7dfe35b886ef297ea74cab8cc"))
            (124500, uint256S("0x0bbbd15d1ea81eaeb7029cf280e1f6843d5dc4fd940e75f8759ed44cc82ec1ac")),
            1516116054, // * UNIX timestamp of last checkpoint block
            287048,     // * total number of transactions between genesis and last checkpoint
                        //   (the tx=... number in the SetBestChain debug.log lines)
            1000.0        // * estimated number of transactions per day after checkpoint
        };
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        consensus.nMajorityEnforceBlockUpgrade = 51;
        consensus.nMajorityRejectBlockOutdated = 75;
        consensus.nMajorityWindow = 100;
        consensus.powLimit = uint256S("0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.nProtocolV1RetargetingFixedTime = 0;
        consensus.nProtocolV2Time = 0;
        consensus.nProtocolV3Time = 0;
        consensus.nLastPOWBlock = 500;
        pchMessageStart[0] = 0x32;
        pchMessageStart[1] = 0x5e;
        pchMessageStart[2] = 0x6f;
        pchMessageStart[3] = 0x86;
        vAlertPubKey = ParseHex("0471dc165db490094d35cde15b1f5d755fa6ad6f2b5ed0f340e3f17f57389c3c2af113a8cbcc885bde73305a553b5640c83021128008ddf882e856336269080496");
        nDefaultPort = 16325;
        nMinerThreads = 0;
        nMaxTipAge = 24 * 60 * 60;
        nPruneAfterHeight = 100000;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1500674579;
        genesis.nBits    = 0x207fffff;
        genesis.nNonce   = 8485;
        consensus.hashGenesisBlock = genesis.GetHash();
        //assert(consensus.hashGenesisBlock == uint256S("0x7286972be4dbc1463d256049b7471c252e6557e222cab9be73181d359cd28bcc"));

        vFixedSeeds.clear();
        vSeeds.clear();

        vSeeds.push_back(CDNSSeedData("nebliodseed1.nebl.io", "nebliodseed2.nebl.io"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,53);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,112);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,181);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = false;

        checkpointData = (Checkpoints::CCheckpointData) {
            boost::assign::map_list_of
            (     0, uint256S("0x7286972be4dbc1463d256049b7471c252e6557e222cab9be73181d359cd28bcc"))
            (   100, uint256S("0x04a4cab534e60e5a1fc78770731090fdce91740c0bce4ed6a54d3ab7d7e9e50b"))
            0,
            0,
            0
        };

    }
};
static CTestNetParams testNetParams;

// /**
//  * Regression test
//  */
// class CRegTestParams : public CTestNetParams {
// public:
//     CRegTestParams() {
//         strNetworkID = "regtest";
//         consensus.nMajorityEnforceBlockUpgrade = 51;
//         consensus.nMajorityRejectBlockOutdated = 75;
//         consensus.nMajorityWindow = 100;
//         consensus.powLimit = uint256S("0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
//         consensus.fPowAllowMinDifficultyBlocks = true;
//         consensus.nProtocolV1RetargetingFixedTime = 0;
//         consensus.nProtocolV2Time = 0;
//         consensus.nProtocolV3Time = 0;
//         consensus.nLastPOWBlock = 500;
//         pchMessageStart[0] = 0x32;
//         pchMessageStart[1] = 0x5e;
//         pchMessageStart[2] = 0x6f;
//         pchMessageStart[3] = 0x86;
//         vAlertPubKey = ParseHex("0471dc165db490094d35cde15b1f5d755fa6ad6f2b5ed0f340e3f17f57389c3c2af113a8cbcc885bde73305a553b5640c83021128008ddf882e856336269080496");
//         nDefaultPort = 16325;
//         nMinerThreads = 0;
//         nMaxTipAge = 24 * 60 * 60;
//         nPruneAfterHeight = 100000;

//         //! Modify the testnet genesis block so the timestamp is valid for a later start.
//         genesis.hashMerkleRoot = genesis.BuildMerkleTree();
//         genesis.nVersion = 1;
//         genesis.nTime    = 1500674579;
//         genesis.nBits    = 0x207fffff;
//         genesis.nNonce   = 8485;
//         consensus.hashGenesisBlock = genesis.GetHash();
//         //assert(consensus.hashGenesisBlock == uint256S("0x7286972be4dbc1463d256049b7471c252e6557e222cab9be73181d359cd28bcc"));

//         vFixedSeeds.clear();
//         vSeeds.clear();

//         vSeeds.push_back(CDNSSeedData("nebliodseed1.nebl.io", "nebliodseed2.nebl.io"));

//         base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,53);
//         base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,112);
//         base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,181);
//         base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
//         base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

//         fRequireRPCPassword = true;
//         fMiningRequiresPeers = true;
//         fDefaultConsistencyChecks = false;
//         fRequireStandard = true;
//         fMineBlocksOnDemand = false;
//         fTestnetToBeDeprecatedFieldRPC = false;

//         checkpointData = (Checkpoints::CCheckpointData) {
//             boost::assign::map_list_of
//             (     0, uint256S("0x7286972be4dbc1463d256049b7471c252e6557e222cab9be73181d359cd28bcc"))
//             (   100, uint256S("0x04a4cab534e60e5a1fc78770731090fdce91740c0bce4ed6a54d3ab7d7e9e50b"))
//             0,
//             0,
//             0
//         };

//     }
// };
// static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = 0;

const CChainParams &Params() {
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams &Params(CBaseChainParams::Network network) {
    switch (network) {
        case CBaseChainParams::MAIN:
            return mainParams;
        case CBaseChainParams::TESTNET:
            return testNetParams;
        // case CBaseChainParams::REGTEST:
        //     return regTestParams;
        default:
            assert(false && "Unimplemented network");
            return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network) {
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}

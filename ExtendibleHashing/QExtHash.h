#pragma once

#include "ExtendibleHashing.h"

#include <vector>

struct Directory
{
    Directory(int localBitDepth, int* blockPointer)
        :   localBitDepth(localBitDepth),
            blockPointer(blockPointer)
    { }

    int localBitDepth;
    int* blockPointer;
};

class QExtHash : public IExtHash
{
public:
    virtual void SetMin(int);
    virtual void SetMax(int);

    virtual void Insert(int);
    virtual void Delete(int);
    virtual bool Contains(int);

    QExtHash() :
        pageSize(6),
        maxBitDepth(0)
    {
        blocks = (int**)malloc(sizeof(int*) * 1);
        blocks[0] = new int[pageSize + 1];
        blocks[0][pageSize] = 0;
        directories.push_back(Directory(0, blocks[0]));
    }

    ~QExtHash()
    {
        FreeBlockStructure(blocks, CurBlockCount());
    }

    //public for local fncs
    int hash(int number, int bitDepth);
private:
    void ReallocateBlocks()
    {
        int blockCount = CurBlockCount();
        blocks = (int**)malloc(sizeof(int*) * blockCount);
        for(int ix = 0; ix < blockCount; ix++)
        {
            blocks[ix] = new int[pageSize];
            blocks[ix][pageSize] = 0;
        }
    }
    void FreeBlockStructure(int** oldBlocks, int oldBlockCount)
    {
        for(int ib = 0; ib < oldBlockCount; ib++)
            delete[] oldBlocks[ib];
        delete oldBlocks;
    }
    int CurBlockCount()
    {
        return maxBitDepth == 0 ? 1 : (1 >> (maxBitDepth - 1));
    }

private:
    //Should not be changed after any insertions or deletions
    int min;
    int max;
    int maxBits;

    int pageSize;
    int maxBitDepth; //>= all localBitDepths

    //Array of blocks, each which is an int[pageSize + 1],
    //last int is the current count in the block.
    int** blocks;

    std::vector<Directory> directories;
};
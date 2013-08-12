#include "QExtHash.h"

#include <math.h>

#include <algorithm>

void QExtHash::SetMin(int newMin)
{
    min = newMin;
    maxBits = (int)ceil(log((double)max - min) / log((double)2));
}
void QExtHash::SetMax(int newMax)
{
    max = newMax;
}

int QExtHash::hash(int number, int bitDepth)
{
    number -= min;
    int hashed = (number * 17) % (max - min);
    hashed >= maxBits - bitDepth;
    return hashed;
}

void QExtHash::Insert(int value)
{
    int iDir = hash(value, maxBitDepth);
    Directory& curDir = directories[iDir];

    //If curDir is full, try to block split until
    //the localBit depth >= maxBitDepth,
    //and then directorySplit until we have room

    //Try to increase localBitDepth
    if(curDir.blockPointer[pageSize] == pageSize)
    {
        while(curDir.localBitDepth < maxBitDepth)
        {
            curDir.localBitDepth++;
            
            //Insure we actually move a value, or else it will still be full
            for(int ix = 0; ix < pageSize; ix++)
            {
                if(hash(curDir.blockPointer[ix], curDir.localBitDepth) != iDir)
                {
                    break;
                }
            }
        }

        //If we could increase localBit, do a block split
        if(curDir.localBitDepth < maxBitDepth)
        {
            //Block split, we just remove all elements and then reinsert them.
            int* tempBlock = new int[pageSize];
            memcpy(tempBlock, curDir.blockPointer, sizeof(int) * curDir.blockPointer[pageSize]);

            curDir.blockPointer[pageSize] = 0;
            for(int ix = 0; ix < pageSize; ix++)
                Insert(tempBlock[ix]);

            delete[] tempBlock;
        }
    }

    //We need to do a directorySplit
    if(curDir.blockPointer[pageSize] == pageSize)
    {
        int oldBlockCount = CurBlockCount();

        //Keep increasing maxBitDepth until we have room
        //(could infinite loop, and it appears there is nothing
        //in the algorithm defined in the notes to account for this).
        while(true)
        {
            maxBitDepth++;
            int newiDir = hash(value, maxBitDepth);

            //Check to make sure it gives us room
            //Insure we actually move a value, or else it will still be full
            for(int ix = 0; ix < pageSize; ix++)
            {
                if(hash(curDir.blockPointer[ix], maxBitDepth) != newiDir)
                {
                    break;
                }
            }
        }

        //Directory split
        int** oldBlocks = blocks;
        directories.clear();

        ReallocateBlocks();

        //Insert all the old values
        for(int ib = 0; ib < oldBlockCount; ib++)
            for(int ix = 0; ix < oldBlocks[ib][pageSize]; ix++)
                Insert(oldBlocks[ib][pageSize]);

        FreeBlockStructure(oldBlocks, oldBlockCount);
    }

    //Now we can finally just insert the value
    iDir = hash(value, maxBitDepth);
    curDir = directories[iDir];

    struct _FindValue
    {
        Directory& curDir;
        QExtHash& context;
        _FindValue(Directory& curDir, QExtHash& context) 
            : curDir(curDir), context(context) 
        { }
        bool operator()(int lhs, int rhs)
        {
            return context.hash(lhs, curDir.localBitDepth) < context.hash(rhs, curDir.localBitDepth);
        }
    } FindValue(curDir, *this);
    
    //std::lower_
}
void QExtHash::Delete(int value)
{

}
bool QExtHash::Contains(int)
{
    return true;
}
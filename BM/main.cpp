#include "tests.h"

#include "QBM.h"

#include "../KMP/QKMP.h"

int main()
{
    QBM q;
    TestBM(&q);

    QKMP q2;
    TestBM(&q, &q2);

    return 0;
}
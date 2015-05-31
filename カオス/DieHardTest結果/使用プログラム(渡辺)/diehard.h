//DihardTestのヘッダ

#if !defined (___DIEHARD_TEST_H)
#define ___DIEHARD_TEST_H

#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

//VolterraFilter（2次）変動パラメータ
#define H2_START	-32.0
#define H2_STOP		32.0
#define H2_STEP		1.0

#define H3_START		1
#define H3_STOP		0xffffffffUL
#define H3_STEP		93871131

#define X1 0.0
#define X2 0.0
#define X3 0.0

#define RNDCHKNUM32 2500000L	// 32bits
#define RNDCHKNUM16 5000000L	// 16bits

//DiehardTest用パラメータ
#define QBIT 10
#define VARBITLENGTH 16
#define ACCBITLENGTH 32

#define INIT_STC 0.138672
#define INIT_AL 5.0
#define INIT_BT 2.1
#define INIT_GM 3.1
#define INIT_K 1.0
#define INIT_D 10.0
#define INIT_E 0.000977
#define INIT_MODEL1_INITVALUE0 0
#define INIT_MODEL1_INITVALUE1 0
#define INIT_MODEL1_INITVALUE2 0

#define IVECTOR3DIM 3

void DiehardTest();
int diehard(int*, int*);

#endif

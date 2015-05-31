//DihardTestのヘッダ

#if !defined (___DIEHARD_TEST_H)
#define ___DIEHARD_TEST_H

#include <stdio.h>
#include <malloc.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//VolterraFilter（2次）変動パラメータ
#define H2_START	-32.0
#define H2_STOP		32.0
#define H2_STEP		1.0

#define H3_START	-32.0
#define H3_STOP		32.0
#define H3_STEP		1.0

#define X1 0.0
#define X2 0.0
#define X3 0.0

#define RNDCHKNUM32 2500000L	// 32bits
#define RNDCHKNUM16 5000000L	// 16bits

#define RNDCHKNUM08 10000000L	// 08bits

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

void DiehardTest(int, int, unsigned char*);

int diehard(int*, int*);

typedef struct
{
  unsigned int x;
  unsigned int y;
  unsigned char state[256];
} ArcfourContext;

void mykey_init(unsigned char* mykey);

void arcfour_init(ArcfourContext *ctx, const unsigned char *key, 
                  unsigned int key_len);

unsigned int arcfour_byte(ArcfourContext *ctx);

void arcfour_encrypt(ArcfourContext *ctx, unsigned char *dest, 
                     const unsigned char *src, unsigned int len);


#endif

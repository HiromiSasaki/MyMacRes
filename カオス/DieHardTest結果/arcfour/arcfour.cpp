#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "diehard.h"

using namespace std;

/*typedef struct
{
  unsigned int x;
  unsigned int y;
  unsigned char state[256];
} ArcfourContext;
*/
void mykey_init(unsigned char* mykey);
void arcfour_init(ArcfourContext *ctx, const unsigned char *key, 
                  unsigned int key_len);

unsigned int arcfour_byte(ArcfourContext *ctx);

void arcfour_encrypt(ArcfourContext *ctx, unsigned char *dest, 
                     const unsigned char *src, unsigned int len);

void speed_test(ArcfourContext *ctx, unsigned char *dest, unsigned int len);


int main(int argc, char **argv)
{
	int select = 0, number = 0;
	const int OHM = 104857600;
	static unsigned char dest[OHM];
	static unsigned char decrypt[OHM];//��������K���ɐݒ�
	unsigned char mykey[] = {0x29, 0x04, 0x19, 0x72, 0xfb, 0x42,
							0xba, 0x5f, 0xc7, 0x12, 0x77, 0x12,
							0xf1, 0x38, 0x29, 0xc9};
	//  unsigned char src[] = "Know thyself";//src�͓��͐M��

  ArcfourContext mycontext;
  ArcfourContext mycontext2;//�����ɕK�v�Ȃ��ߐݒ�

  /* Initialize the algoritm */
  arcfour_init(&mycontext, mykey, 16);
  arcfour_init(&mycontext2, mykey, 16);//�����ɕK�v�Ȃ��ߏ�����

  cout << "mode 0:SPEED TEST" << endl;
  cout << "mode 1:DIEHARD TEST_S" << endl;
  cout << "mode 2:DIEHARD TEST_D" << endl;
  cout << "select mode : ";
  cin >> select;

  /* Encrypt 13 bytes of the src string */
  switch(select){
  case 0:
	  speed_test(&mycontext, dest, OHM);
	  break;
  case 1:
	  for(int iter = 0; iter < 16; iter++)
	  DiehardTest(1, iter, mykey);
	  break;
  case 2:
	  DiehardTest(2, 0, mykey);
	  break;
  }

/*  ofstream fout("dest_data.txt");
  for(int i = 0; i < OHM; i++)fout << dest[i];

  arcfour_encrypt(&mycontext2, decrypt, dest, OHM);//�����ŕ���
  for(int i = 0; i < OHM; i++)	if(decrypt[i] != src[i])	cout << "missmach!";
*/
//  cin >> startt;
  /* Now "dest" contains the encrypted string. Do whatever
     you please with it... */
  //��̕��ɂ���ʂ�Í���������̒l��dest�Ɋi�[����Ă���B

/*  for(int k=0;k<13;k++)
  {
	cout<<src[k];
  }
  cout<<endl;
  for(int k=0;k<13;k++)
  {
	cout<<dest[k];
  }
  cout<<endl;

  arcfour_encrypt(&mycontext2, decrypt, dest, 104857600);//�����ŕ���

  for(int k=0;k<13;k++)
  {
	cout<<decrypt[k];
  }
  cout<<endl;
*/
  return 0;
}

void mykey_init(unsigned char* mykey)
{
	mykey[0] = 0x29;
	mykey[1] = 0x04;
	mykey[2] = 0x19;
	mykey[3] = 0x72;
	mykey[4] = 0xfb;
	mykey[5] = 0x42;
	mykey[6] = 0xba;
	mykey[7] = 0x5f;
	mykey[8] = 0xc7;
	mykey[9] = 0x12;
	mykey[10] = 0x77;
	mykey[11] = 0x12;
	mykey[12] = 0xf1;
	mykey[13] = 0x38;
	mykey[14] = 0x29;
	mykey[15] = 0xc9;
}
void arcfour_init(ArcfourContext *ctx, const unsigned char *key, 
                  unsigned int key_len)
{
	//���̃Z�b�g�A�b�v
  unsigned int t, u;
  unsigned int keyindex;
  unsigned int stateindex;
  unsigned char *state;
  unsigned int counter;

  /*
	1. 8�r�b�g�Œ�`�����1�o�C�g��256�v�f���z����m�ۂ��AS�{�b�N�X
    �Ƃ��Ďg�p����B������ȉ��̂悤�ɕ\���B

               S [0] .. S [255]
	*/
  state = ctx->state;//�㕔�Ő錾����SBOX�̃|�C���^����Ƃ̂��߂ɓn���Ă���B1�̍�Ƃ͂����ɓ�����B
  ctx->x = 0;
  ctx->y = 0;

	/*
	2. S�{�b�N�X������������B���ꂼ��̗v�f�ɂ܂��A���̃C���f�b�N�X�̒l��
�@�@ �i�[����B

               S [0] = 0; S [1] = 1; ... ; S [255] = 255;
	*/
  for (counter = 0; counter < 256; counter++)
       state[counter] = counter;//2�̍�ƕ���
 
  keyindex = 0;
  stateindex = 0;
	/*
	3. ����̃T�C�Y(256)��������1�̔z��ɁA�����Z�b�g����B�K�v�ȃo�C�g
     �������J��Ԃ��B

               for (i = 0; i < 256; i = i + 1)
                 S2 [i] = key [i % keylen];

	 ���̃v���O�����ł�main������mykey[]�Ő錾����Ă��邽�߁A�����ł͂��̏����͂��Ȃ��B

	4. �ϐ� j ���[���ɃZ�b�g���AS�{�b�N�X�����̂悤�ɍď���������B

               for (i = 0; i < 256; i = i + 1)
                 {
                 j = (j + S [i] + S2 [i]) % 256;
                 temp = S [i];
                 S [i] = S [j];
                 S [j] = temp;
                 }
	*/
  for (counter = 0; counter < 256; counter++)
  {
    t = state[counter];//t��SBOX�̒l�̕ς������邽�߂ɑ������Ă���B
    stateindex = (stateindex + key[keyindex] + t) & 0xff;//4�̍�Ƃ̊J�n
    u = state[stateindex];//u=temp:temp = S [i];
    state[stateindex] = t;//S [i] = S [j];
    state[counter] = u;//S [j] = temp;
    if (++keyindex >= key_len)
      keyindex = 0;
  }
}


unsigned int arcfour_byte(ArcfourContext *ctx)
{
	//3.2 �X�g���[���̐���
	/*
	�Í����܂��͕����ɂ����ẮA���̓e�L�X�g�́A1�x��1�o�C�g�����������B
	�[�������o�C�gK�͎��̂悤�ɐ�������B

                i = (i+1) % 256;
                j = (j + S[i]) % 256;
                temp = S [i];
                S [i] = S [j];
                S [j] = temp;
                t = (S [i] + S [j]) % 256;
                K = S [t];
	*/
  unsigned int x;
  unsigned int y;
  unsigned int sx, sy;
  unsigned char *state;

  state = ctx->state;
  x = (ctx->x + 1) & 0xff;//i = (i+1) % 256; 256�Ŋ������]��Ȃ̂�x��256�𒴂��邱�Ƃ͂Ȃ��B
  sx = state[x];//S[i]�̑����sx������Btemp = S [i];
  y = (sx + ctx->y) & 0xff;//j = (j + S[i]) % 256;
  sy = state[y];
  ctx->x = x;//�\���̂Ő錾����Ă��钆�g�̂ق��������̏����Ɠ��������Ă���B
  ctx->y = y;
  state[y] = sx;//S [j] = temp;
  state[x] = sy;//S [i] = S [j];

  return state[(sx + sy) & 0xff];//t = (S [i] + S [j]) % 256;
}


void arcfour_encrypt(ArcfourContext *ctx, unsigned char *dest, 
                     const unsigned char *src, unsigned int len)
{
  unsigned int i;
  for (i = 0; i < len; i++)
    dest[i] = src[i] ^ arcfour_byte(ctx);//K = S [t];
}

void speed_test(ArcfourContext *ctx, unsigned char *dest, unsigned int len)
{
	double startt = 0.0, endt = 0.0, time = 0.0;
	int ave = 100;
	std::ifstream ifs("mod_data.txt");	//100MB�̃f�[�^
	std::string str;
	ifs >> str;
	unsigned char* src = (unsigned char*)str.data();

	ofstream fout2("speed.txt");

	for(int i = 0; i < ave; i++){
		startt = std::clock();
		arcfour_encrypt(ctx, dest, src, len);
		endt = std::clock();
		time += (endt - startt);
	}
	fout2 << "encrypt_speed : " << time / (double)ave << "[ms]";
}
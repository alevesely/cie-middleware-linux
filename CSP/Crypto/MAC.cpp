#include "../StdAfx.h"
#include "MAC.h"
#include <algorithm>

static const char *szCompiledFile=__FILE__;
using std::min;

#ifdef WIN32

class init_mac {
public:
	BCRYPT_ALG_HANDLE algo;
	init_mac() {
		if (BCryptOpenAlgorithmProvider(&algo, BCRYPT_3DES_ALGORITHM, MS_PRIMITIVE_PROVIDER, 0) != 0)
			throw logged_error("Errore nell'inizializzazione dell'algoritmo MAC");
	}
	~init_mac() {
		BCryptCloseAlgorithmProvider(algo, 0);
	}
} algo_mac;

void CMAC::Init(const ByteArray &key, const ByteArray &iv)
{
	init_func
	size_t KeySize = key.size();
	ER_ASSERT((KeySize % 8) == 0, "Errore nella lunghezza della chiave MAC (non divisibile per 8)")
	ER_ASSERT(iv.size() == 8, "Errore nella lunghezza dell'Initial Vector")
	ER_ASSERT(KeySize >= 8 && KeySize <= 24, "Errore nella lunghezza della chiave MAC (<8 o >24)")
	ByteDynArray BCrytpKey;
	this->iv = iv;	
	switch (KeySize) {
	case 8:

		BCrytpKey.set(&key, &key, &key);
		break;
	case 16:
		BCrytpKey.set(&key, &key.left(8));
		break;
	case 24:
		BCrytpKey = key;
		break;
	}

	ByteDynArray k1;
	k1.set(&key.left(8), &key.left(8), &key.left(8));

	if (BCryptGenerateSymmetricKey(algo_mac.algo, &this->key1, nullptr, 0, k1.data(), (ULONG)k1.size(), 0) != 0)
		throw logged_error("Errore nella creazione della chiave MAC");

	if (BCryptGenerateSymmetricKey(algo_mac.algo, &this->key2, nullptr, 0, BCrytpKey.data(), (ULONG)BCrytpKey.size(), 0) != 0)
		throw logged_error("Errore nella creazione della chiave MAC");

	exit_func
}

CMAC::CMAC() : key1(nullptr), key2(nullptr) {
}

CMAC::~CMAC(void)
{
	if (key1!=nullptr)
		BCryptDestroyKey(key1);
	if (key2 != nullptr)
		BCryptDestroyKey(key2);
}

ByteDynArray CMAC::Mac(const ByteArray &data)
{
	init_func

	size_t ANSILen=ANSIPadLen(data.size());
	ByteDynArray iv = this->iv;

	if (data.size()>8) {
		ByteDynArray OutTmp(ANSILen - 8);
		ULONG result = (ULONG)OutTmp.size();
		if (BCryptEncrypt(key1, data.data(), (long)ANSILen - 8, nullptr, iv.data(), (ULONG)iv.size(), OutTmp.data(), (ULONG)OutTmp.size(), &result, 0) != 0)
			throw logged_error("Errore nel calcolo del MAC");
	}

	ByteDynArray resp(8);
	ULONG result = (ULONG)resp.size();
	if (BCryptEncrypt(key2, data.mid(ANSILen - 8).data(), (long)(data.size() - ANSILen) + 8, nullptr, iv.data(), (ULONG)iv.size(), resp.data(), (ULONG)resp.size(), &result, 0) != 0)
		throw logged_error("Errore nel calcolo del MAC");

	return resp;
}
#else

void CMAC::Init(const ByteArray &key, const ByteArray &iv)
{
	init_func
	size_t KeySize = key.size();
	ER_ASSERT((KeySize % 8) == 0, "Errore nella lunghezza della chiave MAC (non divisibile per 8)")
	ER_ASSERT(iv.size() == 8, "Errore nella lunghezza dell'Initial Vector")

	ER_ASSERT(KeySize >= 8 && KeySize <= 24, "Errore nella lunghezza della chiave MAC (<8 o >24)")
	DES_cblock *keyVal1 = nullptr, *keyVal2 = nullptr, *keyVal3 = nullptr;
	memcpy(initVec, iv.data(), min(size_t(8), sizeof(DES_cblock)));

	switch (KeySize) {
	case 8:
		keyVal1 = keyVal2 = keyVal3 = (DES_cblock *)key.data();
		break;
	case 16:
		keyVal1 = keyVal3 = (DES_cblock *)key.data();
		keyVal2 = (DES_cblock *)key.mid(8).data();
		break;
	case 24:
		keyVal1 = (DES_cblock *)key.data();
		keyVal2 = (DES_cblock *)key.mid(8).data();
		keyVal3 = (DES_cblock *)key.mid(16).data();
		break;
	}

	DES_set_key(keyVal1, &k1);
	DES_set_key(keyVal2, &k2);
	DES_set_key(keyVal3, &k3);

	exit_func
}

CMAC::~CMAC(void)
{
}

ByteDynArray CMAC::Mac(const ByteArray &data)
{
	init_func

	DES_cblock iv;
	memcpy(iv, initVec, min(sizeof(initVec), sizeof(DES_cblock)));

	size_t ANSILen = ANSIPadLen(data.size());
	if (data.size()>8) {
		ByteDynArray baOutTmp(ANSILen - 8);
		DES_ncbc_encrypt(data.data(), baOutTmp.data(), (long)ANSILen - 8, &k1, &iv, DES_ENCRYPT);
	}
	ByteDynArray dest(8);
	DES_ede3_cbc_encrypt(data.mid(ANSILen - 8).data(), dest.data(), (long)(data.size() - ANSILen) + 8, &k1, &k2, &k3, &iv, DES_ENCRYPT);

	//exit_func
	return dest;
}

CMAC::CMAC() {
}
#endif


CMAC::CMAC(const ByteArray &key, const ByteArray &iv) {
	Init(key,iv);
}


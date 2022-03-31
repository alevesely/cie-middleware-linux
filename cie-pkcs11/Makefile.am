## Automake

@SET_MAKE@

lib_LTLIBRARIES = libcie-pkcs11.la

noinst_HEADERS = CSP/VerificaConCIE.h \
    CSP/FirmaConCIE.h \
    CSP/AbilitaCIE.h \
    CSP/IAS.h \
    CSP/PINManager.h \
    PKCS11/CardContext.h \
    PKCS11/Mechanism.h \
    PKCS11/session.h \
    PKCS11/P11Object.h \
    PKCS11/cryptoki.h \
    PKCS11/pkcs11.h \
    PKCS11/Slot.h \
    PKCS11/CardTemplate.h \
    PKCS11/pkcs11t.h \
    PKCS11/InitP11.h \
    PKCS11/CIEP11Template.h \
    PKCS11/wintypes.h \
    PKCS11/pkcs11f.h \
    PKCS11/PKCS11Functions.h \
    Util/TLV.h \
    Util/defines.h \
    Util/UtilException.h \
    Util/Array.h \
    Util/funccallinfo.h \
    Util/UUCTextFileReader.h \
    Util/CacheLib.h \
    Util/SyncroMutex.h \
    Util/UUCStringTable.h \
    Util/util.h \
    Util/log.h \
    Util/IniSettings.h \
    Util/CryptoppUtils.h \
    Util/SyncroEvent.h \
    Util/ModuleInfo.h \
    Util/UUCProperties.h \
    Util/UUCByteArray.h \
    keys.h \
    Crypto/AES.h \
    Crypto/DES3.h \
    Crypto/ASNParser.h \
    Crypto/Base64.h \
    Crypto/sha512.h \
    Crypto/sha256.h \
    Crypto/SHA1.h \
    Crypto/CryptoUtil.h \
    Crypto/MD5.h \
    Crypto/RSA.h \
    Crypto/MAC.h \
    LOGGER/Logger.h \
    Sign/CIEVerify.h \
    Sign/CIESign.h \
    Sign/disigonsdk.h \
    Sign/definitions.h \
    Sign/CIEEngine.h \
    PCSC/CardLocker.h \
    PCSC/Token.h \
    PCSC/PCSC.h \
    PCSC/APDU.h


libcie_pkcs11_la_SOURCES = CSP/VerificaConCIE.cpp \
    CSP/FirmaConCIE.cpp \
    CSP/AbilitaCIE.cpp \
    CSP/PINManager.cpp \
    CSP/ExtAuthKey.cpp \
    CSP/IAS.cpp \
    PKCS11/CardContext.cpp \
    PKCS11/Mechanism.cpp \
    PKCS11/CardTemplate.cpp \
    PKCS11/P11Object.cpp \
    PKCS11/initP11.cpp \
    PKCS11/Slot.cpp \
    PKCS11/CIEP11Template.cpp \
    PKCS11/PKCS11Functions.cpp \
    PKCS11/session.cpp \
    Util/Array.cpp \
    Util/UUCStringTable.cpp \
    Util/funccallinfo.cpp \
    Util/UUCTextFileReader.cpp \
    Util/UUCByteArray.cpp \
    Util/util.cpp \
    Util/SyncroMutex.cpp \
    Util/UtilException.cpp \
    Util/ModuleInfo.cpp \
    Util/CacheLib.cpp \
    Util/log.cpp \
    Util/IniSettings.cpp \
    Util/TLV.cpp \
    Util/CryptoppUtils.cpp \
    Util/SyncroEvent.cpp \
    Util/UUCProperties.cpp \
    Crypto/MD5.cpp \
    Crypto/SHA512.cpp \
    Crypto/ASNParser.cpp \
    Crypto/SHA256.cpp \
    Crypto/RSA.cpp \
    Crypto/SHA1.cpp \
    Crypto/DES3.cpp \
    Crypto/AES.cpp \
    Crypto/Base64.cpp \
    Crypto/MAC.cpp \
    LOGGER/Logger.cpp \
    Sign/CIEVerify.cpp \
    Sign/CIESign.cpp \
    PCSC/PCSC.cpp \
    PCSC/Token.cpp \
    PCSC/CardLocker.cpp \
    PCSC/APDU.cpp

libcie_pkcs11_la_CPPFLAGS = @CRPP_INC@ @PCSC_INC@ @XML_INC@ @CRY_INC@ -DDEFINE_CFuncCallInfo

libcie_pkcs11_la_LDFLAGS = @CRPP_PATH@ @PCSC_PATH@ @XML_PATH@ @CRY_PATH@ -shared -pthread

libcie_pkcs11_la_LIBADD = @CRPP_LIB@ @PCSC_LIB@ @XML_LIB@ @CRY_LIB@

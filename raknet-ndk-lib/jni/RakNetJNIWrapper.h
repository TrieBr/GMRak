


/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_triebr_raknet_RakNetJNIWrapper */

#include <GMInterface.hpp>

#ifndef _Included_com_triebr_raknet_RakNetJNIWrapper
#define _Included_com_triebr_raknet_RakNetJNIWrapper
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Last_Error
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Last_1Error
  (JNIEnv *, jclass);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Create
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Create
  (JNIEnv *, jclass);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Destroy
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Destroy
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Shutdown
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Shutdown
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Startup_Client
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Startup_1Client
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Startup_Server
 * Signature: (DDD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Startup_1Server
  (JNIEnv *, jclass, jdouble, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Connect
 * Signature: (DLjava/lang/String;D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Connect
  (JNIEnv *, jclass, jdouble, jstring, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_SetMaxIncomingConnections
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1SetMaxIncomingConnections
  (JNIEnv *, jclass, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Receive
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Receive
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Send
 * Signature: (DDDDDDD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Send
  (JNIEnv *, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Deallocate_Packet
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Deallocate_1Packet
  (JNIEnv *, jclass, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Packet_GetMessageIdentifier
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Packet_1GetMessageIdentifier
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Packet_Get_GUID
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Packet_1Get_1GUID
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_GUID_Destroy
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1GUID_1Destroy
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_Create
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1Create
  (JNIEnv *, jclass);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_Create_From_Packet
 * Signature: (DDD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1Create_1From_1Packet
  (JNIEnv *, jclass, jdouble, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_Destroy
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1Destroy
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteMessageID
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteMessageID
  (JNIEnv *, jclass, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteU8
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteU8
  (JNIEnv *, jclass, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteS8
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteS8
  (JNIEnv *, jclass, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteU16
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteU16
  (JNIEnv *, jclass, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteS16
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteS16
  (JNIEnv *, jclass, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteU32
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteU32
  (JNIEnv *, jclass, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteS32
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteS32
  (JNIEnv *, jclass, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteF16
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteF16
  (JNIEnv *, jclass, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteF32
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteF32
  (JNIEnv *, jclass, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteBool
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteBool
  (JNIEnv *, jclass, jdouble, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteString
 * Signature: (DLjava/lang/String;)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteString
  (JNIEnv *, jclass, jdouble, jstring);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadU8
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadU8
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadS8
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadS8
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadU16
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadU16
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadS16
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadS16
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadU32
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadU32
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadS32
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadS32
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadF16
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadF16
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadF32
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadF32
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadMessageID
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadMessageID
  (JNIEnv *, jclass, jdouble);

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadMessageID
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadBool
  (JNIEnv *, jclass, jdouble);


/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadString
 * Signature: (D)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadString
  (JNIEnv *, jclass, jdouble);

#ifdef __cplusplus
}
#endif
#endif
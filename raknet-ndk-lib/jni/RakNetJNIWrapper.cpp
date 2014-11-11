/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include "RakNetJNIWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Last_1Error
  (JNIEnv * env, jclass clazz) {
      return (env)->NewStringUTF(GMRak_Last_Error());
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Create
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Create
  (JNIEnv * env, jclass clazz) {
		return GMRak_Peer_Create();
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Destroy
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Destroy
  (JNIEnv * env, jclass clazz, jdouble peerID) {
return GMRak_Peer_Destroy(peerID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Shutdown
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Shutdown
  (JNIEnv * env, jclass clazz, jdouble peerID) {
return GMRak_Peer_Shutdown(peerID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Startup_Client
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Startup_1Client
  (JNIEnv * env, jclass clazz, jdouble peerID) {
return GMRak_Peer_Startup_Client(peerID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Startup_Server
 * Signature: (DDD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Startup_1Server
  (JNIEnv * env, jclass clazz, jdouble peerID, jdouble maxConnections, jdouble port) {
return GMRak_Peer_Startup_Server(peerID,maxConnections,port);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Connect
 * Signature: (DLjava/lang/String;D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Connect
  (JNIEnv * env, jclass clazz, jdouble peerID, jstring host, jdouble port) {
    const char* utf_string;
    double res = 0;
    jboolean isCopy;
    utf_string = env->GetStringUTFChars(host, &isCopy);
    res = GMRak_Peer_Connect(peerID,(char*)(utf_string),port);
    env->ReleaseStringUTFChars(host, utf_string);
return res;
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_SetMaxIncomingConnections
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1SetMaxIncomingConnections
  (JNIEnv * env, jclass clazz, jdouble peerID, jdouble maxIncomingConnections) {
return GMRak_Peer_SetMaxIncomingConnections(peerID,maxIncomingConnections);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Receive
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Receive
  (JNIEnv * env, jclass clazz, jdouble peerID) {
return GMRak_Peer_Receive(peerID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Send
 * Signature: (DDDDDDD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Send
  (JNIEnv * env, jclass clazz, jdouble peerID, jdouble bitstreamID, jdouble priority, jdouble reliability, jdouble orderingChannel, jdouble guid, jdouble broadcast) {
return GMRak_Peer_Send(peerID,bitstreamID,priority,reliability,orderingChannel,guid,broadcast);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Peer_Deallocate_Packet
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Peer_1Deallocate_1Packet
  (JNIEnv * env, jclass clazz, jdouble peerID, jdouble packetID) {
return GMRak_Peer_Deallocate_Packet(peerID,packetID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Packet_GetMessageIdentifier
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Packet_1GetMessageIdentifier
  (JNIEnv * env, jclass clazz, jdouble packetID) {
return GMRak_Packet_GetMessageIdentifier(packetID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Packet_Get_GUID
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Packet_1Get_1GUID
  (JNIEnv * env, jclass clazz, jdouble packetID) {
return GMRak_Packet_Get_GUID(packetID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_GUID_Destroy
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1GUID_1Destroy
  (JNIEnv * env, jclass clazz, jdouble guidID) {
return GMRak_GUID_Destroy(guidID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_Create
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1Create
  (JNIEnv * env, jclass clazz) {
return GMRak_Bitstream_Create();
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_Create_From_Packet
 * Signature: (DDD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1Create_1From_1Packet
  (JNIEnv * env, jclass clazz, jdouble bitstreamID, jdouble skipMessageID, jdouble copyData) {
return GMRak_Bitstream_Create_From_Packet(bitstreamID,skipMessageID,copyData);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_Destroy
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1Destroy
  (JNIEnv * env, jclass clazz, jdouble bitstreamID) {
return GMRak_Bitstream_Destroy(bitstreamID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteMessageID
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteMessageID
  (JNIEnv * env, jclass clazz, jdouble bitstream, jdouble value) {
return GMRak_Bitstream_WriteMessageID(bitstream,value);
  }
/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteU8
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteU8
  (JNIEnv * env, jclass clazz, jdouble bitstreamID, jdouble value) {
return GMRak_Bitstream_WriteU8(bitstreamID,value);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteS8
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteS8
  (JNIEnv * env, jclass clazz, jdouble bitstreamID, jdouble value) {
return GMRak_Bitstream_WriteS8(bitstreamID,value);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteU16
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteU16
  (JNIEnv * env, jclass clazz, jdouble bitstreamID, jdouble value) {
return GMRak_Bitstream_WriteU16(bitstreamID,value);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteS16
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteS16
  (JNIEnv * env, jclass clazz, jdouble bitstreamID, jdouble value) {
return GMRak_Bitstream_WriteS16(bitstreamID,value);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteU32
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteU32
  (JNIEnv * env, jclass clazz, jdouble bitstreamID, jdouble value) {
return GMRak_Bitstream_WriteU32(bitstreamID,value);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteS32
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteS32
  (JNIEnv * env, jclass clazz, jdouble bitstreamID, jdouble value) {
return GMRak_Bitstream_WriteS32(bitstreamID, value);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteF16
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteF32
  (JNIEnv * env, jclass clazz, jdouble bitstreamID, jdouble value) {
return GMRak_Bitstream_WriteF32((double)bitstreamID,(double)value);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteF32
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteF64
  (JNIEnv * env, jclass clazz, jdouble bitstreamID, jdouble value) {
return GMRak_Bitstream_WriteF64(bitstreamID, value);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteBool
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteBool
  (JNIEnv * env, jclass clazz, jdouble bitstreamID, jdouble value) {
    return GMRak_Bitstream_WriteBool(bitstreamID,value);
  } 

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_WriteString
 * Signature: (DLjava/lang/String;)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1WriteString
  (JNIEnv * env, jclass clazz, jdouble bitstreamID, jstring str) {
    const char* utf_string;
    double res = 0;
    jboolean isCopy;
    utf_string = env->GetStringUTFChars(str, &isCopy);
    res = GMRak_Bitstream_WriteString(bitstreamID,(char*)(utf_string)); 
    env->ReleaseStringUTFChars(str, utf_string);
    return res;
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadU8
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadU8
  (JNIEnv * env, jclass clazz, jdouble bitstreamID) {
    return GMRak_Bitstream_ReadU8(bitstreamID);
}

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadS8
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadS8
  (JNIEnv * env, jclass clazz, jdouble bitstreamID) {
    return GMRak_Bitstream_ReadS8(bitstreamID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadU16
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadU16
  (JNIEnv * env, jclass clazz, jdouble bitstreamID) {
    return GMRak_Bitstream_ReadU16(bitstreamID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadS16
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadS16
  (JNIEnv * env, jclass clazz, jdouble bitstreamID) {
    return GMRak_Bitstream_ReadS16(bitstreamID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadU32
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadU32
  (JNIEnv * env, jclass clazz, jdouble bitstreamID) {
return GMRak_Bitstream_ReadU32(bitstreamID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadS32
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadS32
  (JNIEnv * env, jclass clazz, jdouble bitstreamID) {
    return GMRak_Bitstream_ReadS32(bitstreamID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadF16
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadF32
  (JNIEnv * env, jclass clazz, jdouble bitstreamID) {
    return (jdouble)GMRak_Bitstream_ReadF32(bitstreamID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadF32
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadF64
  (JNIEnv * env, jclass clazz, jdouble bitstreamID) {
    return GMRak_Bitstream_ReadF64(bitstreamID);
  } 

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadMessageID
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadMessageID
  (JNIEnv * env, jclass clazz, jdouble bitstreamID) {
    return GMRak_Bitstream_ReadMessageID(bitstreamID);
  }


/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadMessageID
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadBool
  (JNIEnv * env, jclass clazz, jdouble bitstreamID) {
    return GMRak_Bitstream_ReadBool(bitstreamID);
  }

/*
 * Class:     com_triebr_raknet_RakNetJNIWrapper
 * Method:    RakNative_Bitstream_ReadString
 * Signature: (D)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_triebr_raknet_RakNetJNIWrapper_RakNative_1Bitstream_1ReadString
  (JNIEnv * env, jclass clazz, jdouble bitstreamID) {
  	const char* str= GMRak_Bitstream_ReadString(bitstreamID);
      return (env)->NewStringUTF(str);
  }

  #ifdef __cplusplus
}
#endif

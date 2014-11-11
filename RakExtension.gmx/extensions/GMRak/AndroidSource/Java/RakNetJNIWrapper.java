package com.triebr.raknet;



public class RakNetJNIWrapper
{

	public static void Init() {    
    	System.loadLibrary("RakNet");   //Load the RakNet .so file 
    } // end Init

	public static native String RakNative_Last_Error();
	//Peer operations
	public static native double RakNative_Peer_Create();
	public static native double RakNative_Peer_Destroy(double peerID);
	public static native double RakNative_Peer_Shutdown(double peerID);
	public static native double RakNative_Peer_Startup_Client(double peerID);
	public static native double RakNative_Peer_Startup_Server(double peerID, double maxConnections, double port);
	public static native double RakNative_Peer_Connect(double peerID, String serverIP, double port);
	public static native double RakNative_Peer_SetMaxIncomingConnections(double peerID, double maxPlayersPerServer);
	public static native double RakNative_Peer_Receive(double peerID);
	public static native double RakNative_Peer_Send(double peerID, double bitstreamID, double priority, double reliability, double orderingChannel, double gUIDID, double broadcast);
	public static native double RakNative_Peer_Deallocate_Packet(double peerID, double packetID) ;
	//Packet operations
	public static native double RakNative_Packet_GetMessageIdentifier(double packetID);
	public static native double RakNative_Packet_Get_GUID(double packetID);
	//GUID operations
	public static native double RakNative_GUID_Destroy(double guidID);
	//Bitstream Operations
	public static native double RakNative_Bitstream_Create();
	public static native double RakNative_Bitstream_Create_From_Packet(double packetID, double skipMessageID, double copyData);
	public static native double RakNative_Bitstream_Destroy(double bitstreamID);

	//Bitstream Operations
	public static native double RakNative_Bitstream_ReadU8(double bitstreamID);
	public static native double RakNative_Bitstream_ReadS8(double bitstreamID);
	public static native double RakNative_Bitstream_ReadU16(double bitstreamID);
	public static native double RakNative_Bitstream_ReadS16(double bitstreamID);
	public static native double RakNative_Bitstream_ReadU32(double bitstreamID);
	public static native double RakNative_Bitstream_ReadS32(double bitstreamID);
	public static native double RakNative_Bitstream_ReadF32(double bitstreamID);
	public static native double RakNative_Bitstream_ReadF64(double bitstreamID) ;
	public static native double RakNative_Bitstream_ReadBool(double bitstreamID);
	public static native String RakNative_Bitstream_ReadString(double bitstreamID);
	public static native double RakNative_Bitstream_ReadMessageID(double bitstreamID);
	public static native double RakNative_Bitstream_WriteU8(double bitstreamID, double val);
	public static native double RakNative_Bitstream_WriteS8(double bitstreamID, double val) ;
	public static native double RakNative_Bitstream_WriteU16(double bitstreamID, double val);
	public static native double RakNative_Bitstream_WriteS16(double bitstreamID, double val);
	public static native double RakNative_Bitstream_WriteU32(double bitstreamID, double val);
	public static native double RakNative_Bitstream_WriteS32(double bitstreamID, double val);
	public static native double RakNative_Bitstream_WriteF32(double bitstreamID, double val);
	public static native double RakNative_Bitstream_WriteF64(double bitstreamID, double val);
	public static native double RakNative_Bitstream_WriteBool(double bitstreamID, double val);
	public static native double RakNative_Bitstream_WriteString(double bitstreamID, String val);
	public static native double RakNative_Bitstream_WriteMessageID(double bitstreamID, double val);


}
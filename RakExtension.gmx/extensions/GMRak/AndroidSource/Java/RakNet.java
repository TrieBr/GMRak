package ${YYAndroidPackageName};

import android.util.Log;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.lang.String;

import ${YYAndroidPackageName}.R;
import com.yoyogames.runner.RunnerJNILib;
import com.triebr.raknet.RakNetJNIWrapper;


public class RakNet
{
	public double GMRak_Init() {
		RakNetJNIWrapper.Init();
		return 1.0;
	}
	public String GMRak_LastError() {
		return RakNetJNIWrapper.RakNative_Last_Error();
	}

	/*
		PEER FUNCTIONS
	*/

	public double GMRak_Peer_Create() {
		return RakNetJNIWrapper.RakNative_Peer_Create();
	}
	public double GMRak_Peer_Destroy(double peerID) {
		return RakNetJNIWrapper.RakNative_Peer_Destroy(peerID);
	}
	public double GMRak_Peer_Shutdown(double peerID) {
		return RakNetJNIWrapper.RakNative_Peer_Shutdown(peerID);
	}
	public double GMRak_Peer_Startup_Client(double peerID) {
		double f = RakNetJNIWrapper.RakNative_Peer_Startup_Client(peerID);
		return f;
	}
	public double GMRak_Peer_Receive(double peerID) {
		return RakNetJNIWrapper.RakNative_Peer_Receive(peerID);
	}
	public double GMRak_Peer_Connect(double peerID,String host, double port) {
		return RakNetJNIWrapper.RakNative_Peer_Connect(peerID, host, port);
	}
	public double GMRak_Peer_Deallocate_Packet(double peerID, double packetID) {
		return RakNetJNIWrapper.RakNative_Peer_Deallocate_Packet(peerID, packetID);
	}
	public double GMRak_Peer_Startup_Server(double peerID, double maxConnections, double port) {
		return RakNetJNIWrapper.RakNative_Peer_Startup_Server(peerID, maxConnections, port);
	}
	public double GMRak_Peer_SetMaxIncomingConnections(double peerID, double maxConnections) {
		return RakNetJNIWrapper.RakNative_Peer_SetMaxIncomingConnections(peerID, maxConnections);
	}
	public double GMRak_Peer_Send(double peerID, double bitstreamID, double priority, double reliability, double orderingChannel, double guid, double broadcast) {
		return RakNetJNIWrapper.RakNative_Peer_Send(peerID, bitstreamID, priority, reliability, orderingChannel, guid, broadcast);
	}
	/*
		PACKET FUNCTIONS
	*/
	public double GMRak_Packet_GetMessageIdentifier(double packetID) {
		return RakNetJNIWrapper.RakNative_Packet_GetMessageIdentifier(packetID);
	}
	public double GMRak_Packet_Get_GUID(double packetID) {
		return RakNetJNIWrapper.RakNative_Packet_Get_GUID(packetID);
	}
	/*
		GUID Functions
	*/
	public double GMRak_GUID_Destroy(double guidID) {
		return RakNetJNIWrapper.RakNative_GUID_Destroy(guidID);
	}

	
	/*
		BITSTREAM FUNCTIONS
	*/
	public double GMRak_Bitstream_Create_From_Packet(double packetID, double skipMessageID, double copyData) {
		return RakNetJNIWrapper.RakNative_Bitstream_Create_From_Packet(packetID, skipMessageID, copyData);
	}
	//Bitstream reading Functions
	public double GMRak_Bitstream_ReadU8(double bitstreamID) {
		return RakNetJNIWrapper.RakNative_Bitstream_ReadU8(bitstreamID);
	}
	public double GMRak_Bitstream_ReadS8(double bitstreamID) {
		return RakNetJNIWrapper.RakNative_Bitstream_ReadS8(bitstreamID);
	}
	public double GMRak_Bitstream_ReadU16(double bitstreamID) {
		return RakNetJNIWrapper.RakNative_Bitstream_ReadU16(bitstreamID);
	}
	public double GMRak_Bitstream_ReadS16(double bitstreamID) {
		return RakNetJNIWrapper.RakNative_Bitstream_ReadS16(bitstreamID);
	}
	public double GMRak_Bitstream_ReadU32(double bitstreamID) {
		return RakNetJNIWrapper.RakNative_Bitstream_ReadU32(bitstreamID);
	}
	public double GMRak_Bitstream_ReadS32(double bitstreamID) {
		return RakNetJNIWrapper.RakNative_Bitstream_ReadS32(bitstreamID);
	}
	public double GMRak_Bitstream_ReadF32(double bitstreamID) {
		return RakNetJNIWrapper.RakNative_Bitstream_ReadF32(bitstreamID);
	}
	public double GMRak_Bitstream_ReadF64(double bitstreamID) {
		return RakNetJNIWrapper.RakNative_Bitstream_ReadF64(bitstreamID);
	}
	public double GMRak_Bitstream_ReadBool(double bitstreamID) {
		return RakNetJNIWrapper.RakNative_Bitstream_ReadBool(bitstreamID);
	}
	public String GMRak_Bitstream_ReadString(double bitstreamID) {
		return RakNetJNIWrapper.RakNative_Bitstream_ReadString(bitstreamID);
	}
	public double GMRak_Bitstream_ReadMessageID(double bitstreamID) {
		return RakNetJNIWrapper.RakNative_Bitstream_ReadMessageID(bitstreamID);
	}

	public double GMRak_Bitstream_Destroy(double bitstreamID) {
		return RakNetJNIWrapper.RakNative_Bitstream_Destroy(bitstreamID);
	}

	//Bitstream Writing Functions
	public double GMRak_Bitstream_Create() {
		return RakNetJNIWrapper.RakNative_Bitstream_Create();
	}
	public double GMRak_Bitstream_WriteU8(double bitstream, double value) {
		return RakNetJNIWrapper.RakNative_Bitstream_WriteU8(bitstream, value);
	}
	public double GMRak_Bitstream_WriteS8(double bitstream, double value) {
		return RakNetJNIWrapper.RakNative_Bitstream_WriteS8(bitstream, value);
	}
	public double GMRak_Bitstream_WriteU16(double bitstream, double value) {
		return RakNetJNIWrapper.RakNative_Bitstream_WriteU16(bitstream, value);
	}
	public double GMRak_Bitstream_WriteS16(double bitstream, double value) {
		return RakNetJNIWrapper.RakNative_Bitstream_WriteS16(bitstream, value);
	}
	public double GMRak_Bitstream_WriteU32(double bitstream, double value) {
		return RakNetJNIWrapper.RakNative_Bitstream_WriteU32(bitstream, value);
	}
	public double GMRak_Bitstream_WriteS32(double bitstream, double value) {
		return RakNetJNIWrapper.RakNative_Bitstream_WriteS32(bitstream, value);
	}
	public double GMRak_Bitstream_WriteF32(double bitstream, double value) {
		return RakNetJNIWrapper.RakNative_Bitstream_WriteF32(bitstream, value);
	}
	public double GMRak_Bitstream_WriteF64(double bitstream, double value) {
		double t = (double) value;
		return RakNetJNIWrapper.RakNative_Bitstream_WriteF64(bitstream,t);
	}
	public double GMRak_Bitstream_WriteBool(double bitstream, double value) {
		return RakNetJNIWrapper.RakNative_Bitstream_WriteBool(bitstream, value);
	}
	public double GMRak_Bitstream_WriteString(double bitstream, String value) {
		return RakNetJNIWrapper.RakNative_Bitstream_WriteString(bitstream, value);
	}
	public double GMRak_Bitstream_WriteMessageID(double bitstream, double value) {
		return RakNetJNIWrapper.RakNative_Bitstream_WriteMessageID(bitstream, value);
	}


}
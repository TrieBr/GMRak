#include "MessageIdentifiers.h"
#include "RakPeerInterface.h"
#include "RakNetTypes.h"
#include "BitStream.h"
#include "PacketPriority.h"
#include "RakString.h"

#include <string>

#include <map>

#include "GMInstanceManager.h"

#ifdef _WIN32
#define GMEXPORT extern "C" __declspec (dllexport)
#else
#define GMEXPORT
#endif

#define GM_TRUE 1.0f
#define GM_FALSE 0.0f
#define GM_ERROR -2.0f

static std::string lastError = "None";

GMInstanceManager<RakNet::RakPeerInterface> peers;		//Peer instances
GMInstanceManager<RakNet::Packet> packets;				//packet instances
GMInstanceManager<RakNet::BitStream> bitstreams;		//Bitstreams
GMInstanceManager<RakNet::AddressOrGUID> addressOrGUIDs;//AddressorGUIDs


GMEXPORT double GMRak_Init() {
	return GM_TRUE;
}

GMEXPORT char* GMRak_Last_Error() {
	return const_cast<char*>(lastError.c_str());
}


/*
	Creates a new RakNet::RakPeerInterface
	Returns the ID or -1 on error.
*/
GMEXPORT double GMRak_Peer_Create(){
	RakNet::RakPeerInterface* peer = RakNet::RakPeerInterface::GetInstance();
	if (peer == NULL) return -1;
	return peers.GetID(peer);
}

/*
	Destory the specified peerInterface
*/
GMEXPORT double GMRak_Peer_Destroy(double peerID) {
	RakNet::RakPeerInterface* peer = peers.GetInstance(peerID);
	if (peer) {
		RakNet::RakPeerInterface::DestroyInstance(peer);
		return GM_TRUE;
	}
	lastError = "Peer ID does not exist";
	return GM_FALSE; //peerID not found
}

/*
	Shutdowns the specified peer
*/

GMEXPORT double GMRak_Peer_Shutdown(double peerID) {
	RakNet::RakPeerInterface* peer = peers.GetInstance(peerID);
	if (peer) {
		peer->Shutdown(300);
		return GM_TRUE;
	}
	lastError = "Peer ID does not exist";
	return GM_FALSE;
}

/*
	Startup peer (as a client)
*/

GMEXPORT double GMRak_Peer_Startup_Client(double peerID) {
	RakNet::RakPeerInterface* peer = peers.GetInstance(peerID);
	if (peer) {
		RakNet::SocketDescriptor descriptor;
		RakNet::StartupResult res =  peer->Startup(1, &descriptor, 1);
		if (res == RakNet::RAKNET_STARTED || res == RakNet::RAKNET_ALREADY_STARTED) //If startup succeeded
			return GM_TRUE;
		else{
			lastError = "Peer Startup() did not return RAKNET_STARTED or RAKNET_ALREADY_STARTED.";
			return GM_FALSE;
		}
	}
	lastError = "Peer ID does not exist";
	return GM_FALSE;
}

/*
	Startup peer (as a server)
*/
GMEXPORT double GMRak_Peer_Startup_Server(double peerID, double maxConnections, double port) {
	RakNet::RakPeerInterface* peer = peers.GetInstance(peerID);
	if (peer) {
		RakNet::SocketDescriptor descriptor((unsigned short)port, 0);
		RakNet::StartupResult res = peer->Startup((int)maxConnections, &descriptor, 1);
		if (res == RakNet::RAKNET_STARTED || res == RakNet::RAKNET_ALREADY_STARTED) //If startup succeeded
			return GM_TRUE;
		else{
			lastError = "Peer Startup() did not return RAKNET_STARTED or RAKNET_ALREADY_STARTED.";
			return GM_FALSE;
		}
	}
	lastError = "Peer ID does not exist";
	return GM_FALSE;
}

/*
	Connect Peer
*/
GMEXPORT double GMRak_Peer_Connect(double peerID, char* serverIP, double port) {
	RakNet::RakPeerInterface* peer = peers.GetInstance(peerID);
	if (peer) {
		RakNet::ConnectionAttemptResult res =  peer->Connect(serverIP, (unsigned short)port, 0, 0);
		if (res == RakNet::CONNECTION_ATTEMPT_STARTED) //If connection attempt was started
			return GM_TRUE;
		else{
			lastError = "Peer Connect() did not return CONNECTION_ATTEMPT_STARTED.";
			return GM_FALSE;
		}
	}
	lastError = "Peer ID does not exist";
	return GM_FALSE;
}

/*
		Set Maximum incoming connections on a peer
*/
GMEXPORT double GMRak_Peer_SetMaxIncomingConnections(double peerID, double maxPlayersPerServer) {
	RakNet::RakPeerInterface* peer = peers.GetInstance(peerID);
	if (peer) {
		peer->SetMaximumIncomingConnections((int)maxPlayersPerServer);
			return GM_TRUE;
	}
	lastError = "Peer ID does not exist";
	return GM_FALSE;
}


/*
		Receives packets on specified Peer.
		Returns ID for a RakNet::Packet, -1 for no packet, or on error
*/
GMEXPORT double GMRak_Peer_Receive(double peerID) {
	RakNet::RakPeerInterface* peer = peers.GetInstance(peerID);
	if (peer) {
		RakNet::Packet *packet = peer->Receive();
		if (!packet) return -1.0f; //No packet received
		return packets.GetID(packet);
	}
	lastError = "Peer ID does not exist";
	return GM_ERROR;
}


/*
	Sends data on specified peer
*/
GMEXPORT double GMRak_Peer_Send(double peerID, double bitstreamID, double priority, double reliability, double orderingChannel, double GUIDID, double broadcast) {
	RakNet::RakPeerInterface* peer = peers.GetInstance(peerID);
	if (peer) {
		RakNet::BitStream* bitstream = bitstreams.GetInstance(bitstreamID);
		if (bitstream){
				if (GUIDID == -1.0f) { //Unassigned GUID
					peer->Send(bitstream, (PacketPriority)(int)priority, (PacketReliability)(int)reliability, (char)orderingChannel, RakNet::UNASSIGNED_RAKNET_GUID, (bool)broadcast);
					return GM_TRUE;
				}
				else{
					RakNet::AddressOrGUID* guid = addressOrGUIDs.GetInstance(GUIDID);
					if (guid) {
						peer->Send(bitstream, (PacketPriority)(int)priority, (PacketReliability)(int)reliability, (char)orderingChannel, *guid, (bool)broadcast);
						return GM_TRUE;
					}
					else{
						lastError = "AddressOrGUID does not exist with that ID.";
						return GM_ERROR;
					}
				}
		}
		else{
			lastError = "Bitstream ID does not exist";
			return GM_ERROR;
		}
		
	}
	lastError = "Peer ID does not exist";
	return GM_ERROR;
}

/*
Deallocates a packet
return GM_TRUE on success, GM_ERROR on failure
*/
GMEXPORT double GMRak_Peer_Deallocate_Packet(double peerID, double packetID) {
	RakNet::RakPeerInterface* peer = peers.GetInstance(peerID);
	if (peer) {
		RakNet::Packet* packet = packets.GetInstance(packetID);
		if (packet) {
			peer->DeallocatePacket(packet);
			return GM_TRUE;
		}
		lastError = "Packet ID does not exist";
		return GM_ERROR;
	}
	lastError = "Peer ID does not exist";
	return GM_ERROR;
}



unsigned char GetPacketIdentifier(RakNet::Packet *p)
{
	if ((unsigned char)p->data[0] == ID_TIMESTAMP)
		return (unsigned char)p->data[sizeof(RakNet::MessageID)+sizeof(RakNet::Time)];
	else
		return (unsigned char)p->data[0];
}

/*
		Gets packet identifier for packet
		Returns identifier, GM_ERROR on failure
*/
GMEXPORT double GMRak_Packet_GetMessageIdentifier(double packetID) {
	RakNet::Packet* packet = packets.GetInstance(packetID);
	if (packet) {
		return (double)GetPacketIdentifier(packet);
	}
	lastError = "Packet ID does not exist";
	return GM_ERROR;
}

/*
Gets packet identifier for packet
Returns identifier, GM_ERROR on failure
*/
GMEXPORT double GMRak_Packet_Get_GUID(double packetID) {
	RakNet::Packet* packet = packets.GetInstance(packetID);
	if (packet) {
		RakNet::AddressOrGUID* guid = new RakNet::AddressOrGUID();
		(*guid) = packet->guid;
		return addressOrGUIDs.GetID(guid);
	}
	lastError = "Packet ID does not exist";
	return GM_ERROR;
}


/*
	Destroy specified GUID
*/

GMEXPORT double GMRak_GUID_Destroy(double guidID){
	RakNet::AddressOrGUID* guid = addressOrGUIDs.GetInstance(guidID);
	if (guid) {
		addressOrGUIDs.DestroyID(guidID);
		delete guid;
		return GM_TRUE;
	}
	lastError = "GUID ID does not exist";
	return GM_ERROR;

}




/*
	Creates a new bitstream and returns the ID
*/

GMEXPORT double GMRak_Bitstream_Create() {
	RakNet::BitStream *newStream = new RakNet::BitStream();
	return bitstreams.GetID(newStream);
}


/*
Creates a new bitstream and returns the ID
*/

GMEXPORT double GMRak_Bitstream_Create_From_Packet(double packetID, double skipMessageID, double copyData) {
	RakNet::Packet* packet = packets.GetInstance(packetID);
	if (packet) {
		RakNet::BitStream *newStream;
		bool copy = (bool)copyData;
		if ((bool)skipMessageID) {
			newStream = new RakNet::BitStream(packet->data + sizeof(RakNet::MessageID), packet->length - sizeof(RakNet::MessageID), copy);
		}
		else{
			newStream = new RakNet::BitStream(packet->data, packet->length, copy);
		}
		return bitstreams.GetID(newStream);
	}
	lastError = "Packet ID does not exist";
	return GM_ERROR;
}

/*
	Destroys specified bitstream
*/

GMEXPORT double GMRak_Bitstream_Destroy(double bitstreamID) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		bitstreams.DestroyID(bitstreamID);
		delete bitstream;
		return GM_TRUE;
	}
	lastError = "Bitstream ID does not exist";
	return GM_ERROR;
}

/*
//Write message ID to bitstream
//Returns true on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_WriteMessageID(double bitstreamID, double val) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		bitstream->Write((RakNet::MessageID)val);
		return GM_TRUE;
	}
	lastError = "Bitstream ID does not exist";
	return GM_FALSE;
}

/*
	//Write unsigned byte to bitstream
	//Returns true on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_WriteU8(double bitstreamID, double val) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		bitstream->Write((unsigned char)val);
		return GM_TRUE;
	}
	lastError = "Bitstream ID does not exist";
	return GM_FALSE;
}

/*
//Write  signed char to bitstream
//Returns true on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_WriteS8(double bitstreamID, double val) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		bitstream->Write((signed char)val);
		return GM_TRUE;
	}
	lastError = "Bitstream ID does not exist";
	return GM_FALSE;
}

/*
//Write  unsigned short to bitstream
//Returns true on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_WriteU16(double bitstreamID, double val) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		bitstream->Write((unsigned short)val);
		return GM_TRUE;
	}
	lastError = "Bitstream ID does not exist";
	return GM_FALSE;
}

/*
//Write  signed short to bitstream
//Returns true on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_WriteS16(double bitstreamID, double val) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		bitstream->Write((signed short)val);
		return GM_TRUE;
	}
	lastError = "Bitstream ID does not exist";
	return GM_FALSE;
}

/*
//Write  unsigned int to bitstream
//Returns true on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_WriteU32(double bitstreamID, double val) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		bitstream->Write((unsigned int)val);
		return GM_TRUE;
	}
	lastError = "Bitstream ID does not exist";
	return GM_FALSE;
}

/*
//Write int to bitstream
//Returns true on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_WriteS32(double bitstreamID, double val) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		bitstream->Write((signed int)val);
		return GM_TRUE;
	}
	lastError = "Bitstream ID does not exist";
	return GM_FALSE;
}

/*
//Write 32-bit float to bitstream
//Returns true on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_WriteF32(double bitstreamID, double val) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		float v = (float)val;
		bitstream->Write(v);
		return GM_TRUE;
	}
	lastError = "Bitstream ID does not exist";
	return GM_FALSE;
}

/*
//Write 64-bit float to bitstream
//Returns true on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_WriteF64(double bitstreamID, double val) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		bitstream->Write(val);
		return GM_TRUE;
	}
	lastError = "Bitstream ID does not exist";
	return GM_FALSE;
}

/*
//Write boolean to bitstream
//Returns true on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_WriteBool(double bitstreamID, double val) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		bitstream->Write((bool)val);
		return GM_TRUE;
	}
	lastError = "Bitstream ID does not exist";
	return GM_FALSE;
}

/*
//Write string to bitstream
//Returns true on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_WriteString(double bitstreamID, char* val) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		RakNet::RakString string(val);
		bitstream->Write(val);
		return GM_TRUE;
	}
	lastError = "Bitstream ID does not exist";
	return GM_FALSE;
}


/*
//Read unsigned char from Bitstream
//Returns value on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_ReadU8(double bitstreamID) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		unsigned char val;
		bitstream->Read(val);
		return (double)val;
	}
	lastError = "Bitstream ID does not exist";
	return GM_ERROR;
}

/*
//Read signed char from Bitstream
//Returns value on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_ReadS8(double bitstreamID) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		signed char val;
		bitstream->Read(val);
		return (double)val;
	}
	lastError = "Bitstream ID does not exist";
	return GM_ERROR;
}
/*
//Read unsigned short from Bitstream
//Returns value on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_ReadU16(double bitstreamID) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		unsigned short val;
		bitstream->Read(val);
		return (double)val;
	}
	lastError = "Bitstream ID does not exist";
	return GM_ERROR;
}

/*
//Read signed short from Bitstream
//Returns value on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_ReadS16(double bitstreamID) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		signed short val;
		bitstream->Read(val);
		return (double)val;
	}
	lastError = "Bitstream ID does not exist";
	return GM_ERROR;
}

/*
//Read unsigned int from Bitstream
//Returns value on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_ReadU32(double bitstreamID) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		unsigned int val;
		bitstream->Read(val);
		return (double)val;
	}
	lastError = "Bitstream ID does not exist";
	return GM_ERROR;
}

/*
//Read signed int from Bitstream
//Returns value on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_ReadS32(double bitstreamID) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		signed int val;
		bitstream->Read(val);
		return (double)val;
	}
	lastError = "Bitstream ID does not exist";
	return GM_ERROR;
}

/*
//Read 32 bit float from Bitstream
//Returns value on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_ReadF32(double bitstreamID) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		float val;
		bitstream->Read(val);
		return (double)val;
	}
	lastError = "Bitstream ID does not exist";
	return GM_ERROR;
}

/*
//Read 64 bit float from Bitstream
//Returns value on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_ReadF64(double bitstreamID) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		double val;
		bitstream->Read(val);
		return (double)val;
	}
	lastError = "Bitstream ID does not exist";
	return GM_ERROR;
}

/*
//Read messageID from Bitstream
//Returns value on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_ReadMessageID(double bitstreamID) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		RakNet::MessageID val;
		bitstream->Read(val);
		return (double)val;
	}
	lastError = "Bitstream ID does not exist";
	return GM_ERROR;
}

/*
//Read boolean from Bitstream
//Returns value on success, GM_ERROR on failure
*/

GMEXPORT double GMRak_Bitstream_ReadBool(double bitstreamID) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		bool val;
		bitstream->Read(val);
		return (double)val;
	}
	lastError = "Bitstream ID does not exist";
	return GM_ERROR;
}


/*
//Read string from Bitstream
//Returns value on success, GM_ERROR on failure
*/

GMEXPORT char* GMRak_Bitstream_ReadString(double bitstreamID) {
	RakNet::BitStream *bitstream = bitstreams.GetInstance(bitstreamID);
	if (bitstream) {
		RakNet::RakString str;
		bitstream->Read(str);
		return str.C_StringUnsafe();
	}
	lastError = "Bitstream ID does not exist";

	return const_cast<char*>("");
}
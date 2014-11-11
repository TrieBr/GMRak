
#include <map>
#include <queue>

/*
	Used to Associate C++ class instances with a double so GameMaker can reference it..
*/

template <class T>
class GMInstanceManager {
public:
	//Constructor
	GMInstanceManager() {
		IDCounter = 0;
	}
	//Get the ID (or create a new ID) for the pointer
	double GetID(T* instance) {
		typename std::map<double, T*>::iterator i;
		for (i = instances.begin(); i != instances.end(); ++i) {
			if (i->second == instance){
				return i->first; //ID already exists so we return it.
			}
		}
		int newID;
		if (!reUseID.empty()) {
			newID = (int)reUseID.front();
			reUseID.pop();
		}
		else{
			newID = IDCounter++;
		}
		instances.insert(std::pair<double,T*>((double)newID, instance));
		return (double)(newID);
	}
	//Get the instance pointer based on the ID
	T* GetInstance(double ID) {
		typename std::map<double, T*>::iterator i;
		i = instances.find(ID);
		if (i == instances.end()) return NULL; //Not found
		return i->second;
	}
	//Marks the instance as destoryed and frees up the ID it was using
	bool DestroyID(double ID) {
		typename std::map<double, T*>::iterator i;
		i = instances.find(ID);
		if (i == instances.end()) return false; //Not found..
		instances.erase(i);
		reUseID.push(ID); //Add to list of reusable ID's
		return true;
	}

private:
	std::map<double, T*> instances;	//Map to map ID's to pointers
	std::queue<double> reUseID;	//ID's that have been desroyed and can be reused now
	int IDCounter;					//ID counter for new ID's
};
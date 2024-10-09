#pragma once
#include <external.h>

class NPC;

class Location
{
private:
    string name;
    string desc;
    int rank;
    vector<NPC*> npcsPresent;
    unordered_map<Location*,int> paths;

    //private helpers
    void genLocation();
    // void setLocInMap();

public:
    Location(int rank);
    Location(int rank,const string &name);
    Location(int rank,const string &name, const string &desc);

    //getters
    string getName() const;
    string getDesc() const;
    vector<NPC*> getNPCs() const;
    unordered_map<Location*,int> getPaths() const;

    //npc adding and deleting
    void addNPC(NPC *npc);
    void removeNPC(NPC *npc);

    //graph manipulations
    void addPath(Location *loc);
    vector<Location*>bfsTraversal();
    vector<Location*>dfsTraversal();

    //travel
    Location *travel(Location* dest);        //travel to the dest in shortest path possible.
};

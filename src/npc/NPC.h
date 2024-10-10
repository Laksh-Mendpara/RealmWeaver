#pragma once

#include <external.h>
#include <Gemini.h>
#include <Location.h>

class Stats;
class Quest;

class NPC {
private:
    int rank;                           // The rank of the NPC, determining difficulty or importance
    string name;                        // Name of the NPC
    string backStory;                   // The NPC's backstory generated by Gemini API
    Location *loc;
    Stats* stats;                       // Dynamic stats for the NPC
    queue<Quest*> quests;               // Queue of quests that the NPC can offer

    // Helper functions
    string generateName(int rank);              // Generates a name based on the NPC's rank (via Gemini API)
    string generateBackStory(int rank);         // Generates a backstory based on the NPC's rank (via Gemini API)
    // void generateQuests();                      // Generate initial quests (from Gemini API or DB)

public:
    // Constructors
    NPC(int rank, Location &loc);                             // Constructor that generates NPC dynamically from Gemini
    NPC(int rank, const string& name, const string& backStory, Location* loc); // Constructor with manual values

    // Getters
    int getRank() const;                       // Get the NPC's rank
    string getName() const;               // Get the NPC's name
    string getBackStory() const;          // Get the NPC's backstory
    Stats* getStats() const;                   // Get NPC's stats

    // Quest management
    void addQuest(Quest* quest);               // Add a quest to the NPC's quest queue
    void removeQuest();                        // Remove the first quest (once completed)
    Quest* getCurrentQuest() const;            // Get the current quest offered by NPC
    bool hasQuests() const;                    // Check if NPC has any quests available

    // Display
    void displayNPCInfo() const;               // Display NPC's basic info
    void displayQuests() const;                // Display all available quests

    // Interaction
    void interact();                           // Interaction logic for talking to the NPC
};

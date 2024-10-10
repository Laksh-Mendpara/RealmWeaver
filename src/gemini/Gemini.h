#pragma once

#include <external.h>
#include <GameEngine.h>
#include <NPC.h>
#include <Stats.h>

class Gemini
{
    private:
        string apiKey;
        mutex apiMutex;

        void getApiKey();
        static int WriteCallBack(void* contents, int size, int nmemb, void* userp);
        json sendGeminiReq(const string &prompt);
        json sendGeminiReq(const string &promptFilePath, const string &prompt);
        json sendBatchGeminiReq(const vector<string>& prompts);
        json isRespCorrect(const json& resp, const json& def);

    public:
        Gemini();

        future<json> genStatsForTheme();
        future<json> genNPC(const int &rank,const string &LocName, const string &LocDesc);
        future<json> genNPCStats(const int& rank, const string &npcName, const string &npcBackStory);
        future<json> genQuests(const int &rank,const string &name,const string &backStory);
        future<json> genLocationByGemini(const int &rank);
        future<json> genLocationByGemini(const int &rank,const string &name);

        future<json> genItem(int rank);

        static future<vector<json>> genMutlipleLocations(const vector<int>& rank);
};

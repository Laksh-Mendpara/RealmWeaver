#pragma once

#include <external.h>
#include <GameEngine.h>
#include <NPC.h>
#include <Stats.h>
#include <Location.h>


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

        future<json> get_loc_json_from_quest(std::unordered_map<int, std::shared_ptr<Location>> loc_map,
                                    const std::string &quest_name, const std::string &quest_disc);

    public:
        Gemini();

        future<json> genStatsForTheme();
        future<json> genNPC(const int &rank,const string &LocName, const string &LocDesc);
        future<json> genNPCStats(const int& rank, const string &npcName, const string &npcBackStory);
        future<json> genQuests(const int &rank,const string &name,const string &backStory);
        future<json> genLocationByGemini(const int &rank, const string &themeName);
        future<json> genLocationByGemini(const int &rank, const string &name,const string &themeName);

        future<json> genItem(int rank, const string &themeName);

        static future<vector<json>> genMutlipleLocations(const vector<int>& rank, const string &themeName);

        std::string query(const std::string& prompt);

        future<json> getResponse(const std::vector<std::string>& dialogueHistory, 
                                  const std::string& npcName, 
                                  const std::string& npcRank, 
                                  const std::string& npcBackStory, 
                                  const std::string& locName, 
                                  const std::string& locDesc, 
                                  const std::string& themeName, 
                                  const std::string& questName, 
                                  const std::string& questDescription, 
                                  const std::string& questTask);

        int get_loc_key_from_quest(std::unordered_map<int, std::shared_ptr<Location>> loc_map,
                                    const std::string &quest_name, const std::string &quest_disc);

        std::string gen_intro(std::string theme_name);
};

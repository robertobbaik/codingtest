#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, int> um;
    unordered_map<string, vector<pair<int, int>>> genre_songs;


    for (int i = 0; i < genres.size(); i++)
    {
        um[genres[i]] += plays[i];
        genre_songs[genres[i]].push_back({plays[i], i});
    }

    vector<pair<int, string>> sorted_genres;

    for(pair<string, int> p : um)
    {
        sorted_genres.push_back({p.second, p.first});
    }
    
    sort(sorted_genres.rbegin(), sorted_genres.rend());

    for(pair<int, string> p : sorted_genres)
    {
        string genre = p.second;

        sort(genre_songs[genre].begin(), genre_songs[genre].end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if(a.first != b.first)
            {
                return a.first > b.first;
            }
            return a.second < b.second;
        });

        for(int i = 0; i < min(2, (int)genre_songs[genre].size()); i++)
        {
            answer.push_back(genre_songs[genre][i].second);
        }
    }
    return answer;
}

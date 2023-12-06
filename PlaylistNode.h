#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

class PlaylistNode {
  public:
    PlaylistNode();
    PlaylistNode(string id, string name, string artist, int length);
    string GetID();
    string GetSongName();
    string GetArtistName();
    int GetSongLength();
    PlaylistNode* GetNext();
    void InsertAfter(PlaylistNode* nodePtr);
    void SetNext(PlaylistNode* nodePtr);
    void PrintPlaylistNode();
  private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

#endif